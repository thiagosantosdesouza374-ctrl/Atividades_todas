#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
    int idade;
} Pessoa;

void cadastrar() {
    FILE *arq = fopen("pessoas.dat", "ab");
    if (!arq) { perror("Erro"); return; }
    
    Pessoa primeira;
    printf("\nID: "); scanf("%d", &primeira.id);
    printf("Nome: "); 
    while(getchar() != '\n'); 
    fgets(primeira.nome, 50, stdin);
    primeira.nome[strcspn(primeira.nome, "\n")] = 0; 
    printf("Idade: "); scanf("%d", &primeira.idade);

    fwrite(&primeira, sizeof(Pessoa), 1, arq);
    printf("Cadastrado!\n");
    fclose(arq);
}

void listar() {
    FILE *arq = fopen("pessoas.dat", "rb");
    if (!arq) { printf("\nArquivo vazio.\n"); return; }

    Pessoa segunda;
    printf("\n--- Lista ---\n");
    while (fread(&segunda, sizeof(Pessoa), 1, arq) == 1) {
        printf("ID: %d | Nome: %s | Idade: %d\n", segunda.id, segunda.nome, segunda.idade);
    }
    fclose(arq);
}

int main() {
    int op;
    do {
        printf("\n1-Cadastrar | 2-Listar | 3-Sair\nOpcao: ");
        if (scanf("%d", &op) != 1) { op = 0; while(getchar() != '\n'); }
        while(getchar() != '\n');

        switch (op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (op != 3);
    return 0;
}