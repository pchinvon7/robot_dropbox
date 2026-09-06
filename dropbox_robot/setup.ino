void setup_robot() {
 
  robot.setMotorPWMFrequency(20000);  // ลอง 12 kHz ถ้าต้องการ เปลี่ยนความถี่ PWM สำหรับมอเตอร์ได้ที่นี่
  Serial.begin(115200);

    Wire.setSDA(4);
    Wire.setSCL(5);
    Wire.begin();
    Wire.setClock(400000);

    if (!imu.begin(0x29, Wire)) {
        Serial.println("BNO055 not found");
        while (1);
    }

    imu.setLPF(0.75f);
    imu.calibrate(11, false);
    imu.resetAngles();

    Serial.println("BNO055 Ready");

  robot.run();    // แสดง Welcome + เมนู + รอคำสั่งrobot.ServoAttach(16);   // ติดตั้ง Servo บนพิน 16
}