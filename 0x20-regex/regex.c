#include "regex.h"

/**
 * strcmp - compare two strings
 * @str1: string
 * @str2: string
 *
 * Return: 1 if they are "equal", 0 otherwise.
 */
int strcmp(char const *str1, char const *str2)
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
int starbranch(char const *s1, char const *star)
{
	if (*s1 == '\0')
		return (strcmp(s1, star));
	return (strcmp(s1, star) || starbranch(s1 + 1, star));
}


/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: ptr to string to check
 * @pattern: pattern to compare with
 *
 * Return: 1 if match, otherwise 0
 */
int regex_match(char const *str, char const *pattern)
{
	return (strcmp(str, pattern));
}
