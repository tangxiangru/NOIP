#include<cstdio>
#include<cstring>
const int NAMELEN = 10;
char month1[19][NAMELEN] ={
	"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax",
	"zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"
};
char month2[20][NAMELEN] ={
	"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk",
	"ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"
};
int main(){
	int kase, i, m;
	scanf("%d",&kase);
	printf("%d\n",kase);
	while(kase--){
		int day,year,dates;
		char month[NAMELEN];
		scanf("%d.%s%d",&day,month,&year);
		for(m = 0; m < 19; m++)
			if(!strcmp(month1[m],month)) break;
		dates = year * 365 + m*20 +day;
		printf("%d %s %d\n",1+dates % 13, month2[dates%20],dates/260);	
	}
	return 0;
}
