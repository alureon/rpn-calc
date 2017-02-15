#include <stdio.h>
#include "postfix.h"
#include "shunting_yard.h"

#include <string.h>

int main(int argc, char *argv[])
{
    char out[256];
    memset(out, 0, 256);
    infix_to_postfix(argv[1], out);
    int i = postfix_eval(out);
    printf("%i\n", i);
}
