#include "cpu/exec/template-start.h"

#define  instr call
# if DATA_BYTE == 2 || DATA_BYTE == 4
make_helper (concat(call_i_, SUFFIX))
{
    int len =  concat(decode_i_, SUFFIX)(eip+1);
    len += 1;
    cpu.esp -= 4;
    swaddr_write(cpu.esp, 4, cpu.eip);
    cpu.eip += op_src->val;
    return len;
}
#endif
/*
make_helper (concat(call_rm_, SUFFIX))
{
 printf("call_rm_ ");
}
*/


#include "cpu/exec/template-end.h"
