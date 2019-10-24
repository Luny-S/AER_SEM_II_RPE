;; Auto-generated. Do not edit!


(when (boundp 'sinwave::WorkaroundDouble)
  (if (not (find-package "SINWAVE"))
    (make-package "SINWAVE"))
  (shadow 'WorkaroundDouble (find-package "SINWAVE")))
(unless (find-package "SINWAVE::WORKAROUNDDOUBLE")
  (make-package "SINWAVE::WORKAROUNDDOUBLE"))

(in-package "ROS")
;;//! \htmlinclude WorkaroundDouble.msg.html


(defclass sinwave::WorkaroundDouble
  :super ros::object
  :slots (_value ))

(defmethod sinwave::WorkaroundDouble
  (:init
   (&key
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _value (float __value))
   self)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; float64 _value
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _value
       (sys::poke _value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _value
     (setq _value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get sinwave::WorkaroundDouble :md5sum-) "1b1594d2b74931ef8fe7be8e2d594455")
(setf (get sinwave::WorkaroundDouble :datatype-) "sinwave/WorkaroundDouble")
(setf (get sinwave::WorkaroundDouble :definition-)
      "float64 value

")



(provide :sinwave/WorkaroundDouble "1b1594d2b74931ef8fe7be8e2d594455")


