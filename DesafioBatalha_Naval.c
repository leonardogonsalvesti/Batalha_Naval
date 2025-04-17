#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    
    int tabuleiroNaval[10][10];   

    
    //O codigo foi bem feito, então você pode determinar o tamanho do navio e a quantidade sem precisar mudar o codigo
    int tamanhoNavio = 3, quantidadeNavio = 5;
    //gerador de numeros aleatorios para melhor funcionalidade do codigo.
    srand(time(NULL));



    
    // inicializar o tabuleiro com zeros
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiroNaval[i][j]=0;            
        }  
    }
    
    //sorteio de onde vai aparecer os navios
    for (int i = 1; i <= quantidadeNavio; i++){
        
        // Sorteia um número de 0 a 99 baseado no numero de locais que em no tabuleiro.
        int linha = rand() % 10;
        int coluna = rand() % 10;
        printf("Sorteio Local Navio |%d|%d|\n",linha,coluna);
        //sorteia se vai ser no angulo x ou y.
        int direcao =rand() % 2; // Sorteia 0 ou 1   zero vai gerar um navio em x e 1 gera um navio em y. 
        int verificaPosisaoX = coluna;  
        int verificaPosisaoY = linha;    
        
        //faço a verificação se tem espaços suficientes para gerar um navio de tamos 3 casas, verifico também a posição que vai ser gerado o navio.
        if ((direcao ==0) && (verificaPosisaoX <=(9-tamanhoNavio))){  
            //garante que não tem navio no local          
            if ((tabuleiroNaval[linha][coluna] ==0)&&(tabuleiroNaval[linha][coluna+1]==0)&&(tabuleiroNaval[linha][coluna+2]==0)){                
                for (int i = 0; i < tamanhoNavio; i++){//NAVIO GERADO EM X.
                    tabuleiroNaval[linha][coluna+i]=1;
                    printf("X: valor da casa %d%d - %d\n",linha,coluna+i,tabuleiroNaval[linha][coluna+i]);
                } 
            }else{
                printf("Já existe um Navio aqui! Gerando em outro local\n");
                i--;
            }
        }else if ((direcao ==0)&&(verificaPosisaoX >(9-tamanhoNavio))){
            if ((tabuleiroNaval[linha][coluna]==0) && (tabuleiroNaval[linha][coluna-1]==0) && (tabuleiroNaval[linha][coluna-2]==0)){
                for (int i = 0; i < tamanhoNavio; i++){//NAVIO GERADO EM X.
                    tabuleiroNaval[linha][coluna-i]=1;
                    printf("X: valor da casa %d%d - %d\n",linha,coluna-i,tabuleiroNaval[linha][coluna-i]);
                }
                
            }else{
                printf("Já existe um Navio aqui! Gerando em outro local\n");
                i--;
            }    
        }else if ((direcao ==1) && (verificaPosisaoY >=0)&&(verificaPosisaoY <=(9-tamanhoNavio))){
            if ((tabuleiroNaval[linha][coluna]==0) && (tabuleiroNaval[linha+1][coluna]==0) && (tabuleiroNaval[linha+2][coluna]==0)){

                for (int i = 0; i < tamanhoNavio; i++){//NAVIO GERADO EM Y.
                    tabuleiroNaval[linha+i][coluna]=1;
                    printf("Y: valor da casa %d%d - %d\n",linha+i,coluna,tabuleiroNaval[linha+i][coluna]);
                } 
            }else{
                printf("Já existe um Navio aqui! Gerando em outro local\n");
                i--;
            }   
        }else if ((direcao ==1)&&(verificaPosisaoY >(9-tamanhoNavio))){
            if ((tabuleiroNaval[linha][coluna]==0) && (tabuleiroNaval[linha-1][coluna]==0) && (tabuleiroNaval[linha-2][coluna]==0)){
                for (int i = 0; i < tamanhoNavio; i++){//NAVIO GERADO EM Y.
                    tabuleiroNaval[linha-i][coluna]=1;
                    printf("Y: valor da casa %d%d - %d\n",linha-i,coluna,tabuleiroNaval[linha-i][coluna]);
                }
            }else{
                printf("Já existe um Navio aqui! Gerando em outro local\n");
                i--;
            }         
        }else{
            printf("Valor incorreto de dados! Execultar Novamente\n");
            break;
        }
        
          
    }

    printf("SAIDA DE DADOS DO JOGO\n");
    //local onde tem 1 é com navio e local onde tem zero é agua.
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d|",tabuleiroNaval[i][j]);
            if (j ==9)
            {
                printf("\n");
            }
                        
        }  
    }
    
    

    return 0;
}
