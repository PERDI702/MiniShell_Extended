/*#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

pid_t pid;
printf("Un proceso...\n");
pid = fork();

while(1){
  if (pid == 0) {
        sleep(2);
        printf("printed from child process - %d\n", getpid());
        exit(EXIT_SUCCESS);
  } else if (pid > 1) {
      wait(NULL);
      printf("printed from parent process - %d\n", getpid());
    }
  }
  return 0;
}*/
