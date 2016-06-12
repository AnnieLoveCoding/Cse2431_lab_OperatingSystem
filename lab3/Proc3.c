#include <stdio.h>
#include "ssem.h"
#include "sshm.h"

int main() {

int i, internal_reg;
	int KEY1 = 000001;
	int KEY = 123456;
	
//synchronize with Proc1, Proc3 & Proc4 (4 process 4 way sync.)
	int sema1 = sem_open(KEY1);
	
	int *Account;
	int shmid = shm_get(KEY, (void**)&Account, 3*sizeof(int));
	

	for (i = 0; i < 2000; i++)
{
	sem_wait(sema1);
	internal_reg = Account [2];
/*Proc3 takes from Account[2]*/
	internal_reg = internal_reg - 200;
	Account[2] = internal_reg;
/* same thing, except we're adding $200 to Account[2] now... */

/*Proc3 adds into Account[0]*/
	internal_reg = Account [0];
	internal_reg = internal_reg + 200;
	Account[0] = internal_reg;
	sem_signal(sema1);
	
	if((i + 1)%100 == 0){
		printf("In pro3, after %dth transaction\n", i + 1);
		printf("The moeny in account0 is :%d\n", Account[0]);
		printf("The moeny in account1 is :%d\n", Account[1]);
		printf("The moeny in account1 is :%d\n", Account[2]);
		printf("In pro3, sum is  :%d\n", Account[0] + Account[1] + Account[2]);
	}
}
/* Add a code that prints contents of each account
and their sum after 100th, 200th, 300th, .... and 1900th
iteration*/
}
/*in the code above include some wait and signal operations on
semaphores. Do not over-synchronize. */