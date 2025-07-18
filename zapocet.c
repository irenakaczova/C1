#include<stdio.h>

int main(){

    char retezec[]="3/2*1000";//retezec,kt.obsahuje matemat.vyraz s celymi cislami a zakl.aritm.operacemi,ve spravnem formatu
    char i,j,k,l,d;//pomocne promenne
    float a,b;
    float vysledek=0;//promenna pro vysledek
    for(k=0;retezec[k]!='\0';k++){//cyklus,ktery postupne projde kazdy znak retezce az do posledneho znaku a vykona prislusne prikazy
        for(i=0;retezec[i]!='\0';i++){//cyklus,ktery prohlizi vsechny znaky retezce..
            if((retezec[i]=='*')||(retezec[i]=='/')){//pokud narazi na znak * nebo /..
                a=0;b=0;d=1;
                for(l=i-1;l>=0;l--){//ve vnitrnim cyklu prevede hodnotu predoslych znaku na cislo
                    if((retezec[l]>='0')&&(retezec[l]<='9')){//dokud jsou prohlizene znaky cisla
                        a=(retezec[l]-'0')*d+a;//vypocita cislo a ulozi do promenne a
                        d=d*10;
                        retezec[l]='x';}//uz zaznamenane znaky odlisi znakem x
                    else if(retezec[l]=='x'){//ak je splnena podmienka pri opakovanom * nebo / ulozime do promenne a predosly vysledek
                            a=vysledek;}
                    else break;}
                d=1;
                for(j=i+1;retezec[j]!='\0';j++){//v dalsim cyklu analogicky provede pro nasledujici znaky vypocet na cisla
                    if((retezec[j]>='0')&&(retezec[j]<='9')){
                        b=b*d+retezec[j]-'0';//ulozi do promenne b
                        d=10;
                        retezec[j]='x';}
                    else if(retezec[j]=='x'){//ak je splnena podmienka pri opakovanom * nebo / ulozime do b predosly vysledek
                            b=vysledek;}
                    else break;}
                switch(retezec[i]){//podle znamenka operace provede vypocet
                    case'/':
                        vysledek=a/b;//ulozi do promenne vysledek operace /
                        retezec[i]='x';//uz zaznamenanou operaci odlisi znakem x
                        break;
                    case'*':
                        vysledek=a*b;//analogicky jako pro operaci /
                        retezec[i]='x';
                        break;}}}
        a=0;b=0;d=1;
        for(i=k;retezec[i]!='\0';i++){//zjisti zda je znak retezce cislo..
            if((retezec[i]>='0')&&(retezec[i]<='9')){//jestli ano,uz znamym algoritmem provede vypocet
               a=a*d+retezec[i]-'0';
               d=10;
               retezec[i]='x';}
            else if(retezec[i]=='x'){
                    a=vysledek;}
            else break;}
        d=1;
        for(j=i+1;retezec[j]!='\0';j++){//to same pro b
            if((retezec[j]>='0')&&(retezec[j]<='9')){
               b=b*d+retezec[j]-'0';
               d=10;
               retezec[j]='x';}
            else if(retezec[j]=='x'){
                    b=vysledek;}
            else break;}
        switch(retezec[i]){//provede vypocet pro + nebo -
            case'+':
                vysledek=a+b;
                retezec[i]='x';
                break;
            case'-':
                vysledek=a-b;
                retezec[i]='x';
                break;}}
        printf("%f",vysledek);

    return 0;}
