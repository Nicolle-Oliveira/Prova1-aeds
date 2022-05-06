#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Constantes
#define SUCESSO 0
#define FALHA 1

#define MAX_VAGOES 26

//O inicio...
int main(int argc, char** argv) {


	Pilha_lst *ordem_errada, *resposta;

	int quant, i, j = 0, inserir = 0;

	char letra, letra_apoio, letra_procura, lixo, ajuda = SUCESSO;

	//Criando todas as pilhas
	ordem_errada = pilha_lst_cria();
	resposta = pilha_lst_cria();
	
	//Obtendo a quantidade de vagões 
	printf("Quantidade de vagoes - ");
	scanf(" %d", &quant);
	
	char minha_string[(quant+1)];

	/*Aqui pegamos do usuário a ordem atual dos vagões*/
	printf("\nOrdem atual (Digite na forma d a t e) - ");
	for (i = 0; i < quant; i++) {
		scanf(" %c%c", &letra, &lixo);
		pilha_lst_push(ordem_errada, letra);
	}
	
	printf("\n Ordem nova (Digite da forma date) - ");

	fgets(minha_string, (quant+1), stdin);
	
	printf("\n Pilha Errada\n");
	pilha_lst_imprime(ordem_errada);
	printf("\n\n");	

	i = 0;


	do {
		if(pilha_lst_vazia(resposta) == FALHA || ajuda == SUCESSO){
			if(inserir < quant){
				//Obtendo a letra do vagão que precisamos arrumar
				letra_procura = pilha_lst_pop(ordem_errada);
			}
		}

		if(ajuda == SUCESSO){
			letra_apoio = minha_string[j];
			j++;
		}

		if (inserir < quant){
			//Coloca na pilha
			pilha_lst_push(resposta, letra_procura);
			printf("I");
			inserir++;
		}
		//Se forem iguais, significa que encontramos nosso vagão!
		if (letra_procura == letra_apoio) {

			//Não precisamos mais dessa letra, podemos jogá-la fora
			lixo = pilha_lst_pop(resposta);
			printf("R");
			ajuda = SUCESSO;
		}
		else{
			ajuda == FALHA;
		}

		//Contador provisório, precisamos de uma nova condição..
		i++;
	} while ( i < MAX_VAGOES);

	pilha_lst_libera(resposta);
	pilha_lst_libera(ordem_errada);

	if (pilha_lst_vazia(resposta) != FALHA) {
		printf("   Impossivel");
	}

	//Se chegamos até aqui, deu tudo certo!!
	return SUCESSO;
}
