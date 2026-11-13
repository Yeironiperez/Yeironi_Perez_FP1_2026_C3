#include <stdio.h>
#include <string.h>

/* Vendedores.
El programa maneja informacion sobre las ventas que realizan los vendedores de
articulos domesticos de una importante empresa de la Ciudad de Mexico. */

typedef struct
/* Declaracion de la estructura banco. */
{
    char noba[20];        /* Nombre del banco. */
    char nucu[20];        /* Numero de cuenta. */
} banco;

typedef union /* Declaracion de la union fpago. */
{
    banco che;            /* Cheque. Campo de tipo estructura banco. */
    banco nomi;           /* Nomina. Campo de tipo estructura banco. */
    char venta;           /* Ventanilla. */
} fpago;

typedef struct /* Declaracion de la estructura domicilio. */
{
    char cnu[20];         /* Calle y numero. */
    char col[20];         /* Colonia. */
    char cp[10];          /* Codigo Postal. */
    char ciu[20];         /* Ciudad. */
} domicilio;

typedef struct /* Declaracion de la estructura vendedor. */
{
    int num;              /* Numero de vendedor. */
    char nom[20];         /* Nombre del vendedor. */
    float ven[12];        /* Ventas del ano. Arreglo unidimensional de tipo real. */
    domicilio domi;       /* domi es de tipo estructura domicilio. */
    float sal;            /* Salario mensual. */
    fpago pago;           /* pago es de tipo union fpago. */
    int cla;              /* Clave forma de pago. */
} vendedor;

void Lectura(vendedor *, int);
void F1(vendedor *, int);
void F2(vendedor *, int); /* Prototipos de funciones. */
void F3(vendedor *, int);
void F4(vendedor *, int);

int main(void)
{
    vendedor VENDEDORES[100];
    /* Declaracion del arreglo unidimensional de tipo estructura vendedor. */
    int TAM;
    do
    {
        printf("Ingrese el numero de vendedores: ");
        scanf("%d", &TAM);
    }
    while (TAM > 100 || TAM < 1);
    /* Se verifica que el numero de elementos del arreglo sea correcto. */
    Lectura(VENDEDORES, TAM);
    F1(VENDEDORES, TAM);
    F2(VENDEDORES, TAM);
    F3(VENDEDORES, TAM);
    F4(VENDEDORES, TAM);
    printf("\n\tFIN DEL PROGRAMA");
    return 0;
}

void Lectura(vendedor A[], int T)
/* Esta funcion se utiliza para leer un arreglo unidimensional de tipo
estructura vendedor de T elementos. */
{
    int I, J;
    for (I = 0; I < T; I++)
    {
        printf("\n\tIngrese datos del vendedor %d", I + 1);
        printf("\nNumero de vendedor: ");
        scanf("%d", &A[I].num);
        printf("Nombre del vendedor: ");
        getchar();
        fgets(A[I].nom, 20, stdin);
        printf("Ventas del ano: \n");
        for (J = 0; J < 12; J++)
        {
            printf("\tMes %d: ", J + 1);
            scanf("%f", &A[I].ven[J]);
        }
        printf("Domicilio del vendedor: \n");
        printf("\tCalle y numero: ");
        getchar();
        fgets(A[I].domi.cnu, 20, stdin);
        printf("\tColonia: ");
        fgets(A[I].domi.col, 20, stdin);
        printf("\tCodigo Postal: ");
        fgets(A[I].domi.cp, 10, stdin);
        printf("\tCiudad: ");
        fgets(A[I].domi.ciu, 20, stdin);
        printf("Salario del vendedor: ");
        scanf("%f", &A[I].sal);
        printf("Forma de Pago (Banco-1 Nomina-2 Ventanilla-3): ");
        scanf("%d", &A[I].cla);
        switch (A[I].cla)
        {
            case 1:
                printf("\tNombre del banco: ");
                getchar();
                fgets(A[I].pago.che.noba, 20, stdin);
                printf("\tNumero de cuenta: ");
                fgets(A[I].pago.che.nucu, 20, stdin);
                break;
            case 2:
                printf("\tNombre del banco: ");
                getchar();
                fgets(A[I].pago.nomi.noba, 20, stdin);
                printf("\tNumero de cuenta: ");
                fgets(A[I].pago.nomi.nucu, 20, stdin);
                break;
            case 3: A[I].pago.venta = 'S';
                break;
        }
    }
}

void F1(vendedor A[], int T)
/* Esta funcion se utiliza para generar las ventas totales anuales de cada uno
de los vendedores de la empresa. */
{
    int I, J;
    float SUM;
    printf("\n\t\tVentas Totales de los Vendedores");
    for (I = 0; I < T; I++)
    {
        printf("\nVendedor: %d", A[I].num);
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        printf("\nVentas: %.2f\n", SUM);
    }
}

void F2(vendedor A[], int T)
/* Esta funcion se utiliza para incrementar 5% el salario de todos aquellos
vendedores cuyas ventas anuales superaron $1,500,000. */
{
    int I, J;
    float SUM;
    printf("\n\t\tIncremento a los Vendedores con Ventas > 1,500,000$");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM > 1500000.00)
        {
            A[I].sal = A[I].sal * 1.05;
            printf("\nNumero de empleado: %d\nVentas: %.2f\nNuevo salario: %.2f",
                   A[I].num, SUM, A[I].sal);
        }
    }
}

void F3(vendedor A[], int T)
/* Esta funcion se utiliza para generar un listado de todos aquellos
vendedores que en el ano vendieron menos de $300,000. */
{
    int I, J;
    float SUM;
    printf("\n\t\tVendedores con Ventas < 300,000");
    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < 12; J++)
            SUM += A[I].ven[J];
        if (SUM < 300000.00)
            printf("\nNumero de empleado: %d\nNombre: %s\nVentas: %.2f", A[I].num,
                   A[I].nom, SUM);
    }
}

void F4(vendedor A[], int T)
/* Esta funcion se usa para imprimir el numero de empleado, el nombre del
banco y el numero de cuenta de todos aquellos empleados a quienes se les
deposita su sueldo en cuenta de cheques. */
{
    int I;
    printf("\n\t\tVendedores con Cuenta en el Banco");
    for (I = 0; I < T; I++)
        if (A[I].cla == 1)
            printf("\nNumero de vendedor: %d\n Banco: %s\nCuenta: %s",
                   A[I].num,
                   A[I].pago.che.noba, A[I].pago.che.nucu);
}
