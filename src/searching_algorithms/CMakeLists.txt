cmake_minimum_required(VERSION 3.0.2)
project(searching_algorithms)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_message_files(
  FILES
  node_index.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

add_executable( ucs src/ucs.cpp )
target_link_libraries(ucs ${catkin_LIBRARIES} )
add_dependencies(ucs searching_algorithms_ucs)

add_executable( astar src/astar.cpp )
target_link_libraries(astar ${catkin_LIBRARIES} )
add_dependencies(astar searching_algorithms_astar)