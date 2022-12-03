cmake_minimum_required(VERSION 3.23)
project(LinkedList C)

set(CMAKE_C_STANDARD 17)

add_executable(LinkedList src/Main.c src/LinkedList/LinkedList.c src/LinkedList/LinkedList.h src/Node/Node.c src/Node/Node.h src/Data/Data.c src/Data/Data.h src/Util/Util.c src/Util/Util.h)
