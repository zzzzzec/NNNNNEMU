#include "cpu/exec/template-start.h"

#define instr pop

static void do_execute() {
int reg = ops_decoded.opcode & 0x7;
DATA_TYPE data=swaddr_read(cpu.esp,DATA_BYTE);
cpu.gpr[check_reg_index(reg)]._32 = data; 
cpu.esp = cpu.esp +4;
switch (reg)
   {
   case  0:
       print_asm("push %%eax ");
       break; 
      case  1:
       print_asm("push %%ecx ");
       break; 
          case  2:
       print_asm("push %%edx ");
       break; 
          case  3:
       print_asm("push %%ebx ");
       break; 
          case  4:
       print_asm("push %%esp ");
       break; 
          case  5:
       print_asm("push %%ebp ");
       break; 
          case  6:
       print_asm("push %%esi ");
       break; 
          case  7:
       print_asm("push %%edi ");
       break; 
   default:
       break;
   }

}

make_instr_helper(r);
#include "cpu/exec/template-end.h"