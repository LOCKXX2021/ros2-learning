#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
import threading
import time
class RotateWheelNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info(f"node {name} init")
        #创建Publisher
        self.pub_joint_states_ = self.create_publisher(JointState,"joint_states",10)
        #初始化消息接口
        self._init_joint_states()
        #创建一个rate
        self.pub_rate = self.create_rate(1000)
        #创建一个线程
        self.thread_ = threading.Thread(target=self._thread_pub)
        self.thread_.start()
    def _init_joint_states(self):#初始化消息接口
         #创建消息接口对象
        self.joint_state = JointState()
        #header
        self.joint_state.header.stamp = self.get_clock().now().to_msg()
        self.joint_state.header.frame_id= ""
        #name float64[]
        self.joint_state.name = ['left_wheel_joint','right_wheel_joint']
        #初始化速度
        self.joint_speeds = [0.0,0.0]
        #velocity float64[]
        self.joint_state.velocity=self.joint_speeds
        #position float64[] (continuous无limit)
        self.joint_state.position=[0.0,0.0]
        #effort float64[] 无力矩可为空
        self.joint_state.effort=[]
    def update_speed(self,speeds):#提供修改速度接口
        self.joint_speeds = speeds
    def _thread_pub(self):
        last_update_time = time.time()
        while rclpy.ok():
            delta_time = time.time() - last_update_time
            last_update_time = time.time()
            #更新位置
            self.joint_state.position[0] += self.joint_speeds[0] * delta_time
            self.joint_state.position[1] += self.joint_speeds[1] * delta_time
            #更新速度
            self.joint_state.velocity = self.joint_speeds
            #更新header
            self.joint_state.header.stamp = self.get_clock().now().to_msg()
            #发布
            self.pub_joint_states_.publish(self.joint_state)
            self.pub_rate.sleep()


def main(args=None):
    rclpy.init(args=args)
    node = RotateWheelNode("rotate_fishbot_wheel")
    node.update_speed([15.0,-15.0])
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
