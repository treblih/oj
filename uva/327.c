/*
 * =====================================================================================
 *
 *       Filename:  327.c
 *
 *    Description:  Evaluating Simple C Expressions
 *
 *        Created:  03.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <ctype.h>

#ifdef DB
	#define getchar()		getc(fp)
	#define	scanf(...)		fscanf(fp, __VA_ARGS__)
#endif

enum {
	LEFT,
	RIGHT
};

/* it says that 110 at most */
static FILE *fp;
static char expr[128];
static char *p;
static int total;
static struct alpha {
	int val;
	int inc_dec;
	int used;
} alpha[26];

/* find the latest char which is not ' ' */
char *adjacent(char *s, int direct)
{
	if (direct == LEFT) {
		while (*--s == ' ') ;
	} else {
		while (*++s == ' ') ;
	}
	return s;
}

void inc_dec_2_spc()
{
	int ch;
	char *pos;
	for (; (ch = *p); p++) {
		if (ch == '+' && *(pos = adjacent(p, RIGHT)) == '+') {
			/* x  ++ */
			if (islower(ch = *adjacent(p, LEFT))) {
				alpha[ch - 0x61].inc_dec = 1;
			/* ++  x */
			} else if (islower(ch = *adjacent(pos, RIGHT))) {
				alpha[ch - 0x61].val += 1;
			}
			*p = *pos = ' ';/* clear the other '+' */
			p = pos;	/* p++ above */
		} else if (ch == '-' && *(pos = adjacent(p, RIGHT)) == '-') {
			/* x  ++ */
			if (islower(ch = *adjacent(p, LEFT))) {
				alpha[ch - 0x61].inc_dec = -1;
			/* ++  x */
			} else if (islower(ch = *adjacent(pos, RIGHT))) {
				alpha[ch - 0x61].val -= 1;
			}
			*p = *pos = ' ';/* clear the other '-' */
			p = pos;	/* p++ above */
		}
	}
}

void alpha_init()
{
	int i;
	for (i = 0; i < 26; i++) {
		alpha[i].val = i + 1;
		alpha[i].inc_dec = alpha[i].used = 0;
	}
}

void expression()
{
	int operand;
	int operator;
	if (!(*p)) 	return ;
	while ((operand  = *p++) == ' ') ;
	/* the prepending spaces */
	if (!operand) 	return ;
	while ((operator = *p++) == ' ') ;
	alpha[operator - 0x61].used = 1;
	/* edited by ++x */
	operator = alpha[operator - 0x61].val;
	if (operand == '+') {
		total += operator;
	} else {
		total -= operator;
	}
	expression();
}

int main(int argc, const char *argv[])
{
#ifdef DB
	fp = fopen("input.txt", "r");
#endif
	int i;
	int ch;
	while ((ch = getchar()) != EOF) {
		/* expr end with var not operator, 
		 * add '+' to make them pairs */
		expr[0] = '+';
		expr[1] = (char)ch;
		/* start from idx 2 */
		for (i = 2; (ch = getchar()) != '\n'; i++) {
			expr[i] = (char)ch;
		}
		expr[i] = '\0';
		p = expr + 1;		/* skip to the adding '+' */
		printf("Expression: %s\n", p);
		alpha_init();
		inc_dec_2_spc();	
		p = expr;
		total = 0;
		expression();
		printf("    value = %d\n", total);
		for (i = 0; i < 26; i++) {
			if (alpha[i].used) {
				printf("    %c = %d\n", 
				       i + 0x61, 
				       alpha[i].val + alpha[i].inc_dec);
			}
		}
	}
	return 0;
}
