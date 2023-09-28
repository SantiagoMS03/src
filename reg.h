#ifndef _REG_H
#define _REG_H


#include <stdio.h>
#include <stdbool.h>
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"


typedef struct {
    address_type GPR[32];
    address_type hi;
    address_type lo;
    address_type pc;
} registers;




#endif
