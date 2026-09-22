void setServo()
  {
    robot.ServoWrite(18, setServoF);
    robot.ServoWrite(16, setServoB);
  }
void dropF()
  {
    robot.ServoWrite(18, setServoF - 150);
    delay(300);
    robot.ServoWrite(18, setServoF);
  }
void dropB()
  {
    robot.ServoWrite(16, setServoB - 150);
    delay(300);
    robot.ServoWrite(16, setServoB);
  }