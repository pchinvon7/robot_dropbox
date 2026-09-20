void setF(int times)
  {
    int timess = 0;
    while(timess < times)
      {
        if(robot.adcRead(1) > robot.adcMD(1) && robot.adcRead(8) > robot.adcMD(8))
          {
            do{Motor(15, 15);}while(robot.adcRead(1) > robot.adcMD(1) && robot.adcRead(8) > robot.adcMD(8));
            Motor(-15, -15);
            delay(20);
            Motor(1, 1);
          }
        
        if(robot.adcRead(1) < robot.adcMD(1) && robot.adcRead(8) > robot.adcMD(8))
          {
            do{Motor(1, 20);}while(robot.adcRead(8) > robot.adcMD(8));
            Motor(1, -20);
            delay(20);
            Motor(1, 1);

          }
        else if(robot.adcRead(8) < robot.adcMD(8) && robot.adcRead(1) > robot.adcMD(1))
          {
            do{Motor(20, 1);}while(robot.adcRead(1) > robot.adcMD(1));
            Motor(-20, 1);
            delay(20);
            Motor(1, 1);
          }
        if(times > 1)
          {
            Motor(-15, -15);
            delay(100);
            Motor(15, 15);
            delay(20);
            Motor(1, 1);
          }
        timess = timess + 1;
      }
    if(times > 1)
      {
        do{Motor(15, 15);}while(robot.adcRead(1) > robot.adcMD(1) || robot.adcRead(8) > robot.adcMD(8));
        Motor(-15, -15);
        delay(50);
        Motor(1, 1);
      }
  }
void setB(int times)
  {
    int timess = 0;
    while(timess < times)
      {
        if(robot.adcRead(0) > robot.adcMD(0) && robot.adcRead(9) > robot.adcMD(9))
          {
            do{Motor(-15, -15);}while(robot.adcRead(0) > robot.adcMD(0) && robot.adcRead(9) > robot.adcMD(9));
            Motor(15, 15);
            delay(20);
            Motor(1, 1);
          }
        
        if(robot.adcRead(0) < robot.adcMD(0) && robot.adcRead(9) > robot.adcMD(9))
          {
            do{Motor(1, -20);}while(robot.adcRead(9) > robot.adcMD(9));
            Motor(1, 20);
            delay(20);
            Motor(1, 1);

          }
        else if(robot.adcRead(9) < robot.adcMD(9) && robot.adcRead(0) > robot.adcMD(0))
          {
            do{Motor(-20, 1);}while(robot.adcRead(0) > robot.adcMD(0));
            Motor(20, 1);
            delay(20);
            Motor(1, 1);
          }
        if(times > 1)
          {
            Motor(15, 15);
            delay(100);
            Motor(-15, -15);
            delay(20);
            Motor(1, 1);
          }
        timess = timess + 1;
      }
    if(times > 1)
      {
        do{Motor(-15, -15);}while(robot.adcRead(0) > robot.adcMD(0) || robot.adcRead(9) > robot.adcMD(9));
        Motor(15, 15);
        delay(50);
        Motor(1, 1);
      }
  }
