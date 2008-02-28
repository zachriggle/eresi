/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

int asm_mips_jalr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_JALR;
   asm_mips_operand_r(&ins->op[0], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   return 777;
}
