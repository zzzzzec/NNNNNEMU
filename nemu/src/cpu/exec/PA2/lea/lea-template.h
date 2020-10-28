#include "cpu/exec/template-start.h"

#define instr lea

static void do_execute(){
    DATA_TYPE_S  addr = op_src->val;
    int reg = op_dest ->reg;
    print_asm("%d %d",addr,reg);






}

make_instr_helper (r2rm);


#include "cpu/exec/template-end.h"