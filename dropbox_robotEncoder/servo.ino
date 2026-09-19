void setServo()
  {
    robot.ServoWrite(16, 160);
  }
void drop()
  {
    robot.ServoWrite(16, 160 - 150);
    delay(300);
    robot.ServoWrite(16, 160);
  }