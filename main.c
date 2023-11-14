#include "main.h"

int main() {
    char *line = NULL;
    char *line_cpy = NULL;
    char *token;
    char *delim = " \n\t";
    size_t n = 0;
    ssize_t l = 0;
    char **tok;
    int i = 0;
    pid_t my_pid;
    int status;
    char cwd[1024];

    while (1) {
        l = get_input(&line, &n);

        if (l == -1) {
            free(line);
            return 0;
        }

        line_cpy = malloc(sizeof(char) * l);
        if (line_cpy == NULL) {
            handle_error("tsh: memory allocation error");
            free(line_cpy);
            return 0;
        }
        strcpy(line_cpy, line);
        token = strtok(line, delim);

        while (token != NULL) {
            i++;
            token = strtok(NULL, delim);
        }
        i++;
        tok = malloc(sizeof(char *) * i);
        token = strtok(line_cpy, delim);

        for (i = 0; token != NULL; i++) {
            tok[i] = malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(tok[i], token);
            token = strtok(NULL, delim);
        }

        free(line_cpy);
        tok[i] = NULL;
        my_pid = fork();

        if (my_pid == 0) {
            execute_command(tok);
        } else if (my_pid < 0) {
            handle_error("Fork error");
        } else {
            waitpid(my_pid, &status, 0);
            /* Handle exit status*/
        }

        /* Free memory allocated for tok and its elements*/
        for (i = 0; tok[i] != NULL; i++) {
            free(tok[i]);
        }
        free(tok);

        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            /* printf("Current working directory: %s\n", cwd);*/
        } else {
            perror("getcwd");
        }
    }

    return 0;
}
