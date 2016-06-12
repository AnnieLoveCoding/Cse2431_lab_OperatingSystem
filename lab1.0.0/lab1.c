#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <sys/param.h>
#include <fcntl.h>
#include <string.h>
#define PERMS 0777    /* RW for owner, group, others */

int reverse(int fileIn, int fileOut) {
	char data;
	int r;
	if (read(fileIn, &data, 1) == 1) {
		r=reverse(fileIn, fileOut)+1;
		write(fileOut, &data, 1)+1;
		
	}
	else {
		r = 1;
	}
	return r;

}

int main() {
	int xx,xyz,xxx,www,zzz,rr,wr,c1,c2,count,rch,wch,i,counta,countb;
	char buffer[500];
	xx = open("xx.xx",0);
	xyz = creat("XYZ.doc",PERMS);
	rr = read(xx,buffer,100);
	count=0;
	//1
	while (rr==100) {
		if(write(xyz, buffer, 100)<0){
			printf("write error");
			exit(0);
		}
		if(write(xyz, "ABC", 3)<0){
			printf("write ABC error");
			exit(0);
		}
		count++;
		//printf("%i\n",rr);
		//printf("%s",buffer);
		rr = read(xx,buffer,100);
	}
	
	printf("read:%d\n",rr);


	wr = write(xyz, buffer, 100);
	printf("read:%d\n",wr);
	
	rch = 100*count+wr;
	wch = 103*count+wr+3;
	wr = write(xyz, "ABC", 3);
	count++;
	printf("read:%i\nwrite:%i\n",rch,wch);
	c1 = close(xx);
	c2 = close(xyz);
	
	//2
	int k;
	char wbuffer[100];
	count=0;
	counta=0;
	countb=0;
	xyz = open("XYZ.doc",0);
	xxx = creat("XXX.txt",PERMS);
	www = creat("WWW.txt",PERMS);
	rr=read(xyz,buffer,110);
	if(rr<0){
		printf("read error start");
		exit(0);
	}
	while (rr==110) {
		for (i=0;i<rr;i++) {
			if (buffer[i]=='1') {
				if (write(xxx, "A", 1)<0){
					printf("write A error");
					exit(0);
				}
				counta++;
			}else {
				wbuffer[0]=buffer[i];
				if (write(xxx, wbuffer, 1)<0){
					printf("write normal error 110");
					exit(0);
				}
				counta++;
				//printf("%c",buffer[i]);
			}
		}
		rr=read(xyz,buffer,150);
		if (rr!=150){
			break;
		}
		for (i=0;i<rr;i++) {
			if (buffer[i]=='2') {
				if(write(www, "Ba", 2)<0){
					printf("write Ba error");
					exit(0);
				}
				countb=countb+2;
			}else {
				wbuffer[0]=buffer[i];
				if(write(www, wbuffer, 1)<0){
					printf("write normal error 150");
					exit(0);
				}
				countb++;
			}
		}
		rr=read(xyz,buffer,110);
	}
	printf("XXX.txt:%i\nWWW.txt:%i\n",counta,countb);
	
	c2=close(xyz);
	c2=close(xxx);
	c2=close(www);
	unlink("XYZ.doc");
	
	//3
	xxx=open("XXX.txt",O_RDWR);
	lseek(xxx, 999, 0);
	strcpy(wbuffer,"12345678abcdefgh");
	if (write(xxx, wbuffer, 16)<0) {
		printf("write at 1000 error");
		exit(0);
	}
	c2=close(xxx);
	
	//4
	www=open("WWW.txt",O_RDWR|O_APPEND);
	if (write(www, "BowenDai", 8)<0) {
		printf("write at 1000 error");
		exit(0);
	}
	c2=close(www);
	//5
	www=open("WWW.txt",O_RDWR);
	lseek(www, 900, 0);
	rr=read(www,buffer,200);
	lseek(www, 900, 0);
	if (write(www, "abcdefghijklmnopQRSTUVWXYZ", 26)<0) {
		printf("write at 900 error");
		exit(0);
	}
	while (rr==200) {
		if (write(www, buffer, 200)<0){
			printf("zzz 200 write error");
		}
		count++;
		rr=read(www,buffer,200);
	}

	c2=close(www);
	//6,7
	count=0;
	zzz = creat("ZZZ.txt",PERMS);
	xxx = open("XXX.txt", 0);
	www = open("WWW.txt", 0);
	rr=read(xxx,buffer,200);
	while (rr==200) {
		if (write(zzz, buffer, 200)<0){
			printf("zzz 200 write error");
		}
		count++;
		rr=read(xxx,buffer,200);
	}
	count=count*200+rr;
	count=count+reverse(www, zzz);
	printf("ZZZ.txt:%i\n",count);
	c2=close(zzz);
	c2=close(xxx);
	c2=close(www);
	//8
	zzz=open("ZZZ.txt", O_RDWR);
	if (zzz<0) {
		printf("open zzz 80 error");
		exit(0);
	}
	lseek(zzz, 0, 0);
	strcpy(buffer, "");
	//printf("buffer:%s",buffer);
	count=1;
	//printf("buffer:%s",buffer);
	rr=read(zzz,buffer,80);
	if (rr<0) {
		printf("read zzz 80 error1");
	}
	while (rr==80) {
		if (count%100==0) {
			printf("%s\n",buffer);
		}
		count++;
		rr=read(zzz,buffer,80);
		if (rr<0) {
			printf("read zzz 80 error2");
		}
	}
	if (count%100==0 && rr>0) {
		printf("%s\n",buffer);
	}
	c2=close(zzz);
	unlink("ZZZ.txt");
	unlink("XXX.txt");
	unlink("WWW.txt");
	exit(0);
	return 0;
}