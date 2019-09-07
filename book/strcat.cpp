#include <stdio.h>
#include <assert.h>
 
char* MyStrcat(char *des, const char *src)
{
	assert(des != NULL && src != NULL); //断言两个字符串不为空
	char *temp = des;                   //指针temp指向des字符串内存地址
	while (*temp != '\0')               //如果temp指针没有遇见'\0'
		temp++;                         //temp++
	while ((*temp++ = *src++) != '\0'); //实现循环拷贝，当src为'\0'时结束
	 
	return des;                         //返回des值
}
 
int main()
{
	const int a = 100;
	a = 20;
	char str1[10] = "abc";
	char str2[] = "bcd";
	char* str3 = MyStrcat(str1, str2);
 
	printf("str1=%s\n", str1);
	printf("str2=%s\n", str2);
	printf("str3=%s\n", str3);
	return 0;
}
