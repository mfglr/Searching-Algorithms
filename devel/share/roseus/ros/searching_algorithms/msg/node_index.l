;; Auto-generated. Do not edit!


(when (boundp 'searching_algorithms::node_index)
  (if (not (find-package "SEARCHING_ALGORITHMS"))
    (make-package "SEARCHING_ALGORITHMS"))
  (shadow 'node_index (find-package "SEARCHING_ALGORITHMS")))
(unless (find-package "SEARCHING_ALGORITHMS::NODE_INDEX")
  (make-package "SEARCHING_ALGORITHMS::NODE_INDEX"))

(in-package "ROS")
;;//! \htmlinclude node_index.msg.html


(defclass searching_algorithms::node_index
  :super ros::object
  :slots (_stop _index _color ))

(defmethod searching_algorithms::node_index
  (:init
   (&key
    ((:stop __stop) 0)
    ((:index __index) 0)
    ((:color __color) 0)
    )
   (send-super :init)
   (setq _stop (round __stop))
   (setq _index (round __index))
   (setq _color (round __color))
   self)
  (:stop
   (&optional __stop)
   (if __stop (setq _stop __stop)) _stop)
  (:index
   (&optional __index)
   (if __index (setq _index __index)) _index)
  (:color
   (&optional __color)
   (if __color (setq _color __color)) _color)
  (:serialization-length
   ()
   (+
    ;; int32 _stop
    4
    ;; int32 _index
    4
    ;; int32 _color
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _stop
       (write-long _stop s)
     ;; int32 _index
       (write-long _index s)
     ;; int32 _color
       (write-long _color s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _stop
     (setq _stop (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _index
     (setq _index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _color
     (setq _color (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get searching_algorithms::node_index :md5sum-) "a66179b4ab883cc0c91011178517137f")
(setf (get searching_algorithms::node_index :datatype-) "searching_algorithms/node_index")
(setf (get searching_algorithms::node_index :definition-)
      "int32 stop
int32 index
int32 color
")



(provide :searching_algorithms/node_index "a66179b4ab883cc0c91011178517137f")


