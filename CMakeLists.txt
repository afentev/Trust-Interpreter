cmake_minimum_required(VERSION 3.23)
project(ParserExample)

if (CMAKE_HOST_SYSTEM_NAME MATCHES "Darwin")
    execute_process(
            COMMAND brew --prefix bison
            RESULT_VARIABLE BREW_BISON
            OUTPUT_VARIABLE BREW_BISON_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_BISON EQUAL 0 AND EXISTS "${BREW_BISON_PREFIX}")
        message(STATUS "Found Bison keg installed by Homebrew at ${BREW_BISON_PREFIX}")
        set(BISON_EXECUTABLE "${BREW_BISON_PREFIX}/bin/bison")
    endif ()

    execute_process(
            COMMAND brew --prefix flex
            RESULT_VARIABLE BREW_FLEX
            OUTPUT_VARIABLE BREW_FLEX_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    if (BREW_FLEX EQUAL 0 AND EXISTS "${BREW_FLEX_PREFIX}")
        message(STATUS "Found Flex keg installed by Homebrew at ${BREW_FLEX_PREFIX}")
        set(FLEX_EXECUTABLE "${BREW_FLEX_PREFIX}/bin/flex")
    endif ()

    include_directories(/usr/local/opt/flex/include/)
endif ()

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

set(
        HEADERS
        ${ParserExample_SOURCE_DIR}/driver.hh
        ${ParserExample_SOURCE_DIR}/parser.hh
)

BISON_TARGET(
        MyParser
        parser.y
        ${ParserExample_SOURCE_DIR}/parser.cpp
        COMPILE_FLAGS --graph
        DEFINES_FILE ${ParserExample_SOURCE_DIR}/parser.hh
)

FLEX_TARGET(
        MyScanner
        scanner.l
        ${ParserExample_SOURCE_DIR}/scanner.cpp
)

ADD_FLEX_BISON_DEPENDENCY(MyScanner MyParser)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -fpermissive -g -std=c++20 -fmax-errors=10 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++0x-compat -Wc++11-compat -Wc++14-compat -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlarger-than=8192 -Wlogical-op -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstack-usage=8192 -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -fcheck-new -fsized-deallocation -fstack-check -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -fPIE -fsanitize=address -fsanitize=alignment -fsanitize=bool -fsanitize=bounds -fsanitize=enum -fsanitize=float-cast-overflow -fsanitize=float-divide-by-zero -fsanitize=integer-divide-by-zero -fsanitize=leak -fsanitize=nonnull-attribute -fsanitize=null -fsanitize=object-size -fsanitize=return -fsanitize=returns-nonnull-attribute -fsanitize=shift -fsanitize=signed-integer-overflow -fsanitize=undefined -fsanitize=unreachable -fsanitize=vla-bound -fsanitize=vptr -lm -pie")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -std=c++20")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

add_executable(
        02-ParserExample
        help/Expressions/OrExpression.cpp
        help/Expressions/AndExpression.cpp help/Expressions/EqualExpression.cpp
        help/Expressions/NotEqualExpression.cpp help/Expressions/GreaterEqExpression.cpp
        help/Expressions/GreaterExpression.cpp help/Expressions/LessEqExpression.cpp
        help/Expressions/LessExpression.cpp help/Expressions/NotExpression.cpp

        help/Expressions/DivExpression.cpp help/Expressions/ModExpression.cpp
        help/Expressions/MulExpression.cpp help/Expressions/UnaryMinusExpression.cpp
        help/Expressions/PlusExpression.cpp help/Expressions/MinusExpression.cpp
        help/Expressions/IDExpression.cpp help/Statements/ExpressionList.cpp
        help/Statements/PrintStatement.cpp help/Statements/Interruptions/BreakStatement.cpp
        help/Statements/Interruptions/ContinueStatement.cpp help/Statements/Interruptions/Interruptions.cpp

        help/Statements/WhileStatement.cpp help/Statements/IfStatement.cpp help/Statements/IfElseStatement.cpp
        help/Statements/AssignmentStatement.cpp

        help/Statements/VariableDeclInit.cpp
        help/Visitor.cpp help/Statements/Statements.cpp help/Program.cpp help/Statements/VariableDeclaration.cpp
        help/Types/Boolean.cpp help/Types/Integer.cpp help/Types/String.cpp

        help/Identifiers/IDTable.cpp help/Identifiers/Identifier.cpp
        main.cpp
        driver.cpp
        ${BISON_MyParser_OUTPUTS}
        ${FLEX_MyScanner_OUTPUTS} help/Statements/TypelessVariableDecl.cpp help/Statements/Interruptions/ReturnStatement.cpp help/Statements/Interruptions/ReturnStatement.h help/InterpretationExceptions/InterpretationExceptions.cpp help/InterpretationExceptions/InterpretationExceptions.h)

target_include_directories(02-ParserExample PRIVATE ${ParserExample_SOURCE_DIR})
