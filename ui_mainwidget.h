/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QTabWidget *tabWidget;
    QWidget *auto_tab;
    QGroupBox *groupBox_auto;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *auto_label_longt;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *auto_lineEdit_longt;
    QHBoxLayout *horizontalLayout_5;
    QLabel *auto_label_lat;
    QSpacerItem *horizontalSpacer;
    QLineEdit *auto_lineEdit_lat;
    QHBoxLayout *horizontalLayout;
    QPushButton *auto_btn_locate;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *auto_btn_add_locs;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *auto_tabWidget_locs;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_2;
    QPushButton *auto_btn_find_me;
    QPushButton *auto_btn_delete;
    QPushButton *auto_btn_clear;
    QSpacerItem *verticalSpacer;
    QPushButton *auto_btn_execute;
    QFrame *line_auto;
    QWidget *man_tab;
    QGroupBox *groupBox_mtr;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *mtr_label_pushMotor;
    QLabel *mtr_label_pitchSteer;
    QLabel *mtr_label_headSteer;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_5;
    QSpinBox *mtr_spinBox_pushMotor;
    QSpinBox *mtr_spinBox_pitchSteer;
    QSpinBox *mtr_spinBox_headSteer;
    QSpacerItem *horizontalSpacer_14;
    QVBoxLayout *verticalLayout_6;
    QSlider *mtr_horSldr_pushMotor;
    QSlider *mtr_horSldr_pitchSteer;
    QSlider *mtr_horSldr_headSteer;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *mtr_checkBox_bbb_ctrl;
    QCheckBox *mtr_checkBox_reverse;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *mtr_btn_close_all;
    QPushButton *mtr_btn_load;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *posi_label_pumpPosi;
    QLabel *posi_label_massPosi;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_8;
    QSpinBox *posi_spinBox_pumpPosi;
    QSpinBox *posi_spinBox_massPosi;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_9;
    QSlider *posi_horSldr_pumpPosi;
    QSlider *posi_horSldr_massPosi;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *posi_btn_reset;
    QPushButton *posi_btn_load;
    QFrame *line;
    QGroupBox *groupBox_fmt;
    QPushButton *fmt_btn_execute;
    QWidget *gridLayoutWidget_10;
    QGridLayout *gridLayout_11;
    QLabel *fmt_label_time;
    QLabel *fmt_label_heading;
    QLabel *fmt_label_distance;
    QLabel *fmt_label_plan;
    QLabel *fmt_label_depth;
    QLabel *fmt_label_speed;
    QComboBox *fmt_cmbx_plan;
    QLineEdit *fmt_lineEdit_text_distance;
    QLineEdit *fmt_lineEdit_text_speed;
    QLineEdit *fmt_lineEdit_text_depth;
    QLineEdit *fmt_lineEdit_text_heading;
    QLineEdit *fmt_lineEdit_text_time;
    QGroupBox *groupBox_power;
    QWidget *gridLayoutWidget_8;
    QGridLayout *gridLayout_8;
    QCheckBox *pwr_checkBox_polav6;
    QCheckBox *pwr_checkBox_sbd9602;
    QCheckBox *pwr_checkBox_usbl;
    QCheckBox *pwr_checkBox_gprs;
    QCheckBox *pwr_checkBox_lora;
    QCheckBox *pwr_checkBox_bbb;
    QPushButton *pwr_btn_apply;
    QGroupBox *groupBox_comtst;
    QWidget *gridLayoutWidget_7;
    QGridLayout *gridLayout_9;
    QLabel *comtst_label_text_loss;
    QLabel *comtst_label_loss;
    QLabel *comtst_label_rec;
    QLabel *comtst_label_text_rec;
    QLabel *comtst_label_text_send;
    QLabel *comtst_label_sended;
    QPushButton *comtst_btn_test;
    QGroupBox *groupBox_gldr;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QGroupBox *groupBox_compass;
    QWidget *data_tab;
    QGroupBox *polav6_groupBox;
    QLabel *label_text_monitor_navi_tim;
    QLabel *label_text_monitor_hight;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *polav6_label_text_pitch;
    QLabel *polav6_label_text_acc_y;
    QLabel *polav6_label_omg_y;
    QLabel *polav6_label_v_east;
    QLabel *polav6_label_text_height;
    QLabel *polav6_label_text_acc_x;
    QLabel *polav6_label_text_v_east;
    QLabel *polav6_label_pitch;
    QLabel *polav6_label_v_sky;
    QLabel *polav6_label_omg_X;
    QLabel *polav6_label_text_yaw;
    QLabel *polav6_label_text_omg_y;
    QLabel *polav6_label_text_omg_x;
    QLabel *polav6_label_head;
    QLabel *polav6_label_text_head;
    QLabel *polav6_label_text_gps_v;
    QLabel *polav6_label_v_north;
    QLabel *polav6_label_text_lat;
    QLabel *polav6_label_acc_x;
    QLabel *polav6_label_text_long;
    QLabel *polav6_label_text_navi_tim;
    QLabel *polav6_label_omg_z;
    QLabel *polav6_label_text_omg_z;
    QLabel *polav6_label_yaw;
    QLabel *polav6_label_text_roll;
    QLabel *polav6_label_height;
    QLabel *polav6_label_text_v_north;
    QLabel *polav6_label_gps_v;
    QLabel *polav6_label_navi_tim;
    QLabel *polav6_label_text_v_sky;
    QLabel *polav6_label_long;
    QLabel *polav6_label_acc_y;
    QLabel *polav6_label_roll;
    QLabel *polav6_label_lat;
    QLabel *polav6_label_acc_z;
    QLabel *polav6_label_text_acc_z;
    QLabel *polav6_label_gps_head;
    QLabel *polav6_label_mag_head;
    QLabel *polav6_label_text_gps_head;
    QLabel *polav6_label_text_mag_head;
    QGroupBox *groupBox_environment;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *envir_label_text_volt;
    QLabel *envir_label_temper;
    QLabel *envir_label_deepth;
    QLabel *envir_label_text_temper;
    QLabel *envir_label_volt;
    QLabel *envir_label_text_deepth;
    QLabel *envir_label_curr;
    QLabel *envir_label_text_curr;
    QGroupBox *groupBox_xsens;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *xsens_label_pitch;
    QLabel *xsens_label_yaw;
    QLabel *xsens_label_roll;
    QLabel *xsens_label_text_pitch;
    QLabel *xsens_label_text_yaw;
    QLabel *xsens_label_text_roll;
    QGroupBox *mtr_dsply_groupBox;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLabel *mtr_dsply_label_pushMotor;
    QLabel *mtr_dsply_label_massPosi;
    QLabel *mtr_dsply_label_pumpPosi;
    QLabel *mtr_dsply_label_headSteer;
    QLabel *mtr_dsply_label_pitchSteer;
    QLabel *mtr_dsply_label_text_pitchSteer;
    QLabel *mtr_dsply_label_text_headSteer;
    QLabel *mtr_dsply_label_text_pushMotor;
    QLabel *mtr_dsply_label_text_massPosi;
    QLabel *mtr_dsply_label_text_pumpPosi;
    QGroupBox *groupBox_leak;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *leak_label_mid;
    QLabel *leak_label_front;
    QLabel *leak_label_tail;
    QLabel *leak_tabel_text_mid;
    QLabel *leak_tabel_text_front;
    QLabel *leak_tabel_text_tail;
    QGroupBox *ser_groupBox_st;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_18;
    QLabel *serst_label_msg;
    QSpacerItem *horizontalSpacer_25;
    QGridLayout *gridLayout_6;
    QLabel *serst_label_baud;
    QLabel *serst_label_port;
    QComboBox *serst_cobx_port;
    QComboBox *serst_cobx_baud;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *serst_btn_refresh;
    QPushButton *serst_btn_con;
    QGroupBox *slct_groupBox;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_7;
    QPushButton *slct_btn_apply;
    QComboBox *slct_cmbx_fish;
    QLabel *slct_label_current_fish;
    QLabel *comtst_label_text_current_fish;
    QGroupBox *groupBox_log;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *log_checkBox_local_record;
    QCheckBox *log_checkBox_bbb_record;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *log_btn_apply;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox_js;
    QWidget *gridLayoutWidget_9;
    QGridLayout *gridLayout_10;
    QComboBox *js_cobx;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *js_btn_refresh;
    QPushButton *js_btn_connect;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(800, 600);
        MainWidget->setMinimumSize(QSize(800, 600));
        MainWidget->setMaximumSize(QSize(1200, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Calibri"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        MainWidget->setFont(font);
        MainWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));
        tabWidget = new QTabWidget(MainWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 600, 600));
        tabWidget->setMinimumSize(QSize(600, 600));
        tabWidget->setMaximumSize(QSize(800, 600));
        tabWidget->setFocusPolicy(Qt::TabFocus);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(16, 16));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);
        auto_tab = new QWidget();
        auto_tab->setObjectName(QString::fromUtf8("auto_tab"));
        groupBox_auto = new QGroupBox(auto_tab);
        groupBox_auto->setObjectName(QString::fromUtf8("groupBox_auto"));
        groupBox_auto->setGeometry(QRect(10, 10, 581, 551));
        horizontalLayoutWidget_10 = new QWidget(groupBox_auto);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(10, 400, 561, 141));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        auto_label_longt = new QLabel(horizontalLayoutWidget_10);
        auto_label_longt->setObjectName(QString::fromUtf8("auto_label_longt"));

        horizontalLayout_2->addWidget(auto_label_longt);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        auto_lineEdit_longt = new QLineEdit(horizontalLayoutWidget_10);
        auto_lineEdit_longt->setObjectName(QString::fromUtf8("auto_lineEdit_longt"));

        horizontalLayout_2->addWidget(auto_lineEdit_longt);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        auto_label_lat = new QLabel(horizontalLayoutWidget_10);
        auto_label_lat->setObjectName(QString::fromUtf8("auto_label_lat"));

        horizontalLayout_5->addWidget(auto_label_lat);

        horizontalSpacer = new QSpacerItem(58, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        auto_lineEdit_lat = new QLineEdit(horizontalLayoutWidget_10);
        auto_lineEdit_lat->setObjectName(QString::fromUtf8("auto_lineEdit_lat"));

        horizontalLayout_5->addWidget(auto_lineEdit_lat);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        auto_btn_locate = new QPushButton(horizontalLayoutWidget_10);
        auto_btn_locate->setObjectName(QString::fromUtf8("auto_btn_locate"));

        horizontalLayout->addWidget(auto_btn_locate);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        auto_btn_add_locs = new QPushButton(horizontalLayoutWidget_10);
        auto_btn_add_locs->setObjectName(QString::fromUtf8("auto_btn_add_locs"));

        horizontalLayout->addWidget(auto_btn_add_locs);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_11->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        auto_tabWidget_locs = new QTableWidget(horizontalLayoutWidget_10);
        if (auto_tabWidget_locs->columnCount() < 2)
            auto_tabWidget_locs->setColumnCount(2);
        if (auto_tabWidget_locs->rowCount() < 4)
            auto_tabWidget_locs->setRowCount(4);
        auto_tabWidget_locs->setObjectName(QString::fromUtf8("auto_tabWidget_locs"));
        auto_tabWidget_locs->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        auto_tabWidget_locs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        auto_tabWidget_locs->setSelectionMode(QAbstractItemView::SingleSelection);
        auto_tabWidget_locs->setSelectionBehavior(QAbstractItemView::SelectRows);
        auto_tabWidget_locs->setTextElideMode(Qt::ElideRight);
        auto_tabWidget_locs->setShowGrid(true);
        auto_tabWidget_locs->setGridStyle(Qt::DotLine);
        auto_tabWidget_locs->setRowCount(4);
        auto_tabWidget_locs->setColumnCount(2);
        auto_tabWidget_locs->verticalHeader()->setVisible(false);

        horizontalLayout_11->addWidget(auto_tabWidget_locs);

        horizontalSpacer_12 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_12);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        auto_btn_find_me = new QPushButton(horizontalLayoutWidget_10);
        auto_btn_find_me->setObjectName(QString::fromUtf8("auto_btn_find_me"));

        verticalLayout_2->addWidget(auto_btn_find_me);

        auto_btn_delete = new QPushButton(horizontalLayoutWidget_10);
        auto_btn_delete->setObjectName(QString::fromUtf8("auto_btn_delete"));

        verticalLayout_2->addWidget(auto_btn_delete);

        auto_btn_clear = new QPushButton(horizontalLayoutWidget_10);
        auto_btn_clear->setObjectName(QString::fromUtf8("auto_btn_clear"));

        verticalLayout_2->addWidget(auto_btn_clear);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        auto_btn_execute = new QPushButton(horizontalLayoutWidget_10);
        auto_btn_execute->setObjectName(QString::fromUtf8("auto_btn_execute"));

        verticalLayout_2->addWidget(auto_btn_execute);


        horizontalLayout_11->addLayout(verticalLayout_2);

        line_auto = new QFrame(groupBox_auto);
        line_auto->setObjectName(QString::fromUtf8("line_auto"));
        line_auto->setGeometry(QRect(10, 370, 561, 21));
        line_auto->setFrameShape(QFrame::HLine);
        line_auto->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(auto_tab, QString());
        man_tab = new QWidget();
        man_tab->setObjectName(QString::fromUtf8("man_tab"));
        groupBox_mtr = new QGroupBox(man_tab);
        groupBox_mtr->setObjectName(QString::fromUtf8("groupBox_mtr"));
        groupBox_mtr->setGeometry(QRect(200, 10, 391, 311));
        horizontalLayoutWidget_3 = new QWidget(groupBox_mtr);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 30, 371, 104));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        mtr_label_pushMotor = new QLabel(horizontalLayoutWidget_3);
        mtr_label_pushMotor->setObjectName(QString::fromUtf8("mtr_label_pushMotor"));
        mtr_label_pushMotor->setEnabled(true);

        verticalLayout_4->addWidget(mtr_label_pushMotor);

        mtr_label_pitchSteer = new QLabel(horizontalLayoutWidget_3);
        mtr_label_pitchSteer->setObjectName(QString::fromUtf8("mtr_label_pitchSteer"));

        verticalLayout_4->addWidget(mtr_label_pitchSteer);

        mtr_label_headSteer = new QLabel(horizontalLayoutWidget_3);
        mtr_label_headSteer->setObjectName(QString::fromUtf8("mtr_label_headSteer"));

        verticalLayout_4->addWidget(mtr_label_headSteer);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_13);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        mtr_spinBox_pushMotor = new QSpinBox(horizontalLayoutWidget_3);
        mtr_spinBox_pushMotor->setObjectName(QString::fromUtf8("mtr_spinBox_pushMotor"));
        mtr_spinBox_pushMotor->setMaximum(1000);
        mtr_spinBox_pushMotor->setSingleStep(25);
        mtr_spinBox_pushMotor->setValue(500);

        verticalLayout_5->addWidget(mtr_spinBox_pushMotor);

        mtr_spinBox_pitchSteer = new QSpinBox(horizontalLayoutWidget_3);
        mtr_spinBox_pitchSteer->setObjectName(QString::fromUtf8("mtr_spinBox_pitchSteer"));
        mtr_spinBox_pitchSteer->setMinimum(1000);
        mtr_spinBox_pitchSteer->setMaximum(2000);
        mtr_spinBox_pitchSteer->setSingleStep(10);
        mtr_spinBox_pitchSteer->setValue(1500);

        verticalLayout_5->addWidget(mtr_spinBox_pitchSteer);

        mtr_spinBox_headSteer = new QSpinBox(horizontalLayoutWidget_3);
        mtr_spinBox_headSteer->setObjectName(QString::fromUtf8("mtr_spinBox_headSteer"));
        mtr_spinBox_headSteer->setMinimum(1000);
        mtr_spinBox_headSteer->setMaximum(2000);
        mtr_spinBox_headSteer->setSingleStep(10);
        mtr_spinBox_headSteer->setValue(1500);

        verticalLayout_5->addWidget(mtr_spinBox_headSteer);


        horizontalLayout_3->addLayout(verticalLayout_5);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_14);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        mtr_horSldr_pushMotor = new QSlider(horizontalLayoutWidget_3);
        mtr_horSldr_pushMotor->setObjectName(QString::fromUtf8("mtr_horSldr_pushMotor"));
        mtr_horSldr_pushMotor->setMinimum(0);
        mtr_horSldr_pushMotor->setMaximum(1000);
        mtr_horSldr_pushMotor->setSingleStep(10);
        mtr_horSldr_pushMotor->setValue(500);
        mtr_horSldr_pushMotor->setOrientation(Qt::Horizontal);
        mtr_horSldr_pushMotor->setInvertedAppearance(false);
        mtr_horSldr_pushMotor->setInvertedControls(false);

        verticalLayout_6->addWidget(mtr_horSldr_pushMotor);

        mtr_horSldr_pitchSteer = new QSlider(horizontalLayoutWidget_3);
        mtr_horSldr_pitchSteer->setObjectName(QString::fromUtf8("mtr_horSldr_pitchSteer"));
        mtr_horSldr_pitchSteer->setMinimum(1000);
        mtr_horSldr_pitchSteer->setMaximum(2000);
        mtr_horSldr_pitchSteer->setSingleStep(10);
        mtr_horSldr_pitchSteer->setPageStep(10);
        mtr_horSldr_pitchSteer->setValue(1500);
        mtr_horSldr_pitchSteer->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(mtr_horSldr_pitchSteer);

        mtr_horSldr_headSteer = new QSlider(horizontalLayoutWidget_3);
        mtr_horSldr_headSteer->setObjectName(QString::fromUtf8("mtr_horSldr_headSteer"));
        mtr_horSldr_headSteer->setMinimum(1000);
        mtr_horSldr_headSteer->setMaximum(2000);
        mtr_horSldr_headSteer->setSingleStep(10);
        mtr_horSldr_headSteer->setPageStep(10);
        mtr_horSldr_headSteer->setValue(1500);
        mtr_horSldr_headSteer->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(mtr_horSldr_headSteer);


        horizontalLayout_3->addLayout(verticalLayout_6);

        horizontalLayoutWidget_2 = new QWidget(groupBox_mtr);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 140, 371, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        mtr_checkBox_bbb_ctrl = new QCheckBox(horizontalLayoutWidget_2);
        mtr_checkBox_bbb_ctrl->setObjectName(QString::fromUtf8("mtr_checkBox_bbb_ctrl"));

        horizontalLayout_4->addWidget(mtr_checkBox_bbb_ctrl);

        mtr_checkBox_reverse = new QCheckBox(horizontalLayoutWidget_2);
        mtr_checkBox_reverse->setObjectName(QString::fromUtf8("mtr_checkBox_reverse"));

        horizontalLayout_4->addWidget(mtr_checkBox_reverse);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        mtr_btn_close_all = new QPushButton(horizontalLayoutWidget_2);
        mtr_btn_close_all->setObjectName(QString::fromUtf8("mtr_btn_close_all"));

        horizontalLayout_4->addWidget(mtr_btn_close_all);

        mtr_btn_load = new QPushButton(horizontalLayoutWidget_2);
        mtr_btn_load->setObjectName(QString::fromUtf8("mtr_btn_load"));

        horizontalLayout_4->addWidget(mtr_btn_load);

        horizontalLayoutWidget_4 = new QWidget(groupBox_mtr);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 190, 371, 71));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        posi_label_pumpPosi = new QLabel(horizontalLayoutWidget_4);
        posi_label_pumpPosi->setObjectName(QString::fromUtf8("posi_label_pumpPosi"));

        verticalLayout_3->addWidget(posi_label_pumpPosi);

        posi_label_massPosi = new QLabel(horizontalLayoutWidget_4);
        posi_label_massPosi->setObjectName(QString::fromUtf8("posi_label_massPosi"));

        verticalLayout_3->addWidget(posi_label_massPosi);


        horizontalLayout_6->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        posi_spinBox_pumpPosi = new QSpinBox(horizontalLayoutWidget_4);
        posi_spinBox_pumpPosi->setObjectName(QString::fromUtf8("posi_spinBox_pumpPosi"));
        posi_spinBox_pumpPosi->setMinimum(200);
        posi_spinBox_pumpPosi->setMaximum(1800);
        posi_spinBox_pumpPosi->setSingleStep(100);
        posi_spinBox_pumpPosi->setValue(200);

        verticalLayout_8->addWidget(posi_spinBox_pumpPosi);

        posi_spinBox_massPosi = new QSpinBox(horizontalLayoutWidget_4);
        posi_spinBox_massPosi->setObjectName(QString::fromUtf8("posi_spinBox_massPosi"));
        posi_spinBox_massPosi->setMinimum(0);
        posi_spinBox_massPosi->setMaximum(8000);
        posi_spinBox_massPosi->setSingleStep(100);
        posi_spinBox_massPosi->setValue(4000);

        verticalLayout_8->addWidget(posi_spinBox_massPosi);


        horizontalLayout_6->addLayout(verticalLayout_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        posi_horSldr_pumpPosi = new QSlider(horizontalLayoutWidget_4);
        posi_horSldr_pumpPosi->setObjectName(QString::fromUtf8("posi_horSldr_pumpPosi"));
        posi_horSldr_pumpPosi->setMinimum(200);
        posi_horSldr_pumpPosi->setMaximum(1800);
        posi_horSldr_pumpPosi->setSingleStep(100);
        posi_horSldr_pumpPosi->setPageStep(100);
        posi_horSldr_pumpPosi->setValue(200);
        posi_horSldr_pumpPosi->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(posi_horSldr_pumpPosi);

        posi_horSldr_massPosi = new QSlider(horizontalLayoutWidget_4);
        posi_horSldr_massPosi->setObjectName(QString::fromUtf8("posi_horSldr_massPosi"));
        posi_horSldr_massPosi->setMaximum(8000);
        posi_horSldr_massPosi->setSingleStep(100);
        posi_horSldr_massPosi->setPageStep(100);
        posi_horSldr_massPosi->setValue(4000);
        posi_horSldr_massPosi->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(posi_horSldr_massPosi);


        horizontalLayout_6->addLayout(verticalLayout_9);

        horizontalLayoutWidget_5 = new QWidget(groupBox_mtr);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 270, 371, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);

        posi_btn_reset = new QPushButton(horizontalLayoutWidget_5);
        posi_btn_reset->setObjectName(QString::fromUtf8("posi_btn_reset"));

        horizontalLayout_7->addWidget(posi_btn_reset);

        posi_btn_load = new QPushButton(horizontalLayoutWidget_5);
        posi_btn_load->setObjectName(QString::fromUtf8("posi_btn_load"));

        horizontalLayout_7->addWidget(posi_btn_load);

        line = new QFrame(groupBox_mtr);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(10, 170, 371, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_fmt = new QGroupBox(man_tab);
        groupBox_fmt->setObjectName(QString::fromUtf8("groupBox_fmt"));
        groupBox_fmt->setGeometry(QRect(11, 320, 181, 241));
        fmt_btn_execute = new QPushButton(groupBox_fmt);
        fmt_btn_execute->setObjectName(QString::fromUtf8("fmt_btn_execute"));
        fmt_btn_execute->setGeometry(QRect(40, 210, 89, 25));
        gridLayoutWidget_10 = new QWidget(groupBox_fmt);
        gridLayoutWidget_10->setObjectName(QString::fromUtf8("gridLayoutWidget_10"));
        gridLayoutWidget_10->setGeometry(QRect(10, 30, 161, 183));
        gridLayout_11 = new QGridLayout(gridLayoutWidget_10);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        fmt_label_time = new QLabel(gridLayoutWidget_10);
        fmt_label_time->setObjectName(QString::fromUtf8("fmt_label_time"));

        gridLayout_11->addWidget(fmt_label_time, 5, 0, 1, 1);

        fmt_label_heading = new QLabel(gridLayoutWidget_10);
        fmt_label_heading->setObjectName(QString::fromUtf8("fmt_label_heading"));

        gridLayout_11->addWidget(fmt_label_heading, 4, 0, 1, 1);

        fmt_label_distance = new QLabel(gridLayoutWidget_10);
        fmt_label_distance->setObjectName(QString::fromUtf8("fmt_label_distance"));

        gridLayout_11->addWidget(fmt_label_distance, 1, 0, 1, 1);

        fmt_label_plan = new QLabel(gridLayoutWidget_10);
        fmt_label_plan->setObjectName(QString::fromUtf8("fmt_label_plan"));

        gridLayout_11->addWidget(fmt_label_plan, 0, 0, 1, 1);

        fmt_label_depth = new QLabel(gridLayoutWidget_10);
        fmt_label_depth->setObjectName(QString::fromUtf8("fmt_label_depth"));

        gridLayout_11->addWidget(fmt_label_depth, 3, 0, 1, 1);

        fmt_label_speed = new QLabel(gridLayoutWidget_10);
        fmt_label_speed->setObjectName(QString::fromUtf8("fmt_label_speed"));

        gridLayout_11->addWidget(fmt_label_speed, 2, 0, 1, 1);

        fmt_cmbx_plan = new QComboBox(gridLayoutWidget_10);
        fmt_cmbx_plan->addItem(QString());
        fmt_cmbx_plan->addItem(QString());
        fmt_cmbx_plan->addItem(QString());
        fmt_cmbx_plan->setObjectName(QString::fromUtf8("fmt_cmbx_plan"));

        gridLayout_11->addWidget(fmt_cmbx_plan, 0, 1, 1, 1);

        fmt_lineEdit_text_distance = new QLineEdit(gridLayoutWidget_10);
        fmt_lineEdit_text_distance->setObjectName(QString::fromUtf8("fmt_lineEdit_text_distance"));

        gridLayout_11->addWidget(fmt_lineEdit_text_distance, 1, 1, 1, 1);

        fmt_lineEdit_text_speed = new QLineEdit(gridLayoutWidget_10);
        fmt_lineEdit_text_speed->setObjectName(QString::fromUtf8("fmt_lineEdit_text_speed"));

        gridLayout_11->addWidget(fmt_lineEdit_text_speed, 2, 1, 1, 1);

        fmt_lineEdit_text_depth = new QLineEdit(gridLayoutWidget_10);
        fmt_lineEdit_text_depth->setObjectName(QString::fromUtf8("fmt_lineEdit_text_depth"));

        gridLayout_11->addWidget(fmt_lineEdit_text_depth, 3, 1, 1, 1);

        fmt_lineEdit_text_heading = new QLineEdit(gridLayoutWidget_10);
        fmt_lineEdit_text_heading->setObjectName(QString::fromUtf8("fmt_lineEdit_text_heading"));

        gridLayout_11->addWidget(fmt_lineEdit_text_heading, 4, 1, 1, 1);

        fmt_lineEdit_text_time = new QLineEdit(gridLayoutWidget_10);
        fmt_lineEdit_text_time->setObjectName(QString::fromUtf8("fmt_lineEdit_text_time"));

        gridLayout_11->addWidget(fmt_lineEdit_text_time, 5, 1, 1, 1);

        groupBox_power = new QGroupBox(man_tab);
        groupBox_power->setObjectName(QString::fromUtf8("groupBox_power"));
        groupBox_power->setGeometry(QRect(0, 10, 192, 151));
        gridLayoutWidget_8 = new QWidget(groupBox_power);
        gridLayoutWidget_8->setObjectName(QString::fromUtf8("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(10, 30, 174, 91));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_8);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        pwr_checkBox_polav6 = new QCheckBox(gridLayoutWidget_8);
        pwr_checkBox_polav6->setObjectName(QString::fromUtf8("pwr_checkBox_polav6"));

        gridLayout_8->addWidget(pwr_checkBox_polav6, 0, 0, 1, 1);

        pwr_checkBox_sbd9602 = new QCheckBox(gridLayoutWidget_8);
        pwr_checkBox_sbd9602->setObjectName(QString::fromUtf8("pwr_checkBox_sbd9602"));

        gridLayout_8->addWidget(pwr_checkBox_sbd9602, 1, 0, 1, 1);

        pwr_checkBox_usbl = new QCheckBox(gridLayoutWidget_8);
        pwr_checkBox_usbl->setObjectName(QString::fromUtf8("pwr_checkBox_usbl"));

        gridLayout_8->addWidget(pwr_checkBox_usbl, 2, 0, 1, 1);

        pwr_checkBox_gprs = new QCheckBox(gridLayoutWidget_8);
        pwr_checkBox_gprs->setObjectName(QString::fromUtf8("pwr_checkBox_gprs"));

        gridLayout_8->addWidget(pwr_checkBox_gprs, 0, 1, 1, 1);

        pwr_checkBox_lora = new QCheckBox(gridLayoutWidget_8);
        pwr_checkBox_lora->setObjectName(QString::fromUtf8("pwr_checkBox_lora"));

        gridLayout_8->addWidget(pwr_checkBox_lora, 1, 1, 1, 1);

        pwr_checkBox_bbb = new QCheckBox(gridLayoutWidget_8);
        pwr_checkBox_bbb->setObjectName(QString::fromUtf8("pwr_checkBox_bbb"));

        gridLayout_8->addWidget(pwr_checkBox_bbb, 2, 1, 1, 1);

        pwr_btn_apply = new QPushButton(groupBox_power);
        pwr_btn_apply->setObjectName(QString::fromUtf8("pwr_btn_apply"));
        pwr_btn_apply->setGeometry(QRect(50, 120, 89, 25));
        groupBox_comtst = new QGroupBox(man_tab);
        groupBox_comtst->setObjectName(QString::fromUtf8("groupBox_comtst"));
        groupBox_comtst->setGeometry(QRect(0, 170, 191, 141));
        gridLayoutWidget_7 = new QWidget(groupBox_comtst);
        gridLayoutWidget_7->setObjectName(QString::fromUtf8("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(10, 30, 171, 81));
        gridLayout_9 = new QGridLayout(gridLayoutWidget_7);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        comtst_label_text_loss = new QLabel(gridLayoutWidget_7);
        comtst_label_text_loss->setObjectName(QString::fromUtf8("comtst_label_text_loss"));

        gridLayout_9->addWidget(comtst_label_text_loss, 2, 1, 1, 1);

        comtst_label_loss = new QLabel(gridLayoutWidget_7);
        comtst_label_loss->setObjectName(QString::fromUtf8("comtst_label_loss"));

        gridLayout_9->addWidget(comtst_label_loss, 2, 0, 1, 1);

        comtst_label_rec = new QLabel(gridLayoutWidget_7);
        comtst_label_rec->setObjectName(QString::fromUtf8("comtst_label_rec"));

        gridLayout_9->addWidget(comtst_label_rec, 1, 0, 1, 1);

        comtst_label_text_rec = new QLabel(gridLayoutWidget_7);
        comtst_label_text_rec->setObjectName(QString::fromUtf8("comtst_label_text_rec"));

        gridLayout_9->addWidget(comtst_label_text_rec, 1, 1, 1, 1);

        comtst_label_text_send = new QLabel(gridLayoutWidget_7);
        comtst_label_text_send->setObjectName(QString::fromUtf8("comtst_label_text_send"));

        gridLayout_9->addWidget(comtst_label_text_send, 0, 1, 1, 1);

        comtst_label_sended = new QLabel(gridLayoutWidget_7);
        comtst_label_sended->setObjectName(QString::fromUtf8("comtst_label_sended"));

        gridLayout_9->addWidget(comtst_label_sended, 0, 0, 1, 1);

        comtst_btn_test = new QPushButton(groupBox_comtst);
        comtst_btn_test->setObjectName(QString::fromUtf8("comtst_btn_test"));
        comtst_btn_test->setGeometry(QRect(50, 110, 89, 25));
        groupBox_gldr = new QGroupBox(man_tab);
        groupBox_gldr->setObjectName(QString::fromUtf8("groupBox_gldr"));
        groupBox_gldr->setGeometry(QRect(200, 330, 181, 231));
        verticalLayoutWidget = new QWidget(groupBox_gldr);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 160, 80));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_11->addWidget(lineEdit);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_11->addWidget(pushButton);

        groupBox_compass = new QGroupBox(man_tab);
        groupBox_compass->setObjectName(QString::fromUtf8("groupBox_compass"));
        groupBox_compass->setGeometry(QRect(390, 330, 201, 231));
        tabWidget->addTab(man_tab, QString());
        data_tab = new QWidget();
        data_tab->setObjectName(QString::fromUtf8("data_tab"));
        polav6_groupBox = new QGroupBox(data_tab);
        polav6_groupBox->setObjectName(QString::fromUtf8("polav6_groupBox"));
        polav6_groupBox->setGeometry(QRect(10, 260, 581, 301));
        polav6_groupBox->setFont(font);
        label_text_monitor_navi_tim = new QLabel(polav6_groupBox);
        label_text_monitor_navi_tim->setObjectName(QString::fromUtf8("label_text_monitor_navi_tim"));
        label_text_monitor_navi_tim->setGeometry(QRect(420, 30, 67, 21));
        label_text_monitor_hight = new QLabel(polav6_groupBox);
        label_text_monitor_hight->setObjectName(QString::fromUtf8("label_text_monitor_hight"));
        label_text_monitor_hight->setGeometry(QRect(550, 30, 67, 21));
        gridLayoutWidget_5 = new QWidget(polav6_groupBox);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 20, 561, 281));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        polav6_label_text_pitch = new QLabel(gridLayoutWidget_5);
        polav6_label_text_pitch->setObjectName(QString::fromUtf8("polav6_label_text_pitch"));

        gridLayout_5->addWidget(polav6_label_text_pitch, 3, 3, 1, 1);

        polav6_label_text_acc_y = new QLabel(gridLayoutWidget_5);
        polav6_label_text_acc_y->setObjectName(QString::fromUtf8("polav6_label_text_acc_y"));

        gridLayout_5->addWidget(polav6_label_text_acc_y, 1, 5, 1, 1);

        polav6_label_omg_y = new QLabel(gridLayoutWidget_5);
        polav6_label_omg_y->setObjectName(QString::fromUtf8("polav6_label_omg_y"));
        polav6_label_omg_y->setFont(font);

        gridLayout_5->addWidget(polav6_label_omg_y, 4, 4, 1, 1);

        polav6_label_v_east = new QLabel(gridLayoutWidget_5);
        polav6_label_v_east->setObjectName(QString::fromUtf8("polav6_label_v_east"));
        polav6_label_v_east->setFont(font);

        gridLayout_5->addWidget(polav6_label_v_east, 0, 2, 1, 1);

        polav6_label_text_height = new QLabel(gridLayoutWidget_5);
        polav6_label_text_height->setObjectName(QString::fromUtf8("polav6_label_text_height"));

        gridLayout_5->addWidget(polav6_label_text_height, 5, 1, 1, 1);

        polav6_label_text_acc_x = new QLabel(gridLayoutWidget_5);
        polav6_label_text_acc_x->setObjectName(QString::fromUtf8("polav6_label_text_acc_x"));

        gridLayout_5->addWidget(polav6_label_text_acc_x, 0, 5, 1, 1);

        polav6_label_text_v_east = new QLabel(gridLayoutWidget_5);
        polav6_label_text_v_east->setObjectName(QString::fromUtf8("polav6_label_text_v_east"));

        gridLayout_5->addWidget(polav6_label_text_v_east, 0, 3, 1, 1);

        polav6_label_pitch = new QLabel(gridLayoutWidget_5);
        polav6_label_pitch->setObjectName(QString::fromUtf8("polav6_label_pitch"));
        polav6_label_pitch->setFont(font);

        gridLayout_5->addWidget(polav6_label_pitch, 3, 2, 1, 1);

        polav6_label_v_sky = new QLabel(gridLayoutWidget_5);
        polav6_label_v_sky->setObjectName(QString::fromUtf8("polav6_label_v_sky"));
        polav6_label_v_sky->setFont(font);

        gridLayout_5->addWidget(polav6_label_v_sky, 2, 2, 1, 1);

        polav6_label_omg_X = new QLabel(gridLayoutWidget_5);
        polav6_label_omg_X->setObjectName(QString::fromUtf8("polav6_label_omg_X"));
        polav6_label_omg_X->setFont(font);

        gridLayout_5->addWidget(polav6_label_omg_X, 3, 4, 1, 1);

        polav6_label_text_yaw = new QLabel(gridLayoutWidget_5);
        polav6_label_text_yaw->setObjectName(QString::fromUtf8("polav6_label_text_yaw"));

        gridLayout_5->addWidget(polav6_label_text_yaw, 4, 3, 1, 1);

        polav6_label_text_omg_y = new QLabel(gridLayoutWidget_5);
        polav6_label_text_omg_y->setObjectName(QString::fromUtf8("polav6_label_text_omg_y"));

        gridLayout_5->addWidget(polav6_label_text_omg_y, 4, 5, 1, 1);

        polav6_label_text_omg_x = new QLabel(gridLayoutWidget_5);
        polav6_label_text_omg_x->setObjectName(QString::fromUtf8("polav6_label_text_omg_x"));

        gridLayout_5->addWidget(polav6_label_text_omg_x, 3, 5, 1, 1);

        polav6_label_head = new QLabel(gridLayoutWidget_5);
        polav6_label_head->setObjectName(QString::fromUtf8("polav6_label_head"));
        polav6_label_head->setFont(font);

        gridLayout_5->addWidget(polav6_label_head, 2, 0, 1, 1);

        polav6_label_text_head = new QLabel(gridLayoutWidget_5);
        polav6_label_text_head->setObjectName(QString::fromUtf8("polav6_label_text_head"));

        gridLayout_5->addWidget(polav6_label_text_head, 2, 1, 1, 1);

        polav6_label_text_gps_v = new QLabel(gridLayoutWidget_5);
        polav6_label_text_gps_v->setObjectName(QString::fromUtf8("polav6_label_text_gps_v"));

        gridLayout_5->addWidget(polav6_label_text_gps_v, 1, 1, 1, 1);

        polav6_label_v_north = new QLabel(gridLayoutWidget_5);
        polav6_label_v_north->setObjectName(QString::fromUtf8("polav6_label_v_north"));
        polav6_label_v_north->setFont(font);

        gridLayout_5->addWidget(polav6_label_v_north, 1, 2, 1, 1);

        polav6_label_text_lat = new QLabel(gridLayoutWidget_5);
        polav6_label_text_lat->setObjectName(QString::fromUtf8("polav6_label_text_lat"));

        gridLayout_5->addWidget(polav6_label_text_lat, 4, 1, 1, 1);

        polav6_label_acc_x = new QLabel(gridLayoutWidget_5);
        polav6_label_acc_x->setObjectName(QString::fromUtf8("polav6_label_acc_x"));
        polav6_label_acc_x->setFont(font);

        gridLayout_5->addWidget(polav6_label_acc_x, 0, 4, 1, 1);

        polav6_label_text_long = new QLabel(gridLayoutWidget_5);
        polav6_label_text_long->setObjectName(QString::fromUtf8("polav6_label_text_long"));

        gridLayout_5->addWidget(polav6_label_text_long, 3, 1, 1, 1);

        polav6_label_text_navi_tim = new QLabel(gridLayoutWidget_5);
        polav6_label_text_navi_tim->setObjectName(QString::fromUtf8("polav6_label_text_navi_tim"));

        gridLayout_5->addWidget(polav6_label_text_navi_tim, 0, 1, 1, 1);

        polav6_label_omg_z = new QLabel(gridLayoutWidget_5);
        polav6_label_omg_z->setObjectName(QString::fromUtf8("polav6_label_omg_z"));
        polav6_label_omg_z->setFont(font);

        gridLayout_5->addWidget(polav6_label_omg_z, 5, 4, 1, 1);

        polav6_label_text_omg_z = new QLabel(gridLayoutWidget_5);
        polav6_label_text_omg_z->setObjectName(QString::fromUtf8("polav6_label_text_omg_z"));

        gridLayout_5->addWidget(polav6_label_text_omg_z, 5, 5, 1, 1);

        polav6_label_yaw = new QLabel(gridLayoutWidget_5);
        polav6_label_yaw->setObjectName(QString::fromUtf8("polav6_label_yaw"));
        polav6_label_yaw->setFont(font);

        gridLayout_5->addWidget(polav6_label_yaw, 4, 2, 1, 1);

        polav6_label_text_roll = new QLabel(gridLayoutWidget_5);
        polav6_label_text_roll->setObjectName(QString::fromUtf8("polav6_label_text_roll"));

        gridLayout_5->addWidget(polav6_label_text_roll, 5, 3, 1, 1);

        polav6_label_height = new QLabel(gridLayoutWidget_5);
        polav6_label_height->setObjectName(QString::fromUtf8("polav6_label_height"));
        polav6_label_height->setFont(font);

        gridLayout_5->addWidget(polav6_label_height, 5, 0, 1, 1);

        polav6_label_text_v_north = new QLabel(gridLayoutWidget_5);
        polav6_label_text_v_north->setObjectName(QString::fromUtf8("polav6_label_text_v_north"));

        gridLayout_5->addWidget(polav6_label_text_v_north, 1, 3, 1, 1);

        polav6_label_gps_v = new QLabel(gridLayoutWidget_5);
        polav6_label_gps_v->setObjectName(QString::fromUtf8("polav6_label_gps_v"));
        polav6_label_gps_v->setFont(font);

        gridLayout_5->addWidget(polav6_label_gps_v, 1, 0, 1, 1);

        polav6_label_navi_tim = new QLabel(gridLayoutWidget_5);
        polav6_label_navi_tim->setObjectName(QString::fromUtf8("polav6_label_navi_tim"));
        polav6_label_navi_tim->setFont(font);

        gridLayout_5->addWidget(polav6_label_navi_tim, 0, 0, 1, 1);

        polav6_label_text_v_sky = new QLabel(gridLayoutWidget_5);
        polav6_label_text_v_sky->setObjectName(QString::fromUtf8("polav6_label_text_v_sky"));

        gridLayout_5->addWidget(polav6_label_text_v_sky, 2, 3, 1, 1);

        polav6_label_long = new QLabel(gridLayoutWidget_5);
        polav6_label_long->setObjectName(QString::fromUtf8("polav6_label_long"));
        polav6_label_long->setFont(font);

        gridLayout_5->addWidget(polav6_label_long, 3, 0, 1, 1);

        polav6_label_acc_y = new QLabel(gridLayoutWidget_5);
        polav6_label_acc_y->setObjectName(QString::fromUtf8("polav6_label_acc_y"));
        polav6_label_acc_y->setFont(font);

        gridLayout_5->addWidget(polav6_label_acc_y, 1, 4, 1, 1);

        polav6_label_roll = new QLabel(gridLayoutWidget_5);
        polav6_label_roll->setObjectName(QString::fromUtf8("polav6_label_roll"));
        polav6_label_roll->setFont(font);

        gridLayout_5->addWidget(polav6_label_roll, 5, 2, 1, 1);

        polav6_label_lat = new QLabel(gridLayoutWidget_5);
        polav6_label_lat->setObjectName(QString::fromUtf8("polav6_label_lat"));
        polav6_label_lat->setFont(font);

        gridLayout_5->addWidget(polav6_label_lat, 4, 0, 1, 1);

        polav6_label_acc_z = new QLabel(gridLayoutWidget_5);
        polav6_label_acc_z->setObjectName(QString::fromUtf8("polav6_label_acc_z"));
        polav6_label_acc_z->setFont(font);

        gridLayout_5->addWidget(polav6_label_acc_z, 2, 4, 1, 1);

        polav6_label_text_acc_z = new QLabel(gridLayoutWidget_5);
        polav6_label_text_acc_z->setObjectName(QString::fromUtf8("polav6_label_text_acc_z"));

        gridLayout_5->addWidget(polav6_label_text_acc_z, 2, 5, 1, 1);

        polav6_label_gps_head = new QLabel(gridLayoutWidget_5);
        polav6_label_gps_head->setObjectName(QString::fromUtf8("polav6_label_gps_head"));
        polav6_label_gps_head->setFont(font);

        gridLayout_5->addWidget(polav6_label_gps_head, 6, 0, 1, 1);

        polav6_label_mag_head = new QLabel(gridLayoutWidget_5);
        polav6_label_mag_head->setObjectName(QString::fromUtf8("polav6_label_mag_head"));
        polav6_label_mag_head->setFont(font);

        gridLayout_5->addWidget(polav6_label_mag_head, 6, 2, 1, 1);

        polav6_label_text_gps_head = new QLabel(gridLayoutWidget_5);
        polav6_label_text_gps_head->setObjectName(QString::fromUtf8("polav6_label_text_gps_head"));

        gridLayout_5->addWidget(polav6_label_text_gps_head, 6, 1, 1, 1);

        polav6_label_text_mag_head = new QLabel(gridLayoutWidget_5);
        polav6_label_text_mag_head->setObjectName(QString::fromUtf8("polav6_label_text_mag_head"));

        gridLayout_5->addWidget(polav6_label_text_mag_head, 6, 3, 1, 1);

        groupBox_environment = new QGroupBox(data_tab);
        groupBox_environment->setObjectName(QString::fromUtf8("groupBox_environment"));
        groupBox_environment->setGeometry(QRect(10, 10, 331, 101));
        groupBox_environment->setFont(font);
        gridLayoutWidget = new QWidget(groupBox_environment);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 311, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        envir_label_text_volt = new QLabel(gridLayoutWidget);
        envir_label_text_volt->setObjectName(QString::fromUtf8("envir_label_text_volt"));

        gridLayout->addWidget(envir_label_text_volt, 0, 1, 1, 1);

        envir_label_temper = new QLabel(gridLayoutWidget);
        envir_label_temper->setObjectName(QString::fromUtf8("envir_label_temper"));
        envir_label_temper->setFont(font);

        gridLayout->addWidget(envir_label_temper, 2, 2, 1, 1);

        envir_label_deepth = new QLabel(gridLayoutWidget);
        envir_label_deepth->setObjectName(QString::fromUtf8("envir_label_deepth"));
        envir_label_deepth->setFont(font);

        gridLayout->addWidget(envir_label_deepth, 0, 2, 1, 1);

        envir_label_text_temper = new QLabel(gridLayoutWidget);
        envir_label_text_temper->setObjectName(QString::fromUtf8("envir_label_text_temper"));

        gridLayout->addWidget(envir_label_text_temper, 2, 3, 1, 1);

        envir_label_volt = new QLabel(gridLayoutWidget);
        envir_label_volt->setObjectName(QString::fromUtf8("envir_label_volt"));
        envir_label_volt->setFont(font);

        gridLayout->addWidget(envir_label_volt, 0, 0, 1, 1);

        envir_label_text_deepth = new QLabel(gridLayoutWidget);
        envir_label_text_deepth->setObjectName(QString::fromUtf8("envir_label_text_deepth"));

        gridLayout->addWidget(envir_label_text_deepth, 0, 3, 1, 1);

        envir_label_curr = new QLabel(gridLayoutWidget);
        envir_label_curr->setObjectName(QString::fromUtf8("envir_label_curr"));
        envir_label_curr->setFont(font);

        gridLayout->addWidget(envir_label_curr, 2, 0, 1, 1);

        envir_label_text_curr = new QLabel(gridLayoutWidget);
        envir_label_text_curr->setObjectName(QString::fromUtf8("envir_label_text_curr"));

        gridLayout->addWidget(envir_label_text_curr, 2, 1, 1, 1);

        groupBox_xsens = new QGroupBox(data_tab);
        groupBox_xsens->setObjectName(QString::fromUtf8("groupBox_xsens"));
        groupBox_xsens->setGeometry(QRect(10, 120, 141, 131));
        groupBox_xsens->setFont(font);
        gridLayoutWidget_2 = new QWidget(groupBox_xsens);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 121, 111));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        xsens_label_pitch = new QLabel(gridLayoutWidget_2);
        xsens_label_pitch->setObjectName(QString::fromUtf8("xsens_label_pitch"));
        xsens_label_pitch->setFont(font);

        gridLayout_2->addWidget(xsens_label_pitch, 0, 0, 1, 1);

        xsens_label_yaw = new QLabel(gridLayoutWidget_2);
        xsens_label_yaw->setObjectName(QString::fromUtf8("xsens_label_yaw"));
        xsens_label_yaw->setFont(font);

        gridLayout_2->addWidget(xsens_label_yaw, 1, 0, 1, 1);

        xsens_label_roll = new QLabel(gridLayoutWidget_2);
        xsens_label_roll->setObjectName(QString::fromUtf8("xsens_label_roll"));
        xsens_label_roll->setFont(font);

        gridLayout_2->addWidget(xsens_label_roll, 2, 0, 1, 1);

        xsens_label_text_pitch = new QLabel(gridLayoutWidget_2);
        xsens_label_text_pitch->setObjectName(QString::fromUtf8("xsens_label_text_pitch"));

        gridLayout_2->addWidget(xsens_label_text_pitch, 0, 1, 1, 1);

        xsens_label_text_yaw = new QLabel(gridLayoutWidget_2);
        xsens_label_text_yaw->setObjectName(QString::fromUtf8("xsens_label_text_yaw"));

        gridLayout_2->addWidget(xsens_label_text_yaw, 1, 1, 1, 1);

        xsens_label_text_roll = new QLabel(gridLayoutWidget_2);
        xsens_label_text_roll->setObjectName(QString::fromUtf8("xsens_label_text_roll"));

        gridLayout_2->addWidget(xsens_label_text_roll, 2, 1, 1, 1);

        mtr_dsply_groupBox = new QGroupBox(data_tab);
        mtr_dsply_groupBox->setObjectName(QString::fromUtf8("mtr_dsply_groupBox"));
        mtr_dsply_groupBox->setGeometry(QRect(350, 10, 241, 241));
        gridLayoutWidget_4 = new QWidget(mtr_dsply_groupBox);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 221, 221));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        mtr_dsply_label_pushMotor = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_pushMotor->setObjectName(QString::fromUtf8("mtr_dsply_label_pushMotor"));
        mtr_dsply_label_pushMotor->setFont(font);

        gridLayout_4->addWidget(mtr_dsply_label_pushMotor, 0, 0, 1, 1);

        mtr_dsply_label_massPosi = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_massPosi->setObjectName(QString::fromUtf8("mtr_dsply_label_massPosi"));
        mtr_dsply_label_massPosi->setFont(font);

        gridLayout_4->addWidget(mtr_dsply_label_massPosi, 3, 0, 1, 1);

        mtr_dsply_label_pumpPosi = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_pumpPosi->setObjectName(QString::fromUtf8("mtr_dsply_label_pumpPosi"));
        mtr_dsply_label_pumpPosi->setFont(font);

        gridLayout_4->addWidget(mtr_dsply_label_pumpPosi, 4, 0, 1, 1);

        mtr_dsply_label_headSteer = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_headSteer->setObjectName(QString::fromUtf8("mtr_dsply_label_headSteer"));
        mtr_dsply_label_headSteer->setFont(font);

        gridLayout_4->addWidget(mtr_dsply_label_headSteer, 1, 0, 1, 1);

        mtr_dsply_label_pitchSteer = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_pitchSteer->setObjectName(QString::fromUtf8("mtr_dsply_label_pitchSteer"));
        mtr_dsply_label_pitchSteer->setFont(font);

        gridLayout_4->addWidget(mtr_dsply_label_pitchSteer, 2, 0, 1, 1);

        mtr_dsply_label_text_pitchSteer = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_text_pitchSteer->setObjectName(QString::fromUtf8("mtr_dsply_label_text_pitchSteer"));

        gridLayout_4->addWidget(mtr_dsply_label_text_pitchSteer, 2, 1, 1, 1);

        mtr_dsply_label_text_headSteer = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_text_headSteer->setObjectName(QString::fromUtf8("mtr_dsply_label_text_headSteer"));

        gridLayout_4->addWidget(mtr_dsply_label_text_headSteer, 1, 1, 1, 1);

        mtr_dsply_label_text_pushMotor = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_text_pushMotor->setObjectName(QString::fromUtf8("mtr_dsply_label_text_pushMotor"));

        gridLayout_4->addWidget(mtr_dsply_label_text_pushMotor, 0, 1, 1, 1);

        mtr_dsply_label_text_massPosi = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_text_massPosi->setObjectName(QString::fromUtf8("mtr_dsply_label_text_massPosi"));

        gridLayout_4->addWidget(mtr_dsply_label_text_massPosi, 3, 1, 1, 1);

        mtr_dsply_label_text_pumpPosi = new QLabel(gridLayoutWidget_4);
        mtr_dsply_label_text_pumpPosi->setObjectName(QString::fromUtf8("mtr_dsply_label_text_pumpPosi"));

        gridLayout_4->addWidget(mtr_dsply_label_text_pumpPosi, 4, 1, 1, 1);

        groupBox_leak = new QGroupBox(data_tab);
        groupBox_leak->setObjectName(QString::fromUtf8("groupBox_leak"));
        groupBox_leak->setGeometry(QRect(160, 120, 181, 131));
        gridLayoutWidget_3 = new QWidget(groupBox_leak);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 161, 111));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        leak_label_mid = new QLabel(gridLayoutWidget_3);
        leak_label_mid->setObjectName(QString::fromUtf8("leak_label_mid"));
        leak_label_mid->setFont(font);

        gridLayout_3->addWidget(leak_label_mid, 2, 0, 1, 1);

        leak_label_front = new QLabel(gridLayoutWidget_3);
        leak_label_front->setObjectName(QString::fromUtf8("leak_label_front"));
        leak_label_front->setFont(font);

        gridLayout_3->addWidget(leak_label_front, 0, 0, 1, 1);

        leak_label_tail = new QLabel(gridLayoutWidget_3);
        leak_label_tail->setObjectName(QString::fromUtf8("leak_label_tail"));
        leak_label_tail->setFont(font);

        gridLayout_3->addWidget(leak_label_tail, 3, 0, 1, 1);

        leak_tabel_text_mid = new QLabel(gridLayoutWidget_3);
        leak_tabel_text_mid->setObjectName(QString::fromUtf8("leak_tabel_text_mid"));
        leak_tabel_text_mid->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));

        gridLayout_3->addWidget(leak_tabel_text_mid, 2, 1, 1, 1);

        leak_tabel_text_front = new QLabel(gridLayoutWidget_3);
        leak_tabel_text_front->setObjectName(QString::fromUtf8("leak_tabel_text_front"));
        leak_tabel_text_front->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));

        gridLayout_3->addWidget(leak_tabel_text_front, 0, 1, 1, 1);

        leak_tabel_text_tail = new QLabel(gridLayoutWidget_3);
        leak_tabel_text_tail->setObjectName(QString::fromUtf8("leak_tabel_text_tail"));
        leak_tabel_text_tail->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";"));

        gridLayout_3->addWidget(leak_tabel_text_tail, 3, 1, 1, 1);

        tabWidget->addTab(data_tab, QString());
        ser_groupBox_st = new QGroupBox(MainWidget);
        ser_groupBox_st->setObjectName(QString::fromUtf8("ser_groupBox_st"));
        ser_groupBox_st->setGeometry(QRect(610, 10, 181, 201));
        verticalLayoutWidget_3 = new QWidget(ser_groupBox_st);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 161, 171));
        verticalLayout_10 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_18);

        serst_label_msg = new QLabel(verticalLayoutWidget_3);
        serst_label_msg->setObjectName(QString::fromUtf8("serst_label_msg"));
        serst_label_msg->setStyleSheet(QString::fromUtf8("font: 12pt \"Calibri\";\n"
"color: rgb(255, 0, 0);"));

        horizontalLayout_9->addWidget(serst_label_msg);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_25);


        verticalLayout_10->addLayout(horizontalLayout_9);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        serst_label_baud = new QLabel(verticalLayoutWidget_3);
        serst_label_baud->setObjectName(QString::fromUtf8("serst_label_baud"));

        gridLayout_6->addWidget(serst_label_baud, 1, 0, 1, 1);

        serst_label_port = new QLabel(verticalLayoutWidget_3);
        serst_label_port->setObjectName(QString::fromUtf8("serst_label_port"));

        gridLayout_6->addWidget(serst_label_port, 0, 0, 1, 1);

        serst_cobx_port = new QComboBox(verticalLayoutWidget_3);
        serst_cobx_port->setObjectName(QString::fromUtf8("serst_cobx_port"));
        serst_cobx_port->setEditable(false);

        gridLayout_6->addWidget(serst_cobx_port, 0, 1, 1, 1);

        serst_cobx_baud = new QComboBox(verticalLayoutWidget_3);
        serst_cobx_baud->addItem(QString());
        serst_cobx_baud->addItem(QString());
        serst_cobx_baud->addItem(QString());
        serst_cobx_baud->addItem(QString());
        serst_cobx_baud->setObjectName(QString::fromUtf8("serst_cobx_baud"));
        serst_cobx_baud->setEditable(false);

        gridLayout_6->addWidget(serst_cobx_baud, 1, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout_6);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        serst_btn_refresh = new QPushButton(verticalLayoutWidget_3);
        serst_btn_refresh->setObjectName(QString::fromUtf8("serst_btn_refresh"));

        horizontalLayout_16->addWidget(serst_btn_refresh);

        serst_btn_con = new QPushButton(verticalLayoutWidget_3);
        serst_btn_con->setObjectName(QString::fromUtf8("serst_btn_con"));

        horizontalLayout_16->addWidget(serst_btn_con);


        verticalLayout_10->addLayout(horizontalLayout_16);

        slct_groupBox = new QGroupBox(MainWidget);
        slct_groupBox->setObjectName(QString::fromUtf8("slct_groupBox"));
        slct_groupBox->setGeometry(QRect(610, 220, 181, 101));
        gridLayoutWidget_6 = new QWidget(slct_groupBox);
        gridLayoutWidget_6->setObjectName(QString::fromUtf8("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 161, 71));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        slct_btn_apply = new QPushButton(gridLayoutWidget_6);
        slct_btn_apply->setObjectName(QString::fromUtf8("slct_btn_apply"));

        gridLayout_7->addWidget(slct_btn_apply, 0, 1, 1, 1);

        slct_cmbx_fish = new QComboBox(gridLayoutWidget_6);
        slct_cmbx_fish->addItem(QString());
        slct_cmbx_fish->addItem(QString());
        slct_cmbx_fish->addItem(QString());
        slct_cmbx_fish->setObjectName(QString::fromUtf8("slct_cmbx_fish"));

        gridLayout_7->addWidget(slct_cmbx_fish, 0, 0, 1, 1);

        slct_label_current_fish = new QLabel(gridLayoutWidget_6);
        slct_label_current_fish->setObjectName(QString::fromUtf8("slct_label_current_fish"));

        gridLayout_7->addWidget(slct_label_current_fish, 1, 0, 1, 1);

        comtst_label_text_current_fish = new QLabel(gridLayoutWidget_6);
        comtst_label_text_current_fish->setObjectName(QString::fromUtf8("comtst_label_text_current_fish"));

        gridLayout_7->addWidget(comtst_label_text_current_fish, 1, 1, 1, 1);

        groupBox_log = new QGroupBox(MainWidget);
        groupBox_log->setObjectName(QString::fromUtf8("groupBox_log"));
        groupBox_log->setGeometry(QRect(610, 470, 181, 101));
        verticalLayoutWidget_2 = new QWidget(groupBox_log);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 161, 69));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        log_checkBox_local_record = new QCheckBox(verticalLayoutWidget_2);
        log_checkBox_local_record->setObjectName(QString::fromUtf8("log_checkBox_local_record"));

        horizontalLayout_8->addWidget(log_checkBox_local_record);

        log_checkBox_bbb_record = new QCheckBox(verticalLayoutWidget_2);
        log_checkBox_bbb_record->setObjectName(QString::fromUtf8("log_checkBox_bbb_record"));

        horizontalLayout_8->addWidget(log_checkBox_bbb_record);


        verticalLayout_7->addLayout(horizontalLayout_8);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_8);

        log_btn_apply = new QPushButton(verticalLayoutWidget_2);
        log_btn_apply->setObjectName(QString::fromUtf8("log_btn_apply"));

        horizontalLayout_12->addWidget(log_btn_apply);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_12);

        groupBox_js = new QGroupBox(MainWidget);
        groupBox_js->setObjectName(QString::fromUtf8("groupBox_js"));
        groupBox_js->setGeometry(QRect(610, 330, 181, 131));
        gridLayoutWidget_9 = new QWidget(groupBox_js);
        gridLayoutWidget_9->setObjectName(QString::fromUtf8("gridLayoutWidget_9"));
        gridLayoutWidget_9->setGeometry(QRect(10, 20, 161, 101));
        gridLayout_10 = new QGridLayout(gridLayoutWidget_9);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        js_cobx = new QComboBox(gridLayoutWidget_9);
        js_cobx->setObjectName(QString::fromUtf8("js_cobx"));

        gridLayout_10->addWidget(js_cobx, 0, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        js_btn_refresh = new QPushButton(gridLayoutWidget_9);
        js_btn_refresh->setObjectName(QString::fromUtf8("js_btn_refresh"));

        horizontalLayout_14->addWidget(js_btn_refresh);

        js_btn_connect = new QPushButton(gridLayoutWidget_9);
        js_btn_connect->setObjectName(QString::fromUtf8("js_btn_connect"));

        horizontalLayout_14->addWidget(js_btn_connect);


        gridLayout_10->addLayout(horizontalLayout_14, 1, 0, 1, 1);


        retranslateUi(MainWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        groupBox_auto->setTitle(QApplication::translate("MainWidget", "Auto Driving", nullptr));
        auto_label_longt->setText(QApplication::translate("MainWidget", "Longtitude", nullptr));
        auto_label_lat->setText(QApplication::translate("MainWidget", "Latitude", nullptr));
        auto_btn_locate->setText(QApplication::translate("MainWidget", "Locate", nullptr));
        auto_btn_add_locs->setText(QApplication::translate("MainWidget", "Add", nullptr));
        auto_btn_find_me->setText(QApplication::translate("MainWidget", "FindMe", nullptr));
        auto_btn_delete->setText(QApplication::translate("MainWidget", "Delete", nullptr));
        auto_btn_clear->setText(QApplication::translate("MainWidget", "Clear", nullptr));
        auto_btn_execute->setText(QApplication::translate("MainWidget", "Execute", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(auto_tab), QApplication::translate("MainWidget", "Auto", nullptr));
        groupBox_mtr->setTitle(QApplication::translate("MainWidget", "Motion Control", nullptr));
        mtr_label_pushMotor->setText(QApplication::translate("MainWidget", "PushMotor", nullptr));
        mtr_label_pitchSteer->setText(QApplication::translate("MainWidget", "PitchSteer", nullptr));
        mtr_label_headSteer->setText(QApplication::translate("MainWidget", "HeadSteer", nullptr));
        mtr_checkBox_bbb_ctrl->setText(QApplication::translate("MainWidget", "BBB Ctr", nullptr));
        mtr_checkBox_reverse->setText(QApplication::translate("MainWidget", "Reverse", nullptr));
        mtr_btn_close_all->setText(QApplication::translate("MainWidget", "Close All", nullptr));
        mtr_btn_load->setText(QApplication::translate("MainWidget", "Load", nullptr));
        posi_label_pumpPosi->setText(QApplication::translate("MainWidget", "PumpPosi  ", nullptr));
        posi_label_massPosi->setText(QApplication::translate("MainWidget", "MassPosi", nullptr));
        posi_btn_reset->setText(QApplication::translate("MainWidget", "Reset", nullptr));
        posi_btn_load->setText(QApplication::translate("MainWidget", "Load", nullptr));
        groupBox_fmt->setTitle(QApplication::translate("MainWidget", "Formation Control", nullptr));
        fmt_btn_execute->setText(QApplication::translate("MainWidget", "Execute", nullptr));
        fmt_label_time->setText(QApplication::translate("MainWidget", "Time(s)", nullptr));
        fmt_label_heading->setText(QApplication::translate("MainWidget", "Heading(rad)", nullptr));
        fmt_label_distance->setText(QApplication::translate("MainWidget", "Distance(m)", nullptr));
        fmt_label_plan->setText(QApplication::translate("MainWidget", "Plan", nullptr));
        fmt_label_depth->setText(QApplication::translate("MainWidget", "Depth(m)", nullptr));
        fmt_label_speed->setText(QApplication::translate("MainWidget", "Speed(m/s)", nullptr));
        fmt_cmbx_plan->setItemText(0, QApplication::translate("MainWidget", "Plan0", nullptr));
        fmt_cmbx_plan->setItemText(1, QApplication::translate("MainWidget", "Plan1", nullptr));
        fmt_cmbx_plan->setItemText(2, QApplication::translate("MainWidget", "Plan2", nullptr));

        fmt_lineEdit_text_distance->setText(QApplication::translate("MainWidget", "50", nullptr));
        fmt_lineEdit_text_speed->setText(QApplication::translate("MainWidget", "0.25", nullptr));
        fmt_lineEdit_text_depth->setText(QApplication::translate("MainWidget", "1", nullptr));
        fmt_lineEdit_text_heading->setText(QApplication::translate("MainWidget", "0", nullptr));
        fmt_lineEdit_text_time->setText(QApplication::translate("MainWidget", "600", nullptr));
        groupBox_power->setTitle(QApplication::translate("MainWidget", "Power Control", nullptr));
        pwr_checkBox_polav6->setText(QApplication::translate("MainWidget", "Pola V6", nullptr));
        pwr_checkBox_sbd9602->setText(QApplication::translate("MainWidget", "SBD9602", nullptr));
        pwr_checkBox_usbl->setText(QApplication::translate("MainWidget", "USBL", nullptr));
        pwr_checkBox_gprs->setText(QApplication::translate("MainWidget", "GPRS", nullptr));
        pwr_checkBox_lora->setText(QApplication::translate("MainWidget", "LoRa", nullptr));
        pwr_checkBox_bbb->setText(QApplication::translate("MainWidget", "BBB", nullptr));
        pwr_btn_apply->setText(QApplication::translate("MainWidget", "Apply", nullptr));
        groupBox_comtst->setTitle(QApplication::translate("MainWidget", "Com Test", nullptr));
        comtst_label_text_loss->setText(QApplication::translate("MainWidget", "-", nullptr));
        comtst_label_loss->setText(QApplication::translate("MainWidget", "Loss(%)", nullptr));
        comtst_label_rec->setText(QApplication::translate("MainWidget", "Recieved", nullptr));
        comtst_label_text_rec->setText(QApplication::translate("MainWidget", "-", nullptr));
        comtst_label_text_send->setText(QApplication::translate("MainWidget", "-", nullptr));
        comtst_label_sended->setText(QApplication::translate("MainWidget", "Sended", nullptr));
        comtst_btn_test->setText(QApplication::translate("MainWidget", "Test", nullptr));
        groupBox_gldr->setTitle(QApplication::translate("MainWidget", "Glider Control", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("MainWidget", "test", nullptr));
        groupBox_compass->setTitle(QApplication::translate("MainWidget", "Compass", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(man_tab), QApplication::translate("MainWidget", "Control", nullptr));
        polav6_groupBox->setTitle(QApplication::translate("MainWidget", "Pola V6", nullptr));
        label_text_monitor_navi_tim->setText(QString());
        label_text_monitor_hight->setText(QString());
        polav6_label_text_pitch->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_acc_y->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_omg_y->setText(QApplication::translate("MainWidget", "Omg_y", nullptr));
        polav6_label_v_east->setText(QApplication::translate("MainWidget", "V_east", nullptr));
        polav6_label_text_height->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_acc_x->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_v_east->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_pitch->setText(QApplication::translate("MainWidget", "Pitch", nullptr));
        polav6_label_v_sky->setText(QApplication::translate("MainWidget", "V_sky", nullptr));
        polav6_label_omg_X->setText(QApplication::translate("MainWidget", "Omg_x", nullptr));
        polav6_label_text_yaw->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_omg_y->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_omg_x->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_head->setText(QApplication::translate("MainWidget", "Heading", nullptr));
        polav6_label_text_head->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_gps_v->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_v_north->setText(QApplication::translate("MainWidget", "V_north", nullptr));
        polav6_label_text_lat->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_acc_x->setText(QApplication::translate("MainWidget", "Acc_x", nullptr));
        polav6_label_text_long->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_navi_tim->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_omg_z->setText(QApplication::translate("MainWidget", "Omg_z", nullptr));
        polav6_label_text_omg_z->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_yaw->setText(QApplication::translate("MainWidget", "Yaw", nullptr));
        polav6_label_text_roll->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_height->setText(QApplication::translate("MainWidget", "Height", nullptr));
        polav6_label_text_v_north->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_gps_v->setText(QApplication::translate("MainWidget", "GPS_v", nullptr));
        polav6_label_navi_tim->setText(QApplication::translate("MainWidget", "Navi_tim", nullptr));
        polav6_label_text_v_sky->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_long->setText(QApplication::translate("MainWidget", "Longtitude", nullptr));
        polav6_label_acc_y->setText(QApplication::translate("MainWidget", "Acc_y", nullptr));
        polav6_label_roll->setText(QApplication::translate("MainWidget", "Roll", nullptr));
        polav6_label_lat->setText(QApplication::translate("MainWidget", "Latitude", nullptr));
        polav6_label_acc_z->setText(QApplication::translate("MainWidget", "Acc_z", nullptr));
        polav6_label_text_acc_z->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_gps_head->setText(QApplication::translate("MainWidget", "GPS_heading", nullptr));
        polav6_label_mag_head->setText(QApplication::translate("MainWidget", "Mag_heading", nullptr));
        polav6_label_text_gps_head->setText(QApplication::translate("MainWidget", "-", nullptr));
        polav6_label_text_mag_head->setText(QApplication::translate("MainWidget", "-", nullptr));
        groupBox_environment->setTitle(QApplication::translate("MainWidget", "Environment", nullptr));
        envir_label_text_volt->setText(QApplication::translate("MainWidget", "-", nullptr));
        envir_label_temper->setText(QApplication::translate("MainWidget", "Temp", nullptr));
        envir_label_deepth->setText(QApplication::translate("MainWidget", "Deepth", nullptr));
        envir_label_text_temper->setText(QApplication::translate("MainWidget", "-", nullptr));
        envir_label_volt->setText(QApplication::translate("MainWidget", "Voltage", nullptr));
        envir_label_text_deepth->setText(QApplication::translate("MainWidget", "-", nullptr));
        envir_label_curr->setText(QApplication::translate("MainWidget", "Current", nullptr));
        envir_label_text_curr->setText(QApplication::translate("MainWidget", "-", nullptr));
        groupBox_xsens->setTitle(QApplication::translate("MainWidget", "Xsens", nullptr));
        xsens_label_pitch->setText(QApplication::translate("MainWidget", "Pitch", nullptr));
        xsens_label_yaw->setText(QApplication::translate("MainWidget", "Yaw", nullptr));
        xsens_label_roll->setText(QApplication::translate("MainWidget", "Roll", nullptr));
        xsens_label_text_pitch->setText(QApplication::translate("MainWidget", "-", nullptr));
        xsens_label_text_yaw->setText(QApplication::translate("MainWidget", "-", nullptr));
        xsens_label_text_roll->setText(QApplication::translate("MainWidget", "-", nullptr));
        mtr_dsply_groupBox->setTitle(QApplication::translate("MainWidget", "Motor", nullptr));
        mtr_dsply_label_pushMotor->setText(QApplication::translate("MainWidget", "PushMotor", nullptr));
        mtr_dsply_label_massPosi->setText(QApplication::translate("MainWidget", "MassPosi", nullptr));
        mtr_dsply_label_pumpPosi->setText(QApplication::translate("MainWidget", "PistonPosi", nullptr));
        mtr_dsply_label_headSteer->setText(QApplication::translate("MainWidget", "HeadStear", nullptr));
        mtr_dsply_label_pitchSteer->setText(QApplication::translate("MainWidget", "PitchStear", nullptr));
        mtr_dsply_label_text_pitchSteer->setText(QApplication::translate("MainWidget", "-", nullptr));
        mtr_dsply_label_text_headSteer->setText(QApplication::translate("MainWidget", "-", nullptr));
        mtr_dsply_label_text_pushMotor->setText(QApplication::translate("MainWidget", "-", nullptr));
        mtr_dsply_label_text_massPosi->setText(QApplication::translate("MainWidget", "-", nullptr));
        mtr_dsply_label_text_pumpPosi->setText(QApplication::translate("MainWidget", "-", nullptr));
        groupBox_leak->setTitle(QApplication::translate("MainWidget", "Leak", nullptr));
        leak_label_mid->setText(QApplication::translate("MainWidget", "MidLeak", nullptr));
        leak_label_front->setText(QApplication::translate("MainWidget", "FrontLeak", nullptr));
        leak_label_tail->setText(QApplication::translate("MainWidget", "TailLeak", nullptr));
        leak_tabel_text_mid->setText(QApplication::translate("MainWidget", "Normal", nullptr));
        leak_tabel_text_front->setText(QApplication::translate("MainWidget", "Normal", nullptr));
        leak_tabel_text_tail->setText(QApplication::translate("MainWidget", "Normal", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(data_tab), QApplication::translate("MainWidget", "Data", nullptr));
        ser_groupBox_st->setTitle(QApplication::translate("MainWidget", "Serial Port Settings", nullptr));
        serst_label_msg->setText(QApplication::translate("MainWidget", "Nothing connected!", nullptr));
        serst_label_baud->setText(QApplication::translate("MainWidget", "BaudRate", nullptr));
        serst_label_port->setText(QApplication::translate("MainWidget", "Port", nullptr));
        serst_cobx_baud->setItemText(0, QApplication::translate("MainWidget", "115200", nullptr));
        serst_cobx_baud->setItemText(1, QApplication::translate("MainWidget", "9600", nullptr));
        serst_cobx_baud->setItemText(2, QApplication::translate("MainWidget", "230400", nullptr));
        serst_cobx_baud->setItemText(3, QApplication::translate("MainWidget", "460800", nullptr));

        serst_btn_refresh->setText(QApplication::translate("MainWidget", "Refresh", nullptr));
        serst_btn_con->setText(QApplication::translate("MainWidget", "Open Port", nullptr));
        slct_groupBox->setTitle(QApplication::translate("MainWidget", "Selection", nullptr));
        slct_btn_apply->setText(QApplication::translate("MainWidget", "Apply", nullptr));
        slct_cmbx_fish->setItemText(0, QApplication::translate("MainWidget", "Fish1", nullptr));
        slct_cmbx_fish->setItemText(1, QApplication::translate("MainWidget", "Fish2", nullptr));
        slct_cmbx_fish->setItemText(2, QApplication::translate("MainWidget", "Fish3", nullptr));

        slct_label_current_fish->setText(QApplication::translate("MainWidget", "Current", nullptr));
        comtst_label_text_current_fish->setText(QApplication::translate("MainWidget", "-", nullptr));
        groupBox_log->setTitle(QApplication::translate("MainWidget", "Log Record", nullptr));
        log_checkBox_local_record->setText(QApplication::translate("MainWidget", "Local", nullptr));
        log_checkBox_bbb_record->setText(QApplication::translate("MainWidget", "BBB", nullptr));
        log_btn_apply->setText(QApplication::translate("MainWidget", "Apply", nullptr));
        groupBox_js->setTitle(QApplication::translate("MainWidget", "JoyStick", nullptr));
        js_btn_refresh->setText(QApplication::translate("MainWidget", "Refresh", nullptr));
        js_btn_connect->setText(QApplication::translate("MainWidget", "Connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
