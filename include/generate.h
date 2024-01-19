#include "input.h"
#include "../include/encrypt.h"

#include <time.h>
#include <stdlib.h>
#include <string.h>

/*
    regenerateRandomString: 
    output: Status code
    input: int poolBuffer[] = buffer which contains the selected character pools
           int bufLength = represents the length of the buffer
           int stringLength = length of desired string
           char * string = string to be filled out with random characters
    description: recursively calls itself and generateRandomString to regenerate the string as many times as needed
*/
enum Status regenerateRandomString( int poolBuffer[], int bufLength, int stringLength, char * string );

/*
    generateRandomString: 
    output: Status code
    input: int poolBuffer[] = buffer which contains the selected character pools
           int bufLength = represents the length of the buffer
           int stringLength = length of desired string
           char * string = string to be filled out with random characters
    description: generates a random string out of characters selected from the user's chosen character pools
*/
enum Status generateRandomString( int poolBuffer[], int bufLength, int stringLength, char * string );
