#include <stdio.h>
#include <stdlib.h>

#define teste01

#ifdef teste01

struct z
{
    int x;
    int y;
};

struct z k = {5000, 10000};

struct *pk;

int main()
{
    int *pd;

    struct z *pk;
    {
        pk = &k;

        mostra(pk);
    };
}

mostra(struct z *pd)
{
    printf("x: %d\n", pd->x);
    printf("y: %d\n", pd->y);
    {
    }
#endif // teste01