all:
	gcc -ffreestanding -mno-red-zone -mno-sse -fno-PIC -fno-builtin -mcmodel=kernel -c src/kernel.c src/console.c src/unifont.c
	ld -m elf_x86_64 -nostdlib  -T linker.ld kernel.o console.o unifont.o -o kernel.elf
