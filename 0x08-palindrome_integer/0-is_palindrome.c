#include <stdio.h>
#include "palindrome.h"
/**
 * is_palindrome - checks a given unsigned integer is a palindrome
 * @n: number to check
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
int once, rev_number = 0;
int  backup = n;

while (n != 0)
{
once = n % 10;
n /= 10;
rev_number = rev_number * 10 + once;
}
if (backup == rev_number)
return (1);
return (0);
}
