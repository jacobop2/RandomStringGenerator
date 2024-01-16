#include "../include/input.h"

int placeCharPool( int buffer[], int bufLength, int charPoolID )
{
    int idx = 0;

    for ( int i = 0; i < bufLength; i++ )
    {
        if ( 0 == buffer[i] )
        {
            buffer[i] = charPoolID;
            return 1;
        }
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

    while ( 1 ) {

        if ( 1 == scanf( "%d", &charPoolID ) ) 
        {

            int b_rv = 0;

            if ( 0 == charPoolID )
            {
                if ( numBufVals != 0 ) return SUCCESS;
                else printf( "Please select a character pool before continuing.\n" );
            }
            else if ( 0 < charPoolID && charPoolID < 6 )
            {
                
                b_rv = placeCharPool( buffer, bufLength, charPoolID );

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

        while ( getchar() != '\n' ); // Clear input buffer
    }

    // Reset charPoolID outside the loop
    charPoolID = 0;
}