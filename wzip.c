#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        for(int cont = 0; getline (&linhaLida, &tamanhoLinha, pArquivo) != EOF; cont ++) {

            for(letraLida = 0; strlen(linhaLida) >= letraLida; letraLida++) {
                
                if(linhaLida[cont] == linhaLida[letraLida]) {
                    quantidadeLetra++;
                } 
                else {
                    //printf("%d", quantidadeLetra);
                    fwrite(&quantidadeLetra, 4, 1, stdout);
                    fwrite(&linhaLida[cont], 1, 1, stdout);
                    quantidadeLetra = 1;
    
                    
                }
                
                cont = letraLida;
            }

        }

    }

}

int main(int argc, char *argv[]) {

    if(argc == 0) {
        printf("wzip: arquivo1 [arquivo2 ...]");
        exit(1);
    }

    else {
    
        for(int palavra = 1; palavra < argc; palavra++) {
                
            abrirArquivo(argv[palavra]);
            
        }
        exit(0);
    
    }
    
}