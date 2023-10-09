#-------------------------------------------------
#
# Project created by QtCreator 2020-06-04T09:36:23
#
#-------------------------------------------------

QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IntelligentCommunity
TEMPLATE = app
RC_ICONS = logo.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    adminlogin.cpp \
    admin_mainwindow.cpp \
    worker_mainwindow.cpp \
    owner_mainwindow.cpp \
    guanliyuanrenshiguanli.cpp \
    wuyeweixiuguanli.cpp \
    yezhuguzhuangbaoxiu.cpp \
    yezhuguzhangchaxunpingjia.cpp \
    wuyeqingxiaojia.cpp \
    wuyeyueduchuqin.cpp \
    wuyeshangxiabandengji.cpp \
    wuyecheweixinxiguanli.cpp \
    wuyecheweichuzu.cpp \
    guanliyuanyueduchuqin.cpp \
    guanliyuanqingjiashenpi.cpp \
    guanliyuanchushihua.cpp \
    canshushezhi.cpp \
    wuyejiaofeiguanli.cpp \
    yezhucheweiguanli.cpp \
    yezhujiaofeichaxun.cpp \
    wuyejiagewihu.cpp \
    yezhuzizhujiaofei.cpp \
    wuyexianxiashoufei.cpp \
    shenpichaxun.cpp \
    guanliyuanrenshichaxun.cpp \
    wuyezengjiaxinxi.cpp \
    guanliyuantheme.cpp

HEADERS  += mainwindow.h \
    adminlogin.h \
    admin_mainwindow.h \
    worker_mainwindow.h \
    owner_mainwindow.h \
    guanliyuanrenshiguanli.h \
    wuyeweixiuguanli.h \
    yezhuguzhuangbaoxiu.h \
    yezhuguzhangchaxunpingjia.h \
    wuyeqingxiaojia.h \
    wuyeyueduchuqin.h \
    wuyeshangxiabandengji.h \
    wuyecheweixinxiguanli.h \
    wuyecheweichuzu.h \
    quanju.h \
    guanliyuanyueduchuqin.h \
    guanliyuanqingjiashenpi.h \
    guanliyuanchushihua.h \
    canshushezhi.h \
    wuyejiaofeiguanli.h \
    yezhucheweiguanli.h \
    yezhujiaofeichaxun.h \
    wuyejiagewihu.h \
    yezhuzizhujiaofei.h \
    wuyexianxiashoufei.h \
    shenpichaxun.h \
    guanliyuanrenshichaxun.h \
    wuyezengjiaxinxi.h \
    guanliyuantheme.h

FORMS    += mainwindow.ui \
    adminlogin.ui \
    admin_mainwindow.ui \
    worker_mainwindow.ui \
    owner_mainwindow.ui \
    guanliyuanrenshiguanli.ui \
    wuyeweixiuguanli.ui \
    yezhuguzhuangbaoxiu.ui \
    yezhuguzhangchaxunpingjia.ui \
    wuyeqingxiaojia.ui \
    wuyeyueduchuqin.ui \
    wuyeshangxiabandengji.ui \
    wuyecheweixinxiguanli.ui \
    wuyecheweichuzu.ui \
    guanliyuanyueduchuqin.ui \
    guanliyuanqingjiashenpi.ui \
    guanliyuanchushihua.ui \
    canshushezhi.ui \
    wuyejiaofeiguanli.ui \
    yezhucheweiguanli.ui \
    yezhujiaofeichaxun.ui \
    wuyejiagewihu.ui \
    yezhuzizhujiaofei.ui \
    wuyexianxiashoufei.ui \
    shenpichaxun.ui \
    guanliyuanrenshichaxun.ui \
    wuyezengjiaxinxi.ui \
    guanliyuantheme.ui

RESOURCES += \
    ../ResourceFile/resourcefile.qrc

DISTFILES += \
   # ../ResourceFile/智慧背景.png \
    ../ResourceFile/2222.png


