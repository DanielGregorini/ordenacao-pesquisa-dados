#include "header.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 500000

void CriarVetorDe500Mil(int vetor500mil[]) {
  FILE *arquivo;
  int tipoDeVetor = 0;
  int posicao = 0;

  while (tipoDeVetor != 10) {
    printf("\nMENU - CRIAR VETOR 500 MIL:\n\n");
    printf("1- Ordenado\n");
    printf("2- Invertido\n");
    printf("3- Aleatório\n");
    printf("10- Voltar para o menu principal\n");
    scanf("%d", &tipoDeVetor);

    switch (tipoDeVetor) {
    case 1:

      // vetor ordenado
      arquivo = fopen("500mil_Ordenado.txt", "w");
      for (int cont = 0; cont < TAM; cont++) {
        int numero = cont;
        fprintf(arquivo, "%d\n", numero);
      }
      fclose(arquivo);

      arquivo = fopen("500mil_Ordenado.txt", "r");
      if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
      }
      posicao = 0; // Reset posicao
      while (fscanf(arquivo, "%d", &vetor500mil[posicao]) == 1) {
        posicao++;
        if (posicao > TAM) {
          printf(
              "O vetor está cheio, não é possível adicionar mais números.\n");
          break;
        }
      }
      fclose(arquivo);

      // imprimirVetor(vetor500mil, TAM);
      break;

    case 2:

      // vertor invertido
      arquivo = fopen("500mil_Invertido.txt", "w");
      for (int cont = 0; cont < TAM; cont++) {
        int numero = TAM - cont - 1;
        fprintf(arquivo, "%d\n", numero);
      }
      fclose(arquivo);

      arquivo = fopen("500mil_Invertido.txt", "r");
      if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
      }
      posicao = 0;
      while (fscanf(arquivo, "%d", &vetor500mil[posicao]) == 1) {
        posicao++;
        if (posicao > TAM) {
          printf(
              "O vetor está cheio, não é possível adicionar mais números.\n");
          break;
        }
      }
      fclose(arquivo);

      // imprimirVetor(vetor500mil, TAM);
      break;

    case 3:

      // vetor aleátorio
      /* srand(time(NULL));
      arquivo = fopen("500mil_Aleatorio.txt", "w");
        for (int cont = 0; cont < TAM; cont++) {
            int numero = rand() % 500000;
            fprintf(arquivo, "%d\n", numero);
        }
        fclose(arquivo);*/

      arquivo = fopen("500mil_Aleatorio.txt", "r");
      if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
      }
      posicao = 0;
      while (fscanf(arquivo, "%d", &vetor500mil[posicao]) == 1) {
        posicao++;
        if (posicao > TAM) {
          printf(
              "O vetor está cheio, não é possível adicionar mais números.\n");
          break;
        }
      }
      fclose(arquivo);

      // imprimirVetor(vetor500mil, TAM);
      break;

    default:
      printf("Voltando ao menu principal...\n\n");
      break;
    }
    tipoDeVetor = 10;
  }
  imprimirVetor(vetor500mil, 10000);
  p(1);//pausar a tela
}
