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
    # global plt,xdata,ydata,line
    value = data.value



def listener():
    global plt
    rospy.init_node('logger', anonymous=True)
    in_topic = rospy.get_param('~in_topic')

    rospy.Subscriber(in_topic, TimeSeriesPoint, callback)
    # plt.show()

    rospy.spin()



if __name__ == '__main__':
    listener()
