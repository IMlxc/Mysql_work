# 配置最低版本
cmake_minimum_required(VERSION 3.30.0)
# 设置项目名称
project(Mysql_Work VERSION 1.0.0)

# 配置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 配置最终的可执行文件输出的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 配置头文件的搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include/mysql)
include_directories(${PROJECT_SOURCE_DIR}/include/db)
include_directories(${PROJECT_SOURCE_DIR}/include/model)
include_directories(${PROJECT_SOURCE_DIR}/include/log)
include_directories(${PROJECT_SOURCE_DIR}/include/thirdparty)
# 配置文件链接路径
link_directories(${PROJECT_SOURCE_DIR}/lib)


# 加载子目录
add_subdirectory(src)