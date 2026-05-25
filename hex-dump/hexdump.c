/*
 * ============================================================================
 *  File: myhexdump.c
 *  Description: a clone of original hexdump
 *
 *  Copyright (c) 2026 Tanvir Ahmed Chowdhury
 *
 *  All rights reserved.
 *
 *  This source code is the property of Tanvir Ahmed Chowdhury.
 *
 *  Created: 2026
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void print_clear(char *s,int len)
{
	printf("| ");
	for(int i =0 ; i<len;i++)
	{
		if(s[i] < 0x20 || s[i] > 0x7E)
		{
			printf(".");
		}else{
			printf("%c",s[i]);
		}
	}
	printf(" | ");
	
}

int main()
{
	int c;
	int mem_i = 0;
	char *s = (char *) calloc(0x10,sizeof(char));
	while((c = getchar()) != EOF)
	{
		s[mem_i % 0x10] = c;

		if(mem_i % 0x10 == 0x0 )
		{
			printf("%08x ",mem_i);
		}	
	printf("%02x ",c);
	mem_i++;
         if(mem_i % 0x10 == 0x0 )
           {
			print_clear(s,0x10);
              printf("\n");
           }			
	}
	printf("%*s",3*(0x10-(mem_i%0x10))," ");
	print_clear(s,(mem_i%0x10));
	printf("\n%08x",mem_i);
	printf("\n");


return 0;

}
