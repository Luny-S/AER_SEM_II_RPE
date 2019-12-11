#!/usr/bin/env python
# license removed for brevity
import time
import datetime
import math
from random import randint

import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64

time0 = 0

def talker():
    global time0
    rospy.init_node('time_gen', anonymous=True)
    out_topic = rospy.get_param('~out_topic')
    omega = rospy.get_param('~omega')

    pub = rospy.Publisher(out_topic, Float64, queue_size=10)
    rate = rospy.Rate(100)
    msg = Float64()
    time0 = rospy.get_time()

    while not rospy.is_shutdown():
        time = rospy.get_time()
        msg = time - time0
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    # in_topic = rospy.getParam('in_topic')

    try:
        talker()
    except rospy.ROSInterruptException:
        pass
