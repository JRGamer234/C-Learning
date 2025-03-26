
int strlen(char *palabra){
    int i = 0;
    for(i=0; palabra != '\0'; i++){
        palabra++;
    };
    return i;
}