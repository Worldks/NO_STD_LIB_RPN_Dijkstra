#include "../include/calls.h"
#include "../include/string_operations.h"
#include "../include/number_convert.h"
#include "../include/stack_static_array.h"
#include "../include/rpn.h"
#include "../include/dijkstra_for_rpn.h"

char error_eof[] = "\nEOF was appear.\n";
char str_error[] = "\nerror code from read() is: ";
char result_of_expression[] = "\nResult of expression is: ";
char incorrect_expression[] = "\nIncorrect expression.\n";
char unclosed_bracket[] = "\nThere is an unclosed bracket.\n";

enum { max_expression_size = 1024 };
int compute_expression(const char *expr, struct stack *rpn, struct stack *dijkstra_stack, const int expression_length);

int main(int argc, char **argv)
{
	char input_expression[max_expression_size] = { 0 };
	char str_result[max_number_length] = { 0 };
	char error_code[max_number_length] = { 0 };
	struct stack rpn, dijkstra_stack;
	int result, number_of_input_characters;
	stack_init(&rpn);
	stack_init(&dijkstra_stack);
	
	number_of_input_characters = sys_read(0, input_expression, max_expression_size);
	/* need to check sys_errno */
	if(number_of_input_characters == 0) {
		sys_write(1, error_eof, sizeof(error_eof));
		sys_exit(1);
	} else if(number_of_input_characters < 0) {
		number_to_str(sys_errno, error_code);
		sys_write(1, str_error, sizeof(str_error));
		sys_write(1, error_code, sizeof(error_code));
		sys_write(1, "\n", 1);
	}

	push_str(&dijkstra_stack, "(");
	result = compute_expression(input_expression, &rpn, &dijkstra_stack, number_of_input_characters);
	number_to_str(result, str_result);
	sys_write(1, result_of_expression, sizeof(result_of_expression));
	sys_write(1, str_result, sizeof(str_result));
	sys_write(1, "\n", 1);
	return 0;
}

int compute_expression(const char *expr, struct stack *rpn, struct stack *dijkstra_stack, const int expression_length)
{
	int offset = 0, len_part_expression = 0, stack_empty = 0, res;
	char number_buffer[max_number_length] = { 0 };
	char operation_buffer[max_operation_length] = { 0 };
	char ch;

	if(expression_length >= max_expression_size) {
		sys_exit(1);
	}

	ch = *expr;
	while(offset != expression_length) {
		#ifdef DEBUG
		print_stack(rpn);
		#endif
		if(ch == op_plus || ch == op_minus || ch == op_div || ch == op_mul) {
			len_part_expression = string_operation_from_char_array(expr + offset, operation_buffer);
			dijkstra_character_of_operation(dijkstra_stack, rpn, operation_buffer);
			offset = offset + len_part_expression;
			ch = *(expr + offset);
			#ifdef DEBUG
			print_stack(dijkstra_stack);
			#endif
		} else if (ch >= 0x30 && ch <= 0x39) {
			len_part_expression = string_number_from_char_array(expr + offset, number_buffer);
			push_str(rpn, number_buffer);
			offset = offset + len_part_expression;
			ch = *(expr + offset);
		} else if(ch == closing_parenthesis) {
			pop_before_openning_parenthesis(dijkstra_stack, rpn);
			offset = offset + 1;
			ch = *(expr + offset);
			#ifdef DEBUG
			print_stack(dijkstra_stack);
			#endif
		} else if(ch == openning_parenthesis) {
			push_str(dijkstra_stack, "(");
			offset = offset + 1;
			ch = *(expr + offset);
			#ifdef DEBUG
			print_stack(dijkstra_stack);
			#endif
		} else if(ch == '\n')
			break;
	}

	pop_before_openning_parenthesis(dijkstra_stack, rpn);
	stack_empty = is_stack_empty(dijkstra_stack);
	if(stack_empty == 0) {
		sys_write(1, unclosed_bracket, sizeof(unclosed_bracket));
		sys_exit(2);
	}
	compute_rpn(rpn);
	res = str_to_number(&((rpn->array)[rpn->free_space]));
	return res;
}
