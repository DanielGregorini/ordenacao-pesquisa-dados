#include "header.h"

#include "funcoes_de_ordenacao.c"

#include "funcoes_de_pesquisa.c"

#include "funcoes_criar_vetor1m.c"

#include "funcoes_criar_vetor500mil.c"

#include "funcoes_criar_vetor750mil.c"


#ifdef __linux__
    #include <unistd.h>
  #elif _WIN32
    #include <windows.h>
  #else
#endif