OS_NAME := $(shell uname -s)

ifeq ($(OS_NAME), Darwin)
install::
	cmake -DCMAKE_BUILD_TYPE=Debug \
		  -DCMAKE_MAKE_PROGRAM=ninja \
		  -DCMAKE_C_COMPILER=gcc-13 \
		  -DCMAKE_CXX_COMPILER=g++-13 \
		  -G Ninja \
		  -S ./ \
		  -B ./build
else
install::
	cmake -DCMAKE_BUILD_TYPE=Debug \
				  -DCMAKE_MAKE_PROGRAM=ninja \
				  -DCMAKE_C_COMPILER=gcc \
				  -DCMAKE_CXX_COMPILER=g++ \
				  -G Ninja \
				  -S ./ \
				  -B ./build
endif

.PHONY: clean
clean:
	rm -rf ./build