#include <stdio.h>
#include "machine_types.h"
#include "bof.h"
#include "instruction.h"
#include "regname.h"
#include "utilities.h"
#include "file_location.h"


void scan_instructions(BOFHeader bfHeader, BOFFILE bf, memory mem);


void scan_words(BOFHeader bfHeader, BOFFILE bf, memory mem);

