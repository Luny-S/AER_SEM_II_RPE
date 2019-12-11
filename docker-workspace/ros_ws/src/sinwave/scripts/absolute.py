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

def callback(data):
    global pub
    msg = TimeSeriesPoint()
    msg.value = math.fabs(data.value)
    msg.timestamp = data.timestamp
    pub.publish(msg)


def talker():
    global pub, power
    rospy.init_node('power', anonymous=True)
    in_topic = rospy.get_param('~inTopic')
    out_topic = rospy.get_param('~outTopic')

    pub = rospy.Publisher(out_topic, TimeSeriesPoint, queue_size=10)
    rospy.Subscriber(in_topic, TimeSeriesPoint, callback)
    rospy.spin()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
