#include <stdio.h>

/*
  Ejercicio: Tabla filtrada con reglas (for + continue + break)

  Reglas:
  - For anidado: externo = filas (i), interno = columnas (j).
  - "Corte" (break): si producto > C, se corta la fila inmediatamente.
  - "Salto" (continue): si producto % S == 0, no se imprime el número y se mantiene la columna con "--".
  - Estadísticas: impresos, saltados, filas cortadas.

  Notas de implementación:
  - Primero se evalúa el CORTE por C y luego el SALTO por S (orden importante).
  - Validamos entradas y limpiamos el buffer de stdin cuando hay lecturas inválidas.
  - Sin arreglos, sin operaciones bit a bit; solo bucles, condicionales, y E/S básica.
*/

int main(void){
    int M = 0, N = 0;          // Dimensiones de la tabla: filas (M), columnas (N)
    int S = 0, C = 0;          // S: múltiplo para saltar; C: valor de corte
    int impresos = 0;          // Cantidad de productos efectivamente impresos
    int saltados = 0;          // Cantidad de productos omitidos por 'continue'
    int filas_cortadas = 0;    // Número de filas que terminaron por 'break'

    // --- Entrada de M (filas) con validación y limpieza de buffer ---
    while (1){
        printf("\nIngrese la cantidad de filas de la tabla (1..12): ");
        if (scanf("%d", &M) != 1) {
            puts("----- Entrada invalida. Escriba un numero entero -----");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {} // limpia buffer
            continue;
        }
        if (M < 1 || M > 12) {
            puts("----- Fuera de rango (1..12) -----");
            continue;
        }
        break;
    }

    // --- Entrada de N (columnas) con validación y limpieza de buffer ---
    while (1){
        printf("\nIngrese la cantidad de columnas de la tabla (1..12): ");
        if (scanf("%d", &N) != 1) {
            puts("----- Entrada invalida. Escriba un numero entero -----");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        if (N < 1 || N > 12) {
            puts("----- Fuera de rango (1..12) -----");
            continue;
        }
        break;
    }

    // --- Entrada de S (divisor para saltar) con validación de > 0 ---
    while (1){
        printf("\nIngrese el divisor para saltar productos (S>0): ");
        if (scanf("%d", &S) != 1) {
            puts("----- Entrada invalida. Escriba un numero entero -----");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        if (S <= 0) {
            puts("----- S debe ser > 0 (evita modulo por 0) -----");
            continue;
        }
        break;
    }

    // --- Entrada de C (corte) con validación de > 0 ---
    while (1){
        printf("\nIngrese el valor de corte (C>0): ");
        if (scanf("%d", &C) != 1) {
            puts("----- Entrada invalida. Escriba un numero entero -----");
            int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
            continue;
        }
        if (C <= 0) {
            puts("----- C debe ser > 0 -----");
            continue;
        }
        break;
    }

    // --- Bucle principal: for anidado (filas x columnas) ---
    for (int i = 1; i <= M; i++){
        printf("\nFila %d:", i);

        for (int j = 1; j <= N; j++){
            int producto = i * j;

            // 1) Regla de CORTE: si producto supera C, se corta la fila (break).
            //    Es crucial que esto se evalúe ANTES que el salto por S.
            if (producto > C){
                printf(" [Corte]");
                filas_cortadas++;
                break; // Rompe SOLO el for interno (la fila actual).
            }

            // 2) Regla de SALTO: si es múltiplo de S, no imprimir el número.
            //    Usamos un ancho fijo para mantener columnas alineadas.
            if (producto % S == 0){
                printf("%4s", "--"); // "%4s" alinea "--" a 4 espacios como los enteros.
                saltados++;
                continue; // Salta al siguiente j sin tocar contadores de 'impresos'.
            }

            // 3) Caso normal: imprimimos el producto con ancho fijo.
            printf("%4d", producto);
            impresos++;
        }
    }

    // --- Resumen de estadísticas ---
    printf("\n\n\n--------- Resumen Tabla ----------");
    printf("\nImpresos: %d", impresos);
    printf("\nSaltados (continue): %d", saltados);
    printf("\nFilas cortadas (break): %d", filas_cortadas);
    printf("\n");

    return 0;
}



