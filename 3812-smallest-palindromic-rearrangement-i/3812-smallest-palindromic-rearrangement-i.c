#include<string.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
    return *(char *)a - *(char *)b;
}
char* smallestPalindrome(char* s) {
    int n = strlen(s);
    int half = n / 2;
    qsort(s, half, sizeof(char), cmp);
    for(int i = 0; i < half; i++){
        s[n - 1 - i] = s[i];
    }
    return s;
}