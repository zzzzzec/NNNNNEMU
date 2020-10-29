#include "cpu/exec/template-start.h"

#define instr inc

static void do_execute () {
	DATA_TYPE result = op_src->val + 1;
	OPERAND_W(op_src, result);
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

/*COMMON_SF_FLAG  MODULE  ===== START*/
int  len = (DATA_BYTE << 3)-1;
 cpu.FLAG.SF = result >> len;
 /*COMMON_SF_FLAG  MODULE  ===== END*/

DATA_TYPE_S sresult1=op_src->val ;
DATA_TYPE_S sresult2 = sresult1 +1;
if (sresult1>0  && sresult2 <0 )       cpu.FLAG.OF = 1;
else                                                            cpu.FLAG.OF = 0;
cpu.FLAG.SF = (cpu.FLAG.SF) ^ (cpu.FLAG.OF) ;

	print_asm_template1();
}

make_instr_helper(rm)
#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(r)
#endif

#include "cpu/exec/template-end.h"
