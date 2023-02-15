#!/usr/bin/env python3
#导包  引入消息接口
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

#继承Node父类，建立Publisher类，属性应具有发布话题作用
class Publisher_node(Node):
    def __init__(self,name) -> None:
        super().__init__(name)
        self.get_logger().info("%s node start"% name)
        self.command_publisher_ = self.create_publisher(String,"command", 10) 
        self._timer = self.create_timer(0.5,self.timer_callback)#定时器，可以改为rate api结合线程
    def timer_callback_(self):#定时器回调函数，经历所需执行周期后执行
        msg = String()
        msg.data = "backup"
        self.command_publisher_.publish(msg)
        self.get_logger().info(f"发布了指令:{msg.data}")

def main(args=None):
    rclpy.init(args=None)
    node = Publisher_node("command_publisher")
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
