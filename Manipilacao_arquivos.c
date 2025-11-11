#include <stdio.h>

typedef struct {
    int id;
    char nome[50];
    int idade;
} Pessoa;

int main() {
    FILE *arq;
    Pessoa p;
    int op;

    do {
        printf("\n1 - Cadastrar\n2 - Listar\n3 - Sair\n\nEscolha: ");
        scanf("%d", &op);

        if (op == 1) {
            arq = fopen("pessoas.dat", "ab");
            printf("ID: "); scanf("%d", &p.id);
            printf("Nome: "); scanf(" [^\n]", p.nome);
            printf("Idade: "); scanf("%d", &p.idade);
            fwrite(&p, sizeof(Pessoa), 1, arq);
            fclose(arq);
            printf("Cadastrado!\n");
        }
        else if (op == 2) {
            arq = fopen("pessoas.dat", "rb");
            if (!arq) { printf("Nenhum cadastro.\n"); continue; }
            while (fread(&p, sizeof(Pessoa), 1, arq) == 1)
                printf("ID: %d | Nome: %s | Idade: %d\n", p.id, p.nome, p.idade);
            fclose(arq);
        }

    } while (op != 3);

    printf("Saindo do cadastro... ");

    return 0;
}
