
QT       += core gui network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TARGET = opencv_cpp_show_webcam_stream_on_Qt_GUI
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




INCLUDEPATH += D:\Opencv\build\include

LIBS += D:\opencv-build\bin\libopencv_core450.dll
LIBS += D:\opencv-build\bin\libopencv_highgui450.dll
LIBS += D:\opencv-build\bin\libopencv_imgcodecs450.dll
LIBS += D:\opencv-build\bin\libopencv_imgproc450.dll
LIBS += D:\opencv-build\bin\libopencv_features2d450.dll
LIBS += D:\opencv-build\bin\libopencv_calib3d450.dll
LIBS += D:\opencv-build\bin\libopencv_flann450.dll
LIBS += D:\opencv-build\bin\libopencv_ml450.dll
LIBS += D:\opencv-build\bin\libopencv_objdetect450.dll
LIBS += D:\opencv-build\bin\libopencv_photo450.dll
LIBS += D:\opencv-build\bin\libopencv_stitching450.dll
LIBS += D:\opencv-build\bin\libopencv_video450.dll
LIBS += D:\opencv-build\bin\libopencv_videoio450.dll
 #LIBS += C:\opencv-build\bin\libopencv_videostab450.dll
  #LIBS += C:\opencv-build\bin\libopencv_superres450.dll
   #LIBS += C:\opencv-build\bin\libopencv_shape450.dll


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtCore
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtCored
#else:unix:!macx: LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtCore

#INCLUDEPATH += $$PWD/'../vlc lib/include'
#DEPENDPATH += $$PWD/'../vlc lib/include'

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtQml
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtQmld
#else:unix:!macx: LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtQml

#INCLUDEPATH += $$PWD/'../vlc lib/include'
#DEPENDPATH += $$PWD/'../vlc lib/include'

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtQml
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtQmld
#else:unix:!macx: LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtQml

#INCLUDEPATH += $$PWD/'../vlc lib/include'
#DEPENDPATH += $$PWD/'../vlc lib/include'

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtWidgets
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtWidgetsd
#else:unix:!macx: LIBS += -L$$PWD/'../vlc lib/lib/' -lVLCQtWidgets

#INCLUDEPATH += $$PWD/'../vlc lib/include'
#DEPENDPATH += $$PWD/'../vlc lib/include'
