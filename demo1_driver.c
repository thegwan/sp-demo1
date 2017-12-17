/*--------------------------------------------------------------------*/
/* demo1_driver.c                                                       */
/* Author: Gerry Wan                                                  */
/*--------------------------------------------------------------------*/

#include "keychain.h"
#include "sha256.h"
#include "tsm.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    unsigned long umk;
    int status;
    int c;
    unsigned int curr;
    unsigned int stop;
    FILE *fptr;

    load umk with the value stored in CSR 0x050
    __asm__ __volatile__(
        "csrr %0, 0x050;\n"
        : "=r" (umk));
    
    // umk = 0xefcdab8967452301;

    // initialize a keychain
    KeyChain_T oKeyChain;

    oKeyChain = KeyChain_new(umk);

    // add some keys
    status = AddKeyToChain(oKeyChain, "0", "00");
    if (status) printf("added key!\n");

    // sleep(1)
    curr = time(0);
    stop = curr + 1;
    while (1) {
      curr = time(0);
      if (curr >= stop)
	break;
    }
    
    status = AddKeyToChain(oKeyChain, "0", "01");
    if (status) printf("added key!\n");

    // sleep(1)
    curr = time(0);
    stop = curr + 1;
    while (1) {
      curr = time(0);
      if (curr >= stop)
	break;
    }
    
    status = AddKeyToChain(oKeyChain, "00", "000");
    if (status) printf("added key!\n");

    // encrypt a file demo

    // print original
    printf("\n---Original text:\n\n");
    fptr = fopen("file.txt", "r");
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }
    fclose(fptr);

    // encrypt
    status = Encrypt("file.txt", "file.enc", oKeyChain, "00");
    if (status) printf("\n---encrypted file.txt into file.enc\n");
    else printf("\n---encryption failed\n");

    // print encrypted
    printf("\n---Encrypted text:\n\n");
    fptr = fopen("file.enc", "r");
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }
    fclose(fptr);

    // decrypt with wrong key
    status = Decrypt("file.enc", "file.dec", oKeyChain, "01");
    if (status) printf("\n---decrypted file.enc into file.dec\n");
    else printf("\n---decryption failed\n");

    // print wrong decrypted
    printf("\n---Decrypted text with wrong key:\n\n");
    fptr = fopen("file.dec", "r");
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }
    fclose(fptr);

    // decrypt with correct key
    status = Decrypt("file.enc", "file.dec", oKeyChain, "00");
    if (status) printf("\n---decrypted file.enc into file.dec\n");
    else printf("\n---decryption failed\n");

    // print decrypted
    printf("\n---Decrypted text with correct key:\n\n");
    fptr = fopen("file.dec", "r");
    while ((c = fgetc(fptr)) != EOF) {
        printf("%c", c);
    }
    fclose(fptr);

    printf("-----done----\n");
}
