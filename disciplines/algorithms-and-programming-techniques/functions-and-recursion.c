#include <stdio.h>
#include <time.h>

// Funções das Etapas 1 e 2
long long fibonacciSimples(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacciSimples(n - 1) + fibonacciSimples(n - 2);
}

long long fibonacciAuxiliar(int n, long long a, long long b)
{
    if (n == 0)
    {
        return a;
    }
    return fibonacciAuxiliar(n - 1, b, a + b);
}

long long fibonacciCauda(int n)
{
    return fibonacciAuxiliar(n, 0, 1);
}

int main()
{
    // Array de valores de n para teste
    int ns[] = {10, 20, 30, 40};
    int num_ns = sizeof(ns) / sizeof(ns[0]);

    clock_t inicio, fim;
    double tempo_simples, tempo_cauda;
    long long resultado_simples;

    // Cabeçalho da tabbela
    printf("n\t\tSimples (s)\t\tCauda (s)\t\tResultado\n");

    // Loop para cada valor de n
    for (int i = 0; i < num_ns; i++)
    {
        int n = ns[i];

        // Medição e cálculo para a função simples
        inicio = clock();
        resultado_simples = fibonacciSimples(n);
        fim = clock();
        tempo_simples = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Medição para a função em cauda (o resultado deve ser o mesmo)
        inicio = clock();
        fibonacciCauda(n);
        fim = clock();
        tempo_cauda = (double)(fim - inicio) / CLOCKS_PER_SEC;

        // Impressão da linha da tabela com o resultado
        printf("%d\t\t%.6f\t\t%.6f\t\t%lld\n", n, tempo_simples, tempo_cauda, resultado_simples);
    }

    return 0;
}