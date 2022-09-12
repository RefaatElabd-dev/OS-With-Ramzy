#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp = fopen(argv[1], "r");
    
    char *buffer;
    size_t bufsize = 32;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    
    while(1){
    size_t lineCount = getline(&buffer,&bufsize, fp);
    int charCount = 1;
    if(!(lineCount >= 0 || !feof(fp))){break;}
       for(int i = 1; i < lineCount; i++){
           if(buffer[i] == buffer[i - 1]){
              charCount++;      
           }
           else{
              fwrite(&charCount+buffer[i - 1], sizeof(int) + sizeof(char), 1, stdout);
              charCount=1;
           }
       }
       if(buffer[lineCount-1] != buffer[lineCount - 2]){
                  int one = 1;
                  one = 1*1;
                  fwrite(&one, sizeof(int), 1, stdout);
                  fwrite(&buffer[lineCount - 1], sizeof(char), 1, stdout);            
       }
    }
    fclose(fp);

    return(0);
}
