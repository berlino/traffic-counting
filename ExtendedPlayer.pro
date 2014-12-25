
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = count
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    package_tracking/BlobTracking.cpp \
    package_tracking/cvblob/cvtrack.cpp \
    package_tracking/cvblob/cvlabel.cpp \
    package_tracking/cvblob/cvcontour.cpp \
    package_tracking/cvblob/cvcolor.cpp \
    package_tracking/cvblob/cvblob.cpp \
    package_tracking/cvblob/cvaux.cpp \
    package_bgs/WeightedMovingVarianceBGS.cpp \
    package_bgs/WeightedMovingMeanBGS.cpp \
    package_bgs/StaticFrameDifferenceBGS.cpp \
    package_bgs/MixtureOfGaussianV2BGS.cpp \
    package_bgs/MixtureOfGaussianV1BGS.cpp \
    package_bgs/GMG.cpp \
    package_bgs/FrameDifferenceBGS.cpp \
    package_bgs/AdaptiveBackgroundLearning.cpp \
    package_bgs/jmo/MultiLayerBGS.cpp \
    package_bgs/jmo/LocalBinaryPattern.cpp \
    package_bgs/jmo/CMultiLayerBGS.cpp \
    package_bgs/jmo/BlobResult.cpp \
    package_bgs/jmo/BlobExtraction.cpp \
    package_bgs/jmo/blob.cpp \
    package_bgs/dp/ZivkovicAGMM.cpp \
    package_bgs/dp/WrenGA.cpp \
    package_bgs/dp/PratiMediodBGS.cpp \
    package_bgs/dp/MeanBGS.cpp \
    package_bgs/dp/Image.cpp \
    package_bgs/dp/GrimsonGMM.cpp \
    package_bgs/dp/Eigenbackground.cpp \
    package_bgs/dp/DPZivkovicAGMMBGS.cpp \
    package_bgs/dp/DPWrenGABGS.cpp \
    package_bgs/dp/DPPratiMediodBGS.cpp \
    package_bgs/dp/DPMeanBGS.cpp \
    package_bgs/dp/DPGrimsonGMMBGS.cpp \
    package_bgs/dp/DPEigenbackgroundBGS.cpp \
    package_bgs/dp/DPAdaptiveMedianBGS.cpp \
    package_bgs/dp/AdaptiveMedianBGS.cpp \
    package_bgs/lb/LBSimpleGaussian.cpp \
    package_bgs/lb/LBMixtureOfGaussians.cpp \
    package_bgs/lb/LBFuzzyGaussian.cpp \
    package_bgs/lb/LBFuzzyAdaptiveSOM.cpp \
    package_bgs/lb/LBAdaptiveSOM.cpp \
    package_bgs/lb/BGModelSom.cpp \
    package_bgs/lb/BGModelMog.cpp \
    package_bgs/lb/BGModelGauss.cpp \
    package_bgs/lb/BGModelFuzzySom.cpp \
    package_bgs/lb/BGModelFuzzyGauss.cpp \
    package_bgs/lb/BGModel.cpp \
    package_bgs/pt/PixelBasedAdaptiveSegmenter.cpp \
    package_bgs/pt/PBAS.cpp \
    package_bgs/tb/T2FMRF_UV.cpp \
    package_bgs/tb/T2FMRF_UM.cpp \
    package_bgs/tb/T2FMRF.cpp \
    package_bgs/tb/T2FGMM_UV.cpp \
    package_bgs/tb/T2FGMM_UM.cpp \
    package_bgs/tb/T2FGMM.cpp \
    package_bgs/tb/PixelUtils.cpp \
    package_bgs/tb/PerformanceUtils.cpp \
    package_bgs/tb/MRF.cpp \
    package_bgs/tb/FuzzyUtils.cpp \
    package_bgs/tb/FuzzySugenoIntegral.cpp \
    package_bgs/tb/FuzzyChoquetIntegral.cpp \
    config.cpp

HEADERS  += mainwindow.h \
    player.h \
    package_tracking/cvblob/cvblob.h \
    package_bgs/WeightedMovingVarianceBGS.h \
    package_bgs/WeightedMovingMeanBGS.h \
    package_bgs/StaticFrameDifferenceBGS.h \
    package_bgs/MixtureOfGaussianV2BGS.h \
    package_bgs/MixtureOfGaussianV1BGS.h \
    package_bgs/IBGS.h \
    package_bgs/GMG.h \
    package_bgs/FrameDifferenceBGS.h \
    package_bgs/AdaptiveBackgroundLearning.h \
    package_bgs/jmo/OpenCvDataConversion.h \
    package_bgs/jmo/MultiLayerBGS.h \
    package_bgs/jmo/LocalBinaryPattern.h \
    package_bgs/jmo/CMultiLayerBGS.h \
    package_bgs/jmo/BlobResult.h \
    package_bgs/jmo/BlobLibraryConfiguration.h \
    package_bgs/jmo/BlobExtraction.h \
    package_bgs/jmo/blob.h \
    package_bgs/jmo/BGS.h \
    package_bgs/jmo/BackgroundSubtractionAPI.h \
    package_bgs/dp/ZivkovicAGMM.h \
    package_bgs/dp/WrenGA.h \
    package_bgs/dp/PratiMediodBGS.h \
    package_bgs/dp/MeanBGS.h \
    package_bgs/dp/Image.h \
    package_bgs/dp/GrimsonGMM.h \
    package_bgs/dp/Eigenbackground.h \
    package_bgs/dp/DPZivkovicAGMMBGS.h \
    package_bgs/dp/DPWrenGABGS.h \
    package_bgs/dp/DPPratiMediodBGS.h \
    package_bgs/dp/DPMeanBGS.h \
    package_bgs/dp/DPGrimsonGMMBGS.h \
    package_bgs/dp/DPEigenbackgroundBGS.h \
    package_bgs/dp/DPAdaptiveMedianBGS.h \
    package_bgs/dp/BgsParams.h \
    package_bgs/dp/Bgs.h \
    package_bgs/dp/AdaptiveMedianBGS.h \
    package_bgs/lb/Types.h \
    package_bgs/lb/LBSimpleGaussian.h \
    package_bgs/lb/LBMixtureOfGaussians.h \
    package_bgs/lb/LBFuzzyGaussian.h \
    package_bgs/lb/LBFuzzyAdaptiveSOM.h \
    package_bgs/lb/LBAdaptiveSOM.h \
    package_bgs/lb/BGModelSom.h \
    package_bgs/lb/BGModelMog.h \
    package_bgs/lb/BGModelGauss.h \
    package_bgs/lb/BGModelFuzzySom.h \
    package_bgs/lb/BGModelFuzzyGauss.h \
    package_bgs/lb/BGModel.h \
    package_bgs/pt/PixelBasedAdaptiveSegmenter.h \
    package_bgs/pt/PBAS.h \
    package_bgs/tb/T2FMRF_UV.h \
    package_bgs/tb/T2FMRF_UM.h \
    package_bgs/tb/T2FMRF.h \
    package_bgs/tb/T2FGMM_UV.h \
    package_bgs/tb/T2FGMM_UM.h \
    package_bgs/tb/T2FGMM.h \
    package_bgs/tb/PixelUtils.h \
    package_bgs/tb/PerformanceUtils.h \
    package_bgs/tb/MRF.h \
    package_bgs/tb/FuzzyUtils.h \
    package_bgs/tb/FuzzySugenoIntegral.h \
    package_bgs/tb/FuzzyChoquetIntegral.h \
    package_tracking/BlobTracking.h \
    config.h
FORMS    += mainwindow.ui \
    config.ui

# Opencv Library
INCLUDEPATH += "/usr/local/include/opencv "
LIBS += `pkg-config --cflags --libs opencv `
LIBS +="-lboost_system"
LIBS +="-lboost_filesystem"

QMAKE_CXXFLAGS_DEBUG+=" -std=c++11 -fpermissive "

# Qwt library
# CONFIG += qwt
# INCLUDEPATH +="/usr/local/qwt-6.1.0-rc3/include"
# LIBS += -L/usr/local/qwt-6.1.0-rc3/lib -lqwt

