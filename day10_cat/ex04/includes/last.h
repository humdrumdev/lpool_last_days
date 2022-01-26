#ifndef LAST_H

#define LAST_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <errno.h>
#include <time.h>
#include <utmp.h>
#include <sys/types.h>

#include <stdio.h>

#define WTMP "/var/log/wtmp"

int ft_strncmp(const char *lhs, const char *rhs, size_t count);
size_t ft_strlen(const char *s);

#endif
