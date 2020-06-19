#include <gmp.h>
#include <stdio.h>


int main(){

    FILE *fp;
    mpz_t a, b, n;

    // init big numbers a, b, n
    mpz_init(a);
    mpz_init(b);
    mpz_init(n);
    
    // get the a value from the file a.data
    fp = fopen("a.data", "r");
    gmp_fscanf(fp,"%Zd\n", a);
    fclose(fp);

    // get the b value from the file b.data
    fp = fopen("b.data", "r");
    gmp_fscanf(fp,"%Zd\n", b);
    fclose(fp);

    // print numbers
    gmp_printf("a: %Zd\n", a);
    gmp_printf("b: %Zd\n", b);

    // multiply a and b
    mpz_mul(n, a, b);

    // print result
    gmp_printf("n: %Zd\n", n);

    //write n value to the file n.data
    fp = fopen("n.data", "w+");
    gmp_fprintf(fp,"n: %Zd\n", n);
    fclose(fp);

    return 0;
}