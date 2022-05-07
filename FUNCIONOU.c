#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Constantes
#define SUCESSO 0
#define FALHA 1
#define MAX_VAGOES 26

//O inicio...
int main(int argc, char** argv) {


	Pilha_lst* ordem_nova, * ordem_nova_inverso, * ordem_errada, * ordem_errada_inverso, * resposta;
	int quant, i, ajuda;
	char letra, letra_apoio, letra_procura, lixo;

	//Criando todas as pilhas
	ordem_nova = pilha_lst_cria();
	ordem_nova_inverso = pilha_lst_cria();
	ordem_errada_inverso = pilha_lst_cria();
	ordem_errada = pilha_lst_cria();
	resposta = pilha_lst_cria();

	//Obtendo a quantidade de vagões 
	printf("Quantidade d vagoes - ");
	scanf(" %d", &quant);

	//Vou usar o exemplo de "date" como esta na prova

	/*Aqui pegamos do usuário a ordem atual dos vagões*/
	printf("\nOrdem atual - ");
	for (i = 0; i < quant; i++) {
		scanf(" %c", &letra);
		pilha_lst_push(ordem_errada_inverso, letra);
	}

	for (i = 0; i < quant; i++) {
		letra = pilha_lst_pop(ordem_errada_inverso);
		pilha_lst_push(ordem_errada, letra);
	}

	printf("\nOrdem desejada - ");
	for (i = 0; i < quant; i++) {
		scanf(" %c", &letra);
		pilha_lst_push(ordem_nova_inverso, letra);
	}

	/* Esse "for" organiza elas do jeito que precisamos*/
	for (i = 0; i < quant; i++) {
		letra = pilha_lst_pop(ordem_nova_inverso);
		pilha_lst_push(ordem_nova, letra);
	}

	pilha_lst_libera(ordem_errada_inverso);
	pilha_lst_libera(ordem_nova_inverso);


	i = 0;
	ajuda = FALHA;
	int insere = quant;
	quant = quant * 2;

	letra_apoio = pilha_lst_pop(ordem_nova);

	do {

		if (ajuda == SUCESSO ) {
			letra_apoio = pilha_lst_pop(ordem_nova);
		}

		if (ajuda != SUCESSO && insere > 0) {
			letra_procura = pilha_lst_pop(ordem_errada);
		}
		else if (ajuda == SUCESSO && pilha_lst_vazia(resposta) != FALHA) {
			letra_procura = pilha_lst_pop(resposta);
			pilha_lst_push(resposta, letra_procura);
		}

		if (insere > 0 && ajuda != SUCESSO) {
			pilha_lst_push(resposta, letra_procura);
			printf("I");
			insere--;
		}

		//Se forem iguais, significa que encontramos nosso vagão!
		if (letra_procura == letra_apoio) {

			//Não precisamos mais dessa letra, podemos jogá-la fora
			lixo = pilha_lst_pop(resposta);
			printf("R");
			ajuda = SUCESSO;
		}
		else {
			ajuda = FALHA;
		}

		//Contador provisório, precisamos de uma nova condição..
		i++;
	} while (i < quant);

	//Se no fim de tudo a pilha "resposta" não estiver vazia, significa que a organização foi impossível
	if (pilha_lst_vazia(resposta) != FALHA) {
		printf("   Impossivel");
	}

	pilha_lst_libera(resposta);
	pilha_lst_libera(ordem_errada);
	pilha_lst_libera(ordem_nova);

	//Se chegamos até aqui, deu tudo certo!!
	return SUCESSO;
}
