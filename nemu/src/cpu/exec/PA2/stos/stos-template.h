#include "cpu/exec/template-start.h"

#define instr stos

static void do_execute () {
   /*IIIIIIII386    IF byte type of instruction
   THEN
 (ES:DestReg) ← AL;
 IF DF = 0
 THEN DestReg ← DestReg + 1;  
 ELSE DestReg ← DestReg - 1;
 FI;*/
    if(ops_decoded.is_operand_size_16)
    {
          swaddr_write(reg_w(R_DI),2,reg_w(R_AX));      
          if (cpu.FLAG.DF==0)
          {
             reg_w (R_DI) += DATA_BYTE;
          }
          else
          {
               reg_w (R_DI) -= DATA_BYTE;
          }
    }
   else
   {
       swaddr_write(reg_w(R_EDI),4,reg_w(R_EAX));      
          if (cpu.FLAG.DF==0)
          {
             reg_w (R_DI) += DATA_BYTE;
          }
          else
          {
               reg_w (R_DI) -= DATA_BYTE;
          }
       
   }
}

make_instr_helper(n)

#include "cpu/exec/template-end.h"