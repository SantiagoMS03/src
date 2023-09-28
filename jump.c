//https://docs.google.com/document/d/1ohnhCke5x50EayAiX12ILtaUIqgd402k976kyCdhpZw/edit

#include <stdio.h>
#include "machine_types.h" // this
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"

void jmp(virtual_machine vm, address_type a) {
    vm.reg.pc = machine_types_formAddress(vm.reg.pc, a)
}

void jal(virtual_machine vm, address_type a) {
    vm.reg.GPR[RA] = vm.reg.pc; 
    vm.reg.pc = machine_types_formAddress(vm.reg.pc, a);
}
