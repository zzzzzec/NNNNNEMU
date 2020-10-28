#include "cpu/exec/template-start.h"

#define instr pop

static void do_execute() {
           DATA_TYPE result = swaddr_read(cpu.esp , DATA_BYTE);
            int reg = ops_decoded.opcode & 0x7;
            cpu.gpr[reg]._32 = result;
            REG(R_ESP)+=DATA_BYTE;
}

make_instr_helper(r);
#include "cpu/exec/template-end.h"