#include "../include/stack_static_array.h"

void stack_init(struct stack *stack)
{
	int i = 0;
	stack->free_space = stack_size;
	stack->elements_count = 0;
	for(; i < stack_size; i++) {
		(stack->array)[i] = 0;
	}
}

int is_stack_empty(struct stack *stack)
{
	return stack->free_space == 1024 ? 1 : 0;
}

int push_char(struct stack *stack, char value)
{ /* I think it's bad function, we need to store string in array(buffer) */
	if(stack->free_space == -1)
		return 0;
	stack->free_space--;
	(stack->array)[stack->free_space] = value;
	if(value == '\0')
		stack->elements_count++;	/* bad, but fast */
	return 1;
}

char pop_char(struct stack *stack) /* if use ONLY ascii table*/
{ /* I think it's bad function, we need to store string in array(buffer) */
	char ch;
	if(stack->free_space == stack_size)
		return 0;
	ch = (stack->array)[stack->free_space];
	stack->free_space++;
	if(ch == '\0')
		stack->elements_count--;	/* bad, but fast */
	return ch;
}

void delete_str_from_stack_top(struct stack *stack)
{
	if(stack->free_space >= stack_size - 1)
		return;
	while((stack->array)[stack->free_space] != '\0') {
		stack->free_space++;
	}
	stack->free_space++;
	stack->elements_count--;
}

int push_str(struct stack *stack, const char *str)
{
	int len = 0, i = 0;
	len = string_length(str);
	if(stack->free_space - len - 1 <= -1) /* '\0' */
		return 0;
	stack->free_space = stack->free_space - len - 1;
	for(; i < len; i++) {
		(stack->array)[stack->free_space + i] = *(str + i);
	}
	(stack->array)[stack->free_space + i] = '\0';
	stack->elements_count++;
	return 1;
}

int pop_str(struct stack *stack, char *str) /* NEED to add check for len of popping string */
{
	int len = 0, i;
	len = string_length(&((stack->array)[stack->free_space]));
	if(stack->free_space >= stack_size - 1)
		return 0;
	for(i = 0; i <= len; i++) {
		*(str + i) = (stack->array)[stack->free_space + i];
	}
	stack->free_space = stack->free_space + len + 1;
	stack->elements_count--;
	return 1;
}

void print_stack(struct stack *stack)
{
	int length, i;
	char buffer[stack_size] = { 0 };
	length = stack_size - stack->free_space;
	for(i = 0; i < length; i++) {
		if(i == length - 1) {
			buffer[i] = 10; /* \n code */
			break;
		}
		buffer[i] = (stack->array)[stack->free_space + i];
	}
	sys_write(1, buffer, length);
}
