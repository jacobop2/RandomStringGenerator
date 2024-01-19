#include "C:\dev\libs\libsodium-win64\include\sodium.h"
#include <string.h>

enum Status savePasswordtoFile( char * string );


//gcc -o main -g src/main.c src/input.c src/generate.c src/encrypt.c -I include -I C:\dev\libs\libsodium-win64\include -L C:\dev\libs\libsodium-win64\lib