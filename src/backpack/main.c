#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int agent;
    int capacity;
    int* items;
    int item_count;
} Agent;

typedef struct {
    int id;
    int weight;
} Item;

int compareItemsByWeightDesc(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    return itemB->weight - itemA->weight;
}

void greedyKnapsack(int C, int N, Item items[], FILE* output_stream);
void writeOutput(FILE* output_stream, Agent agents[], int agentCount);

int main(int argc, char** argv) {
    // Verificar los argumentos de línea de comandos
    if (argc != 3) {
        printf("Modo de uso: %s input output\nDonde:\n", argv[0]);
        printf("\t\"input\" es la ruta al archivo de input\n");
        printf("\t\"output\" es la ruta al archivo de output\n");
        return 1;
    }

    // Abrir el archivo de input
    FILE* input_stream = fopen(argv[1], "r");
    if (!input_stream) {
        printf("El archivo %s no existe o no se puede leer\n", argv[1]);
        return 2;
    }

    // Abrir el archivo de output
    FILE* output_stream = fopen(argv[2], "w");
    if (!output_stream) {
        printf("El archivo %s no se pudo crear o no se puede escribir\n", argv[2]);
        fclose(input_stream);
        return 3;
    }

    int C, N;
    fscanf(input_stream, "%d", &C);
    fscanf(input_stream, "%d", &N);

    Item* items = (Item*)malloc(N * sizeof(Item));
    for (int i = 0; i < N; i++) {
        fscanf(input_stream, "%d", &items[i].weight);
        items[i].id = i;
    }

    greedyKnapsack(C, N, items, output_stream);

    free(items);

    // Cerrar archivo de input
    fclose(input_stream);

    // Cerrar archivo de output
    fclose(output_stream);

    return 0;
}

void greedyKnapsack(int C, int N, Item items[], FILE* output_stream) {
    // Ordenar los items por peso de forma descendente
    qsort(items, N, sizeof(Item), compareItemsByWeightDesc);

    Agent* agents = (Agent*)malloc(N * sizeof(Agent));
    int agentCount = 0;

    int i, j;
    for (i = 0; i < N; i++) {
        int assigned = 0;
        // Buscar un agente disponible para llevar el item actual
        for (j = 0; j < agentCount; j++) {
            if (items[i].weight <= agents[j].capacity) {
                // Asignar el item al agente encontrado
                agents[j].items = realloc(agents[j].items, (agents[j].item_count + 1) * sizeof(int));
                agents[j].items[agents[j].item_count] = items[i].id;
                agents[j].item_count++;
                agents[j].capacity -= items[i].weight;
                assigned = 1;
                break;
            }
        }
        // Si no se asignó a ningún agente existente, crear uno nuevo
        if (!assigned) {
            agents[agentCount].agent = agentCount;
            agents[agentCount].capacity = C - items[i].weight;
            agents[agentCount].items = (int*)malloc(sizeof(int));
            agents[agentCount].items[0] = items[i].id;
            agents[agentCount].item_count = 1;
            agentCount++;
        }

        // Imprimir el ID y peso del item en la consola
        //printf("ID: %d, Peso: %d\n", items[i].id, items[i].weight);
    }

    // Escribir el resultado en el archivo de output
    writeOutput(output_stream, agents, agentCount);
    free(agents);
}


void writeOutput(FILE* output_stream, Agent agents[], int agentCount) {
    fprintf(output_stream, "%d\n", agentCount);
    for (int i = 0; i < agentCount; i++) {
        for (int j = 0; j < agents[i].item_count; j++) {
            fprintf(output_stream, "%d ", agents[i].items[j]);
        }
        fprintf(output_stream, "\n");
        free(agents[i].items);  // Liberar la memoria asignada para la lista de items
    }
}



