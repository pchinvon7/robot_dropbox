// void rotate(int sp, int degree, int offset)
//   {
//     degree = imu.yaw() + degree;
//     if(degree > imu.yaw())
//         {
//             while(imu.yaw() < degree)
//                 {
//                     imu.update();

//                     int spDe = map(imu.yaw(), lastDegree, degree, sp, 15);

//                     robot.Motor(spDe, -spDe);
//                 }
//             robot.Motor(-sp, sp);
//             delay(offset);
//             robot.Motor(1, 1);
//             imu.update();
//             if(imu.yaw() > degree)
//                 {
//                     do{imu.update();robot.Motor(-15, 15);}while(imu.yaw() > degree);
//                     robot.Motor(15, -15);
//                     delay(10);
//                     robot.Motor(1, 1);
//                 }
//         }
//     if(degree < imu.yaw())
//         {
//             while(imu.yaw() > degree)
//                 {
//                     imu.update();

//                     int spDe = map(imu.yaw(), lastDegree, degree, sp, 15);

//                     robot.Motor(-spDe, spDe);
//                 }
//             robot.Motor(sp, -sp);
//             delay(offset);
//             robot.Motor(1, 1);
//             imu.update();
//             if(imu.yaw() < degree)
//                 {
//                     do{imu.update();robot.Motor(15, -15);}while(imu.yaw() < degree);
//                     robot.Motor(-15, 15);
//                     delay(10);
//                     robot.Motor(1, 1);
//                 }
//         }
//   }




float normalizeAngles(float angle)
{
    while (angle > 180)  angle -= 360;
    while (angle < -180) angle += 360;
    return angle;
}

void rotate(int sp, int degree, int offset)
{
    imu.update();
    float startYaw = imu.yaw();

    // แปลง degree (เป้าหมายที่อาจอยู่คนละ "รอบ" กับ yaw ต่อเนื่อง)
    // ให้กลายเป็นค่าเป้าหมายบนเส้นเดียวกับ startYaw โดยเลือกทางที่สั้นที่สุด
    float error  = normalizeAngles(degree - startYaw);  // -180 ถึง 180 เท่านั้น
    float target = startYaw + error;                   // ใช้ค่านี้ตลอดทั้งฟังก์ชัน ห้ามใช้ degree ดิบอีก

    if (error > 0.5)          // ต้องเลี้ยวขวา
    {
        while (target - imu.yaw() > 0.5)
        {
            imu.update();
            float remaining = target - imu.yaw();
            int spDe = (int)constrain(remaining / error * sp, 20, sp);
            robot.Motor(spDe, -spDe);
        }
        robot.Motor(-sp * 0.3, sp * 0.3);
        delay(offset);
        robot.Motor(1, 1);

        imu.update();
        if (target - imu.yaw() < -0.5)          // เลยไป -> ต้องถอยกลับซ้าย
        {
            do { imu.update(); robot.Motor(-15, 15); }
            while (target - imu.yaw() < -0.5);
            robot.Motor(15, -15);
            delay(10);
            robot.Motor(1, 1);
        }
    }
    else if (error < -0.5)    // ต้องเลี้ยวซ้าย
    {
        while (target - imu.yaw() < -0.5)
        {
            imu.update();
            float remaining = target - imu.yaw();
            int spDe = (int)constrain(remaining / error * sp, 20, sp);
            robot.Motor(-spDe, spDe);
        }
        robot.Motor(sp * 0.3, -sp * 0.3);
        delay(offset);
        robot.Motor(1, 1);

        imu.update();
        if (target - imu.yaw() > 0.5)           // เลยไป -> ต้องถอยกลับขวา
        {
            do { imu.update(); robot.Motor(15, -15); }
            while (target - imu.yaw() > 0.5);
            robot.Motor(-15, 15);
            delay(10);
            robot.Motor(1, 1);
        }
    }
}