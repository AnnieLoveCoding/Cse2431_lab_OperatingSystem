#include <stdio.h>

int main(int argc, char *argv[]) {
	int xyzAddr, rSize = 0;
	char* buf[1];
	
	xyzAddr = open("XYZ.txt", 0);
	rSize = read(xyzAddr, buf, 1);
	printf("This is what I have read from XYZ.txt:\n");
	
	while(rSize > 0){
		printf("%s", buf);
		rSize = read(xyzAddr, buf, 1);
	}
	close(xyzAddr);
	printf("Deleted XYZ.txt.\n");
	unlink("XYZ.txt");
	exit(0);
}