#include "selfprot.h"
#include <stdio.h>
#include <string.h>


/*
 * Function: CharToMorse
 * --------------------------------------------
 * convert characters/numbers to dots and dashes (morse code).
 * the function use the character-morse and number-morse maps
 * from the common header.
 *
 * input: the convertable string
 * output: converted morse string
 *
 * returns: the index of the last converted character of the input
 */
int CharToMorse(char input[], char *output) {
	int i;

	for (i = 0; i < strlen(input); i++) {

		if (input[i] < 91 && input[i] > 64 && i < strlen(input)) {
			strcat(output, CHAR_TO_MORSE_ALPHA[input[i]-65]);

		}
		if(i != strlen(input)-1 && input[i] != 32 && input[i+1] != 32) {
			strcat(output, "/");
		}
		if (input[i] == 32) {
			strcat(output, "\t");

		}
	}
	return i;
}
