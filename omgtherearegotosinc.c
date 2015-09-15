#include <stdio.h>

//OMFG C has goto statements.  Never use them. LOL!

main()
{
    int x = 1;

    somelabel:

        printf("%d\n", x);
        x++;
        goto somelabel;

    done:
        return (0);
}
