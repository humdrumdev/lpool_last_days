#include "cat.h"

int	main(int ac, char **av)
{
	int	i;
	int	errnum;

	if (ac == 1) display_stdin();
	i = 1;
	while (i < ac) {
		errnum = display_file(av[i]);
		handle_errors(errnum, av[i]);
		i++;
	}
	return (0);
}
