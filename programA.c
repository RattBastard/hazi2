#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define SEED 2024

int randint(int lo, int hi){
    return lo + (rand() % (hi - lo + 1));
}

void feltolt(const int n, int tomb[]){
    for (int i = 0; i < n; i++)
    {
        tomb[i] =randint(10,99);
    }
}

int main()
{
    srand(SEED);
    int szamok[MAX];
    feltolt(MAX,szamok);

    FILE *makefile;
    makefile = fopen("numbers.txt", "w");

    for (int i = 0; i < MAX; i++)
    {
        fprintf(makefile, "%d\n", szamok[i]);
    }

    fclose(makefile);
}