cmake_minimum_required(VERSION 3.0)
project(LockTest CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

					
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE(LockTest ${CMAKE_SOURCE_DIR}/main.cpp
						${CMAKE_SOURCE_DIR}/Lock.h
						${CMAKE_SOURCE_DIR}/LockOne.h
						${CMAKE_SOURCE_DIR}/LockOne.cpp
						${CMAKE_SOURCE_DIR}/LockTwo.h
						${CMAKE_SOURCE_DIR}/LockTwo.cpp
						${CMAKE_SOURCE_DIR}/Peterson.h
						${CMAKE_SOURCE_DIR}/Peterson.cpp
						${CMAKE_SOURCE_DIR}/Filter.h
						${CMAKE_SOURCE_DIR}/Filter.cpp
						#${CMAKE_SOURCE_DIR}/TestThread.h
						#${CMAKE_SOURCE_DIR}/TestThread.cpp
						#${CMAKE_SOURCE_DIR}/Counter.h
						#${CMAKE_SOURCE_DIR}/Counter.cpp
#						${CMAKE_SOURCE_DIR}tinycthread.h
#						${CMAKE_SOURCE_DIR}tinycthread.c
								)

							#	include_directories(${CXXTEST_INCLUDE_DIR}) 

#CXXTEST_ADD_TEST(QuickS_test QuickS_test.cc ${CMAKE_SOURCE_DIR}/QuickS_test.h QuickS.h fill.h fill.cpp)
#CXXTEST_ADD_TEST(QuickSCon_test QuickSCon_test.cc ${CMAKE_SOURCE_DIR}/QuickSCon_test.h QuickSCon.h fill.h fill.cpp)
#CXXTEST_ADD_TEST(timingP_test timingP_test.cc ${CMAKE_SOURCE_DIR}/timingP_test.h timingP.h timingP.cpp QuickS.h QuickSCon.h fill.h fill.cpp)

set_property(TARGET LockTest PROPERTY CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")



#TARGET_LINK_LIBRARIES(QuickSort Qt4::QtGui Qt4::QtWebKit)
#add_executable(QuickS_test QuickS_test.cpp QuickS.h)					
#add_executable(nav_test )
#add_test(nav_test nav_test)




