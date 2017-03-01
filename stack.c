#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack *stk_new()
{
    struct stack *data = malloc(sizeof(struct stack));
    data->cpos = 0;
    data->mem = malloc(1);
    return data;
}

int stk_peek(struct stack *data)
{
    if(data->cpos > 0) {
        int newpos = data->cpos - sizeof(int);
        return *(int*) (data->mem + newpos);
    }
    return 0;
}

int stk_pop(struct stack *data)
{
    if(data->cpos == 0) {
        printf("ERROR: Attempt to pop from empty stack!\n");
        return 0;
    }
    void *old = data->mem;
    int cpos = data->cpos;
    int newpos = cpos - sizeof(int);
    int ret = stk_peek(data);
    data->mem = realloc(old, newpos);
    data->cpos = newpos;
    return ret;
}

void stk_push(struct stack *data, int d)
{
    void *old = data->mem;
    int cpos = data->cpos;
    int newpos = cpos + sizeof(int);
    data->mem = realloc(old, newpos);
    if(data->mem != old) {
//        free(old);
    }
    *(int*) (data->mem + cpos) = d;
    data->cpos = newpos;
}

void stk_close(struct stack *data)
{
    if(data) {
        if(data->mem) {
            free(data->mem);
        }
        free(data);
    }
}
