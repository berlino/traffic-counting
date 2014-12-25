#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

#include "package_bgs/FrameDifferenceBGS.h"
#include "package_bgs/MixtureOfGaussianV1BGS.h"
#include "package_bgs/GMG.h"
#include "package_bgs/jmo/MultiLayerBGS.h"
#include "package_bgs/pt/PixelBasedAdaptiveSegmenter.h"

#include "package_tracking/BlobTracking.h"
#include "package_analysis/VehicleCouting.h"

int main(int argc, char **argv)
{
    CvCapture *capture = 0;
    if(argc<2)
    {
        printf("Usage:count videofilename\n");
        exit(0);
    }
    capture = cvCaptureFromAVI(argv[1]);
    if(!capture)
    {
        std::cerr << "Cannot open video!" << std::endl;
        return 1;
    }

    int resize_factor = 100; // 50% of original image
    IplImage *frame_aux = cvQueryFrame(capture);
    IplImage *frame = cvCreateImage(cvSize((int)((frame_aux->width*resize_factor)/100) , (int)((frame_aux->height*resize_factor)/100)), frame_aux->depth, frame_aux->nChannels);

    /* Background Subtraction Methods */
    IBGS *bgs;

    bgs = new GMG;

    /* Blob Tracking */
    cv::Mat img_blob;
    BlobTracking* blobTracking;
    blobTracking = new BlobTracking;

    /* Vehicle Counting Algorithm */
    VehicleCouting* vehicleCouting;
    vehicleCouting = new VehicleCouting;

    int key = 0;
    while(key != 'q')
    {
        frame_aux = cvQueryFrame(capture);
        if(!frame_aux)
            break;
        cvResize(frame_aux, frame);

        cv::Mat img_input(frame);
        //cv::imshow("input", img_input);

        // bgs->process(...) method internally shows the foreground mask image
        cv::Mat img_mask;
        bgs->process(img_input, img_mask);

        if(!img_mask.empty())
        {
            // Perform blob tracking
            blobTracking->process(img_input, img_mask, img_blob);

            // Perform vehicle counting
            vehicleCouting->setInput(img_blob);
            vehicleCouting->setTracks(blobTracking->getTracks());
            vehicleCouting->process();
        }

        key = cvWaitKey(1);
    }

    delete vehicleCouting;
    delete blobTracking;
    delete bgs;

    cvDestroyAllWindows();
    cvReleaseCapture(&capture);

    return 0;
}
