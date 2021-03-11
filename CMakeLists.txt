cmake_minimum_required(VERSION 3.17)
project(computer_graphics_course)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS}  ${GLFW_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/GLFW/include)
include_directories(3rd/stb utils)

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    message(STATUS "GLEW ${GLEW_INCLUDE_DIRS}")
    message(STATUS "GLEW ${GLEW_LIBRARIES}")
endif()

add_executable(computer_graphics_course main.cpp ex.h 3rd/stb/stb_image.h 3rd/stb/stb_image.cpp utils/shaderLoader.h
        utils/shaderLoader.cpp src/shader_wrapper.cpp src/shader_wrapper.h src/math/vec2.cpp src/math/vec2.h test/test.cpp)

target_link_libraries(computer_graphics_course sfml-graphics sfml-audio ${OPENGL_LIBRARIES}
            ${GLUT_LIBRARY} ${GLFW_LIBRARIES} ${GLFW_STATIC_LIBRARIES} GL GLEW)