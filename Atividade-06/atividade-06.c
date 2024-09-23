#include <stdio.h>
2#include <string.h>
3
4#define MAX_PRODUTOS 100
5#define MAX_NOME 50
6
7typedef struct {
8    char nome[MAX_NOME];
9    int quantidade;
10    float preco;
11} Produto;
12
13Produto produtos[MAX_PRODUTOS];
14int num_produtos = 0;
15
16void entrada_de_produtos() {
17    char nome[MAX_NOME];
18    int quantidade;
19    float preco;
20
21    printf("Entrada de Produtos\n");
22    printf("Nome do produto: ");
23    scanf("%s", nome);
24    printf("Quantidade do produto: ");
25    scanf("%d", &quantidade);
26    printf("Preco do produto: ");
27    scanf("%f", &preco);
28
29    strcpy(produtos[num_produtos].nome, nome);
30    produtos[num_produtos].quantidade = quantidade;
31    produtos[num_produtos].preco = preco;
32    num_produtos++;
33
34    printf("Produto adicionado com sucesso!\n");
35}
36
37int main() {
38    int option;
39
40    do {
41        // Mostrar a tela de Menu
42        printf("----------------------------------------------------------------------\n");
43        printf("Sistema de Estoque\n");
44        printf("----------------------------------------------------------------------\n");
45        printf("1) Entrada de Produtos\n");
46        printf("2) Listar os Produtos\n");
47        printf("3) Valor Total do Estoque\n");
48        printf("4) Fim\n");
49        printf("Opcao: ");
50
51        // Receber o valor de opcao
52        scanf("%d", &option);
53
54        switch (option) {
55            case 1:
56                entrada_de_produtos();
57                break;
58            case 2:
59                printf("Listar os Produtos\n");
60                // Implementar a funcionalidade de listar produtos aqui
61                break;
62            case 3:
63                printf("Valor Total do Estoque\n"
...
