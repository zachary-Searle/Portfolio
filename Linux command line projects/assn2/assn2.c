#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[]){
	pid_t pid = fork();
	int status;
	argc--;
	argv++;
	if(pid == 0){
		printf("Child started. ");
		if(argc == 0)
			printf("There was no parameters passed\n");
		if(argc == 1){
			printf("There was one parameter passed. Calling execlp().\n");
			execlp(argv[0], argv[0], NULL);
		}
		if(argc > 1){
			printf("There was more than one parameter passed. Calling execvp().\n");
			execvp(*argv, argv);
		}
		exit(0);
	}else if(pid < 0){
		printf("fork() failed, exiting program\n");
		exit(1);
	}else if(pid > 0){
		printf("Parent started, now waiting for process id# %d\n", pid);
		waitpid(pid, &status, 0);
		printf("Parent resumed. Child exit code %d. Now terminating parent\n", status);
		return 0;
	}
}
