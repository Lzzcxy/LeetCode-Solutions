bool isValid(char* s) {
    int top = 0;
    char stack[10005];
    for(; *s; s++){
        if(*s =='(') stack[top++] = ')';
        else if(*s == '{') stack[top++] = '}';
        else if(*s == '[') stack[top++] = ']';
        else if(top == 0 || stack[--top] != *s) return false;
    }
    return top == 0;
}