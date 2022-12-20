
#include "so_long.h"



int main(void)
{
    char **tz;
    int i = 0;

        tz = ft_split("1111111111111111111\n100C000000100000001\n1000000000001000001", '\n');

    while(tz[i])
    {

            printf("%s", tz[i]);
         
        i++;
    }
    return (0);
}
