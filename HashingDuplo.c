#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_ARQUIVO 11
//Variável global para o arquivo
FILE *tabela_hash;

int i_hash;
int id_chave = -1;

typedef struct Hashing
{
	int chave;
	char nome[20];
	int idade;
}hashing, *Dados;
/*Funcção que checa as chaves existentes no arquivo, em caso de já existir não permite a inserção*/
_Bool verifica_chaves(int id, int chave)
{
	long int next = (id * sizeof(struct Hashing));
	hashing h = (hashing) malloc (sizeof(struct Hashing));
	fread(&h, sizeof(hashing), 1, tabela_hash);
	if ((h.chave == -1) || (h.chave == chave))
	{
		free(h);
		if (h.chave == chave)
		{
			free(h);
			id_chave = id;
		}
		return false;
	}                                                                                                                                                                        
	free(h);
	return true;
}
//Encontra a posição exata de inserção após checagem na função hash.
_Bool next_position(int id)
{
	long int next = (id * sizeof(struct Hashing));
	if (fseek(tabela_hash, next, SEEK_SET))
		return true;
	return false;
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
	return ((int)max((chave/TAMANHO_ARQUIVO), 1));
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

int consulta (int chave)
{
	struct Hashing h = malloc (sizeof(struct Hashing));
	int id = hash(chave);
	if (id_chave != -1)
		id = id_chave;
	id_chave = -1;
	long int next = (id * sizeof(struct Hashing));
	fseek(tabela_hash, next, SEEK_SET)
	fread(&h, sizeof(hashing), 1, tabela_hash);
}
/*Função que imprime todo o registro em ordem crescente de índice*/
void imprime_hash()
{
	int chave;
	int id, _1, _3;
	hashing chave = (hashing) malloc (sizeof(struct Hashing));

	scanf(" %d\n", &chave);
	_1 = h1(chave);
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
		if (chave.chave == -1)
			printf("\n");
		else
			printf("%d\n", &chave.chave);
		printf("%s\n", chave.nome);
		printf("%s\n", chave.idade);
	}
}
/*Função que faz a inserção no arquivo*/
_Bool inseri_hash()
{
	hashing chaves = malloc(sizeof(struct Hashing));
	//alocar nova estrutura;
	scanf(" %d", &chaves.chave);
	scanf(" %s", chaves.nome);
	scanf(" %d", &chaves.idade);
	int i = hash(chaves.chave);
	//encontra a posisão exata da inserção.
	next_position((i - 1));
	//inserie no arquivo a chave não existente.
	int j;
	fread(&j, sizeof(int), 1, tabela_hash);
	if (j == i)
	{
		fwrite(&chaves, sizeof(struct Hashing), 1, tabela_hash);
		id_chave = -1;
	}
	else
	{
		printf("chave ja existente: %s\n", chaves.chave);
	}
	//em caso de já existir imprimi a string acima;
	free(chaves);
	rewind(tabela_hash);
}
/*Função que inicializa o arquivo*/
void inicializa_arquivo()
{
	int i;
	hashing h = malloc (sizeof(struct Hashing));
	h.chave = -1;
	for (i = 0; i < TAMANHO_ARQUIVO; i++)
	{
		fwrite(&i, sizeof(int), 1, tabela_hash);
		fwrite(&h, sizeof(struct Hashing), 1, tabela_hash);
	}
	free(h);
}
/*Função que remove registro*/
//_Bool remove_registro()
//{
	
//}
//Principal
int main ()
{
	//Variáveis se for necessário para inserção no registro;
	int id;
	int idade;
	tabela_hash = fopen("Hashing", "w+b"); // Cria um arquivo binário para gravação

	do
	{
		scanf (" %c", &opt);
		if (opt == 'i')
		{
			inseri_hash();
		}
		else if (opt == 'c')
		{
			scanf(" %d", &id);
			if ((consulta(id))
			{
				imprime_hash(id);
			}
			else
				printf("’chave nao encontrada: %d\n", chaves[i].chave);
		}
		else if (opt == 'r')
		{
			scanf(" %d", &id);
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
