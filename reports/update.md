git hub# Software Systems Project 1: Turtles in a Half Shell
## Nathan Estill and Jordan Crawford O'Banner

### Project Goals
The goal of our project is to simulate a UNIX shell. Our MVP is to create a shell that contains five commands that the user can use.

Our stretch goal is to get our shell as close to the UNIX command line as we can. How far we are able to get with our stretch goal will depend on our schedules and how fast we are able to achieve our MVP before the project is due.
### Learning goals
We want to become more comfortable with C. We want to get better with the thought of Small Tools that was outlined in C, of making small tools that do one thing really well. In the same vein, practicing Top-Down programming by listing the functions and tools that we have to make, then just implementing each of the tools we need.
### Getting Started

[Write a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)

[Making your own Linux Shell in C](https://www.geeksforgeeks.org/making-linux-shell-c/)

[Simple C Shell](https://github.com/jmreyes/simple-c-shell)

### First Steps

The first task is for both of us to read through all of the tutorials that we have collected. All of the team members are responsible for this task and will produce notes on each of the tutorials as proof of completion.

Next, the team members will collaborate to create a outline of all of the functions in the code and comments on what they need to achieve. The proof of completion for this task will be a full code skeleton that covers all the functions necessary for the MVP to be completed.

Finally we will create a Trello that outlines each of the steps that are required to complete the project and assign each task to a team member.

### First Actions

We started by going through the tutorials to get a good grasp of how a shell works. We each read a few and understood how they worked before implementing a part of a shell that uses a third party function to handle all of the commands. Then we made an outline that includes each of the commands that we will implement.

We implemented the start of a shell, with a program that makes a child process that handles commands and closes when they give the exit command. From there, we started to work on individual commands.

We separated the shell into multiple files because it allowed us to collaborate without worrying about Github errors. Jordan was tasked with handling the change directory and make directory functions, while Nathan was tasked with handling the remove and list functions.

### Current Actions

Jordan has completed the both the change directory and make directory functions. They provide the basic functionality of the Linux commands, but they do not yet have all of the tags that could possibly be added to the functions. He is currently working on adding flags that he feels are useful, and creating an initializer for the shell that allows it to have its own interactive space.

Nathan has almost completed the list function, with it listing out the files and directories in the current directory. It gets the type of the file/folder, and sorts and color-codes the output. He has implemented a few of the tags, and is looking to implement a few more. However, there are at least 20 tags, so implementing all of them is not incredibly useful as a learning exercise. The next step is to implement rm.

### Next Steps

After both of us finish these tasks, we will link them together with the shell mentioned before. We feel confidant that we can complete the project.
