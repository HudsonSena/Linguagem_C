#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // Para as funções sqrt() e pow()
#include <time.h>   // Para inicializar o gerador de números aleatórios

// 1. Definição da struct Unidade
typedef struct {
    int x;
    int y;
} Unidade;

// Função para gerar um valor inteiro aleatório entre min e max
int gerar_aleatorio(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// --- Função Principal ---
int main() {
    int n = 0;              // Número total de unidades
    double raio = 0.0;      // Raio máximo de proximidade
    Unidade *unidades = NULL; // Ponteiro para o vetor de structs
    int duplas_proximas = 0;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // 1. Entrada de dados
    printf("--- Detector de Duplas Próximas ---\n");
    printf("Digite o número de unidades (N): ");
    if (scanf("%d", &n) != 1 || n <= 1) {
        fprintf(stderr, "Erro: O número de unidades deve ser um inteiro maior que 1.\n");
        return 1;
    }

    printf("Digite o raio de proximidade (R): ");
    if (scanf("%lf", &raio) != 1 || raio < 0) {
        fprintf(stderr, "Erro: O raio deve ser um número não negativo.\n");
        return 1;
    }

    // 2. Alocação dinâmica de memória (malloc)
    // Aloca memória suficiente para N structs Unidade
    unidades = (Unidade *)malloc(n * sizeof(Unidade));

    if (unidades == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        return 1;
    }

    // 3. Inicialização e exibição das coordenadas (usando valores aleatórios)
    printf("\nCoordenadas das Unidades (%d total):\n", n);
    for (int i = 0; i < n; i++) {
        // Gera coordenadas aleatórias entre 0 e 1000
        unidades[i].x = gerar_aleatorio(0, 1000);
        unidades[i].y = gerar_aleatorio(0, 1000);
        printf("Unidade %2d: (%4d, %4d)\n", i, unidades[i].x, unidades[i].y);
    }

    // 4. Lógica de comparação e contagem (Laços Aninhados)
    printf("\nIniciando comparação de duplas...\n");

    // O primeiro laço itera da primeira unidade até a penúltima
    for (int i = 0; i < n; i++) {
        // O segundo laço itera da unidade seguinte (i+1) até a última
        // Isso garante:
        // a) Não comparar a unidade consigo mesma (j > i)
        // b) Não contar o mesmo par duas vezes (se i=A e j=B, não será feito j=A e i=B)
        for (int j = i + 1; j < n; j++) {
            
            // 4.1. Cálculo da diferença de coordenadas
            int dx = unidades[j].x - unidades[i].x;
            int dy = unidades[j].y - unidades[i].y;

            // 4.2. Cálculo da distância euclidiana
            // distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
            double distancia = sqrt(pow(dx, 2) + pow(dy, 2));

            // 4.3. Verificação e contagem
            if (distancia <= raio) {
                duplas_proximas++;
                /* // Linha opcional para verificação detalhada
                printf(" -> Dupla (%d, %d) próxima! Distância: %.2f\n", i, j, distancia); 
                */
            }
        }
    }

    // 5. Impressão do resultado
    printf("\n-------------------------------------------------\n");
    printf("Raio de Proximidade (R) = %.2f\n", raio);
    printf("Total de Unidades (N)   = %d\n", n);
    printf("Contagem total de duplas próximas: %d\n", duplas_proximas);
    printf("-------------------------------------------------\n");

    // 6. Liberação de memória (free)
    free(unidades);
    unidades = NULL; // Boa prática para evitar 'dangling pointer'

    return 0;
}