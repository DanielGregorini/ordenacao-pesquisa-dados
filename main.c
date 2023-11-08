#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#else
#endif
// arquivos
#include "arquivos.c"
#include "header.h"

int main(void)
{
    CriarArquivosAleatorio();

    // PARA O CONSOLE SUPORTAR ACENTOS
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    // cria vetor de 500mil
    int *vetor500Mil = (int *)malloc(500000 * sizeof(int));
    if (vetor500Mil == NULL)
    {
        printf("Erro na alocação de memória para vetor500Mil.\n");
        return 1;
    }

    // cria vetor de 750mil
    int *vetor750Mil = (int *)malloc(750000 * sizeof(int));
    if (vetor750Mil == NULL)
    {
        printf("Erro na alocação de memória para vetor750Mil.\n");
        free(vetor500Mil);
        return 1;
    }

    // cria vetor de 1 milhão
    int *vetor1M = (int *)malloc(1000000 * sizeof(int));
    if (vetor1M == NULL)
    {
        printf("Erro na alocação de memória para vetor1M.\n");
        free(vetor500Mil);
        free(vetor750Mil);
        return 1;
    }

    int menu = 1;

    while (menu != 6)
    {
        p(0.5); // pausar tela
        ll();   // limpar tela

        printf("\n--MENU PRINCIPAL--\n\n");
        printf("1- Criar vetor de 500 mil\n");
        printf("2- Criar vetor de 750 mil\n");
        printf("3- Criar vetor de 1 Milhão\n");
        printf("--------------------------------\n");
        printf("4- Escolher o tipo de algoritmo de ordenação\n");
        printf("5- Escolher o tipo de algoritmo de pesquisa\n");
        // printf("5- \n");
        printf("6- Fechar programa\n");
        scanf("%d", &menu);

        switch (menu)
        {

        case 1:
            CriarVetorDe500Mil(vetor500Mil);
            break;
        case 2:
            CriarVetorDe750Mil(vetor750Mil);
            break;
        case 3:
            CriarVetorDe1M(vetor1M);
            break;
        case 4:
            OrdenarSubMenu(vetor500Mil, vetor750Mil, vetor1M);
            break;
        case 5:
            menuDePesquisaSubMenu(vetor500Mil, vetor750Mil, vetor1M);
            break;
        case 6:
            printf("\nPROGRAMA FECHADO...\n\n");
            break;
        default:
            printf("\n\n");
            break;
        }
    }

    free(vetor500Mil);
    free(vetor750Mil);
    free(vetor1M);

    return 0;
}