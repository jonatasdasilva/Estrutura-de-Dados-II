#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAMANHO_ARQUIVO 11
//Variável global para o arquivo
FILE *tabela_hash

typedef struct HASHING
{
	int chave;
	char nome[20];
	int idade;
}dados, *Dados;
/*Funcção que checa as chaves existentes no arquivo, em caso de já existir não permite a inserção*/
_Bool verifica_chaves(int id)
{

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
	if (verifica_chaves(_1))
	{
		for (int i = 0; i < TAMANHO_ARQUIVO; i++)
		{
			int _3 = (_1 + i * _2);
			if (verifica_chaves(_3))
				return _3;
		}
	}
	else
		return _1;
}
/*Função que imprime todo o registro em ordem crescente de índice*/
void imprime_hash()
{

}

/*Função que faz a inserção no arquivo*/
_Bool inseri_arquivo()
{
	tabela_hash = fopen("Hashing.bin", "wb"); // Cria um arquivo binário para gravação
	fwrite()
}

//Principal
int main ()
{
	HASHING chaves[TAMANHO_ARQUIVO];
	int i;
	//Variáveis se for necessário para inserção no registro;
	int id;
	char pessoa;
	int anos;

	do
	{
		scanf ( "%c", &opt);

		if (opt == 'i')
		{
			//alocar nova estrutura;
			scanf( "%d", &chaves[i].chave);
			scanf( "%s", chaves[i].nome);
			scanf( "%d", chaves[i].idade);
			i = hash(chaves[i].chave);
			if (!(verifica_chaves(chaves[i].chave))
			{
				//se a chave não existir inserie-a no arquivo
				inseri_arquivo();
			}
			else
				printf("chave ja existente: %s\n", chaves[i].chave);
			//em caso de já existir imprimi a string acima;
		}
		else if (opt == 'c')
		{
			scanf( "%d", &id);
			if ((verifica_chaves(id))
			{
				printf("chave: %d\n", chaves[i].chave);
				printf("%s\n", chaves[i].nome);
				printf("%d\n", chaves[i].idade);
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

	return 0;
}
