#include "cpu/exec/template-start.h"

#define instr test
static void do_execute()
{
    cpu.FLAG.CF =0;
    cpu.FLAG.OF =0;
    DATA_TYPE  result = (op_src->val & op_dest->val);
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
    print_asm_template2();
}

make_instr_helper(rm2r);
#include "cpu/exec/template-end.h"
