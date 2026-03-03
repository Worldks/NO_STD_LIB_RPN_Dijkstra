#ifndef NUMBER_CONVERTION_SENTRY
#define NUMBER_CONVERTION_SENTRY

#include "string_operations.h"
/* Maybe should add this modul to string_operations.c (cause this module too litle)? */
int str_to_number(const char *str);
void number_to_str(int number, char *str);

#endif
