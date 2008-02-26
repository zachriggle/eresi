/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

/* MULTU rs,rt */

int asm_mips_multu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_MULTU;
   asm_mips_operand_r(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   return 777;
}
