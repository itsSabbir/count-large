#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);

int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.

	if (argc != 2){
		return 1; 
	}
    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.
	int sin_candidate = strtol(argv[1], NULL, 10);
	int first_digit = argv[1][0] - 48; // subtraction in ascii decimals
	if (first_digit == 0){
		printf("Invalid SIN\n");	
	}

	int sin_array[9]; 

	int invalid_candidate = populate_array(sin_candidate, sin_array);
	if (invalid_candidate == 0){
		int invalid_sin = check_sin(sin_array);
		if (invalid_sin == 0){
			printf("Valid SIN\n");
		}else{
			printf("Invalid SIN\n");
		}
	}
    return 0;
}