/**
 * @file op_out_ref_ib_eax.c
 * $Id: op_out_ref_ib_eax.c,v 1.2 2007-04-13 06:56:34 heroine Exp $
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_out_ref_ib_eax" opcode="0xe7"/>
*/

int op_out_ref_ib_eax(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
    new->ptr_instr = opcode;
    new->instr = ASM_OUT;
    new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
    new->len += asm_operand_fetch(&new->op1, opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, proc);
    new->len += asm_operand_fetch(&new->op2, opcode, ASM_OTYPE_FIXED, proc);
    new->op2.content = ASM_OP_BASE;
    new->op2.regset = ASM_REGSET_R32;
    new->op2.base_reg = ASM_REG_EAX;
#else
    new->op1.type = ASM_OTYPE_IMMEDIATE;
    new->op1.content = ASM_OP_VALUE;
    new->op1.len = 1;
    new->op1.imm = 0;
    memcpy(&new->op1.imm, opcode + 1, 1);

    new->op2.type = ASM_OTYPE_FIXED;
    new->op2.content = ASM_OP_BASE;
    new->op2.regset = ASM_REGSET_R32;
    new->op2.base_reg = ASM_REG_EAX;
    new->len += new->op1.len;
#endif
    return (new->len);
}
