#To use cmake, you create a folder for all the compiled/build files
#and don't usually compile things in the same directory as your source files

#I usually do something like the following:
#for xcode:
#mkdir xcode
#cd xcode
#cmake -G Xcode .. #tells cmake to make an XCode project, and that the CMakelists.txt file is in the directory above
#you can then open the arkanoid.xcodeproj file with xcode
#in product -> scheme, select arkanoid to run that executable when you press
#the play button

# to use make, I do something like
#mkdir build
#cd build
#cmake .. #by default it creates a makefile for you
#make #calls the make command which looks in Makefile to see what to do
#./arkanoid  #run the resulting file


#use a recent version of CMake
cmake_minimum_required(VERSION 3.8)

#the project is called arkanoid
project(arkanoid)

#the project contains the following executables:

#'arkanoid' that uses the following cpp files
add_executable(arkanoid arkanoid.cpp block.hpp block.cpp ball.hpp ball.cpp bar.cpp bar.hpp level.hpp level.cpp game.hpp game.cpp field.hpp field.cpp)

#'arkanoidTests' that uses the following cpp files
add_executable(arkanoidTests block.cpp ball.cpp bar.cpp level.cpp game.cpp field.cpp catch.hpp arkanoidTests.cpp blockTests.cpp)

#create a folder named "cmake" at the top of your project and put the
#findSFML.cmake file in it.  This line tells Cmake to look there for
#find____.cmake files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

#this says find the graphics, window, and system libraries
#it uses the FindSFML.cmake file to do so and sets
#some variables ($SFML_LIBRARIES and SFML_INCLUDE_DIRECTORIES) that are
#used below
find_package( SFML REQUIRED COMPONENTS graphics window system)

#tells Cmake that the arkanoid s executable needs to be linked with SFML
target_link_libraries(arkanoid ${SFML_LIBRARIES})
target_link_libraries(arkanoidTests ${SFML_LIBRARIES})

#and needs to look wherever the SFML headers are
target_include_directories(arkanoid PUBLIC ${SFML_INCLUDE_DIR})
target_include_directories(arkanoidTests PUBLIC ${SFML_INCLUDE_DIR})

#passes an option to clang when compiling to use recent c++ stuff
target_compile_options(arkanoid PUBLIC -std=c++14)
target_compile_options(arkanoidTests PUBLIC -std=c++14)