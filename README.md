this project is a simple shell command interprator
the out put are the same as /bin/sh also the errors
after runing ./hsh u will get an interface to put a command to write
read the command
parse it
execute command
return back to interface untill it user write "exit" , EOF, or ctr+c
basic flowchart will be like this
as the project progress it will have additional features
currently works for both full path also handled path
it impliment exit
Implement the env built-in, that prints the current environment
Handle command lines with arguments
Display a prompt and wait for the user to type a command.
A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple as for now it cant handle non interactive mode yet