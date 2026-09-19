#include <ArrayPico2.h>
#include <Wire.h>
#include "BNO055.h"
#include <EncoderLibrarys.h>

EncoderLibrarys encoder(20, 19, 22, 21);
BNO055 imu;
ArrayPico2 robot;

int lastDegree = 0;
int fb;
int LR;

void setup() {
  
    robot.begin();  // เริ่มต้นทุกอย่าง
    setup_robot();
    encoder.setupEncoder();

    imu.resetAngles();
    setServo();

    
    
    fw(80, 80, 1, 60, 0, 0);
    fw(80, 80, 1, 1100, 0, 50);
    fw(50, 50, 1.4, 150, 0, 90);
    fw(50, 50, 1, 300, 0, 0);
    setF(1);
    delay(200);
    bw(50, 50, 1, 50, 0, 0);
    bw(50, 50, 1, 500, 0, -60);
    bw(50, 50, 1, 600, 0, 0);
    setB(1);
    delay(200);
    fw(50, 50, 1, 100, 0, 0);
    fw(50, 50, 1, 350, 0, -90);
    fw(50, 50, 1, 300, 0, 180);
    setF(1);
    bw(50, 50, 1, 100, 0, 180);
    bw(50, 50, 1, 600, 0, -120);
    bw(50, 50, 1, 200, 0, 180);
    bw(80, 80, 1.4, 950, 0, 90);
    bw(50, 50, 1, 700, 0, 0);
    setB(1);
    robot.Motor(-20, -20);
    delay(500);
    robot.Motor(20, 20);
    delay(10);
    robot.Motor(1, 1);
}

void loop() {
  imu.update();
  Serial.println(encoder.Poss_R());
  delay(50);
}
