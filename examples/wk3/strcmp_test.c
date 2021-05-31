#include <stdio.h>
#include <string.h>

//stack overflow https://stackoverflow.com/questions/20738324/how-to-stop-a-program-based-on-users-input-in-c/20739382

int main()
{
    int a;
    int b;
    char c[5] = {'\0'};
    printf("Enter the two values you like to compare, type stop to end.\n");
    while (strcmp(c,"stop"))
    {
        scanf("%d%d%s", &a, &b, c);
        if (!(a^b))
        {
            printf("both are equal\n");
            getchar();
        }
        else
        {
            printf("both are not equal\n");
            getchar();
        }
    }
    printf("Thanks for playing.");
    getchar();
    return 0;
}