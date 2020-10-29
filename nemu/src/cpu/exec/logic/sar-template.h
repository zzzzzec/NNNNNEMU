#include "cpu/exec/template-start.h"

#define instr sar

static void do_execute () {
	DATA_TYPE src = op_src->val;
	DATA_TYPE_S dest = op_dest->val;

	uint8_t count = src & 0x1f;
	dest >>= count;
	OPERAND_W(op_dest, dest);
	DATA_TYPE_S result = dest;

	/* TODO: Update EFLAGS. */
    /*???????????*/
	cpu.FLAG.CF = 0;
	cpu.FLAG.OF =0;
	/*COMMON_SF_FLAG  MODULE  ===== START*/
int  len = (DATA_BYTE << 3)-1;
 cpu.FLAG.SF = result >> len;
 /*COMMON_SF_FLAG  MODULE  ===== END*/

	/*COMMON_ZF_FLAG  MODULE  ===== START*/
	 if (result == 0 )     cpu.FLAG.ZF =1;
    else                           cpu.FLAG.ZF = 0;
    /*COMMON_ZF_FLAG  MODULE  ===== END*/

	/*COMMON_PF_FLAG  MODULE  ===== START*/
	int count1 = 0;int i;             DATA_TYPE tem =result;
    for (  i = 0; i <8; i++)
    {
        tem = tem >> i;
       if((tem & 1)==1 )         count1 ++;
       tem = result;
    }
    if (count1%2==0)       cpu.FLAG.PF = 1;
    else                                cpu.FLAG.PF = 0;
/*COMMON_PF_FLAG  MODULE  ===== END*/
	
	/*panic("please implement me");*/

	print_asm_template2();
}

make_instr_helper(rm_1)
make_instr_helper(rm_cl)
make_instr_helper(rm_imm)

#include "cpu/exec/template-end.h"
