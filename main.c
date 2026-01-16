#include "main.h"
#include <stdio.h>

// 全局变量
int16_t Sim_Current_ADC = 0;  // 模拟范围（0~4095）
int16_t Sim_Temperature = 25;  // 模拟温度
unit8_t Sim_Motor_Pos = 0;  // 模拟电机位置（0~100%）

// 状态枚举
typedef enum {
  STATE_IDLE,
  STATE_MOVING_UP,
  STATE_MOVING_DOWN,
  STATE_ANTI_PINCH,  // 防夹回退中
  STATE_HEATING
} SystemState_t;

SystemState_t CurrentState = STATE_IDEL;
