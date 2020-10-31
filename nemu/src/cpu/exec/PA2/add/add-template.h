#include "cpu/exec/template-start.h"

#define instr add

static void do_execute() {
	DATA_TYPE result = op_dest->val + op_src->val;
    OPERAND_W(op_dest, result);
	int len = (DATA_BYTE << 3) - 1;
	int s1,s2;
	cpu.FLAG.CF=(result < op_dest->val);
	cpu.FLAG.SF=result >> len;
	s1=op_dest->val>>len;
	s2=op_src->val>>len;
    cpu.FLAG.OF=(s1 == s2 && s1 != cpu.FLAG.SF) ;
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
	print_asm_template2();
}
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)
#include "cpu/exec/template-end.h"