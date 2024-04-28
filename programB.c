#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "prog1.h"

typedef struct
{
    int *numbers;
    int length;
    int capacity;
}DynArray;

void mem_error_exit(){
    fprintf(stderr, "Memoriaval kapcsolatos hiba lepett fel!");
    exit(1);
}

DynArray * da_create(){
    DynArray *result = malloc(sizeof(DynArray));
    if (result == NULL)
    {
        mem_error_exit();
    }
    
    int initial_cap = 2;

    result->numbers = malloc(initial_cap * sizeof(int));
    if (result->numbers == NULL)
    {
        mem_error_exit();
    }
    result->length = 0;
    result->capacity = initial_cap;


    return result;
}

void da_append(DynArray *self, int data){
    if (self->length == self->capacity)
    {
        int new_cap = 2*self->capacity;
        self->numbers = realloc(self->numbers,new_cap * sizeof(int));
        if (self->numbers == NULL)
        {
            mem_error_exit();
        }
        self->capacity = new_cap;
    }
    self->numbers[self->length] = data;
    self->length += 1;
}

void da_destroy(DynArray *self){
    free(self->numbers);
    free(self);
}

double da_avarage(const DynArray *self){
    int sum = 0;
    for (int i = 0; i < self->length; i++)
    {
        sum += self->numbers[i];
    }
    double avg = (1.0 * sum)/(1.0 * self->length);
    return avg;
}

int main()
{
    DynArray *list = da_create();

    FILE *fileread;
    fileread = fopen("numbers.txt", "r");

    char bestring[100];
    int size = 100;

    while(fgets(bestring, 100, fileread)) {
        da_append(list,atoi(bestring));
    }

    printf("%lf\n",da_avarage(list));

    da_destroy(list);

    fclose(fileread);

    return 0;
}
