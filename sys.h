#ifndef _SYS_H
#define _SYS_H
#include <stdio.h>
#include "vm.h"
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"
#include "reg.h"
#include "jump.h"
#include "immed.h"

extern void exit(virtual_machine vm);
extern void pstr(virtual_machine vm);
extern void pch(virtual_machine vm);
extern void rch(virtual_machine vm);
extern void stra(virtual_machine vm);
extern void notr(virtual_machine vm);



#endif
