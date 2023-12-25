; Auto-generated. Do not edit!


(cl:in-package searching_algorithms-msg)


;//! \htmlinclude node_index.msg.html

(cl:defclass <node_index> (roslisp-msg-protocol:ros-message)
  ((stop
    :reader stop
    :initarg :stop
    :type cl:integer
    :initform 0)
   (index
    :reader index
    :initarg :index
    :type cl:integer
    :initform 0)
   (color
    :reader color
    :initarg :color
    :type cl:integer
    :initform 0))
)

(cl:defclass node_index (<node_index>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <node_index>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'node_index)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name searching_algorithms-msg:<node_index> is deprecated: use searching_algorithms-msg:node_index instead.")))

(cl:ensure-generic-function 'stop-val :lambda-list '(m))
(cl:defmethod stop-val ((m <node_index>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader searching_algorithms-msg:stop-val is deprecated.  Use searching_algorithms-msg:stop instead.")
  (stop m))

(cl:ensure-generic-function 'index-val :lambda-list '(m))
(cl:defmethod index-val ((m <node_index>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader searching_algorithms-msg:index-val is deprecated.  Use searching_algorithms-msg:index instead.")
  (index m))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <node_index>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader searching_algorithms-msg:color-val is deprecated.  Use searching_algorithms-msg:color instead.")
  (color m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <node_index>) ostream)
  "Serializes a message object of type '<node_index>"
  (cl:let* ((signed (cl:slot-value msg 'stop)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'index)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'color)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <node_index>) istream)
  "Deserializes a message object of type '<node_index>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stop) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'index) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<node_index>)))
  "Returns string type for a message object of type '<node_index>"
  "searching_algorithms/node_index")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'node_index)))
  "Returns string type for a message object of type 'node_index"
  "searching_algorithms/node_index")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<node_index>)))
  "Returns md5sum for a message object of type '<node_index>"
  "a66179b4ab883cc0c91011178517137f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'node_index)))
  "Returns md5sum for a message object of type 'node_index"
  "a66179b4ab883cc0c91011178517137f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<node_index>)))
  "Returns full string definition for message of type '<node_index>"
  (cl:format cl:nil "int32 stop~%int32 index~%int32 color~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'node_index)))
  "Returns full string definition for message of type 'node_index"
  (cl:format cl:nil "int32 stop~%int32 index~%int32 color~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <node_index>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <node_index>))
  "Converts a ROS message object to a list"
  (cl:list 'node_index
    (cl:cons ':stop (stop msg))
    (cl:cons ':index (index msg))
    (cl:cons ':color (color msg))
))
