srcs = $(shell find -name "*.c")
headers = $(shell find include/  -name "*.h")

out = main

all: build/$(out)

build/$(out): $(srcs) $(headers)
	@mkdir -p build
	gcc -Wall -Wextra -o build/$(out) $(srcs) -I include -L lib -lraylib -lgdi32 -lwinmm