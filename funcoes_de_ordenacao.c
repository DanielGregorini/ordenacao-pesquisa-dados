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

void OrdenarSubMenu(int vetor500mil[], int vetor750mil[], int vetor1m[])
{

  // calculo de tempo
  double tempo;
  struct timeval inicio, fim;

  int menuDeOrdenacao = 0;
  int tipoDoVetor = 0;
  int MenuDeEscolhaDoVetor = 0;

  while (MenuDeEscolhaDoVetor != 10)
  {
    printf("\nEscolha qual vetor você quer ordenar:\n");
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
      break; // Voltar ao menu principal
    default:
      printf("Opção inválida!!\n\n");
      break;
    }
  }

  while (menuDeOrdenacao != 10)
  {
    printf("\nMENU DE ALGORITMO:\n\n");
    printf("1- bubblesort\n");
    printf("2- insertsort\n");
    printf("3- selectsort\n");
    printf("4- shellsort\n");
    printf("5- quicksort_Hoare\n");
    printf("6- quicksort_Lomuto\n");
    printf("7- mergesort\n");
    printf("8- radixsort\n");
    printf("9- heapsort\n");
    printf("10- Voltar para o menu principal\n");
    scanf("%d", &menuDeOrdenacao);

    switch (menuDeOrdenacao)
    {
    case 1:
      if (tipoDoVetor == 1)
      {
        bubblesort(vetor500mil, 500000);
      }
      else if (tipoDoVetor == 2)
      {
        bubblesort(vetor750mil, 750000);
      }
      else if (tipoDoVetor == 3)
      {
        bubblesort(vetor1m, 1000000);
      }

      break;
    case 2:
      if (tipoDoVetor == 1)
      {
        insertsort(vetor500mil, 500000);
      }
      else if (tipoDoVetor == 2)
      {
        insertsort(vetor750mil, 750000);
      }
      else if (tipoDoVetor == 3)
      {
        insertsort(vetor1m, 1000000);
      }

      break;

    case 3:
      if (tipoDoVetor == 1)
      {
        selectionsort(vetor500mil, 500000);
      }
      else if (tipoDoVetor == 2)
      {
        selectionsort(vetor750mil, 750000);
      }
      else if (tipoDoVetor == 3)
      {
        selectionsort(vetor1m, 1000000);
      }
      break;
    case 4:
      if (tipoDoVetor == 1)
      {

        shellsort(vetor500mil, 500000);
      }
      else if (tipoDoVetor == 2)
      {
        shellsort(vetor750mil, 750000);
      }
      else if (tipoDoVetor == 3)
      {
        shellsort(vetor1m, 1000000);
      }
      break;

    case 5:

      printf("\n--Começando a ordenação--\n\n");

      gettimeofday(&inicio, NULL);

      if (tipoDoVetor == 1)
      {

        quickSortHoare(vetor500mil, 0, 500000 - 1);
      }
      else if (tipoDoVetor == 2)
      {
        quickSortHoare(vetor750mil, 0, 750000 - 1);
      }
      else if (tipoDoVetor == 3)
      {
        quickSortHoare(vetor1m, 0, 1000000 - 1);
      }

      gettimeofday(&fim, NULL);
      tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
      printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);

      break;

    case 6:

      printf("\n--Começando a ordenação--\n\n");

      gettimeofday(&inicio, NULL);

      if (tipoDoVetor == 1)
      {
        quickSortLomuto(vetor500mil, 0, 500000 - 1);
      }
      else if (tipoDoVetor == 2)
      {
        quickSortLomuto(vetor750mil, 0, 750000 - 1);
      }
      else if (tipoDoVetor == 3)
      {
        quickSortLomuto(vetor1m, 0, 1000000 - 1);
      }

      gettimeofday(&fim, NULL);
      tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
      printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);

      break;

    case 7:

      printf("\n--Começando a ordenação--\n\n");

      gettimeofday(&inicio, NULL);

      if (tipoDoVetor == 1)
      {
        mergesort(vetor500mil, 0, 500000 - 1);
      }
      else if (tipoDoVetor == 2)
      {
        mergesort(vetor750mil, 0, 750000 - 1);
      }
      else if (tipoDoVetor == 3)
      {
        mergesort(vetor1m, 0, 1000000 - 1);
      }
      gettimeofday(&fim, NULL);
      tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
      printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);
      break;

    case 8:

      printf("\n--Começando a ordenação--\n\n");

      gettimeofday(&inicio, NULL);

      if (tipoDoVetor == 1)
      {
        radixsort(vetor500mil, 500000);
      }
      else if (tipoDoVetor == 2)
      {
        radixsort(vetor750mil, 750000);
      }
      else if (tipoDoVetor == 3)
      {
        radixsort(vetor1m, 1000000);
      }
      gettimeofday(&fim, NULL);
      tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
      printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);
      break;

    case 9:

      printf("\n--Começando a ordenação--\n\n");

      gettimeofday(&inicio, NULL);

      if (tipoDoVetor == 1)
      {
        heapsort(vetor500mil, 500000);
      }
      else if (tipoDoVetor == 2)
      {
        heapsort(vetor750mil, 750000);
      }
      else if (tipoDoVetor == 3)
      {
        heapsort(vetor1m, 1000000);
        imprimirVetor(vetor1m, 10000);
      }
      gettimeofday(&fim, NULL);
      tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
      printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);

      break;

    case 10:
      return;
    default:
      printf("Opção inválida!!\n\n");
      break;
    }
  }
}

void insertsort(int vetor[], int tam)
{
  printf("\n--Começando a ordenação--\n\n");

  struct timeval inicio, fim;

  gettimeofday(&inicio, NULL);

  int aux, y;

  for (int x = 1; x < tam; x++)
  {
    aux = vetor[x];
    y = x - 1;

    while (y >= 0 && aux < vetor[y])
    {
      vetor[y + 1] = vetor[y];
      y = y - 1;
    }

    vetor[y + 1] = aux;
  }
  gettimeofday(&fim, NULL);

  double tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
  printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);

}

void bubblesort(int vetor[], int tam)
{
  clock_t inicio = clock(), fim;

  for (int x = tam; x > 1; x--)
  {
    for (int y = 0; y < x - 1; y++)
    {
      if (vetor[y] > vetor[y + 1])
      {
        int aux = vetor[y + 1];
        vetor[y + 1] = vetor[y];
        vetor[y] = aux;
      }
    }
  }

  fim = clock();
  double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
  printf("Tempo de ordenação: %.2f segundos\n", tempo);
}

void selectionsort(int vetor[], int tam)
{

  printf("\n--Começando a ordenação--\n\n");

  struct timeval inicio, fim;

  gettimeofday(&inicio, NULL);


  int i, j, posicaoMenor, menorValor;

  for (i = 0; i < tam - 1; i++)
  {
    posicaoMenor = i;
    for (j = i + 1; j < tam; j++)
    {
      if (vetor[j] < vetor[posicaoMenor])
      {
        posicaoMenor = j;
      }
    }
    // Troca o elemento atual com o menor elemento encontrado
    if (posicaoMenor != i)
    {
      menorValor = vetor[i];
      vetor[i] = vetor[posicaoMenor];
      vetor[posicaoMenor] = menorValor;
    }
  }

  gettimeofday(&fim, NULL);

  double tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;
  printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);

  //teste se a ordenação funcionou
  //imprimirVetor(vetor, 1000);
}

void shellsort(int vetor[], int tam)
{
  printf("\n--Começando a ordenação--\n\n");
  struct timeval inicio, fim;

  gettimeofday(&inicio, NULL);

  int h, i, j, aux;

  for (h = 1; h < tam; h = 3 * h + 1)
    ; // Inicialização do intervalo

  while (h > 0)
  {
    h = (h - 1) / 3; // Redução do intervalo

    for (i = h; i < tam; i++)
    {
      aux = vetor[i];
      j = i;
      while (j >= h && vetor[j - h] > aux)
      {
        vetor[j] = vetor[j - h];
        j -= h;
      }
      vetor[j] = aux;
    }
  }

  gettimeofday(&fim, NULL);

  double tempo = (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec) / 1000000.0;

  printf("Tempo de ordenação usando método gettime: %.7f segundos\n", tempo);

  // imprimirVetor(vetor, 5000);
}

////////////////////quicksort-Hoare//////////////////////////////

void trocar(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int particaoHoare(int *vetor, int inicio, int fim)
{
  int pivo = vetor[inicio];
  int esquerda = inicio - 1;
  int direita = fim + 1;

  while (1)
  {
    do
    {
      esquerda++;
    } while (vetor[esquerda] < pivo);

    do
    {
      direita--;
    } while (vetor[direita] > pivo);

    if (esquerda >= direita)
      return direita;

    trocar(&vetor[esquerda], &vetor[direita]);
  }
}

void quickSortHoare(int *vetor, int inicio, int fim)
{

  if (inicio < fim)
  {
    int indiceParticao = particaoHoare(vetor, inicio, fim);

    quickSortHoare(vetor, inicio, indiceParticao);
    quickSortHoare(vetor, indiceParticao + 1, fim);
  }
}

////////////////////////////////////////////////////////////////////

////////////////////quicksort-Lumuto////////////////////////////////

// a funcao de troca é a mesmo entao foi reutilizada do algoritmo hoare

int particaoLomuto(int vetor[], int inicio, int fim)
{
  int pivo = vetor[fim];
  int i = inicio - 1;

  for (int j = inicio; j <= fim - 1; j++)
  {
    if (vetor[j] < pivo)
    {
      i++;
      trocar(&vetor[i], &vetor[j]);
    }
  }

  trocar(&vetor[i + 1], &vetor[fim]);
  return i + 1;
}

void quickSortLomuto(int vetor[], int inicio, int fim)
{
  if (inicio < fim)
  {
    int indiceParticao = particaoLomuto(vetor, inicio, fim);

    quickSortLomuto(vetor, inicio, indiceParticao - 1);
    quickSortLomuto(vetor, indiceParticao + 1, fim);
  }
}

/////////////////////////////////////

void mergesort(int vetor[], int esq, int dir)
{

  // printf("d\n");
  if (esq < dir)
  {
    int meio = (esq + dir) / 2;
    mergesort(vetor, esq, meio);
    mergesort(vetor, meio + 1, dir);
    merge(vetor, esq, meio, dir);
  }
}

void merge(int vetor[], int esq, int meio, int dir)
{
  // printf("dsda\n");
  int auxSize = dir - esq + 1;
  int aux[auxSize];

  for (int i = esq; i <= dir; i++)
  {
    aux[i - esq] = vetor[i];
  }

  int i = esq;
  int j = meio + 1;
  int k = esq;

  while (i <= meio && j <= dir)
  {
    if (aux[i - esq] <= aux[j - esq])
    {
      vetor[k] = aux[i - esq];
      i++;
    }
    else
    {
      vetor[k] = aux[j - esq];
      j++;
    }
    k++;
  }

  while (i <= meio)
  {
    vetor[k] = aux[i - esq];
    i++;
    k++;
  }

  while (j <= dir)
  {
    vetor[k] = aux[j - esq];
    j++;
    k++;
  }
}

void radixsort(int vetor[], int TAM)
{
  int base = 10, r;
  int digit = 3;
  int *B = (int *)malloc(sizeof(int) * TAM);
  int *C = (int *)malloc(sizeof(int) * base);

  for (int m = 0; m < digit; m++)
  {
    for (int i = 0; i < base; ++i)
      C[i] = 0;

    for (int j = 0; j < TAM; ++j)
    {
      r = (vetor[j] / (int)pow(10.0, m)) % base;
      ++C[r];
    }

    for (int i = 1; i < base; ++i)
      C[i] += C[i - 1];

    for (int j = TAM - 1; j >= 0; --j)
    {
      r = (vetor[j] / (int)pow(10.0, m)) % base;
      int i = --C[r];
      B[i] = vetor[j];
    }

    for (int j = 0; j < TAM; ++j)
      vetor[j] = B[j];
  }

  free(B);
  free(C);
}

////////////////////////////////////////////////////////////////////

////////////////////Heap Sort////////////////////////////////

void heapify_down(int *array, int i, int tamanho)
{
  int maior = i;
  int esquerda = 2 * i + 1;
  int direita = 2 * i + 2;

  if (esquerda < tamanho && array[esquerda] > array[maior])
    maior = esquerda;

  if (direita < tamanho && array[direita] > array[maior])
    maior = direita;

  if (maior != i)
  {
    int temp = array[i];
    array[i] = array[maior];
    array[maior] = temp;
    heapify_down(array, maior, tamanho);
  }
}

void heapsort(int *array, int tamanho)
{
 
  for (int i = tamanho / 2 - 1; i >= 0; i--)
    heapify_down(array, i, tamanho);
  // Ordenação do array
  for (int i = tamanho - 1; i >= 0; i--)
  {
    int temp = array[0];
    array[0] = array[i];
    array[i] = temp;
    heapify_down(array, 0, i);
  }

}

/////////////////////////////////////////////////////////////////
//////////////////////---Funções--////////////////////////////

void imprimirVetor(int vetor[], int tam)
{

  for (int cont = 0; cont < tam; cont++)
  {
    printf("%d\t", vetor[cont]);
  }
  return;
}

//cria os arquivos aleatorios no começo do programa 
//para que todos os algoritmos tenham o mesmo
//conjuntio de dados

void CriarArquivosAleatorio()
{
  // cria todos os arquivos usados nos vetores aleatorios
  FILE *arquivo;
  srand(time(NULL));
  arquivo = fopen("1m_Aleatorio.txt", "w");
  for (int cont = 0; cont < 1000000; cont++)
  {
    int numero = rand() % 1000000;
    fprintf(arquivo, "%d\n", numero);
  }
  fclose(arquivo);

  srand(time(NULL));
  arquivo = fopen("500mil_Aleatorio.txt", "w");
  for (int cont = 0; cont < 500000; cont++)
  {
    int numero = rand() % 500000;
    fprintf(arquivo, "%d\n", numero);
  }
  fclose(arquivo);

  srand(time(NULL));
  arquivo = fopen("750mil_Aleatorio.txt", "w");
  for (int cont = 0; cont < 750000; cont++)
  {
    int numero = rand() % 750000;
    fprintf(arquivo, "%d\n", numero);
  }
  fclose(arquivo);
}

//limpa tela
void ll()
{
// funcao para limpar tela
#ifdef __linux__
  system("clear");
#elif _WIN32
  system("cls");
#else

#endif
}

//pausa tela
void p(double tempo)
{
#ifdef __linux__
  usleep((useconds_t)(tempo));
#elif _WIN32
  Sleep((DWORD)(tempo * 1000));
#else
#
#endif
}