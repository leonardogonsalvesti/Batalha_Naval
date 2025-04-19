#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define TAM_NAVIO 3//GERADO ALEATORIAMENTE O LOCAL,VERIFICA SE EXISTE LOCAL DISPONIVEL E ADD NO LOCAL.
#define QUANT_NAVIO 2 //LOCAIS DOS NAVIOS SÃO GERADOS ALEATORIAMENTE , PODE SER EM Y OU EM X.
#define DIRECAO_NAVIO  (rand() % 2)

/*
    REPRESENTAÇÃO: 

        5 - REPRESENTA HABILIDADES.
        1 - REPRESENTA OS NAVIOS.
        0 - REPRESENTA A AGUA OU MAR.
*/

// Função para inserir habilidade no tabuleiro
void inserir_habilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int LINHA_x, int COLUNA_y) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Verifica se está dentro dos limites do tabuleiro
            if (i + LINHA_x < TAM_TABULEIRO && j + COLUNA_y < TAM_TABULEIRO) {
                tabuleiro[i + LINHA_x][j + COLUNA_y] = habilidade[i][j];
            }

            
        }
    }
}
int main(){

    
    int tabuleiroNaval[TAM_TABULEIRO][TAM_TABULEIRO] = {0}; // Inicializa com zeros

    int habilidade_cone[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int habilidade_cruz[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 5, 0, 0},
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0},
        {0, 0, 5, 0, 0}
    };
    int habilidade_octaedro[TAM_HABILIDADE][TAM_HABILIDADE] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0}
    };

    

    //O codigo foi bem feito, então você pode determinar o tamanho do navio e a quantidade sem precisar mudar o codigo
    int tamanhoNavio = TAM_NAVIO;
    int quantidadeNavio = QUANT_NAVIO;
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
        int direcao =DIRECAO_NAVIO; // Sorteia 0 ou 1   zero vai gerar um navio em x e 1 gera um navio em y. 
        int verificaPosisaoX = coluna;  
        int verificaPosisaoY = linha;  
        // Inserir habilidades em posições diferentes do tabuleiro

        //ADD HABILIDADES NO TABULEIRO
        inserir_habilidade(tabuleiroNaval, habilidade_cone, 0, 0);      // canto superior esquerdo
        inserir_habilidade(tabuleiroNaval, habilidade_cruz, 0, 5);      // canto superior direito
        inserir_habilidade(tabuleiroNaval, habilidade_octaedro, 5, 0);  // canto inferior esquerdo  
            
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
