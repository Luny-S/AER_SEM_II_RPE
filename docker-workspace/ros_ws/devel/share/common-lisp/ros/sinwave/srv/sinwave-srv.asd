
(cl:in-package :asdf)

(defsystem "sinwave-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :sinwave-msg
)
  :components ((:file "_package")
    (:file "AddTwoDataPoints" :depends-on ("_package_AddTwoDataPoints"))
    (:file "_package_AddTwoDataPoints" :depends-on ("_package"))
  ))