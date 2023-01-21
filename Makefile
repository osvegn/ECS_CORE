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

CC		=	cmake

TESTS	=	vector_tests ecs_tests system_tests

all:
	${CC} -B ${BUILD} -DCMAKE_BUILD_TYPE=Release -DTESTING=OFF
	${CC} --build ${BUILD}

clean:
	${RM} ${BUILD}
	${RM} ${TESTS}

re: clean all

debug:
	${CC} -B ${BUILD} -DCMAKE_BUILD_TYPE=Debug -DTESTING=OFF
	${CC} --build ${BUILD}

run_tests:
	${CC} -B ${BUILD} -DTESTING=ON
	${CC} --build ${BUILD}
	${foreach test, ${TESTS}, ./${test};}
