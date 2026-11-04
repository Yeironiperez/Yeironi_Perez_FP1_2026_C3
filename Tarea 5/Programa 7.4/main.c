#include <stdio.h>

int main(void)
{
    char *cad0;
    cad0 = "Argentina";
    puts(cad0);
    cad0 = "Brasil";
    puts(cad0);

    char *cad1 = "";
    printf("\nEscribe algo para cad1: ");
    fgets(cad1, 20, stdin);
    puts(cad1);

    char cad2[20] = "Mexico";
    puts(cad2);
    printf("\nEscribe algo para cad2: ");
    fgets(cad2, 20, stdin);
    puts(cad2);

    // Esto es INCORRECTO, por eso va comentado:
    // char cad1[];
    // cad2[10] = "Guatemala";

    return 0;
}
