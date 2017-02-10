#include "selfprot.h"
#include <stdio.h>
#include <string.h>
#define toint(c) (int)c - 48


/*
 * Function: MorseToBinary
 * --------------------------------------------
 * converts morse string input bits
 *
 * input: the convertable morse string
 * output: morse in bits
 *
 * returns: the number of used bits for morse
 */
int MorseToBinary(char input[], char output[]) {
	char a[255] = "";
	for( int i=0; i <strlen(input); i++) {
		int ascii = (int) input[i];
		if(ascii == 32) {
			strcat(a, "0");
		}
		else if (ascii == 45){
			strcat(a, "111");
		}
		else if (ascii == 46) {
			strcat(a, "1");
		}
		else if (ascii == 47) {
			strcat(a, "000");

		}
		else if (ascii == 9) {
			strcat(a, "0000000");
		}
	}
	int len = strlen(a);
	int fix_rounds = len / 8;
	int remain = len%8;
	char myByte = 0;
	int round = 0;

	for(int i=0; i < (len-remain); i += 8) {
		for(int b=0; b < 8; b++) {
			myByte |= ((int) a[i+b] - '0' << (7-b));
		}
		output[round] = myByte;
		myByte = 0;
		round += 1;

		if (round == fix_rounds) {
			for(int b=0; b < remain; b++) {
				myByte |= (int) (a[(len-remain) + b] - '0') << ( 7 - b);
			}
			output[round] = myByte;
		}
	}
return len;
}



