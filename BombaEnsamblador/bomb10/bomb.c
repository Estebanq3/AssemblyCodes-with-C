/***************************************************************************
 *
 * Bombas para el Cadejo, Version 1.1
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "support.h"
#include "phases.h"

FILE *infile;

int main(int argc, char *argv[])
{
    char *input;

    /* Cuando se ejecuta sin parametros el programa lee de la entrada estándar. */
    if (argc == 1) {  
	infile = stdin;
    } 

    /* Cuando se ejecuta con un parámetro <file>, el programa lee del archivo <file> 
     * hasta encontrar EOF y luego cambia a leer de entrada estándar. Conforme usted 
     * resuelva fases, puede agregar las respuestas al archivo y evitar tener que re-
     * escribirla en cada ejecución del programa. */
    else if (argc == 2) {
	if (!(infile = fopen(argv[1], "r"))) {
	    printf("%s: Error: No pude abrir %s\n", argv[0], argv[1]);
	    exit(8);
	}
    }

    /* No se puede invocar al programa con más de un parámetro. */
    else {
	printf("Uso: %s [<input_file>]\n", argv[0]);
	exit(8);
    }

    /* Ejecuta inicializaciones secretas que hacen que las fases
     * sean difíciles de desactivar. */
    initialize_bomb();

    printf("Hola, estás ejecutando tu archivo con bombas.\n");
    printf("Tienes que resolver 6 fases. Buena suerte!\n");

    /* Efectivamente, seis fases son mejor que una sola! */
    input = read_line();             /* Lee una hilera              */
    phase_1(input);                  /* Ejecuta la fase             */
    phase_defused();                 /* Si pasa a este punto la fase
				      * fue resuelta con éxito!     */
    printf("Fase 1: desarmada. Vamos a la siguiente.\n");

    /* La segunda fase requiere más esfuerzo.  Nadie podrá resolverla ... */
    input = read_line();
    phase_2(input);
    phase_defused();
    printf("Fase 2: listos con esta fase. Si se pudo!! ...\n");

    /* Parece que la anterior estuvo muy fácil.  Va más difícil ahora. */
    input = read_line();
    phase_3(input);
    phase_defused();
    printf("Fase 3: Bien!!! Estamos a mitad del camino!\n");

    /* Cómo estás en matemática?  Resuelve el siguiente problema! */
    input = read_line();
    phase_4(input);
    phase_defused();
    printf("Fase 4: Esta fase estuvo interesante, a ver como te va en la siguiente.\n");
    
    /* Aquí vamos, de un lado a otro de la memoria, de bomba en bomba! */
    input = read_line();
    phase_5(input);
    phase_defused();
    printf("Fase 5: Buen trabajo! Seguimos...\n");

    /* Esta fase nunca será ejecutada, porque nadie va a llegar aquí!! Jaja...
     * pero solo por si acaso, hagámosla un poco más compleja. */
    input = read_line();
    phase_6(input);
    printf("Fase 6: Parece que llegaste al final...\n");
    phase_defused();

    /* Imposible!!! pero parece que lo lograste!  No dejaste nada de camino? 
     * yo revisaría ... :) */
    
    return 0;
}
