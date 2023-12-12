#include <stdio.h>
#include <stdlib.h>

#define MAX_INSUMOS 100
#define MESES 12

// Estructura para un insumo
typedef struct {
    int id;
    char nombre[50];
    int ingresos[MESES];
    int egresos[MESES];
} Insumo;

// Declaración de funciones
void menuPrincipal(Insumo insumos[], int *cont_insumos);
void registrarInsumo(Insumo insumos[], int *cont_insumos);
void registrarTransaccion(Insumo insumos[], int cont_insumos);
void mostrarReporteAnual(Insumo insumos[], int cont_insumos);

int main() {
    Insumo insumos[MAX_INSUMOS];
    int cont_insumos = 0;

    menuPrincipal(insumos, &cont_insumos);

    return 0;
}

void menuPrincipal(Insumo insumos[], int *cont_insumos) {
    int opcion;

    do {
        printf("Menu Principal\n");
        printf("1. Registrar Insumo\n");
        printf("2. Registrar Transaccion\n");
        printf("3. Mostrar Reporte Anual\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarInsumo(insumos, cont_insumos);
                break;
            case 2:
                registrarTransaccion(insumos, *cont_insumos);
                break;
            case 3:
                mostrarReporteAnual(insumos, *cont_insumos);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while (opcion != 4);
}

void registrarInsumo(Insumo insumos[], int *cont_insumos) {
    if (*cont_insumos < MAX_INSUMOS) {
        printf("Ingrese el ID del insumo: ");
        scanf("%d", &insumos[*cont_insumos].id);
        printf("Ingrese el nombre del insumo: ");
        scanf("%s", insumos[*cont_insumos].nombre);
        for (int i = 0; i < MESES; i++) {
            insumos[*cont_insumos].ingresos[i] = 0;
            insumos[*cont_insumos].egresos[i] = 0;
        }
        (*cont_insumos)++;
    } else {
        printf("Se ha alcanzado el maximo de insumos.\n");
    }
}

void registrarTransaccion(Insumo insumos[], int cont_insumos) {
    int id, mes, ingreso, egreso, encontrado = 0;

    printf("Ingrese el ID del insumo: ");
    scanf("%d", &id);
    printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes);

    if (mes < 1 || mes > 12) {
        printf("Mes invalido.\n");
        return;
    }

    for (int i = 0; i < cont_insumos; i++) {
        if (insumos[i].id == id) {
            encontrado = 1;
            printf("Ingrese los ingresos para el mes: ");
            scanf("%d", &ingreso);
            printf("Ingrese los egresos para el mes: ");
            scanf("%d", &egreso);

            if (egreso > ingreso) {
                printf("Los egresos no pueden superar los ingresos.\n");
            } else {
                insumos[i].ingresos[mes - 1] += ingreso;
                insumos[i].egresos[mes - 1] += egreso;
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Insumo no encontrado.\n");
    }
}

void mostrarReporteAnual(Insumo insumos[], int cont_insumos) {
    for (int i = 0; i < cont_insumos; i++) {
        int totalIngresos = 0, totalEgresos = 0;
        printf("Insumo: %s\n", insumos[i].nombre);
        for (int j = 0; j < MESES; j++) {
            totalIngresos += insumos[i].ingresos[j];
            totalEgresos += insumos[i].egresos[j];
        }
        printf("Total ingresos anuales: %d\n", totalIngresos);
        printf("Total egresos anuales: %d\n", totalEgresos);
    }
}
