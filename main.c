#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "algo.h"
#define SIZE  9999
#define N 999
int main(){
    //A S T B D
//In command A we get amount of nodes to create, e.g 4, so we instantly create 4 nodes, ranging from 0 to n-1.
    char  graph[SIZE];
    char *command;
    char temp[2];
    fgets(graph,SIZE,stdin);
   // printf("TExt= %s\n", graph);
    command= (char*)malloc(strlen(graph));
    int i=0,cVal=0,commandTemp=0;
    //Substring?
    while(graph[i]!='\0'){
        cVal=graph[i];
        if (cVal==65||cVal==66||cVal==68||cVal==83||cVal==84||i==strlen(graph)-1)
        {
            if (i==strlen(graph)-1)
            {
                temp[0]=graph[i];
                strcat(command,temp);
            }
            switch (commandTemp)
            {
            case 65:
                /* code */
               // printf("command= %s, commandTemp= %d\n",command,commandTemp);
                A(command);
                break;
            case 66:
                /* code */
                //printf("command= %s, commandTemp= %d\n",command,commandTemp);
                B(command);
                break;
            case 68:
                /* code */
                //printf("command= %s, commandTemp= %d\n",command,commandTemp);
                D(command);
                break;
            case 83:
                /* code */
                //printf("command= %s, commandTemp= %d\n",command,commandTemp);
               printf("Dijsktra shortest path: %d \n",S(command,0,0,0));
                break;
            case 84:
                /* code */
                //printf("command= %s, commandTemp= %d\n",command,commandTemp);
                printf("TSP shortest path: %d \n",T(command));
                break;
            default:
                break;
            }
            free(command);
            command= (char*)malloc(strlen(graph));
            commandTemp=cVal;
            command[0]='\0';
        }
             temp[0]=graph[i];
        strcat(command,temp);
            
        i++;
    }
     //print(headNode);
     free(command);
     deleteGraph();
    return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

