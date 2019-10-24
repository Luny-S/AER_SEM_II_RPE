;; Auto-generated. Do not edit!


(when (boundp 'sinwave::AddTwoDataPoints)
  (if (not (find-package "SINWAVE"))
    (make-package "SINWAVE"))
  (shadow 'AddTwoDataPoints (find-package "SINWAVE")))
(unless (find-package "SINWAVE::ADDTWODATAPOINTS")
  (make-package "SINWAVE::ADDTWODATAPOINTS"))
(unless (find-package "SINWAVE::ADDTWODATAPOINTSREQUEST")
  (make-package "SINWAVE::ADDTWODATAPOINTSREQUEST"))
(unless (find-package "SINWAVE::ADDTWODATAPOINTSRESPONSE")
  (make-package "SINWAVE::ADDTWODATAPOINTSRESPONSE"))

(in-package "ROS")





(defclass sinwave::AddTwoDataPointsRequest
  :super ros::object
  :slots (_a _b ))

(defmethod sinwave::AddTwoDataPointsRequest
  (:init
   (&key
    ((:a __a) (instance sinwave::TimeSeriesPoint :init))
    ((:b __b) (instance sinwave::TimeSeriesPoint :init))
    )
   (send-super :init)
   (setq _a __a)
   (setq _b __b)
   self)
  (:a
   (&rest __a)
   (if (keywordp (car __a))
       (send* _a __a)
     (progn
       (if __a (setq _a (car __a)))
       _a)))
  (:b
   (&rest __b)
   (if (keywordp (car __b))
       (send* _b __b)
     (progn
       (if __b (setq _b (car __b)))
       _b)))
  (:serialization-length
   ()
   (+
    ;; sinwave/TimeSeriesPoint _a
    (send _a :serialization-length)
    ;; sinwave/TimeSeriesPoint _b
    (send _b :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sinwave/TimeSeriesPoint _a
       (send _a :serialize s)
     ;; sinwave/TimeSeriesPoint _b
       (send _b :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sinwave/TimeSeriesPoint _a
     (send _a :deserialize buf ptr-) (incf ptr- (send _a :serialization-length))
   ;; sinwave/TimeSeriesPoint _b
     (send _b :deserialize buf ptr-) (incf ptr- (send _b :serialization-length))
   ;;
   self)
  )

(defclass sinwave::AddTwoDataPointsResponse
  :super ros::object
  :slots (_sum ))

(defmethod sinwave::AddTwoDataPointsResponse
  (:init
   (&key
    ((:sum __sum) (instance sinwave::TimeSeriesPoint :init))
    )
   (send-super :init)
   (setq _sum __sum)
   self)
  (:sum
   (&rest __sum)
   (if (keywordp (car __sum))
       (send* _sum __sum)
     (progn
       (if __sum (setq _sum (car __sum)))
       _sum)))
  (:serialization-length
   ()
   (+
    ;; sinwave/TimeSeriesPoint _sum
    (send _sum :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; sinwave/TimeSeriesPoint _sum
       (send _sum :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; sinwave/TimeSeriesPoint _sum
     (send _sum :deserialize buf ptr-) (incf ptr- (send _sum :serialization-length))
   ;;
   self)
  )

(defclass sinwave::AddTwoDataPoints
  :super ros::object
  :slots ())

(setf (get sinwave::AddTwoDataPoints :md5sum-) "90646d2d2f45747163c2b98b43301e86")
(setf (get sinwave::AddTwoDataPoints :datatype-) "sinwave/AddTwoDataPoints")
(setf (get sinwave::AddTwoDataPoints :request) sinwave::AddTwoDataPointsRequest)
(setf (get sinwave::AddTwoDataPoints :response) sinwave::AddTwoDataPointsResponse)

(defmethod sinwave::AddTwoDataPointsRequest
  (:response () (instance sinwave::AddTwoDataPointsResponse :init)))

(setf (get sinwave::AddTwoDataPointsRequest :md5sum-) "90646d2d2f45747163c2b98b43301e86")
(setf (get sinwave::AddTwoDataPointsRequest :datatype-) "sinwave/AddTwoDataPointsRequest")
(setf (get sinwave::AddTwoDataPointsRequest :definition-)
      "TimeSeriesPoint a
TimeSeriesPoint b

================================================================================
MSG: sinwave/TimeSeriesPoint
float64 value
float64 timestamp
---
TimeSeriesPoint sum


================================================================================
MSG: sinwave/TimeSeriesPoint
float64 value
float64 timestamp
")

(setf (get sinwave::AddTwoDataPointsResponse :md5sum-) "90646d2d2f45747163c2b98b43301e86")
(setf (get sinwave::AddTwoDataPointsResponse :datatype-) "sinwave/AddTwoDataPointsResponse")
(setf (get sinwave::AddTwoDataPointsResponse :definition-)
      "TimeSeriesPoint a
TimeSeriesPoint b

================================================================================
MSG: sinwave/TimeSeriesPoint
float64 value
float64 timestamp
---
TimeSeriesPoint sum


================================================================================
MSG: sinwave/TimeSeriesPoint
float64 value
float64 timestamp
")



(provide :sinwave/AddTwoDataPoints "90646d2d2f45747163c2b98b43301e86")


