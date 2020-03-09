/*Proyecto Juego de ahorcado
    Emily Soto 
    Madeline Salguero
*/
 
//librerias
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
 
//macros
#define MAX_WORDS 23
 
//Variables Globales
void imprimir (int oport, char *wordserr, char *word);
int found_word(char letra);
int exist_word(char letra);
 
//Cambiamos la opcion dada por marcos y colocamos palabras random
 
 
//Prototipo de funciones
 
 
const char *word_collection[MAX_WORDS]= {
            "pilas", "telele", "ulugrun", "fijese", 
            "atinar", "chancla", "cuchitril", "chilazo", 
            "pencacear", "shucaque", "tanate", "patatush", "chucho",
            "ishto", "hijuela", "chinchilete", "patojo", "chunche", "chanchuy", 
            "mucha", "chispudo", "chilero", "trancazo"
 
};
 
const char* get_random_word(void){
    srand ( time (0) );
    int random_position = rand() % MAX_WORDS;
    return word_collection[random_position];
}
 
void clearscreen(){
    system("@cls||clear");
}
 
int main (void){
   menu:
    clearscreen();
    //Agregue color
       printf("\033[1;32m");
    printf("00   00    111    0000   00  1111111\n");
    printf("0000000  1111111  000 00 00  111  __\n");
    printf("00   00  11   11  000   000  1111111\n\n");
    printf("\033[0m");
    //cambie el color
        printf("\033[0;32m");
    printf("   111   111     000    1111   11\n");
    printf("   1111 1111   0000000  111 11 11\n");
    printf("  111 11  111  00   00  111   111\n");
        printf("\033[0m");
        //Nuevo color
      printf("\033[1;33m");
    printf("                _  _\n");
    printf("               (x)(x) \n");
    printf("              |  ()  | \n");
    printf("            _ | '--' | _ \n");
    printf("           {   '-`""""`-'   }\n");
            printf("\033[0m");
      printf("\033[1;34m");
    printf("=====================================\n\n");
      printf("\033[0m");
    printf("\t 1: Para empezar el juego\n");
    printf("\t 2: Para ver las instrucciones\n");
    printf("\t 3: Para conocernos\n");
    printf("\t 4: Para salir del juego\n\n");
      printf("\033[1;34m");
    printf("______________________________________\n");
      printf("\033[0m");
 
    printf("\nIngrese su seleccion:\n");
    
//definicion de variables de menu
    int seleccion;
    scanf("%d", &seleccion);
    if (seleccion==2){
        clearscreen();
         printf("\033[1;36m");
        printf("INSTRUCCIONES\n\n");
          printf("\033[0m");
        printf("El objetivo del juego es descifrar la palabra oculta adivinando la mayor cantidad de letras por las que esta compuesta. El jugador cuenta con 10 intentos, en los cuales debe ingresar una letra o palabra (*cada letra equivale a un intento), si la palabra contiene la seleccion entonces se le mostrara la posicion de esta y la cantidad de veces que se repite la letra; por otro lado, si el jugador ingresa una letra que no conforma la palabra, el jugador pierde un turno y debe volver a intentar adivinar. Si la seleccion es una palabra y esta es correcta, entonces el jugador ganara y el juego termina.Si el jugador descifra la palabra durante los diez intentos, ganara la partida.\n\n ");
        printf("*Si se ingresa una palabra, cada letra de la palabra equivale a un intento. Por ejemplo la palabra 'sol', sumaría 3 intentos.\n\n");
        }
        
    if (seleccion==3){
        clearscreen();
          printf("\033[1;36m");
        printf("ABOUT\n\n");
          printf("\033[0m");
        printf("Desarrolladores:\n Madeline Salguero: madelinesg@ufm.edu\n Emily Soto: emilysoto@ufm.edu\n\n Somos estudiantes de Ingenieria Empresarial de la Universidad Francisco Marroquin. El objetivo de este proyecto es mejorar nuestras habilidades en programacion, a traves del lenguaje de C; esperamos este juego sea entretenido y que aprenda el lenguaje cotidiano del guatemalteco.\n\n\n");
    }
    if (seleccion==4){
        clearscreen();
        exit(0);
    }
   if (seleccion==1){
        char nombre[20];
        int intentos=0;
        int aciertos=0;
        const char* palabrarand=get_random_word();
        int lengthw=strlen(palabrarand);
        char letra[50];
        int cubrir[lengthw];
        clearscreen();
          printf("\033[1;36m");
        printf("\n\n Ingrese su nombre o alias\n\n\t");
          printf("\033[0m");
        scanf("%s", nombre);
        clearscreen();
        
        printf("\n\nLenght %ld\n\n",strlen(palabrarand));
        for (int i=0; i < lengthw; ++i) {
          cubrir[i] = 0;
          }
 
        int gameover = 0;
        while ((! gameover)&& (intentos<10)&& (aciertos!= lengthw) ){
          clearscreen();
            printf("\033[1;36m");
        printf("Jugador: %s",nombre);
        printf("\nIntentos: %d/10", intentos); 
        printf("\nAciertos: %d\n", aciertos);
          printf("\033[0m");    
        intentos=intentos+1; 
           
          printf("*Seleccione '0' para salir\n");
      
          printf("\nDescifra la palabra:\n\n\n\t");
          for(int j=0; j < lengthw; ++j) {
            if (cubrir[j]) {
              //printf("%i", mask[j]);
              printf("%c", palabrarand[j]);
            }
            else {
                printf("\033[0;31m");
              printf(" _ ");
                printf("\033[0m");
            }
          }
          printf("\n");
 
          char guess;
       
      printf("\n\nIngresa la letra/palabra: ");
      fflush(stdout);
      scanf(" %c", &guess);
  
      if (guess=='0'){
        clearscreen();
        exit(0);
      }
      else{
 
 //Aciertos en el juego
 for (int i = 0; i < lengthw; i++) {
            if (guess == palabrarand[i]) {
                cubrir[i] = guess;
                aciertos++;
                } else {}
        }
      // Marcar como verdaderas las posiciones adivinadas
      for(int k=0; k < lengthw; ++k) {
        if (palabrarand[k] == guess) {
    cubrir[k] = 1;
        }
 
    //Determinar si gano
      gameover = 1;
      for(int m = 0; m < lengthw; ++m) {
        if (!cubrir[m]) {
          gameover = 0;
          break;
        }
      }
    }
    if(aciertos==lengthw){
      printf("\033[0;31m");
  printf("\nGanaste! La palabra era \"%s\".\n", palabrarand);
    printf("\033[0m");
    }
      }  
   }
     if (aciertos!=lengthw){
      printf("\033[0;31m");
  printf("\n¡Perdiste! La palabra era \"%s\".\n", palabrarand);
    printf("\033[0m");
   }
   }
  printf("\nPara regresar al menu principal seleccione 'ENTER'\n");
      char noimporta[3];
      fgets(noimporta, 3, stdin);
      fgets(noimporta, 3, stdin);
        clearscreen();
         goto menu;

return 0;  
    }
