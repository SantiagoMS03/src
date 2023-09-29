#ifndef _VM_H
#define _VM_H
#include "reg.h"

// a size for the memory (2^16 bytes = 64k)
#define MEMORY_SIZE_IN_BYTES (65536 - BYTES_PER_WORD)
#define MEMORY_SIZE_IN_WORDS (MEMORY_SIZE_IN_BYTES / BYTES_PER_WORD)

#define MAX_STACK_HEIGHT 4096 //subject to change, might be wrong

typedef union mem_u
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

extern const void execute_instr(bin_instr_t instr , virtual_machine vm);

extern int main(int argc, char *argv[]);

extern int checkSafety(virtual_machine vm);

#endif