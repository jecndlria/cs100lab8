CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	unit_test.cpp
)

ADD_EXECUTABLE(lab
	main.cpp
	iterator.cpp
	base.hpp
	VisitorLaTeX.cpp
)

TARGET_LINK_LIBRARIES(test gtest)


