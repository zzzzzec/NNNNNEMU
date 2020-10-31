#include "cpu/exec/template-start.h"

#define instr push
static void do_execute()
{
    if (DATA_BYTE == 1)
    {
        op_src->val = (int8_t)op_src->val;
    }
    reg_l(R_ESP) -= 4;   /*minus the stack pointer*/ 
    swaddr_write(reg_l(R_ESP), 4, op_src->val);
  /* switch (op_src->reg)
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
   }*/
    
 print_asm_template1();
}

make_instr_helper(i)
#if DATA_BYTE == 2 || DATA_BYTE == 4
    make_instr_helper(r)
    make_instr_helper(rm)
#endif

#include "cpu/exec/template-end.h"
