//
//  main.c
//  FuzzBizzNezz
//
//  Created by Johnny Hermann on 2015-01-11.
//  Copyright (c) 2015 Johnny Hermann. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//
// Consts
//

#define EXIT_FAILURE_ARGS_NUM -1 // Failure due to invalid number of args
#define EXIT_FAILURE_ARGS_RANGE -2 // Failure due to arg values not in valid range

#define FUZZ_TEXT "Fuzz"
#define BIZZ_TEXT "Bizz"

//
// proc: main
//
// usage:
//		FuzzBizzNezz <fuzz> <bizz> <nezz>
//
// description:
//		Prints the numbers from 1 to "nezz" except as follows:
//		- Multiples of <fuzz>, print "Fuzz".
//		- Multiples of <bizz>, print "Bizz".
//		- Multiples of both, print "FizzBuzz".
//
// args:
//		fuzz - divisor to determine when to print "Fuzz"
//		bizz - divisor to determine when to print "Bizz"
// 		nezz - inclusive upper limit of number range
//
// returns:
//		EXIT_SUCCESS - If success
//		EXIT_FAILURE_ARGS_NUM - If wrong number of args passed.
//		EXIT_FAILURE_ARGS_RANGE - If at least one arg is out of its range.
//
int main(int argc, const char * argv[]) {
	
	// Extract and validate command-line args.

	if (argc != 1 + 3) return EXIT_FAILURE_ARGS_NUM;
	
	const char* app = argv[0];
	int fuzz = atoi(argv[1]);
	int bizz = atoi(argv[2]);
	int nezz = atoi(argv[3]);
	
	if (fuzz < 1 || bizz < 1 || nezz < 1) return EXIT_FAILURE_ARGS_RANGE;

	printf("%s %d %d %d\n", app, fuzz, bizz, nezz);
	
	// Loop thru integers 1 to 'nezz'.
 	// Print keywords at 'fuzz' and 'bizz' divisible numbers.
	for (int i = 1; i <= nezz; i++) {
		
		if (i % fuzz == 0 && i % bizz == 0) {printf("%s%s ", FUZZ_TEXT, BIZZ_TEXT); continue;}
		if (i % fuzz == 0) {printf("%s ", FUZZ_TEXT); continue;}
		if (i % bizz == 0) {printf("%s ", BIZZ_TEXT); continue;}
		
		printf("%d ", i);
	}
	printf("\n");
	
	return EXIT_SUCCESS;
}
