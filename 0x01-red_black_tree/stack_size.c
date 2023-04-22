#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char huge[1000000000];

	memset(huge, 'H', 999999999);
	
	printf("%s\n", huge);

	return 0;
}
