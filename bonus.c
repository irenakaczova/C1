#include<stdio.h>

char print_words(char text[],char words[]){
    int j,condition,l;
    for(int i=0;words[i]!='\0';i++){
        if(text[i]==words[i]){
            condition=1;
            continue;}
        else condition=0;break;}
    for(j=0;text[j]!=' '&&text[j]!='\0';j++){
        if(condition==1)
            printf("%c",text[j]);}
    j++; printf(" ");
    for(l=0;text[l]!='\0';l++){
        text[l]=text[j+l];}
    if(text[0]!='\0')
        print_words(text,words);}
int main(){
char text[]="bazen balon bonbon trouba";
char words[]="ba";
print_words(text,words);
printf("%s",text);
return 0;}
