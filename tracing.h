#ifndef _TRACING_H
#define _TRACING_H

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

extern void print_registers();
extern void print_pc();
extern void print_pointers();
extern void print_stack_address();
extern void print_state();

#endif