// ArrayPico2::ServoWrite(pin, degree) เดิมใช้เลข "พิน GPIO จริง" (16, 18)
// PiperPico2::setservo(channel, angle) ใช้เลข "channel เชิงตรรกะ 0-6" ที่ map ไปพิน PCA9685
// ผ่าน SERVO_CHANNELS[] = {15,14,13,12,11,10} ภายในไลบรารี — คนละความหมายเลขกันเลย
// ด้านล่างเดาว่า servo หน้า = channel 0, servo หลัง = channel 1
// **ต้องเช็คหน้างานว่า servo ต่ออยู่ channel ไหนจริง แล้วแก้เลขให้ตรง**

void setServo()
  {
    robot.setservo(0, setServoF);   // servo หน้า
    robot.setservo(1, setServoB);   // servo หลัง
  }
void dropF()
  {
    robot.setservo(0, setServoF - 150);
    delay(300);
    robot.setservo(0, setServoF);
  }
void dropB()
  {
    robot.setservo(1, setServoB - 150);
    delay(300);
    robot.setservo(1, setServoB);
  }
