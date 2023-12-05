#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// long double pow21(long double x, int pow){
//     long double y=x;
//     for(int i=1; i<pow;i++){
//         x=x*y;
//     }

// }
long double fact(long double input){
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

long double cosl21(long double input){
    long double cosl21=0;
    int i;
    long double x;
    long double previous=1000;
    if(1){
    
    for(i=0;i<200;i++){
        if(i==199)
        printf("bugged iteration %Lf\n", ((pow(-1, i)*pow(input, 2*i))/fact(2*i)));
        printf("on iteration%d %Lf\n", i, cosl21);
        x=cosl21+((pow(-1, i)*pow(input, 2*i))/fact(2*i));
        if(x!=HUGE_VAL&&x!=-HUGE_VAL) cosl21=cosl21+((pow(-1, i)*pow(input, 2*i))/fact(2*i));
         
         previous=cosl21;
     }
    

}//как  это вообще работает оно должно идти в deadloop
else{
    printf("value from 0 to 6.28318");

}
return cosl21;
}

int main(int argc, char** argv){
 long double x=pow(2, 2);
 int value=6;
 //printf("%Lf", x); // lf  выдает 0000000 так что есть разница Lf или lf
 
printf("cos=%Lf\n", cosl21(value));
printf("math.h cos=%Lf\n", cosl(value));
 printf("fact of 3=%Lf\n", fact(0));

    
}