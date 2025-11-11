#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[100];
    int ano_nascimento;
    char sexo;
    float altura;
    float peso;
    double cpf;
};

int main() {
    struct Pessoa pessoas[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        printf("Nome: ");
        fgets(pessoas[i].nome, 100, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0';

        printf("Ano de nascimento: ");
        scanf("%d", &pessoas[i].ano_nascimento);

        printf("Sexo (M/F): ");
        scanf(" %c", &pessoas[i].sexo);

        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);

        printf("Peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("CPF: ");
        scanf("%lf", &pessoas[i].cpf);
        getchar();
        printf("\n");
    }

    for (i = 0; i < 5; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Ano de nascimento: %d\n", pessoas[i].ano_nascimento);
        printf("Sexo: %c\n", pessoas[i].sexo);
        printf("Altura: %.2f\n", pessoas[i].altura);
        printf("Peso: %.2f\n", pessoas[i].peso);
        printf("CPF: %.0lf\n", pessoas[i].cpf);
    }

    return 0;
}
