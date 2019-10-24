#!/usr/bin/env python

from beginner_tutorials.srv import *
import rospy

def handle_add_two_dp(req):
    print "Returning [%s + %s = %s]"%(req.a.value, req.b.value, (req.a.value + req.b.value))
    return AddTwoDataPointsResponse(req.a.value. + req.b.value)

def add_two_dp_server():
    rospy.init_node('Add_two_datapoints_server')
    s = rospy.Service('add_two_dp', AddTwoDataPoints, handle_add_two_dp)
    print "Ready to add two datapoints."
    rospy.spin()

if __name__ == "__main__":
    add_two_dp_server()
