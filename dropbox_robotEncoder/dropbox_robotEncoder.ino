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

int setServoF = 180;
int setServoB = 180;

void setup() {
  

    robot.begin();  // เริ่มต้นทุกอย่าง
    setup_robot();
    encoder.setupEncoder();

    imu.resetAngles();

    //----------------->> เริ่มเขียนโค้ดในนี้
    
    
    
    
    
    
    
    
    
    
    //----------------->> เริ่มเขียนโค้ดในนี้


}

void loop() {
  // imu.update();
  // Serial.println(imu.yaw());
  Serial.println(encoder.Poss_L());
  // Serial.print("              ");
  // Serial.println(encoder.Poss_L());
  delay(50);
}
