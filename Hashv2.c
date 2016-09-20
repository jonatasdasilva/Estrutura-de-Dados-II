#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_ARQUIVO 11
//Variável global para o arquivo
FILE *tabela_hash;

typedef struct Hashing
{
	int chave;
	char nome[20];
	int idade;
}hashing;
/*Função que retorna o máximo entre {[chave/TAMANHO_ARQUIVO], 1}*/
int max (int div, int _1)
{
	if (div > _1)
		return ((int)div);
	else
		return _1;
}
/*Função que calcula o h1*/
int h1 (int chave)
{
	return (chave % TAMANHO_ARQUIVO);
}
/*Função que calcula o h2*/
int h2 (int chave)
{
	return max(floor(chave/TAMANHO_ARQUIVO), 1);
}
/*Função que retorna o valor do hash da chave.*/
int hash (int chave)
{
	int _1 = h1(chave);
	int _2 = h2(chave);
	if (verifica_chaves(_1, chave))
	{
		for (int i = 0; i < TAMANHO_ARQUIVO; i++)
		{
			int _3 = ((_1 + i * _2) % TAMANHO_ARQUIVO);
			if (verifica_chaves(_3, chave))
			{
				i_hash = i;
				rewind(tabela_hash);
				return _3;
			}
		}
	}
	rewind(tabela_hash);
	return _1;
}
/*Função de veriifcação de local.*/
_Bool verifica_hash(int id, int chave)
{
	hashing h;
	fseek(tabela_hash,(id*sizeof(struct Hashing)),SEEK_SET)
	fscanf(tabela_hash, "%d\n%s\n%d\n", &h.chave, h.nome, &h.idade);
	if (h.chave == chave)
		return false;
	if(h.chave == -1)
		return true;
	rewind(tabela_hash);
}
/*Função que faz a inserção no arquivo*/
_Bool inseri_hash()
{
	int chave, idade;
	char nome[20];
	scanf("%d", &chave);
	scanf("%s", nome);
	scanf("%d", &idade);
	//printf("%d - %s - %d", chave, nome, idade);
	int id = hash(chave);
	//encontra a posisão exata da inserção.
	long int next = (id * sizeof(struct Hashing));
	fseek(tabela_hash, (id * sizeof(struct Hashing)), SEEK_SET);
	if (!(verifica_hash(id, chave)))
	{
		rewind(tabela_hash);
		printf("chave ja existente: %d\n", chave);
		return false;
	}
	fseek(tabela_hash, (id * sizeof(struct Hashing)), SEEK_SET);
	//em caso de já existir imprimi a string acima;
	//inserie no arquivo a chave não existente.
	fprintf(tabela_hash, "%d\n%s\n%d\n", chave, nome, idade)
	//fwrite(&chave, sizeof(int), 1, tabela_hash);
	//fwrite(&nome, 20 * sizeof(char), 1, tabela_hash);
	//fwrite(&idade, sizeof(int), 1, tabela_hash);
	//id_chave = -1;
	rewind(tabela_hash);
	printf("true\n");
	return true;
}




if (fopen(tabela_hash, "r+b") == 0)
	//não existe arquivo;
	printar o cálculo do hash;
abrir e fechar o arquivo em cada passo. abrindo como rb  leitura;
