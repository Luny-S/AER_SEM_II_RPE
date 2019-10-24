;; Auto-generated. Do not edit!


(when (boundp 'sinwave::TimeSeriesPoint)
  (if (not (find-package "SINWAVE"))
    (make-package "SINWAVE"))
  (shadow 'TimeSeriesPoint (find-package "SINWAVE")))
(unless (find-package "SINWAVE::TIMESERIESPOINT")
  (make-package "SINWAVE::TIMESERIESPOINT"))

(in-package "ROS")
;;//! \htmlinclude TimeSeriesPoint.msg.html


(defclass sinwave::TimeSeriesPoint
  :super ros::object
  :slots (_value _timestamp ))

(defmethod sinwave::TimeSeriesPoint
  (:init
   (&key
    ((:value __value) 0.0)
    ((:timestamp __timestamp) 0.0)
    )
   (send-super :init)
   (setq _value (float __value))
   (setq _timestamp (float __timestamp))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:timestamp
   (&optional __timestamp)
   (if __timestamp (setq _timestamp __timestamp)) _timestamp)
  (:serialization-length
   ()
   (+
    ;; float64 _value
    8
    ;; float64 _timestamp
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _value
       (sys::poke _value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _timestamp
       (sys::poke _timestamp (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _value
     (setq _value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _timestamp
     (setq _timestamp (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get sinwave::TimeSeriesPoint :md5sum-) "6e0b16802732d370b3f1fc6d31821639")
(setf (get sinwave::TimeSeriesPoint :datatype-) "sinwave/TimeSeriesPoint")
(setf (get sinwave::TimeSeriesPoint :definition-)
      "float64 value
float64 timestamp

")



(provide :sinwave/TimeSeriesPoint "6e0b16802732d370b3f1fc6d31821639")


