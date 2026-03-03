#include "../include/dijkstra_for_rpn.h"

static void check_correct_expression(struct stack *dijkstra_stack)
{
	int empty_stack = 0;
	char more_closed_brackets[] = "There are more closed brackets.\n";
	empty_stack = is_stack_empty(dijkstra_stack);
	if(empty_stack) {
		sys_write(1, more_closed_brackets, sizeof(more_closed_brackets));
		sys_exit(3);
	}
}

void pop_before_openning_parenthesis(struct stack *dijkstra_stack, struct stack *rpn_ptr)
{
	char buffer_string[max_number_length] = { 0 };
    int	stop_poping = 0;
	do {
		stop_poping = is_openning_parenthesis(&((dijkstra_stack->array)[dijkstra_stack->free_space]));
		if(stop_poping) {
			delete_str_from_stack_top(dijkstra_stack);
			break;
		}
		pop_str(dijkstra_stack, buffer_string);
		check_correct_expression(dijkstra_stack);
		push_str(rpn_ptr, buffer_string);
		compute_rpn(rpn_ptr);
	} while (!stop_poping);
}

void dijkstra_character_of_operation(struct stack *dijkstra_stack, struct stack *rpn_ptr, 
										const char *character_operation)
{
	enum compared_result compare;
	int openning_parenthesis_on_top;
	char buffer_string[max_operation_length] = { 0 };
   	openning_parenthesis_on_top = is_openning_parenthesis(&((dijkstra_stack->array)[dijkstra_stack->free_space]));
	if(openning_parenthesis_on_top){
		push_str(dijkstra_stack, character_operation);
		return;
	}
	compare = compare_operations(&((dijkstra_stack->array)[dijkstra_stack->free_space]), character_operation);
	switch(compare) {
		case equal:
		case greather:
			pop_str(dijkstra_stack, buffer_string);
			check_correct_expression(dijkstra_stack);
			push_str(rpn_ptr, buffer_string);
			compute_rpn(rpn_ptr);
			dijkstra_character_of_operation(dijkstra_stack, rpn_ptr, character_operation);	
			break;
		case less:
			push_str(dijkstra_stack, character_operation);
			break;
		case error:
			break;
	}
}
