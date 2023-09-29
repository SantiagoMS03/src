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

void print_pc();
void print_registers() {
    for (int i = 0; i < 32; i++) {
        printf("GPR[%s]: %u\t%c", regname_get(i), vm.regi.GPR[i], (i % 6 == 5) * '\n');
    }
}
void print_pointers();
void print_stack_address();
void print_state() {
    print_pc();
    print_registers();
    print_pointers();
    print_stack_address();
}
