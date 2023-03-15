# CMakeList.txt: проект CMake для myPongCmake; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("myPongCmake")

set(SFML_DIR "${myPongCmake_SOURCE_DIR}/../SFML-2.5.1/lib/cmake/SFML")

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Добавьте источник в исполняемый файл этого проекта.
set(SRC_DIR "${myPongCmake_SOURCE_DIR}/src")
SET(INC_DIR "${myPongCmake_SOURCE_DIR}/inc")

message(${myPongCmake_SOURCE_DIR})
message(${SRC_DIR})
message(${INC_DIR})

add_executable (myPongCmake "${SRC_DIR}/myPongCmake.cpp"
							"${SRC_DIR}/paddle.cpp"
							"${SRC_DIR}/circle.cpp"
							"${SRC_DIR}/algorithm.cpp"
							
							"${INC_DIR}/algorithm.h"
							"${INC_DIR}/circle.h"
							"${INC_DIR}/paddle.h")

target_include_directories(myPongCmake PUBLIC ${INC_DIR})

target_link_libraries(myPongCmake sfml-graphics sfml-audio "${myPongCmake_SOURCE_DIR}/lib/box2d.lib")

#target_link_libraries(myPongCmake STATIC IMPORTED)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET myPongCmake PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
