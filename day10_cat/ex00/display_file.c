#include <unistd.h>
#include <fcntl.h>

int	display_file(char *path)
{
	int	fd;
	char	buf;
	int	status;

	fd = open(path, O_RDONLY);
	if (fd < 0) return (-1);
	while (1)
	{
		status = read(fd, &buf, 1);
		if (status < 0) return (-2 + close(fd));
		if (!status)	return (close(fd));
		write(1, &buf, 1);
	}
}
