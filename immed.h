//https://docs.google.com/document/d/1ohnhCke5x50EayAiX12ILtaUIqgd402k976kyCdhpZw/edit


#ifndef _IMMED_H
#define _IMMED_H


#include <stdio.h>
#include "machine_types.h" // this
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"
#include "vm.c"
// memory is accessed as reg.mem, i didn't know how we were accessing memory, do we have that in our struct?
// work on sb, accessing least significant beat


// do you wanna take out the gpr, hi, lo, and put it into vm straight? instead of making a struct to group them up`
extern void addi(virtual_machine vm, int s, int t, immediate_type i);
extern void andi(virtual_machine vm, int s, int t, immediate_type i);
extern void bori(virtual_machine vm, int s, int t, immediate_type i);
extern void xori(virtual_machine vm, int s, int t, immediate_type i);
extern void beq(virtual_machine vm, int s, int t, immediate_type o);
extern void bne(virtual_machine vm, int s, int t, immediate_type o);
extern void bgez(virtual_machine vm, int s, int t, immediate_type o);
extern void bgtz(virtual_machine vm, int s, int t, immediate_type o);
extern void blez(virtual_machine vm, int s, int t, immediate_type o);
extern void bltz(virtual_machine vm, int s, int t, immediate_type o);
extern void lbu(virtual_machine vm, int b, int t  , immediate_type o);
extern void lw(virtual_machine vm, int b, int t  , immediate_type o);
extern void sb(virtual_machine vm, int b, int t  , immediate_type o);
extern void sw(virtual_machine vm, int b, int t  , immediate_type o);


#endif



