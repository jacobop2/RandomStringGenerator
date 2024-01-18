#include "input.h"

#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
    generateRandomString: 
    output: Status code
    input: int poolBuffer[] = buffer which contains the selected character pools
           int bufLength = represents the length of the buffer
           int stringLength = length of desired string
           char * string = string to be filled out with random characters
*/
enum Status generateRandomString( int poolBuffer[], int bufLength, int stringLength, char * string );
