#include <stdio.h>
#include <stdlib.h>

//#include <>

int main(void){
	char nomeArquivo[60];
	char ext[4] = {".txt"};
    int matriz[5][5];
    int encontrados[5];
    int i,j;
    int continua;
    
    int tot, ver, indice;
    
    bool teste (int x){
    	bool aux;
    	aux = false;
 		for (i=1; i<= tot; i++){
 			if (x = encontrados[i]){
 				aux = true;
			 }
		 }
		 return aux;   	
    	
	}
    
    
    
  	do{
  		system("cls");
		printf(" Digite o nome do arquivo: ");
		scanf("%s", nomeArquivo);
		
		strcat(nomeArquivo, ext); 	/// a funcao strcat cocaltena o valor da primeira variavel a segunda.
		
	    FILE *file;   ///cria ponteiro para um tipo de dados, padrão do C, do tipo file.
	    file = fopen( nomeArquivo,"r" ); /* A funcao fopen(), que está sendo atribuida ao ponteiro do tipo file,
										    abre o arquivo com o segundo atributo com letra "r" de read. O primeiro 
											atributo o caminho+nome+entensao do arquivo. */ 
											
	    if( file == NULL ){  //// verifica se o arquivo file pode ser lido
	    	system("cls");
	    	printf("\n Erro na leitura ou arquivo inexistente \n");
		}else{ 
	        for(i=1;i<6;i++){ //// percorre todo o arquivo lendo e atribuido a cada valor de i e j a matriz[][] em linhas e colunas   
	            for(j=1;j<6;j++){
	                fscanf(file,"%d",&matriz[i][j]);
	            }
	        }  

	        
	        
	        tot = 1;
	        
	        indice = 0;
	        encontrados [tot] = 1;
	        
	        
	        do { 
	        	indice = indice + 1;
	        	ver = encontrados[indice]
	        	for (j = 1; j<6; j++){
	        		if (matriz [ver,j] = 1  and !teste (j)) {
						tot = tot + 1;
						encontrados[tot] = j;						
					}
	        		
	        		
				}
	        
	        	
	        
			} while (indice != tot);
	        
	        
	        printf("As liga��es de vertices sao:\n"); /// percorre
		 	for(i=0;i<5;i++){
		 		printf("%d-> ", i+1);
	            for(j=0;j<5;j++){
	                if(matriz[i][j] == 1){
	                	printf("[%d]", j+1);
	                	
	                	if( matriz[i][j] != 0 && matriz[i][j] != j-1 != matriz[i][j] != j){
	                		encontrados[i] = j+1;
						}
	                
					}
	            }
	            printf("\n");	
			}
	        
	        for(i=0;i<5;i++){
				printf("[%d]", encontrados[i]);
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






