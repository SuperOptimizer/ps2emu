#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t u8;
typedef int8_t s8;
typedef uint16_t u16;
typedef int16_t s16;
typedef uint32_t u32;
typedef int32_t s32;
typedef uint64_t u64;
typedef int64_t s64;
typedef __uint128_t u128;
typedef __int128_t s128;
typedef float f32;

#define auto register __auto_type
#define cleanup(func) __attribute__((cleanup(func)))
#define overload __attribute__((overloadable))


#define __builtin_add_overflow_p(a,b,c) ({ \
__typeof__(c) __result; \
__builtin_add_overflow(a, b, &__result); \
})

#define __builtin_sub_overflow_p(a,b,c) ({ \
__typeof__(c) __result; \
__builtin_sub_overflow(a, b, &__result); \
})

#define __builtin_mul_overflow_p(a,b,c) ({ \
__typeof__(c) __result; \
__builtin_mul_overflow(a, b, &__result); \
})

#define add_overflows(a,b) __builtin_add_overflow_p(a, b, (__typeof__((a) + (b)))0)
#define sub_overflows(a,b) __builtin_sub_overflow_p(a, b, (__typeof__((a) - (b)))0)
#define mul_overflows(a,b) __builtin_mul_overflow_p(a, b, (__typeof__((a) * (b)))0)

#define add_overflow(a,b,dest) __builtin_add_overflow(a, b, dest)
#define sub_overflow(a,b,dest) __builtin_sub_overflow(a, b, dest)
#define mul_overflow(a,b,dest) __builtin_mul_overflow(a, b, dest)

typedef union gpr {
  u8 u8[16];
  s8 s8[16];
  u16 u16[8];
  s16 s16[8];
  u32 u32[4];
  s32 s32[4];
  u64 u64[2];
  s64 s64[2];
  u128 u128[1];
  s128 s128[1];
} gpr [[gnu::aligned(16)]];


typedef struct mips {
    union {
        gpr gpr[32];
        struct {
            gpr zero, at, v0, v1, a0, a1, a2, a3;
            gpr t0, t1, t2, t3, t4, t5, t6, t7;
            gpr s0, s1, s2, s3, s4, s5, s6, s7;
            gpr t8, t9, k0, k1, gp, sp, fp, ra;
        };
    };
    bool is_r5900;

    u32 (*mem_read)(struct mips*, u32 addr);
    void (*mem_write)(struct mips*, u32 addr, u32 data);
} mips;

typedef struct ps2 {
  mips r3000, r5900;
} ps2;


typedef enum mips_instr_e {
  INVALID,
  //mem
  LB, LBU, LD, LDL, LDR, LH, LHU, LW, LWL, LWR, LWU, SB, SD, SDL, SDR, SH, SW, SWL, SWR,
  //alu imm
  ADDI, ADDIU, ANDI, DADDI, DADDIU, LUI, ORI, SLTI, SLTIU, XORI,
  //alu 3 op
  ADD, ADDU, AND, DADD, DADDU, DSUB, DSUBU, NOR, OR, SLT, SLTU, SUB, SUBU, XOR,
  // alu shift
  DSLL, DSLL32, DSLLV, DSRA, DSRA32, DSRAV, DSRL, DSRL32, DSRLV, SLL, SLLV, SRA, SRAV, SRL, SRLV,
  // alu mult div
  DIV, DIVU, MFHI, MFLO, MTHI, MTLO, MULT, MULTU,
  //branch jump
  J, JAL, JALR, JR, BEQ, BEQL, BGEZ, BGEZAL, BGEZALL, BGEZL, BGTZ, BGTZL, BLEZ, BLEZL, BLTZ, BLTZAL, BLTZALL, BLTZL, BNE, BNEL,
  //exception
  SYSCALL, BREAK, TGE, TGEU, TLT, TLTU, TEQ, TNE, TGEI, TGEIU, TLTI, TLTIU, TEQI, TNEI,
  //sync
  SYNC,
  //misc
  MOVN, MOVZ, PREF,
  //ee mult div
  MADD, MADDU, MULT1, MULTU1, DIV1, DIVU1, MADD1, MADDU1, MFHI1, MTHI1, MFLO1, MTLO1,
  // MMI alu
  PADDB, PSUBB, PADDH, PSUBH, PADDW, PSUBW, PADSBH, PADDSB, PSUBSB, PADDSH, PSUBSH, PADDSW, PSUBSW, PADDUB, PSUBUB, PADDUH, PSUBUH, PADDUW, PSUBUW,
  // MMI mul div
  PMULTW, PMULTUW, PDIVW, PDIVUW, PMADDW, PMADDUW, PMSUBW, PMFHI, PMTHI, PMFLO, PMTLO, PMULTH, PMADDH, PMSUBH, PMFHL, PMTHL, PHMADH, PHMSBH, PDIVBW,
  // MMI shift
  MFSA, MTSA, MTSAB, MTSAH, PSLLH, PSRLH, PSRAH, PSLLW, PSLLVW, PSRLW, PSRLVW, PSRAW, PSRAVW, QFSRV,
  // MMI misc
  PABSH, PABSW, PMAXH, PMINH, PMAXW, PMINW, PAND, POR, PNOR, PXOR,
  // MMI comp
  PCGTB, PCEQB, PCGTH, PCEQH, PCGTW, PCEQW, PLZCW,
  // MMI load store
  LQ, SQ,
  // MMI data rearrangement
  PPACB, PPACH, PINTEH, PPACW, PEXTUB, PEXTLB, PEXTUH, PEXTLH, PEXTUW, PEXTLW, PEXT5, PPAC5, PCPYH, PCPYLD, PCPYUD, PREVH, PINTH, PEXEH, PEXCH, PEXEW, PEXCW, PROT3W,
  // cop0
  BC0F, BC0FL, BC0T, BC0TL, CACHE, DI, EI, ERET, MFC0, MTC0, TLBR, TLBWI, TLBWR, TLBP,
  // fpu move
  LWC1, SWC1, MTC1, MFC1, MOV_S, CTC1, CFC1,
  // fpu cvt
  CVT_S_W, CVT_W_S,
  // fpu compute
  ADD_S, SUB_S, MUL_S, DIV_S, ABS_S, NEG_S, SQRT_S, ADDA_S, SUBA_S, MULA_S, MADD_S, MADDA_S, MSUB_S, MSUBA_S, RSQRT_S, MAX_S, MIN_S,
  // fpu compare
  C_LS_S, //TODO: and the like
  //fpu branch
  BC1T, BC1F, BC1TL, BC1FL,
  //cop2
  BC2F, BC2FL, BC2T, BC2TL, CALLMS, CALLMSR, CFC2, CTC2, LQC2, SQC2, QMFC2, QMTC2, WAITQ,



} mips_instr_e;

typedef enum inst_type_e {
  R_TYPE, J_TYPE, I_TYPE
} inst_type_e;

typedef union inst_op {
  u32 raw;
  struct [[gnu::packed]] { u8 op: 6; u8 rs: 5; u8 rt: 5; u8 rd: 5; u8 sa: 5; u8 func: 6; };
  struct [[gnu::packed]] { u8 _op: 6; u32 target:26; };
  struct [[gnu::packed]] { u8 __op: 6; u8 __rs: 5; u8 __rt: 5; union{u16 uimm; s16 simm;};};
} inst_op [[gnu::packed]];

static_assert(sizeof(inst_op) == 4);

typedef struct instruction {
  inst_op op;
  mips_instr_e inst;
  char* disasm;
} instruction;
