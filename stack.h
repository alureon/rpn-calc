struct stack {
    int cpos;
    void *mem;
};

struct stack *stk_new();
void stk_push(struct stack *stk, int i);
int stk_pop(struct stack *stk);
void stk_close(struct stack *data);
