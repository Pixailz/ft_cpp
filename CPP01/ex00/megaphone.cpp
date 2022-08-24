#include <iostream>

void	PrintToUpper(char *str)
{
	for (int i = 0; str[i]; i++)
		putchar(toupper(str[i]));
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	PrintToUpper(argv[1]);
	return (0);
}
