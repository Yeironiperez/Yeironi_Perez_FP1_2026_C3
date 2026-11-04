#include <stdio.h>
#include <string.h>
/* Funciones de la biblioteca string.h */

int main(void)
{
    char cad0[50] = "Hola Mexico";
    char cad1[20], cad2[20], cad3[20] = ", buenos dias!!!";

    strcpy(cad1, cad0);
    printf("\nPrueba de strcpy. Se copia cad0 a cad1: %s\n", cad1);

    strcpy(cad1, cad3);
    printf("\nPrueba de strcpy. Se copia cad3 a cad1: %s\n", cad1);

    strcpy(cad1, "XX");
    printf("\nPrueba de strcpy. Se copia XX a cad1: %s\n", cad1);

    strncpy(cad2, cad0, 4);
    cad2[4] = '\0';
    printf("\nPrueba de strncpy. Se copian 4 caracteres de cad0 a cad2: %s\n", cad2);

    strncpy(cad2, cad3, 3);
    cad2[3] = '\0';
    printf("\nPrueba de strncpy. Se copian 3 caracteres de cad3 a cad2: %s\n", cad2);

    strcat(cad0, cad3);
    printf("\nPrueba de strcat. Se incorpora cad3 a cad0: %s\n", cad0);

    strcat(cad1, " YY");
    printf("\nPrueba de strcat. Se incorpora YY a cad1: %s\n", cad1);

    strcat(cad2, " ");
    strncat(cad2, cad0, 4);
    printf("\nPrueba de strncat. Se incorporan 4 caracteres de cad0 a cad2: %s\n", cad2);

    cad0[0] = 'H'; // Para volver a tener "Hola Mexico..."
    // En realidad cad0 ya cambio, por eso usamos una copia para buscar
    char *resultado;
    resultado = strstr(cad0, "Mexico");
    printf("\nPrueba de strstr. Se trata de localizar Mexico dentro de cad0: %s\n", resultado);

    resultado = strstr(cad0, "Guatemala");
    printf("\nPrueba de strstr. Se trata de localizar Guatemala dentro de cad0: %s\n", resultado);

    return 0;
}
