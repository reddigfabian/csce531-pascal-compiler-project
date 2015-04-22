#include <stdio.h>
#include <stdarg.h>

int Printf(char *format, ...)
{
    int ret;

    va_list ap;
    va_start(ap, format);
    ret = vprintf(format, ap);
    va_end(ap);
    return ret;
}

int Scanf(char *format, ...)
{
    int ret;

    va_list ap;
    va_start(ap, format);
    ret = vscanf(format, ap);
    va_end(ap);
    return ret;
}

int Getchar()
{
    return getchar();
}
