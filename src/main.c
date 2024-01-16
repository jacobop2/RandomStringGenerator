#include "../include/input.h"
#include "../include/generate.h"

int main ()
{
    printf( "Welcome to the Password Generator\n" );

    int passwordLength = 0;

    if ( SUCCESS != processLengthInput( &passwordLength ) )
    {
        printf( "ERROR: failed to process the password length input, quitting..." );
        return 0;
    }

    printf( "The generated password will be length %d.\n", passwordLength );

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

    if ( SUCCESS != generateRandomString( buf, NUM_CHARACTER_POOLS, passwordLength, stringBuffer ) )
    {
        printf( "ERROR: failed to generate the random string, quitting..." );
        return 0;
    }

    printf( "Randomly generated string: <%s>", stringBuffer );

    return 0;
}