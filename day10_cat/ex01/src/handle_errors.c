#include "cat.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i)) i++;
	return (i);
}

void	handle_errors(int code, char *fname)
{

	if (code < 0)  write(2, "error closing file\n", 19);
	else if (code)
	{
		write(2, fname, ft_strlen(fname));
		if (code == EACCES) write(2, PERM, PERM_LEN);
		else if (code == ENOENT) write(2, NO_SUCH_FILE, NO_SUCH_FILE_LEN);
		else if (code == EISDIR) write(2, IS_DIR, IS_DIR_LEN);
		else if (code == EOVERFLOW) write(2, OVERFLOW, OVERFLOW_LEN);
		else write(2, ": Something wrong Happened\n", 27);
	}
	else return;
}
