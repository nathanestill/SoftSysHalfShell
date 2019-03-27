# Software Systems Project 1: Turtles in a Half Shell
## Nathan Estill and Jordan Crawford O'Banner

### Project Goals
The goal of our project is to simulate a UNIX shell. Our MVP is to create a shell that contains five commands that the user can use.

Our stretch goal is to get our shell as close to the UNIX command line as we can. How far we are able to get with our stretch goal will depend on our schedules and how fast we are able to achieve our MVP before the project is due.
### Learning goals
We want to become more comfortable with C. We want to get better with the thought of Small Tools that was outlined in C, of making small tools that do one thing really well. In the same vein, practicing Top-Down programming by listing the functions and tools that we have to make, then just implementing each of the tools we need.
### Resources

[Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)

[Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)

[Simple C Shell](https://github.com/jmreyes/simple-c-shell)

### Final Project

#### Starting Tasks
We started by going through the tutorials to get a good grasp of how a shell works. We each read a few and understood how they worked before implementing a part of a shell that uses a third party function to handle all of the commands. Then we made an outline that includes each of the commands that we will implement.

We implemented the start of a shell, with a program that makes a child process that handles commands and closes when they give the exit command. From there, we started to work on individual commands. We separated the shell into multiple files because it allowed us to collaborate without worrying about Github errors.

#### List
ls returns all of the files and folders in the current directory. It has three possible paramaters that can include files that start with '.', add commas between each file, and add quotations around each file. It also color codes the output, with files in white and folders in blue. This is mostly done with the dirent library, which gets the files and folders within a directory, as well as the type.

```C
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
```

#### Change Directory
cd changes the current file that the shell is working out of to one specified by the user. The function takes in an array that has all of the arguments that were input into the command line and the number of arguments that the input has. The function also has a similar ability to the Ubuntu shell by moving to the home directory when the user inputs "~".

```C
if(!strcmp(args[1],"~")){
  chdir(getenv("HOME"));
}
else {
  if(chdir(args[1])==-1){
    printf("This doesn't even exist my dude\n");
  }
}
```
#### Remove
rm removes the file specified from memory. rm cannot normally remove folders with things in them unless the -r flag is raised. To remove folders, the function recursively calls itself on all files and folders within the folder, until the folder is empty. The following code snippet showcases how the recursion of deleting a folder is completed.

```C
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
```
#### Make Directory
mkdir makes a new folder within the current directory. The function will make the new folder in the current directory if it is not otherwise specified by the user. The file is automatically initialized to be readable and writable by the user.

```C
struct stat file= {0};
if(stat(args[1],&file)==-1){
  mkdir(args[1],0700);
}
free(file);
```
#### Shell Process
The shell works with a series of processes that are forked from the parent process. When a child process is forked, it handles one command, then terminates. Then the parent process forks another child until the user exits. If the child process does anything permanent with the shell, like cd, the parent calls the function. The change directory function is called before the child process is forked in order to permanently change the working directory of the shell because the child will always be in the same directory as the parent.

```C
command = inputToCommand(input,&len);
if(!strcmp(command[0],"cd")){
  changeDirectory(command,len);
  continue;
}
child = fork();
if(child == 0){
  manageEnviron(command, len);
  if(commandVal == -1){
    break;
  }
}
```
### Reflection
We have a better understanding of the Linux shell after having read through the tutorials of making a shell. This includes learning about parent and child processes, which we were previously unaware of. We learned a lot more C, primarily working with arguments passed, due to our commands taking many different arguments. We also learned much about how much C has control of files and directories on the computer. We completed our MVP and not much more.
