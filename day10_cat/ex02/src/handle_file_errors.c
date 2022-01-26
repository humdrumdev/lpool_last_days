#include "../includes/tail.h"

void logs(int fd, const char *strp, const char *str, char *fname)
{
    write(fd, strp, ft_strlen(strp));
    write(fd, fname, ft_strlen(fname));
    write(fd, str, ft_strlen(str));
}

void logerr(const char *errp, const char *err, char *fname)
{
    logs(STDERR_FILENO, errp, err, fname);
}

void logstrs(const char *strp, const char *str, char *fname)
{
    logs(STDOUT_FILENO, strp, str, fname);
}

void handle_file_errors(int code, char *fname)
{
    if (!code)
        return;
    if (code == -2)
        write(STDERR_FILENO, OVERFLOW, ft_strlen(OVERFLOW));
    else if (code == EPERM || code == EACCES)
        logerr(PERM_P, PERM, fname);
    else if (code == EISDIR)
        logerr(IS_DIR_P, IS_DIR, fname);
    else if (code == ENOENT)
        logerr(NO_SUCH_FILE_P, NO_SUCH_FILE, fname);
    else
        write(STDERR_FILENO, "unhundeled\n", 11);
}