#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <assert.h>
#include "leercadena.h"
#include <sys/types.h>
#include <signal.h>

#define MAX 100

int main(int argc, char* argv[]) 
{
  char **vector_cadenas;
  char cadena[MAX];
  pid_t pid_aux;
  while (1) 
  {
    pid_t pid;
	  printf("> ");
	  leer_de_teclado(MAX, cadena);
	  vector_cadenas = de_cadena_a_vector(cadena);
    
    // Si el usuario ingresa "salir", el programa se detiene e imprimira
    // en pantalla "Gracias por usar mi dummy_shell :-)"
    if (strcmp("salir",vector_cadenas[0]) == 0) break;
    
    pid = fork();
    assert(pid >= 0);

    // Si el usuario ingresa "tareas" esto mostrara en pantalla todos
    // los procesos que se estan realizando en background
    if(strcmp("tareas", vector_cadenas[0]) == 0)
    {
      //printf("%s\n", vector_cadenas);
      //int tamano = strlen(cadena);
      //cadenas = cadenas+tamano;
      printf("%s\n", vector_cadenas[0]);
      if (pid == 0 && (strcmp("&", vector_cadenas[1]) == 0)) {
        char buffer[MAX];
        strcat(strcpy(buffer, vector_cadenas[0]), "&");
        execvp(buffer, vector_cadenas);
      }
      else if (pid == 0) {
        printf("ingresa aqui");
        execvp(vector_cadenas[0], vector_cadenas);
      }else {
        wait(NULL);
      }
    }

    // Si el usuario ingresa "detener", solicitara al usuario el PID del
    // proceso que queria detener o "matar". Utilizando la funcion kill()
    if(strcmp("detener",vector_cadenas[0]) == 0)
    {
      printf("Introduzca el PID del proceso a detener: ");
      scanf("%d",&pid_aux);
      kill(pid_aux, SIGKILL);
    }
    else {
      wait(NULL);
    }
  }
  
  printf("Gracias por usar mi dummy shell ;-)\n");

  return 0;
}
