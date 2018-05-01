#include <stdio.h>
#include <stdlib.h>


// TODO: Implement a helper named check_permissions that matches the prototype below.
int check_permissions(char *file_permits, char *req_permits){
	for (int i = 0;i< 9;i++){
		char req_permit = req_permits[i]; 
		char actual_permit = file_permits[i+1]; 
		char blank_permit = '-'; 

		if (req_permit != blank_permit && 
			req_permit != actual_permit){
			return 1; 
		}		
	}
	return 0; 
}


int main(int argc, char** argv) {
    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "USAGE: count_large size [permissions]\n");
        return 1;
    }

    // TODO: Process command line arguments.
    
    /* 0 for size mode, 1 for size and permissions mode */
    int read_mode = 0; 

    /* count of inputs being read. Starts at -2 to account for the two inputs
    from the "total #" first line. */
    int read_count = -2;

    /* next indexes of interest*/
    int next_size = 4; 

    /* Files that are over the given cutoff*/
    int oversize_files = 0; 

    /* file size cutoff specified by the user */
	int cutoff = strtol(argv[1], NULL, 10);

	/* when value is 1, all blocks that are read from current line will be ignored.
	This is set to 1 if the file is a directory, or doesn't meet the permissions req. */
	int invalid_file = 0; 

	// holds input blocks from scanf and req_permits holds permits given by the 
	// user (if any) 
    char input_str[35], *req_permits; 
	input_str[34] = '\0';

    // Process command line args 
    if (argc == 3){
    	read_mode = 1;
    	req_permits = argv[2];  
    }

    while (scanf("%s", input_str) != EOF){
    	if (read_count % 9 == 0){
    		char file_type = input_str[0]; 
    		if (file_type == 'd'){
    			// file on current line is a directory!
    			invalid_file = 1; 
    		}else if (read_mode == 1){
    			// file is not a directory and user has specified req. permissions
    			// check_permissions. If they fail, set invalid_file = 1; 
    			invalid_file = check_permissions(input_str, req_permits); 
    		}else{
    			// file is not a directory and user has not specified any permissions
    			invalid_file = 0; 
    		}
    	}else if (read_count == next_size){
    		int file_size = strtol(input_str, NULL, 10); 
            printf("SIZE: %d\n", file_size);
    		if ((invalid_file == 0) && (file_size > cutoff)){
    			oversize_files++; 
    		}
    		// Set the next position at which we will encounter a size
    		next_size += 9; 
    	}
    	read_count++; 
    }
    printf("%d\n", oversize_files); 

    return 0;
}
