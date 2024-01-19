#include "../include/input.h"
#include "../include/generate.h"

int main ()
{
    printf( "Welcome to the Password Generator\n" );

    int stringLength = 0;

    if ( SUCCESS != processLengthInput( &stringLength ) )
    {
        printf( "ERROR: failed to process the password length input, quitting..." );
        return 0;
    }

    printf( "The generated password will be length %d.\n", stringLength );

    int buf[NUM_CHARACTER_POOLS];

    for ( int i = 0; i < NUM_CHARACTER_POOLS; i++ )
    {
        buf[i] = 0;
    }

    if ( SUCCESS != processCharacterPoolInput( buf, NUM_CHARACTER_POOLS ) )
    {
        printf( "ERROR: failed to process the character pool selection, quitting..." );
        return 0;
    }

    char * stringBuffer;

    if ( SUCCESS != generateRandomString( buf, NUM_CHARACTER_POOLS, stringLength, stringBuffer ) )
    {
        printf( "ERROR: failed to generate the random string, quitting..." );
        return 0;
    }

    int exit = regenerateRandomString( buf, NUM_CHARACTER_POOLS, stringLength, stringBuffer );

    if ( SUCCESS != exit && QUIT != exit )
    {
        printf( "ERROR: failed to regenerate the random string, quitting..." );
        return 0;
    }

    printf( "Program finished, quitting..." );

    return 0;
}