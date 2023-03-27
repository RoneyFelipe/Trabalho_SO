#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void inteiroBinario(int valor, int *binario) {
    int n = valor; // Número de entrada
    int r; // Resultado do deslocamento
    int i; // Contador
    int cont = 0;
  
 // Utiliza um número de 32 bits como base para a conversão.
    for(i = 31; i >= 0; i--) {
        // Executa a operação shift right até a 
        // última posição da direita para cada bit.
        r = n >> i;
            
        // Por meio do "e" lógico ele compara se o valor 
        // na posição mais à direita é 1 ou 0 
        // e imprime na tela até reproduzir o número binário.
        if(r & 1) {
            binario[cont] = 1;
            cont ++;
        } else {
           binario[cont] = 0;
            cont++;
        }
    }

}

void abrirArquivo(char *arquivoAtual) {

    FILE *pArquivo = fopen(arquivoAtual, "r");

    //printf("Abri o arquivo e quero ser feliz\n");

    if (pArquivo == NULL) {
        printf("wzip: não é possível abrir o arquivo <%s>\n", arquivoAtual);
        exit(1);
    }
     else {
        
        
        
        size_t tamanhoLinha = 10;
        char *linhaLida = (char *) malloc (tamanhoLinha);
        int quantidadeLetra = 0;
        int letraLida = 0;
       /* getline (&linhaLida, &tamanhoLinha, pArquivo);
        printf("Linha lida %s", linhaLida);*/
        
        int binario[33];
        char binarioEscrever[6];
        
        /*char letraLida[2];
        int letraAscii;
        char caractere[5];*/

       // printf("Entreiii");

       // printf("Arquivo atual: %s", arquivoAtual);

        for(int cont = 0; getline (&linhaLida, &tamanhoLinha, pArquivo) != EOF; cont ++) {

           // printf("Linha lida %s", linhaLida);

           
           // printf("Aqui: %c", linhaLida[cont]);

           // printf("Tamanho linhda %d", strlen(linhaLida));
           int medidor = 0;
           char ultimo[1];

            for(letraLida = 0; strlen(linhaLida) >= letraLida; letraLida++) {
                
                if(linhaLida[cont] == linhaLida[letraLida]) {
                    quantidadeLetra++;
                } 
                else {
                    inteiroBinario(quantidadeLetra, binario);
                    quantidadeLetra = 1;
                    binarioEscrever[0] = binario[28] + '0';
                    binarioEscrever[1] = binario[29]  + '0';
                    binarioEscrever[2] = binario[30]  + '0';
                    binarioEscrever[3] = binario[31]  + '0';
                    if((linhaLida[cont] - '0')+48 < 100) {
                        binarioEscrever[4] = (((linhaLida[cont] - '0')+48)/10) + '0';
                        binarioEscrever[5] = (((linhaLida[cont] - '0')+48)%10) + '0';
                    }
                    else {
                        //printf("entreii");
                       
                            binarioEscrever[4] = (((linhaLida[cont] - '0')+48)/100) + '0';
                            
                            binarioEscrever[5]  = (((linhaLida[cont] - '0')+48)%100/10) + '0';
                            
                            ultimo[0] = (((linhaLida[cont] - '0')+48)%100%10) + '0';
                            medidor = 1;
                        
                    }
                    
                    printf("  ");
                    fwrite(binarioEscrever, 1, sizeof(binarioEscrever), stdout);
                    if(medidor) {
                        fwrite(ultimo, 1, sizeof(ultimo), stdout);
                    }
                }
                
                cont = letraLida;
            }
            binario[0] = '\0';
            binarioEscrever[0] = '\0';
        }

        printf("\n----------- Fim do %s -----------\n", arquivoAtual);

    }

}

int main(int argc, char *argv[]) {

    if(argc == 0) {
        printf("wzip: arquivo1 [arquivo2 ...]");
        exit(1);
    }

    else {
    
        for(int palavra = 1; palavra < argc; palavra++) {

            printf("Abri o aquivo\n");

            printf("%d Arquivo aberto: %s Abri o aquivo\n", argc, argv[palavra]);
                
            abrirArquivo(argv[palavra]);
            
        }
        exit(0);
        
            
        
        
    }
    
}