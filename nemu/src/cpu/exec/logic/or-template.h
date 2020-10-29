#include "cpu/exec/template-start.h"

#define instr or

static void do_execute () {
	DATA_TYPE result = op_dest->val | op_src->val;
	OPERAND_W(op_dest, result);

	/* TODO: Update EFLAGS. */
	/*panic("please implement me");*/
		/*COMMON_ZF_FLAG  MODULE  ===== START*/
	 if (result == 0 )     cpu.FLAG.ZF =1;
    else                           cpu.FLAG.ZF = 0;
    /*COMMON_ZF_FLAG  MODULE  ===== END*/

	/*COMMON_PF_FLAG  MODULE  ===== START*/
	int count = 0;int i;             DATA_TYPE tem =result;
    for (  i = 0; i <8; i++)
    {
        tem = tem >> i;
       if((tem & 1)==1 )         count ++;
       tem = result;
    }
    if (count%2==0)       cpu.FLAG.PF = 1;
    else                                cpu.FLAG.PF = 0;
/*COMMON_PF_FLAG  MODULE  ===== END*/
	print_asm_template2();
}

make_instr_helper(i2a)
make_instr_helper(i2rm)
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#include "cpu/exec/template-end.h"
