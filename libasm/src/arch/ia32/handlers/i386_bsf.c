/*
** $Id: i386_bsf.c,v 1.2 2007-04-13 06:56:34 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 <i386 func="i386_bsf" opcode"0xbc"/>
*/

int i386_bsf(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->len += 1;
  new->instr = ASM_BSF;
#if LIBASM_USE_OPERAND_VECTOR
  new->len += asm_operand_fetch(&new->op1, opcode, ASM_OTYPE_GENERAL, proc);
  new->len += asm_operand_fetch(&new->op2, opcode, ASM_OTYPE_ENCODED, proc);
#else
  new->op1.type = ASM_OTYPE_GENERAL;
  new->op2.type = ASM_OTYPE_ENCODED;
  operand_rv_rm2(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
