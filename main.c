#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


int main(void){
	char nomeArquivo[60];
	char ext[4] = {".txt"};
    int matriz[7][7];
    int i,j;
    int continua;
    
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
		
		    //// fun��o boleana que verifica se tem caminho entre dois vertices
		    bool verifica_caminho(){
		    	return true;
			} 
			
		    printf("\n");
		}
   	   	fclose(file); /// fecha o arquivo
    
	    printf("\n tecle 'Enter' para digitar um novo arquivo ou tecle 's' se para sair \n");
	    continua = getch();
	    
	}while (continua != 's'); 

	return 0;

}



