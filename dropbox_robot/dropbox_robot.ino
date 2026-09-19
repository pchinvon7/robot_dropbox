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
    
    fw(50, 50, 1, 300, 0, 0);
    fw(50, 50, 1, 400, 0, 90);
    fw(50, 50, 1, 450, 0, 0);
    fw(80, 80, 1.4, 600, 0, 90);
    fw(50, 50, 1, 200, 0, 0);
    setF(1);
    delay(200);
    bw(60, 60, 1.4, 700, 0, 0);
    setB(1);
    delay(200);
    fw(80, 80, 1.4, 400, 0, 0);
    fw(80, 80, 1.2, 850, 0, -90);
    fw(50, 50, 1, 400, 0, 0);
    setF(1);
    delay(200);
    bw(50, 50, 1, 200, 0, 0);
    bw(80, 80, 1.4, 850, 0, -90);
    bw(50, 50, 1, 450, 0, 0);
    bw(50, 50, 1, 350, 0, 90);
    bw(50, 50, 1, 300, 0, 0);
    setB(1);
    delay(200);
    fw(50, 50, 1, 200, 0, 0);
    fw(50, 50, 1, 400, 0, 90);
    fw(50, 50, 1, 400, 0, 0);
    fw(50, 50, 1, 850, 0, -90);
    fw(50, 50, 1, 300, 0, 0);
    setF(1);
    delay(200);
    bw(60, 60, 1, 700, 0, 0);
    setB(1);
    delay(200);
    fw(80, 80, 1, 400, 0, 0);
    fw(50, 50, 1, 400, 0, 90);
    fw(50, 50, 1, 400, 0, 0);
    
}

void loop() {
  imu.update();
  Serial.println(imu.yaw());
  delay(50);
}
