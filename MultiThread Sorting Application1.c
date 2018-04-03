#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<pthread.h>
int a[30],b[15],c[15],d[30];
int sublistsize1,sublistsize2;
//function for first sublist
void sublist1(int a[])
{
sleep(1);
 int i,j,temp;
 for(i=0;i<sublistsize1;i++)
 {
  for(j=0;j<sublistsize1-i-1;j++)
  {
    if(a[j+1]<a[j])
    {
       temp=a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
    }
  }
 }

for(i=0;i<sublistsize1;i++)
{
  b[i]= a[i];
}
printf("First Sorted array: \n");
for(i=0;i<sublistsize1;i++)
{
  printf("%d \t",b[i]);
}
}

//function for second sublist
void sublist2(int a[])
{
sleep(2);
 int i,j,temp;
 for(i=0;i<sublistsize2;i++)
 {
  for(j=0;j<sublistsize2-i-1;j++)
  {
    if(a[j+1]<a[j])
    {
       temp= a[j];
       a[j]=a[j+1];
       a[j+1]=temp;
    }
  }
 }

printf("Second Sorted array: \n");
for(i=0;i<sublistsize2;i++)
{
  c[i]=a[i];
}
printf("Second Sorted array: \n");
for(i=0;i<sublistsize2;i++)
{
  printf("%d \t",c[i]);
}
}

//mergelist
void mergelist(int a[])
{
sleep(3);
 int i,k,j,temp;
 int totalSize = sublistsize1+sublistsize2;
 for(i=0;i<sublistsize1;i++)
 {
  a[i]=b[i];
 }
 k=sublistsize1;
 for(i=0;i<sublistsize2;i++)
 {
  a[k]=c[i];
 k++; 
 }
 printf("Merged Array: \n"); 
 for(i=0;i<totalSize;i++)
 {
  d[i] = a[i];
 }

 for(i=0;i<totalSize;i++)
 {
   for(j=0;j<totalSize-i-1;j++)
   { 
	if(d[j+1]<d[j])
   	{
     		temp=d[j];
		d[j]=d[j+1];
    		d[j+1]=temp;
	}
   }
 }
 printf("\nMerge SOrt: \n");
 for(i=0;i<totalSize;i++)
 {
   printf("%d \t",d[i]);
 }
}
//main
void main()
{
 int n,i,j=0,k=0;
 pthread_t th1,th2,th3;
 printf("Enter size of array:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 scanf("%d",&a[i]);
 }
for(i=0;i<n/2;i++)
{
 b[j]=a[i];
j++;
}
sublistsize1= j;
for(i=n/2;i<n;i++)
{
 c[k]=a[i];
 k++;
}
sublistsize2=k;
printf("First array: ");
for(i=0;i<n/2;i++)
{
printf("%d \n",b[i]);
}
printf("Second array: ");

for(i=0;i<n/2;i++)
{
printf("%d\n",c[i]);
}
pthread_create(&th1,NULL,sublist1,&b);
pthread_create(&th2,NULL,sublist2,&c);
pthread_create(&th3,NULL,mergelist,&d);
pthread_join(th1,NULL);
pthread_join(th2,NULL);
pthread_join(th3,NULL);
}
