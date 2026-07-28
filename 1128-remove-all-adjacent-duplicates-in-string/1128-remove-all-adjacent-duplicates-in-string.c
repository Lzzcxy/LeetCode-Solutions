char* removeDuplicates(char* s) {
    int top = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(top > 0 && s[top - 1] == s[i]){
            top--;
        }
        else{
            s[top++] = s[i];
        }
    }
    s[top] = '\0';
    return s;
}