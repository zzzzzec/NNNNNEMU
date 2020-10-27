#include "cpu/exec/template-start.h"

#define instr test
static void do_execute()
{
    cpu.FLAG.CF =0;
    cpu.FLAG.OF =0;
    DATA_TYPE  result = (op_src->val & op_src2->val);
    int  len = (DATA_BYTE << 3)-1;
    cpu.FLAG.SF = result >> len;
    if (result == 0)
    {
        cpu.FLAG.ZF = 1;
    }
    else
    {
        cpu.FLAG.ZF = 0;
    }
    int count = 0;
    DATA_TYPE tem =result;
    int i;
    for (  i = 0; i <8; i++)
    {
        tem = tem >> i;
       if((tem & 1)==1 )
       {
           count ++;
       }
       tem = result;
    }
    if (count%2==0)
    {
        cpu.FLAG.PF = 1;
    }
    else
    {
        cpu.FLAG.PF = 0;
    }
    print_asm("test");
}

make_instr_helper(rm);





#include "cpu/exec/template-end.h"
