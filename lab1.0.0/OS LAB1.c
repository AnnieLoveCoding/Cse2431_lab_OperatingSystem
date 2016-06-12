#include <stdio.h>
#include <fcntl.h>
#define PERMS 0777    /* RW for owner, group, others */

int main() {
	
//part 1
	int xxAddr, xyzAddr, readSize;
	char buf[100]; 
	
	xxAddr = open("xx.xx", 0);
	xyzAddr = creat("XYZ.doc", PERMS);
		
	int count = 0;
		do{
		readSize = read(xxAddr, buf, 100);
		if(readSize < 0){
			printf("Read error!");
			exit(0);
		}
		
		if(write(xyzAddr, buf, 100) < 0){
			printf("Write error!");
			exit(0);
		}
		
		if(write(xyzAddr, "ABC", 3) < 0){
			printf("Write ABC error!");
			exit(0);
		}
		
		if(readSize < 100) break;
		count++;
	}while(readSize > 0);
	
//	printf("LastRead:%d\n",readSize);
	
	int rSize = count*100 + readSize;
	int wSize = (count + 1)*3 + rSize;
	
	printf("Part1: Number of characters read from xx.xx is : %d\n", rSize);
	printf("Part1: Number of characters written in XYZ.doc is : %d\n", wSize);
	
	printf("   \n");
	
	close(xxAddr);
	close(xyzAddr);
	
	
	
	
	//part2
	int xxxAddr, wwwAddr, readSize2, writeSize2;
	int countXXX = 0, countWWW = 0;
	char buf2[150];
	char temp[300];
	
	xxxAddr = creat("XXX.txt", PERMS);
	wwwAddr = creat("WWW.txt", PERMS);
	xyzAddr = open("XYZ.doc", 0);
		
		do{
		readSize2 = read(xyzAddr, buf2, 110);
		if(readSize2 < 0){
			printf("Read error!");
			exit(0);
		}


		for(int i = 0; i < readSize2; i++){
			if(buf2[i] == '1'){
				buf2[i] = 'A';
			}
		}
		
	
		if(write(xxxAddr, buf2, readSize2) < 0){
			printf("Write XXX error!");
			exit(0);
		}
		
		countXXX = countXXX + readSize2; 
		
		
		readSize2 = read(xyzAddr, buf2, 150);
		if(readSize2 < 0){
			printf("Read XYZ error!");
			exit(0);
		}
		
		int cur = 0;
		for(int i = 0; i < readSize2; i++){
			if(buf2[i] == '2'){
				temp[cur] = 'B';
				cur = cur + 1;
				temp[cur] = 'a';
			}else{
				temp[cur] = buf2[i];
			}
			cur = cur + 1;
		}
		
		if(write(wwwAddr, temp, cur) < 0){
			printf("Write WWW error!");
			exit(0);
		}
		countWWW = countWWW + cur;
			
	}while(readSize2 > 0);
	printf("Read 000 error!");
	printf("Part2: Number of characters written in XXX.txt is : %d\n", countXXX);
	printf("Part2: Number of characters written in WWW.txt is : %d\n", countWWW);
	printf("Read qqq error!");

	printf("Read 000 error!");
	int x1= close(xxxAddr);
	int x2 = close(wwwAddr);
	int x3 = close(xyzAddr);
    unlink("XYZ.doc");
	
	//remove(xyzAddr);
	
	/*
	//part3
	int xxxAddr3;
 	const char *String = "12345678abcdefgh";

	xxxAddr3 = open("XXX.txt", O_RDWR);
	lseek(xxxAddr3, 999, SEEK_SET);
	if(write(xxxAddr3, String, 16) < 0){
		printf("Write XXX error!");
		exit(0);
	}
	close(xxxAddr3);
	
	
	//part4
	/*
	const char *MyName = "Fang He";
	FILE *fp4 = fopen("WWW.txt", "a+");
	if(fp4 == 0){
		printf("Can't open file!\n");
		exit(0);
	}
	
	fseek(fp4, 0, SEEK_END);
	fwrite(MyName, strlen(MyName)*sizeof(char), 1, fp4);
	fclose(fp4);
	
	*/
	//part5
	printf("Read 111 error!");
	char *original1 = "abcdefghijklmnopQRSTUVWXYZ";
	int wwwAddr5, rSize5;

	char original2[26];
	printf("Read 222 error!");
	
	//back up 
	lseek(wwwAddr5, 900, SEEK_SET);
	
	printf("Read 333 error!");
	do{
		printf("Read 333 error!");
		rSize5 = read(wwwAddr5, original2, 26);
		if(rSize5 < 0){
			printf("Read WWW error!");
			exit(0);
		}

		lseek(wwwAddr5, -26, SEEK_CUR);
		
		
		if(write(wwwAddr5, original1, 26)){
			printf("Write WWW error!");
			exit(0);
		}
		
		strcpy(original1, original2);
		
	}while(rSize5 > 0);
	
	close(wwwAddr5);
	
	/*
	//part6
	int zzzAddr, xxxAddr6, countZZZ = 0, rSize6 = 0;
	char buf6[200];
	zzzAddr = creat("ZZZ.txt", PERMS);
	xxxAddr6 = open("XXX.txt", 0);
	
	do{
		rSize6 = read(xxxAddr6, buf6, 200);
		if(write(zzzAddr, buf6, 200) < 0){
			printf("Write ZZZ error!\n");
			exit(0);
		}
		countZZZ = countZZZ + rSize6;
	}while(rSize6 > 0);
		
	printf("Part6: Number of characters written in ZZZ.txt is : %d\n", countZZZ);

	//part7



//part8
	int zzzAddr8, rSize8, count8 = 0;
	char buf8[80];
	zzzAddr8 = open("ZZZ.txt", 0);
	if(zzzAddr8 < 0){
		printf("open zzz 80 error");
		exit(0);
	}
	
	do{
		rSize8 = read(zzzAddr8, buf8, 80);
		if(rSize8 < 0){
			printf("read zzz 80 error1");
			exit(0);
		}
		count++;
		if(count%100 == 0){
			printf("Part8: Every hundredth set of 80 characters:%s\n", buf8);
		}
		
	}while(rSize8 > 0);
	
	close(zzzAddr8);
	unlink("ZZZ.txt");
	unlink("XXX.txt");
	unlink("WWW.txt");
	exit(0);
	return 0;

	*/
}