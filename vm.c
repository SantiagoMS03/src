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
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"

// a size for the memory (2^16 bytes = 64k)
#define MEMORY_SIZE_IN_BYTES (65536 - BYTES_PER_WORD)
#define MEMORY_SIZE_IN_WORDS (MEMORY_SIZE_IN_BYTES / BYTES_PER_WORD)

static union mem_u
{
    byte_type bytes[MEMORY_SIZE_IN_BYTES];
    word_type words[MEMORY_SIZE_IN_WORDS];
    bin_instr_t instrs[MEMORY_SIZE_IN_WORDS];
} memory;

typedef struct {
    memory mem;
    registers regi;
    int is_tracing;
} virtual_machine;

const void execute_instr(bin_instr_t instr) {
    instr_type it = instruction_type(instr);
    int isSyscall = 0;

    switch (it) {
        case syscall_instr_type:
            switch(instr.syscall.code){
                case exit_sc:
                    exit(vm);
                    break;
                case print_str_sc:
                    pstr(vm);
                    break;
                case print_char_sc:
                    pch(vm);
                    break;
                case read_char_sc:
                    rch(vm);
                    break;
                case start_tracing_sc:
                    stra(vm);
                    break;
                case stop_tracing_sc:
                    notr(vm);
                    break;
            }
            break;      


        case reg_instr_type:
            switch (instr.reg.func) {
                case ADD_F:
                    add(instr.reg.rs, instr.reg.rt, instr.reg.rd, vm);
                    break;
                case SUB_F:
                    sub(instr.reg.rs, instr.reg.rt, instr.reg.rd, vm);
                    break;
                case MUL_F:
                    mult(instr.reg.rs, instr.reg.rt, vm);
                    break;
                case DIV_F:
                    div(instr.reg.rs, instr.reg.rt, vm);
                    break;
                case MFHI_F:
                    mfhi(instr.reg.rd, vm);
                    break;
                case MFLO_F:
                    mflo(instr.reg.rd, vm);
                    break;
                case AND_F:
                    and(instr.reg.rs, instr.reg.rt, instr.reg.rd, vm);
                    break;
                case BOR_F:
                    bor(instr.reg.rs, instr.reg.rt, instr.reg.rd, vm);
                    break;
                case NOR_F:
                    nor(instr.reg.rs, instr.reg.rt, instr.reg.rd, vm);
                    break;
                case XOR_F:
                    xor(instr.reg.rs, instr.reg.rt, instr.reg.rd, vm);
                    break;
                case SLL_F:
                    sll(instr.reg.rt, instr.reg.rd, instr.reg.shift, vm);
                    break;
                case SRL_F:
                    srl(instr.reg.rt, instr.reg.rd, instr.reg.shift, vm);
                    break;
                case JR_F:
                    jr(instr.reg.rs, vm)
                    break;
                case SYSCALL_F:
                    //should never reach here because it will check syscall before reg
                    break;
            }
            break;


        case immed_instr_type:
            switch (instr.immed.op) {
                case ADDI_O:
                    addi(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case ANDI_O:
                    andi(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BORI_O:
                    bori(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case XORI_O:
                    xori(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BEQ_O:
                    beq(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BNE_O:
                    bne(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BGEZ_O:
                    bgez(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BGTZ_O:
                    bgtz(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BLEZ_O:
                    blez(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case BLTZ_O:
                    bltz(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case LBU_O:
                    lbu(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case LW_O:
                    lw(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case SB_O:
                    sb(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                case SW_O:
                    sw(vm, instr.immed.rs, instr.immed.rt, instr.immed.immed);
                    break;
                default:
                    break;
            }
            break;

        case jump_instr_type:
            switch (instr.jump.op) {

            }
            break;

        default: //should never reach
            break;
    }


}

int main(int argc, char *argv[])
{
    registers reg;
    virtual_machine * vm = (virtual_machine *) calloc(1, sizeof(virtual_machine));
    //execute_instr(memory.instrs[i]);
    // Checking if filename was passed
    // #TODO Do we need to check? bof_read_open already checks
    //      whether bf.fileptr is null
    // if (argc > 1)
    // {
    //     BOFFILE bf = bof_read_open(argv[1]);
    // }
    // else
    // {
    //     return 1;
    // }
    BOFFILE bf = bof_read_open(argv[1]);
    BOFHeader bfHeader = bof_read_header(bf);

    scan_instructions(bfHeader, bf, mem);
    scan_words(mfHeader, bf, mem);

    // textlen / 4

    //i think this might be how we are supposed to save the registers?
    memory.words[index of register] =

    // Exit
    bof_close(bf);
    return 0;
}


int checkSafety(void) {
    if (PC % BYTES_PER_WORD != 0) {fprintf(stderr, "PC %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (GPR[$gp] % BYTES_PER_WORD != 0) {fprintf(stderr, "GPR[$gp] %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (GPR[$sp] % BYTES_PER_WORD != 0) {fprintf(stderr, "GPR[$sp] %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (GPR[$fp] % BYTES_PER_WORD != 0) {fprintf(stderr, "GPR[$fp] %% BYTES_PER_WORD = 0 IS FALSE"); return 1;}
    if (GPR[$gp] < 0) {fprintf(stderr, "0 ≤ GPR[$gp] IS FALSE"); return 1;}
    if (GPR[$gp] >= GPR[$sp]) {fprintf(stderr, "GPR[$gp] < GPR[$sp] IS FALSE"); return 1;}
    if (GPR[$sp] > GPR[$fp]) {fprintf(stderr, "GPR[$sp] ≤ GPR[$fp] IS FALSE"); return 1;}
    if (GPR[$fp] >= MAX_STACK_HEIGHT) {fprintf(stderr, "GPR[$fp] < MAX_STACK_HEIGHT IS FALSE"); return 1;}
    if (PC < 0) {fprintf(stderr, "0 ≤ PC IS FALSE"); return 1;}
    if (PC >= MEMORY_SIZE_IN_BYTES) {fprintf(stderr, "PC < MEMORY_SIZE_IN_BYTES IS FALSE"); return 1;}
    if (GPR[0] != 0) {fprintf(stderr, "GPR[0] = 0 IS FALSE"); return 1;}
    return 0;
}