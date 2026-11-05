#include <stdio.h>
#include <string.h>
/* Cuenta cadenas. */

int main(void)
{
    char cad1[50], cad2[50], cad0[50];
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    fgets(cad1, 50, stdin);
    cad1[strcspn(cad1, "\n")] = '\0'; // Quitar Enter

    printf("\nIngrese la cadena a buscar: ");
    fgets(cad2, 50, stdin);
    cad2[strcspn(cad2, "\n")] = '\0'; // Quitar Enter

    strcpy(cad0, cad1); // Se copia la cadena original a cad0

    char *pos = strstr(cad0, cad2);
    // En pos se asigna el apuntador a la primera ocurrencia

    while (pos != NULL)
    {
        i++;
        pos = strstr(pos + 1, cad2); // Se mueve una posicion para seguir buscando
    }

    printf("\nEl numero de veces que aparece la segunda cadena es: %d", i);

    return 0;
}
