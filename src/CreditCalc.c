#include "SmartCalc.h"

int CreditCalc(credit *calc) {
  int res = 0;
  if (calc->procent <= 0 || calc->time_credit <= 0 || calc->sum_credit <= 0) {
    res = 1;
  } else {
    if (calc->type == 1) {
      double proc_mes = ((double)calc->procent / 100) / 12;
      double per = (1. + pow((1. + proc_mes), (double)calc->time_credit)) - 1;
      calc->month_pay =
          round_rub(calc->sum_credit * ((proc_mes * per) / (per - 1)));
      calc->over_pay =
          round_rub((calc->month_pay * calc->time_credit) - calc->sum_credit);
      calc->sum_pay = round_rub(calc->month_pay * calc->time_credit);
    } else if (calc->type == 2) {
      double OD = calc->sum_credit / calc->time_credit;
      for (int i = 0; i < calc->time_credit; i++) {
        calc->sum_pay += round_rub(
            OD +
            ((calc->sum_credit - OD * i) * (double)calc->procent / 100) / 12);
      }
      calc->over_pay = round_rub(calc->sum_pay - calc->sum_credit);
      calc->month_pay = round_rub(calc->sum_pay / calc->time_credit);
    } else {
      res = 1;
    }
  }
  return res;
}

double round_rub(double x) {
  for (int i = 0; i < 3; i++) {
    x *= 10;
  }
  double res_x = x;
  while (res_x > 0) {
    res_x /= 10;
  }
  x /= 10;
  x = round(x);
  for (int i = 0; i < 2; i++) {
    x /= 10;
  }
  return x;
}
