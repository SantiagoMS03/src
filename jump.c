//https://docs.google.com/document/d/1ohnhCke5x50EayAiX12ILtaUIqgd402k976kyCdhpZw/edit

#include <stdio.h>
#include "machine_types.h" // this
#include "bof.h"
#include "jump.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"
#include "vm.h"

void jmp(virtual_machine vm, address_type a) {
    vm.regi.pc = machine_types_formAddress(vm.regi.pc, a);
    return;
}

void jal(virtual_machine vm, address_type a) {
    vm.regi.GPR[RA] = vm.regi.pc; 
    vm.regi.pc = machine_types_formAddress(vm.regi.pc, a);
    return;
}
