#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct printHandler - struct function.
 * @plus: '+' character.
 * @space: ' ' character.
 * @hash: '#' character.
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flag;

/**
 * struct printHandler - struct.
 * @c: format specifier variable.
 * @f: pointer to the printing function.
 */
typedef struct printHandler
{
	char c;
	int (*f)(vlist ap, flag *f);
} ph;

int print_int(vlist l, flag *f);
void print_number(int n);
int print_unsigned(vlist l, flag *f);
int count_digit(int i);

int print_hex(vlist l, flag *f);
int print_hex_big(vlist l, flag *f);
int print_binary(vlist l, flag *f);
int print_octal(vlist l, flag *f);

char *convert(unsigned long int num, int base, int lowercase);


int _printf(const char *format, ...);

int (*get_print(char s))(vlist, flag *);

int get_flag(char s, flag *f);

int print_string(vlist l, flag *f);
int print_char(vlist l, flag *f);

int _putchar(char c);
int _puts(char *str);

int print_rot13(vlist l, flag *f);
int print_rev(vlist l, flag *f);
int print_bigS(vlist l, flag *f);

int print_address(vlist l, flag *f);

int print_percent(vlist l, flag *f);

#endif
