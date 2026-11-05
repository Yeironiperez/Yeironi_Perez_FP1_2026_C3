#include <stdio.h>
/* Calcula longitud en forma recursiva sin strlen. */

int cuenta(char *); // Prototipo de funcion

int main(void)
{
    int i;
    char cad[50];

    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, 50, stdin);

    i = cuenta(cad);
    printf("\nLongitud de la cadena: %d", i);

    return 0;
}

int cuenta(char *cadena)
{
    if (cadena[0] == '\0')
        return 0;
    else
        return (1 + cuenta(&cadena[1]));
}
