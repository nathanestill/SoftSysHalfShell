#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <dirent.h>

void list(){
  //TODO make a function that prints all of the files within a directory
	DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
    	while ((dir = readdir(d)) != NULL)
        {
        	if(strcmp(dir->d_name,".") && strcmp(dir->d_name,"..")){
	            if(dir->d_type == 4){
	            	printf("\033[1;34m");
	            }
	            else{
	            	printf("\033[0m");
	            }
	            printf("%s ", dir->d_name);
	            //printf("%d", dir->d_type);
	        }
        }
        printf("\n");
        closedir(d);
    }
}

int removeFile(char* args[]){

}

int main(){
	list();
}