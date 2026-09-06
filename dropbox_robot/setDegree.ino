void setF(int times)
  {
    int timess = 0;
    while(timess < times)
      {
        if(robot.adcRead(1) > 500 && robot.adcRead(8) > 500)
          {
            do{robot.Motor(15, 15);}while(robot.adcRead(1) > 500 && robot.adcRead(8) > 500);
            robot.Motor(-15, -15);
            delay(20);
            robot.Motor(1, 1);
          }
        
        if(robot.adcRead(1) < 500 && robot.adcRead(8) > 500)
          {
            do{robot.Motor(1, 20);}while(robot.adcRead(8) > 500);
            robot.Motor(1, -20);
            delay(20);
            robot.Motor(1, 1);

          }
        else if(robot.adcRead(8) < 500 && robot.adcRead(1) > 500)
          {
            do{robot.Motor(20, 1);}while(robot.adcRead(1) > 500);
            robot.Motor(-20, 1);
            delay(20);
            robot.Motor(1, 1);
          }
        if(times > 1)
          {
            robot.Motor(-15, -15);
            delay(100);
            robot.Motor(15, 15);
            delay(20);
            robot.Motor(1, 1);
          }
        timess = timess + 1;
      }
    if(times > 1)
      {
        do{robot.Motor(15, 15);}while(robot.adcRead(1) > 500 || robot.adcRead(8) > 500);
        robot.Motor(-15, -15);
        delay(50);
        robot.Motor(1, 1);
      }
  }
void setB(int times)
  {
    int timess = 0;
    while(timess < times)
      {
        if(robot.adcRead(0) > 500 && robot.adcRead(9) > 500)
          {
            do{robot.Motor(-15, -15);}while(robot.adcRead(0) > 500 && robot.adcRead(9) > 500);
            robot.Motor(15, 15);
            delay(20);
            robot.Motor(1, 1);
          }
        
        if(robot.adcRead(0) < 500 && robot.adcRead(9) > 500)
          {
            do{robot.Motor(1, -20);}while(robot.adcRead(9) > 500);
            robot.Motor(1, 20);
            delay(20);
            robot.Motor(1, 1);

          }
        else if(robot.adcRead(9) < 500 && robot.adcRead(0) > 500)
          {
            do{robot.Motor(-20, 1);}while(robot.adcRead(0) > 500);
            robot.Motor(20, 1);
            delay(20);
            robot.Motor(1, 1);
          }
        if(times > 1)
          {
            robot.Motor(15, 15);
            delay(100);
            robot.Motor(-15, -15);
            delay(20);
            robot.Motor(1, 1);
          }
        timess = timess + 1;
      }
    if(times > 1)
      {
        do{robot.Motor(-15, -15);}while(robot.adcRead(0) > 500 || robot.adcRead(9) > 500);
        robot.Motor(15, 15);
        delay(50);
        robot.Motor(1, 1);
      }
  }