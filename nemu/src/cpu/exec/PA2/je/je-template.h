#include "cpu/exec/template-start.h"

#define instr je

static void do_execute() {
    DATA_TYPE_S displacement = op_src ->val;
    if(cpu.FLAG.ZF == 1)
    {
           cpu.eip = cpu.eip + displacement;
    } 
    print_asm("jump 0x%08x ",cpu.eip);
}
make_instr_helper(i);

#include "cpu/exec/template-end.h"