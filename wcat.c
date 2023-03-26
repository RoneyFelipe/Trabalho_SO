#include <stdio.h>
#include <stdlib.h>


void imprimirLinha(char *linha) {
    printf("%s", linha);
}

void abrirArquivo(char *arquivoAtual) {

    FILE *pArquivo = fopen(arquivoAtual, "r");

    if (pArquivo == NULL) {
        printf("wcat: não é possível abrir o arquivo <%s>\n", arquivoAtual);
        exit(1);
    }
    else {
        char linha[101];
        
        while(fgets(linha, 100, pArquivo)) {
            imprimirLinha(linha);
        }

        printf("\n----------- Fim do %s -----------\n", arquivoAtual);
        exit(0);
    }

}
int main(int argc, char *argv[]) {


    for(int palavra = 1; palavra < argc; palavra++) {

        abrirArquivo(argv[palavra]);

    }

}