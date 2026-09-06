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


    


    fw(50, 50, 0.4, 500, 10, 0);
    fw(50, 50, 0.4, 500, 10, -90);
    bw(50, 50, 0.4, 500, 10, -90);










    

    

    


}

void loop() {
  Serial.println(robot.adcRead(9));
  delay(50);
}
