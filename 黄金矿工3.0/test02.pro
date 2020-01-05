#-------------------------------------------------
#
# Project created by QtCreator 2018-09-13T15:02:29
#
#-------------------------------------------------

QT       += core gui widgets
QT       += multimedia
QT       += multimediawidgets
CONFIG += resources_big
TARGET = test02
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    item.cpp \
    map.cpp \
    miner.cpp

HEADERS += \
        mainwindow.h \
    item.h \
    map.h \
    miner.h

FORMS += \
        mainwindow.ui

QT       += core gui \
        multimedia \
        multimediawidgets

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = w.ico
DISTFILES += \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/-.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/big.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/background.jpg \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/finish.jpg \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/-.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/+.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/1.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/2.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/3.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/a.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/background.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/bag.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/begin.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/big.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/cancle.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/ccc.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/diamond.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/hook1.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/icon.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/pause.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/ppause.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/reset.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/restart.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/small.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/start.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/time.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/title-money.png \
    ../../Desktop/黄金矿工/kuanggong_rc/iii/title-time.png \
    ../../Desktop/picturesource/5.56mm子弹.png \
    ../../Desktop/picturesource/7.62毫米子弹.png \
    ../../Desktop/picturesource/9毫米子弹.png \
    ../../Desktop/picturesource/45-口径子弹.png \
    ../../Desktop/picturesource/八倍镜s.png \
    ../../Desktop/picturesource/宝箱.png \
    ../../Desktop/picturesource/绷带s.png \
    ../../Desktop/picturesource/机密箱s.png \
    ../../Desktop/picturesource/急救包s.png \
    ../../Desktop/picturesource/马格南楠子弹.png \
    ../../Desktop/picturesource/弩箭s.png \
    ../../Desktop/picturesource/石头s.png \
    ../../Desktop/picturesource/手榴弹s.png \
    ../../Desktop/picturesource/霰弹子弹.png \
    ../../Desktop/picturesource/烟雾弹s.png \
    ../../Desktop/picturesource/饮料s.png \
    ../../Desktop/picturesource/震爆弹ss.png \
    ../../Desktop/picturesource/止痛药s.png \
    ../../Desktop/picturesource/5.56mm子弹.png \
    ../../Desktop/picturesource/7.62毫米子弹.png \
    ../../Desktop/picturesource/9毫米子弹.png \
    ../../Desktop/picturesource/45-口径子弹.png \
    ../../Desktop/picturesource/八倍镜s.png \
    ../../Desktop/picturesource/宝箱.png \
    ../../Desktop/picturesource/绷带s.png \
    ../../Desktop/picturesource/机密箱s.png \
    ../../Desktop/picturesource/急救包s.png \
    ../../Desktop/picturesource/马格南楠子弹.png \
    ../../Desktop/picturesource/弩箭s.png \
    ../../Desktop/picturesource/石头s.png \
    ../../Desktop/picturesource/手榴弹s.png \
    ../../Desktop/picturesource/霰弹子弹.png \
    ../../Desktop/picturesource/烟雾弹s.png \
    ../../Desktop/picturesource/饮料s.png \
    ../../Desktop/picturesource/震爆弹ss.png \
    ../../Desktop/picturesource/止痛药s.png \
    picturesource/background.jpg \
    picturesource/finish.jpg \
    picturesource/-.png \
    picturesource/+.png \
    picturesource/1.png \
    picturesource/2.png \
    picturesource/3.png \
    picturesource/5.56mm子弹.png \
    picturesource/7.62毫米子弹.png \
    picturesource/9毫米子弹.png \
    picturesource/45-口径子弹.png \
    picturesource/a.png \
    picturesource/background.png \
    picturesource/bag.png \
    picturesource/begin.png \
    picturesource/big.png \
    picturesource/cancle.png \
    picturesource/ccc.png \
    picturesource/diamond.png \
    picturesource/hook1.png \
    picturesource/icon.png \
    picturesource/pause.png \
    picturesource/ppause.png \
    picturesource/reset.png \
    picturesource/restart.png \
    picturesource/small.png \
    picturesource/start.png \
    picturesource/time.png \
    picturesource/title-money.png \
    picturesource/title-time.png \
    picturesource/八倍镜s.png \
    picturesource/宝箱.png \
    picturesource/绷带s.png \
    picturesource/机密箱s.png \
    picturesource/急救包s.png \
    picturesource/马格南楠子弹.png \
    picturesource/弩箭s.png \
    picturesource/石头s.png \
    picturesource/手榴弹s.png \
    picturesource/霰弹子弹.png \
    picturesource/烟雾弹s.png \
    picturesource/饮料s.png \
    picturesource/震爆弹ss.png \
    picturesource/止痛药s.png \
    picturesource/startpg1.jpg

RESOURCES += \
    resource.qrc \
