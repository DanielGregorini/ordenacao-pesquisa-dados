#include "header.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CriarVetorDe1M(int vetor1m[])
{

  int TAM = 1000000;
  FILE *arquivo;
  int tipoDeVetor = 0;
  int posicao = 0;

  while (tipoDeVetor != 10)
  {
    printf("\nMENU - CRIAR VETOR 1 MILHÃO:\n\n");
    printf("1- Ordenado\n");
    printf("2- Invertido\n");
    printf("3- Aleatório\n");
    printf("10- Voltar para o menu principal\n");
    scanf("%d", &tipoDeVetor);

    switch (tipoDeVetor)
    {
    case 1:
      // vetor ordenado
      arquivo = fopen("1m_Ordenado.txt", "w");
      for (int cont = 0; cont < TAM; cont++)
      {
        int numero = cont;
        fprintf(arquivo, "%d\n", numero);
      }

      fclose(arquivo);

      arquivo = fopen("1m_Ordenado.txt", "r");
      if (arquivo == NULL)
      {
        printf("Não foi possível abrir o arquivo.\n");
        return;
      }

      posicao = 0;
      char numero[80];

      // Inserindo o número no vetor
      while (!feof(arquivo))
      {
        fscanf(arquivo, "%s", numero);
        vetor1m[posicao++] = atoi(numero);
      }

      fclose(arquivo);
      break;

    case 2:
      // vetor invertido
      arquivo = fopen("1m_Invertido.txt", "w");
      for (int cont = 0; cont < TAM; cont++)
      {
        int numero = TAM - cont - 1;
        fprintf(arquivo, "%d\n", numero);
      }

      fclose(arquivo);

      arquivo = fopen("1m_Invertido.txt", "r");
      if (arquivo == NULL)
      {
        printf("Não foi possível abrir o arquivo.\n");
      }

      posicao = 0;
      char s[80];

      // Inserindo o número no vetor
      while (!feof(arquivo))
      {
        fscanf(arquivo, "%s", s);
        vetor1m[posicao++] = atoi(s);
      }
      fclose(arquivo);
      break;

    case 3:
      // vetor aleatório
      arquivo = fopen("1m_Aleatorio.txt", "r");
      if (arquivo == NULL)
      {
        printf("Não foi possível abrir o arquivo.\n");
      }
      posicao = 0;
      while (fscanf(arquivo, "%d", &vetor1m[posicao]) == 1)
      {
        posicao++;
        if (posicao > TAM)
        {
          printf(
              "O vetor está cheio, não é possível adicionar mais números.\n");
          break;
        }
      }
      fclose(arquivo);
      break;

    case 10:
      return;
      break;

    default:
      printf("Voltando ao menu principal...\n\n");
      break;
    }

    tipoDeVetor = 10;
  }

  imprimirVetor(vetor1m, 1000);
  p(1); // Pausar a tela
}
