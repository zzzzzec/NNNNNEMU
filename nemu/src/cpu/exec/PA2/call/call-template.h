#include "cpu/exec/template-start.h"

#define instr call

/*make_helper(concat(call_i_, SUFFIX))
{
    int len = concat(decode_i_, SUFFIX)(eip + 1);
    len = len +1;
    reg_l(R_ESP) -= 4;
    swaddr_write(reg_l(R_ESP), 4, cpu.eip +len  );
    DATA_TYPE_S displacement = op_src->val;
    cpu.eip  = cpu.eip+displacement;
    print_asm_template1();
    return len;
}*/

static void do_execute() {
    int len = concat(decode_i_, SUFFIX)(cpu.eip + 1);
    len = len +1;
     reg_l(R_ESP) -= 4;
    swaddr_write(reg_l(R_ESP), 4, cpu.eip+len  );
    DATA_TYPE_S displacement = op_src->val;
    cpu.eip  = cpu.eip+displacement;
    int addr;
    addr = cpu.eip + displacement;
    print_asm("call %0xd       %0xd      %0xd    %0xd",addr,DATA_BYTE,displacement,cpu.eip);
}

make_instr_helper(i);

#include "cpu/exec/template-end.h"
