#include "cpu/exec/template-start.h"

#define instr call

make_helper(concat(call_i_, SUFFIX))
{
    int len = concat(decode_i_, SUFFIX)(eip + 1);
    len = len +1;
    reg_l(R_ESP) -= DATA_BYTE;
    swaddr_write(reg_l(R_ESP), 4, cpu.eip);
    DATA_TYPE_S displacement = op_src->val;
     cpu.eip  = cpu.eip+len+displacement;
    print_asm("call 0x%x  %d %d  ", cpu.eip,len,displacement);
   
    
    return len;
}

/*
make_helper (concat(call_rm_, SUFFIX))
{
 printf("call_rm_ ");
}
*/

#include "cpu/exec/template-end.h"
