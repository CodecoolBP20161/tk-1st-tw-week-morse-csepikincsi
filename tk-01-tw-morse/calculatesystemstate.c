#include "selfprot.h"

/*
 * Function: CalculateSystemState
 * --------------------------------------------
 * calculate the system state based on environment data and
 * stores the calculated state in the caught data structure
 *
 * env: contains environment data and calculated state will be stored in it
 */
void CalculateSystemState(EnvironmentData *env) {
	/*High acceleration AND temperature */

	float x = (float)(env->acc_x)/10;
	float y = (float)(env->acc_y)/10;
	float z = (float)(env->acc_z)/10;

	int temp = env->temp;
	int magnitude = 0;

	printf("\n env.accx %f", x);
	printf("\n env.accy %f", y);
	printf("\n env.accz %f", z);
	printf("\n env.temp %i", temp);


	if (!(x == 0 && y == 0 && z == 0)) {
		//ez itt kurvára nem jó !!
		magnitude = (x*2 + y*2 + z*2) / (x*2 + y*2 + z*2);
		printf("\n result : %i", magnitude);

	}

		/*High acceleration*/
	if (x >= 2 || y >= 2 || z >= 2 || magnitude > 3) {
		if (temp > 34){
			SystemState state = {3};
			env->state = state;
		}else {
			SystemState state = {1};
			env->state = state;
		}
	}

	/*High temperature*/
	if (temp > 34 && (x < 2 || y < 2 || z < 2)) {
		SystemState state = {2};
		env->state = state;
	}
}
