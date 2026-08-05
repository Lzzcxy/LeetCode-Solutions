#include<stdlib.h>

int totalFruit(int* fruits, int fruitsSize) {
    int *freq = (int*)calloc(fruitsSize, sizeof(int));
    int left = 0;
    int typeCount = 0;
    int maxLen = 0;
    for(int right = 0;right < fruitsSize; right++){
        if(freq[fruits[right]] == 0){
            typeCount++;
        }
        freq[fruits[right]]++;
        while(typeCount > 2){
            freq[fruits[left]]--; 
            if(freq[fruits[left]] == 0){
                typeCount--;
            }
            left++;
        }
        int currentLen = right - left + 1;
        if(currentLen > maxLen){
            maxLen = currentLen;
        }
    }
    free(freq);
    return maxLen;
}
