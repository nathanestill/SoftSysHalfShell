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

int manageEnviron(char * argv[], int args){
  switch(argv[0]){
    case "cd":
      changeDirectory(argv,args);
      break;
    case "mkdir":
      makeDirectory(argv,args);
    case "rm":
      removeFile(argv,args);
    case "ls":
      list(args,argv);
  }
}
