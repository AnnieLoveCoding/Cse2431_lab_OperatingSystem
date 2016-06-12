#include <stdio.h>
//#include <stdlib.h>

int main(int argc, char *argv[]) {
	int A = getpid();
	int B, C1, C1a, D, C2, E, F; 
	char* arg[1] = {0};
	
	B = fork();
	if(B == 0){
		execl("./BB", NULL);
	}else{
		 C1 = fork();
		 if(C1 == 0){
			execv("CC", arg);
			}else{
				C1a = fork();
				if(C1a == 0){
					execv("CC", arg);
				}else{
					//wait BB to terminate create XYZ
					wait();
					
					printf("Pid %d, Code AA: Created process Pid %d(code BB), process Pid %d(code CC), process Pid %d(code CC)\n", A, B, C1, C1a);

					printf("Pid %d Code AA : Process Pid %d terminated\n", A, B);
					D = fork();
					if(D == 0){
						execv("DD", arg);
						exit(5);
					}else{
						//wait D to terminate 
//						while(1){
//							if(wait() == D){
//								break;
//							} 
//						}
//						
							int z;
							waitpid(D, &z, 0);
							
							E = fork();
							if(E == 0){
								execv("EE", arg);
							}else{
								printf("Pid %d CodeAA: Process Pid %d terminated(not D) process.\n", A, E);

								printf("Kill C1, C1a, C2!\n");
								kill(C1, arg);
								kill(C1a, arg);
								kill(C2, arg);
								usleep(0.25);
								
								printf("0.25 sec elapsed");
								
								int xyzInteger;
								char string[200];
								
								printf("Pid %d Code AA: Input an interger\n", A);
								scanf("%i", &xyzInteger);
								
								printf("Pid %d Code AA: Input a string \n", A);
								scanf("%s", string);
								
								
								F = fork();
								if(F == 0){
									char buffer[10];
									snprintf(buffer, 10, "%d", xyzInteger);
									//char* argF[] = {buffer, string, "Fang He"};
									
									char* argF[] = {buffer, string, "Fang He"};
									
									//execlp("./FF", "./FF", buffer, string, "Fang He", NULL);
									
									//execlp("./FF","./FF", argF);
									execv("FF", argF);
								}else{
									sleep(3);
									printf("Pid %d Code AA: Created process Pid %d(code DD), process Pid%d(code CC), process Pid %d(code EE)\n", A, D, C2, E);
									exit(0);
								}
							}
							
						}
					}
				}
			}
	
	
}