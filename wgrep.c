#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void abrirArquivo(char *arquivoAtual, char *palavraBuscada) {

    FILE *pArquivo = fopen(arquivoAtual, "r");

    if (pArquivo == NULL) {
        printf("wgrep: não é possível abrir o arquivo <%s>\n", arquivoAtual);
        exit(1);
    }
    else {
        
        size_t tamanhoLinha = 10;
        char *linhaLida = (char *) malloc (tamanhoLinha);
    
        while(getline (&linhaLida, &tamanhoLinha, pArquivo) != EOF) {
            
            if(strstr(linhaLida, palavraBuscada)) {
                printf("%s", linhaLida);
            }

        }

        printf("\n----------- Fim do %s -----------\n", arquivoAtual);

    }

}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("wgrep: termo_de_busca [arquivo ...]");
        exit(1);
    }

    else {
        if(strstr(argv[1], ".txt")) {
            printf("Termo de Busca não informado");
        }

        else {
            for(int palavra = 2; palavra < argc; palavra++) {
                abrirArquivo(argv[palavra], argv[1]);
            }
            exit(0);
        }
            
        
        
    }
    

}