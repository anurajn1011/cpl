#include "riodef.h"

ssize_t  rio_writen(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nwritten;
    char *buffptr = usrbuf;
    
    while (nleft > 0) {
        if ((nwritten == write(fd, buffptr, nleft)) <= 0) {
            if (errno == EINTR)
                nwritten = 0;
            else
                return -1;
        }
        nleft -= nwritten;
        buffptr += nwritten;
    }
    
    return n;
}
