#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_ARQUIVO 11
//Variável global para o arquivo
FILE *tabela_hash

typedef struct Hashing
{
	int chave;
	char nome[20];
	int idade;
}hashing, *Dados;
/*Funcção que checa as chaves existentes no arquivo, em caso de já existir não permite a inserção*/
_Bool verifica_chaves(int id)
{
	int i;
	hashing h = (hashing) malloc (sizeof(struct Hashing));

	for ()
	fread(&i, sizeof(int), 1, tabela_hash);
	if ()
}
/*Função que retorna o máximo entre {[chave/TAMANHO_ARQUIVO], 1}*/
int max (float div, int _1)
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
	return (max((chave/TAMANHO_ARQUIVO), 1));
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
			int _3 = (_1 + i * _2);
			if (verifica_chaves(_3, chave))
				return _3;
		}
	}
	else
		return _1;
}
/*Função que imprime todo o registro em ordem crescente de índice*/
void imprime_hash()
{
	int chave;
	int id;
	hashing chave = (hashing) malloc (sizeof(struct Hashing));

	scanf(" %d\n", &chave);
	id = hash(chave);
	/*imprime o Hash procurado se existir*/
	fread(&chave, sizeof(struct Hashing, 1, tabela_hash));
	rewind(tabela_hash);
	printf("%d\n", &chave.chave);
	printf("%s\n", chave.nome);
	printf("%s\n", chave.idade);
}
/*Função que imprime todo o arquivo*/
_Bool imprime_arquivo()
{
	int id;
	hashing h = (hashing) malloc (sizeof(struct Hashing));

	while (!(feof(tabela_hash)))
	{
		fread(&id, sizeof(int), 1, tabela_hash);
		fread(&h, sizeof(struct Hashing), 1, tabela_hash);
		printf("%d\n", &chave.chave);
		printf("%s\n", chave.nome);
		printf("%s\n", chave.idade);
	}
}
/*Função que faz a inserção no arquivo*/
_Bool inseri_hash()
{
	hashing chaves = (hashing) malloc(sizeof(struct Hashing))
	//alocar nova estrutura;
	scanf(" %d", &chaves.chave);
	scanf(" %s", chaves.nome);
	scanf(" %d", &chaves.idade);
	i = hash(chaves.chave);
	if (!(verifica_chaves(i, chaves[i].chave))
	{
		//se a chave não existir inserie-a no arquivo
		fwrite(&chaves, sizeof(struct Hashing), 1, tabela_hash);
	}
	else
		printf("chave ja existente: %s\n", chaves[i].chave);
	//em caso de já existir imprimi a string acima;
	free(chaves);
	rewind(tabela_hash);
}
/*Função que inicializa o arquivo*/
void inicializa_arquivo()
{
	hashing h = (hashing) malloc (sizeof(struct Hashing));
	h.chave = -1;
	for (int i = 0; i < TAMANHO_ARQUIVO; i++)
	{
		fwrite(&i, sizeof(int), 1, tabela_hash);
		fwrite(&h, sizeof(struct Hashing), 1, tabela_hash);
	}
	free(h);
}

//Principal
int main ()
{
	//HASHING chaves[TAMANHO_ARQUIVO];
	int i;
	//Variáveis se for necessário para inserção no registro;
	int id;
	char pessoa;
	int idade;
	tabela_hash = fopen("Hashing", "w+b"); // Cria um arquivo binário para gravação

	do
	{
		scanf ( "%c", &opt);

		if (opt == 'i')
		{
			inseri_hash();
		}
		else if (opt == 'c')
		{
			scanf( "%d", &id);
			if ((verifica_chaves(id))
			{
				imprime_hash(id);
			}
			else
				printf("’chave nao encontrada: %d\n", chaves[i].chave);
		}
		else if (opt == 'r')
		{
			scanf( "%d", &id);
			if ((verifica_chaves(id))
			{
				//se existir remove do registro e não gera saídas;
			}
			else
			{
				printf("chave nao encontrada: %d\n", &id);
			}
		}
		else if (opt == 'p')
		{
			//imprime todo o registro em sequência crescente até tamanho-1.
			imprime_hash();
		}

	}while (opt == 'e');
	fclose(tabela_hash);
	return 0;
}
