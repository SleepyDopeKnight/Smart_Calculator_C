#include "SmartCalc.h"

void deposit_no_cap(deposit *calc) {
  double bet = calc->procent / 100;
  int count = 0;
  while (count != calc->time_deposit) {
    for (int i = 0; calc->day_deposit[i][0] != 0; i++) {
      if ((calc->day_deposit[i][0]) == count) {
        calc->sum_deposit += round_rub(calc->day_deposit[i][1]);
      }
    }
    for (int i = 0; calc->day_pay[i][0] != 0; i++) {
      if ((calc->day_pay[i][0]) == count) {
        calc->sum_deposit -= round_rub(calc->day_pay[i][1]);
      }
    }
    calc->pay_procent +=
        round_rub((((calc->sum_deposit * bet * calc->time_deposit) / 365) /
                   calc->time_deposit));
    count++;
  }
  calc->pay_procent = round_rub(calc->pay_procent);
  calc->sum_nalog = round_rub(calc->pay_procent * (calc->nalog / 100));
  calc->last_deposit = round_rub(calc->sum_deposit + calc->pay_procent);
}

void deposit_daily_cap(deposit *calc) {
  double bet = calc->procent / 100;
  int count = 0;
  while (count != calc->time_deposit) {
    for (int i = 0; calc->day_deposit[i][0] != 0; i++) {
      if ((calc->day_deposit[i][0]) == count) {
        calc->sum_deposit += round_rub(calc->day_deposit[i][1]);
      }
    }
    for (int i = 0; calc->day_pay[i][0] != 0; i++) {
      if ((calc->day_pay[i][0]) == count) {
        calc->sum_deposit -= round_rub(calc->day_pay[i][1]);
      }
    }
    calc->pay_procent +=
        round_rub(((calc->sum_deposit * bet * calc->time_deposit) / 365) /
                  calc->time_deposit);
    calc->sum_deposit +=
        round_rub(((calc->sum_deposit * bet * calc->time_deposit) / 365) /
                  calc->time_deposit);
    count++;
  }
  calc->pay_procent = round_rub(calc->pay_procent);
  calc->sum_nalog = round_rub(calc->pay_procent * (calc->nalog / 100));
  calc->last_deposit = round_rub(calc->sum_deposit);
}

void deposit_another_cap(deposit *calc) {
  double bet = calc->procent / 100;
  int count = 0;
  double rez_procent = 0;
  int days = 0;
  if (calc->type == 2) {
    days = 31;
  } else if (calc->type == 3) {
    days = 91;
  } else if (calc->type == 4) {
    days = 183;
  } else if (calc->type == 5) {
    days = 364;
  }
  while (count != calc->time_deposit) {
    if (count % days == 0 && count != 0) {
      calc->sum_deposit += round_rub(calc->pay_procent);
      rez_procent += round_rub(calc->pay_procent);
      calc->pay_procent = 0;
    }
    for (int i = 0; calc->day_deposit[i][0]; i++) {
      if ((calc->day_deposit[i][0]) == count) {
        calc->sum_deposit += round_rub(calc->day_deposit[i][1]);
      }
    }
    for (int i = 0; calc->day_pay[i][0]; i++) {
      if ((calc->day_pay[i][0]) == count) {
        calc->sum_deposit -= round_rub(calc->day_pay[i][1]);
      }
    }
    calc->pay_procent +=
        (((calc->sum_deposit * bet * calc->time_deposit) / 365) /
         calc->time_deposit);
    count++;
  }
  calc->pay_procent = round_rub(calc->pay_procent) + rez_procent;
  calc->sum_nalog = round_rub(calc->pay_procent * (calc->nalog / 100));
  calc->last_deposit = round_rub(calc->sum_deposit + calc->pay_procent);
}

int check_input(deposit *calc) {
  int res = 0;
  if (calc->capital_procent < 0 || calc->capital_procent > 1) res = 1;
  if (calc->sum_deposit <= 0 || calc->time_deposit <= 0 || calc->nalog < 0 ||
      calc->procent <= 0)
    res = 1;
  if (calc->capital_procent == 1) {
    if (calc->type <= 0 || calc->type > 5) res = 1;
  }
  return res;
}

int DepositCalc(deposit *calc) {
  int res = check_input(calc);
  if (res == 0) {
    if (calc->capital_procent == 0) {
      deposit_no_cap(calc);
    } else {
      if (calc->type == 1) {
        deposit_daily_cap(calc);
      } else {
        deposit_another_cap(calc);
      }
    }
  }
  return res;
}

int transactions(deposit *calc, char *str) {
  int i = 0;
  int j = 0;
  int type_trans = 0;
  char num[10000] = {0};
  int check = 0;
  int len = 0;
  while (*str != '\0') {
    if (*str == 'p' && *(str + 1) == 'a') {
      type_trans = 1;
    } else if (*str == 'd' && *(str + 1) == 'e') {
      type_trans = 2;
    }
    if (strrchr("0123456789", *str)) {
      char *dest = str;
      while (strrchr("0123456789", *str)) {
        str++;
        len++;
      }
      strncpy(num, dest, len);
      if (type_trans == 1) {
        if (check == 0) {
          check = 1;
          sscanf(num, "%d", &calc->day_pay[i][0]);
        } else {
          check = 0;
          sscanf(num, "%d", &calc->day_pay[i][1]);
          i++;
        }
      } else {
        if (check == 0) {
          check = 1;
          sscanf(num, "%d", &calc->day_deposit[j][0]);
        } else {
          check = 0;
          sscanf(num, "%d", &calc->day_deposit[j][1]);
          j++;
        }
      }
    }
    str++;
  }
  return 0;
}
