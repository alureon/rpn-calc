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

int get_precedence(int op)
{
    switch(op) {
        case OP_ADD:
            return PREC_ADD;
        case OP_DIV:
            return PREC_DIV;
        case OP_MUL:
            return PREC_MUL;
        case OP_SUB:
            return PREC_SUB;
        default:
            return 0;
    }
}

// this is wrong
void infix_to_postfix(char *infix, char *output)
{
    struct stack *opstk = stk_new();
    int i = 0, tok = 0;
    while(1) {
        tok = lex(&infix, &i);
        switch(tok) {
            case TK_NUM: {
                char out[22];
                sprintf(out, "%d ", i);
                strcat(output, out);
                break;
            }
            case TK_OP: {
                // TODO: implement precendence
                int sz = (opstk->cpos / sizeof(int));
                int op_prec = get_precedence(i);
                while(op_prec <= get_precedence(stk_peek(opstk))) {
                    char out[2];
                    sprintf(out, "%c", unlex(stk_pop(opstk)));
                    strcat(output, out);
                }
                stk_push(opstk, i);
                break;
            }
            case TK_LP: {
                stk_push(opstk, TK_LP);
                break;
            }
            case TK_RP: {
                int opr = stk_pop(opstk);
                if(opstk->cpos > 0) {
                    do {
                        char out[2];
                        sprintf(out, "%c", unlex(opr));
                        strcat(output, out);
                    } while(opr = stk_pop(opstk) != TK_LP);
                }
                break;
            }
            case TK_EOF: {
                if(opstk->cpos > 0) {
                    do {
                        char out[2];
                        sprintf(out, "%c", unlex(stk_pop(opstk)));
                        strcat(output, out);
                    } while(opstk->cpos > 0);
                }
                strcat(output, "\n");
                stk_close(opstk);
                return;
            }
            default: break;
        }
    }
}
