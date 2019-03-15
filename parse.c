#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>

void init(){
  //TODO:
}

int manageEnviron(char * args[]){
  switch(args[0]){
    case "cd":
      changeDirectory(args);
      break;
    case "mkdir":
      makeDirectory(args);
    case "rm":

    case "ls":
  }
}
