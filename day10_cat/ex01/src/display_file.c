#include "cat.h"

extern	int	errno;

int	display_file(char *path)
{
	char	buf[BUF_SIZE];
	int	fd;
	int	status;

	fd = open(path, O_RDONLY);
	if (fd < 0) return errno;
	status = read(fd, buf, BUF_SIZE);
	if (status == -1) return errno;
	if (!status) return (close(fd));
	write(1, buf, status);
	return (close(fd));
}
