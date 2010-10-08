/*
 * =====================================================================================
 *
 *       Filename:  439.c
 *
 *    Description:  Knight Moves
 *    		    brute force
 *
 *        Created:  06.10.10
 *       Revision:  
 *       Compiler:  GCC 4.4
 *
 *         Author:  Yang Zhang, treblih.divad@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

static int adjacent[64] = {0, 3, 2, 3, 2, 3, 4, 5,
			   3, 2, 1, 2, 3, 4, 3, 4,
			   2, 1, 4, 3, 2, 3, 4, 5,
			   3, 2, 3, 2, 3, 4, 3, 4,
			   2, 3, 2, 3, 4, 3, 4, 5,
			   3, 4, 3, 4, 3, 4, 5, 4,
			   4, 3, 4, 3, 4, 5, 4, 5,
			   5, 4, 5, 4, 5, 4, 5, 6};

int main(int argc, const char *argv[])
{
	char src[3];
	char dst[3];
	while (1) {
		if (scanf("%s", src) == EOF) break;
		scanf("%s", dst);
		if (src[0] == 'a' && src[1] == '1' && dst[0] == 'b' && dst[1] == '2') {
			puts("To get from a1 to b2 takes 4 knight moves.");
			continue;}
		if (src[0] == 'b' && src[1] == '2' && dst[0] == 'a' && dst[1] == '1') {
			puts("To get from b2 to a1 takes 4 knight moves.");
			continue;}

		if (src[0] == 'h' && src[1] == '1' && dst[0] == 'g' && dst[1] == '2') {
			puts("To get from h1 to g2 takes 4 knight moves.");
			continue;}
		if (src[0] == 'g' && src[1] == '2' && dst[0] == 'h' && dst[1] == '1') {
			puts("To get from g2 to h1 takes 4 knight moves.");
			continue;}

		if (src[0] == 'a' && src[1] == '8' && dst[0] == 'b' && dst[1] == '7') {
			puts("To get from a8 to b7 takes 4 knight moves.");
			continue;}
		if (src[0] == 'b' && src[1] == '7' && dst[0] == 'a' && dst[1] == '8') {
			puts("To get from b7 to a8 takes 4 knight moves.");
			continue;}

		if (src[0] == 'h' && src[1] == '8' && dst[0] == 'g' && dst[1] == '7') {
			puts("To get from h8 to g7 takes 4 knight moves.");
			continue;}
		if (src[0] == 'g' && src[1] == '7' && dst[0] == 'h' && dst[1] == '8') {
			puts("To get from g7 to h8 takes 4 knight moves.");
			continue;}

		printf("To get from %s to %s takes %d knight moves.\n", src, dst, 
			adjacent[(abs(src[0] - dst[0]) << 3) + abs(src[1] - dst[1])]);
	}
	return 0;
}
