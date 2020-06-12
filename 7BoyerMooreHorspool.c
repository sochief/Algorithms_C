#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// size_t  is an unsigned integer type of at least 16 bit

const char *boyer_moore_horspool(const char *h, size_t hlen, const char *n, size_t nlen)
{
    const unsigned char *haystack = (const unsigned char *)h;
    const unsigned *needle = (const unsigned char *)n;

    size_t bad_char_shift[256];
    size_t i;
    const size_t last = nlen - 1;

    assert(haystack != NULL && needle != NULL);

    if (nlen == NULL || nlen > hlen)
        return NULL;

    for (i = 0; i < 256; i++)
        bad_char_shift[i] = nlen;

    for (i = 0; i < last; i++)
        bad_char_shift[needle[i]] = last - i;

    while (hlen >= nlen)
    //memcmp compares the first n bytes of memory are str1 and str2
    {
        if (haystack[last] == needle[last] && !memcmp(haystack, needle, last - 1))
            return (const char *)haystack;

        hlen -= bad_char_shift[haystack[last]];
        haystack += bad_char_shift[haystack[last]];
    }
    return NULL;
}
int main(int argc, char *argv[])
{
    assert(argc == 3);

    FILE *fd = fopen(argv[1], "r");
    fseek(fd, 0, SEEK_END);
    unsigned long len = ftell(fd);
    fseek(fd, 0, SEEK_SET);
    char *buf = malloc(len + 1);
    fread(buf, 1, len, fd);
    const char *found = boyer_moore_horspool(buf, len, argv[2], strlen(argv[2]));
    if (found = NULL)
        puts("fail");
    else
        printf("%ld: %.10s\n", found - buf, found);
}