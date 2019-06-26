cmake_minimum_required(VERSION 3.8)
project(life)

include_directories(lib/googletest-release-1.6.0/include lib/googletest-release-1.6.0)

set(CMAKE_CXX_STANDARD 17)
add_definitions (-Wall)

add_subdirectory(lib/googletest-release-1.6.0)

set(SOURCE_FILES main.cpp Parser/Parser.cpp Parser/Parser.h Driver.cpp Driver.h Parser/Option.cpp Parser/Option.h Parser/Descriptor.cpp Parser/Descriptor.h stuff.h Parser/ParseError.cpp Parser/ParseError.h Parser/ParseAll.cpp Parser/ParseAll.h Loader/Loader.cpp Loader/Loader.h Game/Condition.cpp Game/Condition.h Game/CommandParser.cpp Game/CommandParser.h Loader/Opener.cpp Loader/Opener.h Game/Stepper.cpp Game/Stepper.h Export/Exporter.cpp Export/Exporter.h Loader/FileCondit.cpp Loader/FileCondit.h Game/InterMode.cpp Game/InterMode.h Game/Setter.cpp Game/Setter.h Export/ConsExport.cpp Export/ConsExport.h)
set(UNIT_TESTS Parser/ParserTests.cpp Parser/Parser.cpp Parser/Parser.h Parser/Option.cpp Parser/Option.h Parser/Descriptor.cpp Parser/Descriptor.h stuff.h Parser/ParseError.cpp Parser/ParseError.h Parser/ParseAll.cpp Parser/ParseAll.h Loader/Loader.cpp Loader/Loader.h Game/Condition.cpp Game/Condition.h Loader/Opener.cpp Loader/Opener.h)

add_executable(life ${SOURCE_FILES})
add_executable(tests ${UNIT_TESTS})

target_link_libraries(tests gtest gtest_main)