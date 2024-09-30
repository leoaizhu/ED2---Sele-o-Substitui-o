#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>

//Esta é a biblioteca que usamos para client

//Definition da estrutrutura aqui
typedef struct Cliente{
    int code;
    char nome[50];
    char aniversario[20];
    int estado; // Criei a flag para estado de 0 - descongelado(Titular) e 1 - congelado(Reserva)
}Cliente;

//Function para imprimir na tela
void imprime(Cliente *client,int tamanho);

//Function para add cliente
void bemVindo(Cliente *client,int *tamanho, int code , char *nome , char *aniversario, int estado);

//Function para salvar cliente que adicionei
void salva(Cliente *client , int tamanho , FILE *out);

//Function para ler e retornar tamanho , extremamente importante
int le(Cliente *client,FILE *in);

//Function para sobrescrever clientes , porque vamos ficar trocando na medida em que ainda não congelamos todos os nossos N registros
void sobrescrever_cliente(int index, Cliente *clientes, int *tamanho, int newCode, char *newNome, char *newAniversario,int estado,FILE *out);

//Function para le cliente e vai usar a function imprime
void le_cliente(Cliente *client , int *tamanho ,FILE *in);

//Function para le cliente 2
void le_cliente2(Cliente *client , int *tamanho ,FILE *in);

//Function que serve como static int contador 
int contadinho(); 

//Function para criar arquivo que usei a contadinho para poder alterar o nome e ficar Arq%d
char  *criarArq();


//Function para Contar quantos registros tem em cada partition , achei bem util porque torna-se a prova real de no final ver se todos os clientes estao nas partition
int contarRegistros(FILE *arquivo);

//Function que reseta clientes , porque no final da primeira roda teremos N clientes congelados , e depois quero usar de novo e assim , preciso resetar eles para um novo "jogo"
void resetar_clientes(Cliente *clientes, int tam, FILE *out);


#endif