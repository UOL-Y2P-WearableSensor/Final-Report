//Note that only the processing to right femur and right tibia are shown here as a mutual explanation.
// Other processing for the left part is similar and discarded for better illustration.

//threshold to avoid jittering
const threshold=0.02;

//process the pitch data of right femur
idx = 1;
name = "R_F";

//data matching process
current_pitch = this.mesh_joints[idx].rotation.x;
input_roll=new_data[name][0]["r"];
input_pitch=new_data[name][0]["p"];
if (Math.abs(input_roll - 180) < Math.abs(input_roll - 0)
    || Math.abs(input_roll + 180) < Math.abs(input_roll - 0)) {
    k = 1;
} else {
    k = -1;
}
target_pitch = (input_pitch / 180 * Math.PI + Math.PI / 2) * k; //p
diff = (target_pitch - current_pitch) / (this.interpolation_num + 1);

//interpolating the processed data
this.IMU_data_R_F.splice(0, this.IMU_data_R_F.length);
if (Math.abs(diff) > threshold) {
    //valid input
    for (let i = 1; i <= this.interpolation_num; i++) {
        let tmp = current_pitch + i * diff;
        this.IMU_data_R_F.push(tmp);
    }
    this.IMU_data_R_F.push(target_pitch);
} else {
    //invalid input, keep last pose
    for (let i = 0; i <= this.interpolation_num; i++) {
        this.IMU_data_R_F.push(current_pitch);
    }
}



//process the pitch data of right femur
idx = 3;
name = "R_T";

//data matching process
current_pitch = this.mesh_joints[idx].rotation.x;
input_roll=new_data[name][0]["r"];
input_pitch=new_data[name][0]["p"];
if (Math.abs(input_roll - 180) < Math.abs(input_roll - 0)
    || Math.abs(input_roll + 180) < Math.abs(input_roll - 0)) {
    k = 1;
} else {
    k = -1;
}
//this.mesh_joints[1] is right_femur
target_pitch = this.mesh_joints[1].rotation.x
    - (new_data[name][0]["p"] / 180 * Math.PI + Math.PI / 2) * k;
diff = (target_pitch - current_pitch) / (this.interpolation_num + 1);

this.IMU_data_R_T.splice(0, this.IMU_data_R_T.length);
if (Math.abs(diff) > threshold) {
    for (let i = 1; i <= this.interpolation_num; i++) {
        let tmp = current + i * diff;
        this.IMU_data_R_T.push(tmp);
    }
    this.IMU_data_R_T.push(target_pitch);
} else {
    for (let i = 0; i <= this.interpolation_num; i++) {
        this.IMU_data_R_T.push(current);
    }
}