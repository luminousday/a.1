void System_Logic_Loop(void){
  // 1. 防夹逻辑模拟
  // 假设阈值是2000
  if ((CurrentState == STATE_MOVING_UP || CurrentSate == STATE_MOVING_DOWN) && Sim_Current_ADS > 2000){
    pirntf("!! 检测到电流过大（%d）,触发防夹！！\r\n", Sim_Current_ADC);
    // 执行防夹动作
    Motor_Driver(0);  // 先停
    HAL_Delay(50);
    Alarm_Beep();

    // 模拟回退
    printf(">> [防夹] 执行回退操作... \r\n");
    CurrentState = STATE_ANTI_PINCH;
    HAL_Delay(1000);
    
    printf(">> [防夹] 危险解除，系统待机\r\n");
    Sim_Current_ADC = 0;  // 自动归零模拟值，方便下次调试
    CurrentState = STATE_IDEL;
  }

  // 2. 加热逻辑模拟
  static unit8_t is_heating = 0;  // 假设按键按下开启了加热模式标志位，这里简化为一直检测
  if (Sim_Temperature < 30 && is_heating == 0){
    is_heating = 1;
    Heater_Control(1);
  }
  else if(Sim_Temperature > 43 && is_heating == 1){
    is_heating = 0;
    Heater_Control(0);
  }
}
