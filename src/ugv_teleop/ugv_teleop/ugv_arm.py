
LOWER_ELBOW_SERV_LIM = -360.0
UPPER_ELBOW_SERV_LIM = 360.0
DEAD_ZONE_THRESH = 15/100
UPPER_STEER_CMD_LIMIT = 1.0
# step = 5

def clamp(v, lo, high):
    return max(lo, min(v, high))

class ArmController:
    def __init__(self, num_joints = 5, inc_dec_val=5.0, limits=None):
        self.num_joints = num_joints
        self.inc_dec_val = inc_dec_val
        self.limits = limits or [(float('-inf'), float('inf'))] * num_joints
        self.joint_positions = [0.0] * num_joints

    def get_positions(self):
        return self.joint_positions.copy()

    def set_positions(self, positions):
        if len(positions) != self.num_joints:
            raise ValueError(f"Expected {self.num_joints} joint positions, got {len(positions)}")
        self.joint_positions = positions.copy()

    def reset(self):
        self.joint_positions = [0.0] * self.num_joints

    def update_joint(self, joint_index, delta, min_limit=float('-inf'), max_limit=float('inf')):
        if not (0 <= joint_index < self.num_joints):
            raise ValueError(f"Joint index {joint_index} out of range")
        self.joint_positions[joint_index] += delta
        self.joint_positions[joint_index] = clamp(self.joint_positions[joint_index], min_limit, max_limit)

    def process_left_trigger_mode(self, dt, ud_pad, lr_pad, a_btn, b_btn, x_btn, y_btn):
        # D-pad controls joint 0 and 1
        step = self.inc_dec_val * dt
        self.update_joint(1, ud_pad * step, LOWER_ELBOW_SERV_LIM, UPPER_ELBOW_SERV_LIM)
        self.update_joint(0, float(lr_pad) * step)

        # A/B buttons control joint 2
        if a_btn == 1:
            self.update_joint(2, float(step))
        if b_btn == 1:
            self.update_joint(2, -float(step))

        # X/Y buttons control joint 3
        if x_btn == 1:
            self.update_joint(3, float(step))
        if y_btn == 1:
            self.update_joint(3, -float(step))

        return f"Left Trigger Mode - UD: {ud_pad}, LR: {lr_pad}"

    def process_right_trigger_mode(self, dt, a_btn, b_btn):
        step = self.inc_dec_val * dt
        # A/B buttons control joint 4
        if a_btn == 1:
            self.update_joint(4, step)
        if b_btn == 1:
            self.update_joint(4, -step)

        return "Right Trigger Mode - Controlling Joint 4"

    def get_joint_status(self):
        status = "Arm Joints: ["
        status += ", ".join([f"{pos:.1f}" for pos in self.joint_positions])
        status += "]"
        return status
