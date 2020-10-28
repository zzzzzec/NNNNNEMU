#include "cpu/exec/template-start.h"

#define instr call

make_helper(concat(call_i_, SUFFIX))
{
    int len = concat(decode_i_, SUFFIX)(eip + 1);
    len = len +1;
    reg_l(R_ESP) -= 4;
    swaddr_write(reg_l(R_ESP), 4, cpu.eip +len  );
    DATA_TYPE_S displacement = op_src->val;
    cpu.eip  = cpu.eip+displacement;
    print_asm_template1();
    return len;
}

/*
make_helper (concat(call_rm_, SUFFIX))
{
 printf("call_rm_ ");
}
*/

#include "cpu/exec/template-end.h"
