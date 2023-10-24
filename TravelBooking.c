#include "TravelBooking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
  int dia;
  int mes;
  int ano;
};

struct voo {
  int codigo;
  char *origem;
  char *destino;
};

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo {
  struct no_voo *primeiro;
};

struct passageiro {
  int id;
  char *nome;
  char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
};

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};

//>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DO PASSAGEIRO <<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<

/* 1 */ // CRIA PASSAGEIRO NOVO
// aloca espaço para um passageiro
// nome com até 50 caracteres
// edereço com ate 100 caracteres
Passageiro *passageiro_novo(int id, char *nome, char *endereco) {
  if (id < 0 || nome == NULL || endereco == NULL) {
    return NULL;
  } else if (id < 0 || strlen(nome) > 50 || strlen(endereco) > 100) {
    return NULL;
  }

  Passageiro *novo_passageiro = (Passageiro *)malloc(sizeof(Passageiro));
  novo_passageiro->nome = (char *)malloc(50 * sizeof(char));
  novo_passageiro->endereco = (char *)malloc(100 * sizeof(char));

  novo_passageiro->id = id;
  strcpy(novo_passageiro->nome, nome);
  strcpy(novo_passageiro->endereco, endereco);

  return novo_passageiro;
}

/* 2 */ // LIBERA ESPAÇO DE UM PASSAGEIRO  #####
void passageiro_libera(Passageiro **passageiro) {
  if (passageiro != NULL) {
    free(*passageiro);
    *passageiro = NULL;
  }
}

/* 3 */ // ACESSA OS VALORES DOS CAMPOS DE UM PASSAGEIRO
void passageiro_acessa(Passageiro *passageiro, int *id, char *nome,
                       char *endereco) {
  if (passageiro == NULL) {
    *id = -1;
    strcpy(nome, "NULL");
    strcpy(endereco, "NULL");
  } else {
    *id = passageiro->id;
    strcpy(nome, passageiro->nome);
    strcpy(endereco, passageiro->endereco);
  }
}

/* 4 */ // EDITA AS INFORMAÇÕES DE UM PASSAGEIRO EXISTENTE
void passageiro_edita(Passageiro *passageiro, int id, char *nome,
                      char *endereco) {
  if (passageiro != NULL) {
    passageiro->id = id;

    strcpy(passageiro->nome, nome);
    strcpy(passageiro->endereco, endereco);
  }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA LISTA DE PASSAGEIROS <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Aloca espaço para uma lista de passageiros
/* 5 */ // CRIA LISTA DE PASSAGEIROS
ListaPassageiro *cria_lista_passageiro() {
  ListaPassageiro *lista_passageiro =
      (ListaPassageiro *)malloc(sizeof(ListaPassageiro));

  lista_passageiro->primeiro = NULL;

  return lista_passageiro;
}

// retorna -1 se lista null ou passageiro null
// retorna  0 se passageiro repetido
// retorna  1 se possivel adicionar
/* 6 */ // Adiciona passageiro à lista
int lista_adiciona_passageiro(ListaPassageiro *lista_pass,
                              Passageiro *passageiro) {

  if (lista_pass == NULL || passageiro == NULL) {
    return -1;
  }

  int id_aux;
  char *nome = (char *)malloc(50 * sizeof(char));
  char *endereco = (char *)malloc(100 * sizeof(char));

  passageiro_acessa(passageiro, &id_aux, nome, endereco);
  Passageiro *passageiro_aux = lista_busca_pass(lista_pass, id_aux);
  if (passageiro_aux != NULL) {
    return 0;
  }

  NoPassageiro *novo = (NoPassageiro *)malloc(sizeof(NoPassageiro *));
  novo->passageiro = passageiro;

  if (lista_pass->primeiro == NULL) {
    lista_pass->primeiro = novo;
    novo->proximo = NULL;
  } else {
    novo->proximo = lista_pass->primeiro;
  }
  lista_pass->primeiro = novo;

  return 1;
}

/* 7 */ // Retira passageiro da lista (ok)
Passageiro *lista_remove_passageiro(ListaPassageiro *lista_pass, int id) {
  if (lista_pass == NULL) {
    return NULL;
  }

  int id_aux;
  char nome[50];
  char endereco[100];
  NoPassageiro *anterior = lista_pass->primeiro;

  for (NoPassageiro *aux = lista_pass->primeiro; aux != NULL;
       aux = aux->proximo) {
    passageiro_acessa(aux->passageiro, &id_aux, nome, endereco);
    if (id_aux == id) {
      if (aux == lista_pass->primeiro) {
        lista_pass->primeiro = aux->proximo;
      }
      anterior->proximo = aux->proximo;
      aux->proximo = NULL;
      return aux->passageiro;
    }

    anterior = aux;
  }

  return NULL;
}

/* 8 */ // RETORNA O PRIMEIRO PASSAGEIRO #####
Passageiro *lista_top_pass(ListaPassageiro *lista_pass) {
  NoPassageiro *primeiroNo = lista_pass->primeiro;
  Passageiro *primeiro_p = primeiroNo->passageiro;
  return primeiro_p;
};

/* 9 */ // BUSCA UM PASSAGEIRO POR SEU ID
Passageiro *lista_busca_pass(ListaPassageiro *lista_pass, int id) {
  if (lista_pass != NULL && lista_pass->primeiro != NULL) {

    int id_aux;
    char *nome_aux = (char *)malloc(50 * sizeof(char));
    char *endereco_aux = (char *)malloc(100 * sizeof(char));
    NoPassageiro *aux = lista_pass->primeiro;

    do {
      passageiro_acessa(aux->passageiro, &id_aux, nome_aux, endereco_aux);
      if (id_aux == id) {
        return aux->passageiro;
      }
      aux = aux->proximo;
    } while (aux != NULL);
  }
  return NULL;
}

// função axiliar pra imprimir a lista e ajudar a debugar
// passar a lista como parâmetro, imprime tdos os dados de todos os passageiros
// em ordem
/* 10 */ // IMPRIME LISTA DE PASSAGEIROS
void imprimir_lista_passageiros(ListaPassageiro *lista_pass) {
  if (lista_pass != NULL) {

    NoPassageiro *aux = lista_pass->primeiro;

    int id_aux;
    char *nome_aux = (char *)malloc(50 * sizeof(char));
    char *endereco_aux = (char *)malloc(100 * sizeof(char));
    int i = 1;

    do {
      passageiro_acessa(aux->passageiro, &id_aux, nome_aux, endereco_aux);
      printf("passageiro [%d]: ID:%d NOME: %s ENDEREÇO: %s\n", i, id_aux,
             nome_aux, endereco_aux);

      aux = aux->proximo;
      i++;

    } while (aux != NULL);
  }
}

//>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DO VOO <<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<

// aloca espaço para um voo
// retorna NULL se um dos parâmetros é inválido
/* 11 */ // CRIA VOO NOVO
Voo *voo_cria(int codigo, char *origem, char *destino) {
  if (codigo < 0 || origem == NULL || destino == NULL) {
    return NULL;
  }
  Voo *novo_voo = (Voo *)malloc(sizeof(Voo));
  novo_voo->origem = (char *)malloc(50 * sizeof(char));
  novo_voo->destino = (char *)malloc(50 * sizeof(char));

  novo_voo->codigo = codigo;
  strcpy(novo_voo->origem, origem);
  strcpy(novo_voo->destino, destino);

  return novo_voo;
}

/* 12 */ // LIBERA ESPAÇO DE UM VOO
void voo_libera(Voo **voo) {
  if (voo != NULL) {
    free(*voo);
    *voo = NULL;
  }
}

/* 13 */ // ACESSA OS VALORES DOS CAMPOS DE UM VOO
void voo_acessa(Voo *voo, int *codigo, char *origem, char *destino) {
  if (voo == NULL) {
    *codigo = -1;
    strcpy(origem, "NULL");
    strcpy(destino, "NULL");
  } else {
    *codigo = voo->codigo;
    strcpy(origem, voo->origem);
    strcpy(destino, voo->destino);
  }
}

/* 14 */ // EDITA OS VALORES DE UM VOO EXISTENTE
void voo_edita(Voo *voo, int codigo, char *origem, char *destino) {
  if (voo != NULL) {
    voo->codigo = codigo;

    strcpy(voo->origem, origem);
    strcpy(voo->destino, destino);
  }
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA LISTA DE VOOS <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

/* 15 */ // alloca espaço para a lista de voos
ListaVoo *cria_lista_voo() {
  ListaVoo *lista_voo = (ListaVoo *)malloc(sizeof(ListaVoo));

  lista_voo->primeiro = NULL;

  return lista_voo;
}

// retorna -1 se a lista é vazia ou voo é NULL
// retorna 1 se for possivel adiciona
// retorna 0 se Voo ja existe na lista
/* 16 */ // ADICIONA VOO
int lista_adiciona_voo(ListaVoo *lista_voo, Voo *voo) {
  if (lista_voo == NULL || voo == NULL) {
    return -1;
  }

  int codigo_aux;
  char *origem = (char *)malloc(50 * sizeof(char));
  char *destino = (char *)malloc(100 * sizeof(char));

  voo_acessa(voo, &codigo_aux, origem, destino);
  Voo *voo_aux = lista_busca_voo(lista_voo, codigo_aux);
  if (voo_aux != NULL) {
    return 0;
  }

  NoVoo *novo = (NoVoo *)malloc(sizeof(NoVoo *));
  novo->voo = voo;

  if (lista_voo->primeiro == NULL) {
    lista_voo->primeiro = novo;
    novo->proximo = NULL;

  } else {
    novo->proximo = lista_voo->primeiro;
  }

  lista_voo->primeiro = novo;

  return 1;
}

// retorna NULL
/* 17 */ // REMOVE UM VOO PELO CODIGO
Voo *lista_remove(ListaVoo *lista_voo, int codigo) {
  if (lista_voo == NULL) {
    return NULL;
  }

  int cod_aux;
  char origem[50];
  char destino[50];
  NoVoo *anterior = lista_voo->primeiro;

  for (NoVoo *aux = lista_voo->primeiro; aux != NULL; aux = aux->proximo) {
    voo_acessa(aux->voo, &cod_aux, origem, destino);
    if (cod_aux == codigo) {
      if (aux == lista_voo->primeiro) {
        lista_voo->primeiro = aux->proximo;
      }
      anterior->proximo = aux->proximo;
      aux->proximo = NULL;
      return aux->voo;
    }

    anterior = aux;
  }

  return NULL;
}

/* 18 */ // retorna o último voo adicionado #########
Voo *lista_top_voo(ListaVoo *lista_voo) {
  NoVoo *primeiroNo = lista_voo->primeiro;
  Voo *primeiro_v = primeiroNo->voo;
  return primeiro_v;
};

/* 19 */ // BUSCA UM VOO ESPECIFICO PELO CODIGO
Voo *lista_busca_voo(ListaVoo *lista_voo, int codigo) {
  if (lista_voo != NULL && lista_voo->primeiro != NULL) {

    int cod_aux;
    char *origem_aux = (char *)malloc(50 * sizeof(char));

    char *destino_aux = (char *)malloc(100 * sizeof(char));

    NoVoo *aux = lista_voo->primeiro;
    do {
      voo_acessa(aux->voo, &cod_aux, origem_aux, destino_aux);
      if (cod_aux == codigo) {
        return aux->voo;
      }
      aux = aux->proximo;
    } while (aux != NULL);
  }
  return NULL;
}

/* 20 */ // IMPRIME LISTA DE VOOS
void imprimir_lista_Voos(ListaVoo *lista_voo) {
  if (lista_voo != NULL) {

    NoVoo *aux = lista_voo->primeiro;

    int codigo_aux;
    char *origem_aux = (char *)malloc(50 * sizeof(char));
    char *destino_aux = (char *)malloc(100 * sizeof(char));
    int i = 1;

    do {
      voo_acessa(aux->voo, &codigo_aux, origem_aux, destino_aux);
      printf("Voo [%d]: CODIGO:%d ORIGEM: %s DESTINO: %s\n", i, codigo_aux,
             origem_aux, destino_aux);

      aux = aux->proximo;
      i++;

    } while (aux != NULL);
  }
}

//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA RESERVA <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<

// se a data estiver errada, retorna NULL
// senao retorna a data crada
/* 21 */
Data *data_cria(int dia, int mes, int ano) {
  if (valida_data2(dia, mes, ano) == 0) {
    return NULL;
  }

  Data *nova_data = (Data *)malloc(sizeof(Data *));
  nova_data->dia = dia;
  nova_data->mes = mes;
  nova_data->ano = ano;

  return nova_data;
}

// Data acessa
void data_acessa(Data *data, int *dia, int *mes, int *ano) {
  if (data == NULL) {
    *dia = -1;
    *mes = -1;
    *ano = -1;
  } else {
    *dia = data->dia;
    *mes = data->mes;
    *ano = data->ano;
  }
}

// Reserva_acessa
void reserva_acessa(Reserva *reserva, int *cod_reserva, Assento *assento,
                    int *id, int *cod_voo, int *dia, int *mes, int *ano) {
  if (reserva != NULL) {
    char nome[50];
    char endereco[100];
    passageiro_acessa(reserva->passageiro, id, nome, endereco);

    char origem[50];
    char destino[50];
    voo_acessa(reserva->voo, cod_voo, origem, destino);

    *cod_reserva = reserva->codigo;
    *assento = reserva->assento;

    if (reserva->data_viagem == NULL) {
      *dia = -1;
      *mes = -1;
      *ano = -1;
    } else {
      *dia = (reserva->data_viagem)->dia;
      *mes = (reserva->data_viagem)->mes;
      *ano = (reserva->data_viagem)->ano;
    }
  }
}

void reserva_acessa_total(Reserva *reserva, int *cod_reserva, Assento *assento,
                          int *id_p, int *cod_voo, int *dia, int *mes, int *ano,
                          Passageiro *passageiro, Voo *voo) {

  if (reserva != NULL) {
    char nome[50];
    char endereco[100];
    passageiro_acessa(reserva->passageiro, id_p, nome, endereco);
    passageiro = passageiro_novo(*id_p, nome, endereco);

    char origem[50];
    char destino[50];
    voo_acessa(reserva->voo, cod_voo, origem, destino);
    voo = voo_cria(*cod_voo, origem, destino);

    *cod_reserva = reserva->codigo;
    *assento = reserva->assento;

    if (reserva->data_viagem == NULL) {
      *dia = -1;
      *mes = -1;
      *ano = -1;
    } else {
      *dia = (reserva->data_viagem)->dia;
      *mes = (reserva->data_viagem)->mes;
      *ano = (reserva->data_viagem)->ano;
    }
  }
}

// Comparar datas
// -1 = d1 < d2 = d1 mais antiga
// 1  = d1 > d2 = d1 mais recente
// 0 = d1 == d2 = datas iguais
int comparar_datas(Data *data1, Data *data2) { // teste ok
  int d1ano, d2ano, d1mes, d2mes, d1dia, d2dia;
  data_acessa(data1, &d1dia, &d1mes, &d1ano);
  data_acessa(data2, &d2dia, &d2mes, &d2ano);

  if (d1ano < d2ano) {
    return -1;
  }
  if (d1ano == d2ano) {
    if (d1mes < d2mes) {
      return -1;
    } else if (d1mes > d2mes) {
      return 1;
    } else /*iguais*/ {
      if (d1dia == d2dia) {
        return 0;
      } else if (d1dia > d2dia) {
        return 1;
      } else {
        return -1;
      }
    }
  }
  return 1;
}

// errado = 0
// certo = 1
int valida_data2(int dia, int mes, int ano) {
  if (ano > 2025 || ano < 2001) {
    return 0;
  }

  if (mes > 12 || mes < 1) {
    return 0;
  }

  if (dia > 31 || dia < 1) {
    return 0;
  }

  // anos bissextos = 2004, 2008, 2012, 2016, 2020, 2024
  enum meses {
    janeiro = 1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
  } mes_valido;

  if (dia > 28 && dia != 29) {
    if (mes == fevereiro) {
      return 0;
    }
  }

  if (dia == 29) {
    if (mes == fevereiro) {
      if (ano != 2004 || ano != 2008 || ano != 2012 || ano != 2016 ||
          ano != 2020 || ano != 2024) {
        return 0;
      } else {
        return 1;
      }
    }
  }

  if (dia == 31) {
    if (mes == fevereiro || mes == abril || mes == junho || mes == setembro ||
        mes == novembro) {
      return 0;
    } else {
      return 1;
    }
  }
  return 1;
}

Reserva *cria_reserva(int codigo, Data *data_viagem, Passageiro *passageiro,
                      Voo *voo, Assento assento) {

  if (codigo < 0 || data_viagem == NULL || passageiro == NULL || voo == NULL ||
      assento > 29 || assento < 0) {
    return NULL;
  }

  if (voo == NULL) {
    return NULL;
  }
  // verifica se a data está de acordo com o requerido
  if (valida_data2(data_viagem->dia, data_viagem->mes, data_viagem->ano) == 0) {
    return NULL;
  }

  Reserva *nova_reserva = (Reserva *)malloc(sizeof(Reserva));

  nova_reserva->codigo = codigo;
  nova_reserva->data_viagem = data_viagem;
  nova_reserva->passageiro = passageiro;
  nova_reserva->voo = voo;
  nova_reserva->assento = assento;

  return nova_reserva;
}

//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA ARVORE <<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Cria agenda = raiz (cria a arvore)
// Cria No da árvore, cada nó é uma agenda com um campo tipo Reserva e dois
// campos do tipo Agenda
Agenda *cria_agenda_ABB(Reserva *reserva) {
  if (reserva == NULL) {
    return NULL;
  }

  Agenda *agenda = (Agenda *)malloc(sizeof(Agenda *));

  agenda->reserva = reserva;
  agenda->esq = NULL;
  agenda->dir = NULL;

  return agenda;
}

// Insere no
Agenda *insere_agenda_ABB(Agenda *raiz, Agenda *agenda) {
  if (raiz == NULL && agenda == NULL) {
    return NULL;
  }

  if (raiz == NULL) {
    return agenda;
  }

  Data *chave_raiz = chave_da_agenda(raiz);
  Data *chave_agenda = chave_da_agenda(agenda);

  if (busca_agenda_data(raiz, chave_agenda) == NULL) {
    if (comparar_datas(chave_agenda, chave_raiz) <= 0) {
      raiz->esq = insere_agenda_ABB(raiz->esq, agenda);
    } else {
      raiz->dir = insere_agenda_ABB(raiz->dir, agenda);
    }
    return raiz;
  } else {
    return NULL;
  }
}

// Chave da arvore
Data *chave_da_agenda(Agenda *agenda) {
  if (agenda == NULL) {
    return NULL;
  }

  Reserva *reserva = agenda->reserva;
  int cod_reserva, id, cod_voo, dia, mes, ano;
  Assento assento;
  reserva_acessa(reserva, &cod_reserva, &assento, &id, &cod_voo, &dia, &mes,
                 &ano);

  Data *chave = data_cria(dia, mes, ano);
  return chave;
}

void EmOrdem(Agenda *raiz) {
  if (raiz == NULL)
    return;
  else {
    EmOrdem(raiz->esq);
    int dia, mes, ano;
    data_acessa((raiz->reserva)->data_viagem, &dia, &mes, &ano);
    printf("%d/%d/%d\n", dia, mes, ano);
    EmOrdem(raiz->dir);
  }
}

void PreOrdem(Agenda *raiz) {
  if (raiz == NULL)
    return;
  else {
    int dia, mes, ano;
    data_acessa((raiz->reserva)->data_viagem, &dia, &mes, &ano);
    printf("%d/%d/%d\n", dia, mes, ano);
    PreOrdem(raiz->esq);
    PreOrdem(raiz->dir);
  }
}

void PosOrdem(Agenda *raiz) {
  if (raiz == NULL)
    return;
  else {
    PosOrdem(raiz->esq);
    PosOrdem(raiz->dir);
    int dia, mes, ano;
    data_acessa((raiz->reserva)->data_viagem, &dia, &mes, &ano);
    printf("%d/%d/%d\n", dia, mes, ano);
  }
}

int abb_altura(Agenda *raiz) {
  if (raiz == NULL) {
    return -1;
  } else {
    int esq = abb_altura(raiz->esq);
    int dir = abb_altura(raiz->dir);
    if (esq > dir) {
      return esq + 1;
    } else {
      return dir + 1;
    }
  }
}

// +++++++++++ Remover Agenda +++++++++++++
Agenda *remover_reserva(Agenda *raiz, Agenda *agenda) {
  if (raiz == NULL) {
    return NULL;
  } else {
    // acessar dados da raiz
    Reserva *reserva_raiz = raiz->reserva;
    int cod_reserva_raiz, id_raiz, cod_voo_raiz, dia_raiz, mes_raiz, ano_raiz;
    Assento assento_raiz;
    reserva_acessa(reserva_raiz, &cod_reserva_raiz, &assento_raiz, &id_raiz,
                   &cod_voo_raiz, &dia_raiz, &mes_raiz, &ano_raiz);
    // criar chave_raiz para comparar
    Data *data_raiz = data_cria(dia_raiz, mes_raiz, ano_raiz);

    // acessar dados da agenda a ser removida
    Reserva *reserva_agenda = agenda->reserva;
    int cod_reserva_agenda, id_agenda, cod_voo_agenda, dia_agenda, mes_agenda,
        ano_agenda;
    Assento assento_agenda;
    reserva_acessa(reserva_agenda, &cod_reserva_agenda, &assento_agenda,
                   &id_agenda, &cod_voo_agenda, &dia_agenda, &mes_agenda,
                   &ano_agenda);
    // criar chave_agenda para comparar
    Data *data_agenda = data_cria(dia_agenda, mes_agenda, ano_agenda);

    if (comparar_datas(data_agenda, data_raiz) == 0) {
      // Remover um nó folha = OK
      if (raiz->esq == NULL && raiz->dir == NULL) {
        raiz = NULL;
        free(raiz);
        return NULL;
      }

      else {
        // Remover nó com 2 filhos
        if (raiz->esq != NULL && raiz->dir != NULL) {
          // ir no mais à dir da raiz->esq
          Agenda *no = raiz->esq;
          while (no->dir != NULL) {
            no = no->dir;
          }

          // trocar o nó que quero remover pelo nó folha auxiliar encontrado
          // trocar a posição das reservas para remover uma agenda folha
          // reserva da raiz tem que receber reserva do no
          raiz->reserva = no->reserva;
          // assim mantem raiz->dir e raiz->esq intactas

          // reserva do no recebe reserva da agenda que estou buscando e é a da
          // raiz, que foi apagada
          no->reserva = agenda->reserva;
          // no mantem dir/esq nulos = virando folha com a chave a ser removida
          raiz->esq = remover_reserva(raiz->esq, agenda);
          return raiz;

        } else {
          // Remover nó com 1 filho
          Agenda *aux;
          if (raiz->esq != NULL) {
            aux = raiz->esq;
          } else if (raiz->dir != NULL) {
            aux = raiz->dir;
          }
          free(raiz);
          return aux;
        }
      }

    } else {
      // Comparar datas
      // -1 = d1 < d2 = d1 mais antiga
      // 1  = d1 > d2 = d1 mais recente
      // 0 = d1 == d2 = datas iguais

      if (comparar_datas(data_agenda, data_raiz) == -1) {
        raiz->esq = remover_reserva(raiz->esq, agenda);
      } else {
        raiz->dir = remover_reserva(raiz->dir, agenda);
      }
      return raiz;
    }
  }
}

// ++++++++++++++++++++++++++++++ Editar +++++++++++++++++++++++++++++++
Agenda *edita_reserva_pass(Agenda *agenda, Passageiro *passageiro_novo) {
  if (agenda == NULL || passageiro_novo == NULL) {
    return NULL;
  }

  (agenda->reserva)->passageiro = passageiro_novo;

  return agenda;
}

Agenda *edita_reserva_voo(Agenda *agenda, Voo *voo_novo) {
  if (agenda == NULL || voo_novo == NULL) {
    return NULL;
  }

  (agenda->reserva)->voo = voo_novo;

  return agenda;
}

Agenda *edita_reserva_assento(Agenda *agenda, Assento assento_novo) {
  if (agenda == NULL || assento_novo < 0) {
    return NULL;
  }

  (agenda->reserva)->assento = assento_novo;

  return agenda;
}

// +++++++++++++++++++++++++++ Trocar Reserva de agenda ++++++++++++++++

Agenda *troca_reserva_de_agenda(Agenda *agenda, Reserva *reserva) {}

// +++++++++++++++++++++++++++++ Buscar  ++++++++++++++++++++++++++++++++

// DATA DE VIAGEM = retorna o nó se encontrar ou NULL se não encontrar
Agenda *busca_agenda_data(Agenda *raiz, Data *data) {
  if (raiz != NULL) {
    Reserva *reserva = raiz->reserva;
    int cod_reserva, id, cod_voo, dia, mes, ano;
    Assento assento;
    reserva_acessa(reserva, &cod_reserva, &assento, &id, &cod_voo, &dia, &mes,
                   &ano);

    Data *data_aux = (Data *)malloc(sizeof(Data *));
    data_aux->dia = dia;
    data_aux->mes = mes;
    data_aux->ano = ano;

    if (comparar_datas(data, data_aux) == 0) {
      return raiz;
    } else if (comparar_datas(data, data_aux) == -1) {
      return busca_agenda_data(raiz->esq, data);
    } else {
      return busca_agenda_data(raiz->dir, data);
    }
  }

  return NULL;
}

// ID DO PASSAGEIRO + CODIGO DE VOO
Agenda *busca_agenda_id_codi(Agenda *raiz, int id_passageiro, int codigo_voo) {
  if (raiz != NULL) {

    int dia_aux, mes_aux, ano_aux, id_aux, cod_reserva, cod_voo;
    Assento assento;
    reserva_acessa(raiz->reserva, &cod_reserva, &assento, &id_aux, &cod_voo,
                   &dia_aux, &mes_aux, &ano_aux);

    if (id_aux == id_passageiro && cod_voo == codigo_voo) {
      return raiz;
    }

    Agenda *r = busca_agenda_id_codi(raiz->esq, id_passageiro, codigo_voo);

    if (r != NULL) {
      return r;
    } else {
      r = busca_agenda_id_codi(raiz->dir, id_passageiro, codigo_voo);
      if (r != NULL) {
        return r;
      }
    }
  }
  return NULL;
}

// ID DO PASSAGEIRO + DATA DE VIAGEM
Agenda *busca_agenda_id_data(Agenda *raiz, Data *data, int id) {
  if (raiz != NULL) {
    int dia_aux, mes_aux, ano_aux, id_aux, cod_reserva, cod_voo;
    Assento assento;
    reserva_acessa(raiz->reserva, &cod_reserva, &assento, &id_aux, &cod_voo,
                   &dia_aux, &mes_aux, &ano_aux);
    Data *data_aux = data_cria(dia_aux, mes_aux, ano_aux);

    if (comparar_datas(data, data_aux) == 0 && id == id_aux) {
      return raiz;
    } else if (comparar_datas(data, data_aux) < 0) {
      return busca_agenda_id_data(raiz->esq, data, id);
    } else {
      return busca_agenda_id_data(raiz->dir, data, id);
    }
  }

  return NULL;
}

Reserva *agenda_acessa(Agenda *agenda) {
  if (agenda != NULL) {
    return agenda->reserva;
  }
  return NULL;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA TABELA HASH <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// criar trecho
// Só criamos trecho com o id correto. Se id do passageiro != id do
// passageiro da reserva => não cria lista
Trecho *criar_trecho(int id_passageiro, Reserva *reserva) {
  Trecho *trecho = (Trecho *)malloc(sizeof(Trecho *));

  if (reserva == NULL || id_passageiro < 0) {
    return NULL;
  }

  // reserva acessa = obter dados da reserva
  Reserva *confere_p = reserva;
  int cod_reserva, id_pR, cod_voo, dia, mes, ano;
  Assento assento;
  reserva_acessa(confere_p, &cod_reserva, &assento, &id_pR, &cod_voo, &dia,
                 &mes, &ano);

  // printf("id pass: %d\nid reserva: %d\n", id_passageiro, id_pR);
  // conferir id informado com id da reserva
  if (id_passageiro == id_pR) {
    trecho->reserva = reserva;
    trecho->proximo = NULL;
    return trecho;
  }

  return NULL;
}

// funcao conferir:
// cidade origem = cidade destino
// data1 < data 2
// 0 = erro
// 1 = ok
int conferir_origem_destino_data(Trecho *ListaTrechos, Reserva *reserva) {

  // conferir cidade destino x cidade origem = pode virar uma funçao fora
  // daqui
  int cod_reservaR, diaR, mesR, anoR, cod_vooR, id_pR;
  Voo *vooR;
  char origemR[50], destinoR[50];
  Passageiro *passageiroR;
  Assento assentoR;

  // acessar dados da reserva para validação
  reserva_acessa_total(reserva, &cod_reservaR, &assentoR, &id_pR, &cod_vooR,
                       &diaR, &mesR, &anoR, passageiroR, vooR);
  voo_acessa(vooR, &cod_vooR, origemR, destinoR);
  Data *data_R = data_cria(diaR, mesR, anoR);

  while (ListaTrechos != NULL) {
    // acessar dados de cada trecho para comparação
    int cod_reservaT, diaT, mesT, anoT, cod_vooT, id_pT;
    char origemT[50] = "", destinoT[50] = "";
    Voo *vooT;
    Assento assentoT;
    Passageiro *passageiroT;
    reserva_acessa_total(ListaTrechos->reserva, &cod_reservaT, &assentoT,
                         &id_pT, &cod_vooT, &diaT, &mesT, &anoT, passageiroT,
                         vooT);
    voo_acessa(vooT, &cod_vooT, origemT, destinoT);
    Data *data_T = data_cria(diaT, mesT, anoT);

    // comparar passageiros da reserva e dos trechos a receber &&
    // comparar cidade destino x cidade origem &&
    // DataTrecho->atual < DataTrecho->proximo = DataReserva a ser inserida
    if (strcmp(origemT, destinoR) == 0 &&
        (comparar_datas(data_T, data_R) == -1)) {
      // adicionar reserva no trecho
      return 1;
    }
    ListaTrechos = ListaTrechos->proximo;
  }
  return 0;
}

void trecho_acessa(Trecho *trecho, Reserva *reserva) {
  if (trecho != NULL) {
    reserva = trecho->reserva;
  }
  reserva = NULL;
}

Reserva *trecho_acessa2(Trecho *trecho) {
  if (trecho != NULL) {
    return trecho->reserva;
  }
  return NULL;
}

// 0 = erro
// 1 = ok
int conferir_passageiro(Trecho *ListaTrechos, Reserva *reserva) {
  // acessar dados da reserva para validação
  int cod_reservaR, diaR, mesR, anoR, cod_vooR, id_pR;
  Voo *vooR;
  char origemR[50], destinoR[50];
  Passageiro *passageiroR;
  Assento assentoR;

  reserva_acessa_total(reserva, &cod_reservaR, &assentoR, &id_pR, &cod_vooR,
                       &diaR, &mesR, &anoR, passageiroR, vooR);

  Reserva *reserva_trecho = trecho_acessa2(ListaTrechos);
  int cod_reserva, id_pT, cod_voo, dia, mes, ano;
  Passageiro *passageiroT;
  Voo *vooT;
  Assento assento;
  reserva_acessa_total(reserva_trecho, &cod_reserva, &assento, &id_pT, &cod_voo,
                       &dia, &mes, &ano, passageiroT, vooT);

  if (id_pT == id_pR) {
    return 1;
  }
  return 0;
}

// inserir trecho na lista
/*
1- As _viagens_ só podem ser compostas por reservas do _mesmo passageiro_;
2- As viagens só podem ser compostas por reservas cujas datas sejam
cronologicamente compatíveis (isto é, a data da viagem do próximo trecho deve
ser maior que a data da do trecho anterior);
3- a cidade destino de um reserva leve o passageiro à cidade origem da próxima
*/
Trecho *inserir_reserva_trecho(Trecho *ListaTrechos, Reserva *reserva) {
  if (ListaTrechos == NULL && reserva == NULL) {
    return NULL;
  } else {
    if (ListaTrechos->reserva == NULL) {
      ListaTrechos->reserva = reserva;
      ListaTrechos->proximo = NULL;
      return ListaTrechos;
    } else {
      if (conferir_passageiro(ListaTrechos, reserva) == 0) {
        return ListaTrechos;
      } else {
        int id;
        char nome[50], endereco[100];
        passageiro_acessa(reserva->passageiro, &id, nome, endereco);

        // percorrer trecho para achar ponto de inserção
        while (ListaTrechos != NULL) {
          if (conferir_origem_destino_data(ListaTrechos, reserva) == 1) {
            Trecho *aux = criar_trecho(id, reserva);
            Trecho *prox = ListaTrechos->proximo;
            ListaTrechos->proximo = aux;
            aux->proximo = prox;
            return ListaTrechos;
          }
          ListaTrechos = ListaTrechos->proximo;
        }
      }
    }
  }
  return ListaTrechos;
}

// imprimir reserva dos trechos para conferencia

void print_reserva_trechos(Trecho *trecho) {
  if (trecho == NULL) {
    printf("Trecho nulo\n");
  }
  Trecho *aux = trecho;
  int cod_reserva, id, cod_voo, dia, mes, ano;
  Assento assento;
  Reserva *reserva_t = NULL;

  while (aux != NULL) {
    // Reserva *reserva = ;
    trecho_acessa(aux, reserva_t);
    reserva_acessa(reserva_t, &cod_reserva, &assento, &id, &cod_voo, &dia, &mes,
                   &ano);
    printf("Id-passageiro: %d\tcodigo da reserva: %d\n", id, cod_reserva);
    aux = aux->proximo;
  }
}

// criar viagem
// pra criar trecho já filtramos os requisitos do passageiro, origem-destino,
Viagem *criar_viagem(Trecho *trecho) {
  if (trecho == NULL) {
    return NULL;
  }
  Viagem *viagem = (Viagem *)malloc(sizeof(Viagem *));
  viagem->trechos = trecho;
  return viagem;
}

//------------------------------------------------

// criar tabela hash vazia
TabelaViagem *criar_tabela_hash(int tamanho) {
  if (tamanho <= 11) {
    return NULL;
  }

  TabelaViagem *tabela_viagem = (TabelaViagem *)malloc(sizeof(TabelaViagem *));
  tabela_viagem->tamanho = tamanho;
  tabela_viagem->tabela_hash = malloc(sizeof(Viagem *) * tamanho);

  // iniciar tabela com todos os elementos null
  for (int i = 0; i < tamanho; i++) {
    tabela_viagem->tabela_hash[i].trechos = NULL;
  }
  return tabela_viagem;
}

int tabela_acessa(TabelaViagem *tabela_viagem) {
  if (tabela_viagem != NULL) {
    return tabela_viagem->tamanho;
  }
  return -1;
}

Trecho *viagem_acessa(Viagem *viagem) {
  if (viagem != NULL) {
    return viagem->trechos;
  }
  return NULL;
}

/*int funcaoHash(TabelaViagem *tabela, int codigoHash) {
  if(tabela == NULL || codigoHash<0) return -1;
  return codigoHash % tabela->tamanho;
}*/
// função hash = **(OBS. o código hash de cada viagem deve ser função do
// somatório do identificador do passageiro e dos códigos das reservas
// associadas).**
unsigned int hash(Viagem *viagem, TabelaViagem *hash_table) {
  unsigned int hash_value;
  int cod_reserva2, id32, cod_voo2, dia2, mes2, ano2;
  int soma_reservas;
  Assento assento2;
  int tam = 15;

  Trecho *ListaTrechos = viagem_acessa(viagem);
  Reserva *reserva2 = trecho_acessa2(ListaTrechos);

  reserva_acessa(reserva2, &cod_reserva2, &assento2, &id32, &cod_voo2, &dia2,
                 &mes2, &ano2);

  // acessar os trechos das viagens para obter os códigos das reservas pro
  // somatorio com id passageiro
  // obter e somar
  while (ListaTrechos != NULL) {
    Reserva *reserva = ListaTrechos->reserva;
    int cod_reserva, id_pR, cod_voo, dia, mes, ano;
    Assento assento;
    reserva_acessa(reserva, &cod_reserva, &assento, &id_pR, &cod_voo, &dia,
                   &mes, &ano);

    soma_reservas += cod_reserva;
    ListaTrechos = ListaTrechos->proximo;
  }

  // hash function
  hash_value = soma_reservas % tam;
  return hash_value;
}

// inserir Viagem na Tabela
// Quando houver conflitos, a viagem não poderá ser cadastrada.

// return 1 = ok // return 0 = erro
int inserir_viagem(Viagem *viagem, TabelaViagem *hash_table) {
  if (hash_table != NULL || viagem != NULL) {
    hash_table->tamanho += 1;

    unsigned int indice = hash(viagem, hash_table) % 15;

    if (indice < hash_table->tamanho) {
      hash_table = realloc(hash_table, indice * sizeof(TabelaViagem *));
    }

    if (hash_table->tabela_hash[indice].trechos != NULL) {
      return 0;
    }

    hash_table->tabela_hash[indice] = *viagem;
    return 1;
  }

  return 0;
}

// imprimir tabela hash
/* A tabela de viagens deve permitir imprimir na tela dados sobre todo o
intinerário, além de dados do passageiro.*/

void imprimir_tabela(TabelaViagem *hash_table, int indice) {
  Trecho *aux = (&(hash_table->tabela_hash))[indice]->trechos;
  int inicio = 1;
  printf("\tITINERÁRIO DA VIAGEM:\n");

  while (aux != NULL) {

    printf("**************************************\n");
    printf("\t Reserva %d\n", inicio);
    Reserva *reserva = aux->reserva;
    int cod_reserva, id, cod_voo, dia, mes, ano;
    Assento assento;
    reserva_acessa(reserva, &cod_reserva, &assento, &id, &cod_voo, &dia, &mes,
                   &ano);
    printf("Codigo da reserva: %d\n", cod_reserva);
    printf("Viagem marcada para: %d/%d/%d\n", dia, mes, ano);

    printf("Origem: %s\n", aux->reserva->voo->origem);
    printf("Destino: %s\n", aux->reserva->voo->destino);
    printf("Codigo do Voo: %d\n", cod_voo);
    printf("Nome do passageiro: %s\n", aux->reserva->passageiro->nome);
    printf("Id do passageiro: %d\n", id);
    printf("Endereço do passageiro: %s\n", aux->reserva->passageiro->endereco);

    printf("Assento da viagem: %d", assento);
    inicio++;
    aux = aux->proximo;
  }
}
