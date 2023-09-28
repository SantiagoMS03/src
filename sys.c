#include <stdio.h>
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"


void exit(virtual_machine vm) {
    bof_close(vm->bf_ptr);
}


void pstr(virtual_machine vm) {
    // to do
}


void pch(virtual_machine vm) {
    // to do
}


void rch(virtual_machine vm) {
    // to do
}


void stra(virtual_machine vm) {
    vm.is_tracing = 1;
}


void notr(virtual_machine vm) {
    vm.is_tracing = 0;
}

