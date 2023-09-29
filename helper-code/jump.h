#ifndef _JUMP_H
#define _JUMP_H

#include <stdio.h>
#include "vm.h"
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "utilities.h"
#include "file_location.h"
#include "reg.h"

//stuff goes here
extern void jmp(virtual_machine vm, address_type a);
extern void jal(virtual_machine vm, address_type a);

#endif