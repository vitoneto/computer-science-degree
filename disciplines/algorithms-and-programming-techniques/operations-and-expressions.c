#include <stdio.h>
#include <string.h>

const float TAXA_JUROS_ANUAL = 0.05;

int main() {
    float valor_inicial;
    int anos;
    float valor_final;

    // Correção: Vetor declarado com 3 elementos, conforme inicializado.
    int meu_vetor[3] = {10, 20, 30};
    // Correção: Matriz declarada como 2x2, conforme inicializado.
    int minha_matriz[2][2] = {{5, 10}, {15, 20}};

    // Correção: Declaração e inicialização do ponteiro na mesma linha ou separadamente.
    // Atribui ao ponteiro o endereço de memória do primeiro elemento do vetor.
    int *ptr_primeiro_elemento_vetor = &meu_vetor[0];

    // Modifica o valor do primeiro elemento do vetor através do ponteiro.
    *ptr_primeiro_elemento_vetor = 99;

    printf("--- Cálculo de Juros Simples ---\n");
    printf("Digite o valor inicial do investimento: ");
    scanf("%f", &valor_inicial);
    printf("Digite o número de anos para o investimento: ");
    scanf("%d", &anos);

    valor_final = valor_inicial * (1 + (TAXA_JUROS_ANUAL * anos));

    printf("\n--- Resultados do Investimento ---\n");
    printf("Valor Inicial do Investimento: R$ %.2f\n", valor_inicial);
    printf("Número de Anos: %d\n", anos);
    printf("Taxa de Juros Anual: %.2f%%\n", TAXA_JUROS_ANUAL * 100);
    printf("Valor Final do Investimento: R$ %.2f\n", valor_final);

    printf("\n--- Manipulação de Vetor e Matriz ---\n");

    printf("Valores do vetor (após modificação do primeiro elemento via ponteiro):\n");
    for (int i = 0; i < 3; i++) {
        printf("  vetor[%d]: %d (Endereço: %p)\n", i, meu_vetor[i], (void*)&meu_vetor[i]);
    }
    // Correção: Adicionado o especificador de formato e a variável correta.
    printf("  Note que o primeiro elemento do vetor foi modificado para %d usando um ponteiro.\n", meu_vetor[0]);

    printf("\nValores da matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("  matriz[%d][%d]: %d (Endereço: %p)\n", i, j, minha_matriz[i][j], (void*)&minha_matriz[i][j]);
        }
    }

    return 0;
}