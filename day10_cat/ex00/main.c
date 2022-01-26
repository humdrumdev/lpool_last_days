#include <unistd.h>

int	display_file(char *path);

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 1)
		{
			write(1, "File name missing.\n", 19);
			return (0);
		}
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	if (!display_file(av[1])) return (0);
	return (write(2, "something wrong happened\n", 25));
}
