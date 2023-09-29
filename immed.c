//https://docs.google.com/document/d/1ohnhCke5x50EayAiX12ILtaUIqgd402k976kyCdhpZw/edit?usp=sharing



#include <stdio.h>
#include "machine_types.h" // this
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"
#include "reg.h"
#include "vm.c"
// memory is accessed as regi.mem
// work on sb, accessing least significant beat


void addi(virtual_machine vm, int s, int t, immediate_type i) {
    vm.regi.GPR[t] = vm.regi.GPR[s] + i;
}
void andi(virtual_machine vm, int s, int t, immediate_type i) {
    vm.regi.GPR[t] = vm.regi.GPR[s] & machine_types_zeroExt(i);
}
void bori(virtual_machine vm, int s, int t, immediate_type i) {
    vm.regi.GPR[t] = vm.regi.GPR[s] | machine_types_zeroExt(i);
}
void xori(virtual_machine vm, int s, int t, immediate_type i) {
    vm.regi.GPR[t] = vm.regi.GPR[s] ^ machine_types_zeroExt(i);
}
void beq(virtual_machine vm, int s, int t, immediate_type o) {
    if (vm.regi.GPR[t] == vm.regi.GPR[s]) vm.regi.pc += machine_types_formOffset(o);
}
void bne(virtual_machine vm, int s, int t, immediate_type o) {
    if (vm.regi.GPR[t] != vm.regi.GPR[s]) vm.regi.pc += machine_types_formOffset(o);


}
void bgez(virtual_machine vm, int s, int t, immediate_type o) {
    if (vm.regi.GPR[s] >= 0) vm.regi.pc += machine_types_formOffset(o);
}
void bgtz(virtual_machine vm, int s, int t, immediate_type o) {
    if (vm.regi.GPR[s] > 0)  vm.regi.pc += machine_types_formOffset(o);
}
void blez(virtual_machine vm, int s, int t, immediate_type o) {
    if (vm.regi.GPR[s] <= 0) vm.regi.pc += machine_types_formOffset(o);
}
void bltz(virtual_machine vm, int s, int t, immediate_type o) {
    if (vm.regi.GPR[s] < 0)  vm.regi.pc += machine_types_formOffset(o);
}
void lbu(virtual_machine vm, int b, int t  , immediate_type o) {
    vm.regi.GPR[t] = machine_types_zeroExt(vm.mem.bytes[vm.regi.GPR[b] + machine_types_formOffset(o)]); //accessing bytes, might be wrong we'll see
}
void lw(virtual_machine vm, int b, int t  , immediate_type o) {
    vm.regi.GPR[t] = vm.mem.bytes[vm.regi.GPR[b] + machine_types_formOffset(o)]; //accessing bytes, might be wrong we'll see
}
void sb(virtual_machine vm, int b, int t  , immediate_type o) { // least significant bit
    vm.mem.bytes[vm.regi.GPR[b] + machine_types_formOffset(o)] = vm.regi.GPR[t]; //accessing bytes, might be wrong we'll see
}
void sw(virtual_machine vm, int b, int t  , immediate_type o) {
    vm.mem.bytes[vm.regi.GPR[b] + machine_types_formOffset(o)] = vm.regi.GPR[t]; //accessing bytes, might be wrong we'll see


}




