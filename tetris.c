#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.


#define MAX_P 5

//STRUCT DAS PEÇAS
typedef struct{
    char peca;
    int id;
}Pecas;

//STRCUT PARA A LISTA
typedef struct{
    Pecas itens[MAX_P];
    int inicio;
    int fim;
    int total;
}Fila;

int main() {

    // 🧩 Nível Novato: Fila de Peças Futuras
    //
    // - Crie uma struct Peca com os campos: tipo (char) e id (int).
    // - Implemente uma fila circular com capacidade para 5 peças.
    // - Crie funções como inicializarFila(), enqueue(), dequeue(), filaCheia(), filaVazia().
    // - Cada peça deve ser gerada automaticamente com um tipo aleatório e id sequencial.
    // - Exiba a fila após cada ação com uma função mostrarFila().
    // - Use um menu com opções como:
    //      1 - Jogar peça (remover da frente)
    //      0 - Sair
    // - A cada remoção, insira uma nova peça ao final da fila.

    setlocale(LC_ALL, "pt_BR.UTF-8"); //deixar em português
    srand(time(NULL)); //usar o horário do computador na hora de gerar os números
    

    Fila f;
    int opcao;
    

    do{
        menuPrincipal(&f);
        scanf("%d", &opcao);


        switch (opcao)
        {
            case 1:

        }
        
    }while(opcao != 0);

    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

//inicializandoFila()
void inicializandoFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

//filaCheia()
//verificando se a fila esta cheia
void filaCheia(Fila *f)
{
    return f->total = MAX_P;
}

//filaVazia()
//verificando se a fila esta vazia
void filaVazia(Fila *f)
{
    return f->total == 0;
}

//inserindoPrimeiraLista()
//sortear as primeiras peças
void inserindoPrimeiraLista(Fila *f)
{
    for(int i = 0; i < MAX_P; i++)
    {
        gerarPecas(f);
    }
}

//menuPrincipal
void menuPrincipal(Fila *f)
{
    printf("============================\n");
    printf("\tTETRIS STACK\n");
    printf("============================\n");

    printf("1 - Jogar peça\n");
    printf("2 - Inserir nova peça\n");
    printf("0 - Sair\n\n");
    printf("----------------------------\n");
    printf("Fila atual: \n");
    mostrarFila(&f);
    printf("----------------------------\n");
    printf("Escolha sua opção: ");

}

//gerarPecas()
//Função para gerar as pecas
void gerarPecas(Fila *f)
{
    static int ID = 1;
    int num = rand()%4;
    int i=0;

    char tipos[] = {'T', 'I', 'O', 'L'};

    Pecas novaPeca;
    novaPeca.peca = tipos[num];
    novaPeca.id = ID++;

    inserir(f, novaPeca);

}

//inserir()
//inserindo as peças na fila
void inserir(Fila *f, Pecas p, int id)
{
    if(filaCheia)
    {
        printf("\nErro: A fila esta cheia, tire um item antes de acrescentar!\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX_P;
    f->total++;

}

//remover()
//removendo peças
void remover(Fila *f)
{
    if(filaVazia)
    {
        printf("\nErro: A fila está vazia, não tem o que remover\n");
    }
    
    Pecas removida = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_P;
    f->total--;
}

//listarPecas()
void listarPecas(Fila *f)
{
    if(filaVazia)
    {
        printf("Erro: A lista está vazia!");
    }

    printf("\n----------------\n");
    printf("Fila de peças: \n");
    for(int i = 0, idx = f->inicio; i < f-> total; i++, idx = (idx + 1) % MAX_P){
        printf("[%s%d]\n", f->itens[idx].peca, f->itens[idx].id);
    }
    printf("\n----------------\n");
}