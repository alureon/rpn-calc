#include "lex.h"

int lex(char **src, int *num)
{
    char *str = *src;
    while(1) {
        switch(*str) {
            case 0:
            case ';': {
                *src = str + 1;
                return TK_EOF;
            }
            case ' ':
            case '\r':
            case '\n': {
                str++;
                break;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': {
                int i = 0;
                do {
                    i = i * 10 + (*str) - '0';
                    str++;
                } while('0' <= *str && *str <= '9');
                *num = i;
                *src = str;
                return TK_NUM;
            }
            case '+': {
                *num = OP_ADD;
                *src = str + 1;
                return TK_OP;
            }
            case '-': {
                *num = OP_SUB;
                *src = str + 1;
                return TK_OP;
            }
            case '*': {
                *num = OP_MUL;
                *src = str + 1;
                return TK_OP;
            }
            case '/': {
                *num = OP_DIV;
                *src = str + 1;
                return TK_OP;
            }
            case '(': {
                *src = str + 1;
                return TK_LP;
            }
            case ')': {
                *src = str + 1;
                return TK_RP;
            }
            default: {
                return TK_ERR;
                break;
            }
        }
    }
}


