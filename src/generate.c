#include "../include/generate.h"

enum Status generateRandomString( int poolBuffer[], int bufLength, int stringLength, char * string )
{
    int bufValueCount = 0;
    for ( int i = 0; i < bufLength; i++ )
    {
        // If all pools have been selected, finalize bufValueCount to 4 and exit
        if ( poolBuffer[i] == 5 )
        {
            bufValueCount = NUM_CHARACTER_POOLS - 1;
            break;
        } 
        // If a poolID is found, increment bufValueCount
        else if ( poolBuffer[i] != 0 ) bufValueCount++;

    }

    srand( time( NULL ) );

    // for every character in the random string that will be generated
    for ( int j = 0; j < stringLength; j++ )
    {
        // calculate a random pool ID between 0 and bufValueCount - 1
        int poolIdx = rand() % bufValueCount;
        int pool = -1;

        // if we are selecting from all pools, assign current poolIdx to pool
        if ( 4 == bufValueCount )
        {
            pool = poolIdx;
        }
        // otherwise, take the charPoolID at poolBuffer[poolIdx] and assign it to pool
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

        // for each pool, generate a random index from the pool and assign it to the string
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

    // ensure the string is terminated with a null character
    string[stringLength] = '\0';

    return SUCCESS;
}