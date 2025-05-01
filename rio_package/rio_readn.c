#include "riodef.h"

ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
    size_t nleft = n;
    ssize_t nread;
    char *bufptr = usrbuf;
    
    while (nleft > 0) {
        if ((nread = read(fd, bufptr, nleft)) < 0) {
            if (errno == EINTR) // if a signal occurs during sys call
                nread = 0;
            else
                return -1;
        }
        else if (nread == 0)
            break;
        nleft -= nread;
        bufptr += nread;
    }
    
    return (n - nleft);
}
