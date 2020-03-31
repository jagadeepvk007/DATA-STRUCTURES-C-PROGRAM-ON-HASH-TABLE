#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
char name[30];
char id[10];
char address[50];
char mail_id[20];
char mobile[13];
}employee_list;
const int max_size=100;
void build_htable(employee_list *,int *);
void hash_search(employee_list *,int);
int hash_key( char *, int);
int collision(int,int);
void main()
{
employee_list erecord[100];
int last;
last=max_size-1;
build_htable(erecord, &last);
hash_search(erecord,last);
}
void build_htable(employee_list *erecord,int * last)
{
FILE *fp;
employee_list list;
int loc, cntcoli, end,i;
fp=fopen("emp.txt","r");
if(!fp)
{
printf("unable to open the file emp.txt\n");
exit(0);
}
for(i=0;i<=*last;i++)
{
erecord[i].id[0]='\0';
}
while(!feof(fp))
{
fscanf(fp,"%[^;]%*c %[^;]%*c %[^;]%*c %[^;]%*c %[^;]%*c",list.name,list.id,list.address,list.mail_id,list.mobile);

loc=hashkey(list.id,*last);
if(erecord[loc].id[0]!='\0')
{
end=*last;
cntcoli=0;
while(erecord[loc].id[0]!='\0' && cntcoli++<=*last)
{
loc=collision(*last,loc);
}
if(erecord[loc].id[0]!='\0')
{
printf("List is full\n");
return;
}
}
erecord[loc]=list;
}
return;
}
int hashkey(char *key, int last)
{
int add, klen,i;
klen = strlen(key);
add =0;
for(i=0;i<klen;i++)
{
if(key[i]!=' ')
add=add+key[i];

}
return (add%last+1);
}
int collision(int last,int loc)
{
return loc<last ? ++loc:0;
}
void hash_search(employee_list *erecord, int last)
{
char id[30];
char more;
int loc, max_search, cntcoli,i;
printf("enter the id\n");
scanf("%s",id);
loc=hashkey(id,last);
if(strcmp(id,erecord[loc].id)!=0)
{
max_search=last;
cntcoli=0;
while(strcmp(id,erecord[loc].id)!=0 && cntcoli++<=max_search)
loc=collision(last,loc);

}
if(strcmp(id,erecord[loc].id)==0)
printf("%s%s%s%s%s",erecord[loc].name,erecord[loc].id,erecord[loc].address,erecord[loc].mail_id,erecord[loc].mobile);

else
printf("%s not found",id);

}