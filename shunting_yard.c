#include "stack.h"
#include "lex.h"

#include <stdio.h>
#include <string.h>

char unlex(int token)
{
    switch(token) {
        case OP_ADD: {
            return '+';
        }
        case OP_SUB: {
            return '-';
        }
        case OP_MUL: {
            return '*';
        }
        case OP_DIV: {
            return '/';
        }
        default: return 'x';
    }
}

void infix_to_postfix(char *infix, char *output)
{
    struct stack *opstk = stk_new();
    while(1) {
        int i;
        switch(lex(&infix, &i)) {
            case TK_NUM: {
                char out[22];
                sprintf(out, "%d ", i);
                strcat(output, out);
                break;
            }
            case TK_OP: {
                // TODO: implement precendence
                stk_push(opstk, i); 
                break;
            }
            case TK_LP: {
                stk_push(opstk, TK_LP);
                break;
            }
            case TK_RP: {
                int opr = stk_pop(opstk);
                if(opstk->cpos != 0) {
                    do {
                        char out[2];
                        sprintf(out, "%c", unlex(opr));
                        strcat(output, out);
                    } while(opr = stk_pop(opstk) != TK_LP);
                }
                break;
            }
            case TK_EOF: {
                if(opstk->cpos != 0) {
                    do {
                        char out[2];
                        sprintf(out, "%c", unlex(stk_pop(opstk)));
                        strcat(output, out);
                    } while(opstk->cpos != 0);
                }
                strcat(output, "\n");
                stk_close(opstk);
                return;
            }
            default: break;
        }
    }
}
