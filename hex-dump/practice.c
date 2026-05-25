#include <stdio.h>
#include <stdlib.h>

void print_clear(char *s,int len){
    printf("| ");
    for(int i = 0;i<len;i++)
    {
        
        if(s[i] < 0x20 || s[i] > 0x7E)
        {
             printf("."); // Replace speacial char with dot
        }else{
            printf("%c",s[i]);
        }
        
        
    }
       printf(" |");
}

int main(){
    int c;
    int mem_i = 0;
    char *s = (char *) calloc(0x10,sizeof(char)); // Memory Buffer

    while ( (c = getchar()) != EOF) // getchar()/sccanf() - get user ino
    {
        s[mem_i % 0x10] = c;
        if(mem_i % 0x10 == 0x0)
        {
            printf("\n%08x ",mem_i); // 8 bit with empty bits replaced with 0
        }
        printf("%02x ",c); // 2 bit each char and if adrs is one then print other one with 0
        mem_i++;
       
        if(mem_i % 0x10 == 0x0)
        {
            print_clear(s,0x10);
            printf("\n");
            //  printf("\n%08x ",mem_i); // 8 bit with empty bits replaced with 0
        }
    }
    printf("%*s",3*(0x10 - (mem_i%0x10))," ");
    print_clear(s,(mem_i%0x10));
    printf("\n%08x",mem_i);
    printf("\n");
    
}



// List of Bitwise Operators
// Operator	                Name	                         Description
//     &	                    AND	                  Only Both ON Gives ON - 1 - 1 - 1 else all 0
//     |	                    OR	                  Sets each bit to 1 if at least one of the bits is 1
//     ~	                    NOT	                  Inverts all the bits
//     <<	                    Left Shift	          Shifts bits to the left (multiplies by powers of 2)
//     >>	                    Right Shift	          Shifts bits to the right (divides by powers of 2)