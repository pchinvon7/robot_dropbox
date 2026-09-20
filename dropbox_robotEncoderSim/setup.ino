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

  waitToStart();   // แทนที่ robot.run() เดิม (ดูหมายเหตุด้านล่าง)
}

// ----------------------------------------------------------------------
// PiperPico2 ไม่มีเมธอด run() เหมือน ArrayPico2 เดิม (ที่มีเมนู RUN/SETTINGS
// เต็มรูปแบบบนจอ OLED) ฟังก์ชันนี้เป็นแค่ "กดปุ่มเพื่อเริ่ม" แบบง่ายที่สุด
// เพื่อให้ยังวางหุ่นแล้วกดปุ่มก่อนวิ่งได้เหมือนเดิม
//
// ถ้าต้องการเมนูเต็มแบบเดิม (calibrate / view sensor ผ่านจอ) มีให้เลือกต่อยอด 2 ทาง:
//   - UIPiper (class ใน UIPiper.h/UIPier.cpp) → ui.begin(); แล้วเขียน logic เมนูเอง
//     (ของที่ให้มาตอนนี้ showMainMenu() วนลูปเปลี่ยนเมนูอย่างเดียว ยังไม่มี action จริง)
//   - UIPiperPico2.h (ฟังก์ชันลอย ๆ) → ต้องมี gyro, tcs0, tcs1 ประกาศไว้ก่อน
//     ซึ่งโปรเจกต์นี้ไม่มีเซนเซอร์สี/ไจโรแยกแบบนั้น จึงคอมไพล์ไม่ผ่านถ้าใช้ตรง ๆ
// ----------------------------------------------------------------------
void waitToStart() {
  Serial.println("Press button to start...");
  while (digitalRead(PiperPico2::BUTTON_PIN) == HIGH) delay(10);  // รอกด
  delay(200);                                                     // กันสัญญาณเด้ง
  while (digitalRead(PiperPico2::BUTTON_PIN) == LOW) delay(10);   // รอปล่อย
  delay(200);
}
