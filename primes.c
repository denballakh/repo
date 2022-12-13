// Prints infinite sequence of prime numbers
main(){for(int a=1,b=0,c=1,d=0,e=0;;)c&&b>1?d=c,c=0:a*b?a--,e++:b?b--,d++:d*e?a++,c++,d--,e--,d||a!=c?0:printf("%5d",a):d?d--,b=1:(b=2,c--,!e?a=2:(c--,e--,a+=2));}



// Equivalent program:
// It is valid program in C++, to compile in C replace `@@@@x` with `x@=2` where `@` is `+` or `-`
/*
#include <stdio.h>
#include <stdint.h>

int main() {
    uint_fast16_t r1 = 1, r2 = 0, r3 = 1, r4 = 0, r5 = 0;
    for (;;)
        if (r3 && !~-~-r2) {                   --r3; ++r4;       } else
        if (r1 && r2)      {   --r1;                       ++r5; } else
        if (r2)            {           --r2;         ++r4;       } else
        if (r4 && r5)      {   ++r1;           ++r3; --r4; --r5;
                        if (!r4 && r1 == r3) printf("%5d ", r1); } else
        if (r4)            {           ++r2;         --r4;       } else
        if (r5)            { ++++r1; ++++r2; ----r3;       --r5; } else
        if (r1)            {   --r1;                             } else
                           { ++++r1; ++++r2;   --r3;             }
}
*/


// Another approach:
// short
// main(){for(int n=2;;n++){for(int i=2;i<n;)if(!(n%i++))goto X;printf("%8d",n);X:;}}
// fast
// main(){for(int n=3;;n+=2){for(int i=3;i*i<=n;i+=2)if(!(n%i))goto X;printf("%9d",n);X:;}}
// fast and less output
// main(){for(int n=3;;n+=2){for(int i=3;i*i<=n;i+=2)if(!(n%i))goto X;if((n&0xfff)==1)printf("%9x",n);X:;}}

