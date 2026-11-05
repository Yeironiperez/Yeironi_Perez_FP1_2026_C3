#include <stdio.h>
#include <string.h>
/* Cadena invertida resuelta en forma recursiva. */

void inverso(char *); // Prototipo de funcion

int main(void)
{
    char fra[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, 50, stdin);
    fra[strcspn(fra, "\n")] = '\0'; // Quitar Enter

    printf("\nEscribe la linea de texto en forma inversa: ");
    inverso(fra);

    return 0;
}

void inverso(char *cadena)
{
    if (cadena[0] != '\0')
    {
        inverso(&cadena[1]);
        putchar(cadena[0]);
    }
}
