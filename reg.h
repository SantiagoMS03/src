#ifndef _REG_H
#define _REG_H


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
#include "sys.h"
#include "scanbof.h"

#define V0 2
#define A0 4

typedef struct {
    address_type GPR[32];
    address_type hi;
    address_type lo;
    address_type pc;
} registers;

extern void add(int s, int t, int d, virtual_machine vm);

extern void sub(int s, int t, int d, virtual_machine vm);

extern void mult(int s, int t, virtual_machine vm);

extern void div(int s, int t, virtual_machine vm);

extern void mfhi(int d, virtual_machine vm);

extern void mflo(int d, virtual_machine vm);

extern void and(int s, int t, int d, virtual_machine vm);

extern void bor(int s, int t, int d, virtual_machine vm);

extern void nor(int s, int t, int d, virtual_machine vm);

extern void xor(int s, int t, int d, virtual_machine vm);

extern void sll(int t, int d, int h, virtual_machine vm);

extern void srl(int t, int d, int h, virtual_machine vm);

extern void jr(int s, virtual_machine vm);



#endif
