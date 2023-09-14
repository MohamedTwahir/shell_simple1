# simple_shell
* In this assignment i learnt about a command line interpreter famously known as shell. Operations of the shell are basic: when typing a command you first get a prompt in your screen, then the shell creates a child process that executes the command you have entered and it then prompts you for more user input when it has finished.
* although the shell will be similar to the one we use everyday but this version is simpler and no need for too much functionalities in it.

# Task 0;Betty would be proud
Write a beautiful code that passes the Betty checks.


# Task 1: Simple shell 0.1
Write a UNIX command line interpreter.
 *Usage: simple_shell
Your shell should:
	-Display a prompt and wait for the user to type a command. A command line always ends with a new line.
	-The prompt is displayed again each time a command has been executed.
	-The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
	-The command lines are made only of one word. No arguments will be passed to programs.
	-If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
	-You have to handle the “end of file” condition (Ctrl+D)

You don't have to:
	-use the PATH
	-implement built-ins
	-handle special characters: ", ', `, \, *, &, #
	-be able to move the cursor
	-handle commands with arguments
execve will be the core part of the Shell, don't forget to pass the environ to it...
