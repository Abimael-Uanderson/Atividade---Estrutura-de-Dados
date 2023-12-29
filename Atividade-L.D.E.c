#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *proximo;
	struct no *anterior;
}No;

void pilha(No **lista, int n) {
	No *novo = malloc(sizeof(No));
	
	
	if(novo) {
		novo -> valor = n;
		novo -> proximo = *lista;
		novo -> anterior = NULL;
		if(*lista) {
			(*lista)-> anterior = novo;
		}
		*lista = novo;
	}
}

void fila(No **lista, int n) {
	No *novo = malloc(sizeof(No));
	No *aux;
	
	if(novo) {
		novo -> valor = n;
		novo -> proximo = NULL;
		
		if(*lista == NULL) {
			novo -> anterior = NULL;
			*lista = novo;
		}else {
			aux = *lista;
			while(aux -> proximo) {
				aux = aux -> proximo;
				
			}
			aux -> proximo = novo;
			novo->anterior = aux;
		}
	}
}

void aleatoriaDepois(No **lista, int n, int vRef) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = n;

        if (*lista == NULL) {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux->valor != vRef && aux->proximo) {
                aux = aux->proximo;
            }

            novo->proximo = aux->proximo;
            aux->proximo = novo;

            if (novo->proximo) {
                novo->proximo->anterior = novo;
            }
            novo->anterior = aux;
        }
    }
}

void aleatoriaAntes(No **lista, int n, int vRef) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->valor = n;
        
        if (*lista == NULL) {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        } else {
            aux = *lista;
            while (aux != NULL && aux->valor != vRef) {
                aux = aux->proximo;
            }

            if (aux != NULL) {
                novo->proximo = aux;
                novo->anterior = aux->anterior;

                if (aux->anterior != NULL) {
                    aux->anterior->proximo = novo;
                } else {
                    *lista = novo;
                }

                aux->anterior = novo;
            } else {
                aux = *lista;
                while (aux->proximo != NULL) {
                    aux = aux->proximo;
                }

                aux->proximo = novo;
                novo->anterior = aux;
            }
        }
    }
}

No* buscar(No *lista, int num) {
    No *aux = lista;

    while (aux != NULL) {
        if (aux->valor == num) {
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}


No* remover(No **lista, int n) {
	No *remover = NULL;
	No *aux;
	if(*lista) {
		if((*lista)->valor == n) {
			remover = *lista;
			*lista = remover->proximo;
			if(*lista) {
				((*lista) -> anterior = NULL);
			}
			
		}else {
			aux = *lista;
			while(aux->proximo && aux->proximo->valor != n) {
				aux = aux -> proximo;
			}
			if(aux->proximo) {
				remover = aux->proximo;
				aux -> proximo = remover -> proximo;
				if(aux->proximo) {
					aux->anterior = aux;
				}
			}  
		}
	}
	return remover;
}

void impressaoRecursiva(No *no) {
	if(no) {
		printf("%d ", no -> valor);
		
		impressaoRecursiva(no -> proximo);
	}
}

int main() {
	No *remove, *lista = NULL, *busca;
	int opcao, saida, ref, antesOuDepois = 0;
	int valor;

do {	
    printf("\n\tDigite 1: Para inserir em Pilha\n\tDigite 2: Para inserir em Fila\n\tDigite 3: Para inserir Aleatoriamente\n\tDigite 4: Para remover um nó\n\tDigite 5: Para realizar a impressão da lista\n\tDigite 0: Para encerrar o programa.\n");
	printf("\n\tQual é a sua escolha? ");
	scanf("%i", &opcao);
	
	switch (opcao) {
		case 1:
		 do {
		     	printf("Informe o valor: ");
		 		scanf("%i", &valor);
		 
		 		pilha(&lista, valor);
		 		printf("------------Pilha-----------*\n");
		 	impressaoRecursiva(lista);
		 	printf("\n----------------------------*\n"); 

		 	printf("\nDigite 0 para voltar ao menu principal ou qualquer tecla para continuar a inserção na pilha: ");
			scanf("%i", &saida);
			
		 }while(saida);	
		 break;
		 
		case 2:
		 do {
		 		printf("Informe o valor: ");
		 		scanf("%i", &valor);
		 
		 		fila(&lista, valor);
		 		printf("------------Fila-----------*\n");
		 	impressaoRecursiva(lista);
		 	printf("\n----------------------------*\n"); 

		 		printf("\nDigite 0 para voltar ao menu principal ou qualquer tecla para continuar a inserção na fila: ");
				scanf("%i", &saida);
		 }while(saida);
		 break;
		 
		case 3:
		 do {
			    printf("Informe o valor: ");
			    scanf("%i", &valor);
			    
			    if(lista) {
			    	do {
			    		printf("Informe o valor de referencia: ");
			            scanf("%i", &ref);
			            
			            busca = buscar(lista, ref);
			            
					}while(busca == 0);
			    	
				}
			    
			    
			    
			    do {
			    	   printf("Desejas inserir o novo elemento ANTES ou DEPOIS do valor de referencia? \nDigite 1 para ANTES e 2 para depois: ");
			           scanf("%i", &antesOuDepois);
			           
			           
			    
				      if(antesOuDepois == 1) {
				    	aleatoriaAntes(&lista, valor, ref);
				    	
					  }else if(antesOuDepois == 2){
						aleatoriaDepois(&lista, valor, ref);
						
					  }else {
						printf("Opcao invalida \n");
						
					  }	
				}while(antesOuDepois != 2 && antesOuDepois != 1);
				
			     
			    printf("------------Lista Atualizada-----------*\n");
		 	impressaoRecursiva(lista);
		 	printf("\n----------------------------*\n"); 
 
			  
			    
			    printf("\nDigite 0 para voltar ao menu principal ou qualquer tecla para continuar: ");
			    scanf("%i", &saida);
		 }while(saida);
		break;
		
		case 4:
		 do {
		 	    printf("Informe o valor que deseja remover: ");
		 	    scanf("%i", &valor);
		 	    
		 	    remove = remover(&lista, valor);
		 	    if(remove) {
		 	    	printf("Numero a ser removido: %d\n", remove->valor);
		 	    	free(remove);
				 }else {
				 	printf("Numero nao encontrado");
				 }
		 	    impressaoRecursiva(lista);
		 	
		 	    printf("\nDigite 0 para voltar ao menu principal ou qualquer tecla para continuar: ");
			    scanf("%i", &saida);
		 }while(saida);
		 break;
		
		case 5:
			  printf("\n");
			  printf("Lista: ");
			  impressaoRecursiva(lista);
			  printf("\n");
		break;
			  
		default:
			   
			    if(opcao != 0) {
			    	printf("Opcao invalida!\n");
				}
					 
		
	}
}while(opcao);	
	
}
