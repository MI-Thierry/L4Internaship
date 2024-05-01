
build/csa_os.img: build/main.bin
	cp build/main.bin build/csa_os.img
	truncate -s 1440k build/csa_os.img

build/main.bin: src/main.asm
	nasm src/main.asm -f bin -o build/main.bin
