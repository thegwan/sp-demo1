# Makefile
# Author: Gerry Wan

# Dependency rules for non-file targets

CC=riscv64-unknown-linux-gnu-gcc
FLAGS=-static

all: demo1_driver store_umk test test-exclama

clean:
	rm -f *.o
	rm demo1_driver
	rm store_umk
	rm test
	rm test-exclama

# Dependency rules for file targets
demo1_driver: demo1_driver.o tsm.o keychain.o keycrypto.o sha256.o
	$(CC) $(FLAGS) demo1_driver.o tsm.o keychain.o keycrypto.o sha256.o -o demo1_driver
store_umk: store_umk.o
	$(CC) $(FLAGS) store_umk.o -o store_umk
demo1_driver.o: demo1_driver.c keychain.h keycrypto.h sha256.h
	$(CC) $(FLAGS) -c demo1_driver.c
store_umk.o: store_umk.c
	$(CC) $(FLAGS) -c store_umk.c
tsm.o: tsm.c keychain.h keycrypto.h sha256.h
	$(CC) $(FLAGS) -c tsm.c
keychain.o: keychain.c keychain.h keycrypto.h sha256.h
	$(CC) $(FLAGS) -c keychain.c
keycrypto.o: keycrypto.c keycrypto.h
	$(CC) $(FLAGS) -c keycrypto.c
sha256.o: sha256.c sha256.h
	$(CC) $(FLAGS) -c sha256.c
test: test.c
	$(CC) $(FLAGS) -o test test.c
test-exclama: test-exclama.c
	$(CC) $(FLAGS) -o test-exclama test-exclama.c
