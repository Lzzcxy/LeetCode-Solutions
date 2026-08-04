#include <string.h>

void reverse(char* s, int left, int right) {
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char* reverseStr(char* s, int k) {
    int n = strlen(s);
    for (int i = 0; i < n; i += 2 * k) {
        int right = (i + k < n) ? (i + k - 1) : (n - 1);        
        reverse(s, i, right);
    }
    return s;
}