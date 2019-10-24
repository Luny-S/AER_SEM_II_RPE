; Auto-generated. Do not edit!


(cl:in-package sinwave-srv)


;//! \htmlinclude AddTwoDataPoints-request.msg.html

(cl:defclass <AddTwoDataPoints-request> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type sinwave-msg:TimeSeriesPoint
    :initform (cl:make-instance 'sinwave-msg:TimeSeriesPoint))
   (b
    :reader b
    :initarg :b
    :type sinwave-msg:TimeSeriesPoint
    :initform (cl:make-instance 'sinwave-msg:TimeSeriesPoint)))
)

(cl:defclass AddTwoDataPoints-request (<AddTwoDataPoints-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AddTwoDataPoints-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AddTwoDataPoints-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sinwave-srv:<AddTwoDataPoints-request> is deprecated: use sinwave-srv:AddTwoDataPoints-request instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <AddTwoDataPoints-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sinwave-srv:a-val is deprecated.  Use sinwave-srv:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <AddTwoDataPoints-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sinwave-srv:b-val is deprecated.  Use sinwave-srv:b instead.")
  (b m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AddTwoDataPoints-request>) ostream)
  "Serializes a message object of type '<AddTwoDataPoints-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'a) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'b) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AddTwoDataPoints-request>) istream)
  "Deserializes a message object of type '<AddTwoDataPoints-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'a) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'b) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AddTwoDataPoints-request>)))
  "Returns string type for a service object of type '<AddTwoDataPoints-request>"
  "sinwave/AddTwoDataPointsRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddTwoDataPoints-request)))
  "Returns string type for a service object of type 'AddTwoDataPoints-request"
  "sinwave/AddTwoDataPointsRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AddTwoDataPoints-request>)))
  "Returns md5sum for a message object of type '<AddTwoDataPoints-request>"
  "90646d2d2f45747163c2b98b43301e86")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AddTwoDataPoints-request)))
  "Returns md5sum for a message object of type 'AddTwoDataPoints-request"
  "90646d2d2f45747163c2b98b43301e86")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AddTwoDataPoints-request>)))
  "Returns full string definition for message of type '<AddTwoDataPoints-request>"
  (cl:format cl:nil "TimeSeriesPoint a~%TimeSeriesPoint b~%~%================================================================================~%MSG: sinwave/TimeSeriesPoint~%float64 value~%float64 timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AddTwoDataPoints-request)))
  "Returns full string definition for message of type 'AddTwoDataPoints-request"
  (cl:format cl:nil "TimeSeriesPoint a~%TimeSeriesPoint b~%~%================================================================================~%MSG: sinwave/TimeSeriesPoint~%float64 value~%float64 timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AddTwoDataPoints-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'a))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'b))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AddTwoDataPoints-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AddTwoDataPoints-request
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
))
;//! \htmlinclude AddTwoDataPoints-response.msg.html

(cl:defclass <AddTwoDataPoints-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type sinwave-msg:TimeSeriesPoint
    :initform (cl:make-instance 'sinwave-msg:TimeSeriesPoint)))
)

(cl:defclass AddTwoDataPoints-response (<AddTwoDataPoints-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AddTwoDataPoints-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AddTwoDataPoints-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sinwave-srv:<AddTwoDataPoints-response> is deprecated: use sinwave-srv:AddTwoDataPoints-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <AddTwoDataPoints-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sinwave-srv:sum-val is deprecated.  Use sinwave-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AddTwoDataPoints-response>) ostream)
  "Serializes a message object of type '<AddTwoDataPoints-response>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'sum) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AddTwoDataPoints-response>) istream)
  "Deserializes a message object of type '<AddTwoDataPoints-response>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'sum) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AddTwoDataPoints-response>)))
  "Returns string type for a service object of type '<AddTwoDataPoints-response>"
  "sinwave/AddTwoDataPointsResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddTwoDataPoints-response)))
  "Returns string type for a service object of type 'AddTwoDataPoints-response"
  "sinwave/AddTwoDataPointsResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AddTwoDataPoints-response>)))
  "Returns md5sum for a message object of type '<AddTwoDataPoints-response>"
  "90646d2d2f45747163c2b98b43301e86")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AddTwoDataPoints-response)))
  "Returns md5sum for a message object of type 'AddTwoDataPoints-response"
  "90646d2d2f45747163c2b98b43301e86")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AddTwoDataPoints-response>)))
  "Returns full string definition for message of type '<AddTwoDataPoints-response>"
  (cl:format cl:nil "TimeSeriesPoint sum~%~%~%================================================================================~%MSG: sinwave/TimeSeriesPoint~%float64 value~%float64 timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AddTwoDataPoints-response)))
  "Returns full string definition for message of type 'AddTwoDataPoints-response"
  (cl:format cl:nil "TimeSeriesPoint sum~%~%~%================================================================================~%MSG: sinwave/TimeSeriesPoint~%float64 value~%float64 timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AddTwoDataPoints-response>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'sum))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AddTwoDataPoints-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AddTwoDataPoints-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AddTwoDataPoints)))
  'AddTwoDataPoints-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AddTwoDataPoints)))
  'AddTwoDataPoints-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AddTwoDataPoints)))
  "Returns string type for a service object of type '<AddTwoDataPoints>"
  "sinwave/AddTwoDataPoints")