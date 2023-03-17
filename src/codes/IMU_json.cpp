//the whole file could be found in https://github.com/UOL-Y2P-WearableSensor/WearableSensor_Macos/tree/communicate_with_Arduino/src
#include "IMU_json.h"

std::string Euler_angle_t::toString() const {
    return "{\"r\":" + data[0] + ",\"p\":" + data[1] + "}";
}

std::string IMU_Data_t::toString() const {
    std::string json="{";

    for (int imu = 0; imu < IMU_NUM; ++imu) {
        json += "\"" + name[imu] + "\":[";

        for (int pose = 0; pose < data[imu].size(); ++pose) {
            json += data[imu].at(pose).toString();
            if (pose != data[imu].size() - 1) json+=",";
        }

        json+="]";
        if (imu != IMU_NUM-1) json+=",";
    }

    json+="}";
    return json;
}

//This spilit function is copied from https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c.
std::vector<std::string> split(const std::string &s, const std::string &delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}


std::string send_IMU_data() {
    //read the last five lines in IMU_data.txt, then phase2json
    std::ifstream fs;
    fs.open("../fileForServer/IMU_data.txt");

    if (fs.is_open()) {
        fs.seekg(-1, std::ios_base::end);                // go to one spot before the EOF

        char ch;
        int num = 0;
        while (true) {
            if (num >= FRAME2BROWSER+1) break;
            fs.get(ch);
            if (ch == '\n') num++;
            fs.seekg(-2,
                     std::ios_base::cur);
        }
        fs.seekg(2, std::ios_base::cur);

        std::string tmp;
        IMU_Data_t IMU_data;
        Euler_angle_t Euler_angle;
        int split_idx;
        for (int pose = 0; pose < FRAME2BROWSER ; ++pose) {

            // Read the current line
            getline(fs, tmp);
            std::vector<std::string> v = split(tmp, " ");

            //except the time_idx "[19]"
            split_idx = 0;

            //store in the IMU_data struct
            for (int IMU_idx = 0; IMU_idx < IMU_NUM; ++IMU_idx) {
                if (split_idx > v.size() - 1) break;
                for (int angle_idx = 0; angle_idx < (sizeof Euler_angle.data/ sizeof (std::string)); ++angle_idx) {
                    Euler_angle.data[angle_idx] = v.at(split_idx++);
                }
                IMU_data.data[IMU_idx].push_back(Euler_angle);
            }
        }
        fs.close();
        std::string response="HTTP/1.1 200 Ok\r\nContent-Type: application/json";
        response+="\r\n\r\n";
        response+=IMU_data.toString();
        std::cout<<response<<std::endl;
        return response;
    }

}