#include "../include/input.h"

int placeCharPool( int buffer[], int bufLength, int charPoolID )
{
    int idx = 0;
    // loop through character pool buffer
    for ( int i = 0; i < bufLength; i++ )
    {
        // if the buffer contains an empty location, place the ID and return
        if ( 0 == buffer[i] )
        {
            buffer[i] = charPoolID;
            return 1;
        }
        // else if the ID has already been placed, return failure
        else if ( charPoolID == buffer[i] ) 
        {
            return 0;
        }
    }
    return 0;
}

enum Status processLengthInput( int * passwordLength )
{
    
    printf( "Please enter the desired length for the password:\n" );

    // run until a user input is received
    while (1) 
    {
        if ( 1 != scanf( "%d", passwordLength ) )
        {
            printf( "Please enter an integer.\n" );
        }
        else if ( 0 >= *passwordLength )
        {
            printf( "Please enter a positive and nonzero integer.\n" );
        }
        else if ( MAX_PASSWORD_LENGTH < *passwordLength )
        {
            printf( "Please enter an integer less than %d.\n", MAX_PASSWORD_LENGTH );
        }
        else
        {
            return SUCCESS;
        }

        // reset passwordLength and clear input buffer to prepare for another input
        *passwordLength = 0;
        while ( getchar() != '\n' );
    }

}

enum Status processCharacterPoolInput( int buffer[], int bufLength ) 
{
    printf( "Select characters from the following pools:\n" );
    printf( "1. Lowercase Characters\n" );
    printf( "2. Uppercase Characters\n" );
    printf( "3. Numbers\n" );
    printf( "4. Symbols\n" );
    printf( "5. All of the above\n" );
    printf( "Enter '0' to finalize all selections.\n" );

    char inputChar;
    int charPoolID = 0;
    int numBufVals = 0;

    while ( 1 ) 
    {
        // Only accept integer inputs
        if ( 1 == scanf( "%d", &charPoolID ) ) 
        {

            int b_rv = 0;

            // If 0 is entered, char pools finalized
            if ( 0 == charPoolID )
            {
                // if at least 1 char pool has been selected, return
                if ( numBufVals != 0 ) 
                    return SUCCESS;
                else 
                    printf( "Please select a character pool before continuing.\n" );
            }
            // if the char pool is between 1 and 5, process it
            else if ( 0 < charPoolID && charPoolID < 6 )
            {
                // attempt to place the char pool into the buffer
                b_rv = placeCharPool( buffer, bufLength, charPoolID );

                // if the pool is placed, increment num placed pools and inform user
                if ( b_rv != 0 ) 
                {
                    printf( "Character pool number <%d> selected.\n", charPoolID );
                    numBufVals++;
                } 
                else 
                {
                    printf( "Character pool number <%d> has already been selected.\n", charPoolID );
                }
            }
            else
            {
                printf( "Invalid entry, please enter an integer corresponding to a character pool.\n" );
            }
        }
        else
        {
            printf( "Invalid entry, please enter an integer corresponding to a character pool.\n" );
        }

        // Clear input buffer
        while ( getchar() != '\n' ); 
    }

    // Reset charPoolID outside the loop
    charPoolID = 0;
}