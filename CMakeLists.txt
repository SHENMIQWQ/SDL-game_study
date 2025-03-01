#标题
cmake_minimum_required(VERSION 3.5.0)
project(BiohazardChicken VERSION 0.1.0 LANGUAGES C CXX)
  
#设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#设置编译选项
add_compile_options(/W4)

#设置编译输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

#设置一个名字
set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

#查找并载入Cmake预设
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
#添加可执行文件
add_executable(${TARGET}
               "src/main.cpp"
                "src/vector2.h"
                "src/timer.h"
                "src/camera.h"
               "src/atlas.h"
               "src/animation.h"
               "src/bullet.h"
               "src/chicken.h"
               "src/chicken_fast.h"
               "src/chicken_medium.h"
               "src/chicken_slow.h"
               
            )

#链接库
target_link_libraries(${TARGET} 
                        ${SDL2_LIBRARIES}
                        SDL2_image::SDL2_image
                        SDL2_mixer::SDL2_mixer
                        SDL2_ttf::SDL2_ttf
                        )