/*
ID: treblih1
PROG: gift1
LANG: C
*/

#include <stdio.h>
#include <string.h>

static char name[10][16];
static char given_list[10][16];
static int amount[10];

int name_cmp(char *s)
{
	int i;
	for (i = 0; i < 10; ++i) {
		if (!strncmp(s, name[i], 14)) return i;
	}
	return -1;
}

int main(int argc, const char *argv[])
{
	int np, idx, i, j, amt, num, given, remainder;
	char name_tmp[16];
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	while (fscanf(fin, "%d", &np) != EOF) {
		for (i = 0; i < np; ++i) fscanf(fin, "%s", name[i]);
		for (i = 0; i < np; ++i) {
			fscanf(fin, "%s", name_tmp);
			idx = name_cmp(name_tmp);
			fscanf(fin, "%d%d", &amt, &num);
			if (!num) continue;
			remainder = amt % num;
			given = amt / num;
			amount[idx] += remainder ? -(amt - remainder) : -amt;
			for (j = 0; j < num; ++j) {
				fscanf(fin, "%s", given_list[j]);
				amount[name_cmp(given_list[j])] += given;
			}

		}
		/* load done, print */
		for (i = 0; i < np; ++i) {
			fprintf(fout, "%s %d\n", name[i], amount[i]);
		}
	}
	return 0;
}
