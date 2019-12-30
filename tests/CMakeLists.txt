set(test-src
    Main.cc
    TestParsing.cc
)

add_executable(rleTest ${test-src})

include_directories("${rle-parser_SOURCE_DIR}/include")

target_link_libraries(rleTest rle)

add_test(
    NAME parsingtest
    COMMAND build/tests/rleTest
    WORKING_DIRECTORY ${rle-parser_SOURCE_DIR}
)

configure_file(
    ${PROJECT_SOURCE_DIR}/tests/Config.h.in
    ${PROJECT_SOURCE_DIR}/tests/Config.h
)
