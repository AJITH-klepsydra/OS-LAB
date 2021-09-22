
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include<stdlib.h>
int main(){
	key_t token = ftok("Token",65);
	int shmId = shmget(token,1024,0666|IPC_CREAT);
	char * str = (char *) shmat(shmId,(void *)0,0);
	int choice;
	while(1){
	printf("\nProduce(1) or Consume(0) or Stop : ");
	scanf("%d",&choice);
	if(choice ==1)
		{
		int data = rand();
		printf("Data For the shared memory: %d",data);
		sprintf(str, "%d", data);
		}
	else if(choice == 0)
	{
		printf("\nVALUE IN THE SHM: %s\n",str);
		}
		else{
		printf("\nDetaching ...\nKilling...\n");
		shmdt(str);
		shmctl(shmId,IPC_RMID,NULL);
		break;
		}
		}
	

}
