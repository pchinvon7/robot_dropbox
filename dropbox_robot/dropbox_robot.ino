#include <ArrayPico2.h>
#include <Wire.h>
#include "BNO055.h"

BNO055 imu;
ArrayPico2 robot;

int lastDegree = 0;
int fb;

void setup() {
  
    robot.begin();  // เริ่มต้นทุกอย่าง
    setup_robot();

    imu.resetAngles();
    setServo();
    
    
}

void loop() {
  imu.update();
  Serial.println(imu.yaw());
  delay(50);
}
