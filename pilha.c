#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

#define SUCESSO 0
#define RIGHT ')'
#define LEFT '('
#define SAIR '!'

int main(int argc, char** argv){


	Pilha_lst*right;
	Pilha_lst*left;

	char dado;
	int tam_right = 0, tam_left = 0;

	right = pilha_lst_cria();
	left = pilha_lst_cria();
	
	printf("\n\nColoque um caracter por vez (! para sair)\n\n");

	do{
		printf("- ");
		scanf(" %c", &dado);
		
		if (dado == RIGHT){
			pilha_lst_push(right, dado);
			tam_right++;
		}
		else if(dado == LEFT){
			pilha_lst_push(left, dado);
			tam_left++;
		}
		else if(dado != SAIR){
			printf("\n\nCaracter inválido, tente novamente\n\n");
		}
	}while(dado != SAIR);

	if(tam_right == tam_left){
		printf("\n\nExpressão bem formada!\n\n");
	}else{
		printf("\n\nExpressão mal formada!\n\n");
	}

	pilha_lst_libera(right);
	pilha_lst_libera(left);

	return SUCESSO;
}
