#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//Constantes
#define SUCESSO 0
#define FALHA 1

#define MAX_VAGOES 26

//O inicio...
int main(int argc, char** argv) {


	Pilha_lst* ordem_nova, *ordem_nova_inverso, *ordem_errada, *resposta;
	/* 1 - ordem_nova -> pilha com a ordenação correta dos elementos (o ultimo elemento colocado eh a primeira letra da palavra)
	* Ex.:
	* d
	* a
	* t
	* e
	* 
	* 2 - ordem_nova_inverso -> pilha com a ordem correta dos elementos (o ultimo elemento colocado eh a última letra da palavra)
	* é assim que recebemos do usuário
	* Ex.:
	* e
	* t
	* a
	* d
	* 
	*
	* 
	* 3 - ordem_errada -> pilha com a ordem que precisamos organizar, fornecida pelo usuario (o ultimo elemento q ele digitar ficará no topo da pilha)
	* Ex.: se ele digita e t d a
	* a
	* d
	* t
	* e
	* 
	* 4 - resposta -> pilha onde vamos colocar e remover os dados da pilha "ordem_errada" na ordem correta*/


	int quant, i;

	/* 1 - quant -> quantidade de vagoes, inserido pelo usuário
	* 
	* 2 - i -> contador*/

	char letra, letra_com_o_dado_de_apoio, letra_procurando_seu_lugar, lixo;

	/* 1 - letra -> variavel utilizada para quardar as letras dos vagoes, digitadas pelo usario
	* 
	* 2 - letra_com_o_dado_de_apoio -> armazena uma letra para comparação quando inserimos e removemos os dados na pilha "resposta"
	* quarda a letra da ordem certa
	* 
	* 3 - letra_procurando__seu_lugar -> armazena a letra comparada a "letra_com_dado_de_apoio"
	* quarda a letra da ordem errada para q ela seja quardada na pilha "resposta"
	* 
	* 4 - lixo -> variável q quarda a letra removida d "resposta" (ver mais a frente)
	*/

	//Criando todas as pilhas
	ordem_nova = pilha_lst_cria();
	ordem_nova_inverso = pilha_lst_cria();
	ordem_errada = pilha_lst_cria();
	resposta = pilha_lst_cria();
	
	//Obtendo a quantidade de vagões 
	printf("Quantidade de vagoes - ");
	scanf(" %d", &quant);

	//Vou usar o exemplo de "date" como esta na prova

	/*Aqui pegamos do usuário a ordem atual dos vagões*/
	printf("\nOrdem atual - ");
	for (i = 0; i < quant; i++) {
		scanf(" %c", &letra);
		pilha_lst_push(ordem_errada, letra);
	}
	/*No caso, ela ta assim
	* a
	* d
	* t
	* e
	*/

	/*Obtendo a ordem que o usuario deseja organizar os vagoes
	*Ele pode digitar um de cada vez ou tudo junto.
	*Ver no momento de compilação*/
	printf("\nOrdem desejada - ");
	for (i = 0; i < quant; i++) {
		scanf(" %c", &letra);
		pilha_lst_push(ordem_nova_inverso, letra);
	}
	/*Dentro de "ordem_nova_inverso" ta assim:
	* 
	* e
	* t
	* a
	* d
	*/
	

	/* Esse "for" organiza elas do jeito que precisamos*/
	for (i = 0; i < quant; i++) {
		letra = pilha_lst_pop(ordem_nova_inverso);
		pilha_lst_push(ordem_nova, letra);
	}
	/* Agora ta assim:
	* 
	* d
	* a
	* t
	* e
	*/
	
	i = 0;

	/*Esse while eh uma tentativa de colocar os elementos que precisamos na pilha "resposta" e removê - los na ordem certa 
	* Funciona até uma certa parte, mas as condições estão erradas
	* Não consegui pensar em uma condição para o while, ent coloquei o contador i msm, mas so por enquanto
	*/
	
	do {

		//Obtendo a letra do vagão que precisamos arrumar
		letra_procurando_seu_lugar = pilha_lst_pop(ordem_errada);

		//Letra do próximo vagão que precisa ser guardado no lugar
		letra_com_o_dado_de_apoio = pilha_lst_pop(ordem_nova);

		//Coloca na pilha
		pilha_lst_push(resposta, letra_procurando_seu_lugar);
		printf("I");

		//Se forem iguais, significa que encontramos nosso vagão!
		if (letra_procurando_seu_lugar == letra_com_o_dado_de_apoio) {

			//Não precisamos mais dessa letra, podemos jogá-la fora
			lixo = pilha_lst_pop(resposta);
			printf("R");
		}

		/*Se em todas as vezes precisamos insererir e remover cada letra, colocando quant*2 na condição rodariamos somente o necessário
		*Condição provisória*/
		i++;
	} while ( i < MAX_VAOGOES);

	//Se no fim de tudo a pilha "resposta" não estiver vazia, significa que a organização foi impossível
	if (pilha_lst_vazia(resposta) != FALHA) {
		printf("   Impossivel");
	}

	/* Ao compilar o código a resposta é:
	* 
	* ENTRADA
	* Quantidade de vagões - 4
	* Ordem atual - e t d a
	* Ordem desejada - d a t e
	* 
	* SAIDA
	* 
	* IIIRIRPilha vazia
	* 
	* 
	*/

	//Se chegamos até aqui, deu tudo certo!!
	return SUCESSO;
}
