#ifndef STACK_STATICK_ARRAY_SENTRY
#define STACK_STATICK_ARRAY_SENTRY

#include "string_operations.h"
#include "calls.h"

enum { stack_size = 1024 };

struct stack {
	int free_space;     /* A.K.A. sp - stack pointer */
	int elements_count; /* number of strings in stack(array) */
	char array[stack_size];
};

void stack_init(struct stack *stack);
int is_stack_empty(struct stack *stack);
int push_char(struct stack *stack, char value);
char pop_char(struct stack *stack);
int pop_str(struct stack *stack, char *str);
int push_str(struct stack *stack, const char *str);
void delete_str_from_stack_top(struct stack *stack);
void print_stack(struct stack *stack);
#endif
