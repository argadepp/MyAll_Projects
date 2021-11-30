/*
 ============================================================================
 Name        : stringfns.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a,b,ty) { ty t=a; a=b; b=t; }
char* pstrrev(char *s) {
     char *r=s, *q=s;
     while(*q != '\0')
         q++;
     q--;
     while(s < q) {
        SWAP(*s, *q, char);
        s++;
        q--;
     }
     return r;
}

int pstrcmp(char *s1, char *s2) {
    while(*s1 == *s2 && *s1 != '\0') {
         s1++;
         s2++;
    }
    return *s1 - *s2;
}

#define LWR(ch) (ch>='A' && ch<='Z' ? (ch + 32) : ch)
int pstrcmpi(char *s1, char *s2) {
    while(LWR(*s1) == LWR(*s2) && *s1 != '\0') {
         s1++;
         s2++;
    }
    return LWR(*s1) - LWR(*s2);
}

char* pstrcpy(char *d, char *s) {
    char *r = d;
    do {
       *d = *s;
       s++;
       d++;
    } while(*s != '\0');
   return r;
}

char* pstrcat(char *d, char *s) {
	char *r = d;
	while(*d != '\0')
		d++;
	pstrcpy(d, s);
	return r;
}

size_t pstrlen(char *s) {
    size_t cnt = 0;
    while(*s != '\0') {
        cnt++;
        s++;
    }
    return cnt;
}

int pstrncmp(char *s1, char *s2, int n) {
    while(n > 1 && *s1 == *s2 && *s1 != '\0') {
         s1++;
         s2++;
         n--;
    }
    return *s1 - *s2;
}

char* pstrchr(char *s, int ch) {
	while(*s != '\0') {
		if(*s == ch)
			return s;
		s++;
	}
	return NULL;
}

char* pstrstr(char *s, char *w) {
	int diff, len = pstrlen(w);
	while(*s != '\0') {
		diff = pstrncmp(s, w, len);
		if(diff == 0)
			return s;
		s++;
	}
	return NULL;
}

int main(void)
{
	char s[] = "ABCDE", *p;
	pstrrev(s);
	puts(s);

	char s1[] = "RAM", s2[] = "RAJ";
	int diff = pstrncmp(s1, s2, 2);
	printf("diff : %d\n", diff);

	char str[] = "ABCDE";

	p = pstrchr(str, 'D');
	if(p == NULL)
		printf("char not found.\n");
	else
		printf("char found at index = %d.\n", p - str);

	p = pstrstr(str, "CD");
	if(p == NULL)
		printf("word not found.\n");
	else
		printf("word found at index = %d.\n", p - str);

	return 0;
}


