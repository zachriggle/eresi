/*
** $Id: op_les_rm_rmp.c,v 1.2 2007-04-13 06:56:34 heroine Exp $
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_les_rm_rmp" opcode="0xc4"/>
*/

int op_les_rm_rmp(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->ptr_instr = opcode;
    new->instr = ASM_LES;
    new->len += 1;
    #if LIBASM_USE_OPERAND_VECTOR
    #endif
  return (new->len);
}
