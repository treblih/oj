/*
 * =====================================================================================
 *
 *       Filename:  673.c
 *
 *    Description:  Parentheses balance
 *    		    stack
 *
 *        Created:  10.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

#define	SIZE	130

static char str[SIZE];
static char stk[128];

void push(char **p, int ch)
{
	*--p = ch;
}

char *pop(char *p)
{
	if (p = stk + 128) return NULL;
	else return p++;
}

int main(int argc, const char *argv[])
{
	int cases, ch = 0;
	char *stk_p;
	scanf("%d", &cases);
	while (cases--) {
		fgets(str, SIZE, stdin);
		stk_p = stk + 128;
		for (str_p = str; (ch = *str_p) != 0; str_p++) {
			if (ch == '(' || ch == '[') push(&stk_p, ch);
		}
	}
	return 0;
}

int main()
{
	scanf("%d",&n);
	scanf("%c",&c);
	for(int i=0;i<n;i++)
	{
		gets(str);
		len=strlen(str);
		top=0;
		if(len==0)
		{
			printf("Yes\n");
			continue;
		}
		q[0]=str[0];
		bool flay = true;
		for(int j=1;j<len;j++)
		{

			if(str[j]=='('||str[j]=='[')
			{
				top++;
				q[top]=str[j];
			}
			else if(str[j]==')')
			{
				if(q[top]=='(')
					top--;
				else
				{
					flay = false;
					break;
				}
			}
			else if(str[j]==']')
			{
				if(q[top]=='[')
					top--;
				else
				{
					flay = false;
					break;
				}
			}
		}
		if(top==-1 && flay)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
