#include "ps2emu.h"

instruction decode(u32 opcode, u32 pc) {
  auto op = opcode >> 26;
  auto rs = (opcode >> 21) & 0x1f;
  auto rt = (opcode >> 16) & 0x1f;
  auto rd = (opcode >> 11) & 0x1f;
  auto simm16 = (s16)(opcode & 0xffff);
  auto uimm16 = (u16)(opcode & 0xffff);
  auto offset = simm16 << 2 + pc + 4;
  auto code = (opcode >> 6) & 0xfffff;
  auto sa = opcode >> 6 & 0x1f;
  auto func = opcode & 0x3f;

  switch (op) {
    case 0: switch (func) {
      case 0:  return (instruction){.op=opcode, .inst=SLL, .disasm="sll %s %s %s"};
      case 1:  return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 2:  return (instruction){.op=opcode, .inst=SRL, .disasm="srl"};
      case 3:  return (instruction){.op=opcode, .inst=SRA, .disasm="sra"};
      case 4:  return (instruction){.op=opcode, .inst=SLLV, .disasm="sllv"};
      case 5:  return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 6:  return (instruction){.op=opcode, .inst=SRLV, .disasm="srlv"};
      case 7:  return (instruction){.op=opcode, .inst=SRAV, .disasm="srav"};
      case 8:  return (instruction){.op=opcode, .inst=JR, .disasm="jr"};
      case 9:  return (instruction){.op=opcode, .inst=JALR, .disasm="jalr"};
      case 10: return (instruction){.op=opcode, .inst=MOVZ, .disasm="movz"};
      case 11: return (instruction){.op=opcode, .inst=MOVN, .disasm="movn"};
      case 12: return (instruction){.op=opcode, .inst=SYSCALL, .disasm="syscall"};
      case 13: return (instruction){.op=opcode, .inst=BREAK, .disasm="break"};
      case 14: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 15: return (instruction){.op=opcode, .inst=SYNC, .disasm="sync"};
      case 16: return (instruction){.op=opcode, .inst=MFHI, .disasm="mfhi"};
      case 17: return (instruction){.op=opcode, .inst=MTHI, .disasm="mthi"};
      case 18: return (instruction){.op=opcode, .inst=MFLO, .disasm="mflo"};
      case 19: return (instruction){.op=opcode, .inst=MTLO, .disasm="mtlo"};
      case 20: return (instruction){.op=opcode, .inst=DSLLV, .disasm="dsllv"};
      case 21: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 22: return (instruction){.op=opcode, .inst=DSRLV, .disasm="dsrlv"};
      case 23: return (instruction){.op=opcode, .inst=DSRAV, .disasm="dsrav"};
      case 24: return (instruction){.op=opcode, .inst=MULT, .disasm="mult"};
      case 25: return (instruction){.op=opcode, .inst=MULTU, .disasm="multu"};
      case 26: return (instruction){.op=opcode, .inst=DIV, .disasm="div"};
      case 27: return (instruction){.op=opcode, .inst=DIVU, .disasm="divu"};
      case 28: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 29: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 30: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 31: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 32: return (instruction){.op=opcode, .inst=ADD, .disasm="add"};
      case 33: return (instruction){.op=opcode, .inst=ADDU, .disasm="addu"};
      case 34: return (instruction){.op=opcode, .inst=SUB, .disasm="sub"};
      case 35: return (instruction){.op=opcode, .inst=SUBU, .disasm="subu"};
      case 36: return (instruction){.op=opcode, .inst=AND, .disasm="and"};
      case 37: return (instruction){.op=opcode, .inst=OR, .disasm="or"};
      case 38: return (instruction){.op=opcode, .inst=XOR, .disasm="xor"};
      case 39: return (instruction){.op=opcode, .inst=NOR, .disasm="nor"};
      case 40: return (instruction){.op=opcode, .inst=MFSA, .disasm="mfsa"};
      case 41: return (instruction){.op=opcode, .inst=MTSA, .disasm="mtsa"};
      case 42: return (instruction){.op=opcode, .inst=SLT, .disasm="slt"};
      case 43: return (instruction){.op=opcode, .inst=SLTU, .disasm="sltu"};
      case 44: return (instruction){.op=opcode, .inst=DADD, .disasm="dadd"};
      case 45: return (instruction){.op=opcode, .inst=DADDU, .disasm="daddu"};
      case 46: return (instruction){.op=opcode, .inst=DSUB, .disasm="dsub"};
      case 47: return (instruction){.op=opcode, .inst=DSUBU, .disasm="dsubu"};
      case 48: return (instruction){.op=opcode, .inst=TGE, .disasm="tge"};
      case 49: return (instruction){.op=opcode, .inst=TGEU, .disasm="tgeu"};
      case 50: return (instruction){.op=opcode, .inst=TLT, .disasm="tlt"};
      case 51: return (instruction){.op=opcode, .inst=TLTU, .disasm="tltu"};
      case 52: return (instruction){.op=opcode, .inst=TEQ, .disasm="teq"};
      case 53: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 54: return (instruction){.op=opcode, .inst=TNE, .disasm="tne"};
      case 55: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 56: return (instruction){.op=opcode, .inst=DSLL, .disasm="dsll"};
      case 57: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 58: return (instruction){.op=opcode, .inst=DSRL, .disasm="dsrl"};
      case 59: return (instruction){.op=opcode, .inst=DSRA, .disasm="dsra"};
      case 60: return (instruction){.op=opcode, .inst=DSLL32, .disasm="dsll32"};
      case 61: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 62: return (instruction){.op=opcode, .inst=DSRL32, .disasm="dsrl32"};
      case 63: return (instruction){.op=opcode, .inst=DSRA32, .disasm="dsra32"};
    } break;
    case 1: switch (rt) {
      case 0:  return (instruction){.op=opcode, .inst=BLTZ, .disasm="bltz"};
      case 1:  return (instruction){.op=opcode, .inst=BGEZ, .disasm="bgez"};
      case 2:  return (instruction){.op=opcode, .inst=BLTZL, .disasm="bltzl"};
      case 3:  return (instruction){.op=opcode, .inst=BGEZL, .disasm="bgezl"};
      case 4:  return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 5:  return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 6:  return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 7:  return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 8:  return (instruction){.op=opcode, .inst=TGEI, .disasm="tgei"};
      case 9:  return (instruction){.op=opcode, .inst=TGEIU, .disasm="tgeiu"};
      case 10: return (instruction){.op=opcode, .inst=TLTI, .disasm="tlti"};
      case 11: return (instruction){.op=opcode, .inst=TLTIU, .disasm="tltiu"};
      case 12: return (instruction){.op=opcode, .inst=TEQI, .disasm="teqi"};
      case 13: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 14: return (instruction){.op=opcode, .inst=TNEI, .disasm="tnei"};
      case 15: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 16: return (instruction){.op=opcode, .inst=BLTZAL, .disasm="bltzal"};
      case 17: return (instruction){.op=opcode, .inst=BGEZAL, .disasm="bgezal"};
      case 18: return (instruction){.op=opcode, .inst=BLTZALL, .disasm="bltzall"};
      case 19: return (instruction){.op=opcode, .inst=BGEZALL, .disasm="bgezall"};
      case 20: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 21: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 22: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 23: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 24: return (instruction){.op=opcode, .inst=MTSAB, .disasm="mtsab"};
      case 25: return (instruction){.op=opcode, .inst=MTSAH, .disasm="mstah"};
      case 26: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 27: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 28: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 29: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 30: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
      case 31: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    } break;
    case 2:  return (instruction){.op=opcode, .inst=J, .disasm="j"};
    case 3:  return (instruction){.op=opcode, .inst=JAL, .disasm="jal"};
    case 4:  return (instruction){.op=opcode, .inst=BEQ, .disasm="beq"};
    case 5:  return (instruction){.op=opcode, .inst=BNE, .disasm="bne"};
    case 6:  return (instruction){.op=opcode, .inst=BLEZ, .disasm="blez"};
    case 7:  return (instruction){.op=opcode, .inst=BGTZ, .disasm="bgtz"};
    case 8:  return (instruction){.op=opcode, .inst=ADDI, .disasm="addi"};
    case 9:  return (instruction){.op=opcode, .inst=ADDIU, .disasm="addiu"};
    case 10: return (instruction){.op=opcode, .inst=SLTI, .disasm="slti"};
    case 11: return (instruction){.op=opcode, .inst=SLTIU, .disasm="sltiu"};
    case 12: return (instruction){.op=opcode, .inst=ANDI, .disasm="andi"};
    case 13: return (instruction){.op=opcode, .inst=ORI, .disasm="ori"};
    case 14: return (instruction){.op=opcode, .inst=XORI, .disasm="xori"};
    case 15: return (instruction){.op=opcode, .inst=LUI, .disasm="lui"};
    case 16: // COP0
    case 17: // COP1
    case 18: // COP2
    case 19: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 20: return (instruction){.op=opcode, .inst=BEQL, .disasm="beql"};
    case 21: return (instruction){.op=opcode, .inst=BNEL, .disasm="bnel"};
    case 22: return (instruction){.op=opcode, .inst=BLEZL, .disasm="blezl"};
    case 23: return (instruction){.op=opcode, .inst=BGTZL, .disasm="bgtzl"};
    case 24: return (instruction){.op=opcode, .inst=DADDI, .disasm="daddi"};
    case 25: return (instruction){.op=opcode, .inst=DADDIU, .disasm="daddiu"};
    case 26: return (instruction){.op=opcode, .inst=LDL, .disasm="ldl"};
    case 27: return (instruction){.op=opcode, .inst=LDR, .disasm="LDR"};
    case 28: switch (func) {
      case 0:  return (instruction){.op=opcode, .inst=MADD, .disasm="sll %s %s %s"};
      case 1:  return (instruction){.op=opcode, .inst=MADDU, .disasm="invalid"};
      case 4:  return (instruction){.op=opcode, .inst=PLZCW, .disasm="invalid"};
      case 8:  // MMI0
      case 9: //MMI2
      case 16:   return (instruction){.op=opcode, .inst=MFHI1, .disasm="sll %s %s %s"};
      case 17:   return (instruction){.op=opcode, .inst=MTHI1, .disasm="sll %s %s %s"};
      case 18:   return (instruction){.op=opcode, .inst=MFLO1, .disasm="sll %s %s %s"};
      case 19:   return (instruction){.op=opcode, .inst=MTLO1, .disasm="sll %s %s %s"};

    }
    case 29: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 30: return (instruction){.op=opcode, .inst=LQ, .disasm="lq"};
    case 31: return (instruction){.op=opcode, .inst=SQ, .disasm="sq"};
    case 32: return (instruction){.op=opcode, .inst=LB, .disasm="lb"};
    case 33: return (instruction){.op=opcode, .inst=LH, .disasm="lh"};
    case 34: return (instruction){.op=opcode, .inst=LWL, .disasm="lwl"};
    case 35: return (instruction){.op=opcode, .inst=LW, .disasm="lw"};
    case 36: return (instruction){.op=opcode, .inst=LBU, .disasm="lbu"};
    case 37: return (instruction){.op=opcode, .inst=LHU, .disasm="lhu"};
    case 38: return (instruction){.op=opcode, .inst=LWR, .disasm="lwr"};
    case 39: return (instruction){.op=opcode, .inst=LWU, .disasm="lwu"};
    case 40: return (instruction){.op=opcode, .inst=SB, .disasm="sb"};
    case 41: return (instruction){.op=opcode, .inst=SH, .disasm="sh"};
    case 42: return (instruction){.op=opcode, .inst=SWL, .disasm="swl"};
    case 43: return (instruction){.op=opcode, .inst=SW, .disasm="sw"};
    case 44: return (instruction){.op=opcode, .inst=SDL, .disasm="sdl"};
    case 45: return (instruction){.op=opcode, .inst=SDR, .disasm="sdr"};
    case 46: return (instruction){.op=opcode, .inst=SWR, .disasm="dsub"};
    case 47: return (instruction){.op=opcode, .inst=CACHE, .disasm="cache"};
    case 48: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 49: return (instruction){.op=opcode, .inst=LWC1, .disasm="lwc1"};
    case 50: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 51: return (instruction){.op=opcode, .inst=PREF, .disasm="pref"};
    case 52: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 53: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 54: return (instruction){.op=opcode, .inst=LQC2, .disasm="lqc2"};
    case 55: return (instruction){.op=opcode, .inst=LD, .disasm="ld"};
    case 56: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 57: return (instruction){.op=opcode, .inst=SWC1, .disasm="swc1"};
    case 58: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 59: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 60: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 61: return (instruction){.op=opcode, .inst=INVALID, .disasm="invalid"};
    case 62: return (instruction){.op=opcode, .inst=SQC2, .disasm="sqc2"};
    case 63: return (instruction){.op=opcode, .inst=SD, .disasm="SD"};
  }
}

void execute(ps2* ps2, mips* mips, instruction instruction) {
  switch (instruction.inst) {
    case SLL: break;
    default: break;
  }
}


int main(int argc, char** argv) {
  auto ptr = malloc(1234);
  free(ptr);
  auto asdf = 1;
  printf("hello world\n");
  return 0;
}