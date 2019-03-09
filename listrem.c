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

void printDir(struct dirent* dir, int m){
	if(m){
		printf("%s, ", dir->d_name);
	} else {
		printf("%s ", dir->d_name);
	}
}

void list(int argc, char* argv[]){
  //TODO make a function that prints a of the files within a directory
	int a = 0;
	int m = 0;
	int Q = 0;
	char ch;
	while((ch = getopt(argc, argv, "amQ")) != EOF){
		switch(ch) {
			case 'a':
				a = 1;
				continue;
			case 'm':
				m = 1;
				continue;
			case 'Q':
				Q = 1;
				continue;
			default:
				printf("dummy");
		}
		argc -= optind;
		argv += optind;	
	}
	DIR *d;
    struct dirent *dir;
    d = opendir(".");

    if (d)
    {
    	while ((dir = readdir(d)) != NULL)
        {
        	printf("\033[0m");
        	if(dir->d_name[0] != '.' || a){
	            if(dir->d_type == 8){
	            	if(Q){printf("\"");}
	            	printf("%s", dir->d_name);
	            	if(Q){printf("\"");}
	            	if(m){printf(",");}
	            	printf(" ");
	            	
	            }
	            //printf("%d", dir->d_type);
	        }
        }
        rewinddir(d);
        while ((dir = readdir(d)) != NULL)
        {
        	printf("\033[1;34m");
        	if(dir->d_name[0] != '.' || a){
	            if(dir->d_type == 4){
	            	if(Q){printf("\"");}
	            	printf("%s", dir->d_name);
	            	if(Q){printf("\"");}
	            	if(m){printf(",");}
	            	printf(" ");
	            }
	        }
        }
        printf("\n");
        closedir(d);
    }
}

int removeFile(char* args[]){

}

int main(int argc, char* argv[]){
	list(argc, argv);
}