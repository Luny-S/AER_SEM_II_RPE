#!/usr/bin/env python

from sinwave.srv import AddTwoDataPoints, AddTwoDataPointsResponse
from sinwave.msg import TimeSeriesPoint
import rospy

def handle_add_two_dp(req):
    response = AddTwoDataPointsResponse()
    response.sum.timestamp = (req.a.timestamp + req.b.timestamp)/2.0
    response.sum.value = req.a.value + req.b.value

    print "[SERVER] Returning sum: [%s , %s] + [%s , %s] = [%s , %s]"\
    %( str(req.a.timestamp),str(req.a.value),str(req.b.timestamp),str(req.b.value),\
    str(response.sum.timestamp), str(response.sum.value) )
    print "*"*70
    return response

def add_two_dp_server():
    rospy.init_node('Add_two_datapoints_server')
    s = rospy.Service('add_two_dp', AddTwoDataPoints, handle_add_two_dp)
    print "Ready to add two datapoints."
    rospy.spin()

if __name__ == "__main__":
    add_two_dp_server()
