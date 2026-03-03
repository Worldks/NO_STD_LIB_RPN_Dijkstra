#include "../include/rpn.h"

void compute_rpn(struct stack *rpn_ptr)/* maybe int return for this function? */
{
	char res_str[max_number_length] = { 0 };
	enum operations top_stack_value;
	int is_empty, operand_1, operand_2, res;
	char *array = rpn_ptr->array;

	is_empty = is_stack_empty(rpn_ptr);
	if(is_empty)
		return;
	if(rpn_ptr->elements_count < 3) /* strings_count? */
		return;
	top_stack_value = is_str_operation(&(array[rpn_ptr->free_space]));
	if(top_stack_value == op_not)
		return;

	#ifdef DEBUG
	print_stack(rpn_ptr);
	#endif

	delete_str_from_stack_top(rpn_ptr);
	operand_1 = str_to_number(&(array[rpn_ptr->free_space]));
	delete_str_from_stack_top(rpn_ptr);
	operand_2 = str_to_number(&(array[rpn_ptr->free_space]));
	delete_str_from_stack_top(rpn_ptr);

	switch(top_stack_value) {
		case op_plus:
				res = operand_1 + operand_2;
				break;
		case op_minus:
				res = operand_2 - operand_1;
				break;
		case op_div:
				res = operand_2 / operand_1;
				break;
		case op_mul:
				res = operand_1 * operand_2;
				break;
		case op_not:
				return;
				break;
	}
	
	number_to_str(res, res_str);
	push_str(rpn_ptr, res_str);
}
