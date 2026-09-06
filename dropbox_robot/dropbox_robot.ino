#include <ArrayPico2.h>
#include <Wire.h>
#include "BNO055.h"

BNO055 imu;
ArrayPico2 robot;

int lastDegree = 0;

void setup() {
  
    robot.begin();  // เริ่มต้นทุกอย่าง
    setup_robot();

    imu.resetAngles();


    


    bw(50, 50, 0.4, 500, 10, 0);










    

    

    


}

void loop() {
  Serial.println(robot.adcRead(9));
  delay(50);
}
