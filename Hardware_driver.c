// 模拟电机控制
void Motor_Driver(int speed){
  if (speed > 0){
    printf(">> [电机] 正转（上升），速度：%d\r\n", speed);
    CurrentState = STATE_MOVING_UP;
  } else if (speed < 0) {
    printf(">> [电机] 反转（下降），速度：%d\r\n", -speed);
    CurrentState = STATE_MOVING_DOWN；
  } else {
    printf(">> [电机] 停止\r\n");
    CurrentState = STATE_IDLE;
  }
}

// 模拟加热控制
void Heater_Control(unit8_t on_off){
  if (on_off) {
    print(">> [加热] 已开启（当前模拟温度：%d C）\r\n", Sim_Temperature);  // 点亮板载LED提示（PC13通常是低电平亮）
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_REST);
  } else {
    printf(">> [加热] 已停止\r\n");
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);
  }
}

// 模拟报警
void Alarm_Beep(void){
  printf("!! [报警] 嘀嘀嘀！防夹触发\r\n");
}
