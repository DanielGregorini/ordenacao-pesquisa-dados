#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <windows.h>
#else
#endif
#include "header.h"

void menuDePesquisaSubMenu(int vetor500mil[], int vetor750mil[], int vetor1m[])
{

  // calculo de tempo
  int operacoes = 0;
  int posicao = 0;
  int key = 0;
  double tempo;
  struct timeval inicio, fim;

  //loop
  int menuDePesquisa = 0;
  int tipoDoVetor = 0;
  int MenuDeEscolhaDoVetor = 0;

  while (MenuDeEscolhaDoVetor != 10)
  {
    printf("\nEscolha qual vetor você quer pesquisa:\n");
    printf("1- 500mil\n");
    printf("2- 750mil\n");
    printf("3- 1M\n");
    printf("4- Voltar ao menu principal\n");

    scanf("%d", &tipoDoVetor);

    switch (tipoDoVetor)
    {

    case 1:
      printf("\nVocê escolheu de 500 mil!\n");
      MenuDeEscolhaDoVetor = 10;
      break;

    case 2:
      printf("\nVocê escolheu de 750mil!\n");
      MenuDeEscolhaDoVetor = 10;
      break;

    case 3:
      printf("\nVocê escolheu de 1M!\n");
      MenuDeEscolhaDoVetor = 10;
      break;

    case 4:
      return;
      break; 

    default:
      printf("Opção inválida!!\n\n");
      break;
    }
  }

  while (menuDePesquisa != 10)
  {

    

    printf("\nMENU DE ALGORITMO DE PESQUISA:\n\n");
    printf("1- pesquisa binaria\n");
    printf("2-\n");
    printf("10- Voltar para o menu principal\n");
    scanf("%d", &menuDePesquisa);
    printf("\nQual numero você quer pesquisar?\n\n");
    scanf("%d", &key);

    switch (menuDePesquisa)
    {
    case 1:

      operacoes = 0;
      printf("\n--Começando a ordenação--\n\n");
      gettimeofday(&inicio, NULL);

      if (tipoDoVetor == 1)
      {
        posicao = buscaBinaria(vetor500mil, 0, 500000, key, &operacoes);
      }
      else if (tipoDoVetor == 2)
      {
        posicao = buscaBinaria(vetor750mil, 0, 750000, key, &operacoes);
      }
      else if (tipoDoVetor == 3)
      {
        posicao = buscaBinaria(vetor1m, 0, 1000000, key, &operacoes);
      }

      gettimeofday(&fim, NULL);
      tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
      printf("O valor está na posição:  %d e com %d operações.\nTempo de ordenação usando método gettime: %.7f segundos\n", posicao, operacoes, tempo);

      break;
   
   
    case 10:
      return;
    default:
      printf("Opção inválida!!\n\n");
      break;
    }
  }
}

int buscaBinaria(int vetor[], int ini, int fim, int key, int *operacoes){

    *operacoes += 1;

    int mei = (ini + fim) / 2;

    if ((ini == fim) && !(key == vetor[mei])){
        return -1;
    }else{
        if(key == vetor[mei]){
            return mei;
        }else{
            if(key > vetor[mei]){
                return buscaBinaria(vetor, mei+1, fim, key, operacoes);
            }else{
                return buscaBinaria(vetor, ini, mei-1, key, operacoes);
            }
        }
    }
}