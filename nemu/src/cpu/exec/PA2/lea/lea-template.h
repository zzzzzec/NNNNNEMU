#include "cpu/exec/template-start.h"

#define instr lea

static void do_execute(){
    DATA_TYPE_S  addr = op_dest->val;
    int reg = op_src ->reg;
    print_asm("%d %d %d",addr,reg,DATA_BYTE);






}

make_instr_helper (r2rm);


#include "cpu/exec/template-end.h"