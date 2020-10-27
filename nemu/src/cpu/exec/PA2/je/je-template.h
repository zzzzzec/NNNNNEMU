#include "cpu/exec/template-start.h"

#define instr je

static void do_execute() {
    
    if(cpu.FLAG.ZF == 1)
    {
           cpu.eip = cpu.eip + op_src->val;
    } 
    print_asm("jump 0x%08x  %d",cpu.eip,op_src->val);
}

make_instr_helper(i);


#include "cpu/exec/template-end.h"