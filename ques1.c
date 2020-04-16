question no 1:
Write a C program using the fork() system call that generates this sequence in the child process. The starting number will be provided from the user. For example, if 8 is passed as a 
parameter on the command line, the child process will output 8, 4, 2, 1. Because the parent and child processes have their own copies of the data,it will be necessary for the child to
output the sequence. Have the parent invoke the wait() call to wait for the child process to complete before exiting the program.Perform necessary error checking to ensure that a 
positive integer is passed on the command line. 
 
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	
	int p=0;
	int n=0;
	
	pid_t pid;

		do
		{
			printf("enter a number which is greater than 0"); 
  			scanf("%d", &p);	
		}while (p<= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("Child is waiting\n");
			printf("%d\n",p);
			while (p!=1)
			{
				if (p%2 == 0)
				{
					p = p/2;
				}
				else if (p%2 == 1)
				{
					p= 3 * (p) + 1;
				}	
			
				printf("%d\n",p);
			}
		
			printf("Child process done the work\n");
		}
		else
		{
			printf("Parents is waiting for child process...\n");
			wait();
			printf("Parent process is done the work.\n");
		}
	return 0; 
}