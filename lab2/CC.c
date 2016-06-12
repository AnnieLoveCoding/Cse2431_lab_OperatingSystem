#include <stdio.h>

int main(int argc, char *argv[]) {
	int Cpid = getpid();
	printf("Pid %d Code CC:Entering an infinite loop\n", Cpid);
	while(1){
		usleep(100);
	}
	exit(0);
}