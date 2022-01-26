#ifndef HEXDUMP_H

#define HEXDUMP_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_FLAGS 100
#define MAX_FILES 100
#define MAX_BUF_SIZE 30000

#define INVALID_OP "ft_hexdump: invalid option -- '"
#define INVALID_OP_P "'\nusage: ft_hexdump [-C] [files]\n"

#define NO_SUCH_FILE_P "ft_hexdump: "
#define NO_SUCH_FILE ": No such file or directory\n"

#define PERM_P "ft_hexdump: "
#define PERM ": Permission denied\n"

#define IS_DIR_P "ft_hexdump: "
#define IS_DIR ": Is a directory\n"

#define OVERFLOW "ft_hexdump: File is too big\n"

typedef struct s_result
{
    int code;
    int files[MAX_FILES];
    int numfiles;
    int flags[MAX_FLAGS];
    int numflags;
} t_result;

int ft_strncmp(const char *lhs, const char *rhs, size_t count);
size_t ft_strlen(const char *s);
int readfiles(char *buf, int *charcount, char **av, int *indices);
void handle_file_errors(int code, char *fname);
void logs(int fd, const char *strp, const char *str, char *fname);
void logerr(const char *errp, const char *err, char *fname);
void logstrs(const char *strp, const char *str, char *fname);
int ft_isprint(char c);
char *chartohex(int c, const char *base);
char *strhexreprC(char *str, int size);
char *strhexrepr(char *str, int size);
char *hexcount(size_t count, const char *base);
char *strrepr(char *str, int size);
char *strrepr(char *str, int size);
int read_file(char *buf, char *fname, int *charcount);
int readfiles(char *buf, int *charcount, char **av, int *indices);
int print_stdin(char *buf, int op);
int print_content(char *buf, int charcount, int op);
int writeline(char *buf, const char *base, int size, int c);
int writelineC(char *buf, const char *base, int size, int c);

#endif
