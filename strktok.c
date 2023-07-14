#include <stdio.h>
#include <string.h>

int main(void)
{
	char *string2;

	char string[1024] = "father francis fried five fresh fish";
	const char token[4] = " ";

	string2 = strtok(string, token);

	while (string2)
	{
		printf("%s\n", string2);
		string2 = strtok(0, token);
	}
	
	return (0);
}
