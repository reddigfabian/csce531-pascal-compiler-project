#include <stdio.h>

extern int A,B,C;

Print_abc()
{
	printf("a = %d; b =  %d; c = %d\n",A,B,C);
}

extern int X;

Print_x()
{
	printf("x = %d\n",X);
}


extern float Z;

Print_z()
{
	printf("z = %e\n",Z);
}

extern double W;

Print_w()
{
	printf("w = %lf\n",W);
}

extern unsigned char Ca[8];

Print_ca()
{
	int i;
	printf("ca = \"");
	for (i=0; i<8; i++)
		printf("%c", Ca[i]);
	printf("\"\n");
}

extern long Ia[6];

Print_ia()
{
	int i;
	printf("ia = [ ");
	for (i=0; i<6; i++)
		printf("%ld ", Ia[i]);
	printf("]\n");
}

extern double Ra[3];

Print_ra()
{
	int i;
	printf("ra = [ ");
	for (i=0; i<3; i++)
		printf("%.6lf ", Ra[i]);
	printf("]\n");
}

extern long Iaa[11][11];

Print_iaa()
{
	int i, j;
	printf("iaa =\n[\n");
	for (i=0; i<11; i++) {
		printf("  [ ");
		for (j=0; j<11; j++)
			printf("%4ld ", Iaa[i][j]);
		printf("]\n");
	}
	printf("]\n");
}

extern long Iaaa[3][4][5];

Print_iaaa()
{
	int i, j, k;
	printf("iaaa =\n[\n");
	for (i=0; i<3; i++) {
		printf("  [\n");
		for (j=0; j<4; j++) {
			printf("    [ ");
			for (k=0; k<5; k++)
				printf("%4ld ", Iaaa[i][j][k]);
			printf("]\n");
		}
		printf("  ]\n");
	}
	printf("]\n");
}

Print_oops()
{
	printf("oops!\n");
}

Print_7()
{
	printf("7");
}

Print_1()
{
	printf("1");
}

Print_2()
{
	printf("2");
}

Print_newline()
{
	printf("\n");
}

Print_is()
{
	printf(" is ");
}

Print_grooviest()
{
	printf("grooviest\n");
}

Print_outer()
{
	printf("OUTER: a = %d\n",A);
}

Print_inner()
{
	printf("INNER: b = %d\n",B);
}

Print_inner_inner()
{
	printf("INNER INNER: c = %d\n",C);
}

Print_looping()
{
	printf("LOOPING: x = %d\n",X);
}

Print_looping_looping()
{
	printf("LOOPING LOOPING: b = %d\n",B);
}

Print_looping_looping_looping()
{
	printf("LOOPING LOOPING LOOPING: c = %d\n",C);
}
