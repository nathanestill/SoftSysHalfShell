#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

pid_t shell_pgid;
struct termios shell_tmodes;
int shell_terminal;
int shell_is_interactive;

void init_shell(){
  shell_terminal = STDIN_FILENO;
  shell_is_interactive = isatty(shell_terminal);

  if(shell_is_interactive){
    while(tcgetpgrp(shell_terminal) != (shell_pgid=getpgrp())){
      kill(- shell_pgid, SIGTTIN);
    }

    signal (SIGINT, SIG_IGN);
    signal (SIGQUIT, SIG_IGN);
    signal (SIGTSTP, SIG_IGN);
    signal (SIGTTIN, SIG_IGN);
    signal (SIGTTOU, SIG_IGN);
    signal (SIGCHLD, SIG_IGN);

    shell_pgid=getpid();
    if(setpgid(shell_pgid,shell_pgid)<0){
      perror("Failed");
      exit(1);
    }

    tcsetpgrp(shell_terminal,shell_pgid);

    tcgetattr(shell_terminal,&shell_tmodes);
  }
}

void main(){
  init_shell();
  while(1){
    char *ehhh=malloc(sizeof(char)*100);
    printf("insert leh boi");
    scanf("%s\n", ehhh);
  }
}
