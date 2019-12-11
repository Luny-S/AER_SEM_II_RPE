#!/usr/bin/env python
# license removed for brevity
import time
import datetime
import math
from random import randint

import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64
from sinwave.msg import TimeSeriesPoint

time0 = 0

def talker():
    global time0
    rospy.init_node('generator', anonymous=True)
    outTopic = rospy.get_param('~outTopic')
    frequency = rospy.get_param('~frequency')
    loopExecutionFrequency = rospy.get_param('~executionFrequency')

    pub = rospy.Publisher(outTopic, TimeSeriesPoint, queue_size=10)
    rate = rospy.Rate(loopExecutionFrequency)

    msg = TimeSeriesPoint()
    time0 = rospy.get_time()
    omega = 2 * math.pi * frequency

    while not rospy.is_shutdown():
        timestamp = rospy.get_time() - time0

        msg.value = math.sin(omega*(timestamp))
        msg.timestamp = timestamp
        pub.publish(msg)

        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
