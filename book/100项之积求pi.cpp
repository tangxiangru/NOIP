#include  <stdio.h>

main()

{

    double term, result=1.0;

    int n;

    for (n=2; n<=100; n+=2)

    {

        term = ((double)(n * n)) / (( n - 1) * ( n + 1));

        result = result * term;

    }

    printf("result=%f\n", 2 * result);

}
