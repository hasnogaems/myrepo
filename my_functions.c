#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// long double pow21(long double x, int pow){
//     long double y=x;
//     for(int i=1; i<pow;i++){
//         x=x*y;
//     }

// }
long double fact( double input){
    long double i=input;
    if(input!=0){
    while(i>1){
        input=input*(i-1);
        i--;
    }
    }
    else{input=1;}
    return input;
}

long double cosl21( double input){
    long double cosl21=0;
    int i=0;
    long double previous=1000;
    long double x;
    while(input>2*M_PI){
    input=input-(2*M_PI);
    }
    
    while(fabs(previous-cosl21)>0.000000001){
        previous=cosl21;
        x=((pow(-1, i)*pow(input, 2*i))/fact(2*i));

         if(x!=HUGE_VAL&&x!=-HUGE_VAL)cosl21=cosl21+((pow(-1, i)*pow(input, 2*i))/fact(2*i));
         
         
         i++;
     }
    
return cosl21;
}
//long double 



int main(int argc, double* argv[]){
 long double x=pow(2, 2);
 //double value=6660;
 //double value=(int)*argv[1][0];
 double value;
 
   printf("%Lf\n", argv[1][1]);
 
 //long double value=(long double) *argv[1];
 //printf("%Lf", x); // lf  выдает 0000000 так что есть разница Lf или lf
 printf("value=%lf\n", value);
printf("cos=%Lf\n", cosl21(value));
printf("math.h cos=%Lf\n", cosl(value));


    
}