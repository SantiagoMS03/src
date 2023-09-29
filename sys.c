#include <stdio.h>
#include "sys.h"
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
#include "scanbof.h"

void exit() {
    bof_close(vm.bf); 
}


void pstr() {
    vm.regi.GPR[V0] = printf("%s", &vm.mem.words[vm.regi.GPR[A0]]);
}


void pch() {
    vm.regi.GPR[V0] = fputc(vm.regi.GPR[A0], stdout);
}


void rch() {
    vm.regi.GPR[V0] = getc(stdin);
}


void stra() {
    vm.is_tracing = 1;
}


void notr() {
    vm.is_tracing = 0;
}

