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
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
Gets the path of the file and returns whether the file is regular
path: string of the path

returns 0 if success, -1 otherwise
*/
int is_regular_file(const char *path){
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

/*
returns a list of the files and folders in a directory
paramaters: a - includes files and folders with '.'
			m - puts commas between each directory
			Q - puts quotation marks around each directory
*/
void list(int argc, char* argv[]){
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
				printf("Not a valid argument.");
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

/*
removes the file specified
parameters: r - removes directories as well as files.
*/
int removeFile(int argc, char* argv[]){
	int r = 0;
	char ch;
	while((ch = getopt(argc, argv, "r")) != EOF){
		switch(ch) {
			case 'r':
				r = 1;
				break;
			default:
				printf("Those aren't valid arguments. \n");
		}
		argc -= optind;
		argv += optind;
	}
	printf("%s\n", argv[argc-1]);
	DIR *d;
	struct dirent *dir;
	char* array[2];
	int status;
	char directory[strlen(argv[argc-1])+3];
	strcpy(directory,"./");
	strcat(directory,argv[argc-1]);
	if(is_regular_file(argv[argc-1])){
		status = remove(argv[argc-1]);
		printf("%d\n", status);
		if(status){
			printf("rm: cannot remove '%s': No such file\n",argv[argc-1]);
		}
	}
	else{
		if(r){
		    d = opendir(directory);
		    while ((dir = readdir(d)) != NULL){
		    	if(dir->d_name[0] != '.'){
					char nextDir[1+strlen(argv[argc-1])+strlen(dir->d_name)];
					strcpy(nextDir,argv[argc-1]);
					strcat(nextDir,"/");
					strcat(nextDir,dir->d_name);
					array[0] = "./a.out";
					array[1] = "-r";
		    		array[2] = nextDir;
		    		removeFile(3,array);
		    	}
		    }
		    status = remove(argv[argc-1]);

		}
		else{
			status = remove(argv[argc-1]);
			if(status){
			printf("rm: cannot remove '%s': Is a directory\n",argv[argc-1]);
		}
		}
	}
	return 0;
}
