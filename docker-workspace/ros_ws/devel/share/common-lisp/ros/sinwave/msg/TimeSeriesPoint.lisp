; Auto-generated. Do not edit!


(cl:in-package sinwave-msg)


;//! \htmlinclude TimeSeriesPoint.msg.html

(cl:defclass <TimeSeriesPoint> (roslisp-msg-protocol:ros-message)
  ((value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0)
   (timestamp
    :reader timestamp
    :initarg :timestamp
    :type cl:float
    :initform 0.0))
)

(cl:defclass TimeSeriesPoint (<TimeSeriesPoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TimeSeriesPoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TimeSeriesPoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sinwave-msg:<TimeSeriesPoint> is deprecated: use sinwave-msg:TimeSeriesPoint instead.")))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <TimeSeriesPoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sinwave-msg:value-val is deprecated.  Use sinwave-msg:value instead.")
  (value m))

(cl:ensure-generic-function 'timestamp-val :lambda-list '(m))
(cl:defmethod timestamp-val ((m <TimeSeriesPoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sinwave-msg:timestamp-val is deprecated.  Use sinwave-msg:timestamp instead.")
  (timestamp m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TimeSeriesPoint>) ostream)
  "Serializes a message object of type '<TimeSeriesPoint>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'timestamp))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TimeSeriesPoint>) istream)
  "Deserializes a message object of type '<TimeSeriesPoint>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'timestamp) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TimeSeriesPoint>)))
  "Returns string type for a message object of type '<TimeSeriesPoint>"
  "sinwave/TimeSeriesPoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TimeSeriesPoint)))
  "Returns string type for a message object of type 'TimeSeriesPoint"
  "sinwave/TimeSeriesPoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TimeSeriesPoint>)))
  "Returns md5sum for a message object of type '<TimeSeriesPoint>"
  "6e0b16802732d370b3f1fc6d31821639")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TimeSeriesPoint)))
  "Returns md5sum for a message object of type 'TimeSeriesPoint"
  "6e0b16802732d370b3f1fc6d31821639")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TimeSeriesPoint>)))
  "Returns full string definition for message of type '<TimeSeriesPoint>"
  (cl:format cl:nil "float64 value~%float64 timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TimeSeriesPoint)))
  "Returns full string definition for message of type 'TimeSeriesPoint"
  (cl:format cl:nil "float64 value~%float64 timestamp~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TimeSeriesPoint>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TimeSeriesPoint>))
  "Converts a ROS message object to a list"
  (cl:list 'TimeSeriesPoint
    (cl:cons ':value (value msg))
    (cl:cons ':timestamp (timestamp msg))
))
