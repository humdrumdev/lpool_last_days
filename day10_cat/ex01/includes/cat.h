#ifndef CAT_H
# define CAT_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

# define BUF_SIZE 21000
# define NO_SUCH_FILE ": No such file or directory\n"
# define NO_SUCH_FILE_LEN 28
# define PERM ": Permission denied\n"
# define PERM_LEN 20
# define IS_DIR ": Is a directory\n"
# define IS_DIR_LEN 18
# define OVERFLOW ": File is too big\n"
# define OVERFLOW_LEN 18

int	display_file(char *path);
void	display_stdin(void);
void	handle_errors(int code, char *fname);

#endif
