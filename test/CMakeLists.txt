project(Unit_test)
cmake_minimum_required(VERSION 3.5)

add_subdirectory(lib/googletest-1.13.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(sketches_dir ${CMAKE_CURRENT_SOURCE_DIR}/../sketches/main_sketch/src)
set(mock_dir ${CMAKE_CURRENT_SOURCE_DIR}/mock)

add_executable(unit_test_run unit/load_test.cpp unit/http_test.cpp ${sketches_dir}/service/impl/DefaultWeatherService.cpp)
target_include_directories(unit_test_run PUBLIC ${sketches_dir} ${mock_dir} lib/ArduinoJson-v6.21.2)
target_link_libraries(unit_test_run gtest gtest_main gmock gmock_main)