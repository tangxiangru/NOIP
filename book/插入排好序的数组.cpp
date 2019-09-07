void addnum(int n)

    int i, option = 0;//option即要插入的位置,先默认为第一个位置
    int a[11] = { 1,3,5,7,9,11,13,15,17,19 };   //升序排序,这里是默认为已经排好序的数组

    printf("pre:");
    for (i = 0; i < 10; i++)
        printf("%3d", a[i]);//打印原数组顺序

    if (a[0] < a[1])
        while (n > a[option])//n为要插入的数
            //找到应该插入的位置
            option++;
    else
        //降序排序
        while (n < a[option])
            //找到应该插入的位置
            option++;

    //找到option,进行插入
    for (i = 10; i > option; i--) {//从插入位置开始重新排序
        a[i] = a[i - 1];
    }
    a[i] = n;

    printf("\nnow:");
    for (i = 0; i < 11; i++)
    {
        printf("%3d", a[i]);//这里循环的原数组长度加1是为了让大家看到结果的变化
    }
    printf("\n");
}

int main() {
    addnum(20);//插入20
    addnum(10);//插入10

}
