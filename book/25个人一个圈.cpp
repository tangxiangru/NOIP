#include <stdio.h>
#define n 25
typedef struct {
	int number;
	int nextp;
} person;

int main() {
	person link[n];
	int i,count,h;
	for(i=1; i<=n; i++) {
		if(i==n)	link[i].nextp=1;
		else
			link[i].nextp = i+1;
		link[i].number = i;
	}
	count = 0;
	h = n;
	printf("sequence that person leave the circle: \n");
	while(count<n-1) {
		i=0;
		while(i!=3) {
			h = link[h].nextp;
			if(link[h].number)	i++;
		}
		printf("%d ",link[h].number);
		link[h].number = 0;
		count++;
	}
	printf("\nThe last one is: ");
	for(i=1;i<=n;i++){
		if(link[i].number)	printf("%d",link[i].number);
	}
	return 0;
}

