cc = clang
cflags = -std=c99 -Wall -Wextra -pedantic

build_dir = ./target/
enter_build_dir = mkdir -p build_dir ; cd $(build_dir)

info = @printf "\n[INFO] "


all: circle

run: circle
	$(info)
	$(enter_build_dir) && \
		./circle

clean:
	$(info)
	$(enter_build_dir) && \
		rm ./*

circle: main.o circle.o
	$(info)
	$(enter_build_dir) && \
		$(cc) $^ $(cflags) -o $@

main.o: main.c
	$(info)
	$(cc) $^ $(cflags) -c -o $(build_dir)$@

circle.o: circle.c
	@$(info)
	$(cc) $^ $(cflags) -c -o $(build_dir)$@

circle.c: circle.h

