#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
 
// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

#define MAX_P 5
#define MAX_PILHA 3
// STRUCT DAS PEÇAS
typedef struct {
    char peca;
    int id;
} Pecas;

// STRUCT PARA A LISTA
typedef struct {
    Pecas itens[MAX_P];
    int inicio;
    int fim;
    int total;
} Fila;

typedef struct{
    Pecas itens[MAX_PILHA];
    int topo;
}Pilha;

//FUNÇÕES DA FILA
void inicializandoFila(Fila *f);
int filaCheia(Fila *f);
int filaVazia(Fila *f);
void menuPrincipal(Fila *f, Pilha *p);
void inserindoPrimeiraLista(Fila *f);
void gerarPecas(Fila *f);
void inserir(Fila *f, Pecas p);
Pecas remover(Fila *f);
void mostrarFila(Fila *f);

//FUNÇÕES PARA A PILHA
void inicilizandoPilha(Pilha *p);
int pilhaVazia(Pilha *p);
int pilhaCheia(Pilha *p);
void inserirPilha(Fila *f, Pilha *p);
void mostrarPilha(Pilha *p);
Pecas removendoPilha(Pilha *p);

//FUNÇÕES DE INTERAÇÃO ENTRE PILHA E FILA
void trocarTresItens(Fila *f, Pilha *p, Pecas *pe);
void trocarPecaFrente(Fila *f, Pilha *p, Pecas *pe);


//FUNÇÃO PRINCIPAL
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

    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));

    Fila f;
    Pilha p;
    Pecas pe;
    int opcao, i=0;
    
    inicializandoFila(&f);
    inserindoPrimeiraLista(&f);

    inicilizandoPilha(&p);

    do {
        menuPrincipal(&f, &p);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                remover(&f);
                gerarPecas(&f);
                break;
            case 2:
                inserirPilha(&f, &p);
                break;
            case 3:
                removendoPilha(&p);
                break;
            case 4:
                trocarPecaFrente(&f, &p, &pe);
            break;
            case 5:
                trocarTresItens(&f, &p, &pe);
                sleep(1);
            break;
            case 0:
                printf("Saindo...\n");
                sleep(1);
            break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);


    return 0;
}

//////////////////////////// FUNÇÕES PARA FILA //////////////////////
//inicializandoFila()
void inicializandoFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}


//filaCheia()
//verificando se a fila esta cheia
int filaCheia(Fila *f)
{
    return f->total == MAX_P;
}

//filaVazia()
//verificando se a fila esta vazia
int filaVazia(Fila *f)
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
void menuPrincipal(Fila *f, Pilha *p)
{
    sleep(1);
    printf("\n\n============================\n");
    printf("\tTETRIS STACK\n");
    printf("============================\n");

    printf("1 - Jogar peça\n");
    printf("2 - Reservar\n");
    printf("3 - Usar peça reservada\n");
    printf("4 - Trocar 1º item da pila com o 1º da fila\n");
    printf("5 - Inverter os reservas com o primeiros elementos da lista\n");
    printf("0 - Sair\n");
    printf("----------------------------\n");
    printf("Fila atual: \n");
    mostrarFila(f);
    mostrarPilha(p);
    printf("----------------------------\n");
    printf("Escolha sua opção: ");

}

//gerarPecas()
//Função para gerar as pecas
void gerarPecas(Fila *f)
{
    static int ID = 1;
    int num = rand() % 4;
    char tipos[] = {'T', 'I', 'O', 'L'};

    Pecas novaPeca;
    novaPeca.peca = tipos[num];
    novaPeca.id = ID++;

    inserir(f, novaPeca);
}

//inserir()
//inserindo as peças na fila
void inserir(Fila *f, Pecas p)
{
    if(filaCheia(f))
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
Pecas remover(Fila *f)
{
    Pecas removida;
    if(filaVazia(f))
    {
        printf("\nErro: A fila está vazia, não tem o que remover\n");
        // Retorna uma peça vazia em caso de erro
        removida.peca = ' ';
        removida.id = -1;
        return removida;
    }
    
    removida = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_P;
    f->total--;
    return removida; // FALTAVA ESTE RETURN
}

//mostrarFila()
void mostrarFila(Fila *f)
{
    if(filaVazia(f))
    {
        printf("Erro: a fila está vazia!");
        return;
    }
    sleep(1);

    for(int i=0, idx=f->inicio; i < f->total; i++, idx=(idx+1)%MAX_P)
    {
        printf("(%c%d)\n", f->itens[idx].peca, f->itens[idx].id);
    }
}

///////////////////// FUNÇÃO PARA A PILHA //////////////////////////
void inicilizandoPilha(Pilha *p)
{
    p->topo = -1;
}

//Verifica se a pilha esta cheia
int pilhaCheia(Pilha *p)
{
    return p->topo == MAX_PILHA - 1;
}
 // verifica sea pilha esta vazia
int pilhaVazia(Pilha *p)
{
    return p->topo == -1;
}

//inserirndo peças da fila na pilha
void inserirPilha(Fila *f, Pilha *p)
{
    
    if(pilhaCheia(p))
    {
        printf("Erro: a Pilha está cheia!");
        return;
    }

    p->topo++;
    p->itens[p->topo] = f->itens[f->inicio];
    remover(f);
}

void mostrarPilha(Pilha *p)
{
    if(pilhaVazia(p))
    {
        printf("A Pilha está vazia!\n");
        return;
    }
    sleep(1);
    printf("----------------\n");
    printf("Pilha Atual: \n");
    for(int i = p->topo; i >= 0; i-- )
    {
        printf("(%c%d)\n", p->itens[i].peca, p->itens[i].id);
    }
}

//removendo peças da pilha
Pecas removendoPilha(Pilha *p)
{
    if(!pilhaVazia(p))
    {
        return p->itens[p->topo--];
    }
    printf("\nA Pilha está vazia!\n");
}

//////////////////////////// INTERAÇÃO DE FILAS E PILHAS - NÍVEL MESTRE //////////////////////

void trocarPecaFrente(Fila *f, Pilha *p, Pecas *pe)
{
    if(filaVazia(f))
    {
        printf("Erro: a fila está vazia, não há peça na frente para trocar.\n");
        return;
    }
    if(pilhaVazia(p))
    {
        printf("Erro: a pilha está vazia, não há peça no topo para trocar.\n");
        return;
    }

    int idxFila = f->inicio;
    int idxPilha = p->topo;

    // troca simples entre frente da fila e topo da pilha
    f->itens[f->inicio] = p->itens[p->topo];
    removendoPilha(p);

    printf("\nTroca realizada com sucesso!\n");
}
// Função para trocar os 3 primeiros da fila com as 3 peças da pilha
void trocarTresItens(Fila *f, Pilha *p, Pecas *pe)
{
    Fila auxx;


    for(int i = f->inicio; i <= f->fim; i++)
    {
        Pecas pFila = f->itens[i];
        inserir(&auxx, pFila);
    }
    mostrarFila(&auxx);
    printf("Troca realizada: 3 primeiros da fila com as 3 peças da pilha!\n");
}