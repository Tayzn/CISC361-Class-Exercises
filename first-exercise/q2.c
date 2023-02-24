#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int status;
	int pid = fork();

	if(pid == 0) {
		pid = fork();

		if(pid == 0) {
			int grandId = getpid();
			printf("I am the grandchild %d\n", grandId);
		} else {
			wait(NULL);
			int childId = getpid();
			printf("I am the child %d\n", childId);	
		}
	} else {
		wait(NULL);
		int parentId = getpid();
		printf("I am the parent %d\n", parentId);
	}
	return 0;
}