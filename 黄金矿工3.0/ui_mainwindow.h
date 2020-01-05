/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_beginb;
    QToolButton *button_start;
    QToolButton *button_game;
    QLabel *label_45;
    QLabel *label_556mm;
    QLabel *label_762mm;
    QLabel *label_eight;
    QLabel *label_9mm;
    QLabel *label_jian;
    QLabel *label_hospital;
    QLabel *label_shoudan;
    QLabel *label_secret;
    QLabel *label_zhitong;
    QLabel *label_yandan;
    QLabel *label_bengdai;
    QLabel *label_baodan;
    QLabel *label_sandan;
    QLabel *label_drinking;
    QLabel *label_mage;
    QLabel *label_big1;
    QLabel *label_big2;
    QLabel *label_small1;
    QLabel *label_small2;
    QLabel *label_small3;
    QLabel *label_unkown;
    QLabel *label_bigst1;
    QLabel *label_bigst2;
    QLabel *label_bigst3;
    QLabel *label_smast1;
    QLabel *label_smast2;
    QLabel *label_smast3;
    QLabel *label_smast4;
    QLabel *label_smast5;
    QLabel *label_smast6;
    QLabel *label_smast7;
    QToolButton *button_pause;
    QToolButton *button_resume;
    QLabel *label_guobac;
    QToolButton *button_next;
    QToolButton *button_exit;
    QToolButton *button_restart;
    QLabel *label_before;
    QLabel *label_tong;
    QLCDNumber *lcd_time;
    QLCDNumber *lcd_nowsco;
    QToolButton *toolButton;
    QLabel *label_lose;
    QToolButton *button_reset;
    QLCDNumber *lcd_goalsco;
    QLCDNumber *label_goal;
    QLCDNumber *label_now;
    QLCDNumber *label_level;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 1000);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_beginb = new QLabel(centralWidget);
        label_beginb->setObjectName(QStringLiteral("label_beginb"));
        label_beginb->setGeometry(QRect(-10, 120, 1011, 1001));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_beginb->sizePolicy().hasHeightForWidth());
        label_beginb->setSizePolicy(sizePolicy);
        label_beginb->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/startpg1.jpg);"));
        button_start = new QToolButton(centralWidget);
        button_start->setObjectName(QStringLiteral("button_start"));
        button_start->setGeometry(QRect(290, 450, 400, 180));
        button_start->setFocusPolicy(Qt::NoFocus);
        button_start->setContextMenuPolicy(Qt::NoContextMenu);
        button_start->setAcceptDrops(false);
        button_start->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/start.png);"));
        button_start->setCheckable(true);
        button_start->setChecked(true);
        button_start->setAutoRaise(false);
        button_game = new QToolButton(centralWidget);
        button_game->setObjectName(QStringLiteral("button_game"));
        button_game->setGeometry(QRect(400, 800, 200, 90));
        button_game->setFocusPolicy(Qt::NoFocus);
        button_game->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/icon.png);"));
        label_45 = new QLabel(centralWidget);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(650, 70, 54, 41));
        label_45->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/45-\345\217\243\345\276\204\345\255\220\345\274\271.png);"));
        label_556mm = new QLabel(centralWidget);
        label_556mm->setObjectName(QStringLiteral("label_556mm"));
        label_556mm->setGeometry(QRect(670, 70, 54, 31));
        label_556mm->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/5.56mm\345\255\220\345\274\271.png);"));
        label_762mm = new QLabel(centralWidget);
        label_762mm->setObjectName(QStringLiteral("label_762mm"));
        label_762mm->setGeometry(QRect(650, 60, 54, 31));
        label_762mm->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/7.62\346\257\253\347\261\263\345\255\220\345\274\271.png);"));
        label_eight = new QLabel(centralWidget);
        label_eight->setObjectName(QStringLiteral("label_eight"));
        label_eight->setGeometry(QRect(630, 50, 111, 71));
        label_eight->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\345\205\253\345\200\215\351\225\234s.png);"));
        label_9mm = new QLabel(centralWidget);
        label_9mm->setObjectName(QStringLiteral("label_9mm"));
        label_9mm->setGeometry(QRect(650, 60, 54, 41));
        label_9mm->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/9\346\257\253\347\261\263\345\255\220\345\274\271.png);"));
        label_jian = new QLabel(centralWidget);
        label_jian->setObjectName(QStringLiteral("label_jian"));
        label_jian->setGeometry(QRect(650, 70, 61, 31));
        label_jian->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\345\274\251\347\256\255s.png);"));
        label_hospital = new QLabel(centralWidget);
        label_hospital->setObjectName(QStringLiteral("label_hospital"));
        label_hospital->setGeometry(QRect(660, 60, 71, 51));
        label_hospital->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\346\200\245\346\225\221\345\214\205s.png);"));
        label_shoudan = new QLabel(centralWidget);
        label_shoudan->setObjectName(QStringLiteral("label_shoudan"));
        label_shoudan->setGeometry(QRect(670, 70, 61, 41));
        label_shoudan->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\346\211\213\346\246\264\345\274\271s.png);"));
        label_secret = new QLabel(centralWidget);
        label_secret->setObjectName(QStringLiteral("label_secret"));
        label_secret->setGeometry(QRect(730, 50, 91, 61));
        label_secret->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\346\234\272\345\257\206\347\256\261s.png);"));
        label_zhitong = new QLabel(centralWidget);
        label_zhitong->setObjectName(QStringLiteral("label_zhitong"));
        label_zhitong->setGeometry(QRect(780, 70, 71, 41));
        label_zhitong->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\346\255\242\347\227\233\350\215\257s.png);"));
        label_yandan = new QLabel(centralWidget);
        label_yandan->setObjectName(QStringLiteral("label_yandan"));
        label_yandan->setGeometry(QRect(750, 70, 111, 51));
        label_yandan->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\203\237\351\233\276\345\274\271s.png);"));
        label_bengdai = new QLabel(centralWidget);
        label_bengdai->setObjectName(QStringLiteral("label_bengdai"));
        label_bengdai->setGeometry(QRect(770, 80, 61, 41));
        label_bengdai->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\273\267\345\270\246s.png);"));
        label_baodan = new QLabel(centralWidget);
        label_baodan->setObjectName(QStringLiteral("label_baodan"));
        label_baodan->setGeometry(QRect(780, 80, 61, 31));
        label_baodan->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\351\234\207\347\210\206\345\274\271ss.png);"));
        label_sandan = new QLabel(centralWidget);
        label_sandan->setObjectName(QStringLiteral("label_sandan"));
        label_sandan->setGeometry(QRect(780, 70, 54, 31));
        label_sandan->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\351\234\260\345\274\271\345\255\220\345\274\271.png);"));
        label_drinking = new QLabel(centralWidget);
        label_drinking->setObjectName(QStringLiteral("label_drinking"));
        label_drinking->setGeometry(QRect(760, 70, 54, 51));
        label_drinking->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\351\245\256\346\226\231s.png);"));
        label_mage = new QLabel(centralWidget);
        label_mage->setObjectName(QStringLiteral("label_mage"));
        label_mage->setGeometry(QRect(770, 70, 54, 41));
        label_mage->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\351\251\254\346\240\274\345\215\227\346\245\240\345\255\220\345\274\271.png);"));
        label_big1 = new QLabel(centralWidget);
        label_big1->setObjectName(QStringLiteral("label_big1"));
        label_big1->setGeometry(QRect(250, 301, 81, 61));
        label_big1->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\345\256\235\347\256\261.png);"));
        label_big2 = new QLabel(centralWidget);
        label_big2->setObjectName(QStringLiteral("label_big2"));
        label_big2->setGeometry(QRect(320, 291, 81, 61));
        label_big2->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\345\256\235\347\256\261.png);"));
        label_small1 = new QLabel(centralWidget);
        label_small1->setObjectName(QStringLiteral("label_small1"));
        label_small1->setGeometry(QRect(440, 321, 54, 41));
        label_small1->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/smallbox.png);"));
        label_small2 = new QLabel(centralWidget);
        label_small2->setObjectName(QStringLiteral("label_small2"));
        label_small2->setGeometry(QRect(420, 270, 54, 41));
        label_small2->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/smallbox.png);"));
        label_small3 = new QLabel(centralWidget);
        label_small3->setObjectName(QStringLiteral("label_small3"));
        label_small3->setGeometry(QRect(390, 330, 54, 41));
        label_small3->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/smallbox.png);"));
        label_unkown = new QLabel(centralWidget);
        label_unkown->setObjectName(QStringLiteral("label_unkown"));
        label_unkown->setGeometry(QRect(510, 281, 54, 41));
        label_unkown->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/bag.png);"));
        label_bigst1 = new QLabel(centralWidget);
        label_bigst1->setObjectName(QStringLiteral("label_bigst1"));
        label_bigst1->setGeometry(QRect(30, 341, 71, 51));
        label_bigst1->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_bigst2 = new QLabel(centralWidget);
        label_bigst2->setObjectName(QStringLiteral("label_bigst2"));
        label_bigst2->setGeometry(QRect(120, 300, 71, 51));
        label_bigst2->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_bigst3 = new QLabel(centralWidget);
        label_bigst3->setObjectName(QStringLiteral("label_bigst3"));
        label_bigst3->setGeometry(QRect(60, 221, 71, 51));
        label_bigst3->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast1 = new QLabel(centralWidget);
        label_smast1->setObjectName(QStringLiteral("label_smast1"));
        label_smast1->setGeometry(QRect(180, 160, 54, 41));
        label_smast1->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast2 = new QLabel(centralWidget);
        label_smast2->setObjectName(QStringLiteral("label_smast2"));
        label_smast2->setGeometry(QRect(210, 230, 54, 41));
        label_smast2->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast3 = new QLabel(centralWidget);
        label_smast3->setObjectName(QStringLiteral("label_smast3"));
        label_smast3->setGeometry(QRect(270, 170, 54, 41));
        label_smast3->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast4 = new QLabel(centralWidget);
        label_smast4->setObjectName(QStringLiteral("label_smast4"));
        label_smast4->setGeometry(QRect(350, 150, 54, 41));
        label_smast4->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast5 = new QLabel(centralWidget);
        label_smast5->setObjectName(QStringLiteral("label_smast5"));
        label_smast5->setGeometry(QRect(400, 170, 54, 41));
        label_smast5->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast6 = new QLabel(centralWidget);
        label_smast6->setObjectName(QStringLiteral("label_smast6"));
        label_smast6->setGeometry(QRect(420, 200, 54, 41));
        label_smast6->setStyleSheet(QString::fromUtf8("border-image: url(:/pie/picturesource/\347\237\263\345\244\264s.png);"));
        label_smast7 = new QLabel(centralWidget);
        label_smast7->setObjectName(QStringLiteral("label_smast7"));
        label_smast7->setGeometry(QRect(440, 130, 54, 41));
        label_smast7->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/zhayao.png);"));
        button_pause = new QToolButton(centralWidget);
        button_pause->setObjectName(QStringLiteral("button_pause"));
        button_pause->setGeometry(QRect(260, 5, 55, 55));
        button_pause->setFocusPolicy(Qt::NoFocus);
        button_pause->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/a.png);"));
        button_resume = new QToolButton(centralWidget);
        button_resume->setObjectName(QStringLiteral("button_resume"));
        button_resume->setGeometry(QRect(260, 5, 55, 55));
        button_resume->setFocusPolicy(Qt::NoFocus);
        button_resume->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/+.png);"));
        label_guobac = new QLabel(centralWidget);
        label_guobac->setObjectName(QStringLiteral("label_guobac"));
        label_guobac->setGeometry(QRect(0, 0, 1000, 1000));
        label_guobac->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/finish.png);"));
        label_guobac->setFrameShape(QFrame::NoFrame);
        label_guobac->setFrameShadow(QFrame::Raised);
        button_next = new QToolButton(centralWidget);
        button_next->setObjectName(QStringLiteral("button_next"));
        button_next->setGeometry(QRect(270, 600, 200, 90));
        button_next->setFocusPolicy(Qt::NoFocus);
        button_next->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/icon.png);"));
        button_exit = new QToolButton(centralWidget);
        button_exit->setObjectName(QStringLiteral("button_exit"));
        button_exit->setGeometry(QRect(540, 600, 200, 90));
        button_exit->setFocusPolicy(Qt::NoFocus);
        button_exit->setStyleSheet(QLatin1String("\n"
"border-image: url(:/pie/picturesource/cancle.png);"));
        button_restart = new QToolButton(centralWidget);
        button_restart->setObjectName(QStringLiteral("button_restart"));
        button_restart->setGeometry(QRect(270, 600, 200, 90));
        button_restart->setFocusPolicy(Qt::NoFocus);
        button_restart->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/restart.png);"));
        label_before = new QLabel(centralWidget);
        label_before->setObjectName(QStringLiteral("label_before"));
        label_before->setGeometry(QRect(0, 0, 1000, 1000));
        label_before->setStyleSheet(QLatin1String("\n"
"border-image: url(:/pie/picturesource/pause.png);"));
        label_tong = new QLabel(centralWidget);
        label_tong->setObjectName(QStringLiteral("label_tong"));
        label_tong->setGeometry(QRect(0, 0, 1000, 1000));
        label_tong->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/win.jpg);"));
        lcd_time = new QLCDNumber(centralWidget);
        lcd_time->setObjectName(QStringLiteral("lcd_time"));
        lcd_time->setEnabled(false);
        lcd_time->setGeometry(QRect(750, 110, 200, 50));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(false);
        font.setWeight(50);
        lcd_time->setFont(font);
        lcd_time->setStyleSheet(QStringLiteral(""));
        lcd_time->setFrameShape(QFrame::NoFrame);
        lcd_time->setFrameShadow(QFrame::Plain);
        lcd_time->setSmallDecimalPoint(false);
        lcd_time->setDigitCount(5);
        lcd_time->setMode(QLCDNumber::Dec);
        lcd_time->setSegmentStyle(QLCDNumber::Flat);
        lcd_time->setProperty("value", QVariant(0));
        lcd_time->setProperty("intValue", QVariant(0));
        lcd_nowsco = new QLCDNumber(centralWidget);
        lcd_nowsco->setObjectName(QStringLiteral("lcd_nowsco"));
        lcd_nowsco->setEnabled(false);
        lcd_nowsco->setGeometry(QRect(20, 120, 200, 50));
        lcd_nowsco->setStyleSheet(QStringLiteral(""));
        lcd_nowsco->setFrameShape(QFrame::NoFrame);
        lcd_nowsco->setFrameShadow(QFrame::Sunken);
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setEnabled(true);
        toolButton->setGeometry(QRect(425, 0, 200, 200));
        toolButton->setFocusPolicy(Qt::NoFocus);
        toolButton->setContextMenuPolicy(Qt::NoContextMenu);
        toolButton->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/people1.png);"));
        toolButton->setInputMethodHints(Qt::ImhNone);
        label_lose = new QLabel(centralWidget);
        label_lose->setObjectName(QStringLiteral("label_lose"));
        label_lose->setGeometry(QRect(0, 0, 1000, 1000));
        label_lose->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/background.jpg);"));
        button_reset = new QToolButton(centralWidget);
        button_reset->setObjectName(QStringLiteral("button_reset"));
        button_reset->setGeometry(QRect(320, 5, 55, 55));
        button_reset->setFocusPolicy(Qt::NoFocus);
        button_reset->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/reset.png);"));
        lcd_goalsco = new QLCDNumber(centralWidget);
        lcd_goalsco->setObjectName(QStringLiteral("lcd_goalsco"));
        lcd_goalsco->setGeometry(QRect(20, 36, 200, 50));
        lcd_goalsco->setFrameShape(QFrame::NoFrame);
        label_goal = new QLCDNumber(centralWidget);
        label_goal->setObjectName(QStringLiteral("label_goal"));
        label_goal->setEnabled(true);
        label_goal->setGeometry(QRect(500, 525, 150, 135));
        QFont font1;
        font1.setFamily(QStringLiteral("Bahnschrift Light"));
        font1.setBold(true);
        font1.setWeight(75);
        label_goal->setFont(font1);
        label_goal->setTabletTracking(false);
        label_goal->setFocusPolicy(Qt::NoFocus);
        label_goal->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_goal->setFrameShape(QFrame::NoFrame);
        label_goal->setFrameShadow(QFrame::Plain);
        label_goal->setSmallDecimalPoint(false);
        label_goal->setSegmentStyle(QLCDNumber::Flat);
        label_now = new QLCDNumber(centralWidget);
        label_now->setObjectName(QStringLiteral("label_now"));
        label_now->setGeometry(QRect(500, 620, 150, 135));
        label_now->setFrameShape(QFrame::NoFrame);
        label_level = new QLCDNumber(centralWidget);
        label_level->setObjectName(QStringLiteral("label_level"));
        label_level->setGeometry(QRect(223, 99, 100, 90));
        label_level->setFrameShape(QFrame::NoFrame);
        label_level->setProperty("intValue", QVariant(1));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 370, 191, 131));
        label->setStyleSheet(QStringLiteral(""));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(600, 110, 30, 90));
        label_2->setStyleSheet(QStringLiteral("border-image: url(:/pie/picturesource/boomz.png);"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(900, 0, 100, 30));
        MainWindow->setCentralWidget(centralWidget);
        label_2->raise();
        label->raise();
        label_level->raise();
        button_reset->raise();
        lcd_goalsco->raise();
        lcd_time->raise();
        lcd_nowsco->raise();
        toolButton->raise();
        button_resume->raise();
        label_unkown->raise();
        label_small1->raise();
        label_small2->raise();
        label_smast6->raise();
        label_smast5->raise();
        label_smast4->raise();
        label_smast7->raise();
        label_45->raise();
        label_556mm->raise();
        label_762mm->raise();
        label_eight->raise();
        label_9mm->raise();
        label_jian->raise();
        label_hospital->raise();
        label_shoudan->raise();
        label_secret->raise();
        label_zhitong->raise();
        label_yandan->raise();
        label_bengdai->raise();
        label_baodan->raise();
        label_sandan->raise();
        label_drinking->raise();
        label_mage->raise();
        label_big1->raise();
        label_big2->raise();
        label_small3->raise();
        label_bigst1->raise();
        label_bigst2->raise();
        label_bigst3->raise();
        label_smast1->raise();
        label_smast2->raise();
        label_smast3->raise();
        button_pause->raise();
        label_before->raise();
        label_guobac->raise();
        label_tong->raise();
        label_beginb->raise();
        button_start->raise();
        button_game->raise();
        button_next->raise();
        label_lose->raise();
        label_goal->raise();
        label_now->raise();
        button_restart->raise();
        button_exit->raise();
        pushButton->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_beginb->setText(QString());
        button_start->setText(QString());
        button_game->setText(QApplication::translate("MainWindow", "...", nullptr));
        label_45->setText(QString());
        label_556mm->setText(QString());
        label_762mm->setText(QString());
        label_eight->setText(QString());
        label_9mm->setText(QString());
        label_jian->setText(QString());
        label_hospital->setText(QString());
        label_shoudan->setText(QString());
        label_secret->setText(QString());
        label_zhitong->setText(QString());
        label_yandan->setText(QString());
        label_bengdai->setText(QString());
        label_baodan->setText(QString());
        label_sandan->setText(QString());
        label_drinking->setText(QString());
        label_mage->setText(QString());
        label_big1->setText(QString());
        label_big2->setText(QString());
        label_small1->setText(QString());
        label_small2->setText(QString());
        label_small3->setText(QString());
        label_unkown->setText(QString());
        label_bigst1->setText(QString());
        label_bigst2->setText(QString());
        label_bigst3->setText(QString());
        label_smast1->setText(QString());
        label_smast2->setText(QString());
        label_smast3->setText(QString());
        label_smast4->setText(QString());
        label_smast5->setText(QString());
        label_smast6->setText(QString());
        label_smast7->setText(QString());
        button_pause->setText(QString());
        button_resume->setText(QString());
        label_guobac->setText(QString());
        button_next->setText(QString());
        button_exit->setText(QString());
        button_restart->setText(QString());
        label_before->setText(QString());
        label_tong->setText(QString());
        toolButton->setText(QString());
        label_lose->setText(QString());
        button_reset->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "skip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
