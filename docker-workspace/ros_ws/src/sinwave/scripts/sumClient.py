#!/usr/bin/env python

import sys
import rospy
#import time
#import datetime
import random

from sinwave.srv import AddTwoDataPoints, AddTwoDataPointsResponse
from sinwave.msg import TimeSeriesPoint

def add_two_dp_client(dp1, dp2):
    rospy.wait_for_service('add_two_dp')
    try:
        add_two_dp = rospy.ServiceProxy('add_two_dp', AddTwoDataPoints)
        response = add_two_dp(dp1, dp2)
        return response.sum
    except rospy.ServiceException, e:
        print "Service call failed: %s"%e

def client():
    dp1 = TimeSeriesPoint()
    dp2 = TimeSeriesPoint()

    rospy.init_node('Add_two_datapoints_client', anonymous=True)
    numberOfDigits = rospy.get_param('~numberOfDigits')
    rateOfExecution = rospy.get_param('~rateOfExecution')
    rate = rospy.Rate(rateOfExecution)

    time0 = rospy.get_time()

    while not rospy.is_shutdown():
        dp1.timestamp = round(rospy.get_time() - time0 , numberOfDigits)
        dp2.timestamp = dp1.timestamp
        dp1.value = round((random.random()-0.5) * 100 , numberOfDigits)
        dp2.value = round((random.random()-0.5) * 100 , numberOfDigits)
        print "[Client] Sending datapoints: [%s , %s] , [%s , %s]"%\
        (str(dp1.timestamp),str(dp1.value),str(dp2.timestamp),str(dp2.value))
        print "*"*70
        response = add_two_dp_client(dp1,dp2)

        rate.sleep()


if __name__ == '__main__':
    try:
        client()
    except rospy.ROSInterruptException:
        pass
