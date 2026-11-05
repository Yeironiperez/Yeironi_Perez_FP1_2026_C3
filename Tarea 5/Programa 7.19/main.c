#include <stdio.h>
#include <string.h>
/* Cuenta palabras. */

int cuentap(char *); // Prototipo de funcion

int main(void)
{
    int i;
    char fra[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, 50, stdin);
    fra[strcspn(fra, "\n")] = '\0'; // Quitar Enter

    strcat(fra, " "); // Se agrega un espacio al final de la cadena
    i = cuentap(fra);
    printf("\nLa linea de texto tiene %d palabras", i);

    return 0;
}

int cuentap(char *cad)
{
    char *cad0;
    int i = 0;

    cad0 = strstr(cad, " "); // Se localiza el primer espacio en blanco
    while (cad0 != NULL)
    {
        i++;
        cad0 = strstr(cad0 + 1, " "); // Se busca un espacio a partir de la siguiente posicion
    }
    return (i);
}
