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
sub1 = []
sub2 = []


data1_flag = 0
data2_flag = 0
data1 = 0
data2 = 0


def callback1(data):
    global pub,data1_flag,data1,data2_flag,data2
    data1 = data.value
    if data2_flag:
        msg = TimeSeriesPoint()
        msg.timestamp = data.timestamp
        msg.value = data1+data2
        pub.publish(msg)
        data1_flag = 0
        data2_flag = 0
    else:
        data1_flag = 1

def callback2(data):
    global pub,data1_flag,data1,data2_flag,data2
    data2 = data.value
    if data1_flag:
        msg = TimeSeriesPoint()
        msg.timestamp = data.timestamp
        msg.value = data1+data2
        pub.publish(msg)
        data1_flag = 0
        data2_flag = 0
    else:
        data2_flag = 1

def talker():
    global pub, gain, sub1, sub2
    rospy.init_node('integration', anonymous=True)
    in_topic1 = rospy.get_param('~inTopic1')
    in_topic2 = rospy.get_param('~inTopic2')
    out_topic = rospy.get_param('~outTopic')

    pub = rospy.Publisher(out_topic, TimeSeriesPoint, queue_size=10)
    sub1 = rospy.Subscriber(in_topic1, TimeSeriesPoint, callback1)
    sub2 = rospy.Subscriber(in_topic2, TimeSeriesPoint, callback2)
    rospy.spin()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
