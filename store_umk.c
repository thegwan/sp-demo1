#include <stdio.h>
int main() {
    unsigned long umk;
    unsigned long confirm;

    umk = 0xefcdab8967452301;
    confirm = 0;

    __asm__ __volatile__(
        "csrw 0x050, %1;\n"
        "\tcsrr %0, 0x050;\n"
        : "=r" (confirm)
        : "r" (umk));

    printf("confirm umk stored: %lu\n", confirm);
    return 0;
}
