/**
 * @file op_sub_rmb_rb.c
 * @ingroup libasm/ia32/handlers
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sub_rmb_rb" opcode="0x28"/>
*/

int op_sub_rmb_rb(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SUB;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new);
#endif

  return (new->len);
}
