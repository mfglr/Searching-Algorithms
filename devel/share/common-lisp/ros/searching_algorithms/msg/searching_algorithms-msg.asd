
(cl:in-package :asdf)

(defsystem "searching_algorithms-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "node_index" :depends-on ("_package_node_index"))
    (:file "_package_node_index" :depends-on ("_package"))
  ))