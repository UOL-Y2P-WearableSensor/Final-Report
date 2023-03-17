/**
 * logic:
 * input node_child["parent_terminal"] first,
 * then loop all joints to find node_parent whose "child_terminal" matches the node_child["parent_terminal"]
 * where the this.mesh[0] is the zero terminal, "mesh_origin_point"
 * calibrate the binding
 * add a ball on the child terminal
 * At last, this.meshes[node_parent].add(this.meshes[node_child]);
 */

    //the child_terminal is regarded as the index of one node.
let node_info, node_mesh, parent_knot, child_knot;
for (let i = 0; i < this.IMU_schedule.length; i++) {
    // console.log(this.IMU_schedule[i]);
    node_info = this.IMU_schedule[i];
    node_mesh = this.mesh_joints[i];

    //find parent_knot
    if (node_info["parent_terminal"] === "0") {
        console.log("\tfind the parent_knot: mesh_origin");
        parent_knot = this.mesh_origin;
    } else {
        //range of idx: 0,1,2,3,4; excluding 5(this.IMU_schedule.length)
        let idx = 0;

        for (; idx < this.IMU_schedule.length; idx++) {
            if (this.IMU_schedule[idx]["child_terminal"] === node_info["parent_terminal"]) {
                console.log("\tfind the parent_terminal: ", this.IMU_schedule[idx]["child_terminal"]);
                console.log("\tparent_knot idx = ", idx);
                parent_knot = this.mesh_knots[idx];
                break;
            }
        }

        if (idx === this.IMU_schedule.length) {
            console.log("\tfailed to find parent_knot");
            console.log(this.IMU_schedule[i]);
            break;
        }

    }

    //add the current joint to the parent_knot(one knot)
    child_knot = this.mesh_knots[i];
    parent_knot.add(node_mesh);
    node_mesh.add(child_knot);

}