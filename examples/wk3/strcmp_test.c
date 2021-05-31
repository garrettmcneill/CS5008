#include <stdio.h>
#include <string.h>

//stack overflow https://stackoverflow.com/questions/55033405/type-quit-to-quit-c-program/55033679

int main()
{

    do {
        char c;     /* final character read */
        int retn;   /* variable to save scanf return */
        /* prompt */
        fputs ("Enter a bunch of words ('quit' exits): ", stdout);
        /* read saving scanf return */
        retn = scanf (" %199[^\n]%c", string, &c);
        if (retn == EOF) {      /* check the return against EOF */
            fputs ("(user canceled input)\n", stderr);
            return 0;
        }
        else if (retn < 2) {    /* checking both string and c read */
            fputs ("input failure.\n", stderr);
            empty_stdin();
        }
        else if (c != '\n') {   /* check c is '\n', else string too long */
            fprintf (stderr, "warning: input exceeds %d characters.\n",
                     MAXC - 1);
            empty_stdin();
        }
        else    /* good input, output string */
            printf ("string: %s\n", string);

    } while (strcmp (string,"quit") != 0);

    return 0;
}