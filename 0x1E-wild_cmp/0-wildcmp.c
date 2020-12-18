#include "holberton.h"

/**
 * strcmp - compare two strings
 * @str1: string
 * @str2: string
 *
 * Return: 1 if they are "equal", 0 otherwise.
 */
int strcmp(char *str1, char *str2)
{

	if (*str2 == '*')
	{
		return (starbranch(str1, str2 + 1));
	}
	if (*str1 == '\0' || *str2 == '\0')
	{
		if (*str2 == '\0' && *str1 == '\0')
			return (1);
		return (0);
	}
	if (*str1 == *str2)
	{
		return (strcmp(str1 + 1, str2 + 1));
	}
	return (0);
}

/**
 * starbranch - branch horizontally if a '*' has been encountered
 * @s1: ptr to string
 * @star: string with '*'
 *
 * Return: 1 if the string matches, else 0
 */
int starbranch(char *s1, char *star)
{
	if (*s1 == '\0')
		return (strcmp(s1, star));
	return (strcmp(s1, star) || starbranch(s1 + 1, star));
}


/**
 * wildcmp - compares two strings
 * @s: ptr to string 1
 * @s2: ptr to string 2 (may contain wildcard denoted by '*')
 *
 * Return: 1 if identical, otherwise 0
 */
int wildcmp(char *s, char *s2)
{
	return (strcmp(s, s2));
}
