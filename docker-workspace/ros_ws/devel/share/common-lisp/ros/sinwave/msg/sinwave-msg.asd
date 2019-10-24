
(cl:in-package :asdf)

(defsystem "sinwave-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "TimeSeriesPoint" :depends-on ("_package_TimeSeriesPoint"))
    (:file "_package_TimeSeriesPoint" :depends-on ("_package"))
    (:file "WorkaroundDouble" :depends-on ("_package_WorkaroundDouble"))
    (:file "_package_WorkaroundDouble" :depends-on ("_package"))
  ))