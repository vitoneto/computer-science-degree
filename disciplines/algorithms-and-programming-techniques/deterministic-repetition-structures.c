#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main()
{
    float nota;                // Variável para armazenar a nota lida do aluno
    float soma_notas = 0.0;    // Acumulador para a soma de todas as notas.
    int num_alunos = 0;        // Contador de alunos.
    float maior_nota = 0;      // armazena maior nota
    float menor_nota = 0;      // Armazena menor nota.
    int alunos_aprovados = 0;  // Contador de alunos com nota >= 6
    int alunos_reprovados = 0; // Contador de alunos com nota < 6
    float media = 0.0;         // Variável para armazenar a média das notas
    // Uso de uma constante para a nota de aprovação.
    const int nota_de_aprovacao = 6;

    printf("--- Análise de Notas de Alunos ---\n");
    printf("Digite a nota do aluno (0 a 10) ou digite -1 para finalizar.\n");

    // Leitura das notas dos alunos usando um loop while
    while (1)
    {
        printf("Nota do aluno %d: ", num_alunos + 1);

        // Lê a nota e verifica se a leitura foi bem-sucedida
        if (scanf("%f", &nota) != 1)
        {
            printf("Entrada inválida. Por favor, digite um número.\n");
            // Evita um loop infinito em caso de entrada não numérica
            while (getchar() != '\n')
                ;
            continue; // Continua para a próxima iteração do loop
        }

        // Testa a finalização do programa ao digitar -1.
        if (nota == -1)
        {
            break; // Sai do loop quando -1 é digitado
        }

        // Testar com notas inválidas para garantir que o programa trate essas entradas corretamente. [9]
        if (nota < 0 || nota > 10)
        {
            printf("Nota inválida. por favor, digite uma nota entre 0 e 10, ou -1 para sair.\n");
            continue; // vai pra próxima iteração sem processar a nota inválida
        }

        // Atualiza a soma total das notas e o contador de alunos
        soma_notas += nota;
        num_alunos++;

        // Identificação da maior e menor nota usando estruturas condicionais if-else
        // Para a primeira nota válida, inicializa maior_nota e menor_nota
        if (num_alunos == 1)
        {
            maior_nota = nota;
            menor_nota = nota;
        }
        else
        {
            if (nota > maior_nota)
            {
                maior_nota = nota;
            }
            if (nota < menor_nota)
            {
                menor_nota = nota;
            }
        }

        // Contagem dos alunos que passaram e não passaram
        if (nota >= nota_de_aprovacao)
        {
            alunos_aprovados++;
        }
        else
        {
            alunos_reprovados++;
        }
    }

    // Impressão dos resultados.
    printf("\n--- Resultados ---\n");

    if (num_alunos > 0)
    { // Verifica se alguma nota válida foi inserida
        // Cálculo da média das notas.
        media = soma_notas / num_alunos;
        printf("Total de alunos processados: %d\n", num_alunos);
        printf("Média das notas: %.2f\n", media);
        printf("Maior nota: %.2f\n", maior_nota);
        printf("Menor nota: %.2f\n", menor_nota);
        printf("Alunos aprovados (nota >= %d): %d\n", nota_de_aprovacao, alunos_aprovados);
        printf("Alunos reprovados (nota < %d): %d\n", nota_de_aprovacao, alunos_reprovados);
    }
    else
    {
        printf("Nenhuma nota válida foi inserida.\n");
    }

    return 0; // Indica que o programa foi executado com sucesso
}