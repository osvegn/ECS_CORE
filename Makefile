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

all:
	${CC} -B ${BUILD} -DCMAKE_BUILD_TYPE=Release
	${CC} --build ${BUILD}

clean:
	${RM} ${BUILD}

re: clean all

debug:
	${CC} -B ${BUILD} -DCMAKE_BUILD_TYPE=Debug
	${CC} --build ${BUILD}

run_tests: clean
	${CC} -B ${BUILD} -DTESTING=ON
	${CC} --build ${BUILD}
