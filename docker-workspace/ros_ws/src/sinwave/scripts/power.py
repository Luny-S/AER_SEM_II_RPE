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

pub = []
power = 1


def callback(data):
    global pub,power
    msg = TimeSeriesPoint()
    msg.value = math.pow(data.value,power)
    msg.timestamp = data.timestamp
    pub.publish(msg)


def talker():
    global pub, power
    rospy.init_node('power', anonymous=True)
    in_topic = rospy.get_param('~in_topic')
    out_topic = rospy.get_param('~out_topic')
    power = rospy.get_param('~power')

    if(power < 1):
        raise ValueError('Power shall not be less than 1')

    pub = rospy.Publisher(out_topic, TimeSeriesPoint, queue_size=10)
    rospy.Subscriber(in_topic, TimeSeriesPoint, callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
