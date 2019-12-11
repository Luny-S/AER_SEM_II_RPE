#!/usr/bin/env python
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float64

import time
import datetime
import math
import numpy as np
import matplotlib.pyplot as plt
from sinwave.msg import TimeSeriesPoint

def callback(data):
    print data
    print '*'*25

def listener():
    global plt
    rospy.init_node('logger', anonymous=True)
    inTopic = rospy.get_param('~inTopic')
    rospy.Subscriber(inTopic, TimeSeriesPoint, callback)
    rospy.spin()

if __name__ == '__main__':
    listener()
