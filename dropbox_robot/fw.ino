// float normalizeAngle(float angle)
// {
//     // รองรับ error ได้ทุกขนาด ไม่ใช่แค่ ±360 เหมือนของเดิม
//     angle = fmod(angle, 360.0);
//     if (angle > 180.0)
//         angle -= 360.0;
//     else if (angle < -180.0)
//         angle += 360.0;
//     return angle;
// }
// void fw(int spl, int spr, float kp, unsigned long distance, int offset, int degree)
// {
//     float yaw_offset = degree;

//     float previous_error = 0.0;
//     float integral = 0.0;

//     float kpG = kp;
//     float kiG = 0;
//     float kdG = 0;

//     unsigned long startTime = millis();
//     unsigned long last_pid_time = startTime;
//     lastDegree = degree;

//     while (millis() - startTime < distance)
//     {
//         imu.update();

//         unsigned long now = millis();

//         float dt = (now - last_pid_time) / 1000.0;
//         last_pid_time = now;

//         // ใช้ normalizeAngle แทน if/else เดิม
//         float error = normalizeAngle(imu.yaw() - yaw_offset);

//         integral += error * dt;

//         float derivative = 0.0;

//         if (dt > 0)
//             derivative = (error - previous_error) / dt;

//         float corr = (kpG * error)
//                      + (kiG * integral)
//                      + (kdG * derivative);

//         previous_error = error;

//         int leftSpeed  = spl - corr;
//         int rightSpeed = spr + corr;

//         leftSpeed  = constrain(leftSpeed, -100, 100);
//         rightSpeed = constrain(rightSpeed, -100, 100);

//         robot.Motor(leftSpeed, rightSpeed);

//         Serial.print("yaw=");
//         Serial.print(imu.yaw());
//         Serial.print(" error=");
//         Serial.print(error);
//         Serial.print(" corr=");
//         Serial.print(corr);
//         Serial.print(" L=");
//         Serial.print(leftSpeed);
//         Serial.print(" R=");
//         Serial.println(rightSpeed);
//     }

//     robot.Motor(-spl, -spr);
//     delay(offset);
//     robot.Motor(1, 1);
// }
// void bw(int spl, int spr, float kp, unsigned long distance, int offset, int degree)
// {
//     float yaw_offset = degree;

//     float previous_error = 0.0;
//     float integral = 0.0;

//     float kpG = kp;
//     float kiG = 0;
//     float kdG = 0;

//     unsigned long startTime = millis();
//     unsigned long last_pid_time = startTime;
//     lastDegree = degree;

//     while (millis() - startTime < distance)
//     {
//         imu.update();

//         unsigned long now = millis();

//         float dt = (now - last_pid_time) / 1000.0;
//         last_pid_time = now;

//         // ใช้ normalizeAngle แทน if/else เดิม
//         float error = normalizeAngle(imu.yaw() - yaw_offset);

//         integral += error * dt;

//         float derivative = 0.0;

//         if (dt > 0)
//             derivative = (error - previous_error) / dt;

//         float corr = (kpG * error)
//                      + (kiG * integral)
//                      + (kdG * derivative);

//         previous_error = error;

//         int leftSpeed  = spl + corr;
//         int rightSpeed = spr - corr;

//         leftSpeed  = constrain(leftSpeed, -100, 100);
//         rightSpeed = constrain(rightSpeed, -100, 100);

//         robot.Motor(-leftSpeed, -rightSpeed);

//         Serial.print("yaw=");
//         Serial.print(imu.yaw());
//         Serial.print(" error=");
//         Serial.print(error);
//         Serial.print(" corr=");
//         Serial.print(corr);
//         Serial.print(" L=");
//         Serial.print(leftSpeed);
//         Serial.print(" R=");
//         Serial.println(rightSpeed);
//     }

//     robot.Motor(-spl, -spr);
//     delay(offset);
//     robot.Motor(1, 1);
// }