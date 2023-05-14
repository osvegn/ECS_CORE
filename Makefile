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

all:
	${CC} -B ${BUILD} -DCMAKE_BUILD_TYPE=Release -DTESTING=OFF
	${CC} --build ${BUILD}
	cp -r config ${BUILD}

clean:
	${RM} ${BUILD}
	${RM} ${BUILD_DEBUG}
	${RM} ${BUILD_TESTS}
	${RM} ${TESTS}

re: clean all

debug:
	${CC} -B ${BUILD_DEBUG} -DCMAKE_BUILD_TYPE=Debug -DTESTING=OFF
	${CC} --build ${BUILD_DEBUG}
	cp -r config ${BUILD_DEBUG}

run_tests:
	${CC} -B ${BUILD_TESTS} -DTESTING=ON
	${CC} --build ${BUILD_TESTS}
	cp -r config ${BUILD_TESTS}
	${foreach test, ${TESTS}, ./${test};}

valgrind: debug
	valgrind --leak-check=full ./build/our_rpg 2> log_valgrind.txt