#include "palindrome.h"


/**
 * is_palindrome - checks whether or not a given unsigned 
 * integer is a palindrome.
 *
 * @n: The number to be checked.
 *
 * Return: 1 if n is a palindrome, 0 if it isn't
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;
	unsigned long temp = n;

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	if (rev == temp)
		return (1);

	return (0);
}