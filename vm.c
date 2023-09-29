// immed.c
//https://docs.google.com/document/d/175BAN9kpIgs8tq_DU92apkC4ckzXIKiWEHEWZtHuEJE/edit?usp=sharing
// immed.h
//https://docs.google.com/document/d/1-8ikefjF6ctyuxTSkTN1q3g3C4E3GfpDgWUy7Dr4Pfk/edit?usp=sharing

// scanbof.c
//https://docs.google.com/document/d/1qpuNCDE0OXRpM7Ie26izrI_ty_RS96LOdEF0ToHla1I/edit?usp=sharing

// scanbof.h
//https://docs.google.com/document/d/14tX-8NS-lf23MmXEdtLYDf9dkw8Wr6nAXuJJsgCKjJI/edit?usp=sharing

//reg.h: //https://docs.google.com/document/d/1mNsu7Sk98riXXhGbOBK4Ucf6qZQvhJkIdwPpQVIlJyE/edit?usp=sharing

//reg.c:
//https://docs.google.com/document/d/1L3n7nLEPRSFZZ6rDwQZDllVJ7KR1z1w2NHjWksEgtO4/edit?usp=sharing  

// jump.c
//https://docs.google.com/document/d/1tBscFu8j-_ZcQItqXMoQAnf4KKcNe23DcZbzXE4_1dw/edit?usp=sharing

// jump.h
//https://docs.google.com/document/d/1mXWQWo5HkfYnjMyCj1RQweXuHVf_-rTUSaHOxWxjf4s/edit?usp=sharing

// sys.c
//https://docs.google.com/document/d/1tugw3R9-Me7lKjrmvLweAn5dtPWb4Au2O_2QlgS32LM/edit?usp=sharing

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

void initialize_vm(BOFHeader bfHeader)
{
    vm.regi.hi = 0;
    vm.regi.lo = 0;
    vm.regi.pc = bfHeader.text_start_address;

    for(int i = 0; i < 32; i++)
    {
        vm.regi.GPR[i] = 0;
    }

    vm.regi.GPR[GP] = bfHeader.data_start_address;
    vm.regi.GPR[SP] = bfHeader.stack_bottom_addr;
    vm.regi.GPR[FP] = bfHeader.stack_bottom_addr;
    return;
}

int execute_instr(bin_instr_t instr, virtual_machine vm) {
    instr_type it = instruction_type(instr);
    int isSyscall = 0;

    switch (it) {
        case syscall_instr_type:
            switch(instr.syscall.code){
                case exit_sc:
                    exit();
                    return 0;
                    break;
                case print_str_sc:
                    pstr();
                    break;
                case print_char_sc:
                    pch();
                    break;
                case read_char_sc:
                    rch();
                    break;
                case start_tracing_sc:
                    stra();
                    break;
                case stop_tracing_sc:
                    notr();
                    break;
            }
            break;      


        case reg_instr_type:
            switch (instr.reg.func) {
                case ADD_F:
                    add(instr.reg.rs, instr.reg.rt, instr.reg.rd);
                    break;
                case SUB_F:
                    sub(instr.reg.rs, instr.reg.rt, instr.reg.rd);
                    break;
                case MUL_F:
                    mult(instr.reg.rs, instr.reg.rt);
                    break;
                case DIV_F:
                    div(instr.reg.rs, instr.reg.rt);
                    break;
                case MFHI_F:
                    mfhi(instr.reg.rd);
                    break;
                case MFLO_F:
                    mflo(instr.reg.rd);
                    break;
                case AND_F:
                    and(instr.reg.rs, instr.reg.rt, instr.reg.rd);
                    break;
                case BOR_F:
                    bor(instr.reg.rs, instr.reg.rt, instr.reg.rd);
                    break;
                case NOR_F:
                    nor(instr.reg.rs, instr.reg.rt, instr.reg.rd);
                    break;
                case XOR_F:
                    xor(instr.reg.rs, instr.reg.rt, instr.reg.rd);
                    break;
                case SLL_F:
                    sll(instr.reg.rt, instr.reg.rd, instr.reg.shift);
                    break;
                case SRL_F:
                    srl(instr.reg.rt, instr.reg.rd, instr.reg.shift);
                    break;
                case JR_F:
                    jr(instr.reg.rs);
                    break;
                case SYSCALL_F:
                    //should never reach here because it will check syscall before reg
                    break;
                default:
                    break;
            }
            break;


        case immed_instr_type:
            switch (instr.immed.op) {
                case ADDI_O:
                    addi(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case ANDI_O:
                    andi(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BORI_O:
                    bori(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case XORI_O:
                    xori(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BEQ_O:
                    beq(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BNE_O:
                    bne(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BGEZ_O:
                    bgez(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BGTZ_O:
                    bgtz(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BLEZ_O:
                    blez(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BLTZ_O:
                    bltz(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case LBU_O:
                    lbu(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case LW_O:
                    lw(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case SB_O:
                    sb(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case SW_O:
                    sw(instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                default:
                    break;
            }
            break;

        case jump_instr_type:
            switch (instr.jump.op) {
                case JMP_O:
                    jmp(instr.jump.addr);
                    break;
                case JAL_O:
                    jal(instr.jump.addr);
                    break;
            }
            break;

        default: //should never reach
            break;
    }
    return 1;

}

virtual_machine vm;

int main(int argc, char *argv[])
{
    registers reg;

    int res = 0;

    BOFFILE bf = bof_read_open(argv[1]);
    BOFHeader bfHeader = bof_read_header(bf);
    vm.bf = bf;


    initialize_vm(bfHeader);
    printf("pc before increment: %d\n", vm.regi.pc);
    vm.regi.pc++;
    printf("pc after increment: %d\n", vm.regi.pc);
    return 0;


    scan_instructions(bfHeader, bf, vm.mem);
    scan_words(bfHeader, bf, vm.mem);

    while(res) {
        res = execute_instr(vm.mem.instrs[vm.regi.pc]);
        vm.regi.pc++;
        
    }

    // Exit
    bof_close(bf);
    return 0;
}


int checkSafety() {
    if (vm.regi.pc % BYTES_PER_WORD != 0) {fprintf(stderr, "PC %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (vm.regi.GPR[GP] % BYTES_PER_WORD != 0) {fprintf(stderr, "GPR[$gp] %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (vm.regi.GPR[SP] % BYTES_PER_WORD != 0) {fprintf(stderr, "GPR[$sp] %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (vm.regi.GPR[FP] % BYTES_PER_WORD != 0) {fprintf(stderr, "GPR[$fp] %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (vm.regi.GPR[GP] < 0) {fprintf(stderr, "0 ≤ GPR[$gp] IS FALSE"); return 1;}
    if (vm.regi.GPR[GP] >= vm.regi.GPR[SP]) {fprintf(stderr, "GPR[$gp] < GPR[$sp] IS FALSE"); return 1;}
    if (vm.regi.GPR[SP] > vm.regi.GPR[FP]) {fprintf(stderr, "GPR[$sp] ≤ GPR[$fp] IS FALSE"); return 1;}
    if (vm.regi.GPR[FP] >= MAX_STACK_HEIGHT) {fprintf(stderr, "GPR[$fp] < MAX_STACK_HEIGHT IS FALSE"); return 1;}
    if (vm.regi.pc < 0) {fprintf(stderr, "0 ≤ PC IS FALSE"); return 1;}
    if (vm.regi.pc >= MEMORY_SIZE_IN_BYTES) {fprintf(stderr, "PC < MEMORY_SIZE_IN_BYTES IS FALSE"); return 1;}
    if (vm.regi.GPR[0] != 0) {fprintf(stderr, "GPR[0] = 0 IS FALSE"); return 1;}
    return 0;
}
