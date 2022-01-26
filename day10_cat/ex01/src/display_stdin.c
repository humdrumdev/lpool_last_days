#include "cat.h"

void	display_stdin(void)
{
	char	buf[BUF_SIZE];
	int	size;
	int	len;

	size = 0;
	while (size < BUF_SIZE)
	{
		len = read(0, buf + size, BUF_SIZE - size);
		if (!len) return;
		size += len;
		write(1, buf + size - len, len);
	}
}
