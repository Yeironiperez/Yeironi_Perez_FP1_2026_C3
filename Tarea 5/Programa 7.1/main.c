#include <stdio.h>

int main(void)
{
    char p1, p2, p3 = '$';

    printf("\nIngrese un caracter: ");
    p1 = getchar();   // Lee 1 caracter
    putchar(p1);      // Escribe 1 caracter
    printf("\n");

    printf("\nEl caracter p3 es: ");
    putchar(p3);      // Muestra $
    printf("\n");

    printf("\nIngrese otro caracter: ");
    scanf("%c", &p2); // Otra forma de leer 1 caracter
    printf("%c", p2);  // Otra forma de escribirlo

    return 0;
}
