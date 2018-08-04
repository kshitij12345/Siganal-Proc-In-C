//Reference Wikipedia..

#include <stdio.h>
#include <stdlib.h>
#define NTICK 8
typedef double *p; // Pointer to array of desired length
typedef double word; // signal and coefficient data type

typedef struct _iirVars {
int P;//forwardFilterOrder
int Q;//backwardFilterOrder

p outputAinp;
p inputAinp;
p b;//Forward Coefficients
p a;//Backward Coefficients
p x;//Past Input
p y;//Past Output
} iirVars;


void iir(iirVars *a){

    int i,j;
    //double temp;
    for(i=0;i<NTICK;i++){
        a->x[0] = a->inputAinp[i];

        for(j=0;j<=a->P;j++){a->outputAinp[i]+=a->b[j]*a->x[j];}//printf("%lf * %lf = %lf \n",a->b[j],a->x[j],a->outputAinp[i]);
        for(j=1;j<=a->Q;j++){a->outputAinp[i]-=a->a[j]*a->y[j];}//printf("%lf * %lf = %lf \n",a->a[j],a->y[j],a->outputAinp[i]);
        a->outputAinp[i] = (a->outputAinp[i]/a->a[0]);
        a->y[0] = a->outputAinp[i];
        //printf("firsvar %lf   %lf   %lf \n",a->past[0],a->past[1],a->past[2]);
        for(j=a->P;j>=1;j--){a->x[j]=a->x[j-1];}//printf("%lf   %lf    %d \n",a->x[j],a->x[j-1],j);
        for(j=a->Q;j>=1;j--){a->y[j]=a->y[j-1];}//printf("%lf   %lf    %d \n",a->y[j],a->y[j-1],j);
        //a->past[1] = a->past[0];//somehow this works
       // printf("%d   %d \n",j,j-1);
        //a->past[a->0] = a->past[0];
    printf("end one iteration \n");
    }

}

int main()
{   int i;
    double input[8] = {1,1,1,1,1,1,1,1};
    double output[8] = {0,0,0,0,0,0,0,0};
    double forwardcoeff[4]={0.5,0.5,0.25,0.27};
    double backwardcoeff[4]={0.5,0.5,0.6,0.7};
    int P = 3;
    int Q = 3;
    double inpPast[4] = {0,3,2,1};
    double outPast[4] = {0,1,2,3};

    iirVars iir1;
    iir1.a = backwardcoeff;
    iir1.b = forwardcoeff;
    iir1.inputAinp = input;
    iir1.outputAinp = output;
    iir1.x = inpPast;
    iir1.y = outPast;
    iir1.P = P;
    iir1.Q = Q;

    iir(&iir1);


    printf("\n");
    for(i=0;i<8;i++){
        printf("%lf ",output[i]);
    }

    return 0;
}
