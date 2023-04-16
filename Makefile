##
# Filename: /workspaces/our_rpg/Makefile
# Path: /workspaces/our_rpg
# Created Date: Saturday, January 21st 2023, 2:18:05 pm
# Author: osvegn
# 
# Copyright (c) 2023 our_rpg
##

RM		=	rm -rf

BUILD	=	build

BUILD_DEBUG		=	build_debug

BUILD_TESTS		=	build_tests

CC		=	cmake

TESTS	=	component_tests resource_tests system_tests
# vector_tests ecs_tests

all:
	${CC} -B ${BUILD} -DCMAKE_BUILD_TYPE=Release -DTESTING=OFF
	${CC} --build ${BUILD}

clean:
	${RM} ${BUILD}
	${RM} ${TESTS}

re: clean all

debug:
	${CC} -B ${BUILD_DEBUG} -DCMAKE_BUILD_TYPE=Debug -DTESTING=OFF
	${CC} --build ${BUILD_DEBUG}

run_tests:
	${CC} -B ${BUILD_TESTS} -DTESTING=ON
	${CC} --build ${BUILD_TESTS}
	${foreach test, ${TESTS}, ./${test};}

valgrind: debug
	valgrind --leak-check=full ./build/our_rpg 2> log_valgrind.txt