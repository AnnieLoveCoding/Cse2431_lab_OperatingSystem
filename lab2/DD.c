#include <stdio.h>
//#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
	int C3, index;
	int D = getpid();
	char *arg[1] = {0};
	
	C3 = fork();
	if(C3 == 0){
		
		execv("CC", arg);
	}else{
		
		printf("Pid %d Code DD :Create process Pid %d (code CC) and waiting for 0.5 sec\n", 						D, C3);
		usleep(5);
		index = fork();
		
		if(index == 0){
			write(1, "----output from ps-----\n", 100);
			char* para = {"", "-A","Fang He", NULL};
			execl("/bin/ps",para);
			
			exit(5);
		}else{
			/*int status, i;
			while(1){
				wait(&status);
				i = WEXITSTATUS(status);
				if(i == 5){
					break;
				}
			}
			*/
			printf("Pid %d Code DD: 0.5 sec elapsd. Create %d (ps), and waiting for it to terminate.\n", D, index);


			int z;
			waitpid(index, &z, 0);
			
			printf("Pid %d Code DD: Process Pid %d terminate.\n", D, index);
			printf("Pid %d Code DD: Killing Process Pid %d.\n", D, C3);

			kill(C3, SIGKILL);
			printf("Pid %d Code DD: Process Pid %d terminate.\n", D, C3);
			}
	}

	exit(0);
}