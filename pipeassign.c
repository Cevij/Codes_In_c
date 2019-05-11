#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int arg,char *array[100])
{
    int pipes[4][2];
    pid_t pid;

    printf("number of files: %d\n",(arg-1));

    if((arg-1) < 2 )
    {
        printf("Error you must enter at least 2 files..\n");
        exit(1);
    }

    if ((arg-1) > 4)
    {
        printf("Error you must enter up to 4 files...\n");
        exit(1);
    }


    for(int i = 1; i < arg;i++){

        pipe(pipes[i]);

        if ((pid = fork()) == 0)
        {
            /* child process */
            printf("child is made\n");
            close(pipes[i][0]);
            dup2(pipes[i][1], 1);
            execv("/bin/ls", array);
            printf("exec has failed\n");
        }
        else
        {
            //Parent process

            close(pipes[i][1]);

            char buffer[1];
            int read_status = 1;
            int write_status = 1;

            while (read_status > 0)
            {
                read_status = read(pipes[i][0], &buffer, 1);
                write_status = write(1, &buffer, 1);

                if (write_status < 0)
                {
                    fprintf(stderr, "write failed.\n\n");
                    return 1;
                }
            }

            if (read_status < 0)
            {
                fprintf(stderr, "read failed.\n\n");
                return 1;
            }

            //For the sake of this example, the wait status of the child is not checked.
            int wait_status;
            waitpid(pid, &wait_status, 0);
            printf("\nThe child is done and the program is exiting.\n");
        }

    }




    return 0;
}