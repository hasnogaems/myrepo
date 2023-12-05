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
    if(input<6.28318&&input>0){
    
    while(abs(previous-cosl21>0.00001)){
         cosl21=cosl21+((pow(-1, i)*pow(input, 2*i))/fact(2*i));
         
         previous=cosl21;
         i++;
     }
    

}
else{
    printf("value from 0 to 6.28318");

}
return cosl21;
}

int main(int argc, char** argv){
 long double x=pow(2, 2);
 double value=6;
 //printf("%Lf", x); // lf  выдает 0000000 так что есть разница Lf или lf
 printf("fact of 3=%lf\n", value);
printf("cos=%Lf\n", cosl21(value));
printf("math.h cos=%Lf\n", cosl(value));


    
}