#include <stdio.h>

int main () {
    int x = 10;
    int *p;

    p = &x; // p recebe o endereço de x

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", &x);
    printf("valor armazenado em p; %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    return 0;
}