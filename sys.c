#include <stdio.h>
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"
#include "vm.h"

void exit(virtual_machine vm) {
    bof_close(vm.bf); 
}


void pstr(virtual_machine vm) {
    vm.regi.GPR[V0] = printf("%s", &vm.mem.words[vm.regi.GPR[A0]]);
}


void pch(virtual_machine vm) {
    vm.regi.GPR[V0] = fputc(vm.regi.GPR[A0], stdout);
}


void rch(virtual_machine vm) {
    vm.regi.GPR[V0] = getc(stdin);
}


void stra(virtual_machine vm) {
    vm.is_tracing = 1;
}


void notr(virtual_machine vm) {
    vm.is_tracing = 0;
}

