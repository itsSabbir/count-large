// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
    for (int i = 8; i > -1; i--){
    	if ((i != 0 && (sin/10) == 0)){
    		return 1;
    	}
    	sin_array[i] = sin % (10);
    	sin = sin / 10; 
    }
    return 0;
}

// TODO: Implement check_sin
/* 
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {	
	int arr[9]; 
	int n = 0; // multiplier for Luhn Alg. 		
	for (int i = 0; i < 9; i ++){
		if ((i % 2) == 0){
			n = 1; 
		}else{
			n = 2; 
		}
		// product 
		int p = sin_array[i] * n; 
		if (p % 10 == 0){
			arr[i] = p; 
		}else{
			// first digit of product
			int p1 = p / 10; 

			// second digit of product
			int p2 = p % 10; 

			//sum of the two digits
			int  p1_p2 = p1 + p2; 
			arr[i] = p1_p2; 
		}
	}

	int arr_sum = 0;
	for (int i = 0; i < 9; i++){
		arr_sum += arr[i]; 
	}

	if (arr_sum % 10 == 0){
		return 0; 
	}
    return 1;
}