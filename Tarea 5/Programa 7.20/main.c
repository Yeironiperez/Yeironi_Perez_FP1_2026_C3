#include <stdio.h>
#include <string.h>
/* Encuentra la cadena con mayor longitud. */

int longitud(char *cad); // Prototipo de funcion

int main(void)
{
    int i, n, l = -1, p = 0, t;
    char cad[50], FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);
    getchar(); // Limpia el Enter que deja el scanf

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto. Maximo 50 caracteres: ", i + 1);
        fgets(FRA[i], 50, stdin);
        FRA[i][strcspn(FRA[i], "\n")] = '\0'; // Quitar Enter
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        strcpy(cad, FRA[i]);
        t = longitud(cad);
        if (t > l)
        {
            l = t;
            p = i;
        }
    }

    printf("\nLa cadena con mayor longitud es: ");
    puts(FRA[p]);
    printf("\nLongitud: %d", l);

    return 0;
}

int longitud(char *cadena)
{
    int cue = 0;
    while (cadena[cue] != '\0')
        cue++;
    return (cue);
}
