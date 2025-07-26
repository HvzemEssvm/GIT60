#include <stdio.h>

/**
 * @brief Just wanted to test Doxygen
 * 
 * @param a int
 * @return int 
 */
int testing_dox(int a)
{
	printf("%d",a);
	return a++;
}

int main()
{
	testing_dox(1);
	printf("\nWelcome To My REPO\n");
}

