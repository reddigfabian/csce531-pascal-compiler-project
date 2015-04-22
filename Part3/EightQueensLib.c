#include <stdarg.h>
#include <stdio.h>

int Printf(char *format, ...)
{
    int ret;

    va_list ap;
    va_start(ap, format);
    ret = vprintf(format, ap);
    va_end(ap);
    return ret;
}

int Getchar()
{
    return getchar();
}

void Putchar(int c)
{
	putchar(c);
}
