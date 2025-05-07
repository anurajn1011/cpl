#pragma once

// some libraries to include by default
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h> //macos is posix compliant
#include <errno.h>

// defining the rio_t struct
#define RIO_BUFFERSIZE 8192
typedef struct {
    int rio_file_descriptor;
    int rio_count; //unread bytes
    char *rio_buffptr; //subsequent unread byte
    char rio_buffer[RIO_BUFFERSIZE];
} rio_t;

ssize_t  rio_writen(int fd, void *usrbuf, size_t n);
ssize_t rio_readn(int fd, void *usrbuf, size_t n);

void rio_readinitbuffer(rio_t *rp, int fd);
ssize_t rio_readlineb(rio_t *rp, void *usrbuff, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuff, size_t n);
