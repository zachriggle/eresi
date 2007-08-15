/**
 * @file op_sub_eax_iv.c
 * @ingroup handlers_ia32
** $Id: op_sub_eax_iv.c,v 1.6 2007-08-15 21:30:21 strauss Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sub_eax_iv" opcode="0x2d"/>
*/

int op_sub_eax_iv(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->instr = ASM_SUB;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

  new->len += asm_operand_fetch(&new->op1, opcode, ASM_OTYPE_FIXED, new);
  new->op1.content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op1.ptr = opcode;
  new->op1.len = 0;
  new->op1.regset = ASM_REGSET_R32;
  new->op1.baser = ASM_REG_EAX;
  new->len += asm_operand_fetch(&new->op2, opcode, ASM_OTYPE_IMMEDIATE, new);

  return (new->len);
}
