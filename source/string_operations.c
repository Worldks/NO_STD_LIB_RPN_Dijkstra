#include "../include/string_operations.h"

int string_length(const char *str)
{
	int i = 0;
	for( ; *(str + i) != '\0'; i++)
		{}
	return i;
}

int is_div_mul_operation(const char *operation)
{
	if(*(operation + 1) != '\0')
		return 0;
	if(*operation == op_div || *operation == op_mul)
		return 1;
	else
		return 0;
}

int is_sub_add_operation(const char *operation)
{
	if(*(operation + 1) != '\0')
		return 0;
	if(*operation == op_minus || *operation == op_plus)
		return 1;
	else
		return 0;
}

int is_openning_parenthesis(const char *str)
{
	if(*(str + 1) != '\0')
		return 0;
	else if(*str == openning_parenthesis)
		return 1;
	else 
		return 0;
}

int is_closing_parenthesis(const char *str) /* MOVE TO string_operations.c? */
{
	if(*(str + 1) != '\0')
		return 0;
	else if(*str == closing_parenthesis)
		return 1;
	else 
		return 0;
}

enum compared_result compare_operations(const char *operation_1, const char *operation_2)
{
	int len_1 = 0, len_2 = 0;
	int op_1, op_2;
	len_1 = string_length(operation_1);
	len_2 = string_length(operation_2);
	if(len_1 != len_2 || len_1 != 1 || len_2 != 1)
		return error;
	op_1 = is_div_mul_operation(operation_1);
	op_2 = is_div_mul_operation(operation_2);
	if(op_1 == op_2)
		return equal;
	else if(op_1 > op_2)
		return greather;
	else
		return less;
}

enum operations is_str_operation(const char *str)
{
	if(*(str + 1) != '\0')
		return op_not;
	switch(*str) {
		case op_plus:
			return op_plus;
		case op_minus:
			return op_minus;
		case op_div:
			return op_div;
		case op_mul:
			return op_mul;
		case op_not:
			return op_not;
	}
	return op_not;
}

int string_number_from_char_array(const char *arr, char *string_number)
{
	char ch;
	int i = 0;
	ch = arr[i];
	while(ch >= 0x30 && ch <= 0x39) {
		*(string_number + i) = ch;
		i++;
		ch = arr[i];
	}
	*(string_number + i) = '\0';
	return i;
}

int string_operation_from_char_array(const char *arr, char *string_operation)
{
	char ch;
	switch(*arr) {
		case op_plus:
			ch = op_plus;
			break;
		case op_minus:
			ch = op_minus;
			break;
		case op_div:
			ch = op_div;
			break;
		case op_mul:
			ch = op_mul;
			break;
		case op_not:
			return 0; /* not operation */
	}
	*string_operation = ch;
	*(string_operation + 1) = '\0';
	return 1;
}
