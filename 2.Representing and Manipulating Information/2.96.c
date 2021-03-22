/*
Following the bit-level floating-point coding rules, implement the function with
the following prototype:

* Compute (int) f.
* If conversion causes overflow or f is NaN, return 0x80000000

int float_f2i(float_bits f);For floating-point number f , this function computes (int) f . Your function
should round toward zero. If f cannot be represented as an integer (e.g., it is out
of range, or it is NaN), then the function should return 0x80000000
*/
#include <stdio.h>
typedef unsigned float_bits;
float_bits float_f2i(float_bits f){
    unsigned exp=(f>>23) & 0xff ;
    unsigned frac=f&0x7fffff;
    unsigned s=f>>31;
    unsigned bias=127;
    if(exp==0xff && frac!=0){
        return 0x80000000;
    }

    exp=exp-127;
    unsigned k=23-exp;

    if(exp>32){
        return 0x80000000;
    }else if(exp>23){
        k=exp-23;
    }
    
    frac=frac >> k;
    return (1<<(exp))|frac;
}
int main()
{
    unsigned x=0x4A564504;
    printf("0x%x convert ",x);
    printf("0x%x\n",float_f2i(x));

    x=0x4640E400;
    printf("0x%x convert ",x);
    printf("0x%x\n",float_f2i(x));

}