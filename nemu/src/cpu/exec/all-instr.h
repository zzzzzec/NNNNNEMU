#include "prefix/prefix.h"

#include "data-mov/mov.h"
#include "data-mov/xchg.h"
#include "data-mov/movext.h"
#include "data-mov/cltd.h"
#include "data-mov/leave.h"
#include "PA2/call/call.h"
#include "PA2/push/push.h"
#include "PA2/test/test.h"
#include "PA2/je/je.h"
#include "PA2/cmp/cmp.h"
#include "PA2/pop/pop.h"
#include  "PA2/ret/ret.h"
#include  "PA2/adc/adc.h"
#include  "PA2/add/add.h"
#include  "PA2/sbb/sbb.h"
#include  "PA2/sub/sub.h"
#include "PA2/jmp/jmp.h"
#include "PA2/jle/jle.h"
#include "PA2/jne/jne.h"
#include "PA2/jl/jl.h"
#include "PA2/jg/jg.h"
#include "PA2/jbe/jbe.h"
#include "PA2/set/setb/setb.h"
#include "PA2/set/sete/sete.h"
#include "PA2/set/setne/setne.h"
#include "PA2/set/seto/seto.h"
#include "PA2/set/setp/setp.h"
#include "PA2/set/sets/sets.h"
#include "PA2/stos/stos.h"








#include "arith/dec.h"
#include "arith/inc.h"
#include "arith/neg.h"
#include "arith/imul.h"
#include "arith/mul.h"
#include "arith/idiv.h"
#include "arith/div.h"

#include "logic/and.h"
#include "logic/or.h"
#include "logic/not.h"
#include "logic/xor.h"
#include "logic/sar.h"
#include "logic/shl.h"
#include "logic/shr.h"
#include "logic/shrd.h"

#include "string/rep.h"

#include "misc/misc.h"

#include "special/special.h"
