#include "selfprot.h"

/*
 * Function: CreateEnvironmentData
 * --------------------------------------------
 * converts input data into structured form
 *
 * acc_x: acceleration in the X direction
 * acc_y: acceleration in the Y direction
 * acc_z: acceleration in the Z direction
 * temp: magnitude of the temperature
 */
EnvironmentData CreateEnvironmentData(float acc_x, float acc_y, float acc_z, signed int temp) {
	printf(" x = %f", acc_x);
	printf(" y = %f", acc_y);
	printf(" z = %f", acc_z);

	int acc_x_int = (int) (acc_x*10);
	int acc_y_int = (int) (acc_y*10);
	int acc_z_int = (int) (acc_z*10);

	printf(" x after *10 = %i", acc_x_int);
	printf(" y after *10  = %i", acc_y_int);
	printf(" z after *10 = %i", acc_z_int);

	EnvironmentData env = {acc_x_int, acc_y_int, acc_z_int, temp};
	printf(" size of the structure : %d \n", sizeof(env));
	return env;
}
