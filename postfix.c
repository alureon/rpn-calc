#include "postfix.h"
#include "stack.h"
#include "lex.h"
#include <stdio.h>
#include <stdlib.h>

int postfix_eval(char *str)
{
    struct stack *stk = stk_new();
    while(1) {
        int i;
        switch(lex(&str, &i)) {
            case TK_NUM: {
                stk_push(stk, i);
                break;
            }
            case TK_OP: {
                int temp = stk_pop(stk);
                int topstack = stk_pop(stk);
                switch(i) {
                    case OP_ADD: {
                        stk_push(stk, topstack + temp);
                        break;
                    }
                    case OP_MUL: {
                        stk_push(stk, topstack * temp);
                        break;
                    }
                    case OP_SUB: {
                        stk_push(stk, topstack - temp);
                        break;
                    }
                    case OP_DIV: {
                        stk_push(stk, topstack / temp);
                        break;
                    }
                    default: break;
                }
                break;
            }
            case TK_EOF: {
                int res = stk_pop(stk);
                stk_close(stk);
                return res;
            }
        }
    }
}
