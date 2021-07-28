/****
(Discoteca) Crie um programa em C que registra informações das músicas de
um álbum musical. Um álbum pode ser caracterizado pelos seguintes dados:
nome (tamanho máximo de 25 caracteres), gênero musical (tamanho máximo
de 25 caracteres), quantidade de músicas (máximo de 10 músicas) e um
vetor de músicas. Uma música é caracterizada por: número da música
(incremental, sendo zero a primeira música do disco), nome (tamanho
máximo de 25 caracteres), duração da música (formato da string: MM:SS). O
programa deve exibir a cada iteração as seguintes opções:
1 - Criar o álbum músical
2 - Adicionar música ao álbum
3 - Listar músicas do álbum
4 - Sair
A opção 1 só pode ser escolhida uma única vez, enquanto as opções 2 e 3
só podem ser escolhidas apenas após a criação do álbum. Caso a opção 1 seja
escolhida mais de uma vez, o atual álbum deve ser apagado e inserido informações
sobre o novo álbum. A opção 2 deve exibir mensagem de erro caso o usuário tente
adicionar mais de 10 músicas e voltar ao menu principal. Já na opção 3, deve-se
listar em ordem crescente (a partir do número da música) o número da música,
nome e duração da música (uma música por linha). Por fim, a opção 4 encerra o
programa.
****/

#include <stdio.h>
#include <string.h>

struct Album
{
    char nome[25];
    int qtdMusicas;
    char genero[25];
} albums;

struct Musica{
    int numero;
    char nome[25];
    char duracao[6];
}musica;

void verifica(char palavra[])
{

    int controle=1, cont=0;

    while(controle != 0)
    {
        if(palavra[2] == ':')
        {
            for(int i=0; i<2; i++)
            {
                if(palavra[i] >= '0'  || palavra[i] <= '9')
                {
                    cont++;
                }
            }
            for(int i=3; i<5; i++)
            {
                if(palavra[i] >= '0'  || palavra[i] <= '9')
                {
                    cont++;
                }
            }

            if(cont == 4)
            {
                controle=0;
            }
        }
        else
        {
            printf("\nFormato incorreto, a duracao precisa ser no formato XX:XX onde X sao numeros!\n");
            scanf("%s",palavra);
            getchar();
        }
    }
}

int main()
{
    struct Musica musica[10]; //vetor de musicas
    int controle, controle2=1, controle3=1, cont=0;
    char aux[6];

    while(controle != 4)
    {
        printf("1 - criar o album musical;\n2 - Adicionar musica ao album;\n3 - listar musicas do album;\n4 - sair;\n");
        printf("\n");
        scanf("%d",&controle);
        switch(controle)
        {
        case 1:
            controle2 =1;
            controle3 =1;
            getchar();
            printf("\nNome do album: ");
            scanf("%[^\n]s",albums.nome);
            getchar();
            printf("\nGenero musical: ");
            scanf("%[^\n]s",albums.genero);
            getchar();
            printf("\nQuantidade de musicas do album: ");
            scanf("%d",&albums.qtdMusicas);
            if(albums.qtdMusicas >10)
            {
                printf("\nLimite execido, o album so pode conter no maximo 10 musicas!\n");
            }
            else
            {
                controle2 = 0;
            }

            printf("\n");

            break;
        case 2:
            if(controle2 == 0)
            {
                getchar();
                printf("\nEntre com as musicas do album: \n");
                for(int i=0; i<albums.qtdMusicas; i++)
                {
                    printf("Nome da musica: ");
                    scanf("%[^\n]s",musica[i].nome);
                    getchar();
                    printf("Duracao da musica: ");
                    scanf("%s",aux);
                    getchar();
                    verifica(aux);
                    strcpy(musica[i].duracao, aux);
                    cont = cont + 1;
                    musica[i].numero = cont;
                    printf("\n");
                }
                controle3 = 0;
            }
            else
            {
                printf("\nO album precisa ser criado antes de se adicionar alguma musica!\n");
            }
            printf("\n");
            break;
        case 3:
            printf("\n");
            if(controle3 == 0)
            {
                for(int i=0; i<albums.qtdMusicas; i++)
                {
                    printf("%d: Nome da musica: %s          duracao: %s\n",musica[i].numero, musica[i].nome, musica[i].duracao);
                }
            }
            else
            {
                printf("\nO album nao possui musicas adicionadas!\n");
            }
            printf("\n");
            break;
        case 4:
            printf("\nVoce saiu!\n");
            break;
        default:
            printf("\nopcao invalida, digite uma opcao valida! ");
            break;
        }
    }
}
