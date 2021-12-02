CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)
ADD_COMPILE_OPTIONS(-g -O0)
ADD_EXECUTABLE(test
	unit_test.cpp

	iterator.cpp
	VisitorLaTeX.cpp
	add.cpp 
	div.cpp 
	mult.cpp 
	op.cpp 
	pow.cpp 
	rand.cpp 
	sub.cpp 
)

ADD_EXECUTABLE(lab
	main.cpp
	iterator.cpp
	VisitorLaTeX.cpp
	add.cpp 
	div.cpp 
	mult.cpp 
	op.cpp 
	pow.cpp 
	rand.cpp 
	sub.cpp 
)

TARGET_LINK_LIBRARIES(test gtest)


