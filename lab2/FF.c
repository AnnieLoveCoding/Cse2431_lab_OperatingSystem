#include <stdio.h>

int main(int argc, char *argv[]) {
	//char* argF[3] = {"123", "234", "Fang He"};
	//printf("%s", argF[0]);
	
	for(int i = 0; i < 3; i++){
		printf("%s\n", argv[i]);
	}
	exit(0);
}