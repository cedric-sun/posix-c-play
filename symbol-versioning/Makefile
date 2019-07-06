default:lib
	gcc -o main.elf main.c ./lib.so

lib:
	gcc -shared -fPIC lib.c -Xlinker --version-script lib.ver -o lib.so
