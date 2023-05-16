#include "SmartCalc.h"

void push(stack **head, double value, int priority, int type) {
  stack *tmp = malloc(sizeof(stack));
  tmp->value = value;
  tmp->priority = priority;
  tmp->type = type;
  tmp->next = *head;
  *head = tmp;
}

int pop(stack **head, double *value, int *priority, int *type) {
  stack *prev = NULL;
  int res = 0;
  if ((*head) != NULL) {
    prev = (*head);
    if (value != NULL) *value = prev->value;
    if (priority != NULL) *priority = prev->priority;
    if (type != NULL) *type = prev->type;
    *head = (*head)->next;
    free(prev);
  } else {
    res = 1;
  }
  return res;
}

void peek(stack *head, double *value, int *priority, int *type) {
  if (value != NULL) *value = head->value;
  if (priority != NULL) *priority = head->priority;
  if (type != NULL) *type = head->type;
}

// void print_stack(stack *head) {
//   int i = 1;
//   while (head) {
//     printf("%d value %f\n", i, head->value);
//     printf("%d priority %d\n", i, head->priority);
//     printf("%d type %d\n", i, head->type);
//     printf("\n");
//     head = head->next;
//     i++;
//   }
// }

void reverse_stack(stack **head, stack **reversed) {
  double value = 0;
  int priority = 0;
  int type = 0;
  while (!pop(head, &value, &priority, &type))
    push(reversed, value, priority, type);
}

// PARSER

int valid_input(char *str) {
  char allow_symbols[33] = {'0', '1', '2', '3', '4', '5', '6', '7',
                            '9', 'x', 'a', 'c', 'o', 's', 'i', 'n',
                            't', 'q', 'r', 'l', 'g', 'm', '+', '-',
                            '/', '*', '^', '(', ')', '.', '8', 'd'};
  int res = 0;
  while (*str != '\0') {
    if (strlen(str) > 255) {
      res = 1;
      break;
    }
    int count = 0;
    for (size_t i = 0; i < strlen(allow_symbols); i++) {
      if (*str == allow_symbols[i]) {
        res = 0;
        count += 1;
        continue;
      }
    }
    if (*str == 'c' || *str == 'a' || *str == 's' || *str == 'l' ||
        *str == 't' || *str == 'm') {
      if (valid_func(str) == 0) {
        count += 1;
        if (*str == 't') str += 2;
        if (*str == 's') str += 1;
        if (*str == 'q') str += 2;
        if (*str == 'c') str += 3;
        if (*str == 'a') str += 3;
      } else {
        count = 0;
      }
    }
    if (count == 0) {
      res = 1;
      break;
    }
    str++;
  }
  return res;
}

int valid_func(char *str) {
  int res = 0;
  if (strncmp(str, "acos(", 5) == 0) {
    res = 0;
  } else if (strncmp(str, "asin(", 5) == 0) {
    res = 0;
  } else if (strncmp(str, "atan(", 5) == 0) {
    res = 0;
  } else if (strncmp(str, "log(", 4) == 0) {
    res = 0;
  } else if (strncmp(str, "sin(", 4) == 0) {
    res = 0;
  } else if (strncmp(str, "cos(", 4) == 0) {
    res = 0;
  } else if (strncmp(str, "tan(", 4) == 0) {
    res = 0;
  } else if (strncmp(str, "ln(", 3) == 0) {
    res = 0;
  } else if (strncmp(str, "sqrt(", 5) == 0) {
    res = 0;
  } else if (strncmp(str, "mod", 3) == 0) {
    res = 0;
  } else {
    res = 1;
  }
  return res;
}

int check_func_place(char *str) {
  int res = 0;
  char prev_char = '\0';
  char preprev_char = '\0';
  while (*str != '\0') {
    if (*str == 'c' || *str == 's' || *str == 'l' || *str == 't') {
      str--;
      if (*str == 'a') str--;
      if (*str == 'o') str -= 2;
      if (*str == 'a') str--;
      if (*str == 'r') str -= 3;
      if ((*str == '+' || *str == '-' || *str == '*' || *str == '/' ||
           *str == '(' || *str == ')' || *str == '^' || prev_char == '\0' ||
           preprev_char == '\0')) {
        str++;
        if (*str == 'a') str += 4;
        if (*str == 'c') str += 3;
        if (*str == 't') str += 3;
        if (*str == 's') str += 2;
        if (*str == 'r') str += 2;
        if (*str == 'l') str += 2;
      } else {
        res += 1;
        break;
      }
    }
    preprev_char = prev_char;
    prev_char = *str;
    str++;
  }
  return res;
}

int check_bracket(char *str) {
  int res = 0;
  int l_br = 0;
  int r_br = 0;
  char prev_char = '\0';
  while (*str != '\0') {
    if (*str == '(') l_br += 1;
    if (*str == ')') r_br += 1;
    if (r_br > l_br) res += 1;
    if (*str == ')' && prev_char == '(') res += 1;
    if ((*str == '(' &&
         (prev_char == ')' || (prev_char >= '0' && prev_char <= '9'))))
      res += 1;
    prev_char = *str;
    str++;
  }
  if (l_br != r_br) res += 1;
  return res;
}

int check_operators_place(char *str) {
  stack *head = NULL;
  int res = 0;
  char prev_char = '\0';
  while (*str != '\0') {
    if ((*str == '+' || *str == '-' || *str == '*' || *str == '/' ||
         *str == '^') &&
        (prev_char == '+' || prev_char == '-' || prev_char == '*' ||
         prev_char == '/' || prev_char == '^' || head != NULL))
      res += 1;
    if (*str == 'x' &&
        (prev_char == 'x' || (prev_char >= '0' && prev_char <= '9')))
      res += 1;
    if ((*str >= '0' && *str <= '9') && prev_char == 'x') res += 1;
    if ((*str == ')' || *str == '*' || *str == '/' || *str == '^') &&
        (prev_char == '(' || prev_char == '\0'))
      res += 1;
    if (*str == '.' || *str == 'm') {
      str--;
      if (*str >= '0' && *str <= '9') {
        str += 2;
        if (*str == 'o') str += 2;
        if (*str >= '0' && *str <= '9') {
          str--;
        } else {
          res += 1;
        }
      } else {
        res += 1;
        break;
      }
    }
    prev_char = *str;
    str++;
  }
  if (*str == '\0' && (prev_char == '+' || prev_char == '-' ||
                       prev_char == '*' || prev_char == '/'))
    res += 1;
  return res;
}

int valid_str(char *str) {
  int res = 0;
  if (valid_input(str) == 0 && check_bracket(str) == 0 &&
      check_func_place(str) == 0 && check_operators_place(str) == 0) {
    res = 0;
  } else {
    res += 1;
  }
  return res;
}

void pusher_str(char *str, double x, stack **head) {
  if (valid_str(str) == 0) {
    while (*str != '\0') {
      if ((*str >= '0' && *str <= '9') || *str == '.') {
        push(head, atof(str), 0, 1);
        while ((*str >= '0' && *str <= '9') || *str == '.') str++;
      }
      if (*str == '-') {
        str--;
        if (*str == '(') push(head, 0, 0, 1);
        str++;
        if (*head == NULL) push(head, 0, 0, 1);
        push(head, 0, 1, 4);
      } else if (*str == '+') {
        str--;
        if (*str == '(') push(head, 0, 0, 1);
        str++;
        if (*head == NULL) push(head, 0, 0, 1);
        push(head, 0, 1, 3);
      } else if (*str == 'x') {
        push(head, x, 0, 2);
      } else if (*str == '*') {
        push(head, 0, 2, 5);
      } else if (*str == '/') {
        push(head, 0, 2, 6);
      } else if (*str == 'm') {
        push(head, 0, 2, 7);
      } else if (*str == '^') {
        push(head, 0, 3, 8);
      } else if (*str == '(') {
        push(head, 0, -1, 9);
      } else if (*str == ')') {
        push(head, 0, -1, 10);
      } else if (*str == 'c') {
        push(head, 0, 4, 12);
        push(head, 0, -1, 9);
      } else if (*str == 't') {
        push(head, 0, 4, 13);
      } else if (*str == 'a' || *str == 's') {
        str++;
        if (*str == 'i') push(head, 0, 4, 11);
        if (*str == 's') push(head, 0, 4, 14);
        if (*str == 'c') {
          push(head, 0, 4, 15);
          push(head, 0, -1, 9);
        }
        if (*str == 't') push(head, 0, 4, 16);
        if (*str == 'q') {
          push(head, 0, 4, 17);
          str += 2;
        }
      } else if (*str == 'l') {
        str++;
        if (*str == 'n') push(head, 0, 4, 18);
        if (*str == 'o') push(head, 0, 4, 19);
      }
      str++;
    }
  }
}

// RPN & CALCULATE

stack *rpn(stack **head) {
  stack *support = NULL;
  stack *ready = NULL;
  double value = 0;
  int priority = 0;
  int type = 0;
  int support_priority = 0;
  while (!pop(head, &value, &priority, &type)) {
    if (priority == 0) push(&ready, value, priority, type);
    if (priority > 0 && priority < 5) {
      if (support != NULL) peek(support, NULL, &support_priority, NULL);
      double buf_value = value;
      int buf_priority = priority;
      int buf_type = type;
      while (support_priority >= priority) {
        pop(&support, &value, &priority, &type);
        push(&ready, value, priority, type);
        if (support != NULL) {
          peek(support, NULL, &support_priority, NULL);
          priority = buf_priority;
        } else {
          support_priority = -2;
        }
      }
      push(&support, buf_value, buf_priority, buf_type);
    }
    if (priority == -1) {
      if (type == 9) push(&support, value, priority, type);
      if (type == 10) {
        while (type != 9) {
          pop(&support, &value, &priority, &type);
          if (type != 9) push(&ready, value, priority, type);
        }
      }
    }
  }
  while (!pop(&support, &value, &priority, &type))
    push(&ready, value, priority, type);
  return ready;
}

double calculate(stack *ready) {
  double res = 0;
  stack *result = NULL;
  while (ready != NULL) {
    if (ready->priority == 0)
      push(&result, ready->value, ready->priority, ready->type);
    if (ready->type >= 3 && ready->type <= 8) {
      if (ready->type == 3) res = result->next->value + result->value;
      if (ready->type == 4) res = result->next->value - result->value;
      if (ready->type == 5) res = result->next->value * result->value;
      if (ready->type == 6) res = result->next->value / result->value;
      if (ready->type == 7) res = fmod(result->next->value, result->value);
      if (ready->type == 8) res = pow(result->next->value, result->value);
      pop(&result, NULL, NULL, NULL);
      pop(&result, NULL, NULL, NULL);
      push(&result, res, 0, 1);
    }
    if (ready->type > 10) {
      if (ready->type == 11) res = sin(result->value);
      if (ready->type == 12) res = cos(result->value);
      if (ready->type == 13) res = tan(result->value);
      if (ready->type == 14) res = asin(result->value);
      if (ready->type == 15) res = acos(result->value);
      if (ready->type == 16) res = atan(result->value);
      if (ready->type == 17) res = sqrt(result->value);
      if (ready->type == 18) res = log(result->value);
      if (ready->type == 19) res = log10(result->value);
      pop(&result, NULL, NULL, NULL);
      push(&result, res, 0, 1);
    }
    ready = ready->next;
  }
  double eq = 0;
  pop(&result, &eq, NULL, NULL);
  return eq;
}

double terminal(char *str, double x) {
  stack *head = NULL;
  pusher_str(str, x, &head);
  stack *reversed = NULL;
  reverse_stack(&head, &reversed);
  stack *ready = rpn(&reversed);
  reverse_stack(&ready, &reversed);
  double result = calculate(reversed);
  while (!pop(&reversed, 0, 0, 0)) {
    continue;
  }
  return result;
}
