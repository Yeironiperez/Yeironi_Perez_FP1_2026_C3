#include <stdio.h>
#include <stdlib.h>
/* Suma y promedio. */

int main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\nDesea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();

    while (c == 'S')
    {
        // Limpiar el Enter
        while (getchar() != '\n');

        printf("\nIngrese la cadena de caracteres: ");
        fgets(cad, 10, stdin);
        i++;
        sum += atof(cad);

        printf("\nDesea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
    }

    printf("\nSuma: %.2f", sum);
    if (i > 0)
        printf("\nPromedio: %.2f", sum / i);
    else
        printf("\nPromedio: 0.00");

    return 0;
}
