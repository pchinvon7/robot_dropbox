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

    
    
    
}

void loop() {
  imu.update();
  Serial.println(encoder.Poss_R());
  delay(50);
}
