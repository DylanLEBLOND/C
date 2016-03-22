#include <stdio.h>

int main(void)
{
    int i = 0;
    int j, tmp;
    int tab[8] = {10, 15, 5, 3, 7 , 3, 0, 20};
    
    while (i < 8)
    {
        j = 7;
        while (j > i)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            --j;    
        }
        ++i;
    }
    j = -1;
    while (++j < 8)
        printf("tab[%d] = %d\n", j, tab[j]);
    return (0);
}