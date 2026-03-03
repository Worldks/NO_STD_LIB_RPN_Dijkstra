#ifndef DIJKSTRA_FOR_RPN_SENTRY
#define DIJKSTRA_FOR_RPN_SENTRY

#include "stack_static_array.h"
#include "number_convert.h"
#include "string_operations.h"
#include "rpn.h"

void pop_before_openning_parenthesis(struct stack *dijkstra_stack, 
										struct stack *rpn_ptr);
void dijkstra_character_of_operation(struct stack *dijkstra_stack, struct stack *rpn_ptr, 
										const char *character_operation);

#endif
