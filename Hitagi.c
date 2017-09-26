#include<stdio.h>
int main() {
	int a[200],n,k,b[200],i,index[200],count;
	scanf("%d %d\n",&n,&k);
	i=0;
	for (; i<n;i++) {
		scanf("%d",&a[i]);
		if (a[i] == 0)
			index[count++]=i;
	}
	i=0;
	for (;i<k;i++) {
		scanf("%d",&b[i]);
	}
	i=0;
	int counter=0;
	for (; i<fac(k); i++) {
		a[index[counter]] = b[counter];

		counter++;
	}

}