cmake_minimum_required(VERSION 2.6)

project (Parser)

FIND_PACKAGE(GenerateCLP REQUIRED)
IF(GenerateCLP_FOUND)
  INCLUDE(${GenerateCLP_USE_FILE})
ELSE(GenerateCLP_FOUND)
  MESSAGE(FATAL_ERROR
          "GenerateCLP not found. Please set GenerateCLP_DIR.")
ENDIF(GenerateCLP_FOUND)

set(parser_clp
 main.cpp
)
generateclp(parser_clp parser_clp.xml)

add_executable(Parser ${parser_clp})

