#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"


/**
 * get_tenth - get tenth
 *
 * @n: get max tenth of this number
 * Return: tenth
 */
unsigned long int get_tenth(unsigned long n)
{
	unsigned long i;

	for (i = 1; n / 10; i *= 10)
		n /= 10;
	return (i);
}

/**
 * check_pali - check if int is palidrome or not
 *
 * @n: number checking
 * @i: starting point
 * @tenth: end point
 * Return: 1 if true, 0 if false
 */
int check_pali(unsigned long n, unsigned long i, unsigned long tenth)
{
	if ((n / i % 10 == n / tenth % 10) && (i < tenth))
		return (check_pali(n, i * 10, tenth / 10));
	else if (n / i % 10 != n / tenth % 10)
		return (0);
	else
		return (1);
}

/**
 * is_palindrome - checks if unsigned int is palindrome
 * @n: unsigned int of given number to be checked
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	return (check_pali(n, 1, get_tenth(n)));
}
