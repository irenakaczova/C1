#include<stdio.h>

int main()
{
	int n;//pocet obracenych trojuhelniku,ktere maji postupne vysku n,n−1,... , 1 radku
	int j,k,l,m,o;

	printf("Zadejte n: ");
	scanf("%d",&n);

    if(n<0){
        printf ("Zadane n je zaporne cislo!");}
    else
    for (j=2*n-1;j>0;j--){//cyklus pro trojuhelniky
        for (k=j;k>0;k--){//cyklus pro nove radky
            for (m=(j-k)/2;m>1;m--){//mezery v trojuhelniku
                printf("  ");}
            for (l=k;l>0;l--){//*
			printf("* ");}
        printf("\n");
		k--;
		for (o=((2*n-1)-j)/2;o>=0;o--)//mezery pred trojuhlenikem
            printf("  ");}
    j--;}
return 0;
}
