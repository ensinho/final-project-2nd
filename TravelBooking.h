enum cod_assento {
  A0,
  B0,
  C0,
  A1,
  B1,
  C1,
  A2,
  B2,
  C2,
  A3,
  B3,
  C3,
  A4,
  B4,
  C4,
  A5,
  B5,
  C5,
  A6,
  B6,
  C6,
  A7,
  B7,
  C7,
  A8,
  B8,
  C8,
  A9,
  B9,
  C9
};

typedef enum cod_assento Assento;
typedef struct data Data;

typedef struct voo Voo;
typedef struct no_voo NoVoo;
typedef struct lista_voo ListaVoo;

typedef struct passageiro Passageiro;
typedef struct no_passageiro NoPassageiro;
typedef struct lista_passageiro ListaPassageiro;

typedef struct reserva Reserva;
typedef struct agenda Agenda;

typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;
typedef struct trecho Trecho;

typedef struct no No;

//>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DO PASSAGEIRO <<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Cria passageiro novo
Passageiro *passageiro_novo(int id, char *nome, char *endereco);

// Libera espaço do passageiro
void passageiro_libera(Passageiro **passageiro);

// Acessa valores do passageiro
void passageiro_acessa(Passageiro *passageiro, int *id, char *nome,
                       char *endereco);

// Edita os valores de um passageiro existente
void passageiro_edita(Passageiro *passageiro, int id, char *nome,
                      char *endereco);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA LISTA DE PASSAGEIROS <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Cria lista de passageiros
ListaPassageiro *cria_lista_passageiro();

// Adiciona passageiro à lista
int lista_adiciona_passageiro(ListaPassageiro *lista_pass,
                              Passageiro *passageiro);

// Retira passageiro da lista
Passageiro *lista_remove_passageiro(ListaPassageiro *lista_pass, int id);

// Retorna o primeiro adicionado
Passageiro *lista_top_pass(ListaPassageiro *lista_pass);

// Busca um passageiro pelo id
Passageiro *lista_busca_pass(ListaPassageiro *lista_pass, int id);

// Imprime lista de passageiros
void imprimir_lista_passageiros(ListaPassageiro *lista_pass);

//>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DO VOO <<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<

// Cria voo novo
Voo *voo_cria(int codigo, char *origem, char *destino);

// Libera espaço do voo
void voo_libera(Voo **voo);

// Acessa valores do voo
void voo_acessa(Voo *voo, int *codigo, char *origem, char *destino);

// Edita os valores de um voo existente
void voo_edita(Voo *voo, int codigo, char *origem, char *destino);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA LISTA DE VOOS <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Cria lista de voos
ListaVoo *cria_lista_voo();

// Adiciona voo a lista
int lista_adiciona_voo(ListaVoo *lista_voo, Voo *voo);

// Retira voo da lista (não precisa ser o topo da pilha)
Voo *lista_remove(ListaVoo *lista_voo, int codigo);

// Retorna o primeiro voo adicionado
Voo *lista_top_voo(ListaVoo *lista_voo);

// Busca um voo pelo codigo
Voo *lista_busca_voo(ListaVoo *lista_voo, int codigo);

//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA RESERVA <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<

// cria data
Data *data_cria(int dia, int mes, int ano);

// acessa o conteúdo da data
void data_acessa(Data *data, int *dia, int *mes, int *ano);

// acessa o conteúdo da reserva
void reserva_acessa(Reserva *reserva, int *cod_reserva, Assento *assento,
                    int *id, int *cod_voo, int *dia, int *mes, int *ano);

// comparar datas entre nós
int comparar_datas(Data *data1, Data *data2);

// faz a validação da data em relação aos meses, dias e anos
int valida_data(int dia, int mes, int ano);

// cria reserva - conteudo de agenda
Reserva *cria_reserva(int codigo, Data *data_viagem, Passageiro *passageiro,
                      Voo *voo, Assento assento);

//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA ARVORE <<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<

// cria nó - agenda
Agenda *cria_agenda_ABB(Reserva *reserva);

// insere nó - agenda
Agenda *insere_agenda_ABB(Agenda *raiz, Agenda *agenda);

Data *chave_da_agenda(Agenda *agenda);

// remove reserva (e agenda) da arvore
Agenda *remover_reserva(Agenda *raiz, Agenda *agenda);

Agenda *troca_reserva_de_agenda(Agenda *agenda, Reserva *reserva);

void reserva_acessa_total(Reserva *reserva, int *cod_reserva, Assento *assento,
                          int *id, int *cod_voo, int *dia, int *mes, int *ano,
                          Passageiro *passageiro, Voo *voo);

// verifica se uma data é valida
int valida_data(int dia, int mes, int ano);

int valida_data2(int dia, int mes, int ano);

// busca pela data
Agenda *busca_agenda_data(Agenda *raiz, Data *data);

// busca pela data e pelo id do passageiro
Agenda *busca_agenda_id_data(Agenda *raiz, Data *data, int id);

// busca pelo id do passageiro e pelo codigo do voo
Agenda *busca_agenda_id_codi(Agenda *raiz, int id_passageiro, int codigo_voo);

Reserva *agenda_acessa(Agenda *agenda);

void chave_acessa(Reserva *reserva, int *dia, int *mes, int *ano);

void EmOrdem(Agenda *raiz);

void PreOrdem(Agenda *raiz);

void PosOrdem(Agenda *raiz);

int abb_altura(Agenda *raiz);

//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>> FUNÇÕES DA TABELA HASH <<<<<<<<<<<<<<<<<<
//>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// função hash = **(OBS. o código hash de cada viagem deve ser função do
// somatório do identificador do passageiro e dos códigos das reservas
// associadas).**
unsigned int hash(Viagem *viagem, TabelaViagem *hash_table);

// A tabela de viagens deve permitir imprimir na tela dados sobre todo o
// intinerário, além de dados do passageiro.
// imprimir tabela
void imprimir_tabela(TabelaViagem *hash_table, int indice);

// criar tabela hash
TabelaViagem *criar_tabela_hash(int tamanho);

// inserir viagem na tabela
int inserir_viagem(Viagem *viagem, TabelaViagem *hash_table);

// funcoes Viagem
// associar um conjunto de reservas de tal forma que a cidade destino de um
// reserva leve o passageiro à cidade origem da próxima reserva.
Viagem *criar_viagem(Trecho *trecho);

// criar trecho
Trecho *criar_trecho(int id_passageiro, Reserva *reserva);

// inserir reserva no trecho
Trecho *inserir_reserva_trecho(Trecho *ListaTrechos, Reserva *reserva);

// conferir se passageiro pode ser adicionado no trecho
int conferir_passageiro(Trecho *ListaTrechos, Reserva *reserva);

// conferir se a origem, destino e data estão de acordo com os requisitos de
// inserção
int conferir_origem_destino_data(Trecho *ListaTrechos, Reserva *reserva);

// contar tamanho do trecho para conferencia
int tamanho_trecho(Trecho *trecho);

// imprimir reseras dos trechos para conferencia
void print_reserva_trechos(Trecho *trecho);

// trecho acessa
void trecho_acessa(Trecho *trecho, Reserva *reserva);

Reserva *trecho_acessa2(Trecho *trecho);

int tabela_acessa(TabelaViagem *tabela);

Trecho *viagem_acessa(Viagem *viagem);

int codigo_hash(Viagem *viagem);
