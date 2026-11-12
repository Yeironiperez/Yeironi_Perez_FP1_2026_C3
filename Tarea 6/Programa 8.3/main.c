#include <stdio.h>
#include <string.h>

/* Estructuras-3.
El programa muestra la manera en que se declara una estructura anidada, asi
como la forma de acceso a los campos de las variables o apuntadores de tipo
estructura, tanto para lectura como para escritura. Se utiliza ademas una
funcion que recibe como parametro un apuntador de tipo estructura. */

typedef struct        /* Declaracion de la estructura domicilio utilizando
un typedef. */
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado    /* Declaracion de la estructura anidada empleado. */
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;        /* direccion es un campo de tipo estructura
    domicilio de la estructura empleado. */
};

void Lectura(struct empleado *a)
/* Funcion que permite leer los campos de un apuntador de tipo estructura
empleado. */
{
    printf("\nIngrese el nombre del empleado: ");
    fgets(a->nombre, 20, stdin);
    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, 20, stdin);
    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    getchar();
    printf("---Ingrese la direccion del empleado---");
    printf("\n\tCalle: ");
    fgets(a->direccion.calle, 20, stdin);
    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    getchar();
    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, 20, stdin);
}

int main(void)
{
    struct empleado e0 = {"Juan", "Ventas", 15000, {"Reforma", 123, 64000, "Monterrey"}};
    struct empleado e1;

    Lectura(&e1);

    printf("\nDatos del empleado 0\n");
    printf("%s\t%s\t%.2f\t%s %d %d %s", e0.nombre, e0.departamento, e0.sueldo,
           e0.direccion.calle, e0.direccion.numero, e0.direccion.cp, e0.direccion.localidad);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s %d %d %s", e1.nombre, e1.departamento, e1.sueldo,
           e1.direccion.calle, e1.direccion.numero, e1.direccion.cp, e1.direccion.localidad);

    return 0;
}
