#include "s21_math.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_INFINITY (1.0 / 0.0)
// long double pow(long double x, int pow){
//     long double y=x;
//     for(int i=1; i<pow;i++){
//         x=x*y;
//     }

// }

// }

// long double fact( double input){
//     long double i=input;
//     if(input!=0){
//     while(i>1){
//         input=input*(i-1);
//         i--;
//     }
//     }
//     else{input=1;}
//     return input;
// }

long double cosl21(double input) {
  long double cosl21 = 0;
  int i = 0;
  long double previous = 1000;
  long double x;
  x = 1.0 / 0.0;

  x = ((s21_pow(-1, i) * s21_pow(input, 2 * i)) / fact(2 * i));
  if (x == s21_INFINITY)
    printf("nan");
  if (x == -s21_INFINITY || x == s21_INFINITY)
    printf("-nan");
  if (!(input ==
        s21_INFINITY)) { //луп возникает именно тут и он возвращает nan как и
                         //ванильный если не уменьшать, поэтому ванильный
                         //наверное и не уменьшает. Странно сравнение с x не
                         //работает, а INFINITY работает
    while (s21_fabs(input) > s21_fabs(2 * s21_M_PI)) {
      input = s21_fabs(input) - s21_fabs(2 * s21_M_PI);
    }
  }

  while (s21_fabs((previous - cosl21)) > 0.00000000001) {
    previous = cosl21;

    if (x != s21_INFINITY && x != -s21_INFINITY && x != s21_INFINITY)
      cosl21 =
          cosl21 + ((s21_pow(-1, i) * s21_pow(input, 2 * i)) / fact(2 * i));

    i++;
  }

  /* else{
     cosl21=x;
  } */

  return cosl21;
}
long double sin21(double input) {
  int i = 3;

  int flipflop = 1;
  long double previous = input + 1000;
  long double x;
  if (!(input == INFINITY)) {
    while (fabs(input) > fabs(2 * M_PI)) {
      if (input > 0)
        input = input - (2 * M_PI);
      if (input < 0)
        input = input + (2 * M_PI);
    }
  }
  long double sin21 = input - ((pow(input, i)) / fact(i));
  while (fabs((double)(previous - sin21)) > 0.000000001) {
    i = i + 2;
    previous = sin21;
    x = ((pow(input, i)) / fact(i));

    if (flipflop)
      sin21 = sin21 + x;
    if (!flipflop)
      sin21 = sin21 - x;

    flipflop = !flipflop;
  }
  return sin21; //оно не ругалось если не было ретурна и возвращало nan, how the
                //f
}

// long double tan21(double input){
//     long double tan21=0;
//    // long double previous=1000;

//         tan21=sin21(input)/cosl21(input);

//     return tan21;

// }

int main() {
  // long double x=pow(2, 2);
  double value = 0;
  //  //double value=(int)*argv[1][0];
  //  //double value;
  //  printf("math.h cos=%Lf\n", cosl(value));
  //   // printf("%Lf\n", argv[1][1]);
  //  printf("cos=%Lf\n", cosl21(value));
  //  //long double value=(long double) *argv[1];
  //  //printf("%Lf", x); // lf  выдает 0000000 так что есть разница Lf или lf
  //  printf("value=%lf\n", value);

  printf("math.h cos=%Lf\n", cosl(value));

  // printf("math.h sin=%Lf\n", sinl(value));
  // printf("math.h tan=%Lf\n", tanl(value));
  // printf("21 tan=%Lf", tan21(value));
  double k = 2 * s21_M_PI;
  for (int R = 20; R >= -20; R -= 4) {
    for (; k > -2 * s21_M_PI; k -= s21_M_PI / 17) {
      if (cos(k + R * s21_M_PI) != s21_cos(k + R * s21_M_PI)) {

        printf("x=%f s211=%Lf m=%f\n", k + R, s21_cos(k + R * s21_M_PI),
               cos(k + R * s21_M_PI));
      }
    }
  }
  printf("s21cos=%Lf\n", s21_cos(value));
  printf("cosl=%Lf", cosl21(value));
}