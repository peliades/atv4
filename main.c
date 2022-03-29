#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int numProcessos, quantum, clock, entrada;
    int parada = -1;

    scanf("%d", &numProcessos);
    scanf("%d", &quantum);

    int ** arrayProcessos = (int**)malloc(numProcessos * sizeof(int*));

    for (int i = 0; i < numProcessos; i++){
        arrayProcessos[i] = (int*)malloc(4 * sizeof(int));
    }

    for (int i = 0; i < numProcessos; i++){
        for (int j = 0; j < 2; j++){
            scanf("%d", &entrada);
            arrayProcessos[i][j] = entrada;
        }
    }

    int restam = 0;
    int holder [2];
    
    int responseTime = 0;
    int waitTime = 0;
    int finishTime = 0;



    for (int i = 0, clock =0; i != -1; i++, clock++){
        if (arrayProcessos[numProcessos - 1][1] <= 0){
            parada = -1;
        }

        if (restam = 1){
            i = i-1;
        }

        //finishTime
        for (int x = i; x < numProcessos; x++){
            if (arrayProcessos[x][0] >= clock){
                arrayProcessos[x][3] += 1;
            }
        }

        //waitTime
        for (int x = i; x < numProcessos; x++){
            if (arrayProcessos[x][0] != i){
                if (arrayProcessos[x][0] >= clock){
                arrayProcessos[x][4] += 1;
                }
            }
        }

        arrayProcessos[i][1] = arrayProcessos[i][1] - quantum;

        if (arrayProcessos[i][1] > 0){
            if (arrayProcessos[i+1][0] > clock){
                holder[0] = arrayProcessos[i][0];
                holder[1] = arrayProcessos[i][1];

                for (int e = i; e < numProcessos - 1; e++){
                    arrayProcessos[e][0] = arrayProcessos[e + 1][0];
                    arrayProcessos[e][1] = arrayProcessos[e + 1][1];
                }
                arrayProcessos[numProcessos-1][0] = holder [0];
                arrayProcessos[numProcessos-1][1] = holder [1];
                restam = 1;
                    
            }
            else{
                restam = 1;
            }
        }else{
            restam = 0;
        }
    }

    int finishTimeTotal = 0;
    for (int x = 0; x < numProcessos; x++){
        finishTimeTotal += arrayProcessos[x][3];

    }

    int finishTimeAvg = finishTimeTotal/numProcessos;

    int waitTimeTotal = 0;
    for (int x = 0; x < numProcessos; x++){
        waitTimeTotal += arrayProcessos[x][4];

    }

    int waitTimeAvg = waitTimeTotal/numProcessos;

    printf("RR: %d indisponivel  %d", finishTimeAvg, waitTimeAvg);
}