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

extern void add(int s, int t, int d);

extern void sub(int s, int t, int d);

extern void mult(int s, int t);

extern void div(int s, int t);

extern void mfhi(int d);

extern void mflo(int d);

extern void and(int s, int t, int d);

extern void bor(int s, int t, int d);

extern void nor(int s, int t, int d);

extern void xor(int s, int t, int d);

extern void sll(int t, int d, int h);

extern void srl(int t, int d, int h);

extern void jr(int s);



#endif
