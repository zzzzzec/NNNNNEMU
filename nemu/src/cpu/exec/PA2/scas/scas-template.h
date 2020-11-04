#include "cpu/exec/template-start.h"

#define instr scas

static void do_execute () {
	DATA_TYPE src,dest;
	if (ops_decoded.is_operand_size_16)
	{
		src = swaddr_read (reg_w (R_AL),DATA_BYTE);
		dest = swaddr_read (reg_w (R_DI),DATA_BYTE);
	}
	else
	{
		src = swaddr_read (reg_l (R_EAX),DATA_BYTE);
		dest = swaddr_read (reg_l (R_EDI),DATA_BYTE);
	}/*dest-src?*/
    DATA_TYPE result = src - dest; 
    result =result;
    /*cpu.FLAG.ZF=!result;    
	int len = (DATA_BYTE << 3) - 1;
	cpu.FLAG.CF = dest < src;
	cpu.FLAG.SF= result >> len;
    int s1,s2;
	s1=dest>>len;
	s2=src>>len;
    cpu.FLAG.OF=(s1 != s2 && s2 == cpu.FLAG.SF) ;
	result ^= result >>4;
	result ^= result >>2;
	result ^= result >>1;
	cpu.FLAG.PF=!(result & 1);
	if (cpu.FLAG.DF == 0){
    REG (R_EDI) += DATA_BYTE;
    REG (R_ESI) += DATA_BYTE;
    }
	else {
    REG (R_EDI) -= DATA_BYTE;
    REG (R_ESI) -= DATA_BYTE;
    }
	print_asm("scas");*/
}

make_instr_helper(n);

#include "cpu/exec/template-end.h"