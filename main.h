#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

ssize_t get_input(char **line, size_t *n);
void execute_command(char **tok);
void handle_error(char *message);

#endif /* MAIN_H */