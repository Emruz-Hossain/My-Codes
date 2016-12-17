#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
int n,m,i;
char s[10000];
scanf("%d",&n);
while(n--)
{

scanf("%s",&s);
m=strlen(s);
if((s[0]=='1' && m==1 )|| (s[0]=='4'&& m==1 )|| (s[0]=='7'&& s[1]=='8' && m==2 )) {
printf("+\n");
}
else if(s[m-2]=='3' && s[m-1]=='5') {
printf("-\n");

}
else if(s[0]=='9' && s[m-1]=='4') {
printf("*\n");

}
else if(s[0]=='1' && s[1]=='9' && s[2]=='0') {
printf("?\n");

}
}
return 0;

}
