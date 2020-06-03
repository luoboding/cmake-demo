# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本号
project(Demo VERSION 1.0)

# 查找源文件
aux_source_directory(. DIR_SRCS)


# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否使用自己的math库
option (USE_MYMATH
       "Use provided math implementation" ON)

# 是否加入math库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)  
  set (EXTRA_LIBS ${EXTRA_LIBS} math)
endif (USE_MYMATH)


# 指定生成目标
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})

