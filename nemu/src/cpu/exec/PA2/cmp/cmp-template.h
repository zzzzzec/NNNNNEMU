#include "cpu/exec/template-start.h"

#define instr cmp
static void do_execute() {
     DATA_TYPE result = (op_dest->val) - (op_src->val);
     cpu.FLAG.CF= (op_dest->val) <  (op_src->val);
    int  len = (DATA_BYTE << 3)-1;
     if (result == 0 )
     {
          cpu.FLAG.ZF =1;
    }
    else
    {
        cpu.FLAG.ZF = 0;
    }
    cpu.FLAG.SF = result >> len;
    int count = 0;/*set PF*/
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
DATA_TYPE_S s1 = op_src->val;/*set of*/
DATA_TYPE_S s2 = op_dest->val;
if(s1<0&&s2>0&&s1-s2>0)
{
    cpu.FLAG.OF =1;
}
else
{
     cpu.FLAG.OF = 0;
}
cpu.FLAG.SF = (cpu.FLAG.SF) ^ (cpu.FLAG.OF) ;/*adjust sf */
print_asm_template2();
}
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)


#include "cpu/exec/template-end.h"