#include<stdio.h>
#include<string.h>
int main()
{
FILE *file;
FILE *file1;
char x1,x2,x3,x4,x0;
int store[4][6] =
{{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
int total_price[6]={0,0,0,0};
int no_of_products=8;
int arr[no_of_products][2];
for(int i=0;i<no_of_products;i++)
{
for(int j=0;j<2;j++)
{
arr[i][j]=0;
}
}
for(int i=1;i<=no_of_products;i++)
{
int unit_price;
printf("dear user enter the unit price corresponing to %d th product: ",i);
scanf("%d",&unit_price);
arr[i-1][0]=i;
arr[i-1][1]=unit_price;
}
file=fopen("sales.txt","r");
if(file==NULL){
printf("This file is not opened");
return 0;
}
int i=7;
do{
x1=fgetc(file);
x0=fgetc(file);
x2=fgetc(file);
x0=fgetc(file);
x3=fgetc(file);
x0=fgetc(file);
x4=fgetc(file);
x0=fgetc(file);
int x5=x1-'0';
int x6=x2-'0';
int x7=x3-'0';
int x8=x4-'0';
store[x5-1][x6-1]+=x8*arr[x7-1][1];
total_price[x5-1]+=x8*arr[x7-1][1];
}while(i--);
file1=fopen("output.txt","w");
if(file1==NULL)
{
printf("file not opened");
return 0;
}
else
{
for(int i=0;i<4;i++)
{
fprintf(file1,"Region %d\n",(i+1));
for(int j=0;j<6;j++)
{
fprintf(file1,"The salesman %d Rs%d/\n",(j+1),store[i][j]);
}
fprintf(file1,"Total sale at Region %d is%d \n",(i+1),total_price[i]);
}
}
return 0;
}
