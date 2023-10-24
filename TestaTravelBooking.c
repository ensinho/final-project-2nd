#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// testa funções passageiro

/* 1 */
float teste_passageiro_novo() {
  float pontuacao;
  Passageiro *passageiro =
      passageiro_novo(2, "joao", "Av. Barao de Studart 505");

  if (passageiro != NULL) {
    printf("[Passou 1.00] - Teste da função passageiro_novo() com dados "
           "válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 0.00] - Teste da função passageiro_novo() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 2 */
float teste_passageiro_novo_dados_invalidos() {
  float pontuacao;
  Passageiro *passageiro = passageiro_novo(-2, 'c', '100');

  if (passageiro != NULL) {
    printf("[Falhou 0.00] - Teste da função passageiro_novo() com dados "
           "inválidos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função passageiro_novo() com dados "
           "inválidos!\n");
    pontuacao = 1.0;
  }
  return pontuacao;
}

/* 3 */
float teste_passageiro_novo_dados_nulos() {
  float pontuacao;
  Passageiro *passageiro = passageiro_novo(0, NULL, NULL);

  if (passageiro != NULL) {
    printf("[Falhou 0.00] - Teste da função passageiro_novo() com dados "
           "nulos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função passageiro_novo() com dados "
           "nulos!\n");
    pontuacao = 1.0;
  }
  return pontuacao;
}

/* 4*/
float teste_passageiro_libera() {
  float pontuacao = 0;
  Passageiro *passageiro =
      passageiro_novo(2, "Joao", "Av. Barão de Studart 505");

  passageiro_libera(&passageiro);

  if (passageiro != NULL) {
    printf("[Falhou 0.00] - Teste da função passageiro_libera com dados "
           "válidos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função passageiro_libera com dados "
           "válidos!\n");
    pontuacao = 1.0;
  }
  return pontuacao;
}

/* 5 */
float teste_passageiro_acessa() {
  float pontuacao = 0;
  int id;
  char *nome = (char *)malloc(50 * sizeof(char));
  char *endereco = (char *)malloc(100 * sizeof(char));

  Passageiro *passenger =
      passageiro_novo(1, "Alarico I", "Reino dos Visigodos, 382 d.C.");
  if (passenger != NULL) {
    passageiro_acessa(passenger, &id, nome, endereco);
    if (id == 1 && strcmp(nome, "Alarico I") == 0 &&
        strcmp(endereco, "Reino dos Visigodos, 382 d.C.") == 0) {
      printf("[Passou 1.00] - Teste da função passageiro_acessa() com dados "
             "válidos!\n");
      pontuacao = 1.0;
    } else {
      printf("[Falhou 0.00] - Teste da função passageiro_acessa()com dados "
             "válidos!\n");
    }
  } else {
    printf("[Falhou 0.00] - Teste da função passageiro_acessa() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 6 */
float teste_passageiro_edita() {
  float pontuacao = 0;
  int id;
  char *nome = (char *)malloc(50 * sizeof(char));
  char *endereco = (char *)malloc(100 * sizeof(char));
  Passageiro *passageiro =
      passageiro_novo(2, "Genserico", "R. 2º Rei dos Vândalos, 429 d.C.");

  if (passageiro != NULL) {
    passageiro_edita(passageiro, 5, "Trasamundo",
                     "R. 5º Rei dos Vândalos, 496 d.C.");
    passageiro_acessa(passageiro, &id, nome, endereco);
    if (id == 5 && strcmp(nome, "Trasamundo") == 0 &&
        strcmp(endereco, "R. 5º Rei dos Vândalos, 496 d.C.") == 0) {
      printf("[Passou 1.00] - Teste da função passageiro_edita() com dados "
             "válidos!\n");
      pontuacao = 1.00;
    } else {
      printf("[Falhou 0.00] - Teste da função passageiro_edita() com dados "
             "válidos!\n");
    }
  } else {
    printf("[Falhou 0.00] - Teste da função passageiro_edita() com dados "
           "válidos!\n");
  }

  return pontuacao;
}

/* Bateria de testes do Passageiro */
float bateria_testes_passageiro() {
  printf("====================================================================="
         "====================\n");
  printf(".:: Teste do TAD Passageiro: Bateria de Testes 01 ::.\n");
  printf("====================================================================="
         "====================\n");
  float pontuacao = 0;
  pontuacao = teste_passageiro_novo() +
              teste_passageiro_novo_dados_invalidos() +
              teste_passageiro_novo_dados_nulos() + teste_passageiro_libera() +
              teste_passageiro_acessa() + teste_passageiro_edita();
  printf("\nTotal: %.2f / de um max de: 6.00\n", pontuacao);
  printf("====================================================================="
         "====================\n\n");
  return pontuacao;
}

// testa funções lista_passageiro
/* 7 */
float testa_cria_lista_passageiro() {
  float pontuacao = 0;
  ListaPassageiro *listap = cria_lista_passageiro();
  if (listap != NULL) {
    printf("[Passou 1.00] - Teste da função cria_lista_passageiro() com dados "
           "válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 0.00] - Teste da função cria_lista_passageiro() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 8 */
float teste_lista_adiciona_passageiro() {
  float pontuacao = 0;
  ListaPassageiro *lista_p = cria_lista_passageiro();

  Passageiro *passageiro1 =
      passageiro_novo(1, "Thom Yorke", "R. Radiohead Ok Computer, 1997");
  Passageiro *passageiro2 =
      passageiro_novo(2, "Alex Turner", "R. Arctic Monkeys AM, 2013");
  Passageiro *passageiro3 =
      passageiro_novo(3, "Dexter Holland", "R. The Offspring Smash , 1994");

  int a = lista_adiciona_passageiro(lista_p, passageiro1);
  int b = lista_adiciona_passageiro(lista_p, passageiro2);
  int c = lista_adiciona_passageiro(lista_p, passageiro3);
  int d = lista_adiciona_passageiro(lista_p, passageiro3);

  if (a == 1 && b == 1 && c == 1 && d == 0) {
    printf("[Passou 1.00] - Teste da função lista_adiciona_passageiro() com "
           "dados válidos!\n");
    pontuacao = 1.00;
  } else {
    printf("[Falhou 0.00] - Teste da função lista_adiciona_passageiro() com "
           "dados válidos!\n");
  }

  return pontuacao;
}

/* 9 */
float teste_lista_adiciona_passageiro_invalidos_nulos() {
  float pontuacao = 0;
  ListaPassageiro *lista_p = cria_lista_passageiro();

  Passageiro *passageiro1 =
      passageiro_novo(1, "Thom Yorke", "R. Radiohead Ok Computer, 1997");
  Passageiro *passageiro2 =
      passageiro_novo(-2, "Alex Turner", "R. Arctic Monkeys AM, 2013");
  Passageiro *passageiro3 =
      passageiro_novo(3, "Dexter Holland", "R. The Offspring Smash , 1994");

  int a = lista_adiciona_passageiro(lista_p, passageiro1);
  int b = lista_adiciona_passageiro(lista_p, passageiro2);
  int c = lista_adiciona_passageiro(lista_p, NULL);
  int d = lista_adiciona_passageiro(lista_p, passageiro3);
  int e = lista_adiciona_passageiro(lista_p, passageiro3);

  if (a == 1 && b == -1 && c == -1 && d == 1 && e == 0) {
    printf("[Passou 1.00] - Teste da função lista_adiciona_passageiro() com "
           "dados inválidos e nulos!\n");
    pontuacao = 1.00;
  } else {
    printf("[Falhou 0.00] - Teste da função lista_adiciona_passageiro() com "
           "dados inválidos e nulos!\n");
  }

  return pontuacao;
}

/* 10 */
float teste_lista_busca_pass() {
  float pontuacao = 0.0;
  ListaPassageiro *lista_p = cria_lista_passageiro();

  Passageiro *passageiro1 = passageiro_novo(
      1, "David Gilmour", "R. Pink Floyd Dark side of the moon, 1973");
  Passageiro *passageiro2 =
      passageiro_novo(2, "Bon Scott", "R. AC/DC Highway to Hell, 1979");
  Passageiro *passageiro3 =
      passageiro_novo(3, "Igor Cavalera", "R. Sepultura Roots , 1996");

  int a = lista_adiciona_passageiro(lista_p, passageiro1);
  int b = lista_adiciona_passageiro(lista_p, passageiro2);
  int c = lista_adiciona_passageiro(lista_p, passageiro3);

  Passageiro *buscado = lista_busca_pass(lista_p, 2);
  int id;
  char *nome = (char *)malloc(50 * sizeof(char));
  char *endereco = (char *)malloc(100 * sizeof(char));
  passageiro_acessa(buscado, &id, nome, endereco);

  if (id == 2 && strcmp(nome, "Bon Scott") == 0 &&
      strcmp(endereco, "R. AC/DC Highway to Hell, 1979") == 0) {
    printf("[Passou 1.00] - Teste da função lista_busca_pass() com"
           " dados válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 1.00] - Teste da função lista_busca_pass() com"
           " dados válidos!\n");
  }

  return pontuacao;
}

/* 11 */

float teste_lista_busca_pass_invalidos_nulos() {
  float pontuacao = 0.0;
  ListaPassageiro *lista_p = cria_lista_passageiro();

  Passageiro *passageiro1 = passageiro_novo(
      1, "David Gilmour", "R. Pink Floyd Dark side of the moon, 1973");
  Passageiro *passageiro2 =
      passageiro_novo(2, "Bon Scott", "R. AC/DC Highway to Hell, 1979");

  int a = lista_adiciona_passageiro(lista_p, passageiro1);
  int b = lista_adiciona_passageiro(lista_p, passageiro2);

  Passageiro *buscado = lista_busca_pass(lista_p, -20);
  Passageiro *nulo = lista_busca_pass(NULL, 1);

  if (buscado == NULL && nulo == NULL) {
    printf("[Passou 1.50] - Teste da função lista_busca_pass() com"
           " dados inválidos e nulos!\n");
    pontuacao = 1.5;
  } else {
    printf("[Falhou 1.00] - Teste da função lista_busca_pass() com"
           " dados inválidos e nulos!\n");
  }

  return pontuacao;
}

/* 12 */
float teste_lista_remove_passageiro() {
  float pontuacao = 0;
  ListaPassageiro *lista_p = cria_lista_passageiro();
  Passageiro *passageiro1 =
      passageiro_novo(1, "Hayley Williams", "R. Paramored Paramore, 2013");
  Passageiro *passageiro2 =
      passageiro_novo(2, "Kurt Cobain", "R. Nirvana Nevermind, 1991");
  Passageiro *passageiro3 =
      passageiro_novo(3, "Roger Waters", "R. Pink Floyd The Wall , 1979");
  Passageiro *passageiro4 =
      passageiro_novo(4, "Tarja Turunen", "R. Nightwish Once , 2004");

  int a = lista_adiciona_passageiro(lista_p, passageiro1);
  int b = lista_adiciona_passageiro(lista_p, passageiro2);
  int c = lista_adiciona_passageiro(lista_p, passageiro3);
  int d = lista_adiciona_passageiro(lista_p, passageiro4);

  lista_remove_passageiro(lista_p, 2);

  if (lista_busca_pass(lista_p, 2) == NULL &&
      lista_busca_pass(lista_p, 1) != NULL &&
      lista_busca_pass(lista_p, 3) != NULL) {
    printf("[Passou 1.00] - Teste da função lista_remove_passageiro() com "
           "dados válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 1.00] - Teste da função lista_remove_passageiro() com "
           "dados válidos!\n");
  }

  return pontuacao;
}

/* 13 */
float teste_lista_top_pass() {
  float pontuacao = 0;
  ListaPassageiro *lista_p = cria_lista_passageiro();
  Passageiro *passageiro1 =
      passageiro_novo(1, "Hayley Williams", "R. Paramore Paramore, 2013");
  Passageiro *passageiro2 =
      passageiro_novo(2, "Kurt Cobain", "R. Nirvana Nevermind, 1991");
  Passageiro *passageiro3 =
      passageiro_novo(3, "Roger Waters", "R. Pink Floyd The Wall, 1979");

  int a1 = lista_adiciona_passageiro(lista_p, passageiro1);
  int a2 = lista_adiciona_passageiro(lista_p, passageiro2);
  int a3 = lista_adiciona_passageiro(lista_p, passageiro3);

  Passageiro *first = lista_top_pass(lista_p);

  int id;
  char *nome = (char *)malloc(50 * sizeof(char));
  char *endereco = (char *)malloc(100 * sizeof(char));
  passageiro_acessa(first, &id, nome, endereco);

  if (id == 3 && strcmp(nome, "Roger Waters") == 0 &&
      strcmp(endereco, "R. Pink Floyd The Wall, 1979") == 0) {
    pontuacao = 0.5;
  } else {
    pontuacao = 0;
  }

  lista_remove_passageiro(lista_p, 2);

  int d = lista_adiciona_passageiro(lista_p, passageiro2);
  lista_remove_passageiro(lista_p, 1);
  int e = lista_adiciona_passageiro(lista_p, passageiro1);

  Passageiro *primeiro2 = lista_top_pass(lista_p);
  int identifica;
  char *name = (char *)malloc(50 * sizeof(char));
  char *address = (char *)malloc(100 * sizeof(char));

  passageiro_acessa(primeiro2, &identifica, name, address);

  if (identifica == 1 && strcmp(name, "Hayley Williams") == 0 &&
      strcmp(address, "R. Paramore Paramore, 2013") == 0) {
    pontuacao = pontuacao + 0.5;
  } else {
    pontuacao = pontuacao + 0;
  }

  if (pontuacao == 1) {
    printf("[Passou 1.00] - Teste da função lista_top_pass() com "
           "dados válidos!\n");
  } else {
    printf("[Falhou 0.00] - Teste da função lista_top_pass() com "
           "dados válidos!\n");
  }

  return pontuacao;
}

float bateria_testes_lista_passageiro() {
  printf("====================================================================="
         "====================\n");
  printf(".:: Teste da Lista de Passageiro: Bateria de Testes 02 ::.\n");
  printf("====================================================================="
         "====================\n");
  float pontuacao = 0;
  pontuacao =
      testa_cria_lista_passageiro() + teste_lista_adiciona_passageiro() +
      teste_lista_adiciona_passageiro_invalidos_nulos() +
      teste_lista_busca_pass() + teste_lista_busca_pass_invalidos_nulos() +
      teste_lista_remove_passageiro() + teste_lista_top_pass();
  printf("\nTotal: %.2f / de um max de: 7.50\n", pontuacao);
  printf("====================================================================="
         "====================\n\n");
  return pontuacao;
}

// testa funções voo

/* 14 */
float teste_voo_cria() {
  float pontuacao;
  Voo *novo_voo = voo_cria(1, "Fortaleza", "Hogwarts");

  if (novo_voo != NULL) {
    printf("[Passou 1.00] - Teste da função voo_cria com dados "
           "válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 0.00] - Teste da função voo_cria() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 15 */
float teste_voo_novo_dados_invalidos() {
  float pontuacao;
  Voo *novo_voo = voo_cria(-2, 'c', '100');

  if (novo_voo != NULL) {
    printf(
        "[Falhou 0.00] - Teste da função voo_novo_dados_invalidos() com dados "
        "inválidos!\n");
  } else {
    printf(
        "[Passou 1.00] - Teste da função voo_novo_dados_invalidos() com dados "
        "inválidos!\n");
    pontuacao = 1.0;
  }
  return pontuacao;
}

/* 16 */
float teste_voo_novo_dados_nulos() {
  float pontuacao;
  Voo *voo = voo_cria(0, NULL, NULL);

  if (voo != NULL) {
    printf("[Falhou 0.00] - Teste da função voo_cria() com dados "
           "nulos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função voo_cria() com dados "
           "nulos!\n");
    pontuacao = 1.0;
  }
  return pontuacao;
}

/* 17 */
float teste_voo_libera() {
  float pontuacao = 0;
  Voo *voo = voo_cria(2, "Joao", "Av. Barão de Studart 505");

  voo_libera(&voo);

  if (voo != NULL) {
    printf("[Falhou 0.00] - Teste da função voo_libera com dados "
           "válidos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função voo_libera com dados "
           "válidos!\n");
    pontuacao = 1.0;
  }
  return pontuacao;
}

/* 18 */
float teste_voo_acessa() {
  float pontuacao = 0;
  int codigo;
  char *origem = (char *)malloc(50 * sizeof(char));
  char *destino = (char *)malloc(100 * sizeof(char));

  Voo *voor = voo_cria(1, "Alarico I", "Reino dos Visigodos, 382 d.C.");
  if (voor != NULL) {
    voo_acessa(voor, &codigo, origem, destino);
    if (codigo == 1 && strcmp(origem, "Alarico I") == 0 &&
        strcmp(destino, "Reino dos Visigodos, 382 d.C.") == 0) {
      printf("[Passou 1.00] - Teste da função voo_acessa() com dados "
             "válidos!\n");
      pontuacao = 1.0;
    } else {
      printf("[Falhou 0.00] - Teste da função voo_acessa()com dados "
             "válidos!\n");
    }
  } else {
    printf("[Falhou 0.00] - Teste da função voo_acessa() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 19 */

float teste_voo_edita() {
  float pontuacao = 0;
  int conteudo;
  char *origem = (char *)malloc(50 * sizeof(char));
  char *destino = (char *)malloc(100 * sizeof(char));
  Voo *voo = voo_cria(2, "Genserico", "R. 2º Rei dos Vândalos, 429 d.C.");

  if (voo != NULL) {
    voo_edita(voo, 5, "Trasamundo", "R. 5º Rei dos Vândalos, 496 d.C.");
    voo_acessa(voo, &conteudo, origem, destino);
    if (conteudo == 5 && strcmp(origem, "Trasamundo") == 0 &&
        strcmp(destino, "R. 5º Rei dos Vândalos, 496 d.C.") == 0) {
      printf("[Passou 1.00] - Teste da função voo_edita() com dados "
             "válidos!\n");
      pontuacao = 1.00;
    } else {
      printf("[Falhou 0.00] - Teste da função voo_edita() com dados "
             "válidos!\n");
    }
  } else {
    printf("[Falhou 0.00] - Teste da função voo_edita() com dados "
           "válidos!\n");
  }

  return pontuacao;
}

//-----------------

float bateria_testes_voo() {
  printf("====================================================================="
         "====================\n");
  printf(".:: Teste das funções Voo: Bateria de Testes 03 ::.\n");
  printf("====================================================================="
         "====================\n");
  float pontuacao = 0;
  pontuacao = teste_voo_cria() + teste_voo_novo_dados_invalidos() +
              teste_voo_novo_dados_nulos() + teste_voo_libera() +
              teste_voo_acessa() + teste_voo_edita();
  printf("\nTotal: %.2f / de um max de: 6.00\n", pontuacao);
  printf("====================================================================="
         "====================\n\n");
  return pontuacao;
}

// testa funções lista_voo

/* 20 */

float testa_cria_lista_voo() {
  float pontuacao = 0;
  ListaVoo *listap = cria_lista_voo();
  if (listap != NULL) {
    printf("[Passou 1.00] - Teste da função cria_lista_voo() com dados "
           "válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 0.00] - Teste da função cria_lista_voo() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 21 */
float teste_lista_adiciona_voo() {
  float pontuacao = 0;
  ListaVoo *lista_v = cria_lista_voo();

  Voo *voo1 = voo_cria(1, "Thom Yorke", "R. Radiohead Ok Computer, 1997");
  Voo *voo2 = voo_cria(2, "Alex Turner", "R. Arctic Monkeys AM, 2013");
  Voo *voo3 = voo_cria(3, "Dexter Holland", "R. The Offspring Smash , 1994");

  int a = lista_adiciona_voo(lista_v, voo1);
  int b = lista_adiciona_voo(lista_v, voo2);
  int c = lista_adiciona_voo(lista_v, voo3);

  if (a == 1 && b == 1 && c == 1) {
    printf("[Passou 1.00] - Teste da função lista_adiciona_voo() com "
           "dados válidos!\n");
    pontuacao = 1.00;
  } else {
    printf("[Falhou 0.00] - Teste da função lista_adiciona_voo() com "
           "dados válidos!\n");
  }
  return pontuacao;
}

/* 22 */

float teste_lista_adiciona_voo_invalidos_nulos() {
  float pontuacao = 0;
  ListaVoo *lista_p = cria_lista_voo();

  Voo *voo1 = voo_cria(1, "Thom Yorke", "R. Radiohead Ok Computer, 1997");
  Voo *voo2 = voo_cria(-2, "Alex Turner", "R. Arctic Monkeys AM, 2013");
  Voo *voo3 = voo_cria(3, "Dexter Holland", "R. The Offspring Smash , 1994");
  Voo *voo4 = NULL;

  int a = lista_adiciona_voo(lista_p, voo1); // ok
  int b = lista_adiciona_voo(lista_p, voo2); // Voo Nulo
  int c = lista_adiciona_voo(lista_p, voo3); // ok
  int d = lista_adiciona_voo(lista_p, voo4); // nulo
  int e = lista_adiciona_voo(lista_p, voo3); // repetido

  if (a == 1 && b == -1 && c == 1 && d == -1 && e == 0) {
    printf("[Passou 1.00] - Teste da função lista_adiciona_voo() com "
           "dados inválidos e nulos!\n");
    pontuacao = 1.00;
  } else {
    printf("[Falhou 0.00] - Teste da função lista_adiciona_voo() com "
           "dados inválidos e nulos!\n");
  }

  return pontuacao;
}

/* 23 */

float teste_lista_busca_voo() {
  float pontuacao = 0.0;
  ListaVoo *lista_p = cria_lista_voo();

  Voo *voo1 =
      voo_cria(1, "David Gilmour", "R. Pink Floyd Dark side of the moon, 1973");
  Voo *voo2 = voo_cria(2, "Bon Scott", "R. AC/DC Highway to Hell, 1979");
  Voo *voo3 = voo_cria(3, "Igor Cavalera", "R. Sepultura Roots , 1996");

  int a = lista_adiciona_voo(lista_p, voo1);
  int b = lista_adiciona_voo(lista_p, voo2);
  int c = lista_adiciona_voo(lista_p, voo3);

  Voo *buscado = lista_busca_voo(lista_p, 2);
  int conteudo;
  char *origem = (char *)malloc(50 * sizeof(char));
  char *destino = (char *)malloc(100 * sizeof(char));
  voo_acessa(buscado, &conteudo, origem, destino);

  if (conteudo == 2 && strcmp(origem, "Bon Scott") == 0 &&
      strcmp(destino, "R. AC/DC Highway to Hell, 1979") == 0) {
    printf("[Passou 1.00] - Teste da função lista_busca_voo() com"
           " dados válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 1.00] - Teste da função lista_busca_voo() com"
           " dados válidos!\n");
  }

  return pontuacao;
}

/* 24 */

float teste_lista_busca_voo_invalidos_nulos() {
  float pontuacao = 0.0;
  ListaVoo *lista_p = cria_lista_voo();

  Voo *voo1 =
      voo_cria(1, "David Gilmour", "R. Pink Floyd Dark side of the moon, 1973");
  Voo *voo2 = voo_cria(2, "Bon Scott", "R. AC/DC Highway to Hell, 1979");

  int a = lista_adiciona_voo(lista_p, voo1);
  int b = lista_adiciona_voo(lista_p, voo2);

  Voo *buscado = lista_busca_voo(lista_p, -20);
  Voo *nulo = lista_busca_voo(NULL, 1);

  if (buscado == NULL && nulo == NULL) {
    printf("[Passou 1.50] - Teste da função lista_busca_voo() com"
           " dados inválidos e nulos!\n");
    pontuacao = 1.5;
  } else {
    printf("[Falhou 1.00] - Teste da função lista_busca_voo() com"
           " dados inválidos e nulos!\n");
  }

  return pontuacao;
}

/* 25 */

float teste_lista_remove_voo() {
  float pontuacao = 0;
  ListaVoo *lista_p = cria_lista_voo();
  Voo *voo1 = voo_cria(1, "Hayley Williams", "R. Paramored Paramore, 2013");
  Voo *voo2 = voo_cria(2, "Kurt Cobain", "R. Nirvana Nevermind, 1991");
  Voo *voo3 = voo_cria(3, "Roger Waters", "R. Pink Floyd The Wall , 1979");
  Voo *voo4 = voo_cria(4, "Tarja Turunen", "R. Nightwish Once , 2004");

  int a = lista_adiciona_voo(lista_p, voo1);
  int b = lista_adiciona_voo(lista_p, voo2);
  int c = lista_adiciona_voo(lista_p, voo3);
  int d = lista_adiciona_voo(lista_p, voo4);

  lista_remove(lista_p, 2);

  if (lista_busca_voo(lista_p, 2) == NULL &&
      lista_busca_voo(lista_p, 1) != NULL &&
      lista_busca_voo(lista_p, 3) != NULL) {
    printf("[Passou 1.00] - Teste da função lista_remove_voo() com "
           "dados válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 1.00] - Teste da função lista_remove_voo() com "
           "dados válidos!\n");
  }

  return pontuacao;
}

///////
float bateria_testes_lista_voo() {
  printf("====================================================================="
         "====================\n");
  printf(".:: Teste da Lista Voos: Bateria de Testes 04 ::.\n");
  printf("====================================================================="
         "====================\n");
  float pontuacao = 0;
  pontuacao = 0;
  pontuacao =
      testa_cria_lista_voo() + teste_lista_adiciona_voo() +
      teste_lista_adiciona_voo_invalidos_nulos() + teste_lista_busca_voo() +
      teste_lista_busca_voo_invalidos_nulos() + teste_lista_remove_voo();
  printf("\nTotal: %.2f / de um max de: 6.5\n", pontuacao);
  printf("====================================================================="
         "====================\n\n");
  return pontuacao;
}

// testa funções reserva + abb

/* 26 */

// erro data > 2025 || data < 2001 alem das demais incorrecoes
// 0 - erro
// 1 - certo
float teste_valida_data() {
  float pontuacao = 0;
  int erro;
  erro = 0;
  if (valida_data2(1, 12, 2022) == 0) {
    erro = 1;
    printf("erro em valida_data,ano anterior ao atual\n");
  } else if (valida_data2(30, 2, 2023) == 1) {
    erro = 1;
    printf("erro em valida_data,fevereiro com 30 dias com ano valido\n");
  } else if (valida_data2(30, 13, 2023) == 1) {
    erro = 1;
    printf("erro em valida_data,mês que não existe com ano valido\n");
  } else if (valida_data2(29, 2, 2023) == 1) {
    erro = 1;
    printf("erro em valida_data,tudo igual a data atual\n");
  } else if (valida_data2(2, 1, 2023) == 0) {
    erro = 1;
    printf("erro em valida_data,erro em compara dia com mes e ano valido\n");
  } else if (valida_data2(1, 1, 2026) == 1) {
    erro = 1;
    printf("erro em valida_data,erro limite de ano ate 2025\n");
  } else {
    printf("[Passou 1.00] - Teste da função valida_data2() com dados válidos e "
           "inválidos!\n");
    pontuacao = 1;
  }

  return pontuacao;
}
// 27 //

float teste_acessa_data() {
  int dia, mes, ano;
  int dia2, mes2, ano2;
  dia = 29;
  mes = 4;
  ano = 2023;
  data_acessa(NULL, &dia, &mes, &ano);
  if (dia != -1 || mes != -1 || ano != -1) {
    printf("erro em teste_acessa_data, quando data é NULL\n");
    return 0;
  }
  Data *nova_data = (Data *)malloc(sizeof(Data *));
  data_acessa(nova_data, &dia2, &mes2, &ano2);
  if (dia == dia2 || mes == mes2 || ano == ano2) {
    printf("erro em teste_acessa_data, quando data tem valores\n");
    return 0;
  }
  printf("[Passou 1.00] - Teste da função data_acessa() com dados válidos!\n");
  return 1;
}

// 28 //
float teste_cria_data() {
  int dia, mes, ano;
  int dia2, mes2, ano2;
  dia = 29;
  mes = 4;
  ano = 2023;
  Data *nova_data = data_cria(dia, mes, ano);
  data_acessa(nova_data, &dia2, &mes2, &ano2);

  if (dia2 != dia) {
    printf("erro em teste_cria_data,em dia\n");
    return 0;
  }
  if (mes2 != mes) {
    printf("erro em teste_cria_data,em mes\n");
    return 0;
  }
  if (ano2 != ano) {
    printf("erro em teste_cria_data,em ano\n");
    return 0;
  }
  printf("[Passou 1.00] - Teste da função data_cria() com dados válidos!\n");
  return 1.0;
}

float teste_comparar_datas_validas() {
  float pontuacao = 0;
  Data *data1 = data_cria(20, 5, 2022);
  Data *data2 = data_cria(20, 5, 2022);

  int a = comparar_datas(data1, data2);
  if (a == 0) {
    pontuacao = 0.3;
    // printf("compara, 1 passou\n");
  }

  Data *data3 = data_cria(10, 6, 2023);
  Data *data4 = data_cria(20, 5, 2022);
  int b = comparar_datas(data3, data4);
  if (b == 1) {
    pontuacao = pontuacao + 0.3;
    // printf("compara, 2 passou\n");
  }

  Data *data5 = data_cria(10, 6, 2023);
  Data *data6 = data_cria(12, 2, 2024);
  int c = comparar_datas(data5, data6);
  if (c == -1) {
    pontuacao = pontuacao + 0.4;
    // printf("compara, 3 passou\n");
  }

  if (pontuacao == 1) {
    printf("[Passou 1.00] - Teste da função comparar_datas() com dados "
           "válidos!\n");
  } else {
    printf("[Falhou 0.00] - Teste da função comparar_datas() com dados "
           "válidos!\n");
  }

  return pontuacao;
}

float teste_chave_da_agenda() {
  float pontuacao = 0;
  Data *data10 = data_cria(17, 8, 2022);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl JaTen, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data10, passageiro1, voo1, A0);
  Agenda *agenda1 = cria_agenda_ABB(reserva1);

  Data *chave1 = chave_da_agenda(agenda1);
  int dia, mes, ano;
  int dia2, mes2, ano2;
  data_acessa(chave1, &dia, &mes, &ano);
  data_acessa(data10, &dia2, &mes2, &ano2);

  if (dia == dia2 && mes == mes2 && ano == ano2) {
    printf("[Passou 1.00] - Tudo certo em chave_da_agenda \n");
    pontuacao = 1;
  } else {
    printf("[Falhou 0.00] - Teste sem sentido: Tudo errado para "
           "chave_da_agenda()\n");
  }
  return pontuacao;
}

float teste_cria_reserva() {
  float pontuacao = 0;
  Data *data11 = data_cria(17, 8, 2022);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data11, passageiro1, voo1, A0);

  if (reserva1 != NULL) {
    printf("[Passou 1.00] - Passou em teste_cria_reserva com dados válidos!\n");
    pontuacao = 1;
  } else {
    printf("Erro em teste_cria_reserva() \n");
  }

  return pontuacao;
}

float teste_cria_reserva_com_dados_invalidos() {
  float pontuacao = 0;
  // codigo da reserva = -1
  Data *data15 = data_cria(17, 8, 2022);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(-1, data15, passageiro1, voo1, 0);

  if (reserva1 != NULL) {
    return pontuacao;
    printf("[Falhou 0.00] - Teste da função teste_cria_reserva com dados "
           "invalidos falhou com Código da Reserva\n");
  }

  // data = NULL
  Data *data2 = NULL;
  Assento segunddo = B0;
  Passageiro *passageiro2 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo2 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva2 = cria_reserva(0, data2, passageiro2, voo2, B0);

  if (reserva2 != NULL) {
    return pontuacao;
    printf("[Falhou 0.00] - Teste da função teste_cria_reserva com dados "
           "invalidos falhou com Data \n");
  }

  // passageiro = NULL
  Data *data3 = data_cria(17, 8, 2022);
  Assento terceiro = B0;
  Passageiro *passageiro3 = NULL;
  Voo *voo3 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva3 = cria_reserva(0, data3, passageiro3, voo3, B0);

  if (reserva3 != NULL) {
    printf("[Falhou 0.00] - Teste da função teste_cria_reserva com dados "
           "invalidos falhou com Passageiro \n");
    return pontuacao;
  }

  // voo = NULL
  Data *data4 = data_cria(17, 8, 2022);
  Assento quarto = C0;
  Passageiro *passageiro4 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo4 = NULL;
  Reserva *reserva4 = cria_reserva(0, data4, passageiro4, voo4, C0);

  if (reserva4 != NULL) {
    printf("[Falhou 0.00] - Teste da função teste_cria_reserva com dados "
           "invalidos falhou com Voo \n");
    return pontuacao;
  }

  // assento > 29
  Data *data5 = data_cria(17, 8, 2022);
  Assento quinto = A1;
  Passageiro *passageiro5 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo5 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva5 = cria_reserva(0, data5, passageiro5, voo5, 30);

  if (reserva5 != NULL) {
    printf("[Falhou 0.00] - Teste da função teste_cria_reserva com dados "
           "invalidos falhou com Assento \n");
    return pontuacao;
  }

  // assento < 0
  Data *data6 = data_cria(17, 8, 2022);
  Assento sexto = B1;
  Passageiro *passageiro6 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo6 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva6 = cria_reserva(0, data6, passageiro6, voo6, -1);

  if (reserva6 != NULL) {
    printf("[Falhou 0.00] - Teste da função teste_cria_reserva com dados "
           "invalidos falhou com Assento \n");
    return pontuacao;
  }

  printf("[Passou 1.00] - Passou em teste_cria_reserva_com_dados_invalidos\n");
  pontuacao = 1;
  return pontuacao;
}

float teste_cria_agenda_ABB() {
  float pontuacao = 0;
  Data *data11 = data_cria(17, 8, 2022);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data11, passageiro1, voo1, A0);
  Agenda *agenda = cria_agenda_ABB(reserva1);

  if (agenda != NULL) {
    printf("[Passou 1.00] - Teste da função cria_agenda_ABB() com dados "
           "válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 0.00] - Teste da função cria_agenda_ABB() com dados "
           "válidos!\n");
  }
  return pontuacao;
}

/* 27 */
// teste busca_agenda_data

float teste_busca_agenda_data() {
  float pontuacao = 0;
  Data *data14 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data14, passageiro1, voo1, A0);
  Agenda *agenda1 = cria_agenda_ABB(reserva1);

  Data *data_erro = data_cria(13, 5, 2024);

  Agenda *raiz = agenda1;
  Agenda *busca = busca_agenda_data(agenda1, data14);
  Agenda *busca2 = busca_agenda_data(agenda1, data_erro);

  if (busca == NULL && busca2 != NULL) {
    printf("[Falhou 0.00] - Teste da função busca_agenda_data() com dados "
           "válidos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função busca_agenda_data() com dados "
           "válidos!\n");
    pontuacao = 1;
  }

  return pontuacao;
}

/* 28 */

float teste_abb_insere_no_com_dados_validos() {
  float pontuacao = 0.0;

  // criar um nó na árvore
  Data *data14 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data14, passageiro1, voo1, A0);
  Agenda *agenda1 = cria_agenda_ABB(reserva1);

  // criar segundo nó
  Data *data20 = data_cria(27, 1, 2024);
  Assento segundo = B0;
  Passageiro *passageiro2 =
      passageiro_novo(2, "Greg Graffin", "R. The Gray Race, 1996");
  Voo *voo2 = voo_cria(2, "Belém", "Brasília");
  Reserva *reserva2 = cria_reserva(2, data20, passageiro2, voo2, B0);
  Agenda *agenda2 = cria_agenda_ABB(reserva2);

  // criar terceiro nó
  Data *data30 = data_cria(26, 1, 2023);
  Assento terceiro = C0;
  Passageiro *passageiro3 =
      passageiro_novo(3, "Billie Joe", "R. Green Day Dookie, 1994");
  Voo *voo3 = voo_cria(3, "Sobral", "Rio de Janeiro");
  Reserva *reserva3 = cria_reserva(3, data30, passageiro3, voo3, C0);
  Agenda *agenda3 = cria_agenda_ABB(reserva3);

  // criar quarto nó
  Data *data40 = data_cria(6, 3, 2023);
  Assento quarto = A1;
  Passageiro *passageiro4 =
      passageiro_novo(4, "Taylor Swift", "R. Midnights, 2022");
  Voo *voo4 = voo_cria(4, "Recife", "Salvador");
  Reserva *reserva4 = cria_reserva(4, data40, passageiro4, voo4, A1);
  Agenda *agenda4 = cria_agenda_ABB(reserva4);

  // criar quint nó
  Data *data50 = data_cria(3, 2, 2022);
  Assento quinto = B1;
  Passageiro *passageiro5 =
      passageiro_novo(5, "Ariana Grande", "R.Dangerous Woman, 2016");
  Voo *voo5 = voo_cria(5, "Palmas", "Manaus");
  Reserva *reserva5 = cria_reserva(5, data50, passageiro5, voo5, B1);
  Agenda *agenda5 = cria_agenda_ABB(reserva5);

  // criar arvore e adicionar nós
  Agenda *raiz = NULL;
  ////
  raiz = insere_agenda_ABB(raiz, agenda1);
  raiz = insere_agenda_ABB(raiz, agenda2);
  raiz = insere_agenda_ABB(raiz, agenda3);
  raiz = insere_agenda_ABB(raiz, agenda4);
  raiz = insere_agenda_ABB(raiz, agenda5);

  // testar os nós criados e adicionados
  if (comparar_datas(chave_da_agenda(busca_agenda_data(raiz, data14)),
                     data14) == 0 &&
      comparar_datas(chave_da_agenda(busca_agenda_data(raiz, data20)),
                     data20) == 0 &&
      comparar_datas(chave_da_agenda(busca_agenda_data(raiz, data30)),
                     data30) == 0 &&
      comparar_datas(chave_da_agenda(busca_agenda_data(raiz, data40)),
                     data40) == 0 &&
      comparar_datas(chave_da_agenda(busca_agenda_data(raiz, data50)),
                     data50) == 0) {
    printf("[Passou 1.00] - Teste da função abb_insere_no() com dados "
           "válidos!\n");
    pontuacao = 1.0;
  } else {
    printf("[Falhou 0.00] - Teste da função abb_insere_no() com dados"
           " válidos!\n");
    pontuacao = 0.0;
  }

  return pontuacao;
}

float teste_remover_reserva() {
  float pontuacao = 0;
  // criar um nó na árvore
  Data *data14 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data14, passageiro1, voo1, A0);
  Agenda *agenda1 = cria_agenda_ABB(reserva1);

  // criar segundo nó
  Data *data20 = data_cria(27, 1, 2024);
  Assento segundo = B0;
  Passageiro *passageiro2 =
      passageiro_novo(2, "Greg Graffin", "R. The Gray Race, 1996");
  Voo *voo2 = voo_cria(2, "Belém", "Brasília");
  Reserva *reserva2 = cria_reserva(2, data20, passageiro2, voo2, B0);
  Agenda *agenda2 = cria_agenda_ABB(reserva2);

  // criar terceiro nó
  Data *data30 = data_cria(26, 1, 2023);
  Assento terceiro = C0;
  Passageiro *passageiro3 =
      passageiro_novo(3, "Billie Joe", "R. Green Day Dookie, 1994");
  Voo *voo3 = voo_cria(3, "Sobral", "Rio de Janeiro");
  Reserva *reserva3 = cria_reserva(3, data30, passageiro3, voo3, C0);
  Agenda *agenda3 = cria_agenda_ABB(reserva3);

  // criar quarto nó
  Data *data40 = data_cria(6, 3, 2023);
  Assento quarto = A1;
  Passageiro *passageiro4 =
      passageiro_novo(4, "Taylor Swift", "R. Midnights, 2022");
  Voo *voo4 = voo_cria(4, "Recife", "Salvador");
  Reserva *reserva4 = cria_reserva(4, data40, passageiro4, voo4, A1);
  Agenda *agenda4 = cria_agenda_ABB(reserva4);

  // criar quint nó
  Data *data50 = data_cria(3, 2, 2022);
  Assento quinto = B1;
  Passageiro *passageiro5 =
      passageiro_novo(5, "Ariana Grande", "R.Dangerous Woman, 2016");
  Voo *voo5 = voo_cria(5, "Palmas", "Manaus");
  Reserva *reserva5 = cria_reserva(5, data50, passageiro5, voo5, B1);
  Agenda *agenda5 = cria_agenda_ABB(reserva5);

  // criar arvore e adicionar nós
  Agenda *raiz = NULL;

  raiz = insere_agenda_ABB(raiz, agenda1);
  raiz = insere_agenda_ABB(raiz, agenda2);
  raiz = insere_agenda_ABB(raiz, agenda3);
  raiz = insere_agenda_ABB(raiz, agenda4);
  raiz = insere_agenda_ABB(raiz, agenda5);

  // **************** REMOVENDO  NÓ COM 1 FILHO ***********
  raiz = remover_reserva(raiz, agenda3);

  //************************************************************************
  //***********************TESTE BUSCANDO AGENDA REMOVIDA ******************
  //************************************************************************
  Agenda *removida3 = busca_agenda_data(raiz, data30);

  if (removida3 == NULL) {
    pontuacao = pontuacao + 0.2;
  } else {
    printf("Algo errado remnove 3\n");
  }

  //***************** REMOVENDO RAIZ E 2 FILHOS ********************
  raiz = remover_reserva(raiz, agenda1);

  Agenda *removida1 = busca_agenda_data(raiz, data14);
  if (removida1 == NULL) {
    pontuacao = pontuacao + 0.2;
  } else {
    printf("Algo errado remnove 1\n");
  }

  //************* REMOVENDO NÓ FOLHA ************************
  raiz = remover_reserva(raiz, agenda4);

  Agenda *removida4 = busca_agenda_data(raiz, data40);
  if (removida4 == NULL) {
    pontuacao = pontuacao + 0.2;
  } else {
    printf("Algo errado remnove 4\n");
  }

  // ************** REMOVE NÓ COM 1 FILHO ************************
  raiz = remover_reserva(raiz, agenda2);

  Agenda *removida2 = busca_agenda_data(raiz, data20);
  if (removida2 == NULL) {
    pontuacao = pontuacao + 0.2;
  } else {
    printf("Algo errado remnove 2\n");
  }

  raiz = remover_reserva(raiz, agenda5);

  Agenda *removida5 = busca_agenda_data(raiz, data50);
  if (removida5 == NULL) {
    pontuacao = pontuacao + 0.2;
  } else {
    printf("Algo errado remnove 5\n");
  }

  if (pontuacao == 1) {
    printf("[Passou 1.00] - Teste da função remover_reserva() com dados "
           "válidos!\n");
  } else {
    printf("[Falhou 0.00] - Teste da função remover_reserva() com dados "
           "válidos!\n");
  }

  return pontuacao;
}

float teste_busca_id_codi_busca_data() {
  float pontuacao = 0;
  // criar um nó na árvore
  Data *data14 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data14, passageiro1, voo1, A0);
  Agenda *agenda1 = cria_agenda_ABB(reserva1);

  // criar segundo nó
  Data *data20 = data_cria(27, 1, 2024);
  Assento segundo = B0;
  Passageiro *passageiro2 =
      passageiro_novo(2, "Greg Graffin", "R. The Gray Race, 1996");
  Voo *voo2 = voo_cria(2, "Belém", "Brasília");
  Reserva *reserva2 = cria_reserva(2, data20, passageiro2, voo2, B0);
  Agenda *agenda2 = cria_agenda_ABB(reserva2);

  // criar terceiro nó
  Data *data30 = data_cria(26, 1, 2023);
  Assento terceiro = C0;
  Passageiro *passageiro3 =
      passageiro_novo(3, "Billie Joe", "R. Green Day Dookie, 1994");
  Voo *voo3 = voo_cria(3, "Sobral", "Rio de Janeiro");
  Reserva *reserva3 = cria_reserva(3, data30, passageiro3, voo3, C0);
  Agenda *agenda3 = cria_agenda_ABB(reserva3);

  // criar quarto nó
  Data *data40 = data_cria(6, 3, 2023);
  Assento quarto = A1;
  Passageiro *passageiro4 =
      passageiro_novo(4, "Taylor Swift", "R. Midnights, 2022");
  Voo *voo4 = voo_cria(4, "Recife", "Salvador");
  Reserva *reserva4 = cria_reserva(4, data40, passageiro4, voo4, A1);
  Agenda *agenda4 = cria_agenda_ABB(reserva4);

  // criar quint nó
  Data *data50 = data_cria(3, 2, 2022);
  Assento quinto = B1;
  Passageiro *passageiro5 =
      passageiro_novo(5, "Ariana Grande", "R.Dangerous Woman, 2016");
  Voo *voo5 = voo_cria(5, "Palmas", "Manaus");
  Reserva *reserva5 = cria_reserva(5, data50, passageiro5, voo5, B1);
  Agenda *agenda5 = cria_agenda_ABB(reserva5);

  // criar arvore e adicionar nós
  Agenda *raiz = NULL;
  ////
  raiz = insere_agenda_ABB(raiz, agenda1);
  raiz = insere_agenda_ABB(raiz, agenda2);
  raiz = insere_agenda_ABB(raiz, agenda3);
  raiz = insere_agenda_ABB(raiz, agenda4);
  raiz = insere_agenda_ABB(raiz, agenda5);

  // testar busca agenda id cod voo
  Agenda *agenda_buscada = busca_agenda_id_codi(raiz, 5, 5);
  Reserva *reserva = agenda_acessa(agenda_buscada);
  int dia, mes, ano, id, cod_voo, cod_reserva;
  Assento assento;
  reserva_acessa(reserva, &cod_reserva, &assento, &id, &cod_voo, &dia, &mes,
                 &ano);

  // testar busca_agenda_id_data
  Agenda *buscada2 = busca_agenda_id_data(raiz, data30, 3);
  Reserva *reserva200 = agenda_acessa(buscada2);
  int dia200, mes200, ano200, id200, cod_voo200, cod_reserva200;
  Assento assento200;
  reserva_acessa(reserva200, &cod_reserva200, &assento200, &id200, &cod_voo200,
                 &dia200, &mes200, &ano200);
  Data *data_busca200 = data_cria(dia200, mes200, ano200);

  // teste dos dados validos
  if ((id == 5 && cod_voo == 5) &&
      (comparar_datas(data30, data_busca200) == 0 && id200 == 3)) {
    printf("[Passou 0.50] - Teste da funções busca_agenda_id_datas() e "
           "busca_agenda_id_codi() com dados válidos!\n");
    pontuacao = pontuacao + 0.5;
  } else {
    printf("[Falhou 0.00] - Teste da funções busca_agenda_id_datas() e "
           "busca_agenda_id_codi() com dados válidos!\n");
  }
  raiz = remover_reserva(raiz, agenda3);
  raiz = remover_reserva(raiz, agenda1);

  // teste dos dados invalidos busca agenda id codi
  Agenda *agenda_buscada000 = busca_agenda_id_codi(raiz, 3, 3);
  Reserva *reserva000 = agenda_acessa(agenda_buscada);
  int dia000, mes000, ano000, id000, cod_voo000, cod_reserva000;
  Assento assento000;
  reserva_acessa(reserva, &cod_reserva000, &assento000, &id000, &cod_voo000,
                 &dia000, &mes000, &ano000);

  // testar busca_agenda_id_data invalidos
  Agenda *buscada002 = busca_agenda_id_data(raiz, data30, 3);
  Reserva *reserva002 = agenda_acessa(buscada002);
  int dia002, mes002, ano002, id002, cod_voo002, cod_reserva002;
  Assento assento002;
  reserva_acessa(reserva002, &cod_reserva002, &assento002, &id002, &cod_voo002,
                 &dia002, &mes002, &ano002);
  Data *data_busca002 = data_cria(dia002, mes002, ano002);

  if (agenda_buscada000 == NULL && id000 != 3 && cod_voo000 != 3 &&
      buscada002 == NULL && comparar_datas(data30, data_busca002) != 0) {
    printf("[Passou 0.50] - Teste da funções busca_agenda_id_datas() e "
           "busca_agenda_id_codi() com dados inválidos!\n");
    pontuacao = pontuacao + 0.5;
  } else {
    printf("algo deu errado\n");
  }

  raiz = remover_reserva(raiz, agenda4);
  raiz = remover_reserva(raiz, agenda2);

  return pontuacao;
}

float bateria_testes_arvore_reservas() {
  printf("====================================================================="
         "====================\n");
  printf(".:: Teste das Reservas: Bateria de Testes 05 - ABB ::.\n");
  printf("====================================================================="
         "====================\n");
  float pontuacao = 0;
  pontuacao = teste_valida_data() + teste_acessa_data() + teste_cria_data() +
              teste_comparar_datas_validas() + teste_cria_reserva() +
              teste_cria_reserva_com_dados_invalidos() +
              teste_cria_agenda_ABB() + teste_chave_da_agenda() +
              teste_abb_insere_no_com_dados_validos() +
              teste_busca_agenda_data() + teste_remover_reserva() +
              teste_busca_id_codi_busca_data();

  printf("\nTotal: %.2f / de um max de: 12.00\n", pontuacao);
  printf("====================================================================="
         "====================\n\n");
  return pontuacao;
}

// testa funções hash table

// Teste da função criar_recho
float teste_criar_trecho() {
  float pontuacao = 0;
  Data *data14 = data_cria(3, 1, 2023);
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Voo *voo1 = voo_cria(1, "Fortaleza", "São Paulo");
  Reserva *reserva1 = cria_reserva(1, data14, passageiro1, voo1, B2);
  Trecho *trecho1 = criar_trecho(1, reserva1);

  // print_reserva_trechos(trecho1);

  if (trecho1 == NULL) {
    printf("Falhou - trecho nulo \n");
  } else {
    printf("[Passou 1.00] - Teste da função criar_trecho() com"
           " dados válidos!\n");
    pontuacao = 1;
  }
  return pontuacao;
}

// Teste funçao auxiliar Conferir Passageiro
float teste_conferir_passageiro() {
  float pontuacao = 0;
  // criar passageiro + reserva
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Data *data1 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Voo *voo1 = voo_cria(1, "Fortaleza", "Sao Paulo");
  Reserva *reserva1 = cria_reserva(1, data1, passageiro1, voo1, A0);

  // segundo passageiro + reserva2
  Data *data20 = data_cria(27, 1, 2024);
  Assento segundo = B0;
  Passageiro *passageiro2 =
      passageiro_novo(2, "Greg Graffin", "R. The Gray Race, 1996");
  Voo *voo2 = voo_cria(2, "Belém", "Brasília");
  Reserva *reserva2 = cria_reserva(2, data20, passageiro2, voo2, B0);

  Trecho *trecho = criar_trecho(1, reserva1);

  int a = conferir_passageiro(trecho, reserva1); // dados válidos
  int b = conferir_passageiro(trecho, reserva2); // dados invalidos

  if (a == 1 && b == 0) {
    printf("[Passou 1.00] - Teste da função conferir_passageiro() com"
           " dados válidos e inválidos!\n");
    pontuacao = 1;
  } else {
    printf("falhou conferir passageiro\n");
  }

  return pontuacao;
}

// Teste funcao auxiliar Conferir Origem_Destino_Data
float teste_conferir_origem_destino_data() {
  float pontuacao = 0;
  // criar passageiro + reserva
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");
  Data *data1 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Voo *voo1 = voo_cria(1, "Fortaleza", "Sao Paulo");
  Reserva *reserva1 = cria_reserva(1, data1, passageiro1, voo1, A0);

  Trecho *trecho = criar_trecho(1, reserva1);

  // Segunda reserva do mesmo passageiro
  Data *data2 = data_cria(3, 2, 2023);
  Assento dois = A0;
  Voo *voo2 = voo_cria(1, "Sao Paulo", "Brasilia");
  Reserva *reserva2 = cria_reserva(2, data2, passageiro1, voo2, A0);

  int a = conferir_origem_destino_data(trecho, reserva2);

  if (a == 1) {
    printf("[Passou 1.00] - Teste da função conferir_origem_destino_data() com"
           " dados válidos!\n");
    pontuacao = 1;
  } else {
    printf("deu ruim o conferir destino-origem-data\n");
  }

  return pontuacao;
}

// int a = conferir_origem_destino_data(ListaTrechos, reserva);

// Teste inserir reserva em um trecho
float teste_inserir_reserva_trecho() {
  float pontuacao = 0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");

  // primeira reserva do passageiro Eddie Vedder
  Data *data1 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Voo *voo1 = voo_cria(1, "Fortaleza", "Sao Paulo");
  Reserva *reserva1 = cria_reserva(1, data1, passageiro1, voo1, A0);

  // Segunda reserva do mesmo passageiro
  Data *data2 = data_cria(3, 2, 2023);
  Assento dois = A0;
  Voo *voo2 = voo_cria(1, "Sao Paulo", "Brasilia");
  Reserva *reserva2 = cria_reserva(2, data2, passageiro1, voo2, A0);

  // terceira reserva do mesmo passageiro
  Data *data3 = data_cria(3, 3, 2023);
  Assento tres = A0;
  Voo *voo3 = voo_cria(1, "Brasilia", "Belem");
  Reserva *reserva3 = cria_reserva(3, data3, passageiro1, voo3, A0);

  Trecho *trecho = criar_trecho(1, reserva1);

  trecho = inserir_reserva_trecho(trecho, reserva2);
  trecho = inserir_reserva_trecho(trecho, reserva3);

  if (trecho != NULL) {
    printf("[Passou 1.00] - Teste da função inserir_reserva_trecho() com"
           " dados válidos!\n");
    pontuacao = 1;
  } else {
    printf("[Falhou 0.00] - Teste da função conferir_passageiro() com"
           " dados válidos!\n");
  }

  return pontuacao;
}

// Viagem *criar_viagem(Trecho *trecho)

float teste_criar_viagem() {
  float pontuacao = 0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");

  // primeira reserva do passageiro Eddie Vedder
  Data *data1 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Voo *voo1 = voo_cria(1, "Fortaleza", "Sao Paulo");
  Reserva *reserva1 = cria_reserva(1, data1, passageiro1, voo1, A0);
  Trecho *trecho = criar_trecho(1, reserva1);
  Viagem *viagem = criar_viagem(trecho);

  if (viagem != NULL) {
    printf("[Passou 1.00] - Teste da função criar_viagem() com"
           " dados válidos!\n");
    pontuacao = 1;
  } else {
    printf("[Falhou 0.00] - Teste da função criar_viagem() com"
           " dados válidos!\n");

    return pontuacao;
  }
}

// teste criar tabela_hash
float teste_criar_tabela_hash() {
  float pontuacao = 0;
  TabelaViagem *tabela_viagem = criar_tabela_hash(15);

  int oi = tabela_acessa(tabela_viagem);

  if (tabela_viagem == NULL) {
    printf("[Falhou 0.00] - Teste da função criar_tabela_hash() com"
           " dados válidos!\n");
  } else {
    printf("[Passou 1.00] - Teste da função criar_tabela_hash() com"
           " dados válidos!\n");
    pontuacao = 1;
  }

  return pontuacao;
}

// teste criar hash
float teste_criar_hash() {
  float pontuacao = 0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");

  // primeira reserva do passageiro Eddie Vedder
  Data *data1 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Voo *voo1 = voo_cria(1, "Fortaleza", "Sao Paulo");
  Reserva *reserva1 = cria_reserva(1, data1, passageiro1, voo1, A0);
  Trecho *trecho = criar_trecho(1, reserva1);
  Viagem *viagem = criar_viagem(trecho);

  TabelaViagem *tabela_viagem = criar_tabela_hash(15);
  int oi = tabela_acessa(tabela_viagem);

  unsigned int a = hash(viagem, tabela_viagem);

  if (a == 0) {
    printf("[Passou 1.00] - Teste da função criar_hash() com"
           " dados válidos!\n");
    pontuacao = 1;
  } else {
    printf("[Falhou 0.00] - Teste da função criar_hash() com"
           " dados válidos!\n");
  }

  return pontuacao;
}

// teste inserir viagem

float teste_inserir_viagem_hash() {
  float pontuacao = 0;
  Passageiro *passageiro1 =
      passageiro_novo(1, "Eddie Vedder", "R. Pearl Jam Ten, 1991");

  // primeira reserva do passageiro Eddie Vedder
  Data *data1 = data_cria(3, 1, 2023);
  Assento primeiro = A0;
  Voo *voo1 = voo_cria(1, "Fortaleza", "Sao Paulo");
  Reserva *reserva1 = cria_reserva(1, data1, passageiro1, voo1, A0);
  Trecho *trecho = criar_trecho(1, reserva1);
  Viagem *viagem = criar_viagem(trecho);
  TabelaViagem *tabela_viagem = criar_tabela_hash(15);

  int a = inserir_viagem(viagem, tabela_viagem);

  if (a == 1) {
    printf("[Passou 1.00] - Teste da função inserir_viagem() com"
           " dados válidos!\n");
    pontuacao = 1;
  } else {
    printf("[Falhou 1.00] - Teste da função inserir_viagem() com"
           " dados válidos!\n");
  }

  return pontuacao;
}

float bateria_testes_tabela_hash() {
  printf("====================================================================="
         "====================\n");
  printf(".:: Teste das Reservas: Bateria de Testes - 06 - Tabela Hash ::.\n");
  printf("====================================================================="
         "====================\n");
  float pontuacao = 0;
  pontuacao = teste_criar_trecho() + teste_conferir_passageiro() +
              teste_conferir_origem_destino_data() +
              teste_inserir_reserva_trecho() + teste_criar_viagem() +
              teste_criar_tabela_hash() + teste_criar_hash() +
              teste_inserir_viagem_hash();

  printf("\nTotal: %.2f / de um max de: 7.00\n", pontuacao);
  printf("====================================================================="
         "====================\n\n");
  return pontuacao;
}

int main(void) {

  bateria_testes_passageiro();
  bateria_testes_lista_passageiro();
  bateria_testes_voo();
  bateria_testes_lista_voo();
  bateria_testes_arvore_reservas();
  bateria_testes_tabela_hash();

  return 0;
}
