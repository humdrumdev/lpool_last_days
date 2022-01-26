#ifndef TAIL_H

#define TAIL_H

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_LINES 10
#define MAX_FLAGS 100
#define MAX_BUF_SIZE 30000

#define HEAD_P "==> "
#define HEAD_S " <==\n"

#define INVALID_NUM "ft_tail: invalid number of bytes: ‘"

#define INVALID_OP "ft_tail: invalid option -- '"
#define INVALID_OP_P "'\nTry 'tail --help' for more information.\n"

#define MISSIN_ARG "ft_tail: option requires an argument -- 'c'\nTry 'tail --help' for more information.\n"

#define NO_SUCH_FILE_P "ft_tail: cannot open '"
#define NO_SUCH_FILE "' for reading: No such file or directory\n"

#define PERM_P "ft_tail: cannot open '"
#define PERM "' for reading: Permission denied\n"

#define IS_DIR_P "ft_tail: error reading '"
#define IS_DIR "': Is a directory\n"

#define OVERFLOW "ft_tail: File is too big\n"

typedef struct s_err_arg
{
    int code;
    int index;
    int bytes;
} t_err_arg;

typedef struct s_result
{
    int idxtodrop[MAX_FLAGS];
    t_err_arg status;
} t_result;

int ft_strncmp(const char *lhs, const char *rhs, size_t count);
int valid_successor(char *successor, int *bytes);
int getmin(int a, int b);
int is_num(char c);
int ft_atoi(const char *str);
size_t ft_strlen(const char *s);
t_result valid_input(int ac, char **av, char *arg);
t_result validate_input(int ac, char **av, char *arg);
void handle_input_errors(int error_code, int argidx, char **av, char *arg);
int count_files(int *indices);
int tail_file(char *fname, int bytes, int ac);
void handle_file_errors(int code, char *fname);
void logs(int fd, const char *strp, const char *str, char *fname);
void logerr(const char *errp, const char *err, char *fname);
void logstrs(const char *strp, const char *str, char *fname);

#endif
