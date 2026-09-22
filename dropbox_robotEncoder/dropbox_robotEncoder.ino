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
    setServo();

    fw(50, 50, 1.4, 10, 0, 0);
    fw(50, 50, 1.4, 37, 0, 60);
    fw(50, 50, 1.4, 40, 0, 0);
    setF(1);
    delay(300);
    bw(30, 30, 1.4, 3, 0, 0);
    bw(50, 50, 1.4, 50, 0, -90);
    bw(50, 50, 1.4, 30, 0, 180);
    setB(1);

    // fw(50, 50, 1, 15, 0, 0);
    // fw(50, 50, 1, 100, 0, 50);
    // fw(50, 50, 1, 70, 0, 0);

    
}

void loop() {
  // imu.update();
  // Serial.println(imu.yaw());
  Serial.println(encoder.Poss_L());
  // Serial.print("              ");
  // Serial.println(encoder.Poss_L());
  delay(50);
}
