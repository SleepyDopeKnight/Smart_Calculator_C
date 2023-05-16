#ifndef SRC_SMARTCALC_H_
#define SRC_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack {
  double value;
  int type;
  // number - 1;
  // x - 2;
  // plus - 3;
  // minus - 4;
  // * - 5;
  // / - 6;
  // mod - 7;
  // ^ - 8;
  // ( - 9;
  // ) - 10;
  // sin - 11;
  // cos - 12;
  // tan - 13;
  // asin - 14;
  // acos - 15;
  // atan - 16;
  // sqrt - 17;
  // ln - 18
  // log - 19;
  int priority;
  // X и Число = 0, +- = 1, */mod = 2, ^ = 3, scatl = 4, () = -1;
  struct stack *next;
} stack;

typedef struct credit {
  double sum_credit;
  int time_credit;
  double procent;
  int type;
  double sum_pay;
  double over_pay;
  double month_pay;
} credit;

typedef struct deposit {
  double sum_deposit;
  int time_deposit;
  double procent;
  double nalog;
  int type;
  int capital_procent;
  int day_deposit[100][2];
  int day_pay[100][2];
  double pay_procent;
  double sum_nalog;
  double last_deposit;
} deposit;

// STACK
void push(stack **head, double value, int priority, int type);
int pop(stack **head, double *value, int *priority, int *type);
void peek(stack *head, double *value, int *priority, int *type);
void print_stack(stack *head);
void reverse_stack(stack **head, stack **reverse);
// PARSER
int valid_input(char *str);
int valid_func(char *str);
int check_func_place(char *str);
int check_bracket(char *str);
int check_operators_place(char *str);
int valid_str(char *str);
void pusher_str(char *str, double x, stack **head);
// RPN & CALCULATE
stack *rpn(stack **head);
double calculate(stack *ready);
double terminal(char *str, double x);
// CREDIT & DEPOSIT
int CreditCalc(credit *calc);
double round_rub(double x);
void deposit_no_cap(deposit *calc);
void deposit_daily_cap(deposit *calc);
void deposit_another_cap(deposit *calc);
int check_input(deposit *calc);
int DepositCalc(deposit *calc);
int transactions(deposit *calc, char *str);

#endif  // SRC_SMARTCALC_H_