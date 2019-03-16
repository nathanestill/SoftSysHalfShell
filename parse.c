#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include "switch.h"

int manageEnviron(char *argv[], int args){
  if(!strcmp(argv[0],"cd")){
  	changeDirectory(argv,args);
    char *currentDirectory = (char*) calloc(1024, sizeof(char));
    char hostn[1204] = "";
  	gethostname(hostn, sizeof(hostn));
  	printf("%s@%s %s > ", getenv("LOGNAME"), hostn, getcwd(currentDirectory, 1024));
  } else if(!strcmp(argv[0],"mkdir")){
    makeDirectory(argv,args);
  } else if(!strcmp(argv[0],"rm")){
  	removeFile(args,argv);
  } else if(!strcmp(argv[0],"ls")){
    list(args,argv);
  } else {
  	printf("No function called %s.\n", argv[0]);
  }
}
char **inputToCommand(char *input, int *len){
	/*
	splits the input into commands by spaces
	input: string that contains commands
	returns an array of strings that are the commands
	*/
	char **command = malloc(8 * sizeof(char *));
	char *token;
	int index = 0;
	token = strtok(input," ");
	while(token != NULL){
		command[index] = token;
		index++;
    (*len)++;
		token = strtok(NULL," ");
	}
	return command;
}

int getCommands(char **commands){
	/*
	TODO: make this be a switch that calls the correct one
	*/
	if(strcmp(commands[0], "exit")){
		return -1;
	}
	else {
		return 0;
	}
}

int main(){
	char** command;
	char input[50];
	pid_t child;
	int randomVariable;
	int commandVal = -1;
	while(1){
    int len=0;
		fgets(input, 50, stdin);
		strtok(input, "\n");
		command = inputToCommand(input,&len);
		child = fork();
		if(child == 0){
			manageEnviron(command, len);
			if(commandVal == -1){
				break;
			}
		}
		else{
			if(strcmp(command[0],"exit") == 0){
				break;
			}
			waitpid(child, &randomVariable, WUNTRACED);
		}
		free(command);
	}
}
