// Programa Lista Telefônica com Tabela Hash - Professor Lucas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMANHO_TABELA 1000

// Estrutura para armazenar os contatos
typedef struct contato {
    char nome[100];
    char telefone[20];
    struct contato *prox;
} Contato;

// Declaração da tabela hash
Contato *tabelaHash[TAMANHO_TABELA];

// Variáveis para medir desempenho
double tempoTotalInsercao = 0;
double tempoTotalBusca = 0;
int numInsercoes = 0;
int numBuscas = 0;

// Função hash para strings
int funcaoHash(char *nome) {
    unsigned long hash = 5381;
    int c;
    while ((c = *nome++))
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % TAMANHO_TABELA;
}

// Função para adicionar contato
void adicionarContato() {
    char nome[100];
    char telefone[20];
    printf("Nome: ");
    scanf(" %[^\n]", nome);
    printf("Telefone: ");
    scanf(" %[^\n]", telefone);

    clock_t inicio = clock();

    int indice = funcaoHash(nome);

    // Verificar se o contato já existe
    Contato *atual = tabelaHash[indice];
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            printf("Contato já existe. Atualizando telefone.\n");
            strcpy(atual->telefone, telefone);
            clock_t fim = clock();
            double tempoInsercao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
            tempoTotalInsercao += tempoInsercao;
            numInsercoes++;
            printf("Contato atualizado com sucesso (tempo de inserção: %.4f ms).\n", tempoInsercao);
            return;
        }
        atual = atual->prox;
    }

    // Criar novo contato
    Contato *novoContato = (Contato *)malloc(sizeof(Contato));
    if (novoContato == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(novoContato->nome, nome);
    strcpy(novoContato->telefone, telefone);
    novoContato->prox = tabelaHash[indice];
    tabelaHash[indice] = novoContato;

    clock_t fim = clock();
    double tempoInsercao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
    tempoTotalInsercao += tempoInsercao;
    numInsercoes++;

    printf("Contato adicionado com sucesso (tempo de inserção: %.4f ms).\n", tempoInsercao);
}

// Função para buscar contato
void buscarContato() {
    char nome[100];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    clock_t inicio = clock();

    int indice = funcaoHash(nome);

    Contato *atual = tabelaHash[indice];
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            clock_t fim = clock();
            double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
            tempoTotalBusca += tempoBusca;
            numBuscas++;
            printf("Telefone de %s: %s (tempo de busca: %.4f ms)\n", atual->nome, atual->telefone, tempoBusca);
            return;
        }
        atual = atual->prox;
    }

    clock_t fim = clock();
    double tempoBusca = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
    tempoTotalBusca += tempoBusca;
    numBuscas++;
    printf("Contato não encontrado (tempo de busca: %.4f ms).\n", tempoBusca);
}

// Função para remover contato
void removerContato() {
    char nome[100];
    printf("Nome: ");
    scanf(" %[^\n]", nome);

    int indice = funcaoHash(nome);

    Contato *atual = tabelaHash[indice];
    Contato *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                tabelaHash[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Contato removido com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Contato não encontrado.\n");
}

// Função para exibir todos os contatos
void exibirContatos() {
    printf("Lista de contatos:\n");
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Contato *atual = tabelaHash[i];
        while (atual != NULL) {
            printf("Nome: %s | Telefone: %s\n", atual->nome, atual->telefone);
            atual = atual->prox;
        }
    }
}

// Função para liberar a memória
void liberarMemoria() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Contato *atual = tabelaHash[i];
        while (atual != NULL) {
            Contato *temp = atual;
            atual = atual->prox;
            free(temp);
        }
        tabelaHash[i] = NULL;
    }
}

int main() {
    int opcao;

    // Inicializar a tabela hash
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabelaHash[i] = NULL;
    }

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar contato por nome\n");
        printf("3 - Remover contato\n");
        printf("4 - Exibir todos os contatos\n");
        printf("0 - Sair\n");
        printf("\nDigite uma opcao: ");

        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                buscarContato();
                break;
            case 3:
                removerContato();
                break;
            case 4:
                exibirContatos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Exibir estatísticas de desempenho
    if (numInsercoes > 0) {
        double mediaInsercao = tempoTotalInsercao / numInsercoes;
        printf("Tempo medio de insercao: %.4f ms\n", mediaInsercao);
    }
    if (numBuscas > 0) {
        double mediaBusca = tempoTotalBusca / numBuscas;
        printf("Tempo medio de busca: %.4f ms\n", mediaBusca);
    }

    // Liberar a memória alocada
    liberarMemoria();

    return 0;
}