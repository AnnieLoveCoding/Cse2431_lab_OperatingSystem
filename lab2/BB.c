#include <stdio.h>
#define PERMS 0777    /* RW for owner, group, others */
#include <unistd.h>  //for offset

int main(int argc, char *argv[]) {
	int Bpid = getpid();
	printf("Pid %d Code BB: Creating file XYZ and write 200 chars\n", Bpid);
		
	int xyzAddr, xyAddr, rSize;
	char* buf[200];
	
	xyzAddr = creat("XYZ.txt", PERMS);
	if(xyzAddr < 0){
		printf("Create XYZ error!");
		exit(0);
	}
	
	xyAddr = open("x.y", 0);
	if(xyAddr < 0){
		printf("Open x.y error!");
		exit(0);
	}
	
	//if(lseek(xyAddr, -201, SEEK_END) == -1){
	int cur = lseek(xyAddr, -200, SEEK_END);
		
	if(cur == -1){
		printf("Can not seek!");
		exit(0);

	}
	
	rSize = read(xyAddr, buf, 200);
	if(rSize < 200){
		printf("There are less than 200 char in x.y!");
		exit(0);
	}
	
	if(write(xyzAddr, buf, 200) < 0){
		printf("Write XYZ error!");
		exit(0);
	}
	
	close(xyzAddr);
	close(xyAddr);
	printf("Pid %d Code BB: Done and terminating.\n", Bpid);
	exit(0);
}