#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 60
#define N 6
//Penso em titular e reserva , 0 para aqueles que tao no campo e 1 para reserva
//0 para Titular
//1 para Reserva

//Function para inserir no arquivo 
void insere_Cliente(Cliente *client,int *tamanho, FILE *out){

    printf("\n\nLista de Clientes no Arquivo Principal");

  bemVindo(client,tamanho,29,"Leonardo   ","09/12/2002",0);
  bemVindo(client,tamanho,14,"Lidiane    ","09/05/2001",0);
  bemVindo(client,tamanho,76,"Andre      ","04/01/2001",0);
  bemVindo(client,tamanho,75,"Ruth       ","06/07/1942",0);
  bemVindo(client,tamanho,59,"Agatha     ","12/12/2003",0);
  bemVindo(client,tamanho,6,"Cano        ","02/01/1988",0);
  bemVindo(client,tamanho,7, "Marcelo    ","12/05/1988",0);
  bemVindo(client,tamanho,74,"Andre      ","11/07/2001",0);
  bemVindo(client,tamanho,48,"Keno       ","10/09/1989",0);
  bemVindo(client,tamanho,46,"Ganso      ","12/10/1989",0);
  bemVindo(client,tamanho,10,"Fabio      ","30/09/1980",0);
  bemVindo(client,tamanho,18,"Lima       ","11/06/1996",0);
  bemVindo(client,tamanho,56,"Nino       ","10/04/1997",0);
  bemVindo(client,tamanho,20,"Jhon K     ","18/05/2002",0);
  bemVindo(client,tamanho,26,"Diogo B    ","17/08/1992",0);
  bemVindo(client,tamanho,4, "Samuel X   ","06/06/1990",0);
  bemVindo(client,tamanho,21,"Martinelli ","05/10/2001",0);
  bemVindo(client,tamanho,65,"David D.   ","24/01/1995",0);
  bemVindo(client,tamanho,22,"Felipe M.  ","26/06/1983",0);
  bemVindo(client,tamanho,49,"Aleksander ","08/10/2003",0);
  bemVindo(client,tamanho,11,"Fred       ","03/10/1983",0);
  bemVindo(client,tamanho,16,"Conca      ","11/05/1983",0);
  bemVindo(client,tamanho,8,"Thiago S    ","22/09/1984",0);
  bemVindo(client,tamanho,15,"Deco       ","27/08/1987",0);
  bemVindo(client,tamanho,5,"Carioca     ","31/01/2000",0);
  bemVindo(client,tamanho,19,"Brtt       ","19/02/1991",0);
  bemVindo(client,tamanho,50,"Titan      ","08/07/2000",0);
  bemVindo(client,tamanho,55,"Kami       ","02/04/1996",0);
  bemVindo(client,tamanho,25,"Dioud      ","03/11/1990",0);
  bemVindo(client,tamanho,66,"Mylon      ","08/11/1996",0);
  bemVindo(client,tamanho,57,"Sirt       ","20/10/1992",0);
  bemVindo(client,tamanho,77,"Takeshi    ","01/07/1993",0);
  bemVindo(client,tamanho,12,"Dynquedo   ","14/10/1997",0);
  bemVindo(client,tamanho,30,"Kuri       ","0808/2000",0);
  bemVindo(client,tamanho,17,"Wizer      ","29/11/1998",0);
  bemVindo(client,tamanho,9,"Revolta     ","27/12/1995",0);
  bemVindo(client,tamanho,54,"Baiano     ","09/04/1994",0);
  bemVindo(client,tamanho,78,"Esa        ","09/03/1994",0);
  bemVindo(client,tamanho,43,"Tockers    ","21/08/1996",0);
  bemVindo(client,tamanho,38,"Absolut    ","26/04/1998",0);
  bemVindo(client,tamanho,51,"Tinows     ","26/04/1990",0);
  bemVindo(client,tamanho,32,"Robo       ","21/08/1996",0);
  bemVindo(client,tamanho,58,"Pain       ","26/04/1998",0);
  bemVindo(client,tamanho,73,"Hornetts   ","21/08/1996",0);
  bemVindo(client,tamanho,79,"Code       ","26/04/1998",0);
    salva(client, *tamanho ,out);
}

int main(){
    
    Cliente clientes[MAX];               //Crio vetor de clientes
    memset(clientes,0,sizeof(Cliente));  //Inicializo com 0 para evitar pegar residuo
    int tam=0, sobrescreve=0;
    int count =0, menor =0;
    int acumula = 6,acaba=0;
   
    FILE *out = fopen("Principal.dat","w+b"); //Abro meu arquivo 

    insere_Cliente(clientes,&tam,out);       //Insiro meus clientes
    le_cliente(clientes,&tam,out);           //Leio os meus clientes
    printf("Total de clientes : %d\n",tam);
    int totaleRegistros = 0;
        
while(acaba<tam)
   {
    out = fopen("Principal.dat","w+b");//Abro meu out para ficar resetando dentro da function
    char *nomeArq=criarArq();         //Chamo a function que cria arquivo
    FILE *arquivo = fopen(nomeArq,"w+b");//Pego o nome pra function
    count=0;
    sobrescreve = 0;
 
    while(count<N && acaba<=tam){
        for(int j=acumula;j<=tam;j++){
           
        int tente = 0 ;
        menor=0;
        for(int i=0;i<6;i++){

                        while(clientes[menor].estado==1){
                                menor++;
                            if( menor>=6){
                                menor=0;
                                tente++;
                            }
                    
                            if(tente>=N){
                                break;
                            }
                        }
        
                if(tente>=N){
                    break;
                            }
            
                if(((clientes[menor].code)>(clientes[i].code))&&(clientes[i].estado!=1)){//Se o code do menor for maior do que o do i E estado do i for!=1 , so menor recebe i
                    menor = i;
                            }
                
                    }     
                if((clientes[menor].code)>(clientes[j].code)){//Se o code do menor for maior do que o do que vem pra sobrescrever , so congela
                    clientes[j].estado=1;            
                    count++; //Soma no contador
                    
                } 
                if(tente>=N)break;
                if((clientes[menor].estado)!=1){//Senao ta congelado , add na partition
                fwrite(&clientes[menor],sizeof(Cliente),1,arquivo);
                        
                }
            
                sobrescrever_cliente(menor,clientes,&tam,clientes[j].code,clientes[j].nome,clientes[j].aniversario,clientes[j].estado,out);//Sobrescreve j no menor 
                            
                    acaba++; 
                sobrescreve++; 
                        
            }
        
        } 
            acumula += sobrescreve;


            resetar_clientes(clientes,tam,out);
            printf("\nPartition : %s",nomeArq);
            le_cliente(clientes,&tam,arquivo);//Leio a saida do arquivo da partition
            totaleRegistros =totaleRegistros +  contarRegistros(arquivo);
            printf("Total de registros no arquivo: %d\n", totaleRegistros);
            le_cliente2(clientes,&tam,out);

            //Fechando os arquivos e desalocando memoria do nome do Arq criado
            fclose(out);
            fclose(arquivo);
            free(nomeArq);
    
            }
        

        return 0;
} 

//Deduction : Pensei em pegar N registros , e ir substituindo , assim que todos forem 1 no estado , eu termino esta partition . Inicializo a outra trocando o estado para 0 , e ai que a magica acontece , com dois for , um interior por i que vai ate menor que N , e um exterior para j que inicia em N e vai ate menor que tam , eu sempre vou comparar aonde eu parei 