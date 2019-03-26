#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/stat.h>


void changeDirectory(char *args[], int len){
  /*
   Function takes in an array of arguements from the command line and the number of arguements. The function then changes the current working directory
   to what the user specified. If the file does not exit the function prints an error.

   Input: array of chars and size of array

   Returns: nothing
  */
  if(args[1] == "~"){
    chdir(getenv("./"));
  }
  else {
    if(chdir(args[1])==-1){
      printf("This doesn't even exist my dude\n");
    }
  }
}

int makeDirectory(char* args[], int len){
  /*
  Function takes in an array of arguements from the command line and the number of arguements.
  The function then creates a file with the specified name at the specified file location.

   Input: array of chars and size of array

   Returns: nothing
  */

  struct stat file= {0};
  if(stat(args[1],&file)==-1){
    mkdir(args[1],0700);
  }
}
