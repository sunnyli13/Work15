#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
	int f, pid, status;
	pid = getpid();

	printf("Parent [%d]\n\nFirst fork\n", pid);

	f = fork();

	if (f) {
		printf("Second fork\n\n");

		f = fork();
	}

	if (f) {
		int childpid = wait(&status);

		printf("Child [%d] finished and woke up after %d seconds.\n\n", childpid, WEXITSTATUS(status));
		printf("Parent finished\n");

		return 0;
	}

	else {
		int childpid = getpid();

		srand(childpid + time(NULL));
		printf("Forked Child [%d]\n", childpid);

		int slp = (rand() % 9) + 2;

		sleep(slp);

		printf("\nChild [%d] woke up\n", childpid);

		return slp;
	}
}