#include <stdio.h>
#include <stdlib.h>


int main(void){
	char nomeArquivo[61];
	char ext[4] = {".txt"};
    int matriz[7][7];
    int vet[2];
    int i,j;
    int continua;
    
  	do{
  		system("cls");
		printf(" Digite o nome do arquivo: ");
		scanf("%s", nomeArquivo);
		
		strcat(nomeArquivo, ext); 	/// a função strcat cocaltena o valor da primeira variavel a segunda.
		
	    FILE *file;   ///cria ponteiro para um tipo de dados, padrão do C, do tipo file.
	    file = fopen( nomeArquivo,"r" ); /* A função fopen(), que está sendo atribuida ao ponteiro do tipo file,
										    abre o arquivo com o segundo atributo com letra "r" de read. O primeiro 
											atributo é o caminho+nome+entensão do arquivo. */ 
											
	    if( file == NULL ){  //// verifica se o arquivo file pode ser lido
	    	system("cls");
	    	printf("\n Erro na leitura ou arquivo inexistente \n");
		}else{ 
	        for(i=0;i<7;i++){ //// percorre todo o arquivo lendo e atribuido a cada valor de i e j a matriz[][] em linhas e colunas   
	            for(j=0;j<7;j++){
	                fscanf(file,"%d",&matriz[i][j]);
	            }
	        }
	   
			fflush(stdin);  /// limpa o bufer 
			system("cls");
		    printf("\n---| Matriz %s: |---\n", nomeArquivo);
		    printf("\n");
		
		    for(i=0;i<7;i++){ //// percorre toda a matriz[][] em linhas e colunas e printa na tela
		        for(j=0;j<7;j++){
		            printf(" [%d]",matriz[i][j]); /// mostra a matriz na tela
		        }
		        printf("\n");
		    }
		
		    
		    //// pega dois vertice e joga em um vetor
		    for(i=0;i<7;i++){ 
		        for(j=0;j<7;j++){   ////// i representa numero de linhas  e j representa numero de colunas 
					if(i==1 && j==2){
							vet[0] =  matriz[i][j]; //// atribui 1 vertice a 1° posição do vetor
							vet[1] =  matriz[j][i]; //// atribui o vertice de ligação a 2° posição do vetor
					} 		
		        }
		    }		
											/*
		    											 for(i=0;i<7;i++){ 
													        for(j=0;j<7;j++){   ////// i representa numero de linhas  e j representa numero de colunas 
																if(i==1 && j==0){
																		vet[0] =  matriz[i][j]; //// atribui 1 vertice a 1° posição do vetor
																} 
																if(i==0 && j==1){  ////// i representa numero de linhas  e j representa numero de colunas 
																	vet[1] =  matriz[i][j]; // atribui 1 vertice a 2° posição do vetor
																}
													        }
													    }
		    										*/
		    
		    printf("\n vetor com dois vertices selecionados \n");
		    for(i=0;i<2;i++){
				printf(" [%d]", vet[i]); /// mostra o vetor na tela
			} 
			
		    printf("\n");
		}
   	   	fclose(file); /// fecha o arquivo
    
	    printf("\n tecle 'Enter' para digitar um novo arquivo ou tecle 's' se para sair \n");
	    continua = getch();
	    
	}while (continua != 's'); 

	return 0;

}
