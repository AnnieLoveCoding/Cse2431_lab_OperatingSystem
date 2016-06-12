#include "ssem.h"
#include "sshm.h"

int main()
{
	int i, internal_reg;
	//int KEY1 = 000001, KEY2 = 000002, KEY3 = 000003;
	int KEY1 = 000001;
	int KEY = 123456;
	 
/* here create and initialize all semaphores */
	int sema1 = sem_create(KEY1, 1);
	/*int sema0 = sem_create(KEY1, 1);
	int sema1 = sem_create(KEY2, 1);
	int sema3 = sem_create(KEY3, 1);
	*/

/* here created: shared memory array Account of size 3 */
	int *Account;
	int shmid = shm_get(KEY, (void**)&Account, 3*sizeof(int));
	/*
	int shmid1 = shm_get(KEY1, (void**)&Account[0], 1*sizeof(int));
	int shmid2 = shm_get(KEY2, (void**)&Account[1], 1*sizeof(int));
	int shmid3 = shm_get(KEY3, (void**)&Account[2], 1*sizeof(int));
	*/
	Account[0]=10000;
	Account[1]=10000;
	Account[2]=10000;
	
/* synchronize with Proc2, Proc3 and Proc4 (4 process 4 way
synch.)*/

	

	for (i = 0; i < 2000; i++)
	{ 
		sem_wait(sema1);
		internal_reg = Account [0];
		internal_reg = internal_reg - 200;
		Account[0] = internal_reg;
		
/* same thing, except we're adding $200 to account1 now... */
		//printf("we're adding $200 to account1 now...\n");
		internal_reg = Account [1];
		internal_reg = internal_reg + 200;
		Account[1] = internal_reg;
		sem_signal(sema1);
		
		if((i + 1)%100 == 0){
			printf("In pro1, after %dth transaction\n", i + 1);
			printf("The moeny in account0 is :%d\n", Account[0]);
			printf("The moeny in account1 is :%d\n", Account[1]);
			printf("The moeny in account1 is :%d\n", Account[2]);
			printf("In pro1, sum is  :%d\n", Account[0] + Account[1] + Account[2]);
		}
		
	}
/* Add a code that prints contents of each account and
their sum after 100th, 200th, 300th, .... and 1900th
iteration*/
}
/*in the code above include some wait and signal operations on
semaphores. Do not over-synchronize. */