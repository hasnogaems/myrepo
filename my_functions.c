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
    x=1.0/0;
     
    
    
   
    x=((pow(-1, i)*pow(input, 2*i))/fact(2*i));
    if(x==INFINITY)printf("nan");
         if(x==-HUGE_VAL||x==HUGE_VAL)printf("-nan");
     if(!(input==INFINITY)){ //луп возникает именно тут и он возвращает nan как и ванильный если не уменьшать, поэтому ванильный наверное и не уменьшает. Странно сравнение с x не работает, а INFINITY работает
     while(fabs(input)>fabs(2*M_PI)){
    input=fabs(input)-fabs(2*M_PI);
    }
     }
    
    while(fabs(previous-cosl21)>0.000000001){
        previous=cosl21;
        

         if(x!=HUGE_VAL&&x!=-HUGE_VAL&&x!=INFINITY)cosl21=cosl21+((pow(-1, i)*pow(input, 2*i))/fact(2*i));
         
         
         
         i++;
     }
     
     /* else{
        cosl21=x;
     } */
    
return cosl21;
}
long double sin21(double input){
    int i=3;
    
    int flipflop=1;
    long double previous=input+1000;
    long double x;
    if(!(input==INFINITY)){
    while(fabs(input)>fabs(2*M_PI)){
    if(input>0)input=input-(2*M_PI);
    if(input<0)input=input+(2*M_PI);
    }
    }
    long double sin21=input-((pow(input, i))/fact(i));
    while(fabs(previous-sin21)>0.000000001){
        i=i+2;
        previous=sin21;
        x=((pow(input, i))/fact(i));
        
        if(flipflop)sin21=sin21+x;
        if(!flipflop)sin21=sin21-x;
        
        flipflop=!flipflop;
        
    }
    return sin21;//оно не ругалось если не было ретурна и возвращало nan, how the f

}



int main(int argc, double* argv[]){
 long double x=pow(2, 2);
 double value=-0;
 //double value=(int)*argv[1][0];
 //double value;
 printf("math.h cos=%Lf\n", cosl(value));
  // printf("%Lf\n", argv[1][1]);
 printf("cos=%Lf\n", cosl21(value));
 //long double value=(long double) *argv[1];
 //printf("%Lf", x); // lf  выдает 0000000 так что есть разница Lf или lf
 printf("value=%lf\n", value);

printf("math.h cos=%Lf\n", cosl(value));
printf("sin=%Lf\n", sin21(value));
printf("math.h sin=%Lf\n", sinl(value));


    
}