QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# 配置需要引进库的路径 windows系统路径分隔符是（\）, Qt里面路径名分隔符(/)
DLLDEMO_SDK  =  $$quote(F:/Qt31/lession13/userdll/)

# 配置库的头文件
INCLUDEPATH+=  $${DLLDEMO_SDK} \

#  配置库  LIBS  +=  添加库
CONFIG(debug,debug|release){
LIBS  +=  -L"$${DLLDEMO_SDK}"  \  #  debug
          -llibstaticLibd  #  ‐L  指定路径  ‐l  指定库  #  d  表Debug库
}
else{
LIBS  +=  -L"$${DLLDEMO_SDK}"  \  #  release
          -llibstaticLib  #  ‐L  指定路径  ‐l  指定库  #
}
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
        dlldemo.h \
        dlldemo_global.h \
        staticlib.h

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
