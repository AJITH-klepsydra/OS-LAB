
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main(){
	key_t token = ftok("Token",65);
	int shmId = shmget(token,1024,0666|IPC_CREAT);
	char * str = (char *) shmat(shmId,(void *)0,0);
	int choice;
	printf("Produce(1) or Consume(0) : ");
	scanf("%d",&choice);
	if(choice)
		{
		printf("Data For the shared memory: ");
		scanf("%s",str);
		printf("\nDetaching...\n");
		shmdt(str);
		}
	else
	{
		printf("\nVALUE IN THE SHM: %s\n",str);
		printf("\nDetaching ...\nKilling...\n");
		shmdt(str);
		shmctl(shmId,IPC_RMID,NULL);
		}
	

}
