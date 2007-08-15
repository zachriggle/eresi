/*
** $Id: op_sbb_rv_rmv.c,v 1.4 2007-08-15 21:30:20 strauss Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_rv_rmv" opcode="0x1b"/>
*/

int op_sbb_rv_rmv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->len += 1;
  new->instr = ASM_SBB;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

  new->len += asm_operand_fetch(&new->op1, opcode +1, ASM_OTYPE_GENERAL, new);
  new->len += asm_operand_fetch(&new->op2, opcode +1, ASM_OTYPE_ENCODED, new);

  return (new->len);
}
