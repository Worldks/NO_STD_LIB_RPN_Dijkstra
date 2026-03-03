#ifndef STRING_OPERATIONS_SENTRY
#define STRING_OPERATIONS_SENTRY

enum { max_number_length = 12 };
enum { max_operation_length = 2 };
enum compared_result { less, equal, greather, error };
enum parenthesis { openning_parenthesis = 40, closing_parenthesis = 41 };
enum operations { op_plus = 43,  op_minus = 45, 
				  op_div = 47,   op_mul = 42,    op_not = -1 };

int string_length(const char *str);
int is_div_mul_operation(const char *operation);
int is_sub_add_operation(const char *operation);
int is_openning_parenthesis(const char *str);
int is_closing_parenthesis(const char *str);
int string_number_from_char_array(const char *arr, char *string_number);
int string_operation_from_char_array(const char *arr, char *string_operation);
enum operations is_str_operation(const char *str);
enum compared_result compare_operations(const char *operation_1, const char *operation_2);
#endif
