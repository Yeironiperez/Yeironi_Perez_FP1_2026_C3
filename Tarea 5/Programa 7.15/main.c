#include <stdio.h>
#include <ctype.h>
/* Decodifica. */

void interpreta(char *); // Prototipo de funcion

int main(void)
{
    char cad[50];
    printf("\nIngrese la cadena de caracteres: ");
    fgets(cad, 50, stdin);
    interpreta(cad);
    return 0;
}

void interpreta(char *cadena)
{
    int i = 0, j, k;
    while (cadena[i] != '\0')
    {
        if (isalpha(cadena[i])) // Si es letra
        {
            k = cadena[i - 1] - 48; // Convierte el caracter numero a numero
            for (j = 0; j < k; j++)
                putchar(cadena[i]);
        }
        i++;
    }
}
