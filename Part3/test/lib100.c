#include <stdio.h>

Print_nl()
{
	printf("\n");
}

Print_dot()
{
	printf(".");
}

Print_even()
{
	printf("E");
}

Print_odd()
{
	printf("O");
}

Print_j()
{
	printf("j");
}

Print_i_j_values()
{
	extern int I,J;
	printf("i = %d; j = %d\n",I,J);
}

Print_oops()
{
	printf("oops\n");
}

extern long Iaa[14][12];

Print_iaa()
{
	int i, j;
	printf("iaa =\n[\n");
	for (i=0; i<14; i++) {
		printf("  [ ");
		for (j=0; j<12; j++)
			printf("%4ld ", Iaa[i][j]);
		printf("]\n");
	}
	printf("]\n");
}

extern double Raaa[3][6][4];

Print_raaa()
{
	int i, j, k;
	printf("raaa =\n[\n");
	for (i=0; i<3; i++) {
		printf("  [\n");
		for (j=0; j<6; j++) {
			printf("    [ ");
			for (k=0; k<4; k++)
				printf("%.6lf ", Raaa[i][j][k]);
			printf("]\n");
		}
		printf("  ]\n");
	}
	printf("]\n");
}

extern double R;

Print_r()
{
	printf("r = %.6lf\n", R);
}
