/**
 * $Id: vectors.c,v 1.8 2007-05-29 00:40:27 heroine Exp $
 * @file vectors.c
 *  Initialize the instruction and opcode vectors.
 */

#include <libasm.h>

/**
 * Default handler for the disasm vector.
 * This handler does nothing, simply returning -1.
 * @param ins Pointer to instruction structure to fill
 * @param opcode Pointer to buffer to disassemble
 * @param len Length of the buffer to disassemble
 * @param proc Pointer to the processor structure
 * @return -1
 */
int	asm_fetch_default(asm_instr *ins, u_char *opcode, u_int len, 
			  asm_processor *proc)
{
  int	to_ret;
  LIBASM_PROFILE_FIN();
  if (proc->type == ASM_PROC_SPARC)
    to_ret = asm_sparc_illegal(ins, opcode, len, proc);
  else	
    to_ret = -1;
  LIBASM_PROFILE_FOUT(to_ret);
}

/**
 * Default handler for the operand vector
 * This handler does nothing, simply returning -1
 * @param ins Pointer to instruction structure to fill
 * @param opcode Pointer to buffer to disassemble
 * @param len Length of the buffer to disassemble
 * @param proc Pointer to the processor structure
 * @return -1
 *
 */

int	asm_operand_fetch_default(asm_operand *op, u_char *opcode, int otype,
				  asm_instr *ins)
{
  LIBASM_PROFILE_FIN();
  LIBASM_PROFILE_FOUT(-1);
}

/**
 * Intialize the disasm and operand vectors.
 * @param proc Pointer to the processor structure
 * @return 1 on success, 0 on error
 */
int	asm_init_vectors(asm_processor *proc)
{
  u_int	*dims;
  char	**dimstr;
  int	to_ret;
  
  LIBASM_PROFILE_IN();
  aspect_init();
  
  dims = malloc(4 * sizeof (u_int));
  if (!dims)
    {
      to_ret = 0;
      goto out;
    }
  dimstr = malloc(4 * sizeof (char *));
  if (!dimstr)
    {
      to_ret = 0;
      goto out;
    }
  
  dims[0] = LIBASM_VECTOR_ARCHNUM;
  dims[1] = 512;
  dims[2] = 64;
  dims[3] = 32;
  
  dimstr[0] = "MACHINE";
  dimstr[1] = "OPCODES";
  dimstr[2] = "SECONDARY OPCODES (SPARC ONLY)"; /* Should be 0 when unused */
  dimstr[3] = "FPOP OPCODE (SPARC ONLY)"; /* Should be 0 when unused */
  aspect_register_vector("disasm",
			 asm_fetch_default,
			 dims, dimstr, 4, ASPECT_TYPE_CADDR);
  dims = malloc(2 * sizeof (u_int));
  if (!dims)
    {
      to_ret = 0;
      goto out;
    }
  dimstr = malloc(4 * sizeof (char *));
  if (!dimstr)
    {
      to_ret = 0;
      goto out;
    }
  
  dims[0] = LIBASM_VECTOR_ARCHNUM;
  dims[1] = ASM_OTYPE_NUM;

  dimstr[0] = "MACHINE";
  dimstr[1] = "OPERAND";
  
  aspect_register_vector("operand",
			 asm_operand_fetch_default,
			 dims, dimstr, 2, ASPECT_TYPE_CADDR);

  config_add_item(ASM_CONFIG_ENDIAN_FLAG,
		  CONFIG_TYPE_INT,
		  CONFIG_MODE_RW,
		  (void *)ASM_CONFIG_LITTLE_ENDIAN);

  config_add_item(ASM_CONFIG_ATT_MARGIN_FLAG,
		  CONFIG_TYPE_INT,
		  CONFIG_MODE_RW,
		  (void *)ASM_CONFIG_ATT_MARGIN_DEFAULT);
 
 out:
  LIBASM_PROFILE_FOUT(to_ret);
}


