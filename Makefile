# Makefile
# Author: Gerry Wan

# Dependency rules for non-file targets
all: demo1_driver store_umk

clean:
	rm -f *.o
	rm demo1_driver
	rm store_umk

# Dependency rules for file targets
demo1_driver: demo1_driver.o tsm.o keychain.o keycrypto.o sha256.o
	riscv64-unknown-elf-gcc demo1_driver.o tsm.o keychain.o keycrypto.o sha256.o -o demo1_driver
store_umk: store_umk.o
	riscv64-unknown-elf-gcc store_umk.o -o store_umk
demo1_driver.o: demo1_driver.c keychain.h keycrypto.h sha256.h
	riscv64-unknown-elf-gcc -c demo1_driver.c
store_umk.o: store_umk.c
	riscv64-unknown-elf-gcc -c store_umk.c
tsm.o: tsm.c keychain.h keycrypto.h sha256.h
	riscv64-unknown-elf-gcc -c tsm.c
keychain.o: keychain.c keychain.h keycrypto.h sha256.h
	riscv64-unknown-elf-gcc -c keychain.c
keycrypto.o: keycrypto.c keycrypto.h
	riscv64-unknown-elf-gcc -c keycrypto.c
sha256.o: sha256.c sha256.h
	riscv64-unknown-elf-gcc -c sha256.c

