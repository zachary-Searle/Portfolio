#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
long totalMemory = 0;

void tree(char *path, int x);

int main(int argc, char *argv[]){
	DIR* directory;
	//hold the original path
	argv++;
	argc--;
	char path[100];
	//if no argument was passed, than just use current working directory
	if(argc == 0)
	strcat(path, ".");
	//else use the argument given
	else
	strcat(path, argv[0]);
	//check to see if current address is proper
	if(directory = opendir(path))
		closedir(directory);
	//if not, then throw out a message and exit
	else{
		printf("Please provide a proper address to a directory\n");
		return 0;
	}
	printf("dir %s\n", path);
	//pass the original path to recusive function
	tree(path, 0);
	//print total memory
	printf("Total file space used: %ld\n", totalMemory);
	return 0;
}

void tree(char *path, int indent){
	//intialize directory and file as well as open original directory
	DIR* directory;
	struct dirent* file = NULL;
	directory = opendir(path);
	//as long as I'm not at the end of the current directory, keep looping
	while((file = readdir(directory)) != NULL){
		//this is so if I run into a sub-directory
		char *nextPath;
		asprintf(&nextPath, "%s/%s", path, file->d_name);
		struct stat stats;
		lstat(nextPath, &stats);
		//if the current file is a symbolic link or a git repository
		if(strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0 || strcmp(file->d_name, ".git") == 0 || S_ISLNK(stats.st_mode)){

		}else if(S_ISDIR(stats.st_mode)){ //this is to check if the current file is a sub-directory
			for(int i = 0; i < indent + 1; i++)
				//padding
				printf("    ");
			printf("directory %s\n", nextPath);
			//call my recursive function with the path to the sub-directory
			tree(nextPath, indent + 1);
		}else{ //if it is not a symbolic link or a sub-directory, than it is a file
			//add the size of the file with the rest of the files
			totalMemory += (long)stats.st_size;
			for(int i = 0; i < indent + 1; i++)
				//more padding
				printf("     ");
			printf("%ld:%s\n", (long)stats.st_size, file->d_name);
		}
	//make sure you don't leak memory
	free(nextPath);
	}
	//close that directory
	closedir(directory);
	return;
}
