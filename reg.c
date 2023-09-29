#include <stdio.h>
#include "vm.h"
#include "reg.h"
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"
#include "jump.h"
#include "immed.h"
#include "sys.h"
#include "scanbof.h"


void add(int s, int t, int d){
    vm.regi.GPR[d] = vm.regi.GPR[s] + vm.regi.GPR[t];
    return;
}


void sub(int s, int t, int d){
    vm.regi.GPR[d] = vm.regi.GPR[s] - vm.regi.GPR[t];
    return;
}


void mult(int s, int t){
    int res = vm.regi.GPR[s] * vm.regi.GPR[t];
    int temphi = (res >> 32);
    int templo = (res << 32) >> 32;
    vm.regi.hi = temphi;
    vm.regi.lo = templo;
    return;
}


void div(int s, int t)
{
    vm.regi.hi = vm.regi.GPR[s] % vm.regi.GPR[t];
    vm.regi.lo = vm.regi.GPR[s] / vm.regi.GPR[t];
    return;
}


void mfhi(int d)
{
    vm.regi.GPR[d] = vm.regi.hi;
    return;
}


void mflo(int d)
{
    vm.regi.GPR[d] = vm.regi.lo;
    return;
}


void and(int s, int t, int d)
{
    vm.regi.GPR[d] = vm.regi.GPR[s] & vm.regi.GPR[t];
    return;
}


void bor(int s, int t, int d)
{
    vm.regi.GPR[d] = vm.regi.GPR[s] | vm.regi.GPR[t];
    return;
}


void nor(int s, int t, int d)
{
    vm.regi.GPR[d] = ~(vm.regi.GPR[s] | vm.regi.GPR[t]);
    return;
}


void xor(int s, int t, int d)
{
    vm.regi.GPR[d] = vm.regi.GPR[s] ^ vm.regi.GPR[t];
    return;
}


void sll(int t, int d, int h)
{
    vm.regi.GPR[d] = vm.regi.GPR[t] << h;
    return;
}


void srl(int t, int d, int h)
{
    vm.regi.GPR[d] = vm.regi.GPR[t] >> h;
    return;
}


void jr(int s)
{
    vm.regi.pc = vm.regi.GPR[s];
    return;
}



















