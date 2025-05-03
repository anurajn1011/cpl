//
//  rio_buffered.c
//  
//
//  Created by Anuraj Nair on 5/3/25.
//

#include "riodef.h"

// file descriptor is associated to a buffer
void rio_readinitbuffer(rio_t *rp, int fd)
{
    rp->rio_file_descriptor = fd;
    rp->rio_count = 0;
    rp->rio_buffptr = rp->rio_buffer;
}

static ssize_t rio_read(rio_t *rp, char *usrbuff, size_t n)
{
    while (rp->rio_count <= 0) {
        rp->rio_count = read(rp->rio_file_descriptor, rp->rio_buffer, sizeof(rp->rio_buffer));
        
        if (rip->rio_count < 0) { // some event has interrupted
            if (errno != EINTR)
                return -1
        }
        else if (rp->rio_count == 0) // no more to be read
            return 0;
        else
            rp->rio_buffptr = rp->rio_buffer; // reset the buffer pointer
    }
    
    // copy the minimum num of bytes from internal to user buffer
    int count = n;
    if (rp->rio_count < n) {
        count = rp->rio_count;
    }
    memcpy(usrbuff, rp->rio_buffptr, count);
    rp->rio_buffptr += count;
    rp->rio_count -= count;
    return count;
}

ssize_t rio_readlineb(rio_t *rp, void *usrbuff, size_t maxlen)
{
    int rc;
    char c;
    char *buffptr = usrbuff;
    
    for(int n = 1; n < maxlen; n++) {
        if ((rc == rio_read(rp, &c, 1)) == 1) {
            *buffptr++ = c;
            if (c == '\n') {
                n++;
                break;
            }
        }
        else if (rc == 0) {
            if (n == 1) // if no remaining data
                return 0;
            else
                break;
        }
        else {
            return - 1; // encountered error
        }
    }
    
    *buffptr = 0;
    return n - 1;
}
