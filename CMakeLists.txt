cmake_minimum_required(VERSION 3.5)

project(F1Quiz VERSION 0.1 LANGUAGES CXX)

set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
        main.cpp
        quizquestion.h
        quizquestion.cpp
        questiontemplatedata.h
        questiontemplatedata.cpp
        diskquestiontemplaterepository.h
        diskquestiontemplaterepository.cpp
        quizquestiongeneratorusecase.h
        quizquestiongeneratorusecase.cpp
        quizquestiongenerator.h
        quizquestiongenerator.cpp
)


add_executable(F1Quiz
    ${PROJECT_SOURCES})
