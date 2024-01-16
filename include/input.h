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
    INVALID_INPUT
};

int placeCharPool( int buffer[], int bufLength, int charPoolID );

enum Status processLengthInput( int * passwordLength );

enum Status processCharacterPoolInput( int * buffer, int bufLength );