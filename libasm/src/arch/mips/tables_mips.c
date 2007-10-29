/**
 *
 *
 *
 *  Manuel Martin - 2007 
 */

#include <libasm.h>

struct e_mips_instr e_mips_instrs [] = {
  {"add"      ,ASM_MIPS_ADD       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_ADD       ,0x0}, 
  {"addi"     ,ASM_MIPS_ADDI      ,MIPS_OPCODE_ADDI          ,0x0                   ,0x0},
  {"addiu"    ,ASM_MIPS_ADDIU     ,MIPS_OPCODE_ADDIU         ,0x0                   ,0x0},
  {"addu"     ,ASM_MIPS_ADDU      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_ADDU      ,0x0},
  {"clo"      ,ASM_MIPS_CLO       ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_CLO       ,0x0},
  {"clz"      ,ASM_MIPS_CLZ       ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_CLZ       ,0x0},
  {"div"      ,ASM_MIPS_DIV       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_DIV       ,0x0},
  {"divu"     ,ASM_MIPS_DIVU      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_DIVU      ,0x0},
  {"madd"     ,ASM_MIPS_MADD      ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_MADD      ,0x0},
  {"maddu"    ,ASM_MIPS_MADDU     ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_MADDU     ,0x0},
  {"msub"     ,ASM_MIPS_MSUB      ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_MSUB      ,0x0},
  {"msubu"    ,ASM_MIPS_MSUBU     ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_MSUBU     ,0x0},
  {"mul"      ,ASM_MIPS_MUL       ,MIPS_OPCODE_SPECIAL2      ,MIPS_OPCODE_MUL       ,0x0},
  {"mult"     ,ASM_MIPS_MULT      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MULT      ,0x0},
  {"multu"    ,ASM_MIPS_MULTU     ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MULTU     ,0x0},
  {"seb"      ,ASM_MIPS_SEB       ,MIPS_OPCODE_SPECIAL3      ,MIPS_OPCODE_BSHFL     ,MIPS_OPCODE_SEB},
  {"seh"      ,ASM_MIPS_SEH       ,MIPS_OPCODE_SPECIAL3      ,MIPS_OPCODE_BSHFL     ,MIPS_OPCODE_SEH},
  {"slt"      ,ASM_MIPS_SLT       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLT       ,0x0},
  {"slti"     ,ASM_MIPS_SLTI      ,MIPS_OPCODE_SLTI          ,0x0                   ,0x0},
  {"sltiu"    ,ASM_MIPS_SLTIU     ,MIPS_OPCODE_SLTIU         ,0x0                   ,0x0},
  {"sltu"     ,ASM_MIPS_SLTU      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLTU      ,0x0},
  {"sub"      ,ASM_MIPS_SUB       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SUB       ,0x0},
  {"subu"     ,ASM_MIPS_SUBU      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SUBU      ,0x0},
  {"b"        ,ASM_MIPS_B         ,MIPS_OPCODE_BEQ           ,0x0                   ,0x0},
  {"bal"      ,ASM_MIPS_BAL       ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BGEZAL    ,0x0},
  {"beq"      ,ASM_MIPS_BEQ       ,MIPS_OPCODE_BEQ           ,0x0                   ,0x0},
  {"bgez"     ,ASM_MIPS_BGEZ      ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BGEZ      ,0x0},
  {"bgezal"   ,ASM_MIPS_BGEZAL    ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BGEZAL    ,0x0},
  {"bgtz"     ,ASM_MIPS_BGTZ      ,MIPS_OPCODE_BGTZ          ,0x0                   ,0x0},
  {"blez"     ,ASM_MIPS_BLEZ      ,MIPS_OPCODE_BLEZ          ,0x0                   ,0x0},
  {"bltz"     ,ASM_MIPS_BLTZ      ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BLTZ      ,0x0},
  {"bltzal"   ,ASM_MIPS_BLTZAL    ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BLTZAL    ,0x0},
  {"bne"      ,ASM_MIPS_BNE       ,MIPS_OPCODE_BNE           ,0x0                   ,0x0},
  {"j"        ,ASM_MIPS_J         ,MIPS_OPCODE_J             ,0x0                   ,0x0},
  {"jal"      ,ASM_MIPS_JAL       ,MIPS_OPCODE_JAL           ,0x0                   ,0x0},
  {"jalr"     ,ASM_MIPS_JALR      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_JALR      ,0x0},
  {"jalr.hb"  ,ASM_MIPS_JALR_HB   ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_JALR      ,0x0},
  {"jr"       ,ASM_MIPS_JR        ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_JR        ,0x0},
  {"jr.hb"    ,ASM_MIPS_JR_HB     ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_JR        ,0x0},
  {"beql"     ,ASM_MIPS_BEQL      ,MIPS_OPCODE_BEQL          ,0x0                   ,0x0},
  {"bgezall"  ,ASM_MIPS_BGEZALL   ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BGEZALL   ,0x0},
  {"bgezl"    ,ASM_MIPS_BGEZL     ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BGEZL     ,0x0},
  {"bgtzl"    ,ASM_MIPS_BGTZL     ,MIPS_OPCODE_BGTZL         ,0x0                   ,0x0},
  {"blezl"    ,ASM_MIPS_BLEZL     ,MIPS_OPCODE_BLEZL         ,0x0                   ,0x0},
  {"bltzall"  ,ASM_MIPS_BLTZALL   ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BLTZALL   ,0x0},
  {"bltzl"    ,ASM_MIPS_BLTZL     ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_BLTZL     ,0x0},
  {"bnel"     ,ASM_MIPS_BNEL      ,MIPS_OPCODE_BNEL          ,0x0                   ,0x0},
  {"ehb"      ,ASM_MIPS_EHB       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLL       ,MIPS_OPCODE_EHB},
  {"nop"      ,ASM_MIPS_NOP       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLL       ,MIPS_OPCODE_NOP},
  {"ssnop"    ,ASM_MIPS_SSNOP     ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLL       ,MIPS_OPCODE_SSNOP},
  {"lb"       ,ASM_MIPS_LB        ,MIPS_OPCODE_LB            ,0x0                   ,0x0},
  {"lbu"      ,ASM_MIPS_LBU       ,MIPS_OPCODE_LBU           ,0x0                   ,0x0},
  {"lh"       ,ASM_MIPS_LH        ,MIPS_OPCODE_LH            ,0x0                   ,0x0},
  {"lhu"      ,ASM_MIPS_LHU       ,MIPS_OPCODE_LHU           ,0x0                   ,0x0},
  {"ll"       ,ASM_MIPS_LL        ,MIPS_OPCODE_LL            ,0x0                   ,0x0},
  {"lw"       ,ASM_MIPS_LW        ,MIPS_OPCODE_LW            ,0x0                   ,0x0},
  {"lwl"      ,ASM_MIPS_LWL       ,MIPS_OPCODE_LWL           ,0x0                   ,0x0},
  {"lwr"      ,ASM_MIPS_LWR       ,MIPS_OPCODE_LWR           ,0x0                   ,0x0},
  {"pref"     ,ASM_MIPS_PREF      ,MIPS_OPCODE_PREF          ,0x0                   ,0x0},
  {"sb"       ,ASM_MIPS_SB        ,MIPS_OPCODE_SB            ,0x0                   ,0x0},
  {"sc"       ,ASM_MIPS_SC        ,MIPS_OPCODE_SC            ,0x0                   ,0x0},
  {"sh"       ,ASM_MIPS_SH        ,MIPS_OPCODE_SH            ,0x0                   ,0x0},
  {"sw"       ,ASM_MIPS_SW        ,MIPS_OPCODE_SW            ,0x0                   ,0x0},
  {"swl"      ,ASM_MIPS_SWL       ,MIPS_OPCODE_SWL           ,0x0                   ,0x0},
  {"swr"      ,ASM_MIPS_SWR       ,MIPS_OPCODE_SWR           ,0x0                   ,0x0},
  {"sync"     ,ASM_MIPS_SYNC      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SYNC      ,0x0},
  {"synci"    ,ASM_MIPS_SYNCI     ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_SYNCI     ,0x0},
  {"and"      ,ASM_MIPS_AND       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_AND       ,0x0},
  {"andi"     ,ASM_MIPS_ANDI      ,MIPS_OPCODE_ANDI          ,0x0                   ,0x0},
  {"lui"      ,ASM_MIPS_LUI       ,MIPS_OPCODE_LUI           ,0x0                   ,0x0},
  {"nor"      ,ASM_MIPS_NOR       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_NOR       ,0x0},
  {"or"       ,ASM_MIPS_OR        ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_OR        ,0x0},
  {"ori"      ,ASM_MIPS_ORI       ,MIPS_OPCODE_ORI           ,0x0                   ,0x0},
  {"xor"      ,ASM_MIPS_XOR       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_XOR       ,0x0},
  {"xori"     ,ASM_MIPS_XORI      ,MIPS_OPCODE_XORI          ,0x0                   ,0x0},
  {"ext"      ,ASM_MIPS_EXT       ,MIPS_OPCODE_SPECIAL3      ,MIPS_OPCODE_EXT       ,0x0},
  {"ins"      ,ASM_MIPS_INS       ,MIPS_OPCODE_SPECIAL3      ,MIPS_OPCODE_INS       ,0x0},
  {"wsbh"     ,ASM_MIPS_WSBH      ,MIPS_OPCODE_SPECIAL3      ,MIPS_OPCODE_BSHFL     ,MIPS_OPCODE_WSBH},
  {"mfhi"     ,ASM_MIPS_MFHI      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MFHI      ,0x0},
  {"mflo"     ,ASM_MIPS_MFLO      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MFLO      ,0x0},
  {"movf"     ,ASM_MIPS_MOVF      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MOVCI     ,MIPS_OPCODE_MOVF},
  {"movn"     ,ASM_MIPS_MOVN      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MOVN      ,0x0},
  {"movt"     ,ASM_MIPS_MOVT      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MOVCI     ,MIPS_OPCODE_MOVT},
  {"movz"     ,ASM_MIPS_MOVZ      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MOVZ      ,0x0},
  {"mthi"     ,ASM_MIPS_MTHI      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MTHI      ,0x0},
  {"mtlo"     ,ASM_MIPS_MTLO      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_MTLO      ,0x0},
  {"rdhwr"    ,ASM_MIPS_RDHWR     ,MIPS_OPCODE_SPECIAL3      ,MIPS_OPCODE_RDHWR     ,0x0},
  {"rotr"     ,ASM_MIPS_ROTR      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SRL       ,MIPS_OPCODE_ROTR},
  {"rotrv"    ,ASM_MIPS_ROTRV     ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SRLV      ,MIPS_OPCODE_ROTRV},
  {"sll"      ,ASM_MIPS_SLL       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLL       ,0x0},
  {"sllv"     ,ASM_MIPS_SLLV      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SLLV      ,0x0},
  {"sra"      ,ASM_MIPS_SRA       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SRA       ,0x0},
  {"srav"     ,ASM_MIPS_SRAV      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SRAV      ,0x0},
  {"srl"      ,ASM_MIPS_SRL       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SRL       ,MIPS_OPCODE_SRL},
  {"srlv"     ,ASM_MIPS_SRLV      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SRLV      ,MIPS_OPCODE_SRLV},
  {"break"    ,ASM_MIPS_BREAK     ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_BREAK     ,0x0},
  {"syscall"  ,ASM_MIPS_SYSCALL   ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_SYSCALL   ,0x0},
  {"teq"      ,ASM_MIPS_TEQ       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_TEQ       ,0x0},
  {"teqi"     ,ASM_MIPS_TEQI      ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_TEQI      ,0x0},
  {"tge"      ,ASM_MIPS_TGE       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_TGE       ,0x0},
  {"tgei"     ,ASM_MIPS_TGEI      ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_TGEI      ,0x0},
  {"tgeiu"    ,ASM_MIPS_TGEIU     ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_TGEIU     ,0x0},
  {"tgeu"     ,ASM_MIPS_TGEU      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_TGEU      ,0x0},
  {"tlt"      ,ASM_MIPS_TLT       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_TLT       ,0x0},
  {"tlti"     ,ASM_MIPS_TLTI      ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_TLTI      ,0x0},
  {"tltiu"    ,ASM_MIPS_TLTIU     ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_TLTIU     ,0x0},
  {"tltu"     ,ASM_MIPS_TLTU      ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_TLTU      ,0x0},
  {"tne"      ,ASM_MIPS_TNE       ,MIPS_OPCODE_SPECIAL       ,MIPS_OPCODE_TNE       ,0x0},
  {"tnei"     ,ASM_MIPS_TNEI      ,MIPS_OPCODE_REGIMM        ,MIPS_OPCODE_TNEI      ,0x0},

  /*TODO
   * - FPU insns
   * - COP2 insns
   * - privileged insns
   */
  
  /**
   * @todo Replace -1 by NULL to avoid compiler warning.
   */
  {-1,-1,-1,-1,-1}
};

struct e_mips_register e_mips_registers [] = {
   {"zero","r0",ASM_MIPS_REG_ZERO},
   {"at","r1",ASM_MIPS_REG_AT},
   {"v0","r2",ASM_MIPS_REG_V0},
   {"v1","r3",ASM_MIPS_REG_V1},
   {"a0","r4",ASM_MIPS_REG_A0},
   {"a1","r5",ASM_MIPS_REG_A1},
   {"a2","r6",ASM_MIPS_REG_A2},
   {"a3","r7",ASM_MIPS_REG_A3},
   {"t0","r8",ASM_MIPS_REG_T0},
   {"t1","r9",ASM_MIPS_REG_T1},
   {"t2","r10",ASM_MIPS_REG_T2},
   {"t3","r11",ASM_MIPS_REG_T3},
   {"t4","r12",ASM_MIPS_REG_T4},
   {"t5","r13",ASM_MIPS_REG_T5},
   {"t6","r14",ASM_MIPS_REG_T6},
   {"t7","r15",ASM_MIPS_REG_T7},
   {"s0","r16",ASM_MIPS_REG_S0},
   {"s1","r17",ASM_MIPS_REG_S1},
   {"s2","r18",ASM_MIPS_REG_S2},
   {"s3","r19",ASM_MIPS_REG_S3},
   {"s4","r20",ASM_MIPS_REG_S4},
   {"s5","r21",ASM_MIPS_REG_S5},
   {"s6","r22",ASM_MIPS_REG_S6},
   {"s7","r23",ASM_MIPS_REG_S7},
   {"t8","r24",ASM_MIPS_REG_T8},
   {"t9","r25",ASM_MIPS_REG_T9},
   {"k0","r26",ASM_MIPS_REG_K0},
   {"k1","r27",ASM_MIPS_REG_K1},
   {"gp","r28",ASM_MIPS_REG_GP},
   {"sp","r29",ASM_MIPS_REG_SP},
   {"fp","r30",ASM_MIPS_REG_FP},
   {"ra","r31",ASM_MIPS_REG_RA},
   {-1,-1,-1}
};

