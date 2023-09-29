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

void print_registers(virtual_machine vm) {
    for (int i = 0; i < 32; i++) {
        printf("GPR[%s]: %u\t%c", regname_get(i), vm.regi.GPR[i], (i % 6 == 5) * '\n');
    }
}
void print_pc(virtual_machine vm);
void print_pointers(virtual_machine vm);
void print_stack_address(virtual_machine vm);
void print_state(virtual_machine vm) {
    print_pc(vm);
    print_registers(vm);
    print_pointers(vm);
    print_stack_address(vm);
}
