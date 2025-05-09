//
//  main.c
//  
//
//  Created by Anuraj Nair on 5/7/25.
//

#include "riodef.h"
#include <stdio.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int n;
    rio_t rio;
    char buf[MAXLINE];
    
    rio_readinitbuffer(&rio, STDIN_FILENO);
    while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0) {
        rio_writen(STDOUT_FILENO, buf, n);
    }
    
    return 0;
}
