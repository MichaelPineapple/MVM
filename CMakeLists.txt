cmake_minimum_required(VERSION 3.15)
project(glfw_app)
add_executable(app 
src/main.c
src/interface.c
src/processor.c
)
set_target_properties(app PROPERTIES LINKER_LANGUAGE C C_STANDARD 11)
target_compile_definitions(app PUBLIC GL_SILENCE_DEPRECATION)
target_link_directories(app PUBLIC glfw3/lib/)
target_include_directories(app PUBLIC glfw3/include/)
target_link_libraries(app glfw3)
target_link_libraries(app "-framework Cocoa" "-framework IOKit")
target_link_libraries(app "-framework OpenGL")