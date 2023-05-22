#include <stdio.h>
#include <stdlib.h>


int main(void){
	char nomeArquivo[60];
	char ext[4] = {".txt"};
    int matriz[4][4];
    int matriz_sec[4][4];
    int encontrados[10];
    int i,j;
    int continua;
    
  	do{
  		system("cls");
		printf(" Digite o nome do arquivo: ");
		scanf("%s", nomeArquivo);
		
		strcat(nomeArquivo, ext); 	/// a funcao strcat cocaltena o valor da primeira variavel a segunda.
		
	    FILE *file;   ///cria ponteiro para um tipo de dados, padr√£o do C, do tipo file.
	    file = fopen( nomeArquivo,"r" ); /* A funcao fopen(), que est√° sendo atribuida ao ponteiro do tipo file,
										    abre o arquivo com o segundo atributo com letra "r" de read. O primeiro 
											atributo o caminho+nome+entensao do arquivo. */ 
											
	    if( file == NULL ){  //// verifica se o arquivo file pode ser lido
	    	system("cls");
	    	printf("\n Erro na leitura ou arquivo inexistente \n");
		}else{ 
	        for(i=0;i<4;i++){ //// percorre todo o arquivo lendo e atribuido a cada valor de i e j a matriz[][] em linhas e colunas   
	            for(j=0;j<4;j++){
	                fscanf(file,"%d",&matriz[i][j]);
	            }
	        }   
	        
	        
	        
	        
	        
	        /////////// funÁ„o boleana
	        int busca_largura(){
	        	///// recebe 2 valores e verifica se ha caminho
			}
	        
	        
	        
	        
	        
	        
	        
	        
	    	 printf("\n -----remove diagonal principal \n"); 
		 	for(i=0;i<4;i++){
	            for(j=0;j<4;j++){
	                if(i != j){
	                	printf("[%d]", matriz[i][j]);
					}
	            }
	            printf("\n");
	        }
	        
	        printf("\n -----remove linha1 \n");
	        
	    	for(i=0;i<4;i++){
	            for(j=0;j<4;j++){
	                if(i != 0){
	                	printf("[%d]", matriz[i][j]);
					}
	            }
	            printf("\n");
	        } 
	        
	        printf("\n --- remove linha 2 \n");
			for(i=0;i<4;i++){
	            for(j=0;j<4;j++){
	                if(i != 1){
	                	printf("[%d]", matriz[i][j]);
					}
	            }
	            printf("\n");
	        } 
		  
	         printf("\n --- remove coluna 3 \n"); 
			for(i=0;i<4;i++){
	            for(j=0;j<4;j++){
	                if(j != 2){
	                	printf("[%d]", matriz[i][j]);
					}
	            }
	            printf("\n");
	        } 
		  
	        
			
					
		}/// fim do else
		
			
		fclose(file); /// fecha o arquivo
	    printf("\n tecle 'Enter' para digitar um novo arquivo ou tecle 's' se para sair \n");
	    continua = getch();
	    
	}while (continua != 's'); 

	return 0;








/*

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
		*/
}






