#define TK_NUM 0
#define TK_OP  1
#define TK_EOF 3
#define TK_LP  8
#define TK_RP  9
#define TK_ERR 134

#define OP_ADD 4
#define OP_MUL 5
#define OP_SUB 6
#define OP_DIV 7

#define PREC_ADD 2
#define PREC_SUB 2
#define PREC_DIV 3
#define PREC_MUL 3

int lex(char **src, int *num);
