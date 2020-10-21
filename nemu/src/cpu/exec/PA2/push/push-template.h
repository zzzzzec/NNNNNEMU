#include "cpu/exec/template-start.h"

#define  instr push

make_helper (concat(push_r_,SUFFIX))
{
    return 0;

}

#include "cpu/exec/template-end.h"
