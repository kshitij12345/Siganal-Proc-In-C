#include <stdio.h>
#include <stdlib.h>
#define NTICK 8
typedef double *p; // Pointer to array of desired length
typedef double word; // signal and coefficient data type

typedef struct _fir3Vars {
p outputAinp;
p inputAinp;
word b0;
word b1;
word b2;
word s1;
word s2;
} fir3Vars;


typedef struct _firVars {
int filterlength;
p outputAinp;
p inputAinp;
p coeff;
p past;
} firVars;

void fir3(fir3Vars *a){

    int i;
    word input;
    for(i=0;i<NTICK;i++){
        input = a->inputAinp[i];
        a->outputAinp[i] = a->b0*input + a->b1*a->s1 + a->b2 * a->s2;
        printf("firs3var  %lf   %lf  %lf \n",input,a->s1,a->s2);
        a->s2 = a->s1;
        a->s1 = input;
    }
}

void fir(firVars *a){

    int i,j;
    double temp;
//    word input;
    for(i=0;i<NTICK;i++){
        temp = a->inputAinp[i];
        a->past[0] = temp;
        for(j=0;j<a->filterlength;j++){a->outputAinp[i]+=a->coeff[j]*a->past[j];}
        //printf("firsvar %lf   %lf   %lf \n",a->past[0],a->past[1],a->past[2]);
        for(j=a->filterlength-1;j>=1;j--){a->past[j]=a->past[j-1];}
        //a->past[1] = a->past[0];//somehow this works
       // printf("%d   %d \n",j,j-1);
        //a->past[a->0] = a->past[0];

    }
}

int main()
{   int i;
    double input[8],input1[8];
    double output[8],output1[8];
    double coeff[3]={0.5,0.25,0.27};
    double sig[3]={0,200,1.01};
    for (i=0;i<8;i++){
        input[i] = 1.0;
        input1[i] = 1.0;
        output[i]=0;
        output1[i]=0;
    }
    fir3Vars f;
    firVars fe;
    fe.inputAinp = &input1;
    fe.outputAinp = &output1;
    fe.coeff = &coeff;
    fe.past = &sig;
    fe.filterlength = 3;
    f.inputAinp = &input;
    f.outputAinp = &output;

    f.b0 = 0.5;
    f.b1 = 0.25;
    f.b2 = 0.27;
    f.s1 = 200;
    f.s2 = 1.01;

    fir3(&f);
    fir(&fe);
    for(i=0;i<8;i++){
        printf("%lf ",output[i]);
    }
    printf("\n");
    for(i=0;i<8;i++){
        printf("%lf ",output1[i]);
    }

    return 0;
}
