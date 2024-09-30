#include "client.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

//Imprimir basico que mostra somente o codigo que eh chave inteira do cliente , conforme o solicitado pelo professor
void imprime(Cliente *client , int tamanho){
    for (int i=0;i<tamanho;i++){
        printf("\nCodigo do Cliente : %d   ",client[i].code);    
    }
         printf("\n*********************************\n");
}

//BemVindo ao time , insiro meu cliente no meu time ele ja e registrado pra poder entrar em campo
void bemVindo(Cliente *client , int *tamanho, int code , char *nome , char *aniversario,int estado){
    client[*tamanho].code=code;
    strcpy(client[*tamanho].nome,nome);
    strcpy(client[*tamanho].aniversario,aniversario);
  
    client[*tamanho].estado=estado;
      (*tamanho)++;
}

//Salvamos a informação dele 
void salva(Cliente *client , int tamanho , FILE *out){
     rewind(out);
    for(int i=0;i<tamanho;i++){
      fwrite(&client[i], sizeof(Cliente), 1, out);
    }
}

//Aqui lemos em si e temos um contador
int le(Cliente *client,FILE *in){
    rewind(in);
        int contador =0;
        while(fread(&client[contador],sizeof(Cliente),1,in)==1)
        {
            contador++;
        }
        return contador;

}

//Senao a mais importante , mas uma das funcoes mais importantes que implementamos , aqui subsituimos um por outro para manter nosso codigo rodando conforme a logica adotada
void sobrescrever_cliente(int index, Cliente *clientes, int *tamanho, int newCode, char *newNome, char *newAniversario,int estado,FILE *out) {
    rewind(out);
    if (index < 0 || index >= *tamanho) { 
        printf("Eita ta fora do esperado\n");
        return;
    }

    clientes[index].code = newCode;
    clientes[index].estado=estado;
    strncpy(clientes[index].nome, newNome, sizeof(clientes[index].nome) - 1);
    clientes[index].nome[sizeof(clientes[index].nome) - 1] = '\0'; // Garante que a string esteja terminada
    strncpy(clientes[index].aniversario, newAniversario, sizeof(clientes[index].aniversario) - 1);
    clientes[index].aniversario[sizeof(clientes[index].aniversario) - 1] = '\0'; // Garante que a string esteja terminada
    salva(clientes, *tamanho, out);
}

//Leio o cliente e imprime na tela
void le_cliente(Cliente *client , int *tamanho ,FILE *in) {
                    rewind(in);
                    printf("\n");
                    *tamanho=le(client,in);
                    if(*tamanho>0){
                        imprime(client,*tamanho);
                    }else {
                        printf("Sem cliente");
                    }
    }

void le_cliente2(Cliente *client , int *tamanho ,FILE *in) {
                    rewind(in);
                    printf("\n");
                    *tamanho=le(client,in);
                
    }

//Contador estatico
int contadinho(){
    static int conta = 0;
    conta++;
    return conta;
}

//Criamos nosso arquivo com nome incrementado
 char  *criarArq(){
        char *nomeArq=malloc(20*sizeof(char));
        FILE *arquivo;

    snprintf(nomeArq,20,"Arquivo%d.dat",contadinho());
    arquivo = fopen(nomeArq,"w+b");
 
    fclose(arquivo);
    return nomeArq;
    }

//Contamos o registro de cada partition
int contarRegistros(FILE *arquivo) {
    fseek(arquivo, 0, SEEK_END); 
    long tamanhoArquivo = ftell(arquivo); 
    fseek(arquivo, 0, SEEK_SET); 
    return tamanhoArquivo / sizeof(Cliente); 
}


//Aqui resetamos o cliente , o que era 1 vira 0 , e vai pra jogo
void resetar_clientes(Cliente *clientes, int tam, FILE *out) {
    for(int i = 0; i < tam; i++) {
        clientes[i].estado = 0; 
        sobrescrever_cliente(i, clientes, &tam, clientes[i].code, clientes[i].nome, clientes[i].aniversario, clientes[i].estado, out);
    }
}