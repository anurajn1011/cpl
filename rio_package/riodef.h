#pragma once

// some libraries to include by default
#include <stdio.h>
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
