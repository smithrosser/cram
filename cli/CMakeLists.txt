project(cram_cli)
set(SRC "cli.cpp")

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} cram_lib cxxopts)
