/*
ID: treblih1
LANG: C
TASK: ride
*/

#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[])
{
	FILE *fin  = fopen ("ride.in", "r");
	FILE *fout = fopen ("ride.out", "w");
	char name[8] = {0};
	int product, product2, i, len;
	while (fscanf(fin, "%s", name) != EOF) {
		product = product2 = 1;
		len = strlen(name);
		/* 1~26, can't sub 0x41 */
		for (i = 0; i < len; ++i) {
			product *= (name[i] - 0x40);
		}
		fscanf(fin, "%s", name);
		len = strlen(name);
		for (i = 0; i < len; ++i) {
			product2 *= (name[i] - 0x40);
		}
		if (product % 47 == product2 % 47) fputs("GO\n", fout);
		else fputs("STAY\n", fout);
	}
	return 0;
}
