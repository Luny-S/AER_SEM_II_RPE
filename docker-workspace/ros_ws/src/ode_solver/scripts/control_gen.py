#!/usr/bin/env python
# license removed for brevity
import time
import datetime
import math
from random import randint

import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64
from ode_solver.msg import ControlSignal

time0 = 0
pub = []

def callback(data):
    global pub

    msg = ControlSignal()
    msg.u1 = 1*math.sin(data.data)
    msg.u2 = 2*math.cos(data.data)



    pub.publish(msg)

def talker():
    global time0, pub
    rospy.init_node('control_gen', anonymous=True)
    in_topic = rospy.get_param('~in_topic')
    out_topic = rospy.get_param('~out_topic')

    pub = rospy.Publisher(out_topic, ControlSignal, queue_size=10)
    rospy.Subscriber(in_topic, Float64, callback)
    rospy.spin()


if __name__ == '__main__':
    # in_topic = rospy.getParam('in_topic')

    try:
        talker()
    except rospy.ROSInterruptException:
        pass
