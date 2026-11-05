#include <stdio.h>
#include <string.h>
/* Cadena invertida. */

char *inverso(char *); // Prototipo de funcion

int main(void)
{
    char fra[50], aux[50];

    printf("\nIngrese la linea de texto: ");
    fgets(fra, 50, stdin);
    fra[strcspn(fra, "\n")] = '\0'; // Quitar el Enter para que no salga al reves

    strcpy(aux, inverso(fra));
    printf("\nEscribe la linea de texto en forma inversa: ");
    puts(aux);

    return 0;
}

char *inverso(char *cadena)
{
    int i = 0, j, lon;
    char cad;

    lon = strlen(cadena);
    j = lon - 1;

    while (i < ((lon - 1) / 2))
    {
        cad = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = cad;
        i++;
        j--;
    }
    return (cadena);
}
