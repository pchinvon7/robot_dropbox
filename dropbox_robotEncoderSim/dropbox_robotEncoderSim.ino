#include "PiperPico2.h"
#include <Wire.h>
#include "BNO055.h"
// ไม่ต้อง #include <EncoderLibrarys.h> เอง — PiperPico2.h include ให้แล้ว
// และ encoder ของล้อถูกฝังอยู่ใน PiperPico2 (robot.enc1Left()/enc1Right()) แล้ว
// ไม่ต้องสร้าง EncoderLibrarys encoder(...) แยกอีก เพราะจะไปแย่งพิน 20,19 กับตัวใน robot

PiperPico2 robot;
BNO055 imu;

int lastDegree = 0;
int fb;
int LR;

int setServoF = 180;
int setServoB = 180;

// ----------------------------------------------------------------------
// wrapper แทน ArrayPico2::Motor(left, right) เดิม
// PiperPico2 ไม่มี Motor(l,r) แล้ว ต้องสั่งทีละตัวด้วย motor('A'/'B'/'C'/'D', speed)
// สมมติ A = ล้อซ้าย, B = ล้อขวา (เดาจากตำแหน่งพิน PWM_PIN_A/PWMA เดิมที่ตรงกัน)
// **ต้องทดสอบวิ่งจริงเพื่อยืนยันว่า A/B ตรงกับซ้าย/ขวาจริงไหม ถ้าสลับให้สลับในนี้ที่เดียว**
// ----------------------------------------------------------------------
void Motor(int left, int right) {
  robot.motor('A', left);
  robot.motor('C', right);
}

void setup() {

    robot.begin();   // เริ่มต้นทุกอย่าง (I2C, PCA9685, OLED, buzzer, โหลด calibration) — ครอบคลุมกว่า ArrayPico2::begin() เดิม
    //encoder.setupEncoder();
    setup_robot();
    robot.resetEncoders();
    imu.resetAngles();
    setServo();

    fw(50, 50, 1, 200, 0, 0);
    fw(80, 80, 1.4, 500, 0, 60);
    fw(80, 80, 1.4, 400, 0, 0);
    setF(1);
    dropF();
    bw(50, 50, 1, 200, 0, 0);
    bw(80, 80, 1.4, 900, 0, -90);
    bw(50, 50, 1.2, 300, 0, 180);
    setB(1);
    dropB();
    fw(80, 80, 1.4, 900, 0, 180);
    setF(1);
    dropF();
    bw(50, 50, 1.4, 200, 0, 180);
    bw(80, 80, 1.4, 400, 0, 90);
    bw(60, 60, 1, 300, 0, 0);
    setB(1);
    dropB();
    fw(50, 50, 1.4, 100, 0, 0);
    fw(80, 80, 1.4, 650, 0, 62);
    fw(80, 80, 1, 1500, 0, -90);
    fw(60, 60, 1, 300, 0, 0);
    setF(1);
    Motor(30, 30);
    delay(200);
    Motor(-30, -30);
    delay(10);
    Motor(1, 1);
    delay(200);
    Motor(-30, -30);
    delay(200);
    Motor(30, 30);
    delay(10);
    Motor(1, 1);
    bw(50, 50, 1.4, 200, 0, 0);
    bw(80, 80, 1.4, 900, 0, -90);
    bw(60, 60, 1.2, 300, 0, 180);
    setB(1);
    Motor(-30, -30);
    delay(200);
    Motor(30, 30);
    delay(10);
    Motor(1, 1);
    delay(200);
    Motor(30, 30);
    delay(200);
    Motor(-30, -30);
    delay(10);
    Motor(1, 1);
    fw(60, 60, 1, 200, 0, 180);
    fw(80, 80, 1.4, 500, 0, -100);
    fw(80, 80, 1.4, 600, 0, 180);
    setF(1);
    Motor(30, 30);
    delay(200);
    Motor(-30, -30);
    delay(10);
    Motor(1, 1);

}

void loop() {
  imu.update();
  //Serial.println(robot.enc1Right());   // encoder.Poss_R() เดิม → robot.enc1Right()
  Serial.println(imu.yaw());
  delay(50);
}
