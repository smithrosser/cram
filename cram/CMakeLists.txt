project(cram_lib)
set(SRC "./cram.cpp")

add_library(${PROJECT_NAME} STATIC ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC "./include")

