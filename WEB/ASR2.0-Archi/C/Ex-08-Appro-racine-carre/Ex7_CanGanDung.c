#include <stdio.h>
#include <stdlib.h>

int main()
{

  float a;
  int j;
  float result;
  
  printf("Nhap a : ");
  scanf("%f",&a);
  printf("Nhap j : ");
  scanf("%d",&j);
  
  int i;
  for(i=1;i<=j;i++)
    {
      if(i==1)
	result=a;
      else
	result=(result+a/result)/2;
      printf("La %dère approximation de la racine carrée de %f est %f \n",i,a,result);
    }
}


  
