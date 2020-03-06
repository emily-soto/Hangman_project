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
int aciertos;
 
//Cambiamos la opcion dada por marcos y colocamos palabras random
 
 
//Prototipo de funciones
 
 
const char *word_collection[MAX_WORDS]= {
            "resiliente", "inefable", "serendipia", "limerencia", 
            "aurora", "efimero", "inmarcesible", "sempiterno", 
            "petricor", "perenne", "nefelibato", "ataraxia", "acendrado",
            "alba", "armonia", "equilibrio", "libertad", "saudade", "sublime", 
            "esplendor", "chispudo", "chilero", "meraki"
 
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
    printf("=========== HANGMAN MENU ===========\n\n");
    printf("1: Para empezar el juego\n");
    printf("2: Para ver las instrucciones\n");
    printf("3: Para conocernos\n");
    printf("4: Para salir del juego\n\n");
 
    printf("Ingrese su seleccion\n");
//definicion de variables de menu
    int seleccion;
    scanf("%d", &seleccion);
    if (seleccion==2){
        clearscreen();
        printf("INSTRUCCIONES\n\n");
        printf("El objetivo del juego es descifrar la palabra oculta adivinando la mayor cantidad de letras por las que esta compuesta. El jugador cuenta con 10 intentos, en los cuales debe ingresar una letra o palabra, si la palabra contiene la seleccion entonces se le mostrara la posicion de esta, y la cantidad de veces que se repite la letra (si es el caso); por otro lado, si el jugador ingresa una letra que no conforma la palabra, el jugador pierde un turno y debe volver a intentar adivinar. Si la seleccion es una palabra y esta es correcta, entonces el jugador ganara y el juego termina.\n\n Si el jugador no descifra la palabra en los diez intentos, el jugador perdera la partida. Si el jugador descifra la palabra durante los diez intentos, ganara la partida. Si el jugador quiere volver a jugar debe regresar al menu principal e iniciar otro juego.\n\n\n");
        }
    if (seleccion==3){
        clearscreen();
        printf("ABOUT\n\n");
        printf("Desarrolladores:\n Madeline Salguero: madelinesg@ufm.edu\n Emily Soto: emilysoto@ufm.edu\n\n Somos estudiantes de Ingenieria Empresarial de la Universidad Francisco Marroquin. El objetivo de este proyecto es mejorar nuestras habilidades en programacion, a traves del lenguaje de C; esperamos este juego sea entretenido y que aprenda de las palabras elocuentes del lenguaje.\n\n\n");
    }
    if (seleccion==4){
        clearscreen();
        exit(0);
    }
   if (seleccion==1){
        char nombre[20];
        int intentos=0;
        const char* palabrarand=get_random_word();
        int lengthw=strlen(palabrarand);
        char letra[50];
        int cubrir[lengthw];
        clearscreen();
        printf("\n\n Ingrese su nombre o alias\n\n\t");
        scanf("%s", nombre);
        clearscreen();
        
        printf("\n\nLenght %ld\n\n",strlen(palabrarand));
        for (int i=0; i < lengthw; ++i) {
          cubrir[i] = 0;
          }
 
        int gameover = 0;
        while ((! gameover)&& (intentos<10)&& (aciertos!= lengthw) ){
          clearscreen();
        printf("Jugador: %s",nombre);
        intentos=intentos+1; 
        printf("\nIntentos: %d/10", intentos); 
        printf("\nAciertos: %d", aciertos);        
      
          printf("\nDescifra la palabra:\n\n\n\t");
          for(int j=0; j < lengthw; ++j) {
            if (cubrir[j]) {
              //printf("%i", mask[j]);
              printf("%c", palabrarand[j]);
            }
            else {
              printf(" _ ");
            }
          }
          printf("\n");
 
          char guess;
       
      printf("\n\nIngresa la letra/palabra: ");
      fflush(stdout);
      scanf(" %c", &guess);
 
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
 
      // Determine whether the player has won!
      gameover = 1;
      for(int m = 0; m < lengthw; ++m) {
        if (!cubrir[m]) {
          gameover = 0;
          break;
        }
      }
    }
    if(aciertos==lengthw){
  printf("\nGanaste! La palabra era \"%s\".\n", palabrarand);
    }
   else{
  printf("\n¡Perdiste! La palabra era \"%s\".\n", palabrarand);
   }  
   }
   }
    printf("\nPara regresar al menu principal seleccione '0'\n");
    int opcion;
    scanf("%d", &opcion);
    if (opcion==0){
        goto menu;
    }
return 0;  
    }

  
