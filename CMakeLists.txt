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
    expressions/binary_ops/BinaryAnd.cpp
    expressions/binary_ops/BinaryDiv.cpp
    expressions/binary_ops/BinaryEq.cpp
    expressions/binary_ops/BinaryMax.cpp
    expressions/binary_ops/BinaryMin.cpp
    expressions/binary_ops/BinaryMod.cpp
    expressions/binary_ops/BinaryMul.cpp
    expressions/binary_ops/BinaryNeq.cpp
    expressions/binary_ops/BinaryOp.cpp
    expressions/binary_ops/BinaryOr.cpp
    expressions/binary_ops/BinarySub.cpp
    expressions/binary_ops/BinarySum.cpp
    expressions/binary_ops/BinaryXor.cpp
    expressions/ArrayAccess.cpp
    expressions/BooleanLiteral.cpp
    expressions/Identifier.cpp
    expressions/It.cpp
    expressions/Join.cpp
    expressions/LogicalNot.cpp
    expressions/NumberLiteral.cpp
    expressions/StringLiteral.cpp
    statements/loop_components/DecrementLoopHead.cpp
    statements/loop_components/IncrementLoopHead.cpp
    statements/loop_components/LoopCondition.cpp
    statements/loop_components/LoopHead.cpp
    statements/loop_components/LoopUntil.cpp
    statements/loop_components/LoopWhile.cpp
    statements/ArrayAssign.cpp
    statements/ArrayDecl.cpp
    statements/ArrayNewIndex.cpp
    statements/Break.cpp
    statements/ExprStatement.cpp
    statements/IfThen.cpp
    statements/Loop.cpp
    statements/Print.cpp
    statements/VarAssign.cpp
    statements/VarDecl.cpp
    Program.cpp
)
target_include_directories(lolbison PRIVATE ${Lolbison_SOURCE_DIR})
