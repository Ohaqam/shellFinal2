#include "main.h"

ssize_t get_input(char **line, size_t *n) {
    if (isatty(STDIN_FILENO)) {
            write(1, "$ ", 2);
        }
    
    return getline(line, n, stdin);
}
