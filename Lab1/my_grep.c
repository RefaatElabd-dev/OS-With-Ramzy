#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[2], "r");
    
    char *buffer;
    size_t bufsize = 32;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }


    while(getline(&buffer,&bufsize, fp) >= 0 || !feof(fp)){
       if (strstr(buffer, argv[1]) != NULL) {
            printf("the subString is exestis in this Line: %s\n", buffer);
        }
      }
    fclose(fp);

    return(0);
}
