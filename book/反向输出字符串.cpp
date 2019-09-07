#include <stdio.h>
#include <string.h>

void rev(char *buf, int size)
{
        int i = 0;
        int temp;
        for(;i<size/2; i++)
        {

                temp = buf[i];
                buf[i] = buf[size-i-1];
                buf[size-i-1] = temp;
        }
}

int main()
{
    char str[20] = "hello world!";
    int size;

    size = strlen(str);

    printf("%s\n", str);

    rev(str, size);
    printf("%s\n", str);

    return 0;
}
