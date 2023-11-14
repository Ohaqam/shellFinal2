#include "main.h"

void execute_command(char **tok) {
    while (tok != NULL) {
if(execve(tok[0], tok, NULL) == -1)
			{
				/*perror("hsh");*/
                exit(127);
			}
           

    }
    /* If the loop completes, the command was not found in PATH*/
    /*fprintf(stderr, "Command not found: %s\n", tok[0]);*/
    exit(126);  /* 127 indicates command not found*/
}
