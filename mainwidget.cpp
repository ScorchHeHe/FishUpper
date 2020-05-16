/**
 * File name: mainwidget.cpp
 * Brief: MainWidget class cpp source file
 * Author: GJH
 * Version: 0.1
 * See: mainwidget.h
 * Date: 2020.1.8
**/

#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>
#include <QTextStream>
#include <QDateTime>
#include <QTime>
#include <QCoreApplication>


/**
 * Class name: MainWidget
 * Brief: UI of AUV upper software
 * Author: GJH
 * Version: 0.1
 * See:
 * Date: 2020.1.8
**/
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWidget),
      m_serialport(new QSerialPort),
      m_mutex(new QMutex),
      m_webchannel(new QWebChannel),
      m_compass(new Compass)
{
    ui->setupUi(this);
    ui->leak_tabel_text_front->setStyleSheet("color:green");
    ui->leak_tabel_text_mid->setStyleSheet("color:green");
    ui->leak_tabel_text_tail->setStyleSheet("color:green");
    ui->pwr_checkBox_polav6->setChecked(true);
    ui->pwr_checkBox_polav6->setStyleSheet("color:green");
    ui->pwr_checkBox_gprs->setChecked(true);
    ui->pwr_checkBox_gprs->setStyleSheet("color:green");
    ui->pwr_checkBox_sbd9602->setChecked(true);
    ui->pwr_checkBox_sbd9602->setStyleSheet("color:green");
    ui->pwr_checkBox_lora->setChecked(true);
    ui->pwr_checkBox_lora->setStyleSheet("color:green");
    ui->pwr_checkBox_usbl->setChecked(true);
    ui->pwr_checkBox_usbl->setStyleSheet("color:green");
    ui->pwr_checkBox_bbb->setChecked(true);
    ui->pwr_checkBox_bbb->setStyleSheet("color:green");

    QStringList hor_header, ver_header;
    hor_header << "Longtitude" << "Latitude";
    ver_header << "1" << "2" << "3" << "4";
    ui->auto_tabWidget_locs->setHorizontalHeaderLabels(hor_header);
    ui->auto_tabWidget_locs->setVerticalHeaderLabels(ver_header);
    ui->auto_tabWidget_locs->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->init_tabwidget_locs();

    m_webview = new QWebEngineView(ui->auto_tab);
    m_webview->setGeometry(QRect(10, 30, 581, 341));
    m_webview->load(QUrl("file:///E:/Code/FishUpper/webview/FishMap.html"));
    m_webview->show();

    connect(m_serialport, SIGNAL(readyRead()), this, SLOT(serial_rec_data_addr_parse()));

    // publish a MainWidget object to m_webchannel
    m_webchannel->registerObject("mainwidget", this);
    m_webview->page()->setWebChannel(m_webchannel);
    ui->auto_lineEdit_longt->setText("120.3364982");
    ui->auto_lineEdit_lat->setText("30.3137504");

    m_joystick = QJoysticks::getInstance();
    connect(m_joystick, SIGNAL(axisChanged(int, int, qreal)), this, SLOT(joysitck_axis(int, int, qreal)));
    connect(m_joystick, SIGNAL(buttonChanged(int, int, bool)), this, SLOT(joystick_btn(int, int, bool)));

    local_record_flag = false;

    this->scan_serialport();
    this->scan_joysticks();

    m_compass->setParent(ui->groupBox_compass);
    m_compass->show();

    rec_flag = 0x00;
    rec_index = 0x00;

    push_motor_para = 0;
    head_steer_para = 0;
    pitch_steer_para = 0;

    push_mtr_timer = 0;
    head_steer_timer = 0;
    pitch_steer_timer = 0;
    BMap_timer = 0;
    send_mtr_para_timer = 0;

    current_fish = FRAME_ADDR_FISH1;

}

MainWidget::~MainWidget()
{
    delete ui;
    delete m_serialport;
    delete m_mutex;
    delete m_webchannel;
    delete m_webview;
    delete m_compass;
}

/**
 * Function name: scan_serialport()
 * Brief: Add avaliable serialports to serst_cobx_port
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: None
 * Date: 2020.1.8
**/
void MainWidget::scan_serialport()
{
    ui->serst_cobx_port->clear();
    // add avaliable serialports to cobx_port
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()){
        QSerialPort tmp_serial;
        tmp_serial.setPort(info);
        if (tmp_serial.open(QIODevice::ReadWrite)){
            ui->serst_cobx_port->addItem(info.portName());
            tmp_serial.close();
        }
    }
    if (ui->serst_cobx_port->count() > 0){
        ui->serst_label_msg->setText("Please open port");
        ui->serst_label_msg->setStyleSheet("color:black");
    }
    else {
        ui->serst_label_msg->setText("No ports found");
        ui->serst_label_msg->setStyleSheet("color:red");
    }
}

/**
 * Function name: scan_joysticks()
 * Brief: Add avaliable joysticks to js_cobx
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: QJoysticks: https://github.com/alex-spataru/QJoysticks
 * Date: 2020.2.11
**/
void MainWidget::scan_joysticks()
{
    ui->js_cobx->clear();
    m_joystick->setVirtualJoystickEnabled (true);
    m_joystick->setVirtualJoystickRange (1);
    QStringList js_names = m_joystick->deviceNames();
    foreach (QString name, js_names){
        ui->js_cobx->addItem(name);
    }
    joystick_connect_state = false;
}

/**
 * Function name: on_serst_btn_refresh_clicked()
 * Brief: serst_btn_refresh click slot, scan avaliable serialport
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: scan_serialport()
 * Date: 2020.1.8
**/
void MainWidget::on_serst_btn_refresh_clicked()
{
    this->scan_serialport();
}

/**
 * Function name: on_serst_btn_con_clicked()
 * Brief: serst_btn_con click slot, open or close serialport when clicked
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.8
**/
void MainWidget::on_serst_btn_con_clicked()
{
    m_serialport->setPortName(ui->serst_cobx_port->currentText());
    // close port
    if (m_serialport->isOpen()){
        m_serialport->close();
        ui->serst_btn_con->setText("Open Port");
        ui->serst_cobx_port->setEnabled(true);
        ui->serst_cobx_baud->setEnabled(true);
        ui->serst_btn_refresh->setEnabled(true);
        ui->serst_label_msg->setText("Please open port");
        ui->serst_label_msg->setStyleSheet("font:12pt Calibri; color:black");
    }
    // open port
    else {
        // open port successed
        if (m_serialport->open(QIODevice::ReadWrite)){
            // serialport settings
            m_serialport->setBaudRate(ui->serst_cobx_baud->currentText().toInt());
            m_serialport->setStopBits(QSerialPort::OneStop);
            m_serialport->setFlowControl(QSerialPort::NoFlowControl);
            m_serialport->setDataBits(QSerialPort::Data8);
            m_serialport->setParity(QSerialPort::NoParity);
            ui->serst_btn_con->setText("Close Port");
            ui->serst_cobx_port->setDisabled(true);
            ui->serst_cobx_baud->setDisabled(true);
            ui->serst_btn_refresh->setDisabled(true);
            ui->serst_label_msg->setText(m_serialport->portName() + " is connected");
            ui->serst_label_msg->setStyleSheet("font:12pt Calibri; color:green");
        }
        // open port failed
        else {
            ui->serst_label_msg->setText("No ports found");
            ui->serst_label_msg->setStyleSheet("font:12pt Calibri; color:red");
        }
    }
}

/**
 * Function name: serial_rec_data_process()
 * Brief: Parse address byte of recieved data from serialport
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: FrameGet(uint8_t byte),
 *      serial_rec_data_display()
 * Date: 2020.1.9
**/
void MainWidget::serial_rec_data_addr_parse()
{
    uint8_t buffer[BUFFER_MAX_SIZE] = {0};
    // read serialport recieved data to buffer[]
    uint16_t data_length = m_serialport->bytesAvailable();
    m_serialport->read((char*)buffer, data_length);
    // find frame in recieved data
    for (int i = 0; i < data_length; ++i) {
        // address byte
        switch (FrameGet(buffer[i])) {
        case FRAME_ADDR_FISH1:
            // current activate fish
            if (ui->slct_cmbx_fish->currentText() == "Fish1"){
                this->serial_rec_data_process();
            }
            break;
        case FRAME_ADDR_FISH2:
            // current activate fish
            if (ui->slct_cmbx_fish->currentText() == "Fish2"){
                this->serial_rec_data_process();
            }
            break;
        case FRAME_ADDR_FISH3:
            // current activate fish
            if (ui->slct_cmbx_fish->currentText() == "Fish3"){
                this->serial_rec_data_process();
            }
            break;
        case 0x00:
            break;
        default:
            qDebug() << "Address process error";
            break;
        }
    }
}

/**
 * Function name: FrameGet(uint8_t byte)
 * Brief: Get complete frame from recieved data
 * Author: GJH
 * Paras: (uint8_t) byte: each byte in recieved data
 * Return: (uint8_t) rec_data[0]: address byte of one complete frame
 *                          0x00: cannot find complete frame
 * Version: 0.1
 * See:
 * Date: 2020.1.9
**/
uint8_t MainWidget::FrameGet(uint8_t byte)
{
    // FRAME_HEAD_H
    if (byte == FRAME_HEAD_H){
        rec_flag = rec_flag | FRAME_HEAD_FLAG;
        rec_data[rec_index] = byte;
        rec_index++;
    }
    // FRAME_HEAD_L
    else if (byte == FRAME_HEAD_L)
    {
        // real FRAME_HEAD_L
        if (rec_flag & FRAME_HEAD_FLAG)
        {
            //get rid of frame_head
            rec_flag = rec_flag & ~FRAME_OVER_FLAG;
            rec_index = 0;
        }
        // fake FRAME_HEAD_L, this is a data byte
        else
        {
            rec_data[rec_index] = byte;
            ++rec_index;
            rec_flag = rec_flag & ~FRAME_HEAD_FLAG;
        }
    }
    // other byte
    else
    {
        rec_data[rec_index] = byte;
        rec_flag &= ~FRAME_HEAD_FLAG;
        rec_index++;
        // rec_index equals frame length rec_data[2]
        if (rec_index == rec_data[2])
        {
            // FRAME_TAIL
            if (rec_data[rec_index - 1] == FRAME_TAIL)
            {
                rec_flag |= FRAME_OVER_FLAG;
                // xor bit check
                if (this->xor_check(rec_data)[0]){
                    return rec_data[0];
                }
                else{
                    return 0x00;
                }
            }
        }
        // overflow
        else if(rec_index == BUFFER_MAX_SIZE){
            rec_index--;
        }
    }
    return 0x00;
}

/**
 * Function name: xor_check(uint8_t *p)
 * Brief: Recieved data frame xor byte check
 * Author: GJH
 * Paras: (uint8_t) *p: point to the first byte of one frame data which needs xor check
 * Return: (uint8_t*) data_byte[0]: xor check flag, 1 represents pass, 0 represents fail
 *                    data_byte[1]: xor bit
 * Version: 0.1
 * See:
 * Date: 2020.1.9
**/
uint8_t* MainWidget::xor_check(uint8_t *data_byte)
{
    uint8_t xor_byte = 0x00;
    // do ^ operation for each bit in rec_data[]
    for (int i = 0; i < *(data_byte + 2) - 2; ++i) {
        xor_byte ^= *(data_byte + i);
        //qDebug() << xor_byte;
    }
    // compare result and xor_bit
    if ((xor_byte & 0xff) == *(data_byte + (*(data_byte + 2) - 2))){
        xor_result[0] = 1;
    }
    else {
        xor_result[0] = 0;
    }
    xor_result[1] = xor_byte;
    return xor_result;
}

/**
 * Function name: serial_rec_data_display()
 * Brief: Process and display recieved data from serialport
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: connection_confirm(uint8_t address)
 *      webview/FishMap.html->current_location()
 * Date: 2020.1.9
**/
void MainWidget::serial_rec_data_process()
{
    Stm32_Data_Package stm32_data;
    PolaV6_Data_Package polav6_data;
    Base_Frame base_frame;
    QString current_location_cmd;
    switch (rec_data[3]) {
    // stm32 data
    case FRAME_FUNC_STM32:
        memcpy(&stm32_data, &rec_data[4], sizeof(stm32_data));
        ui->envir_label_text_deepth->setText(QString::number(stm32_data.deepth, 'f', 2));
        ui->envir_label_text_temper->setText(QString::number(stm32_data.temper, 'f', 2));
        ui->envir_label_text_volt->setText(QString::number(stm32_data.volt * 9.0, 'f', 3));
        ui->envir_label_text_curr->setText(QString::number(stm32_data.curr, 'f', 3));
        ui->xsens_label_text_roll->setText(QString::number(stm32_data.roll, 'f', 2));
        ui->xsens_label_text_pitch->setText(QString::number(stm32_data.pitch, 'f', 2));
        ui->xsens_label_text_yaw->setText(QString::number(stm32_data.yaw, 'f', 2));
        ui->mtr_dsply_label_text_pumpPosi->setText(QString::number(stm32_data.pump_posi));
        ui->mtr_dsply_label_text_massPosi->setText(QString::number(stm32_data.mass_posi));
        ui->mtr_dsply_label_text_pushMotor->setText(QString::number(stm32_data.push_motor));
        ui->mtr_dsply_label_text_headSteer->setText(QString::number(stm32_data.head_steer));
        ui->mtr_dsply_label_text_pitchSteer->setText(QString::number(stm32_data.pitch_steer));
        // front leak
        if ((uint16_t)stm32_data.leak / 100){
            ui->leak_tabel_text_front->setText("Leak");
            ui->leak_tabel_text_front->setStyleSheet("font:12pt Calibri; color:red");
        }
        else {
            ui->leak_tabel_text_front->setText("Normal");
            ui->leak_tabel_text_front->setStyleSheet("font:12pt Calibri; color:green");
        }
        stm32_data.leak =(uint16_t)stm32_data.leak % 100;
        // mid leak
        if ((uint16_t)stm32_data.leak / 10){
            ui->leak_tabel_text_mid->setText("Leak");
            ui->leak_tabel_text_mid->setStyleSheet("font:12pt Calibri; color:red");
        }
        else {
            ui->leak_tabel_text_mid->setText("Normal");
            ui->leak_tabel_text_mid->setStyleSheet("font:12pt Calibri; color:green");
        }
        stm32_data.leak =(uint16_t)stm32_data.leak % 10;
        // tail leak
        if ((uint8_t)stm32_data.leak){
            ui->leak_tabel_text_tail->setText("Leak");
            ui->leak_tabel_text_tail->setStyleSheet("font:12pt Calibri; color:red");
        }
        else if (!(uint8_t)stm32_data.leak){
            ui->leak_tabel_text_tail->setText("Normal");
            ui->leak_tabel_text_tail->setStyleSheet("font:12pt Calibri; color:green");
        }
        // record stm32 data
        if (local_record_flag){
            record_file_init("stm32");
            local_record_stm32(stm32_data);
            record_file_close();
        }
        this->connection_confirm(rec_data[0]);
        break;
    // pola v6 data
    case FRAME_FUNC_POLAV6:
        memcpy(&polav6_data, &rec_data[4], sizeof(polav6_data));
        ui->polav6_label_text_navi_tim->setText(QString::number(polav6_data.navi_time_ms));
        ui->polav6_label_text_long->setText(QString::number(polav6_data.longtitude / 10000000.0, 'f', 6));
        ui->polav6_label_text_lat->setText(QString::number(polav6_data.latitude / 10000000.0, 'f', 6));
        ui->polav6_label_text_height->setText(QString::number(polav6_data.height, 'f', 2));
        ui->polav6_label_text_head->setText(QString::number(polav6_data.GPS_head, 'f', 2));
        ui->polav6_label_text_gps_v->setText(QString::number(polav6_data.GPS_v, 'f', 2));
        ui->polav6_label_text_acc_x->setText(QString::number(polav6_data.acc_x, 'f', 2));
        ui->polav6_label_text_acc_y->setText(QString::number(polav6_data.acc_y, 'f', 2));
        ui->polav6_label_text_acc_z->setText(QString::number(polav6_data.acc_z, 'f', 2));
        ui->polav6_label_text_v_east->setText(QString::number(polav6_data.v_east, 'f', 2));
        ui->polav6_label_text_v_north->setText(QString::number(polav6_data.v_north, 'f', 2));
        ui->polav6_label_text_v_sky->setText(QString::number(polav6_data.v_sky, 'f', 2));
        ui->polav6_label_text_omg_x->setText(QString::number(polav6_data.omg_x, 'f', 2));
        ui->polav6_label_text_omg_y->setText(QString::number(polav6_data.omg_y, 'f', 2));
        ui->polav6_label_text_omg_z->setText(QString::number(polav6_data.omg_z, 'f', 2));
        ui->polav6_label_text_pitch->setText(QString::number(polav6_data.pitch, 'f', 2));
        ui->polav6_label_text_yaw->setText(QString::number(polav6_data.yaw, 'f', 2));
        ui->polav6_label_text_roll->setText(QString::number(polav6_data.roll, 'f', 2));      
        ui->polav6_label_text_gps_head->setText(QString::number(polav6_data.gps_heading, 'f', 2));
        ui->polav6_label_text_mag_head->setText(QString::number(polav6_data.mag_heading, 'f', 2));
        ui->polav6_label_text_gps_long->setText(QString::number(polav6_data.gps_long / 10000000.0, 'f', 2));
        ui->polav6_label_text_gps_lat->setText(QString::number(polav6_data.gps_lat / 10000000.0, 'f', 2));


        // update current location in map(javascript)
        longtitude = polav6_data.longtitude / 10000000.0;
        latitude = polav6_data.latitude / 10000000.0;

        // record polav6 data
        if (local_record_flag){
            record_file_init("polav6");
            local_record_polav6(polav6_data);
            record_file_close();
        }

        // compass display
        m_compass->update_compass(polav6_data.mag_heading);
        break;
    // motor feedback
    case FRAME_FUNC_MOTOR:
        send_mtr_para_timer = 0;
        break;
    // connection confirm
    case FRAME_FUNC_CONNECTION:
        memcpy(&base_frame, &rec_data[0], sizeof(base_frame));
        this->connection_confirm(rec_data[0]);
        break;
    case COM_TEST:
        ++rec_pack_count;
        ui->comtst_label_text_rec->setText(QString::number(rec_pack_count));
        loss = (send_pack_count - rec_pack_count) / send_pack_count;
        ui->comtst_label_text_loss->setText(QString::number(loss, 'f', 2));
        break;
    default:
        break;
    }
}

/**
 * Function name: connection_confirm(uint8_t address)
 * Brief: Send connection confirm frame
 * Author: GJH
 * Paras: (uint8_t) address: fish address
 * Return: Void
 * Version: 0.1
 * See: xor_check(uint8_t *data_byte)
 *      serial_write_data(uint8_t *start_byte, uint8_t length)
 * Date: 2020.1.9
**/
void MainWidget::connection_confirm(uint8_t address)
{
    Base_Frame base_frame;
    base_frame.head_h = FRAME_HEAD_H;
    base_frame.head_l = FRAME_HEAD_L;
    base_frame.addr = address;
    base_frame.rw = FRAME_WRITE;
    base_frame.len = sizeof(base_frame) - 2;
    base_frame.func_id = FRAME_FUNC_CONNECTION;
    uint8_t *p_base_frame;
    p_base_frame = &base_frame.addr;
    // calculate xor check bit
    base_frame.xor_check = this->xor_check(p_base_frame)[1];
    base_frame.tail = FRAME_TAIL;
    // send connection confirm frame
    serial_write_data(&base_frame.head_h, base_frame.len+2);
}

/**
 * Function name: serial_write_data(uint8_t *start_byte, uint8_t length)
 * Brief: Send data from serialport
 * Author: GJH
 * Paras: (uint8_t*) start_byte: first byte of sended data
 *        (uint8_t)  length: length of sended data
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.9
**/
void MainWidget::serial_write_data(uint8_t* start_byte, uint8_t length)
{
    if (m_serialport->isOpen())
    {
        // thread lock
        if (m_mutex->tryLock(5) == true){
            m_serialport->write((char*)start_byte, length);
            m_mutex->unlock();
        }
    }
}

/**
 * Function name: on_mtr_spinBox_XXX_valueChanged and on_mtr_horSldr_XXX_valueChanged
 * Brief: Bind motor spinBox and slider value change slots
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.10
**/
void MainWidget::on_mtr_spinBox_pushMotor_valueChanged(int arg1){
    ui->mtr_horSldr_pushMotor->setValue(arg1);
}
void MainWidget::on_mtr_horSldr_pushMotor_valueChanged(int value)
{
    ui->mtr_spinBox_pushMotor->setValue(value);
}
void MainWidget::on_mtr_spinBox_headSteer_valueChanged(int arg1)
{
    ui->mtr_horSldr_headSteer->setValue(3000 - arg1);
}
void MainWidget::on_mtr_horSldr_headSteer_valueChanged(int value)
{
    ui->mtr_spinBox_headSteer->setValue(3000 - value);
}
void MainWidget::on_mtr_spinBox_pitchSteer_valueChanged(int arg1)
{
    ui->mtr_horSldr_pitchSteer->setValue(arg1);
}
void MainWidget::on_mtr_horSldr_pitchSteer_valueChanged(int value)
{
    ui->mtr_spinBox_pitchSteer->setValue(value);
}
void MainWidget::on_posi_spinBox_pumpPosi_valueChanged(int arg1)
{
    ui->posi_horSldr_pumpPosi->setValue(arg1);
}
void MainWidget::on_posi_horSldr_pumpPosi_valueChanged(int value)
{
    ui->posi_spinBox_pumpPosi->setValue(value);
}
void MainWidget::on_posi_spinBox_massPosi_valueChanged(int arg1)
{
    ui->posi_horSldr_massPosi->setValue(arg1);
}
void MainWidget::on_posi_horSldr_massPosi_valueChanged(int value)
{
    ui->posi_spinBox_massPosi->setValue(value);
}

/**
 * Function name: on_mtr_btn_load_clicked()
 * Brief: mtr_btn_load clicked slot, send motor control and posture control parameters to serialport
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: get_fish_address()
 *      xor_check(uint8_t *data_byte)
 *      serial_write_data(uint8_t* start_byte, uint8_t length)
 * Date: 2020.1.10
**/
void MainWidget::on_mtr_btn_load_clicked()
{
    // send motor ctrl parameters
    if (!send_mtr_para_timer)
        send_mtr_para_timer = startTimer(1000);

    Motor_Para_Package motor_para;
    Motor_Frame motor_frame;
    motor_para.push_motor = ui->mtr_spinBox_pushMotor->value();
    motor_para.head_steer = ui->mtr_spinBox_pitchSteer->value();
    motor_para.pitch_steer = ui->mtr_spinBox_headSteer->value();
    motor_para.status_ctrl = 0x01;
    if (ui->mtr_checkBox_bbb_ctrl->isChecked()){
        motor_para.status_ctrl += 10;
    }
    if (ui->log_checkBox_bbb_record->isChecked()){
        motor_para.status_ctrl += 1;
    }
    motor_para.power_ctrl = 0x00;
    if (ui->pwr_checkBox_polav6->isChecked()){
        motor_para.power_ctrl += 100000;
    }
    if (ui->pwr_checkBox_gprs->isChecked()){
        motor_para.power_ctrl += 10000;
    }
    if (ui->pwr_checkBox_sbd9602->isChecked()){
        motor_para.power_ctrl += 1000;
    }
    if (ui->pwr_checkBox_lora->isChecked()){
        motor_para.power_ctrl += 100;
    }
    if (ui->pwr_checkBox_usbl->isChecked()){
        motor_para.power_ctrl += 10;
    }
    if (ui->pwr_checkBox_bbb->isChecked()){
        motor_para.power_ctrl += 1;
    }
    motor_para.reserved = 10;

    motor_frame.head_h = FRAME_HEAD_H;
    motor_frame.head_l = FRAME_HEAD_L;
    motor_frame.addr = current_fish;
    motor_frame.rw = FRAME_WRITE;
    motor_frame.len = sizeof(motor_para) + 6;
    motor_frame.func_id = FRAME_FUNC_MOTOR;
    motor_frame.motor_para = motor_para;
    uint8_t *p_motor_frame;
    p_motor_frame = &motor_frame.addr;
    motor_frame.xor_check = this->xor_check(p_motor_frame)[1];
    motor_frame.tail = FRAME_TAIL;
    serial_write_data(&motor_frame.head_h, motor_frame.len + 2);

//结构体未对齐用以下发送方式
//    serial_write_data(&motor_frame.head_h, 6);
//    m_serialport->write((char*)&motor_frame.motor_para, sizeof(motor_para));
//    serial_write_data(&motor_frame.xor_check, 2);

    // clear control byte
    motor_para.power_ctrl = 0x00;
    motor_para.status_ctrl = 0x00;

}

/**
 * Function name: on_pwr_checkBox_XXX_stateChanged()
 * Brief: Power control state Changed slot
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.10
**/
void MainWidget::on_pwr_checkBox_polav6_stateChanged()
{
    if (ui->pwr_checkBox_polav6->isChecked()){
        ui->pwr_checkBox_polav6->setStyleSheet("color:green");
    }
    else {
        ui->pwr_checkBox_polav6->setStyleSheet("color:red");
    }
}
void MainWidget::on_pwr_checkBox_gprs_stateChanged()
{
    if (ui->pwr_checkBox_gprs->isChecked()){
        ui->pwr_checkBox_gprs->setStyleSheet("color:green");
    }
    else {
        ui->pwr_checkBox_gprs->setStyleSheet("color:red");
    }
}
void MainWidget::on_pwr_checkBox_sbd9602_stateChanged()
{
    if (ui->pwr_checkBox_sbd9602->isChecked()){
        ui->pwr_checkBox_sbd9602->setStyleSheet("color:green");
    }
    else {
        ui->pwr_checkBox_sbd9602->setStyleSheet("color:red");
    }
}
void MainWidget::on_pwr_checkBox_lora_stateChanged()
{
    if (ui->pwr_checkBox_lora->isChecked()){
        ui->pwr_checkBox_lora->setStyleSheet("color:green");
    }
    else {
        ui->pwr_checkBox_lora->setStyleSheet("color:red");
    }
}
void MainWidget::on_pwr_checkBox_usbl_stateChanged()
{
    if (ui->pwr_checkBox_usbl->isChecked()){
        ui->pwr_checkBox_usbl->setStyleSheet("color:green");
    }
    else {
        ui->pwr_checkBox_usbl->setStyleSheet("color:red");
    }
}
void MainWidget::on_pwr_checkBox_bbb_stateChanged()
{
    if (ui->pwr_checkBox_bbb->isChecked()){
        ui->pwr_checkBox_bbb->setStyleSheet("color:green");
    }
    else {
        ui->pwr_checkBox_bbb->setStyleSheet("color:red");
    }
}

/**
 * Function name: on_pwr_btn_apply_clicked()
 * Brief: Apply power control status
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: on_mtr_btn_load_clicked()
 * Date: 2020.1.10
**/
void MainWidget::on_pwr_btn_apply_clicked()
{
    this->on_mtr_btn_load_clicked();
}

/**
 * Function name: record_file_init(QString flag)
 * Brief: Init local record file
 * Author: GJH
 * Paras: (QString) flag: Define file name as yyyy_MM_dd_flag_log.txt
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.10
**/
void MainWidget::record_file_init(QString flag)
{
    QDateTime current_time = QDateTime::currentDateTime();
    QString file_name = current_time.toString("yyyy_MM_dd");
    logfile = new QFile(tr("E:/Code/FishUpper/log/%1_%2_log.txt").arg(file_name).arg(flag));
    if (!logfile->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        QMessageBox::critical(this, tr("Local record error, cannot open file"), tr("%1")
                              .arg(logfile->errorString()));
}

/**
 * Function name: record_file_close
 * Brief: Close local record file
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.10
**/
void MainWidget::record_file_close()
{
    logfile->close();
    delete logfile;
}

/**
 * Function name: local_record_stm32(Stm32_Data_Package stm32_data)
 * Brief: Save stm32 data to local
 * Author: GJH
 * Paras: (Stm32_Data_Package) stm32_data: Saved stm32 data
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.10
**/
void MainWidget::local_record_stm32(Stm32_Data_Package stm32_data)
{
    QTextStream logout(logfile);
    QDateTime current_time = QDateTime::currentDateTime();
    logout << "[" << current_time.toString("yyyy-MM-dd hh:mm:ss") << "] " << "Deepth: " << stm32_data.deepth << "   " <<
              "Temperature: " << stm32_data.temper << "   " << "Xsens_Roll: " << stm32_data.roll << "   " <<
              "Xsens_Pitch: " << stm32_data.pitch << "   " << "Xsens_yaw: " << stm32_data.yaw << "   " <<
              "Voltage: " << stm32_data.volt * 9 << "   " << "Current: " << stm32_data.curr << "   " <<
              "pump_Position: " << stm32_data.pump_posi << "   " << "Mass_Position: " << stm32_data.mass_posi << "   " <<
              "Leak: " << stm32_data.leak << "   " << "Push_Motor: " << stm32_data.push_motor << "   " <<
              "Head_Steer: " << stm32_data.head_steer << "   " << "Pitch_Steer: " << stm32_data.pitch_steer << endl;
}

/**
 * Function name: local_record_polav6(PolaV6_Data_Package polav6_data)
 * Brief: Save polav6 data to local
 * Author: GJH
 * Paras: (PolaV6_Data_Package) polav6_data: Saved polav6 data
 * Return: Void
 * Version: 0.1
 * See:
 * Date:2020.1.10
**/
void MainWidget::local_record_polav6(PolaV6_Data_Package polav6_data)
{
    QTextStream logout(logfile);
    QDateTime current_time = QDateTime::currentDateTime();
    logout << "[" << current_time.toString("yyyy-MM-dd hh:mm:ss") << "] " << "Time: " << polav6_data.navi_time_ms << "   " <<
              "Longtitude: " << polav6_data.longtitude / 10000000.0 << "   " << "Latitude: " << polav6_data.latitude / 10000000.0 << "   " <<
              "Height: " << polav6_data.height << "   " << "GPS_Heading: " << polav6_data.GPS_head << "  " <<
              "GPS_V: " << polav6_data.GPS_v << "   " << "Acc_x: " << polav6_data.acc_x << "   " <<
              "Acc_y: " << polav6_data.acc_y << "   " << "Acc_z: " << polav6_data.acc_z << "   " <<
              "V East: " << polav6_data.v_east << "   " << "V North: " << polav6_data.v_north << "   " <<
              "V Sky: " << polav6_data.v_sky << "   " << "Omg_x: " << polav6_data.omg_x << "   " <<
              "Omg_y: " << polav6_data.omg_y << "   " << "Omg_z: " << polav6_data.omg_z << "   " <<
              "Roll: " << polav6_data.roll << "   " << "Pitch: " << polav6_data.pitch << "   " <<
              "yaw: " << polav6_data.yaw << "   " << "GPS_heading: " << polav6_data.gps_heading << "   "<<
              "Mag_heading: " << polav6_data.mag_heading << "GPS_longtitude: " << polav6_data.gps_long /  10000000.0 << "   "
              "GPS_latitude: " << polav6_data.gps_lat /  10000000.0 << endl;
}

/**
 * Function name: on_log_btn_apply_clicked()
 * Brief: log_btn_apply clicked slot, confirm the state of recording data
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.1.10
**/
void MainWidget::on_log_btn_apply_clicked()
{
    if (ui->log_checkBox_local_record->isChecked()){
        local_record_flag = true;
    }
    else {
        local_record_flag = false;
    }
    this->on_mtr_btn_load_clicked();
}

/**
 * Function name: on_auto_btn_add_locs_clicked()
 * Brief: auto_btn_add clicked slot, add points to tabwidget and show them in map
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: webview/FishMap.html->set_destination();
 * Date: 2020.1.13
**/
void MainWidget::on_auto_btn_add_locs_clicked()
{
    if (ui->auto_lineEdit_longt->text().isEmpty() || ui->auto_lineEdit_longt->text().isEmpty()){
        return;
    }
    if (location_count < 4){
        if(ui->auto_tabWidget_locs->item(location_count,0)->text() == "-"){
            ui->auto_tabWidget_locs->item(location_count,0)->setText(ui->auto_lineEdit_longt->text());
            ui->auto_tabWidget_locs->item(location_count,1)->setText(ui->auto_lineEdit_lat->text());
            QString add_point_cmd = QString("set_destination(%1, %2, %3);").arg(ui->auto_lineEdit_longt->text())
                    .arg(ui->auto_lineEdit_lat->text()).arg(location_count);
            m_webview->page()->runJavaScript(add_point_cmd);
            ui->auto_lineEdit_longt->clear();
            ui->auto_lineEdit_lat->clear();
            ++location_count;
        }
    }
}

/**
 * Function name: on_auto_btn_locate_clicked()
 * Brief: auto_btn_locate clicked slot, show point in map according to lineEdit
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: webview/Fishmap.html->locate()
 * Date: 2020.2.4
**/
void MainWidget::on_auto_btn_locate_clicked()
{
    // coor_type: 0->WGS84, 1->BD09
    uint8_t coor_type = 0;
    if (ui->auto_lineEdit_longt->text().isEmpty() || ui->auto_lineEdit_longt->text().isEmpty()){
        return;
    }
    QString add_point_cmd = QString("locate(%1, %2, %3);").arg(ui->auto_lineEdit_longt->text())
            .arg(ui->auto_lineEdit_lat->text()).arg(coor_type);
    m_webview->page()->runJavaScript(add_point_cmd);
}

/**
 * Function name: on_auto_btn_clear_clicked()
 * Brief: auto_btn_clear clicked slot, clear tabwidget and map
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: webview/Fishmap.html->reset()
 * Date: 2020.1.13
**/
void MainWidget::on_auto_btn_clear_clicked()
{
    // reset map in javascript
    QString reset_cmd = QString("reset();");
    m_webview->page()->runJavaScript(reset_cmd);
        this->init_tabwidget_locs();
}

/**
 * Function name: on_auto_btn_delete_clicked()
 * Brief: auto_btn_delete clicked slot, delete selected locations(longtitude and latitude) in tabelwidget
 * Author: GJH
 * Paras: None
 * Return:
 * Version: 0.1
 * See:
 * Date: 2020.1.13
**/
void MainWidget::on_auto_btn_delete_clicked()
{
    if (ui->auto_tabWidget_locs->item(0, 0)->text() != "-"){
        // delete 1st 2nd 3rd locations, need to move data in tabwidget
        if (ui->auto_tabWidget_locs->currentRow() < 3){
            // after deleted data
            for (int i = ui->auto_tabWidget_locs->currentRow(); i < 3; ++i){
                // move data upward
                if (ui->auto_tabWidget_locs->item(i + 1, 0)->text() != "-"){
                    ui->auto_tabWidget_locs->item(i,0)->setText(ui->auto_tabWidget_locs->item(i + 1, 0)->text());
                    ui->auto_tabWidget_locs->item(i,1)->setText(ui->auto_tabWidget_locs->item(i + 1, 1)->text());
                }
                // last data, set "-"
                else {
                    ui->auto_tabWidget_locs->item(i, 0)->setText("-");
                    ui->auto_tabWidget_locs->item(i, 1)->setText("-");
                    break;
                }
            }
        }

        // delete corresponding marker in javascript
        QString delete_marker_cmd = QString("delete_marker(%1);").arg(ui->auto_tabWidget_locs->currentRow());
        m_webview->page()->runJavaScript(delete_marker_cmd);

        ui->auto_tabWidget_locs->item(3,0)->setText("-");
        ui->auto_tabWidget_locs->item(3,1)->setText("-");
        if (location_count > 0)
            --location_count;
        ui->auto_tabWidget_locs->setCurrentItem(NULL);
    }
}

/**
 * Function name: on_auto_btn_execute_clicked()
 * Brief: auto_btn_execute clicked slot, send location(longtitude and latitude) value to serialport
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: get_fish_address()
 *      xor_check(uint8_t *data_byte)
 *      serial_write_data(uint8_t* start_byte, uint8_t length)
 * Date: 2020.1.13
**/
void MainWidget::on_auto_btn_execute_clicked()
{
    Auto_Para_Package auto_para;
    Auto_Frame auto_frame;

    auto_para.formation_plan = 2;
    auto_para.count = location_count;
    for (int i = 0; i < 4; ++i) {
        if (i < auto_para.count){
            auto_para.coordinates[i][0] = ui->auto_tabWidget_locs->item(i, 0)->text().toFloat();
            auto_para.coordinates[i][1] = ui->auto_tabWidget_locs->item(i, 1)->text().toFloat();
        }
        else {
            auto_para.coordinates[i][0] = 0;
            auto_para.coordinates[i][1] = 0;
        }
    }
    auto_para.reserved = 1;

    auto_frame.head_h = FRAME_HEAD_H;
    auto_frame.head_l = FRAME_HEAD_L;
    auto_frame.addr = current_fish;
    auto_frame.rw = FRAME_WRITE;
    auto_frame.len = sizeof(auto_para) + 6;
    auto_frame.func_id = FRAME_FUNC_AUTO;
    auto_frame.auto_para = auto_para;
    uint8_t *p_auto_frame;
    p_auto_frame = &auto_frame.addr;
    auto_frame.xor_check = this->xor_check(p_auto_frame)[1];
    auto_frame.tail = FRAME_TAIL;
    serial_write_data(&auto_frame.head_h, auto_frame.len + 2);
//结构体未对齐用以下发送方式
//    serial_write_data(&auto_frame.head_h, 6);
//    m_serialport->write((char*)&auto_frame.auto_para, sizeof(auto_para));
//    serial_write_data(&auto_frame.xor_check, 2);

    this->on_auto_btn_clear_clicked();

    QString reset_cmd = QString("reset();");
    m_webview->page()->runJavaScript(reset_cmd);
}

/**
 * Function name: on_mtr_btn_close_all_clicked()
 * Brief:  mtr_btn_close_all clicked slot, close all motor
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: on_mtr_btn_default_clicked()
 *      on_mtr_btn_load_clicked()
 * Date: 2020.1.13
**/
void MainWidget::on_mtr_btn_close_all_clicked()
{
    ui->mtr_spinBox_pushMotor->setValue(500);
    ui->mtr_spinBox_headSteer->setValue(1500);
    ui->mtr_spinBox_pitchSteer->setValue(1500);
    this->on_mtr_btn_load_clicked();
}

/**
 * Function name: on_posi_btn_load_clicked()
 * Brief: posi_btn_load clicked slot, send pumpPosi and massPosi value to serialport
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: get_fish_address()
 *      xor_check(uint8_t *data_byte)
 *      serial_write_data(uint8_t* start_byte, uint8_t length)
 * Date: 2020.1.13
**/
void MainWidget::on_posi_btn_load_clicked()
{

    // send posture ctrl parameters
    Posture_Para_Package posture_para;
    Posture_Frame posture_frame;

    posture_para.mass_position = ui->posi_spinBox_massPosi->value();
    posture_para.pump_position = ui->posi_spinBox_pumpPosi->value();
    posture_para.reserved_1 = 1;
    posture_para.reserved_2 = 2;
    posture_para.reserved_3 = 3;

    posture_frame.head_h = FRAME_HEAD_H;
    posture_frame.head_l = FRAME_HEAD_L;
    posture_frame.addr = current_fish;
    posture_frame.rw = FRAME_WRITE;
    posture_frame.len = sizeof(posture_para) + 6;
    posture_frame.func_id = FRAME_FUNC_POSTURE;
    posture_frame.posture_para = posture_para;
    uint8_t *p_pose_frame;
    p_pose_frame = &posture_frame.addr;
    posture_frame.xor_check = this->xor_check(p_pose_frame)[1];
    posture_frame.tail = FRAME_TAIL;
    serial_write_data(&posture_frame.head_h, posture_frame.len + 2);

//结构体未对齐用以下发送方式
//    serial_write_data(&posture_frame.head_h, 6);
//    m_serialport->write((char*)&posture_frame.posture_para, sizeof(posture_para));
//    serial_write_data(&posture_frame.xor_check, 2);
}

/**
 * Function name: on_posi_btn_reset_clicked()
 * Brief: posi_btn_reset clicked slot, set pumpPosi and massPosi to default value
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: on_posi_btn_default_clicked()
 *      on_posi_btn_load_clicked()
 * Date: 2020.1.13
**/
void MainWidget::on_posi_btn_reset_clicked()
{
    ui->posi_spinBox_pumpPosi->setValue(200);
    ui->posi_spinBox_massPosi->setValue(4000);
    this->on_posi_btn_load_clicked();
}

/**
 * Function name: init_tabwidget_locs()
 * Brief: initialize tabwidget with "-" and reset location_count
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.2.4
**/
void MainWidget::init_tabwidget_locs()
{
    ui->auto_tabWidget_locs->setItem(0, 0, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(0, 1, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(1, 0, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(1, 1, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(2, 0, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(2, 1, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(3, 0, new QTableWidgetItem("-"));
    ui->auto_tabWidget_locs->setItem(3, 1, new QTableWidgetItem("-"));
    location_count = 0;
}

/**
 * Function name: map_clicked(QString longtitude, QString latitude)
 * Brief: show longtitude and latitude of clicked point in lineEdit
 * Author: GJH
 * Paras: (QString) longtitude
 *        (QString) latitude
 * Return: Void
 * Version: 0.1
 * See: webview/Fishmap.html->clicked_listener()
 * Date: 2020.2.4
**/
void MainWidget::map_clicked(QString longtitude, QString latitude)
{
    ui->auto_lineEdit_longt->setText(longtitude);
    ui->auto_lineEdit_lat->setText(latitude);
}

/**
 * Function name: on_auto_btn_find_me_clicked()
 * Brief: auto_btn_find_me clicked slot, set map center to current location
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: webview/Fishmap.html->pan_to_current()
 * Date: 2020.2.4
**/
void MainWidget::on_auto_btn_find_me_clicked()
{
    // for test
//    static float lng = 120.3364982;
//    static float lat = 30.3137504;
//    QString current_location_cmd = QString("current_location(%1, %2);").arg(lng).arg(lat);
//    m_webview->page()->runJavaScript(current_location_cmd);
//    lng = lng + 0.05;
    if(!BMap_timer)
        BMap_timer = startTimer(5000);

    QString pan_to_current_cmd = QString("pan_to_current();");
    m_webview->page()->runJavaScript(pan_to_current_cmd);
}

/**
 * Function name: on_js_btn_refresh_clicked()
 * Brief: js_btn_refresh clicked slot, scan avaliable joystick
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: QJoysticks/Sources/src/QJoysticks.cpp -> updateInterfaces();
 * Date: 2020.2.11
**/
void MainWidget::on_js_btn_refresh_clicked()
{
    ui->js_cobx->clear();
    m_joystick->updateInterfaces();
    QStringList js_names = m_joystick->deviceNames();
    foreach (QString name, js_names){
        ui->js_cobx->addItem(name);
    }
}

/**
 * Function name: on_js_btn_connect_clicked()
 * Brief: Enabel joystick
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.2.11
**/
void MainWidget::on_js_btn_connect_clicked()
{
    if (ui->js_cobx->currentText() == ""){
        return;
    }
    if (joystick_connect_state){
        joystick_connect_state = false;
        ui->js_btn_connect->setText("Connect");
        ui->js_btn_refresh->setEnabled(true);
        ui->mtr_checkBox_bbb_ctrl->setChecked(false);

        if (push_mtr_timer)
            push_mtr_timer = 0;
        if (pitch_steer_timer)
            pitch_steer_timer = 0;
        if (head_steer_timer)
            head_steer_timer = 0;
    }
    else {
        if (m_joystick->joystickExists(0)){
            ui->mtr_checkBox_bbb_ctrl->setChecked(false);
            ui->js_btn_connect->setText("Disconnect");
            ui->js_btn_refresh->setDisabled(true);
            joystick_connect_state = true;

            if (!push_mtr_timer)
                push_mtr_timer = startTimer(20);
            if (!pitch_steer_timer)
                pitch_steer_timer = startTimer(20);
            if (!head_steer_timer)
                head_steer_timer = startTimer(20);
        }
    }
}

/**
 * Function name: joysitck_axis()
 * Brief: QJoysticks->axisChanged slot, use joystick to modify motor parameters
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.2.11
**/
void MainWidget::joysitck_axis(int js_index, int axis_index, qreal value)
{
//    if (!send_mtr_para_timer)
//        send_mtr_para_timer = startTimer(1000);
    if (joystick_connect_state){
        if (m_joystick->joystickExists(js_index)){
            switch (axis_index){
            case PUSH_MORTOR:
                push_motor_para = value;
                break;
            case HEAD_STEER:
                head_steer_para = value;
                break;
            case PITCH_STEER:
                pitch_steer_para = value;
                break;
            default:
                break;
            }
        }
    }
}

/**
 * Function name: joystick_btn()
 * Brief: QJoysticks->buttonChanged slot, use joystick to modify motor parameters
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.2.11
**/
void MainWidget::joystick_btn(int js_index, int btn_index, bool is_pressed)
{
    int para = ui->mtr_spinBox_pushMotor->text().toUInt();
    if (joystick_connect_state){
        if (m_joystick->joystickExists(js_index)){
            switch (btn_index){
            case BRAKE_A:
                ui->mtr_spinBox_pushMotor->setValue(500);
                ui->mtr_spinBox_pushMotor->setValue(400);
                this->on_mtr_btn_load_clicked();
                break;
            case EXIT_B:
                this->on_js_btn_connect_clicked();
                break;
            case RESET_X:
                // set motor control parameters to default value
                ui->mtr_spinBox_pushMotor->setValue(500);
                ui->mtr_spinBox_headSteer->setValue(1500);
                ui->mtr_spinBox_pitchSteer->setValue(1500);
                this->on_mtr_btn_load_clicked();
                break;
            case SHIFT_Y:
                if (ui->mtr_spinBox_pushMotor->value() == 500) {
                    if (ui->mtr_checkBox_reverse->isChecked()) {
                        ui->mtr_checkBox_reverse->setChecked(false);
                    }
                    else {
                        ui->mtr_checkBox_reverse->setChecked(true);
                    }
                }
                break;
            case LB:
                if (para >= 550)
                    para -= 25;
                else if (para > 500)
                    para = 500;
                else if (para >= 50 && para < 500)
                    para -= 25;
                else if (para < 50)
                    para = 0;
                else if (para == 500 && ui->mtr_checkBox_reverse->isChecked())
                    para -= 25;
                ui->mtr_spinBox_pushMotor->setValue(para);
                send_mtr_para_timer = startTimer(1000);
                break;
            case RB:
                if (para >= 950)
                    para = 1000;
                else if (para > 500)
                    para += 25;
                else if (para >= 450 && para < 500)
                    para = 500;
                else if (para < 450)
                    para += 25;
                else if (para == 500 && !ui->mtr_checkBox_reverse->isChecked())
                    para += 25;
                ui->mtr_spinBox_pushMotor->setValue(para);
                send_mtr_para_timer = startTimer(1000);
                break;
            case START:
                this->on_mtr_btn_load_clicked();
            default:
                break;
            }
        }
    }
    else {
        qDebug() << "Joystick connect error!";
    }
}

/**
 * Function name: on_comtst_btn_test_clicked()
 * Brief: comtst_btn_test clicked slot, start com test
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.2.18
**/
void MainWidget::on_comtst_btn_test_clicked()
{
//    if (!m_serialport->isOpen()){
//        return;
//    }
//    send_pack_count = 0;
//    rec_pack_count = 0;
//    if (m_test_timer->isActive()){
//        m_test_timer->stop();
//        ui->comtst_btn_test->setText("Test");
//    }

//    else {
//        if (m_query_timer->isActive()){
//            m_query_timer->stop();
//        }
//        m_test_timer->start(500);
//        ui->comtst_btn_test->setText("Stop");
//    }
}

/**
 * Function name: com_test()
 * Brief: com test slot, send test data pack
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: serial_write_data()
 * Date: 2020.2.18
**/
void MainWidget::com_test()
{
    Test_Frame test_frame;
    test_frame.head_h = FRAME_HEAD_H;
    test_frame.head_l = FRAME_HEAD_L;
    test_frame.addr = current_fish;
    test_frame.rw = FRAME_WRITE;
    test_frame.len = sizeof(test_frame) - 2;
    test_frame.func_id = COM_TEST;
    test_frame.count = send_pack_count;
    uint8_t *p_test_frame;
    p_test_frame = &test_frame.addr;
    test_frame.xor_check = this->xor_check(p_test_frame)[1];
    test_frame.tail = FRAME_TAIL;
    serial_write_data(&test_frame.head_h, test_frame.len+2);
    ++send_pack_count;
    ui->comtst_label_text_send->setText(QString::number(send_pack_count));
}

void MainWidget::on_pushButton_clicked()
{
//    static float angle = 15;
//    m_compass->update_compass(angle);
//    angle += 15;
    //this->connection_confirm(01);
    Stm32_Data_Package stm32_data;
    record_file_init("stm32");
    local_record_stm32(stm32_data);
    record_file_close();
}

/**
 * Function name: on_fmt_btn_execute_clicked()
 * Brief: fmt_btn_execute clicked slot, start formation
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See: on_mtr_btn_load_clicked()
 * Date: 2020.5.11
**/
void MainWidget::on_fmt_btn_execute_clicked()
{
    Formation_Para_Package formation_para;
    Formation_Frame formation_frame;

    formation_para.status_ctrl = 0;
    if (ui->fmt_cmbx_plan->currentText() == "Plan0") {
        formation_para.plan = 0;
    }
    if (ui->fmt_cmbx_plan->currentText() == "Plan1") {
        formation_para.plan = 1;
    }
    if (ui->fmt_cmbx_plan->currentText() == "Plan2") {
        formation_para.plan = 2;
    }
    formation_para.distance = ui->fmt_lineEdit_text_distance->text().toFloat();
    formation_para.speed = ui->fmt_lineEdit_text_speed->text().toFloat();
    formation_para.depth = ui->fmt_lineEdit_text_depth->text().toFloat();
    formation_para.heading = ui->fmt_lineEdit_text_heading->text().toFloat();
    formation_para.time = ui->fmt_lineEdit_text_time->text().toFloat();

    formation_frame.head_h = FRAME_HEAD_H;
    formation_frame.head_l = FRAME_HEAD_L;
    formation_frame.addr = current_fish;
    formation_frame.rw = FRAME_WRITE;
    formation_frame.len = sizeof(formation_para) + 6;
    formation_frame.func_id = FRAME_FUNC_FORMATION;
    formation_frame.formation_para = formation_para;
    uint8_t *p_formation_frame;
    p_formation_frame = &formation_frame.addr;
    formation_frame.xor_check = this->xor_check(p_formation_frame)[1];
    formation_frame.tail = FRAME_TAIL;
    serial_write_data(&formation_frame.head_h, formation_frame.len + 2);
//结构体未对齐用以下发送方式
//    serial_write_data(&formation_frame.head_h, 6);
//    m_serialport->write((char*)&formation_frame.formation_para, sizeof(formation_para));
//    serial_write_data(&formation_frame.xor_check, 2);

     ui->mtr_checkBox_bbb_ctrl->setChecked(true);
//     send_mtr_para_timer = startTimer(500);
}

/**
 * Function name: timerEvent()
 * Brief: timer management (m_query_timer, push_mtr_timer, head_steer_timer, pitch_steer_timer)
 * Author: GJH
 * Paras: None
 * Return: Void
 * Version: 0.1
 * See:
 * Date: 2020.5.11
**/
void MainWidget::timerEvent(QTimerEvent *event)
{
    // send motion control para
    if (event->timerId() == send_mtr_para_timer) {
         this->on_mtr_btn_load_clicked();
    }

    // joystick push motor ctrl
    if (event->timerId() == push_mtr_timer) {
        if (ui->mtr_spinBox_pushMotor->value() >= 500 && !ui->mtr_checkBox_reverse->isChecked()) {
            ui->mtr_spinBox_pushMotor->setRange(500, 1000);
            ui->mtr_spinBox_pushMotor->setValue(ui->mtr_spinBox_pushMotor->value() - push_motor_para * 10);
        }
        if (ui->mtr_spinBox_pushMotor->value() <= 500 && ui->mtr_checkBox_reverse->isChecked()) {
            ui->mtr_spinBox_pushMotor->setRange(0, 500);
            ui->mtr_spinBox_pushMotor->setValue(ui->mtr_spinBox_pushMotor->value() - push_motor_para * 10);
        }
    }
    // joystick steer ctrl
    else if (event->timerId() == head_steer_timer) {
        ui->mtr_spinBox_headSteer->setValue(ui->mtr_spinBox_headSteer->value() - head_steer_para * 10);
    }
    else if (event->timerId() == pitch_steer_timer) {
        ui->mtr_spinBox_pitchSteer->setValue(ui->mtr_spinBox_pitchSteer->value() + pitch_steer_para * 10);
    }

    // map current location
    else if (event->timerId() == BMap_timer) {
        QString current_location_cmd;
        current_location_cmd = QString("current_location(%1, %2);").arg(longtitude).arg(latitude);
        m_webview->page()->runJavaScript(current_location_cmd);
    }
}

void MainWidget::on_slct_btn_apply_clicked()
{
    if (ui->slct_cmbx_fish->currentText() == "Fish1") {
        current_fish = FRAME_ADDR_FISH1;
        ui->comtst_label_text_current_fish->setText("Fish1");
    }
    if (ui->slct_cmbx_fish->currentText() == "Fish2") {
        current_fish = FRAME_ADDR_FISH2;
        ui->comtst_label_text_current_fish->setText("Fish2");
    }
    if (ui->slct_cmbx_fish->currentText() == "Fish3") {
        current_fish = FRAME_ADDR_FISH3;
        ui->comtst_label_text_current_fish->setText("Fish3");
    }
    if (ui->slct_cmbx_fish->currentText() == "BroadCast") {
        current_fish = FRAME_ADDR_BOARDCAST;
        ui->comtst_label_text_current_fish->setText("BroadCast");
    }
}
