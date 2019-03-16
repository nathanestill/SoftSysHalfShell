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

int is_regular_file(const char *path);
void printDir(struct dirent* dir, int m);
void list(int argc, char* argv[]);
int removeFile(int argc, char* argv[]);
void changeDirectory(char *args[], int len);
int makeDirectory(char* args[], int len);
