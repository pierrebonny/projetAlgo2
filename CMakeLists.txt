cmake_minimum_required(VERSION 3.7)
project(algo)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_ALGO source/main.cpp source/Bin.cpp source/Bin.h source/Parser.h source/Parser.cpp source/algorithmes/Algorithme.cpp source/algorithmes/Algorithme.h source/algorithmes/AlmostWorstFirst.cpp source/algorithmes/AlmostWorstFirst.h source/algorithmes/BestFit.cpp source/algorithmes/BestFit.h
        source/utils/BinaryNode.cpp source/utils/BinaryNode.h source/utils/BinaryTree.cpp source/utils/BinaryTree.h
        source/algorithmes/NextFit.cpp source/algorithmes/NextFit.h source/algorithmes/FirstFit.cpp
        source/algorithmes/FirstFit.h source/algorithmes/WorstFit.cpp source/algorithmes/WorstFit.h)

set(EXECUTABLE_OUTPUT_PATH ../)
add_executable(algo ${SOURCE_FILES_ALGO})

project(stat)
set(SOURCE_FILES_STAT source/main2.cpp source/Bin.cpp source/Bin.h source/Parser.h source/Parser.cpp source/algorithmes/Algorithme.cpp source/algorithmes/Algorithme.h source/algorithmes/AlmostWorstFirst.cpp source/algorithmes/AlmostWorstFirst.h source/algorithmes/BestFit.cpp source/algorithmes/BestFit.h
        source/utils/BinaryNode.cpp source/utils/BinaryNode.h source/utils/BinaryTree.cpp source/utils/BinaryTree.h
        source/algorithmes/NextFit.cpp source/algorithmes/NextFit.h source/algorithmes/FirstFit.cpp
        source/algorithmes/FirstFit.h source/algorithmes/WorstFit.cpp source/algorithmes/WorstFit.h)
add_executable(stat ${SOURCE_FILES_STAT})