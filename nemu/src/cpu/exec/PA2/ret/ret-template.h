#include "cpu/exec/template-start.h"

#define instr ret

make_helper(concat(ret_n_,SUFFIX))
{
        /*cpu.eip = MEM_R(reg_l(R_ESP));*/
         DATA_TYPE result = swaddr_read(cpu.esp,DATA_BYTE);
         cpu.eip = result;
        reg_l (R_ESP) +=DATA_BYTE;
        print_asm("ret  0x%x %d",result,DATA_BYTE);
        return 1;
}

#include "cpu/exec/template-end.h"