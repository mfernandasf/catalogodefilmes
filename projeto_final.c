#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct filme {
    char titulo[50];
    char categoria[30];
    int duracao;
    int lancamento;
} filme;

typedef struct No {
    struct No* proximo;
    struct No* anterior;
    filme dados; 
} No;

void exibir_menu(){
    printf("--------------MENU---------------------\n");
    printf("1 - Inserir Filme\n2 - Buscar Filme\n3 - Exibir Catálogo\n4 - Excluir Filme\n0 - Sair\n");
    printf("Escolha uma opção: ");
}

void voltar_menu(){
    printf("\nPressione ENTER para voltar ao menu...");
    getchar(); 
}

// Função para inserir um filme
No* inserir_filme(No* catalogo, const char* titulo, const char* categoria, int duracao, int lancamento) {
    No* novo_filme = (No*)malloc(sizeof(No));

    strcpy(novo_filme->dados.titulo, titulo);
    strcpy(novo_filme->dados.categoria, categoria);
    novo_filme->dados.duracao = duracao;
    novo_filme->dados.lancamento = lancamento;

    novo_filme->proximo = catalogo;
    novo_filme->anterior = NULL;

    if (catalogo != NULL)
        catalogo->anterior = novo_filme;

    return novo_filme;
}

// Função para imprimir o catálogo de filmes
void imprime_catalogo(No* catalogo) {
    No* atual = catalogo;

    if (atual == NULL) {
        printf("Catálogo vazio!\n");
        return;
    }
    
    while (atual != NULL) {
        printf("Título: %s, Categoria: %s, Duração: %d min, Lançamento: %d\n",
               atual->dados.titulo, atual->dados.categoria, atual->dados.duracao, atual->dados.lancamento);
        atual = atual->proximo;
    }
}

// Função de busca linear para procurar filmes 
No* procura_filme(No* catalogo, const char* titulo) {
    No* temp = catalogo;
    int encontrado = 0;

    while (temp != NULL) {
        if (strncmp(temp->dados.titulo, titulo, strlen(titulo)) == 0) {
            printf("Título: %s, Categoria: %s, Duração: %d min, Lançamento: %d\n",
                   temp->dados.titulo, temp->dados.categoria, temp->dados.duracao, temp->dados.lancamento);
            encontrado = 1;
            break;
        }
        temp = temp->proximo;
    }

    if (!encontrado) {
        printf("Nenhum filme encontrado!\n");
    }

    return NULL;
}

// Função para excluir um filme 
No* excluir_filme(No* catalogo, const char* titulo) {
    No* temp = catalogo;
    int encontrado = 0;


    while (temp != NULL) {
        if (strstr(temp->dados.titulo, titulo) != NULL) {
            encontrado = 1;
            break;  
        }
        temp = temp->proximo;
    }

    if (!encontrado) {
        printf("Filme não encontrado!\n");
        return catalogo;
    }

    if (temp == catalogo) {
        catalogo = temp->proximo;
        if (catalogo != NULL) 
            catalogo->anterior = NULL;
    } else {
        if (temp->anterior != NULL)
            temp->anterior->proximo = temp->proximo;
        if (temp->proximo != NULL)
            temp->proximo->anterior = temp->anterior;
    }

    free(temp); 
    printf("Filme removido com sucesso!\n");
    return catalogo;
}

void menu_principal(No* catalogo) {
    int opcao;

    do {
        system("clear");  
        
        exibir_menu();
        scanf("%d", &opcao);
        getchar();  

        system("clear");  

        switch (opcao) {
            case 1: {
                char titulo[50], categoria[30];
                int duracao, lancamento;

               
                printf("Título do filme: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; 

                printf("Categoria do filme: ");
                fgets(categoria, 30, stdin);
                categoria[strcspn(categoria, "\n")] = '\0'; 

                printf("Duração (min): ");
                scanf("%d", &duracao);
                printf("Ano de lançamento: ");
                scanf("%d", &lancamento);
                getchar();  

                // Insere o filme no catálogo
                catalogo = inserir_filme(catalogo, titulo, categoria, duracao, lancamento);
                printf("Filme inserido com sucesso!\n");

                voltar_menu();
                break;
            }
            case 2: {
                char titulo[50];
                
                printf("Digite o título do filme que deseja buscar: ");
                fgets(titulo, 50, stdin);
                titulo[strcspn(titulo, "\n")] = '\0'; 

                procura_filme(catalogo, titulo);

                voltar_menu();
                break;
            }
            case 3:
                
                imprime_catalogo(catalogo);

                voltar_menu();
                break;
            case 4: {
                char parte_titulo[50];
                
                printf("Digite o título do filme que deseja excluir: ");
                fgets(parte_titulo, 50, stdin);
                parte_titulo[strcspn(parte_titulo, "\n")] = '\0'; 

                
                catalogo = excluir_filme(catalogo, parte_titulo);

                voltar_menu();
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                voltar_menu();
        }
    } while (opcao != 0);
}

int main() {
    No* catalogo = NULL;
    
    catalogo = inserir_filme(catalogo, "O Poderoso Chefão", "Drama", 175, 1972);
    catalogo = inserir_filme(catalogo, "Forrest Gump", "Drama", 142, 1994);
    catalogo = inserir_filme(catalogo, "A Origem", "Ficção Científica", 148, 2010);
    catalogo = inserir_filme(catalogo, "Clube da Luta", "Drama", 139, 1999);
    catalogo = inserir_filme(catalogo, "Matrix", "Ficção Científica", 136, 1999);
    catalogo = inserir_filme(catalogo, "O Senhor dos Anéis: A Sociedade do Anel", "Fantasia", 178, 2001);
    catalogo = inserir_filme(catalogo, "Vingadores: Ultimato", "Ação", 181, 2019);
    catalogo = inserir_filme(catalogo, "Interestelar", "Ficção Científica", 169, 2014);
    catalogo = inserir_filme(catalogo, "O Cavaleiro das Trevas", "Ação", 152, 2008);
    catalogo = inserir_filme(catalogo, "Gladiador", "Ação", 155, 2000);
    
    menu_principal(catalogo);
    
    return 0;
}
