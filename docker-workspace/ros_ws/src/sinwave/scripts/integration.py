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
sum = 0;
timestamp = 0;


def callback(data):
    global pub,sum, timestamp
    msg = TimeSeriesPoint()
    sum = sum + (data.value * (data.timestamp - timestamp))
    timestamp = data.timestamp
    msg.timestamp = timestamp
    msg.value = sum
    pub.publish(msg)


def talker():
    global pub, sum
    rospy.init_node('integration', anonymous=True)
    in_topic = rospy.get_param('~in_topic')
    out_topic = rospy.get_param('~out_topic')
    sum = rospy.get_param('~initial_value')

    pub = rospy.Publisher(out_topic, TimeSeriesPoint, queue_size=10)
    rospy.Subscriber(in_topic, TimeSeriesPoint, callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
