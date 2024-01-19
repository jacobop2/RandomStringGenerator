#pragma once

#include <stdio.h>

#define MAX_PASSWORD_LENGTH 50
#define NUM_CHARACTER_POOLS 5

#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS "1234567890"
#define SYMBOLS "~!@#$^&*()=+[{]}];:<>/?"
#define ALL LOWERCASE UPPERCASE NUMBERS SYMBOLS

enum Status {
    SUCCESS,
    QUIT,
    ERROR_INVALID_INPUT,
    ERROR_UNKNOWN
};

/*
    placeCharPool: 
    output: 0 = successful placement
            1 = unsuccessful placement
    input: int buffer[] = buffer containing current assortment of character pools
           int bufLength = int representing the length of the buffer
           int charPoolID = int representing the ID of the character pool to be placed
    note: buffer is filled from index 0 to length
*/
int placeCharPool( int buffer[], int bufLength, int charPoolID );

/*
    processLengthInput: 
    output: Status code 
    input: int * passwordLength = buffer to be filled with the user input password length
*/
enum Status processLengthInput( int * stringLength );

/*
    processCharacterPoolInput: 
    output: Status code
    input: int buffer[] = buffer cwhich will be filled with the selected character pools
           int bufLength = int representing the length of the buffer
    note: buffer is filled from index 0 to length
*/
enum Status processCharacterPoolInput( int * buffer, int bufLength );