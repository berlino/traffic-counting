#include "config.h"
#include "ui_config.h"

config::config(Player *parent) :ui(new Ui::config)
{
    file_name=parent->filename;
    //printf("configuring %s",file_name);
    ui->setupUi(this);
    module=0;
    direction=2;
    QObject::connect(ui->buttonGroup,SIGNAL(buttonReleased(QAbstractButton*)),SLOT(change_background_module(QAbstractButton*)));
}

config::~config()
{
    delete ui;
}

void config::on_resetAllToDefaultsButton_clicked()
{
    char file_xml[200];
    sprintf(file_xml,"./config/%s.VehicleCounting.xml",this->file_name.data());
    //printf("%s\n",file_xml);
    CvFileStorage* fs = cvOpenFileStorage(file_xml, 0, CV_STORAGE_WRITE);
    cvWriteInt(fs, "showOutput", 1);
    cvWriteInt(fs, "showAB", 2);

    cvWriteInt(fs, "fav1_use_roi", 1);
    cvWriteInt(fs, "fav1_roi_defined", 0);
    cvWriteInt(fs, "fav1_roi_x0", 0);
    cvWriteInt(fs, "fav1_roi_y0", 130);
    cvWriteInt(fs, "fav1_roi_x1", 510);
    cvWriteInt(fs, "fav1_roi_y1", 128);

    cvReleaseFileStorage(&fs);
    QMessageBox::about(NULL,"Reset","Reset done!");
}

void config::change_background_module(QAbstractButton* but)
{
    int module;
    if (but==(QAbstractButton*)ui->GMG)
            module=0;
    if(but==(QAbstractButton*)ui->MultiLayerBGS)
            module=1;
    if(but==(QAbstractButton*)ui->PixelBasedAdaptive)
            module=2;
    if(but==(QAbstractButton*)ui->FrameDifferenceBGS)
            module=3;
    if(but==(QAbstractButton*)ui->StaticFrameDifferenceBGS)
            module=4;
    if(but==(QAbstractButton*)ui->WeightedMovingMeanBGS)
            module=5;
    if(but==(QAbstractButton*)ui->None)
        direction=0;
    if(but==(QAbstractButton*)ui->A)
        direction=1;
    if(but==(QAbstractButton*)ui->B)
        direction=2;
}

void config::on_okCancelBox_accepted()
{
    char file_xml[200];
    sprintf(file_xml,"./config/%s.VehicleCounting.xml",file_name.data());
    CvFileStorage* fs = cvOpenFileStorage(file_xml, 0, CV_STORAGE_WRITE);
    if(access(file_xml,F_OK)==-1)
    {
        cvWriteInt(fs, "showOutput", 1);
        cvWriteInt(fs, "showAB", 2);
        if(module>=0)
            cvWriteInt(fs,"module",module);
        else
            cvWriteInt(fs,"module",0);
        if(direction>=0)
            cvWriteInt(fs,"showAB",direction);
        else
            cvWriteInt(fs,"showAB",2);
        cvWriteInt(fs, "fav1_use_roi", 1);
        cvWriteInt(fs, "fav1_roi_defined", 0);
        cvReleaseFileStorage(&fs);
    }
    else
    {
        cvReleaseFileStorage(&fs);
        CvFileStorage* fs_read = cvOpenFileStorage(file_xml, 0, CV_STORAGE_READ);
        int showOutput = cvReadIntByName(fs, 0, "showOutput", true);
        int use_roi = cvReadIntByName(fs, 0, "fav1_use_roi", true);
        int roi_defined = cvReadIntByName(fs, 0, "fav1_roi_defined", false);
        int roi_x0= cvReadIntByName(fs, 0, "fav1_roi_x0", 0);
        int roi_y0 = cvReadIntByName(fs, 0, "fav1_roi_y0", 0);
        int roi_x1 = cvReadIntByName(fs, 0, "fav1_roi_x1", 0);
        int roi_y1 = cvReadIntByName(fs, 0, "fav1_roi_y1", 0);
        cvReleaseFileStorage(&fs_read);
        CvFileStorage* fs = cvOpenFileStorage(file_xml, 0, CV_STORAGE_WRITE);
        cvWriteInt(fs,"showOutput",showOutput);
        cvWriteInt(fs,"showAB",direction);
        cvWriteInt(fs,"module",module);
        cvWriteInt(fs, "fav1_use_roi", use_roi);
        cvWriteInt(fs, "fav1_roi_defined", roi_defined);
        cvWriteInt(fs, "fav1_roi_x0", roi_x0);
        cvWriteInt(fs, "fav1_roi_y0", roi_y0);
        cvWriteInt(fs, "fav1_roi_x1", roi_x1);
        cvWriteInt(fs, "fav1_roi_y1", roi_y1);
        cvReleaseFileStorage(&fs);
    }

    delete(this);
}
