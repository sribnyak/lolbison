cmake_minimum_required(VERSION 3.18)
project(Lolbison)

find_package(BISON)
find_package(FLEX)

set(HEADERS
    ${Lolbison_SOURCE_DIR}/driver.hh
    ${Lolbison_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
    MyParser
    parser.y
    ${Lolbison_SOURCE_DIR}/parser.cpp
    COMPILE_FLAGS --graph
    DEFINES_FILE ${Lolbison_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
    MyScanner
    scanner.l
    ${Lolbison_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

add_executable(
    lolbison
    main.cpp
    driver.cpp
    ${BISON_MyParser_OUTPUTS}
    ${FLEX_MyScanner_OUTPUTS}
    expressions/ArrayAccess.cpp
    expressions/BooleanLiteral.cpp
    expressions/Identifier.cpp
    expressions/It.cpp
    expressions/LogicalNot.cpp
    expressions/NumberLiteral.cpp
    expressions/StringLiteral.cpp
    statements/ArrayAssign.cpp
    statements/ArrayDecl.cpp
    statements/ArrayNewIndex.cpp
    statements/Break.cpp
    statements/ExprStatement.cpp
    statements/VarAssign.cpp
    statements/VarDecl.cpp
    Program.cpp
)
target_include_directories(lolbison PRIVATE ${Lolbison_SOURCE_DIR})
