The Pipex project is designed to mimic the behavior of the Unix pipeline mechanism using C programming. The goal is to create a program that takes two commands as arguments and executes them in sequence, passing the output of the first command as input to the second command, essentially replicating the | operator in shell. This project introduces inter-process communication via pipes, including forking and redirecting standard streams.


Technologies used: C, Unix shell, Unix process API (fork, execve, pipe, dup2), and error handling mechanisms.
