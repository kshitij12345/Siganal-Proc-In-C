#include <stdio.h>
#include <stdlib.h>
#define N 3//first input

int* pad(int* paddedarray,int* array,int arrlen,int M){
    int i;
    for(i=0;i<M-1;i++){
        paddedarray[i] = 0;
        printf("%d \n ",i);
    }
    for(i=M-1;i<M+2;i++){
        paddedarray[i] = array[i-(M-1)];
        printf("%d %d \n",i,i-M);
    }

    for(i=M+2;i<2*M-1+3;i++){
        paddedarray[i] = 0;
        printf("%d \n",i);
    }

    for(i=0;i<7;i++){
        printf("%d ",paddedarray[i]);
    }
    printf("\n");
    return paddedarray;
}


int main()
{
    int M =3;//Second input
    int i12[8] = {1,2,3};
    int i2[3] = {-1,2,2};
    int out[5] = {0,0,0,0,0};
    int n,i,j,k,l;
    int i1[3+2*(M-1)];

    pad(i1,i12,N,M);

    for(i=0;i<3+2*(3-1);i++){
        printf("%d ",i1[i]);
    }
    printf("\n");
    for (n=0;n<N+M-1;n++){
        for(k=0;k<M;k++){
            out[n] += i1[n+k]*i2[N-1-k];
            printf("%d    %d  \n",i1[n+k],i2[N-1-k]);
        }
        printf("iteration %d \n",n);
    }

    for(i = 0;i<5;i++){
        printf("%d ",out[i]);
    }

    printf("\n Circular \n");
    i = N;
    while(i<M+N-1){
        printf("%d    %d \n",out[i%3],out[i]);
        out[i%N] += out[i];
        printf("%d    %d \n",out[i%N],out[i]);
        i++;
    }

    for(i=0;i<3;i++){
        printf("%d ",out[i]);
    }

}
