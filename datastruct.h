/**
 * File name: datastruct.h
 * Brief: Define the format of the data to be transmitted
 * Author: GJH
 * Version: 0.1
 * See: /documents/HDUBeagleBoneSTM32串口通信协议数据表.xlsx
 * Date: 2020.1.8
**/

#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <stdint.h>

// frame head and frame tail
const uint8_t FRAME_HEAD_H = 0xca;
const uint8_t FRAME_HEAD_L = 0xac;
const uint8_t FRAME_TAIL = 0xcc;

// address byte
const uint8_t FRAME_ADDR_FISH1 = 0x01;
const uint8_t FRAME_ADDR_FISH2 = 0x02;
const uint8_t FRAME_ADDR_FISH3 = 0x03;
const uint8_t FRAME_ADDR_FISH4 = 0x04;
const uint8_t FRAME_ADDR_BOARDCAST = 0x55;

// readwrite byte
const uint8_t FRAME_READ = 0x30;
const uint8_t FRAME_WRITE = 0x31;

// function byte
const uint8_t FRAME_FUNC_STM32 = 0x01;
const uint8_t FRAME_FUNC_POLAV6 = 0x02;
const uint8_t FRAME_FUNC_MOTOR = 0x03;
const uint8_t FRAME_FUNC_POSTURE = 0x04;
const uint8_t FRAME_FUNC_AUTO = 0x05;
const uint8_t FRAME_FUNC_CONNECTION = 0x06;
const uint8_t COM_TEST = 0x07;


// max buffer size
const uint16_t BUFFER_MAX_SIZE = 256;

// recieved data process flag byte
const uint16_t FRAME_HEAD_FLAG = 0x01;
const uint16_t FRAME_OVER_FLAG = 0x02;

// default value of motor control parameters
const uint16_t MOTOR_PUSH = 500;
const uint16_t MOTOR_HEAD_STEER = 1500;
const uint16_t MOTOR_PITCH_STEER = 1500;

// default value of posture control parameters
const uint16_t PUMP_POSITION = 200;
const uint16_t MASS_POSITION = 4000;

// joystick mapping
// axis index
const uint8_t PUSH_MORTOR = 1;
const uint8_t HEAD_STEER = 2;
// button index
const uint8_t A = 0;
const uint8_t EXIT_B = 1;
const uint8_t RESET_X = 2;
const uint8_t Y = 3;

// query data and connection confirm frame
typedef struct {
    uint8_t head_h;
    uint8_t head_l;
    uint8_t addr;
    uint8_t rw;
    uint8_t len;
    uint8_t func_id;
    uint8_t xor_check;
    uint8_t tail;
} Base_Frame;

// stm32 upload data package
typedef struct{
    float deepth;
    float temper;
    float roll;
    float pitch;
    float yaw;
    float volt;
    float curr;
    float pump_posi;
    float mass_posi;
    float leak;
    float push_motor;
    float head_steer;
    float pitch_steer;
    float reserved;
} Stm32_Data_Package;

// pola V6 upload data package
typedef struct{
    float navi_time_ms;
    float longtitude;
    float latitude;
    float height;
    float GPS_head;
    float GPS_v;
    float acc_x;
    float acc_y;
    float acc_z;
    float v_north;
    float v_sky;
    float v_east;
    float omg_x;
    float omg_y;
    float omg_z;
    float pitch;
    float yaw;
    float roll;
} PolaV6_Data_Package;

// motor control parameters
typedef struct{
    float push_motor;
    float pitch_steer;
    float head_steer;
    float status_ctrl;
    float power_ctrl;
    float reserved;
} Motor_Para_Package;

// motor control frame
typedef struct{
    uint8_t head_h;
    uint8_t head_l;
    uint8_t addr;
    uint8_t rw;
    uint8_t len;
    uint8_t func_id;
    Motor_Para_Package motor_para;
    uint8_t xor_check;
    uint8_t tail;
} Motor_Frame;

// posture control parameters
typedef struct{
    float mass_position;
    float pump_position;
    float reserved_1;
    float reserved_2;
    float reserved_3;
} Posture_Para_Package;

// posture contorl frame
typedef struct{
    uint8_t head_h;
    uint8_t head_l;
    uint8_t addr;
    uint8_t rw;
    uint8_t len;
    uint8_t func_id;
    Posture_Para_Package posture_para;
    uint8_t xor_check;
    uint8_t tail;
} Posture_Frame;

// automatic control parameters
typedef struct{
    float formation_plan;
    float count;
    float coordinates [4][2];
    float reserved;
} Auto_Para_Package;

// automatic control frame
typedef struct{
    uint8_t head_h;
    uint8_t head_l;
    uint8_t addr;
    uint8_t rw;
    uint8_t len;
    uint8_t func_id;
    Auto_Para_Package auto_para;
    uint8_t xor_check;
    uint8_t tail;
} Auto_Frame;

// com test frame
typedef struct{
    uint8_t head_h;
    uint8_t head_l;
    uint8_t addr;
    uint8_t rw;
    uint8_t len;
    uint8_t func_id;
    uint8_t count;
    uint8_t xor_check;
    uint8_t tail;
} Test_Frame;


#endif // DATASTRUCT_H
