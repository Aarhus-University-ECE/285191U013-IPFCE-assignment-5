

all: build

configure:
	cmake -S . -B build

build: configure
	cmake --build build

test: build
	./build/unit-tests

clean:
	rm -rf build
