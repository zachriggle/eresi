/*
** $Id: op_dec_reg.c,v 1.2 2007-04-13 06:56:34 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_dec_reg" opcode="0x48"/>
  <instruction func="op_dec_reg" opcode="0x49"/>
  <instruction func="op_dec_reg" opcode="0x4a"/>
  <instruction func="op_dec_reg" opcode="0x4b"/>
  <instruction func="op_dec_reg" opcode="0x4c"/>
  <instruction func="op_dec_reg" opcode="0x4d"/>
  <instruction func="op_dec_reg" opcode="0x4e"/>
  <instruction func="op_dec_reg" opcode="0x4f"/>
*/

int op_dec_reg(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  struct s_modrm        *modrm;
  
  modrm = (struct s_modrm *) opcode;
  new->ptr_instr = opcode;
  new->instr = ASM_DEC;
  new->len += 1;
  
  #if LIBASM_USE_OPERAND_VECTOR
  new->len += asm_operand_fetch(&new->op1, opcode, ASM_OTYPE_OPMOD, proc);
  #else
  new->op1.type = ASM_OTYPE_OPMOD;
  new->op1.content = ASM_OP_BASE;
  new->op1.ptr = opcode;
  new->op1.regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  new->op1.base_reg = modrm->m;
#endif
    return (new->len);
}
