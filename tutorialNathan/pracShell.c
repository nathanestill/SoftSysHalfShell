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
	char **command = malloc(8 * sizeof(char *));
	char *token;
	int index = 0;
	token = strtok(input," ");
	printf("%s\n", token);
	while(token != NULL){
		printf("Enters\n");
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
		command = inputToCommand(input);
		child = fork();
		if(child == 0){
			//getCommands(command);
			if(commandVal == -1){
				break;
			}
		}
		else{
			printf("%s", command[0]);
			printf("%d\n", strcmp(command[0],"exit"));
			if(strcmp(command[0],"exit") == 0){
				break;
			}
			waitpid(child, &randomVariable, WUNTRACED);
		}
		free(command);
	}
}