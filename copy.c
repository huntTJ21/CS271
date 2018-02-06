#include "stdio.h"
#include <stdbool.h>
int main(argc,argv)
int argc;
char* argv[];
{
    int fd_in, fd_out, nbytes;
    char buf[512];
    fd_in = open(argv[1],0);
    fd_out = creat(argv[2],0644);
    nbytes = read(fd_in, buf, 512);

    bool detect_space = true;
    int wordCount = 0;
    for(int i = 0; i < nbytes; i++){
        if(buf[i] == 32){               //if character is a space
            if(detect_space == false){  //and the previous character was not also a space 
                detect_space = true;
                wordCount++;            //add one to the word count
            }
        }

    }

    while(nbytes >0){
        printf("%i", wordCount);
        write(fd_out, buf, nbytes);
        nbytes = read(fd_in, buf, 512);
    }
}
