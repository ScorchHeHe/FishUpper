#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "datastruct.h"
#include <QWidget>
#include <QString>
#include <QtSerialPort>
#include <QTimer>
#include <QMutex>
#include <QMessageBox>
#include <QByteArray>
#include <QFile>
#include <QtWebEngineWidgets/QWebEngineView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void on_serst_btn_refresh_clicked();

    void on_serst_btn_con_clicked();

    void serial_rec_data_addr_parse();

    void on_slct_btn_query_clicked();

    void query_data();

    void on_mtr_spinBox_pushMotor_valueChanged(int arg1);

    void on_mtr_horSldr_pushMotor_valueChanged(int value);

    void on_mtr_spinBox_headSteer_valueChanged(int arg1);

    void on_mtr_horSldr_headSteer_valueChanged(int value);

    void on_mtr_spinBox_pitchSteer_valueChanged(int arg1);

    void on_mtr_horSldr_pitchSteer_valueChanged(int value);

    void on_posi_spinBox_pumpPosi_valueChanged(int arg1);

    void on_posi_horSldr_pumpPosi_valueChanged(int value);

    void on_posi_spinBox_massPosi_valueChanged(int arg1);

    void on_posi_horSldr_massPosi_valueChanged(int value);

    void on_mtr_btn_default_clicked();

    void on_mtr_btn_load_clicked();

    void on_pwr_checkBox_polav6_stateChanged();

    void on_pwr_checkBox_gprs_stateChanged();

    void on_pwr_checkBox_sbd9602_stateChanged();

    void on_pwr_checkBox_lora_stateChanged();

    void on_pwr_checkBox_usbl_stateChanged();

    void on_pwr_checkBox_bbb_stateChanged();

    void on_pwr_btn_apply_clicked();

    void on_log_btn_apply_clicked();

    void on_auto_btn_add_locs_clicked();

    void on_auto_btn_clear_clicked();

    void on_auto_btn_delete_clicked();

    void on_auto_btn_execute_clicked();

    void on_mtr_btn_close_all_clicked();

    void on_posi_btn_default_clicked();

    void on_posi_btn_load_clicked();

    void on_posi_btn_reset_clicked();

private:
    Ui::MainWidget* ui;
    QSerialPort* m_serialport;
    QTimer* m_timer;
    QMutex* m_mutex;
    QFile* logfile;
    QWebEngineView* m_webview;

    // serialport recieved data buffer
    uint8_t rec_data[BUFFER_MAX_SIZE];
    uint8_t rec_flag = 0x00;
    uint16_t rec_index = 0x00;

    // xor check result and value
    uint8_t xor_result[2] {0, 0x00};

    // auto cruise destination coordinates count
    uint8_t location_count = 0;

    // local record enable flag
    bool local_record_flag = false;

    void scan_serialport();

    uint8_t FrameGet(uint8_t byte);

    uint8_t* xor_check(uint8_t *data_byte);

    void serial_rec_data_process();

    void connection_confirm(uint8_t addr);

    void serial_write_data(uint8_t *start_byte, uint8_t length);

    uint8_t get_fish_address();

    void record_file_init(QString flag);

    void record_file_close();

    void local_record_stm32(Stm32_Data_Package stm32_data);

    void local_record_polav6(PolaV6_Data_Package polav6_data);

    void sleep_ms(uint16_t ms);

};
#endif // MAINWIDGET_H
