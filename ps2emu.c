#include "ps2emu.h"

instruction mips_decode(u32 opcode, u32 pc) {
  inst_op decoded = (inst_op){.raw=opcode};

  switch (decoded.op) {
    case 0: switch (decoded.func) {
      case 0:  return (instruction){.op=decoded, .inst=SLL, .disasm="sll %s %s %s"};
      case 1:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 2:  return (instruction){.op=decoded, .inst=SRL, .disasm="srl"};
      case 3:  return (instruction){.op=decoded, .inst=SRA, .disasm="sra"};
      case 4:  return (instruction){.op=decoded, .inst=SLLV, .disasm="sllv"};
      case 5:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 6:  return (instruction){.op=decoded, .inst=SRLV, .disasm="srlv"};
      case 7:  return (instruction){.op=decoded, .inst=SRAV, .disasm="srav"};
      case 8:  return (instruction){.op=decoded, .inst=JR, .disasm="jr"};
      case 9:  return (instruction){.op=decoded, .inst=JALR, .disasm="jalr"};
      case 10: return (instruction){.op=decoded, .inst=MOVZ, .disasm="movz"};
      case 11: return (instruction){.op=decoded, .inst=MOVN, .disasm="movn"};
      case 12: return (instruction){.op=decoded, .inst=SYSCALL, .disasm="syscall"};
      case 13: return (instruction){.op=decoded, .inst=BREAK, .disasm="break"};
      case 14: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 15: return (instruction){.op=decoded, .inst=SYNC, .disasm="sync"};
      case 16: return (instruction){.op=decoded, .inst=MFHI, .disasm="mfhi"};
      case 17: return (instruction){.op=decoded, .inst=MTHI, .disasm="mthi"};
      case 18: return (instruction){.op=decoded, .inst=MFLO, .disasm="mflo"};
      case 19: return (instruction){.op=decoded, .inst=MTLO, .disasm="mtlo"};
      case 20: return (instruction){.op=decoded, .inst=DSLLV, .disasm="dsllv"};
      case 21: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 22: return (instruction){.op=decoded, .inst=DSRLV, .disasm="dsrlv"};
      case 23: return (instruction){.op=decoded, .inst=DSRAV, .disasm="dsrav"};
      case 24: return (instruction){.op=decoded, .inst=MULT, .disasm="mult"};
      case 25: return (instruction){.op=decoded, .inst=MULTU, .disasm="multu"};
      case 26: return (instruction){.op=decoded, .inst=DIV, .disasm="div"};
      case 27: return (instruction){.op=decoded, .inst=DIVU, .disasm="divu"};
      case 28: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 29: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 30: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 31: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 32: return (instruction){.op=decoded, .inst=ADD, .disasm="add"};
      case 33: return (instruction){.op=decoded, .inst=ADDU, .disasm="addu"};
      case 34: return (instruction){.op=decoded, .inst=SUB, .disasm="sub"};
      case 35: return (instruction){.op=decoded, .inst=SUBU, .disasm="subu"};
      case 36: return (instruction){.op=decoded, .inst=AND, .disasm="and"};
      case 37: return (instruction){.op=decoded, .inst=OR, .disasm="or"};
      case 38: return (instruction){.op=decoded, .inst=XOR, .disasm="xor"};
      case 39: return (instruction){.op=decoded, .inst=NOR, .disasm="nor"};
      case 40: return (instruction){.op=decoded, .inst=MFSA, .disasm="mfsa"};
      case 41: return (instruction){.op=decoded, .inst=MTSA, .disasm="mtsa"};
      case 42: return (instruction){.op=decoded, .inst=SLT, .disasm="slt"};
      case 43: return (instruction){.op=decoded, .inst=SLTU, .disasm="sltu"};
      case 44: return (instruction){.op=decoded, .inst=DADD, .disasm="dadd"};
      case 45: return (instruction){.op=decoded, .inst=DADDU, .disasm="daddu"};
      case 46: return (instruction){.op=decoded, .inst=DSUB, .disasm="dsub"};
      case 47: return (instruction){.op=decoded, .inst=DSUBU, .disasm="dsubu"};
      case 48: return (instruction){.op=decoded, .inst=TGE, .disasm="tge"};
      case 49: return (instruction){.op=decoded, .inst=TGEU, .disasm="tgeu"};
      case 50: return (instruction){.op=decoded, .inst=TLT, .disasm="tlt"};
      case 51: return (instruction){.op=decoded, .inst=TLTU, .disasm="tltu"};
      case 52: return (instruction){.op=decoded, .inst=TEQ, .disasm="teq"};
      case 53: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 54: return (instruction){.op=decoded, .inst=TNE, .disasm="tne"};
      case 55: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 56: return (instruction){.op=decoded, .inst=DSLL, .disasm="dsll"};
      case 57: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 58: return (instruction){.op=decoded, .inst=DSRL, .disasm="dsrl"};
      case 59: return (instruction){.op=decoded, .inst=DSRA, .disasm="dsra"};
      case 60: return (instruction){.op=decoded, .inst=DSLL32, .disasm="dsll32"};
      case 61: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 62: return (instruction){.op=decoded, .inst=DSRL32, .disasm="dsrl32"};
      case 63: return (instruction){.op=decoded, .inst=DSRA32, .disasm="dsra32"};
      default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
    } break;
    case 1: switch (decoded.rt) {
      case 0:  return (instruction){.op=decoded, .inst=BLTZ, .disasm="bltz"};
      case 1:  return (instruction){.op=decoded, .inst=BGEZ, .disasm="bgez"};
      case 2:  return (instruction){.op=decoded, .inst=BLTZL, .disasm="bltzl"};
      case 3:  return (instruction){.op=decoded, .inst=BGEZL, .disasm="bgezl"};
      case 4:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 5:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 6:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 7:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 8:  return (instruction){.op=decoded, .inst=TGEI, .disasm="tgei"};
      case 9:  return (instruction){.op=decoded, .inst=TGEIU, .disasm="tgeiu"};
      case 10: return (instruction){.op=decoded, .inst=TLTI, .disasm="tlti"};
      case 11: return (instruction){.op=decoded, .inst=TLTIU, .disasm="tltiu"};
      case 12: return (instruction){.op=decoded, .inst=TEQI, .disasm="teqi"};
      case 13: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 14: return (instruction){.op=decoded, .inst=TNEI, .disasm="tnei"};
      case 15: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 16: return (instruction){.op=decoded, .inst=BLTZAL, .disasm="bltzal"};
      case 17: return (instruction){.op=decoded, .inst=BGEZAL, .disasm="bgezal"};
      case 18: return (instruction){.op=decoded, .inst=BLTZALL, .disasm="bltzall"};
      case 19: return (instruction){.op=decoded, .inst=BGEZALL, .disasm="bgezall"};
      case 20: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 21: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 22: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 23: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 24: return (instruction){.op=decoded, .inst=MTSAB, .disasm="mtsab"};
      case 25: return (instruction){.op=decoded, .inst=MTSAH, .disasm="mstah"};
      case 26: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 27: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 28: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 29: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 30: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      case 31: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
      default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
    } break;
    case 2:  return (instruction){.op=decoded, .inst=J, .disasm="j"};
    case 3:  return (instruction){.op=decoded, .inst=JAL, .disasm="jal"};
    case 4:  return (instruction){.op=decoded, .inst=BEQ, .disasm="beq"};
    case 5:  return (instruction){.op=decoded, .inst=BNE, .disasm="bne"};
    case 6:  return (instruction){.op=decoded, .inst=BLEZ, .disasm="blez"};
    case 7:  return (instruction){.op=decoded, .inst=BGTZ, .disasm="bgtz"};
    case 8:  return (instruction){.op=decoded, .inst=ADDI, .disasm="addi"};
    case 9:  return (instruction){.op=decoded, .inst=ADDIU, .disasm="addiu"};
    case 10: return (instruction){.op=decoded, .inst=SLTI, .disasm="slti"};
    case 11: return (instruction){.op=decoded, .inst=SLTIU, .disasm="sltiu"};
    case 12: return (instruction){.op=decoded, .inst=ANDI, .disasm="andi"};
    case 13: return (instruction){.op=decoded, .inst=ORI, .disasm="ori"};
    case 14: return (instruction){.op=decoded, .inst=XORI, .disasm="xori"};
    case 15: return (instruction){.op=decoded, .inst=LUI, .disasm="lui"};
    case 16: switch (decoded.rs) {
      //case 0: switch () TODO: breakpoint stuff
      //case 4: switch () TODO: breakpoint stuff
      case 8: switch (decoded.rt) {
        case 0: return (instruction){.op=decoded, .inst=BC0F, .disasm="lui"};
        case 1: return (instruction){.op=decoded, .inst=BC0T, .disasm="lui"};
        case 2: return (instruction){.op=decoded, .inst=BC0FL, .disasm="lui"};
        case 3: return (instruction){.op=decoded, .inst=BC0TL, .disasm="lui"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
      } break;
      case 16: switch (decoded.func) {
        case 1: return (instruction){.op=decoded, .inst=TLBR, .disasm="lui"};
        case 2: return (instruction){.op=decoded, .inst=TLBWI, .disasm="lui"};
        case 6: return (instruction){.op=decoded, .inst=TLBWR, .disasm="lui"};
        case 8: return (instruction){.op=decoded, .inst=TLBP, .disasm="lui"};
        case 16: return (instruction){.op=decoded, .inst=ERET, .disasm="lui"};
        case 56: return (instruction){.op=decoded, .inst=EI, .disasm="lui"};
        case 57: return (instruction){.op=decoded, .inst=DI, .disasm="lui"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="lui"};
      }
      default: return (instruction){.op=decoded, .inst=INVALID, .disasm="lui"};
    }
    case 17: switch (decoded.rs) {
      case 0: return (instruction){.op=decoded, .inst=MFC1, .disasm="lui"};
      case 2: return (instruction){.op=decoded, .inst=CFC1, .disasm="lui"};
      case 4: return (instruction){.op=decoded, .inst=MTC1, .disasm="lui"};
      case 6: return (instruction){.op=decoded, .inst=CTC1, .disasm="lui"};
      case 8: switch (decoded.rt) {
        case 0: return (instruction){.op=decoded, .inst=BC1F, .disasm="lui"};
        case 1: return (instruction){.op=decoded, .inst=BC1T, .disasm="lui"};
        case 2: return (instruction){.op=decoded, .inst=BC1FL, .disasm="lui"};
        case 3: return (instruction){.op=decoded, .inst=BC1TL, .disasm="lui"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="lui"};
      } break;
      case 16: switch (decoded.func) {

      }

    }
    case 18: // COP2
    case 19: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 20: return (instruction){.op=decoded, .inst=BEQL, .disasm="beql"};
    case 21: return (instruction){.op=decoded, .inst=BNEL, .disasm="bnel"};
    case 22: return (instruction){.op=decoded, .inst=BLEZL, .disasm="blezl"};
    case 23: return (instruction){.op=decoded, .inst=BGTZL, .disasm="bgtzl"};
    case 24: return (instruction){.op=decoded, .inst=DADDI, .disasm="daddi"};
    case 25: return (instruction){.op=decoded, .inst=DADDIU, .disasm="daddiu"};
    case 26: return (instruction){.op=decoded, .inst=LDL, .disasm="ldl"};
    case 27: return (instruction){.op=decoded, .inst=LDR, .disasm="LDR"};
    case 28: switch (decoded.func) {
      case 0:  return (instruction){.op=decoded, .inst=MADD, .disasm="sll %s %s %s"};
      case 1:  return (instruction){.op=decoded, .inst=MADDU, .disasm="invalid"};
      case 4:  return (instruction){.op=decoded, .inst=PLZCW, .disasm="invalid"};
      case 8:  switch (decoded.sa) {
        case 0:  return (instruction){.op=decoded, .inst=PADDW, .disasm="bltz"};
        case 1:  return (instruction){.op=decoded, .inst=PSUBW, .disasm="bgez"};
        case 2:  return (instruction){.op=decoded, .inst=PCGTW, .disasm="bltzl"};
        case 3:  return (instruction){.op=decoded, .inst=PMAXW, .disasm="bgezl"};
        case 4:  return (instruction){.op=decoded, .inst=PADDH, .disasm="invalid"};
        case 5:  return (instruction){.op=decoded, .inst=PSUBH, .disasm="invalid"};
        case 6:  return (instruction){.op=decoded, .inst=PCGTH, .disasm="invalid"};
        case 7:  return (instruction){.op=decoded, .inst=PMAXH, .disasm="invalid"};
        case 8:  return (instruction){.op=decoded, .inst=PADDB, .disasm="tgei"};
        case 9:  return (instruction){.op=decoded, .inst=PSUBB, .disasm="tgeiu"};
        case 10: return (instruction){.op=decoded, .inst=PCGTB, .disasm="tlti"};
        case 11: return (instruction){.op=decoded, .inst=INVALID, .disasm="tltiu"};
        case 12: return (instruction){.op=decoded, .inst=INVALID, .disasm="teqi"};
        case 13: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 14: return (instruction){.op=decoded, .inst=INVALID, .disasm="tnei"};
        case 15: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 16: return (instruction){.op=decoded, .inst=PADDSW, .disasm="bltzal"};
        case 17: return (instruction){.op=decoded, .inst=PSUBSW, .disasm="bgezal"};
        case 18: return (instruction){.op=decoded, .inst=PEXTLW, .disasm="bltzall"};
        case 19: return (instruction){.op=decoded, .inst=PPACW, .disasm="bgezall"};
        case 20: return (instruction){.op=decoded, .inst=PADDSH, .disasm="invalid"};
        case 21: return (instruction){.op=decoded, .inst=PSUBSH, .disasm="invalid"};
        case 22: return (instruction){.op=decoded, .inst=PEXTLH, .disasm="invalid"};
        case 23: return (instruction){.op=decoded, .inst=PPACH, .disasm="invalid"};
        case 24: return (instruction){.op=decoded, .inst=PADDSB, .disasm="mtsab"};
        case 25: return (instruction){.op=decoded, .inst=PSUBSB, .disasm="mstah"};
        case 26: return (instruction){.op=decoded, .inst=PEXTLB, .disasm="invalid"};
        case 27: return (instruction){.op=decoded, .inst=PPACB, .disasm="invalid"};
        case 28: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 29: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 30: return (instruction){.op=decoded, .inst=PEXT5, .disasm="invalid"};
        case 31: return (instruction){.op=decoded, .inst=PPAC5, .disasm="invalid"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
      } break;
      case 9:  switch (decoded.sa) {
        case 0:  return (instruction){.op=decoded, .inst=PMADDW, .disasm="bltz"};
        case 1:  return (instruction){.op=decoded, .inst=INVALID, .disasm="bgez"};
        case 2:  return (instruction){.op=decoded, .inst=PSLLVW, .disasm="bltzl"};
        case 3:  return (instruction){.op=decoded, .inst=PSRLVW, .disasm="bgezl"};
        case 4:  return (instruction){.op=decoded, .inst=PMSUBW, .disasm="invalid"};
        case 5:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 6:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 7:  return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 8:  return (instruction){.op=decoded, .inst=PMFHI, .disasm="tgei"};
        case 9:  return (instruction){.op=decoded, .inst=PMFLO, .disasm="tgeiu"};
        case 10: return (instruction){.op=decoded, .inst=PINTH, .disasm="tlti"};
        case 11: return (instruction){.op=decoded, .inst=INVALID, .disasm="tltiu"};
        case 12: return (instruction){.op=decoded, .inst=PMULTW, .disasm="teqi"};
        case 13: return (instruction){.op=decoded, .inst=PDIVW, .disasm="invalid"};
        case 14: return (instruction){.op=decoded, .inst=PCPYLD, .disasm="tnei"};
        case 15: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 16: return (instruction){.op=decoded, .inst=PMADDH, .disasm="bltzal"};
        case 17: return (instruction){.op=decoded, .inst=PHMADH, .disasm="bgezal"};
        case 18: return (instruction){.op=decoded, .inst=PAND, .disasm="bltzall"};
        case 19: return (instruction){.op=decoded, .inst=PXOR, .disasm="bgezall"};
        case 20: return (instruction){.op=decoded, .inst=PMSUBH, .disasm="invalid"};
        case 21: return (instruction){.op=decoded, .inst=PHMSBH, .disasm="invalid"};
        case 22: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 23: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 24: return (instruction){.op=decoded, .inst=INVALID, .disasm="mtsab"};
        case 25: return (instruction){.op=decoded, .inst=INVALID, .disasm="mstah"};
        case 26: return (instruction){.op=decoded, .inst=PEXEH, .disasm="invalid"};
        case 27: return (instruction){.op=decoded, .inst=PREVH, .disasm="invalid"};
        case 28: return (instruction){.op=decoded, .inst=PMULTH, .disasm="invalid"};
        case 29: return (instruction){.op=decoded, .inst=PDIVBW, .disasm="invalid"};
        case 30: return (instruction){.op=decoded, .inst=PEXEH, .disasm="invalid"};
        case 31: return (instruction){.op=decoded, .inst=PROT3W, .disasm="invalid"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
      } break;
      case 16: return (instruction){.op=decoded, .inst=MFHI1, .disasm="sll %s %s %s"};
      case 17: return (instruction){.op=decoded, .inst=MTHI1, .disasm="sll %s %s %s"};
      case 18: return (instruction){.op=decoded, .inst=MFLO1, .disasm="sll %s %s %s"};
      case 19: return (instruction){.op=decoded, .inst=MTLO1, .disasm="sll %s %s %s"};
      case 24: return (instruction){.op=decoded, .inst=MULT1, .disasm="sll %s %s %s"};
      case 25: return (instruction){.op=decoded, .inst=MULTU1, .disasm="sll %s %s %s"};
      case 26: return (instruction){.op=decoded, .inst=DIV1, .disasm="sll %s %s %s"};
      case 27: return (instruction){.op=decoded, .inst=DIVU1, .disasm="sll %s %s %s"};
      case 32: return (instruction){.op=decoded, .inst=MADD1, .disasm="sll %s %s %s"};
      case 33: return (instruction){.op=decoded, .inst=MADDU1, .disasm="sll %s %s %s"};
      case 40:  switch (decoded.sa) {
        case 0:  return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
        case 1:  return (instruction){.op=decoded, .inst=PABSW, .disasm="bgez"};
        case 2:  return (instruction){.op=decoded, .inst=PCEQW, .disasm="bltzl"};
        case 3:  return (instruction){.op=decoded, .inst=PMINW, .disasm="bgezl"};
        case 4:  return (instruction){.op=decoded, .inst=PADSBH, .disasm="invalid"};
        case 5:  return (instruction){.op=decoded, .inst=PABSH, .disasm="invalid"};
        case 6:  return (instruction){.op=decoded, .inst=PCEQH, .disasm="invalid"};
        case 7:  return (instruction){.op=decoded, .inst=PMINH, .disasm="invalid"};
        case 8:  return (instruction){.op=decoded, .inst=INVALID, .disasm="tgei"};
        case 9:  return (instruction){.op=decoded, .inst=INVALID, .disasm="tgeiu"};
        case 10: return (instruction){.op=decoded, .inst=PCEQB, .disasm="tlti"};
        case 11: return (instruction){.op=decoded, .inst=INVALID, .disasm="tltiu"};
        case 12: return (instruction){.op=decoded, .inst=INVALID, .disasm="teqi"};
        case 13: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 14: return (instruction){.op=decoded, .inst=INVALID, .disasm="tnei"};
        case 15: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 16: return (instruction){.op=decoded, .inst=PADDUW, .disasm="bltzal"};
        case 17: return (instruction){.op=decoded, .inst=PSUBUW, .disasm="bgezal"};
        case 18: return (instruction){.op=decoded, .inst=PEXTUW, .disasm="bltzall"};
        case 19: return (instruction){.op=decoded, .inst=INVALID, .disasm="bgezall"};
        case 20: return (instruction){.op=decoded, .inst=PADDUH, .disasm="invalid"};
        case 21: return (instruction){.op=decoded, .inst=PSUBUH, .disasm="invalid"};
        case 22: return (instruction){.op=decoded, .inst=PEXTUH, .disasm="invalid"};
        case 23: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 24: return (instruction){.op=decoded, .inst=PADDUB, .disasm="mtsab"};
        case 25: return (instruction){.op=decoded, .inst=PSUBUB, .disasm="mstah"};
        case 26: return (instruction){.op=decoded, .inst=PEXTUB, .disasm="invalid"};
        case 27: return (instruction){.op=decoded, .inst=QFSRV, .disasm="invalid"};
        case 28: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 29: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 30: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        case 31: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
      } break;
      case 41:  switch (decoded.sa) {
        case 0:  return (instruction){.op=decoded, .inst=PMADDUW, .disasm="bltz"};
        case 3:  return (instruction){.op=decoded, .inst=PSRAVW, .disasm="bltz"};
        case 8:  return (instruction){.op=decoded, .inst=PMTHI, .disasm="bltz"};
        case 9:  return (instruction){.op=decoded, .inst=PMTLO, .disasm="bltz"};
        case 10: return (instruction){.op=decoded, .inst=PINTEH, .disasm="bltz"};
        case 12: return (instruction){.op=decoded, .inst=PMULTUW, .disasm="bltz"};
        case 13: return (instruction){.op=decoded, .inst=PDIVUW, .disasm="bltz"};
        case 14: return (instruction){.op=decoded, .inst=PCPYUD, .disasm="bltz"};
        case 18: return (instruction){.op=decoded, .inst=POR, .disasm="bltz"};
        case 19: return (instruction){.op=decoded, .inst=PNOR, .disasm="bltz"};
        case 26: return (instruction){.op=decoded, .inst=PEXCH, .disasm="bltz"};
        case 27: return (instruction){.op=decoded, .inst=PCPYH, .disasm="bltz"};
        case 30: return (instruction){.op=decoded, .inst=PEXCW, .disasm="bltz"};
        default: return (instruction){.op=decoded, .inst=INVALID, .disasm="bltz"};
      } break;
      case 48: return (instruction){.op=decoded, .inst=PMFHL, .disasm="sll %s %s %s"};
      case 49: return (instruction){.op=decoded, .inst=PMTHL, .disasm="sll %s %s %s"};
      case 52: return (instruction){.op=decoded, .inst=PSLLH, .disasm="sll %s %s %s"};
      case 54: return (instruction){.op=decoded, .inst=PSRLH, .disasm="sll %s %s %s"};
      case 55: return (instruction){.op=decoded, .inst=PSRAH, .disasm="sll %s %s %s"};
      case 60: return (instruction){.op=decoded, .inst=PSLLW, .disasm="sll %s %s %s"};
      case 62: return (instruction){.op=decoded, .inst=PSRLW, .disasm="sll %s %s %s"};
      case 63: return (instruction){.op=decoded, .inst=PSRAW, .disasm="sll %s %s %s"};
      default: return (instruction){.op=decoded, .inst=INVALID, .disasm="sll %s %s %s"};
    }
    case 29: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 30: return (instruction){.op=decoded, .inst=LQ, .disasm="lq"};
    case 31: return (instruction){.op=decoded, .inst=SQ, .disasm="sq"};
    case 32: return (instruction){.op=decoded, .inst=LB, .disasm="lb"};
    case 33: return (instruction){.op=decoded, .inst=LH, .disasm="lh"};
    case 34: return (instruction){.op=decoded, .inst=LWL, .disasm="lwl"};
    case 35: return (instruction){.op=decoded, .inst=LW, .disasm="lw"};
    case 36: return (instruction){.op=decoded, .inst=LBU, .disasm="lbu"};
    case 37: return (instruction){.op=decoded, .inst=LHU, .disasm="lhu"};
    case 38: return (instruction){.op=decoded, .inst=LWR, .disasm="lwr"};
    case 39: return (instruction){.op=decoded, .inst=LWU, .disasm="lwu"};
    case 40: return (instruction){.op=decoded, .inst=SB, .disasm="sb"};
    case 41: return (instruction){.op=decoded, .inst=SH, .disasm="sh"};
    case 42: return (instruction){.op=decoded, .inst=SWL, .disasm="swl"};
    case 43: return (instruction){.op=decoded, .inst=SW, .disasm="sw"};
    case 44: return (instruction){.op=decoded, .inst=SDL, .disasm="sdl"};
    case 45: return (instruction){.op=decoded, .inst=SDR, .disasm="sdr"};
    case 46: return (instruction){.op=decoded, .inst=SWR, .disasm="dsub"};
    case 47: return (instruction){.op=decoded, .inst=CACHE, .disasm="cache"};
    case 48: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 49: return (instruction){.op=decoded, .inst=LWC1, .disasm="lwc1"};
    case 50: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 51: return (instruction){.op=decoded, .inst=PREF, .disasm="pref"};
    case 52: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 53: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 54: return (instruction){.op=decoded, .inst=LQC2, .disasm="lqc2"};
    case 55: return (instruction){.op=decoded, .inst=LD, .disasm="ld"};
    case 56: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 57: return (instruction){.op=decoded, .inst=SWC1, .disasm="swc1"};
    case 58: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 59: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 60: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 61: return (instruction){.op=decoded, .inst=INVALID, .disasm="invalid"};
    case 62: return (instruction){.op=decoded, .inst=SQC2, .disasm="sqc2"};
    case 63: return (instruction){.op=decoded, .inst=SD, .disasm="SD"};
  }
}

overload bool mips_read8(ps2* ps2, mips* mips, u32 address, u8* dest) {}
overload bool mips_read16(ps2* ps2, mips* mips, u32 address, u16* dest) {}
overload bool mips_read32(ps2* ps2, mips* mips, u32 address, u32* dest) {}
overload bool mips_read64(ps2* ps2, mips* mips, u32 address, u64* dest) {}
overload bool mips_read128(ps2* ps2, mips* mips, u32 address, u128* dest) {}

overload bool mips_read8(ps2* ps2, mips* mips, u32 address, s8* dest) {}
overload bool mips_read16(ps2* ps2, mips* mips, u32 address, s16* dest) {}
overload bool mips_read32(ps2* ps2, mips* mips, u32 address, s32* dest) {}
overload bool mips_read64(ps2* ps2, mips* mips, u32 address, s64* dest) {}
overload bool mips_read128(ps2* ps2, mips* mips, u32 address, s128* dest) {}

overload bool mips_write8(ps2* ps2, mips* mips, u32 address, u8 data) {}
overload bool mips_write16(ps2* ps2, mips* mips, u32 address, u16 data) {}
overload bool mips_write32(ps2* ps2, mips* mips, u32 address, u32 data) {}
overload bool mips_write64(ps2* ps2, mips* mips, u32 address, u64 data) {}
overload bool mips_write128(ps2* ps2, mips* mips, u32 address, u128 data) {}

overload bool mips_write8(ps2* ps2, mips* mips, u32 address, s8 data) {}
overload bool mips_write16(ps2* ps2, mips* mips, u32 address, s16 data) {}
overload bool mips_write32(ps2* ps2, mips* mips, u32 address, s32 data) {}
overload bool mips_write64(ps2* ps2, mips* mips, u32 address, s64 data) {}
overload bool mips_write128(ps2* ps2, mips* mips, u32 address, s128 data) {}

void mips_execute(ps2* ps2, mips* mips, instruction instruction) {
  inst_op decoded = instruction.op;

#define rt(T,i)   mips->gpr[decoded.rt].T[i]
#define rd(T,i)   mips->gpr[decoded.rd].T[i]
#define rs(T,i)   mips->gpr[decoded.rs].T[i]
#define base(T,i) rs(T,i)

  auto simm = decoded.simm;
  auto uimm = decoded.uimm;
  auto base = decoded.rs;

  u64 shift = 0, mask = 0, data = 0, merged = 0;

  u8 u8 = 0;
  u16 u16 = 0;
  u32 u32 = 0;
  u64 u64 = 0;
  u128 u128 = 0;

  s8 s8 = 0;
  s16 s16 = 0;
  s32 s32 = 0;
  s64 s64 = 0;
  s128 s128 = 0;

  switch (instruction.inst) {
  case INVALID: break;
  case LB:  if (mips_read8(ps2,  mips, base(u32,0) + simm, &s8))  rt(s64,0) = s8;  break;
  case LBU: if (mips_read8(ps2,  mips, base(u32,0) + simm, &u8))  rt(u64,0) = u8;  break;
  case LD:  if (mips_read64(ps2, mips, base(u32,0) + simm, &u64)) rt(u64,0) = u64; break;
  case LDL: if (mips_read64(ps2, mips, base(u32,0) + simm & ~7UL, &u64)) {
      rt(u64,0) = rt(u64,0) & (1ULL << (base(u32,0) + simm & 7) * 8) - 1 | u64 << (base(u32,0) + simm & 7) * 8;
    }
    break;
  case LDR: if (mips_read64(ps2, mips, base(u32,0) + simm & ~7UL, &u64)) {
      rt(u64,0) = rt(u64,0) & ~((1ULL << (8 - base(u32,0) + simm & 7) * 8) - 1) | u64 >> (base(u32,0) + simm & 7 * 8);
    }
    break;
  case LH:  if (mips_read16(ps2,  mips, base(u32,0) + simm, &s16))  rt(s64,0) = s16; break;
  case LHU: if (mips_read16(ps2,  mips, base(u32,0) + simm, &u16))  rt(u64,0) = u16;  break;
  case LW:  if (mips_read32(ps2,  mips, base(u32,0) + simm, &s32))  rt(s64,0) = s32;  break;
  case LWL: if (mips_read32(ps2, mips, base(u32,0) + simm & ~3UL, &u32)) {
    rt(u64,0) = rt(u64,0) & (1ULL << (base(u32,0) + simm & 3) * 8) - 1 | (s64)(s32)(u32 << (base(u32,0) + simm & 3) * 8);
  }
  break;
  case LWR: if (mips_read32(ps2, mips, base(u32,0) + simm & ~3UL, &u32)) {
    rt(u64,0) = rt(u64,0) & ~((1ULL << (4 - base(u32,0) + simm & 3) * 8) - 1) | (s64)(s32)(u32 >> (base(u32,0) + simm & 3) * 8);
  }
  break;
  case LWU: if (mips_read32(ps2, mips, base(u32,0) + simm, &u32)) rt(u64,0) = u32; break;
  case SB: mips_write8(ps2, mips, base(u32,0) + simm, rt(u8,0));   break;
  case SD: mips_write64(ps2, mips, base(u32,0) + simm, rt(u64,0)); break;
  case SDL: if (mips_read64(ps2, mips, base(u32,0) + simm & ~7UL, &u64))
        mips_write64(ps2, mips, base(u32,0) + simm & ~7UL, (u64 & ~(~0ULL << ((base(u32,0) + simm & 7) * 8))) | (rt(u64,0) >> ((base(u32,0) + simm & 7) * 8))); break;
  case SDR: if (mips_read64(ps2, mips, base(u32,0) + simm & ~7UL, &u64))
        mips_write64(ps2, mips, base(u32,0) + simm & ~7UL, (u64 & ~((1ULL << ((8 - (base(u32,0) + simm & 7)) * 8)) - 1)) | (rt(u64,0) << ((8 - (base(u32,0) + simm & 7)) * 8))); break;
  case SH: break;
  case SW: break;
  case SWL: break;
  case SWR: break;
  case ADDI:
    if (add_overflow(rs(s64,0), simm, &rt(s64,0))) {
      // exception
    }
    break;
  case ADDIU:
    rt(u64,0) = rs(s64,0) + simm;
    break;
  case ANDI: break;
  case DADDI: break;
  case DADDIU: break;
  case LUI: break;
  case ORI: break;
  case SLTI: break;
  case SLTIU: break;
  case XORI: break;
  case ADD: break;
  case ADDU: break;
  case AND: break;
  case DADD: break;
  case DADDU: break;
  case DSUB: break;
  case DSUBU: break;
  case NOR: break;
  case OR: break;
  case SLT: break;
  case SLTU: break;
  case SUB: break;
  case SUBU: break;
  case XOR: break;
  case DSLL: break;
  case DSLL32: break;
  case DSLLV: break;
  case DSRA: break;
  case DSRA32: break;
  case DSRAV: break;
  case DSRL: break;
  case DSRL32: break;
  case DSRLV: break;
  case SLL: break;
  case SLLV: break;
  case SRA: break;
  case SRAV: break;
  case SRL: break;
  case SRLV: break;
  case DIV: break;
  case DIVU: break;
  case MFHI: break;
  case MFLO: break;
  case MTHI: break;
  case MTLO: break;
  case MULT: break;
  case MULTU: break;
  case J: break;
  case JAL: break;
  case JALR: break;
  case JR: break;
  case BEQ: break;
  case BEQL: break;
  case BGEZ: break;
  case BGEZAL: break;
  case BGEZALL: break;
  case BGEZL: break;
  case BGTZ: break;
  case BGTZL: break;
  case BLEZ: break;
  case BLEZL: break;
  case BLTZ: break;
  case BLTZAL: break;
  case BLTZALL: break;
  case BLTZL: break;
  case BNE: break;
  case BNEL: break;
  case SYSCALL: break;
  case BREAK: break;
  case TGE: break;
  case TGEU: break;
  case TLT: break;
  case TLTU: break;
  case TEQ: break;
  case TNE: break;
  case TGEI: break;
  case TGEIU: break;
  case TLTI: break;
  case TLTIU: break;
  case TEQI: break;
  case TNEI: break;
  case SYNC: break;
  case MOVN: break;
  case MOVZ: break;
  case PREF: break;
  case MADD: break;
  case MADDU: break;
  case MULT1: break;
  case MULTU1: break;
  case DIV1: break;
  case DIVU1: break;
  case MADD1: break;
  case MADDU1: break;
  case MFHI1: break;
  case MTHI1: break;
  case MFLO1: break;
  case MTLO1: break;
  case PADDB: break;
  case PSUBB: break;
  case PADDH: break;
  case PSUBH: break;
  case PADDW: break;
  case PSUBW: break;
  case PADSBH: break;
  case PADDSB: break;
  case PSUBSB: break;
  case PADDSH: break;
  case PSUBSH: break;
  case PADDSW: break;
  case PSUBSW: break;
  case PADDUB: break;
  case PSUBUB: break;
  case PADDUH: break;
  case PSUBUH: break;
  case PADDUW: break;
  case PSUBUW: break;
  case PMULTW: break;
  case PMULTUW: break;
  case PDIVW: break;
  case PDIVUW: break;
  case PMADDW: break;
  case PMADDUW: break;
  case PMSUBW: break;
  case PMFHI: break;
  case PMTHI: break;
  case PMFLO: break;
  case PMTLO: break;
  case PMULTH: break;
  case PMADDH: break;
  case PMSUBH: break;
  case PMFHL: break;
  case PMTHL: break;
  case PHMADH: break;
  case PHMSBH: break;
  case PDIVBW: break;
  case MFSA: break;
  case MTSA: break;
  case MTSAB: break;
  case MTSAH: break;
  case PSLLH: break;
  case PSRLH: break;
  case PSRAH: break;
  case PSLLW: break;
  case PSLLVW: break;
  case PSRLW: break;
  case PSRLVW: break;
  case PSRAW: break;
  case PSRAVW: break;
  case QFSRV: break;
  case PABSH: break;
  case PABSW: break;
  case PMAXH: break;
  case PMINH: break;
  case PMAXW: break;
  case PMINW: break;
  case PAND: break;
  case POR: break;
  case PNOR: break;
  case PXOR: break;
  case PCGTB: break;
  case PCEQB: break;
  case PCGTH: break;
  case PCEQH: break;
  case PCGTW: break;
  case PCEQW: break;
  case PLZCW: break;
  case LQ: break;
  case SQ: break;
  case PPACB: break;
  case PPACH: break;
  case PINTEH: break;
  case PPACW: break;
  case PEXTUB: break;
  case PEXTLB: break;
  case PEXTUH: break;
  case PEXTLH: break;
  case PEXTUW: break;
  case PEXTLW: break;
  case PEXT5: break;
  case PPAC5: break;
  case PCPYH: break;
  case PCPYLD: break;
  case PCPYUD: break;
  case PREVH: break;
  case PINTH: break;
  case PEXEH: break;
  case PEXCH: break;
  case PEXEW: break;
  case PEXCW: break;
  case PROT3W: break;
  case BC0F: break;
  case BC0FL: break;
  case BC0T: break;
  case BC0TL: break;
  case CACHE: break;
  case DI: break;
  case EI: break;
  case ERET: break;
  case MFC0: break;
  case MTC0: break;
  case TLBR: break;
  case TLBWI: break;
  case TLBWR: break;
  case TLBP: break;
  case LWC1: break;
  case SWC1: break;
  case MTC1: break;
  case MFC1: break;
  case MOV_S: break;
  case CTC1: break;
  case CFC1: break;
  case CVT_S_W: break;
  case CVT_W_S: break;
  case ADD_S: break;
  case SUB_S: break;
  case MUL_S: break;
  case DIV_S: break;
  case ABS_S: break;
  case NEG_S: break;
  case SQRT_S: break;
  case ADDA_S: break;
  case SUBA_S: break;
  case MULA_S: break;
  case MADD_S: break;
  case MADDA_S: break;
  case MSUB_S: break;
  case MSUBA_S: break;
  case RSQRT_S: break;
  case MAX_S: break;
  case MIN_S: break;
  case C_LS_S: break;
  //TODO: and the like
  case BC1T: break;
  case BC1F: break;
  case BC1TL: break;
  case BC1FL: break;
  case BC2F: break;
  case BC2FL: break;
  case BC2T: break;
  case BC2TL: break;
  case CALLMS: break;
  case CALLMSR: break;
  case CFC2: break;
  case CTC2: break;
  case LQC2: break;
  case SQC2: break;
  case QMFC2: break;
  case QMTC2: break;
  case WAITQ: break;
  }
}


int main(int argc, char** argv) {
  auto ptr = malloc(1234);
  free(ptr);
  auto asdf = 1;
  printf("hello world\n");
  return 0;
}