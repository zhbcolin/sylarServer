cmake_minimum_required(VERSION 3.0)
project(sylar)

include (cmake/utils.cmake)

set(CMAKE_CXX_FLAGS "-D_GLIBCXX_USE_CXX11_ABI=0")
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function  -Wno-builtin-macro-redefined")

include_directories(.)
include_directories(/user/local/include)
link_directories(/user/local/lib)

set(LIB_SRC
        sylar/log.cpp
        sylar/util.cpp
        sylar/config.cpp
        sylar/thread.cpp
        sylar/fiber.cpp
        sylar/scheduler.cpp
        sylar/iomanager.cpp
        sylar/timer.cpp
        sylar/hook.cpp
        sylar/fd_manager.cpp
        sylar/address.cpp
        sylar/socket.cpp
        sylar/bytearray.cpp
        sylar/http/http.cpp
        sylar/http/http_parser.cpp
        sylar/tcp_server.cpp
        sylar/stream.cpp
        sylar/socket_stream.cpp
        sylar/http/http_session.cpp
        sylar/http/http_server.cpp
        sylar/http/servlet.cpp
        sylar/http/http_connection.cpp
        sylar/daemon.cpp
        sylar/env.cpp
        sylar/application.cpp
        )

ragelmaker(sylar/http/http11_parser.rl LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sylar/http)
ragelmaker(sylar/http/httpclient_parser.rl LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sylar/http)
ragelmaker(sylar/uri.rl LIB_SRC ${CMAKE_CURRENT_SOURCE_DIR}/sylar)

add_library(sylar SHARED ${LIB_SRC})
force_redefine_file_macro_for_sources(sylar) #__FILE__
#add_library(sylar_static STATIC ${LIB_SRC})
#SET_TARGET_PROPERTIES (sylar_static PROPERTIES OUTPUT_NAME "sylar")

find_library(YAMLCPP yaml-cpp)
find_library(PTHREAD pthread)
#set(LIBS ${LIBS} sylar)
#set(LIBS ${LIBS} dl)
#set(LIBS ${LIBS} ${YAMLCPP})
#set(LIBS ${LIBS} ${PTHREAD})

set(LIBS
        sylar
        dl
        pthread
        yaml-cpp
)

add_executable(test tests/test.cpp)
add_dependencies(test sylar)
force_redefine_file_macro_for_sources(test) #__FILE__
target_link_libraries(test ${LIBS})

add_executable(test_config tests/test_config.cpp)
add_dependencies(test_config sylar)
force_redefine_file_macro_for_sources(test_config) #__FILE__
target_link_libraries(test_config ${LIBS})

add_executable(test_thread tests/test_thread.cpp)
add_dependencies(test_thread sylar)
force_redefine_file_macro_for_sources(test_thread) #__FILE__
target_link_libraries(test_thread ${LIBS})

add_executable(test_util tests/test_util.cpp)
add_dependencies(test_util sylar)
force_redefine_file_macro_for_sources(test_util) #__FILE__
target_link_libraries(test_util ${LIBS})

add_executable(test_fiber tests/test_fiber.cpp)
add_dependencies(test_fiber sylar)
force_redefine_file_macro_for_sources(test_fiber) #__FILE__
target_link_libraries(test_fiber ${LIBS})

add_executable(test_schedule tests/test_schedule.cpp)
add_dependencies(test_schedule sylar)
force_redefine_file_macro_for_sources(test_schedule) #__FILE__
target_link_libraries(test_schedule ${LIBS})

add_executable(test_iomanager tests/test_iomanager.cpp)
add_dependencies(test_iomanager sylar)
force_redefine_file_macro_for_sources(test_iomanager) #__FILE__
target_link_libraries(test_iomanager ${LIBS})

add_executable(test_hook tests/test_hook.cpp)
add_dependencies(test_hook sylar)
force_redefine_file_macro_for_sources(test_hook) #__FILE__
target_link_libraries(test_hook ${LIBS})

add_executable(test_address tests/test_address.cpp)
add_dependencies(test_address sylar)
force_redefine_file_macro_for_sources(test_address) #__FILE__
target_link_libraries(test_address ${LIBS})

add_executable(test_socket tests/test_socket.cpp)
add_dependencies(test_socket sylar)
force_redefine_file_macro_for_sources(test_socket) #__FILE__
target_link_libraries(test_socket ${LIBS})

add_executable(test_bytearray tests/test_bytearray.cpp)
add_dependencies(test_bytearray sylar)
force_redefine_file_macro_for_sources(test_bytearray) #__FILE__
target_link_libraries(test_bytearray ${LIBS})

add_executable(test_http tests/test_http.cpp)
add_dependencies(test_http sylar)
force_redefine_file_macro_for_sources(test_http) #__FILE__
target_link_libraries(test_http ${LIBS})

add_executable(test_http_parser tests/test_http_parser.cpp)
add_dependencies(test_http_parser sylar)
force_redefine_file_macro_for_sources(test_http_parser) #__FILE__
target_link_libraries(test_http_parser ${LIBS})

add_executable(test_tcp_server tests/test_tcp_server.cpp)
add_dependencies(test_tcp_server sylar)
force_redefine_file_macro_for_sources(test_tcp_server) #__FILE__
target_link_libraries(test_tcp_server ${LIBS})

add_executable(test_http_server tests/test_http_server.cpp)
add_dependencies(test_http_server sylar)
force_redefine_file_macro_for_sources(test_http_server) #__FILE__
target_link_libraries(test_http_server ${LIBS})

add_executable(test_http_connection tests/test_http_connection.cpp)
add_dependencies(test_http_connection sylar)
force_redefine_file_macro_for_sources(test_http_connection) #__FILE__
target_link_libraries(test_http_connection ${LIBS})

add_executable(test_uri tests/test_uri.cpp)
add_dependencies(test_uri sylar)
force_redefine_file_macro_for_sources(test_uri) #__FILE__
target_link_libraries(test_uri ${LIBS})

add_executable(echo_server examples/echo_server.cpp)
add_dependencies(echo_server sylar)
force_redefine_file_macro_for_sources(echo_server) #__FILE__
target_link_libraries(echo_server ${LIBS})

add_executable(test_daemon tests/test_daemon.cpp)
add_dependencies(test_daemon sylar)
force_redefine_file_macro_for_sources(test_daemon) #__FILE__
target_link_libraries(test_daemon ${LIBS})

add_executable(test_env tests/test_env.cpp)
add_dependencies(test_env sylar)
force_redefine_file_macro_for_sources(test_env) #__FILE__
target_link_libraries(test_env ${LIBS})

add_executable(test_application tests/test_application.cpp)
add_dependencies(test_application sylar)
force_redefine_file_macro_for_sources(test_application) #__FILE__
target_link_libraries(test_application ${LIBS})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
