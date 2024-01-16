#include "../include/generate.h"

enum Status generateRandomString( int poolBuffer[], int bufLength, int stringLength, char * string )
{
    int bufValueCount = 0;
    for ( int i = 0; i < bufLength; i++ )
    {
        if ( poolBuffer[i] == 5 )
        {
            bufValueCount = NUM_CHARACTER_POOLS - 1;
            break;
        } 
        else if ( poolBuffer[i] != 0 ) bufValueCount++;

    }

    srand( time( NULL ) );

    for ( int j = 0; j < stringLength; j++ )
    {
        int poolIdx = rand() % bufValueCount;
        int pool = -1;

        if ( 4 == bufValueCount )
        {
            pool = poolIdx;
        }
        else if ( 0 <= poolIdx && poolIdx < bufLength )
        {
            pool = poolBuffer[poolIdx] - 1;
        }
        else
        {
            printf( "ERROR: Random number generation failed, quitting...\n" );
            return 1;
        }

        int charIdx = 0;
        switch ( pool )
        {
            case 0: 
                charIdx = rand() % strlen( LOWERCASE );
                string[j] = LOWERCASE[charIdx];
                break;
            case 1: 
                charIdx = rand() % strlen( UPPERCASE );
                string[j] = UPPERCASE[charIdx];
                break;
            case 2: 
                charIdx = rand() % strlen( NUMBERS );
                string[j] = NUMBERS[charIdx];
                break;
            case 3: 
                charIdx = rand() % strlen( SYMBOLS );
                string[j] = SYMBOLS[charIdx];
                break;
            default:
                printf( "ERROR: Invalid character pool selected, quitting...\n" );
                return 1;
       }
    }

    string[stringLength] = '\0';

    return SUCCESS;
}