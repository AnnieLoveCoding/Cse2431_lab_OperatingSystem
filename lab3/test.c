#include <stdio.h>
#include "ssem.h"
#include "sshm.h"


int main(int argc, char *argv[]) {
	int A = getpid();
	int pro1, pro2, pro3;
	
	pro1 = fork();
		
	if(pro1 == 0){
		execl("./Proc1", NULL);
	}
	wait();
	
	pro2 = fork();
	if(pro2 == 0){
		execl("./Proc2", NULL);
	}
	
	pro3 = fork();
	if(pro3 == 0){
		execl("./Proc3", NULL);
	}
	
	wait();
	
	/*
	pro1 = fork();
	if(pro1 == 0){
		execl("./Proc1", NULL);
	
	}else{
		printf("Finish pro1");
		pro2 = fork();
		if(pro2 == 0){
			execl("./Proc2", NULL);
		}
		else{
			pro3 = fork();
			if(pro3 == 0){
				execl("./Proc3", NULL);
			}
		}
	}
	*/
	
	
}