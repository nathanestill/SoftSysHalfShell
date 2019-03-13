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

void changeDirectory(char *args[]){
  //TODO: Create a function that switches from current directory to specified directory
  if(args[1] == "~"){
    chdir(getenv("home"));
  }
  else {
    if(chdir(args[1])==-1){
      printf("This doesn't even exist my dude");
    }
  }
}

int makeDirectory(char* args[]){
  //TODO: Create a function that creates a new file
  struct stat bish= {0};
  if(stat(args[1],&bish)==-1){
    mkdir(args[1],0700);
  }
}

int main(int argc, char *argv[]){
  makeDirectory(argv);
}
