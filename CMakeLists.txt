cmake_minimum_required(VERSION 4.3)
project(Asky)

set(CMAKE_CXX_STANDARD 23)

add_executable(Asky main.cpp
        Helper.h
        Questions.h
        User.h
        UserManager.h
        QuestionManager.h
        AskySystem.h
        Helper.cpp
        Questions.cpp
        User.cpp
        UserManager.cpp
        QuestionManager.cpp
        AskySystem.cpp)
