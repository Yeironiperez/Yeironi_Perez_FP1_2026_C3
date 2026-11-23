#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// ===== ESTRUCTURAS =====
typedef struct {
    int id;
    char nombre[50];
    char cedula[20];
    char telefono[20];
    int activo; // 1 = existe, 0 = borrado
} Cliente;

typedef struct {
    int id;
    int idCliente;
    char vehiculo[50];
    double valorVehiculo;
    double precio;
    double avance;
    double montoFinanciar;
    int meses;
    double interesAnual;
    double cuotaMensual;
    int activo;
} Prestamo;

Cliente clientes[MAX];
Prestamo prestamos[MAX];
int totalClientes = 0;
int totalPrestamos = 0;

// ===== ENTRADA SEGURA =====
// Lee una linea completa y la guarda en destino (maximo tam-1 caracteres).
void leerTexto(char *destino, int tam) {
    char linea[256];
    if (fgets(linea, sizeof(linea), stdin) == NULL) {
        destino[0] = '\0';
        return;
    }
    linea[strcspn(linea, "\n")] = 0;
    strncpy(destino, linea, tam - 1);
    destino[tam - 1] = '\0';
}

int leerInt() {
    char linea[100];
    int valor;
    while (1) {
        if (fgets(linea, sizeof(linea), stdin) == NULL) return 0;
        if (sscanf(linea, "%d", &valor) == 1) return valor;
        printf("Entrada invalida, intenta de nuevo: ");
    }
}

double leerDouble() {
    char linea[100];
    double valor;
    while (1) {
        if (fgets(linea, sizeof(linea), stdin) == NULL) return 0;
        if (sscanf(linea, "%lf", &valor) == 1) return valor;
        printf("Entrada invalida, intenta de nuevo: ");
    }
}

void pausa() {
    printf("\nPresiona ENTER para continuar...");
    getchar();
}

// ===== CLIENTES =====
int buscarCliente(int id) {
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].id == id && clientes[i].activo == 1)
            return i;
    }
    return -1;
}

void crearCliente() {
    if (totalClientes >= MAX) {
        printf("No se pueden crear mas clientes.\n");
        return;
    }
    Cliente c;
    c.id = totalClientes + 1;
    c.activo = 1;

    printf("\n--- CREAR CLIENTE ---\n");
    printf("Nombre: ");
    leerTexto(c.nombre, sizeof(c.nombre));
    printf("Cedula: ");
    leerTexto(c.cedula, sizeof(c.cedula));
    printf("Telefono: ");
    leerTexto(c.telefono, sizeof(c.telefono));

    clientes[totalClientes] = c;
    totalClientes++;
    printf("\nCliente creado con ID %d\n", c.id);
}

void listarClientes() {
    printf("\n--- LISTA DE CLIENTES ---\n");
    printf("%-5s %-25s %-15s %-15s\n", "ID", "NOMBRE", "CEDULA", "TELEFONO");
    for (int i = 0; i < totalClientes; i++) {
        if (clientes[i].activo == 1) {
            printf("%-5d %-25s %-15s %-15s\n", clientes[i].id, clientes[i].nombre,
                   clientes[i].cedula, clientes[i].telefono);
        }
    }
}

void modificarCliente() {
    listarClientes();
    printf("\nID del cliente a modificar: ");
    int id = leerInt();
    int pos = buscarCliente(id);
    if (pos == -1) {
        printf("Cliente no encontrado.\n");
        return;
    }
    printf("\n--- MODIFICAR CLIENTE (deja en blanco si no quieres cambiar) ---\n");

    char aux[50];

    printf("Nombre actual: %s\nNuevo nombre: ", clientes[pos].nombre);
    leerTexto(aux, sizeof(aux));
    if (strlen(aux) > 0) strcpy(clientes[pos].nombre, aux);

    char aux20[20];
    printf("Cedula actual: %s\nNueva cedula: ", clientes[pos].cedula);
    leerTexto(aux20, sizeof(aux20));
    if (strlen(aux20) > 0) strcpy(clientes[pos].cedula, aux20);

    printf("Telefono actual: %s\nNuevo telefono: ", clientes[pos].telefono);
    leerTexto(aux20, sizeof(aux20));
    if (strlen(aux20) > 0) strcpy(clientes[pos].telefono, aux20);

    printf("\nCliente modificado.\n");
}

void borrarCliente() {
    listarClientes();
    printf("\nID del cliente a borrar: ");
    int id = leerInt();
    int pos = buscarCliente(id);
    if (pos == -1) {
        printf("Cliente no encontrado.\n");
        return;
    }
    clientes[pos].activo = 0;
    // Tambien se borran sus prestamos
    for (int i = 0; i < totalPrestamos; i++) {
        if (prestamos[i].idCliente == id) prestamos[i].activo = 0;
    }
    printf("Cliente borrado (y sus prestamos).\n");
}

// ===== PRESTAMOS =====
double calcularCuota(double monto, int meses, double interesAnual) {
    double r = interesAnual / 12.0 / 100.0; // tasa mensual
    if (r == 0) return monto / meses;
    double factor = pow(1 + r, meses);
    return monto * r * factor / (factor - 1);
}

void crearPrestamo() {
    if (totalPrestamos >= MAX) {
        printf("No se pueden crear mas prestamos.\n");
        return;
    }
    listarClientes();
    printf("\nID del cliente para el prestamo: ");
    int idCliente = leerInt();
    if (buscarCliente(idCliente) == -1) {
        printf("Cliente no existe.\n");
        return;
    }

    Prestamo p;
    p.id = totalPrestamos + 1;
    p.idCliente = idCliente;
    p.activo = 1;

    printf("\n--- CREAR PRESTAMO ---\n");
    printf("Vehiculo (marca/modelo): ");
    leerTexto(p.vehiculo, sizeof(p.vehiculo));

    printf("Valor del vehiculo: ");
    p.valorVehiculo = leerDouble();

    do {
        printf("Precio de venta: ");
        p.precio = leerDouble();
        if (p.precio <= 0) printf("El precio debe ser mayor que 0.\n");
    } while (p.precio <= 0);

    do {
        printf("Avance del cliente (inicial): ");
        p.avance = leerDouble();
        if (p.avance < 0 || p.avance > p.precio)
            printf("El avance debe estar entre 0 y el precio.\n");
    } while (p.avance < 0 || p.avance > p.precio);

    do {
        printf("Cantidad de meses para pagar: ");
        p.meses = leerInt();
        if (p.meses <= 0) printf("Los meses deben ser mayor que 0.\n");
    } while (p.meses <= 0);

    do {
        printf("Porciento de interes anual (ej: 12): ");
        p.interesAnual = leerDouble();
        if (p.interesAnual < 0) printf("El interes no puede ser negativo.\n");
    } while (p.interesAnual < 0);

    p.montoFinanciar = p.precio - p.avance;
    p.cuotaMensual = calcularCuota(p.montoFinanciar, p.meses, p.interesAnual);

    prestamos[totalPrestamos] = p;
    totalPrestamos++;

    printf("\nPrestamo creado con ID %d!\n", p.id);
    printf("Monto a financiar: %.2f\n", p.montoFinanciar);
    printf("Cuota mensual: %.2f\n", p.cuotaMensual);
}

void listarPrestamos() {
    printf("\n--- LISTA DE PRESTAMOS ---\n");
    printf("%-5s %-8s %-20s %-12s %-12s %-10s %-8s %-10s\n",
           "ID", "CLIENTE", "VEHICULO", "PRECIO", "AVANCE", "FINANCIAR", "MESES", "CUOTA");
    for (int i = 0; i < totalPrestamos; i++) {
        if (prestamos[i].activo == 1) {
            printf("%-5d %-8d %-20s %-12.2f %-12.2f %-10.2f %-8d %-10.2f\n",
                   prestamos[i].id, prestamos[i].idCliente, prestamos[i].vehiculo,
                   prestamos[i].precio, prestamos[i].avance, prestamos[i].montoFinanciar,
                   prestamos[i].meses, prestamos[i].cuotaMensual);
        }
    }
}

void reportePrestamosPorCliente() {
    listarClientes();
    printf("\nID del cliente para ver sus prestamos: ");
    int idCliente = leerInt();
    int pos = buscarCliente(idCliente);
    if (pos == -1) {
        printf("Cliente no encontrado.\n");
        return;
    }
    printf("\n--- PRESTAMOS DE %s ---\n", clientes[pos].nombre);
    int encontrado = 0;
    for (int i = 0; i < totalPrestamos; i++) {
        if (prestamos[i].activo == 1 && prestamos[i].idCliente == idCliente) {
            encontrado = 1;
            printf("Prestamo #%d | Vehiculo: %s | Valor: %.2f | Precio: %.2f | Avance: %.2f | "
                   "Financiar: %.2f | Meses: %d | Interes: %.2f%% | Cuota: %.2f\n",
                   prestamos[i].id, prestamos[i].vehiculo, prestamos[i].valorVehiculo,
                   prestamos[i].precio, prestamos[i].avance, prestamos[i].montoFinanciar,
                   prestamos[i].meses, prestamos[i].interesAnual, prestamos[i].cuotaMensual);
        }
    }
    if (!encontrado) printf("Este cliente no tiene prestamos.\n");
}

void reportePagosPorMes() {
    listarPrestamos();
    printf("\nID del prestamo para ver tabla de pagos: ");
    int idPrestamo = leerInt();

    Prestamo *p = NULL;
    for (int i = 0; i < totalPrestamos; i++) {
        if (prestamos[i].id == idPrestamo && prestamos[i].activo == 1) {
            p = &prestamos[i];
            break;
        }
    }
    if (p == NULL) {
        printf("Prestamo no encontrado.\n");
        return;
    }

    double saldo = p->montoFinanciar;
    double r = p->interesAnual / 12.0 / 100.0;

    printf("\n--- TABLA DE PAGOS - Prestamo #%d ---\n", p->id);
    printf("Cliente ID: %d | Vehiculo: %s | Monto: %.2f | Cuota: %.2f\n\n",
           p->idCliente, p->vehiculo, p->montoFinanciar, p->cuotaMensual);
    printf("%-6s %-12s %-12s %-12s %-12s\n", "MES", "CUOTA", "INTERES", "CAPITAL", "SALDO");

    for (int mes = 1; mes <= p->meses; mes++) {
        double interes = saldo * r;
        double capital = p->cuotaMensual - interes;
        saldo = saldo - capital;
        if (saldo < 0.01) saldo = 0;
        printf("%-6d %-12.2f %-12.2f %-12.2f %-12.2f\n", mes, p->cuotaMensual, interes, capital, saldo);
    }
}

// ===== MENU =====
int main() {
    int opcion = -1;
    do {
        printf("\n========================================\n");
        printf("  GESTION DE PRESTAMO DE VEHICULOS\n");
        printf("========================================\n");
        printf("1. Crear cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Modificar cliente\n");
        printf("4. Borrar cliente\n");
        printf("5. Crear prestamo\n");
        printf("6. Listar prestamos\n");
        printf("7. Reporte: Prestamos por cliente\n");
        printf("8. Reporte: Pagos por mes y saldos\n");
        printf("0. Salir\n");
        printf("Elige una opcion: ");
        opcion = leerInt();

        switch (opcion) {
            case 1: crearCliente(); break;
            case 2: listarClientes(); break;
            case 3: modificarCliente(); break;
            case 4: borrarCliente(); break;
            case 5: crearPrestamo(); break;
            case 6: listarPrestamos(); break;
            case 7: reportePrestamosPorCliente(); break;
            case 8: reportePagosPorMes(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n"); break;
        }
        if (opcion != 0) pausa();

    } while (opcion != 0);
    return 0;
}
