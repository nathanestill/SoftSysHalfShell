#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **inputToCommand(char *input){
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
		token = strtok(NULL," ");
	}
	return command;
}

int getCommands(char **commands){
	/*
	TODO: For the starting thing, this should 
	just check if commands has exit, and return -1 if so
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
		fgets(input, 50, stdin);
		strtok(input, "\n");
		command = inputToCommand(input);
		child = fork();
		if(child == 0){
			execvp(command[0], command);
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