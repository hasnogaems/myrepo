// mathlib.c
#include "s21_math.h"
#define NAN (0.0 / 0.0)
#define s21_INFINITY (1.0 / 0.0)

const double s21_M_E = 2.71828182845904523536028747135266250;
const double s21_M_PI = 3.14159265358979323846264338327950288;
long double s21_sqrtx(double base, double exp) {
  return s21_exp(s21_log(base) / exp);
}
int s21_isnan(long double x) { return (x != x); }
long double fact(double input) {
  long double i = input;
  if (input != 0) {
    while (i > 1) {
      input = input * (i - 1);
      i--;
    }
  } else {
    input = 1;
  }
  return input;
}

// 1
int s21_abs(int x) { return (x < 0 ? -x : x); }

// 2
long double s21_acos(double x) {
  if (x > 1.0) {
    x = 1.0;
  } else if (x < -1.0) {
    x = -1.0;
  }

  long double result = 3.141592653589793 / 2;
  long double term = 1.0;
  long double term_multiplier = x * x;
  long double factorial = 1.0;
  long double numerator = x;

  for (int n = 3; n < 50; n += 2) {
    numerator *= term_multiplier;
    factorial *= (n - 1) * n;
    term = numerator / factorial;
    result -= term / n;
  }

  return result;
}

// 3
long double s21_asin(double x) {
  if (x > 1.0) {
    x = 1.0;
  } else if (x < -1.0) {
    x = -1.0;
  }

  long double result = x;
  long double term = x;
  long double term_multiplier = x * x;
  long double factorial = 1.0;
  long double numerator = x;

  for (int n = 3; n < 50; n += 2) {
    numerator *= term_multiplier;
    factorial *= (n - 1) * n;
    term = numerator / factorial;
    result += term / n;
  }

  return result;
}

// 4
long double s21_atan(double x) {
  long double arctan_result;
  if (x == 0.0)
    arctan_result = 0.0;
  else {
    long double arccos_arg = 1.0 / s21_sqrt(1 + x * x);
    arctan_result = s21_acos(arccos_arg);
  }

  return arctan_result;
}

// 5
long double s21_ceil(double x) {
  if (x == s21_INFINITY || x == -s21_INFINITY || s21_isnan(x)) {
    return x;
  }
  long double integerPart = (int)x;
  long double decimalPart = x - integerPart;
  if (decimalPart > 0) {
    integerPart += 1;
  }
  return integerPart;
}

// 6

long double s21_cos(double input) {
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
// 7
long double s21_exp(double x) {
  long double result = 1.0;
  if (x == -s21_INFINITY) {
    result = 0;
  } else if (s21_isnan(x)) {
    result = NAN;
  } else if (x == s21_INFINITY)
    result = s21_INFINITY;
  else if (x == 0) {
    result = 1;
  } else {
    long double term = 1.0;
    long double precision = 1e-20; // Точность до 20 знаков после запятой
    long double term_contrib = term;
    for (int n = 1; s21_fabs(term_contrib) >= precision; n++) {
      term *= x / n;
      term_contrib = term;
      result += term;
    }
  }
  return result;
}

// 8
long double s21_fabs(double x) { return (long double)(x < 0 ? -x : x); }

// 9
long double s21_floor(double x) {
  if (x == s21_INFINITY || x == -s21_INFINITY || s21_isnan(x)) {
    return x;
  }
  long double intPart = (int)x;
  if (x >= 0 || intPart == x) {
    intPart += 1;
  }
  return intPart - 1;
}

// 10
long double s21_fmod(double x, double y) {
  long double res;
  if (s21_isnan(y) || s21_isnan(x) || y == 0.0 || x == s21_INFINITY) {
    res = NAN;
  } else if (x == 0.0) {
    res = x;
  } else {
    int digitX = x < 0 ? 0 : 1;
    int digitY = y < 0 ? 0 : 1;
    long double fabsX = s21_fabs(x);
    long double fabsY = s21_fabs(y);
    while (fabsX >= fabsY) {
      fabsX -= fabsY;
    }
    if ((digitX && digitY) || (digitX && !digitY)) {
      res = fabsX;
    } else {
      res = -fabsX;
    }
  }
  return res;
}
// 11
long double s21_log(double x) {
  long double result = 0.0;
  if (x < 0 || s21_isnan(x))
    result = NAN;
  else if (x == 0.0)
    result = -s21_INFINITY;
  else if (x == s21_INFINITY)
    result = s21_INFINITY;
  else if (x == s21_M_E)
    result = 1.0;
  else {
    long double term = (x - 1) / (x + 1);
    long double term_squared = term * term;
    long double power = term;
    long double precision = 1e-20;
    long double term_contrib = power;
    for (int n = 1; s21_fabs(term_contrib) >= precision; n += 2) {
      term_contrib = power / n;
      result += power / n;
      power *= term_squared;
    }

    result *= 2;
  }
  return result;
}

// 12

long double s21_pow(double base, double exp) {
  if (s21_isnan(exp) && (base == 0.0 || base == s21_INFINITY)) {
    return NAN;
  }
  if (exp == 0.0) {
    return 1.0;
  }
  if (s21_isnan(exp) && base == -s21_INFINITY) {
    return NAN;
  }
  if (s21_isnan(exp) && (base != 0.0 || base != s21_INFINITY)) {
    return base;
  }
  if (s21_isnan(base)) {
    return NAN;
  }

  if ((base == s21_INFINITY && exp < 0) ||
      (base == 0.0 && exp == s21_INFINITY) ||
      (base == s21_INFINITY && exp == -s21_INFINITY) ||
      (base == -s21_INFINITY && exp == -s21_INFINITY)) {
    return 0.0;
  }
  if (exp == -s21_INFINITY && base > 1) {
    return 0.0;
  }
  if (exp == -s21_INFINITY && (base < 0 || base == 1)) {
    return 1.0;
  }
  if (exp == s21_INFINITY && base > 0 && base < 1) {
    return 0;
  }
  if (base == s21_INFINITY || exp == s21_INFINITY || base == -s21_INFINITY) {
    return s21_INFINITY;
  }
  if (base < 0 && s21_fmod(exp, 2) == 1.0) {
    return -s21_exp(exp * s21_log(-base));
  }
  if (base < 0 && s21_fmod(exp, 2) == 0.0)
    return s21_exp(exp * s21_log(-base));

  return s21_exp(exp * s21_log(base));
}

// 13
long double s21_sin(double input) {
  int i = 3;

  int flipflop = 1;
  long double previous = input + 1000;
  long double x;
  if (!(s21_isnan(input) || input == s21_INFINITY || input == -s21_INFINITY)) {
    while (s21_fabs(input) > s21_fabs(2 * s21_M_PI)) {
      if (input > 0)
        input = input - (2 * s21_M_PI);
      if (input < 0)
        input = input + (2 * s21_M_PI);
    }
  }
  long double sin21 = input - ((s21_pow(input, i)) / fact(i));
  while (s21_fabs((double)(previous - sin21)) > 0.000000001) {
    i = i + 2;
    previous = sin21;
    x = ((s21_pow(input, i)) / fact(i));

    if (flipflop)
      sin21 = sin21 + x;
    if (!flipflop)
      sin21 = sin21 - x;

    flipflop = !flipflop;
  }
  return sin21; //оно не ругалось если не было ретурна и возвращало nan, how the
                //f
}

// 14
long double s21_sqrt(double x) { return s21_sqrtx(x, 2); }

// 15
long double s21_tan(double x) {
  long double result;
  long double sin_x = s21_sin(x);
  long double cos_x = s21_cos(x);
  if (cos_x == 0.0) {
    if (sin_x > 0.0) {
      result = s21_INFINITY;
    } else if (sin_x < 0.0) {
      result = -s21_INFINITY;
    } else {
      result = NAN;
    }
  } else if (s21_isnan(sin_x) || s21_isnan(cos_x)) {
    result = NAN;
  } else {
    result = sin_x / cos_x;
  }

  return result;
}
//для себя пока хз зачем
// long double s21_Round(double x){
//  return x-s21_fmod(x,0.000001) ;
// }
// long double s21_sqrtx( double base, double exp){
//       long double res;
//       long double i=0;
//       int koef=1;
// //тут тоже условия можно подредачить
// while(Round(res)!=Round(base)){
//   res=i;
//   for(int j=1;j<exp;j++)
//   res*=i;
//   if(res-base>0.000001 && !((res-base<0.000001)) ){
//       i-=1/s21_pow(10,koef);
//       koef++;
//   }
//   i+=1/s21_pow(10,koef);
// }
// return i;
// }
