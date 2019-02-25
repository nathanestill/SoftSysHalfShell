#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **inputToCommand(char *input){
	/*
	TODO: Make this function take in the input string,
	and separates the input into an array of strings, separated
	by each space in the input
	*/
}

int getCommands(char **commands){
	/*
	TODO: For the starting thing, this should 
	just check if commands has exit, and return -1 if so
	*/ 
}

int main(){
	char** command;
	char* input;
	pid_t child;
	int randomVariable;
	while(1){
		fgets(input, 50, stdin);
		command = inputToCommand(input);
		child = fork();
		if(child == 0){
			getCommands(command);
			if(getCommands == -1){
				break;
			}
		}
		else{
			waitpid(child, &randomVariable, WUNTRACED);
		}
		free(input);
		free(command);
	}
}