set(rle-src
    Board.cc
    Parser.cc
    Utils.cc
)

include_directories("${rle-parser_SOURCE_DIR}/include")

add_library(rle ${rle-src})
