#将目录下的所有文件给到SRC_LIST
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)
aux_source_directory(./log LOG_LIST)
aux_source_directory(./model MODEL_LIST)
aux_source_directory(./moa MOA_LIST)
#指定生成可执行文件
add_executable(main ${SRC_LIST} ${DB_LIST} ${LOG_LIST} ${MODEL_LIST} ${MOA_LIST})

#指定可执行文件链接时需要依赖的库文件
target_link_libraries(main libmysql)