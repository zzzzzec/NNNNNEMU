#include "cpu/exec/template-start.h"

#define instr lea

static void do_execute(){
    DATA_TYPE_S  addr = op_dest->val;
    int reg = op_src ->reg;
    cpu.gpr[reg]._32 = addr;
}

make_instr_helper (r2rm);


#include "cpu/exec/template-end.h"