float normalizeAngle(float angle)
{
    // รองรับ error ได้ทุกขนาด ไม่ใช่แค่ ±360 เหมือนของเดิม
    angle = fmod(angle, 360.0);
    if (angle > 180.0)
        angle -= 360.0;
    else if (angle < -180.0)
        angle += 360.0;
    return angle;
}

// distance ตอนนี้มีหน่วยเป็น "encoder tick" แทนที่จะเป็น ms
// decelZone = ระยะ (tick) ก่อนถึงเป้าหมายที่จะเริ่มลดความเร็ว ต้องจูนใหม่เอง
void fw(int spl, int spr, float kp, float distance, int offset, int degree)
{
    float yaw_offset = degree;

    float previous_error = 0.0;
    float integral = 0.0;

    float kpG = kp;
    float kiG = 0;
    float kdG = 0.1;

    const int splT = spl;
    const int sprT = spr;

    const long decelZone = 100; // TODO: จูนค่านี้เป็น tick ให้เหมาะกับ encoder ของคุณ

    encoder.resetEncoders();

    unsigned long last_pid_time = millis();

    lastDegree = degree;
    fb = 1;

    long currentPos = 0;

    distance = (distance / (3.1416 * 4.3)) * 200;

    while (currentPos < (long)distance)
    {
        imu.update();

        currentPos = (abs(encoder.Poss_L()) + abs(encoder.Poss_R())) / 2;

        if (currentPos > (long)distance - decelZone && distance >= 400 && spl >= 20 && spr >= 20 && offset > 0)
        {
            spl = 20;
            spr = 20;
        }

        unsigned long now = millis();
        float dt = (now - last_pid_time) / 1000.0;
        last_pid_time = now;

        // ใช้ normalizeAngle แทน if/else เดิม
        float error = normalizeAngle(imu.yaw() - yaw_offset);

        integral += error * dt;

        float derivative = 0.0;
        if (dt > 0)
            derivative = (error - previous_error) / dt;

        float corr = (kpG * error) + (kiG * integral) + (kdG * derivative);
        previous_error = error;

        int leftSpeed  = spl - corr;
        int rightSpeed = spr + corr;

        leftSpeed  = constrain(leftSpeed, -100, 100);
        rightSpeed = constrain(rightSpeed, -100, 100);

        robot.Motor(leftSpeed, rightSpeed);

        Serial.print("pos=");
        Serial.print(currentPos);
        Serial.print(" yaw=");
        Serial.print(imu.yaw());
        Serial.print(" error=");
        Serial.print(error);
        Serial.print(" corr=");
        Serial.print(corr);
        Serial.print(" L=");
        Serial.print(leftSpeed);
        Serial.print(" R=");
        Serial.println(rightSpeed);
    }

    robot.Motor(-spl, -spr);
    delay(offset);
    robot.Motor(1, 1);
}

void bw(int spl, int spr, float kp, unsigned long distance, int offset, int degree)
{
    float yaw_offset = degree;

    float previous_error = 0.0;
    float integral = 0.0;

    float kpG = kp;
    float kiG = 0;
    float kdG = 0.1;

    const int splT = spl;
    const int sprT = spr;

    const long decelZone = 80; // TODO: จูนค่านี้เป็น tick ให้เหมาะกับ encoder ของคุณ

    encoder.resetEncoders();

    unsigned long last_pid_time = millis();

    lastDegree = degree;
    fb = 0;

    long currentPos = 0;

    distance = (distance / (3.1416 * 4.3)) * 200;

    while (currentPos < (long)distance)
    {
        imu.update();

        currentPos = (abs(encoder.Poss_L()) + abs(encoder.Poss_R())) / 2;

        if (currentPos > (long)distance - decelZone && distance >= 400 && spl >= 20 && spr >= 20 && offset > 0)
        {
            spl = 20;
            spr = 20;
        }

        if (robot.adcRead(0) < robot.adcMD(0))
        {
            do
            {
                robot.Motor(-spl - 20, -spr);
                imu.update();
            } while (robot.adcRead(0) < robot.adcMD(0));
        }
        else if (robot.adcRead(9) < robot.adcMD(9))
        {
            do
            {
                robot.Motor(-spl, -spr - 20);
                imu.update();
            } while (robot.adcRead(9) < robot.adcMD(9));
        }

        unsigned long now = millis();
        float dt = (now - last_pid_time) / 1000.0;
        last_pid_time = now;

        // ใช้ normalizeAngle แทน if/else เดิม
        float error = normalizeAngle(imu.yaw() - yaw_offset);

        integral += error * dt;

        float derivative = 0.0;
        if (dt > 0)
            derivative = (error - previous_error) / dt;

        float corr = (kpG * error) + (kiG * integral) + (kdG * derivative);
        previous_error = error;

        int leftSpeed  = spl + corr;
        int rightSpeed = spr - corr;

        leftSpeed  = constrain(leftSpeed, -100, 100);
        rightSpeed = constrain(rightSpeed, -100, 100);

        robot.Motor(-leftSpeed, -rightSpeed);

        Serial.print("pos=");
        Serial.print(currentPos);
        Serial.print(" yaw=");
        Serial.print(imu.yaw());
        Serial.print(" error=");
        Serial.print(error);
        Serial.print(" corr=");
        Serial.print(corr);
        Serial.print(" L=");
        Serial.print(leftSpeed);
        Serial.print(" R=");
        Serial.println(rightSpeed);
    }

    robot.Motor(spl, spr);
    delay(offset);
    robot.Motor(0, 0);
}