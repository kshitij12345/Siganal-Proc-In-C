#include <stdio.h>
#include <stdlib.h>
#define N 3

int main()
{
    int i1[N] = {1,2,3,2};
    int i2[N] = {-1,2,2,2};
    int out[7] = {0,0,0,0,0,0,0};
    int i,j,k,cnt,c;

    for(i = 0;i<N;i++){
        k = i;
        for(j=0;j<i+1;j++){
            out[i] += i1[k]*i2[j];
            printf("%d %d \n",k,j);
            k--;

        }
        printf("iteration %d \n ",i);
    }

    printf("Half end \n");
    /*cnt = N;
    c = N-2;
    for(i=N-1;i>=1;i--){
        k = N-1;
        for(j=1;j<i+1;j++){
            //out[cnt] += i1[j]*i2[k];

            printf("%d %d \n",j,k);
            k--;
        }
        cnt++;
        c--;
        printf("iteration %d \n ",i);

    }*/

    cnt = N;
    c = N-2;
    for(i=N-1;i>=1;i--){
        k = N-1;
        for(j=i-c;j<N;j++){
            out[cnt] += i1[j]*i2[k];

            printf("%d %d \n",j,k);
            k--;
        }
        cnt++;
        c=c-2;
        printf("iteration %d \n ",i);

    }

    for(i=0;i<7;i++){
        printf("%d ",out[i]);
    }

    exit(0);
}
