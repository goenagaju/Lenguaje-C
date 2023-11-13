#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras para guardar los datos
struct Venta {
    char codigo_producto[11];
    int codigo_vendedor;
    int cantidad;
};

struct Producto {
    char codigo_producto[11];
    float precio_venta;
};

// Función para leer el archivo de ventas
int leerVentas(struct Venta ventas[], int *numVentas) {
    FILE *archivo = fopen("ventas.dat", "rb");
    if (archivo == NULL) {
        return 0;
    }

    *numVentas = 0;
    while (fread(&ventas[*numVentas], sizeof(struct Venta), 1, archivo) == 1) {
        (*numVentas)++;
    }

    fclose(archivo);
    return 1;
}

// Función para mostrar la cantidad de ventas por vendedor y producto
void mostrarVentas(struct Venta ventas[], int numVentas) {
    int matriz[15][5] = {0}; // Matriz para contar ventas por producto y vendedor

    for (int i = 0; i < numVentas; i++) {
        int productoIndex = atoi(ventas[i].codigo_producto) - 1;
        int vendedorIndex = ventas[i].codigo_vendedor - 1;
        matriz[productoIndex][vendedorIndex] += ventas[i].cantidad;
    }

    printf("Producto\tVendedor 1\tVendedor 2\tVendedor 3\tVendedor 4\tVendedor 5\n");

    for (int i = 0; i < 15; i++) {
        printf("Prod%d\t", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%d\t\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para agregar una nueva venta
void agregarVenta(struct Venta ventas[], int *numVentas) {
    char codigo_producto[11];
    int codigo_vendedor, cantidad;

    printf("Ingrese el código de producto (max 10 caracteres): ");
    scanf("%s", codigo_producto);

    if (strcmp(codigo_producto, "99") == 0) {
        return;
    }

    printf("Ingrese el código de vendedor (1-5): ");
    scanf("%d", &codigo_vendedor);

    printf("Ingrese la cantidad de ventas: ");
    scanf("%d", &cantidad);

    if (codigo_vendedor < 1 || codigo_vendedor > 5) {
        printf("Código de vendedor no válido.\n");
        return;
    }

    if (*numVentas < 100) {
        strcpy(ventas[*numVentas].codigo_producto, codigo_producto);
        ventas[*numVentas].codigo_vendedor = codigo_vendedor;
        ventas[*numVentas].cantidad = cantidad;
        (*numVentas)++;
        printf("Venta registrada con éxito.\n");
    } else {
        printf("Se ha alcanzado el límite de ventas.\n");
    }
}

// Función para escribir las ventas en el archivo
void escribirVentas(struct Venta ventas[], int numVentas) {
    FILE *archivo = fopen("ventas.dat", "wb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de ventas.\n");
        return;
    }

    fwrite(ventas, sizeof(struct Venta), numVentas, archivo);
    fclose(archivo);
}

// Función principal
int main() {
    struct Venta ventas[100];
    int numVentas = 0;

    if (!leerVentas(ventas, &numVentas)) {
        printf("No se pudo abrir el archivo de ventas existente.\n");
    }

    int opcion;

    do {
        printf("\nMenú:\n");
        printf("1. Mostrar cantidad de ventas por vendedor y producto.\n");
        printf("2. Registrar nuevas ventas.\n");
        printf("3. Mostrar listado actualizado.\n");
        printf("4. Mostrar listado ordenado por importe de ventas.\n");
        printf("5. Mostrar productos con menor cantidad de ventas.\n");
        printf("6. Salir.\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarVentas(ventas, numVentas);
                break;
            case 2:
                agregarVenta(ventas, &numVentas);
                break;
            case 3:
                mostrarVentas(ventas, numVentas);
                break;
            case 4:
                // Implementar ordenamiento y mostrar ventas ordenadas por importe
                break;
            case 5:
                // Implementar búsqueda de productos con menor cantidad de ventas
                break;
            case 6:
                escribirVentas(ventas, numVentas);
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
    } while (opcion != 6);

    return 0;
}
