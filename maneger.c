#include <stdio.h>
#include <string.h>

#define ITENS 20

typedef struct Voo
{
  unsigned int id;
  char origem[30], destino[30]; // cidade-UF
  float preco;
  char companhia[20];
  char hora[5], data[10]; //hora: hh-mm | dia: dd-mm-aaaa
} Voo;

void busca_preco(Voo voos[ITENS], float p)
{
  int i, voos_achados = 0;

  for (i = 0; i < ITENS; i++)
  {
    if (voos[i].preco == p)
    {
      printf("\nID: %d\n", voos[i].id);
      printf("Origem do voo: %s\n", voos[i].origem);
      printf("Destino do voo: %s\n", voos[i].destino);
      printf("Preço do voo: R$%.2f\n", voos[i].preco);
      printf("Companhia do voo: %s\n", voos[i].companhia);
      printf("Hora do voo: %s\n", voos[i].hora);
      printf("Data do voo: %s\n", voos[i].data);
      voos_achados++;
    }
  }
  if (voos_achados == 0)
    printf("Não há nenhum voo com o preço %f", p);
}

void ordena_preco(Voo voos[ITENS])
{
  int i, j, k;
  int menor;
  float precos[ITENS], tmp;

  for (i = 0; i < ITENS; i++)
  {
    precos[i] = voos[i].preco;
  }

  for (j = 0; j < ITENS - 1; j++)
  {
    menor = j;
    for (k = j + 1; k < ITENS; k++)
    {
      if (precos[k] < precos[menor])
      {
        menor = k;
      }
    }
    if (j != menor)
    {
      tmp = precos[j];
      precos[j] = precos[menor];
      precos[menor] = tmp;
    }
  }

  for (i = 0; i < ITENS; i++)
  {
    for (j = 0; j < ITENS; j++)
    {
      if (*(precos + i) == voos[j].preco)
      {
        printf("\nID: %d\n", voos[j].id);
        printf("Origem do voo: %s\n", voos[j].origem);
        printf("Destino do voo: %s\n", voos[j].destino);
        printf("Preço do voo: R$%.2f\n", voos[j].preco);
        printf("Companhia do voo: %s\n", voos[j].companhia);
        printf("Hora do voo: %s\n", voos[j].hora);
        printf("Data do voo: %s\n\n", voos[j].data);
      }
    }
  }
}

int main(int argc, char *argv[])
{
  int i;
  Voo voos[ITENS];
  float user_preco;

  for (i = 0; i < ITENS; i++)
  {
    voos[i].id = i;
    printf("Informe origem do voo (Ex.: belem-PA): ");
    scanf("%s", voos[i].origem);

    printf("Informe o destino do voo (Ex.: manaus-AM): ");
    scanf(" %s", voos[i].destino);

    printf("Informe a companhia do voo: ");
    scanf(" %s", voos[i].companhia);

    printf("Informe a data (dd-mm-aaaa): ");
    scanf("%s", voos[i].data);

    printf("Informe a hora (hh-mm): ");
    scanf("%s", voos[i].hora);

    printf("Informe o preço do voo: R$");
    scanf("%f", &voos[i].preco);

    printf("------------------------------------------------\n\n");
  }

  printf("Busca de voos pelo preço\n");
  printf("Informe um preço: R$");
  scanf("%f", &user_preco);

  busca_preco(voos, user_preco);

  printf("Ordenando voos pelo preço:\n");
  ordena_preco(voos);

  return 0;
}
