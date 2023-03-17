//the full file could be found in https://github.com/UOL-Y2P-WearableSensor/PlatformIO.
//calibrating for three seconds
#define CALI_TIME_MS 3000
void Sensor::calibrating_external() {
    Serial.print("IMU_external GYRO calibration, ETA=");
    Serial.print(CALI_TIME_MS);
    Serial.println("ms");

    unsigned long start_time = millis();
    int num = 0;

    for (int port = 0; port < 8; ++port) {
        memset(IMU_external_data[port].gyro_cali, 0, 3);
    }

    while (millis() <= start_time + CALI_TIME_MS) {
        num++;

        for (int port = 0; port < 8; port++) {
            if (port == IMU_LEFT_FEMUR
                || port == IMU_RIGHT_FEMUR
                || port == IMU_LEFT_TIBIA
                || port == IMU_RIGHT_TIBIA) {
                I2CMulti.selectPort(port);
                memset(IMU_external_data[port].gyro, 0, 3);
                IMU_external.getGyroscope(
                    &IMU_external_data[port].gyro[0],
                    &IMU_external_data[port].gyro[1],
                    &IMU_external_data[port].gyro[2]);
                for (int i = 0; i < 3; ++i) {
                    IMU_external_data[port].gyro_cali[i] -=
                        (IMU_external_data[port].gyro[i]);
                }
            }
        }
    }
    Serial.print("cali data num: ");
    Serial.println(num);
    for (int port = 0; port < 8; port++) {
        if (port == IMU_LEFT_FEMUR
            || port == IMU_RIGHT_FEMUR
            || port == IMU_LEFT_TIBIA
            || port == IMU_RIGHT_TIBIA) {
            for (int i = 0; i < 3; ++i) {
                IMU_external_data[port].gyro_cali[i] =
                    IMU_external_data[port].gyro_cali[i] / num;
            }
            Serial.print("IMU_external[");
            Serial.print(port);
            Serial.println("].gyro_cali");
            Serial.print("\t\t[x]=");
            Serial.println(IMU_external_data[port].gyro_cali[0]);
            Serial.print("\t\t[y]=");
            Serial.println(IMU_external_data[port].gyro_cali[1]);
            Serial.print("\t\t[z]=");
            Serial.println(IMU_external_data[port].gyro_cali[2]);
        }
    }

}