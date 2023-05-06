# 1 "../main.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1\\Debug//"
# 1 "<command-line>"
# 1 "../main.c"
# 10 "../main.c"
# 1 "D:/KungFu32_/ChipONCC32/include/KF32A156MQV.h" 1




# 1 "D:/KungFu32_/ChipONCC32/include/KF32R2ALLOVER.h" 1
# 11 "D:/KungFu32_/ChipONCC32/include/KF32R2ALLOVER.h"
struct all_bit{
  unsigned int _b0:1;
  unsigned int _b1:1;
  unsigned int _b2:1;
  unsigned int _b3:1;
  unsigned int _b4:1;
  unsigned int _b5:1;
  unsigned int _b6:1;
  unsigned int _b7:1;
  unsigned int _b8:1;
  unsigned int _b9:1;
  unsigned int _b10:1;
  unsigned int _b11:1;
  unsigned int _b12:1;
  unsigned int _b13:1;
  unsigned int _b14:1;
  unsigned int _b15:1;
  unsigned int _b16:1;
  unsigned int _b17:1;
  unsigned int _b18:1;
  unsigned int _b19:1;
  unsigned int _b20:1;
  unsigned int _b21:1;
  unsigned int _b22:1;
  unsigned int _b23:1;
  unsigned int _b24:1;
  unsigned int _b25:1;
  unsigned int _b26:1;
  unsigned int _b27:1;
  unsigned int _b28:1;
  unsigned int _b29:1;
  unsigned int _b30:1;
  unsigned int _b31:1;
};



union OSC_CTL0_REG{
 unsigned int reg;
 struct OSC_CTL0_BITS{
  unsigned int _PMWREN:1;
  unsigned int _SCKS:3;
  unsigned int _LFCKEN:1;
  unsigned int :1;
  unsigned int _LFCKS:1;
  unsigned int :1;
  unsigned int _HFCKEN:1;
  unsigned int _HFCKS:3;
  unsigned int _PLLCKS:1;
  unsigned int :3;
  unsigned int _SCKDIV:3;
  unsigned int :1;
  unsigned int _HFCKDIV:4;
  unsigned int _LFCKDIV:3;
  unsigned int :1;
  unsigned int _PLLDIV:1;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OSC_CTL1_REG{
 unsigned int reg;
 struct OSC_CTL1_BITS{
  unsigned int :16;
  unsigned int _FSCM:1;
  unsigned int _FSCMGAP:3;
  unsigned int :1;
  unsigned int _FSCMS:3;
  unsigned int :1;
  unsigned int _CLKOUTS:3;
  unsigned int _CLKOE:1;
  unsigned int _CLKOUTDIV:3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OSC_INT_REG{
 unsigned int reg;
 struct OSC_INT_BITS{
  unsigned int _ILFIF:1;
  unsigned int _IHFIF:1;
  unsigned int _ELFIF:1;
  unsigned int _EHFIF:1;
  unsigned int _PLLIF:1;
  unsigned int :1;
  unsigned int _LP4MIF:1;
  unsigned int _CKFIF:1;
  unsigned int _ILFIE:1;
  unsigned int _IHFIE:1;
  unsigned int _ELFIE:1;
  unsigned int _EHFIE:1;
  unsigned int _PLLIE:1;
  unsigned int :1;
  unsigned int _LP4MIE:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OSC_CTL2_REG{
 unsigned int reg;
 struct OSC_CTL2_BITS{
  unsigned int _INTLFSWEN:1;
  unsigned int _INTHFSWEN:1;
  unsigned int _EXTLFSWEN:1;
  unsigned int _EXTHFSWEN:1;
  unsigned int _PLLSWEN:1;
  unsigned int :1;
  unsigned int _LP4MSWEN:1;
  unsigned int :9;
  unsigned int _ELFDLY:4;
  unsigned int _EHFDLY:4;
  unsigned int _PLLDLY:4;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OSC_HFOSCCAL0_REG{
 unsigned int reg;
 struct OSC_HFOSCCAL0_BITS{
  unsigned int _CTAT:5;
  unsigned int _PTAT:5;
  unsigned int _OSCLVBG12TRIM:3;
  unsigned int _HSIHIGRADE:1;
  unsigned int _HISLDO15:3;
  unsigned int _SCALEDIV32:1;
  unsigned int _SCALEDIV16:1;
  unsigned int _SCALEDIV8:1;
  unsigned int _SCALEDIV4:1;
  unsigned int _SCALEDIV2:1;
  unsigned int _SCALE1X:1;
  unsigned int _SCALE2X:1;
  unsigned int _SCALE4X:1;
  unsigned int _SCALE8X:1;
  unsigned int _SCALE16X:5;
  unsigned int _SCALE32X:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OSC_HFOSCCAL1_REG{
 unsigned int reg;
 struct OSC_HFOSCCAL1_BITS{
  unsigned int _HLSW:1;
  unsigned int _HSXTALEXEN:1;
  unsigned int _HSFSEN:1;
  unsigned int _SELGAIN:2;
  unsigned int _HSE48MHZEN:1;
  unsigned int _HISZVTOUTEN:1;
  unsigned int _PLLLDO12OUTEN:1;
  unsigned int _HISBG12OUTEN:1;
  unsigned int _HISLDO15OUTEN:1;
  unsigned int _MR12OUTEN:1;
  unsigned int :18;
  unsigned int _DEDC:1;
  unsigned int _PLLSI:1;
  unsigned int _CRCVER:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union QEI1_CTL0_REG{
 unsigned int reg;
 struct QEI1_CTL0_BITS{
  unsigned int _TXDIR:1;
  unsigned int _TXDIROUT:1;
  unsigned int _INDEX:1;
  unsigned int _TXCS:1;
  unsigned int _INDRES:1;
  unsigned int _QEIMOD:3;
  unsigned int _CNTERRIF:1;
  unsigned int _PHEIF:1;
  unsigned int _TXIF:1;
  unsigned int _LPCLK:1;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union QEI1_CTL1_REG{
 unsigned int reg;
 struct QEI1_CTL1_BITS{
  unsigned int _SWPAB:1;
  unsigned int _QEICK:3;
  unsigned int _QEIOUT:1;
  unsigned int _QEICLK:2;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T8_CNT_REG{
 unsigned int reg;
 struct T8_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T8_PPX_REG{
 unsigned int reg;
 struct T8_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T8_PRSC_REG{
 unsigned int reg;
 struct T8_PRSC_BITS{
  unsigned int _TXPRSC:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union QEI1_DIER_REG{
 unsigned int reg;
 struct QEI1_DIER_BITS{
  unsigned int _CNTERRIE:1;
  unsigned int _PHEIE:1;
  unsigned int _TXIE:1;
  unsigned int _CNTERRIC:1;
  unsigned int _PHEIC:1;
  unsigned int _TXIC:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T1_CNT_REG{
 unsigned int reg;
 struct T1_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T1_CTL1_REG{
 unsigned int reg;
 struct T1_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T1_CTL2_REG{
 unsigned int reg;
 struct T1_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS0:1;
  unsigned int _TXMMS1:1;
  unsigned int _TXMMS2:1;
  unsigned int _TXSMS0:1;
  unsigned int _TXSMS1:1;
  unsigned int _TXSMS2:1;
  unsigned int _TXTS0:1;
  unsigned int _TXTS1:1;
  unsigned int _TXTS2:1;
  unsigned int _TXTS3:1;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T1_PRSC_REG{
 unsigned int reg;
 struct T1_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T1_PPX_REG{
 unsigned int reg;
 struct T1_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T1_UDTIMx_REG{
 unsigned int reg;
 struct T1_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_C1_REG{
 unsigned int reg;
 struct CCP1_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_C2_REG{
 unsigned int reg;
 struct CCP1_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_C3_REG{
 unsigned int reg;
 struct CCP1_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_C4_REG{
 unsigned int reg;
 struct CCP1_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_SRIC_REG{
 unsigned int reg;
 struct CCP1_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_DF_REG{
 unsigned int reg;
 struct CCP1_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_CTL1_REG{
 unsigned int reg;
 struct CCP1_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_R1_REG{
 unsigned int reg;
 struct CCP1_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_R2_REG{
 unsigned int reg;
 struct CCP1_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_R3_REG{
 unsigned int reg;
 struct CCP1_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_R4_REG{
 unsigned int reg;
 struct CCP1_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_CTL2_REG{
 unsigned int reg;
 struct CCP1_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_CTL3_REG{
 unsigned int reg;
 struct CCP1_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP1_EGIF_REG{
 unsigned int reg;
 struct CCP1_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T2_CNT_REG{
 unsigned int reg;
 struct T2_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T2_CTL1_REG{
 unsigned int reg;
 struct T2_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T2_CTL2_REG{
 unsigned int reg;
 struct T2_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS0:1;
  unsigned int _TXMMS1:1;
  unsigned int _TXMMS2:1;
  unsigned int _TXSMS0:1;
  unsigned int _TXSMS1:1;
  unsigned int _TXSMS2:1;
  unsigned int _TXTS0:1;
  unsigned int _TXTS1:1;
  unsigned int _TXTS2:1;
  unsigned int _TXTS3:1;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T2_PRSC_REG{
 unsigned int reg;
 struct T2_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T2_PPX_REG{
 unsigned int reg;
 struct T2_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T2_UDTIMx_REG{
 unsigned int reg;
 struct T2_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_C1_REG{
 unsigned int reg;
 struct CCP2_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_C2_REG{
 unsigned int reg;
 struct CCP2_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_C3_REG{
 unsigned int reg;
 struct CCP2_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_C4_REG{
 unsigned int reg;
 struct CCP2_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_SRIC_REG{
 unsigned int reg;
 struct CCP2_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_DF_REG{
 unsigned int reg;
 struct CCP2_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_CTL1_REG{
 unsigned int reg;
 struct CCP2_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_R1_REG{
 unsigned int reg;
 struct CCP2_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_R2_REG{
 unsigned int reg;
 struct CCP2_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_R3_REG{
 unsigned int reg;
 struct CCP2_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_R4_REG{
 unsigned int reg;
 struct CCP2_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_CTL2_REG{
 unsigned int reg;
 struct CCP2_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_CTL3_REG{
 unsigned int reg;
 struct CCP2_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP2_EGIF_REG{
 unsigned int reg;
 struct CCP2_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T3_CNT_REG{
 unsigned int reg;
 struct T3_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T3_CTL1_REG{
 unsigned int reg;
 struct T3_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T3_CTL2_REG{
 unsigned int reg;
 struct T3_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS0:1;
  unsigned int _TXMMS1:1;
  unsigned int _TXMMS2:1;
  unsigned int _TXSMS0:1;
  unsigned int _TXSMS1:1;
  unsigned int _TXSMS2:1;
  unsigned int _TXTS0:1;
  unsigned int _TXTS1:1;
  unsigned int _TXTS2:1;
  unsigned int _TXTS3:1;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T3_PRSC_REG{
 unsigned int reg;
 struct T3_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T3_PPX_REG{
 unsigned int reg;
 struct T3_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T3_UDTIMx_REG{
 unsigned int reg;
 struct T3_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_C1_REG{
 unsigned int reg;
 struct CCP3_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_C2_REG{
 unsigned int reg;
 struct CCP3_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_C3_REG{
 unsigned int reg;
 struct CCP3_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_C4_REG{
 unsigned int reg;
 struct CCP3_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_SRIC_REG{
 unsigned int reg;
 struct CCP3_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_DF_REG{
 unsigned int reg;
 struct CCP3_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_CTL1_REG{
 unsigned int reg;
 struct CCP3_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_R1_REG{
 unsigned int reg;
 struct CCP3_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_R2_REG{
 unsigned int reg;
 struct CCP3_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_R3_REG{
 unsigned int reg;
 struct CCP3_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_R4_REG{
 unsigned int reg;
 struct CCP3_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_CTL2_REG{
 unsigned int reg;
 struct CCP3_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_CTL3_REG{
 unsigned int reg;
 struct CCP3_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP3_EGIF_REG{
 unsigned int reg;
 struct CCP3_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T4_CNT_REG{
 unsigned int reg;
 struct T4_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T4_CTL1_REG{
 unsigned int reg;
 struct T4_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T4_CTL2_REG{
 unsigned int reg;
 struct T4_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS0:1;
  unsigned int _TXMMS1:1;
  unsigned int _TXMMS2:1;
  unsigned int _TXSMS0:1;
  unsigned int _TXSMS1:1;
  unsigned int _TXSMS2:1;
  unsigned int _TXTS0:1;
  unsigned int _TXTS1:1;
  unsigned int _TXTS2:1;
  unsigned int _TXTS3:1;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T4_PRSC_REG{
 unsigned int reg;
 struct T4_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T4_PPX_REG{
 unsigned int reg;
 struct T4_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T4_UDTIMx_REG{
 unsigned int reg;
 struct T4_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_C1_REG{
 unsigned int reg;
 struct CCP4_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_C2_REG{
 unsigned int reg;
 struct CCP4_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_C3_REG{
 unsigned int reg;
 struct CCP4_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_C4_REG{
 unsigned int reg;
 struct CCP4_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_SRIC_REG{
 unsigned int reg;
 struct CCP4_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_DF_REG{
 unsigned int reg;
 struct CCP4_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_CTL1_REG{
 unsigned int reg;
 struct CCP4_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_R1_REG{
 unsigned int reg;
 struct CCP4_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_R2_REG{
 unsigned int reg;
 struct CCP4_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_R3_REG{
 unsigned int reg;
 struct CCP4_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_R4_REG{
 unsigned int reg;
 struct CCP4_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_CTL2_REG{
 unsigned int reg;
 struct CCP4_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_CTL3_REG{
 unsigned int reg;
 struct CCP4_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP4_EGIF_REG{
 unsigned int reg;
 struct CCP4_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_CNT_REG{
 unsigned int reg;
 struct T5_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_CNT_REG{
 unsigned int reg;
 struct T6_CNT_BITS{
  unsigned int _TZCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_PPX_REG{
 unsigned int reg;
 struct T5_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_PPZ_REG{
 unsigned int reg;
 struct T6_PPZ_BITS{
  unsigned int _PPZ:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_PRSC_REG{
 unsigned int reg;
 struct T5_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_PRSC_REG{
 unsigned int reg;
 struct T6_PRSC_BITS{
  unsigned int _TZCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_CCR0_REG{
 unsigned int reg;
 struct T5_CCR0_BITS{
  unsigned int _TXCCR0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_CCR1_REG{
 unsigned int reg;
 struct T5_CCR1_BITS{
  unsigned int _TXCCR1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_CCR0_REG{
 unsigned int reg;
 struct T6_CCR0_BITS{
  unsigned int _TZCCR0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_CTL_REG{
 unsigned int reg;
 struct T5_CTL_BITS{
  unsigned int _TXCS:1;
  unsigned int _TXSY:1;
  unsigned int _TXEN:1;
  unsigned int _TXCKBS:4;
  unsigned int _TXDIR:1;
  unsigned int _TXCLK:2;
  unsigned int _TXADAUTO:1;
  unsigned int _TXOFS0:1;
  unsigned int _TXOFS1:1;
  unsigned int _TXCMS:3;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_CTL_REG{
 unsigned int reg;
 struct T6_CTL_BITS{
  unsigned int _TZCS:1;
  unsigned int _TZSY:1;
  unsigned int _TZEN:1;
  unsigned int _TZCKBS:4;
  unsigned int _TZDIR:1;
  unsigned int _TZCLK:2;
  unsigned int _TZADAUTO:1;
  unsigned int _TZOFS0:1;
  unsigned int _TZOFS1:1;
  unsigned int _TZCMS:3;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PDCTL_REG{
 unsigned int reg;
 struct ECCP5_PDCTL_BITS{
  unsigned int _CPE0:1;
  unsigned int _CPE1:1;
  unsigned int _CMPE:1;
  unsigned int _TI0EN:1;
  unsigned int _TI1EN:1;
  unsigned int _TI2EN:1;
  unsigned int :1;
  unsigned int _SMPEN:1;
  unsigned int _RDA:3;
  unsigned int :1;
  unsigned int _CPD:3;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PXASCTL_REG{
 unsigned int reg;
 struct ECCP5_PXASCTL_BITS{
  unsigned int _TXPXPASS:2;
  unsigned int _TZPXPASS:2;
  unsigned int _TXBKINS:1;
  unsigned int _TZBKINS:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_CCTCTL_REG{
 unsigned int reg;
 struct T5_CCTCTL_BITS{
  unsigned int _CCTEN:1;
  unsigned int _CRSET:1;
  unsigned int _CCTSEL:2;
  unsigned int :8;
  unsigned int _TXCKSEL:2;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_CCTCTL_REG{
 unsigned int reg;
 struct T6_CCTCTL_BITS{
  unsigned int _CCTEN:1;
  unsigned int _CRSET:1;
  unsigned int _CCTSEL:2;
  unsigned int :8;
  unsigned int _TZCKSEL:2;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COMH1_REG{
 unsigned int reg;
 struct ECCP5_COMH1_BITS{
  unsigned int _COMH:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COMH2_REG{
 unsigned int reg;
 struct ECCP5_COMH2_BITS{
  unsigned int _COMH:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COMH3_REG{
 unsigned int reg;
 struct ECCP5_COMH3_BITS{
  unsigned int _COMH:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COMH4_REG{
 unsigned int reg;
 struct ECCP5_COMH4_BITS{
  unsigned int _COMH:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COML1_REG{
 unsigned int reg;
 struct ECCP5_COML1_BITS{
  unsigned int _COML:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COML2_REG{
 unsigned int reg;
 struct ECCP5_COML2_BITS{
  unsigned int _COML:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COML3_REG{
 unsigned int reg;
 struct ECCP5_COML3_BITS{
  unsigned int _COML:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_COML4_REG{
 unsigned int reg;
 struct ECCP5_COML4_BITS{
  unsigned int _COML:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_FAUCTL1_REG{
 unsigned int reg;
 struct ECCP5_FAUCTL1_BITS{
  unsigned int _FAUEN:1;
  unsigned int _FLTP:4;
  unsigned int _FLTEN:1;
  unsigned int _FAUIE:1;
  unsigned int _FAUIC:1;
  unsigned int _FAUIF:1;
  unsigned int _FVAL:3;
  unsigned int _FINV:2;
  unsigned int _TRST:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_FAUCTL2_REG{
 unsigned int reg;
 struct ECCP5_FAUCTL2_BITS{
  unsigned int _FAUEN:1;
  unsigned int _FLTP:4;
  unsigned int _FLTEN:1;
  unsigned int _FAUIE:1;
  unsigned int _FAUIC:1;
  unsigned int _FAUIF:1;
  unsigned int _FVAL:3;
  unsigned int _FINV:2;
  unsigned int _TRST:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_FAUCTL3_REG{
 unsigned int reg;
 struct ECCP5_FAUCTL3_BITS{
  unsigned int _FAUEN:1;
  unsigned int _FLTP:4;
  unsigned int _FLTEN:1;
  unsigned int _FAUIE:1;
  unsigned int _FAUIC:1;
  unsigned int _FAUIF:1;
  unsigned int _FVAL:3;
  unsigned int _FINV:2;
  unsigned int _TRST:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_FAUCTL4_REG{
 unsigned int reg;
 struct ECCP5_FAUCTL4_BITS{
  unsigned int _FAUEN:1;
  unsigned int _FLTP:4;
  unsigned int _FLTEN:1;
  unsigned int _FAUIE:1;
  unsigned int _FAUIC:1;
  unsigned int _FAUIF:1;
  unsigned int _FVAL:3;
  unsigned int _FINV:2;
  unsigned int _TRST:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_DITCTL_REG{
 unsigned int reg;
 struct ECCP5_DITCTL_BITS{
  unsigned int _FRCVAL:5;
  unsigned int _DEDEN:1;
  unsigned int _DPEEN:1;
  unsigned int _DCOMEN:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_CCRCTL_REG{
 unsigned int reg;
 struct ECCP5_CCRCTL_BITS{
  unsigned int _TXCCR0SEN:1;
  unsigned int _TXCCR1SEN:1;
  unsigned int _TZCCR0SEN:1;
  unsigned int _TXCCR0SEL:1;
  unsigned int _TXCCR1SEL:1;
  unsigned int _TZCCR0SEL:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_CTL1_REG{
 unsigned int reg;
 struct ECCP5_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_R1_REG{
 unsigned int reg;
 struct ECCP5_R1_BITS{
  unsigned int _ECCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_R2_REG{
 unsigned int reg;
 struct ECCP5_R2_BITS{
  unsigned int _ECCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_R3_REG{
 unsigned int reg;
 struct ECCP5_R3_BITS{
  unsigned int _ECCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_R4_REG{
 unsigned int reg;
 struct ECCP5_R4_BITS{
  unsigned int _ECCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PxUDCTL_REG{
 unsigned int reg;
 struct ECCP5_PxUDCTL_BITS{
  unsigned int _PXUDEN0:1;
  unsigned int _PXUDEN1:1;
  unsigned int _PXUDEVT0:1;
  unsigned int _PXUDEVT1:1;
  unsigned int _PXUDEVT2:1;
  unsigned int _PXUDEVT3:1;
  unsigned int _PXMPEN:1;
  unsigned int _TXUDR:1;
  unsigned int _TXIFUDREN:1;
  unsigned int _TZUDR:1;
  unsigned int _TZIFUDREN:1;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_CTL2_REG{
 unsigned int reg;
 struct ECCP5_CTL2_BITS{
  unsigned int _TXMMS:3;
  unsigned int _TXSMS:3;
  unsigned int _TXTS:3;
  unsigned int _TXMSSYNC:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _TZSMS:3;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PXDTCTL_REG{
 unsigned int reg;
 struct ECCP5_PXDTCTL_BITS{
  unsigned int _PZDC:8;
  unsigned int _PXDC:8;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PWMXOC_REG{
 unsigned int reg;
 struct ECCP5_PWMXOC_BITS{
  unsigned int _PXOC1L:2;
  unsigned int _PXOC1H:2;
  unsigned int _PXOC2L:2;
  unsigned int _PXOC2H:2;
  unsigned int _PXOC3L:2;
  unsigned int _PXOC3H:2;
  unsigned int _PXOC4L:2;
  unsigned int _PXOC4H:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PXATRCTL_REG{
 unsigned int reg;
 struct ECCP5_PXATRCTL_BITS{
  unsigned int :8;
  unsigned int _PXCH1MOD:1;
  unsigned int _PXCH2MOD:1;
  unsigned int _PXCH3MOD:1;
  unsigned int _PXCH4MOD:1;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PXASCTL0_REG{
 unsigned int reg;
 struct ECCP5_PXASCTL0_BITS{
  unsigned int _PXASS1:2;
  unsigned int _PXASS2:2;
  unsigned int _PXASS3:2;
  unsigned int _PXASS4:2;
  unsigned int _PXASE1:1;
  unsigned int _PXASE2:1;
  unsigned int _PXASE3:1;
  unsigned int _PXASE4:1;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_PXASCTL1_REG{
 unsigned int reg;
 struct ECCP5_PXASCTL1_BITS{
  unsigned int _PXSS1L:2;
  unsigned int _PXSS1H:2;
  unsigned int _PXSS2L:2;
  unsigned int _PXSS2H:2;
  unsigned int _PXSS3L:2;
  unsigned int _PXSS3H:2;
  unsigned int _PXSS4L:2;
  unsigned int _PXSS4H:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_ZPDCTL0_REG{
 unsigned int reg;
 struct ECCP5_ZPDCTL0_BITS{
  unsigned int _ZPD1FLAG:1;
  unsigned int _ZPD2FLAG:1;
  unsigned int _ZPD3FLAG:1;
  unsigned int _ZPD4FLAG:1;
  unsigned int _ZPD1TWIN:1;
  unsigned int _ZPD2TWIN:1;
  unsigned int _ZPD3TWIN:1;
  unsigned int _ZPD4TWIN:1;
  unsigned int _ZCLK:4;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_ZPDCTL1_REG{
 unsigned int reg;
 struct ECCP5_ZPDCTL1_BITS{
  unsigned int _ZPD1S:3;
  unsigned int _ZPD2S:3;
  unsigned int _ZPD3S:3;
  unsigned int _ZPD4S:3;
  unsigned int _ZPD1EN:1;
  unsigned int _ZPD2EN:1;
  unsigned int _ZPD3EN:1;
  unsigned int _ZPD4EN:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_ZPDPORT_REG{
 unsigned int reg;
 struct ECCP5_ZPDPORT_BITS{
  unsigned int _ZPORT0:1;
  unsigned int _ZPORT1:1;
  unsigned int _ZPORT2:1;
  unsigned int _ZPORT3:1;
  unsigned int _ZPORT4:1;
  unsigned int _ZPORT5:1;
  unsigned int _ZPORT6:1;
  unsigned int _ZPORT7:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_IE_REG{
 unsigned int reg;
 struct ECCP5_IE_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TZIE:1;
  unsigned int _TXIE:1;
  unsigned int _TZUIE:1;
  unsigned int _TXUIE:1;
  unsigned int _CPIE:1;
  unsigned int _PDIE:1;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_EGIF_REG{
 unsigned int reg;
 struct ECCP5_EGIF_BITS{
  unsigned int _CPIF:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TZIF:1;
  unsigned int _TXIF:1;
  unsigned int _TZUIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PDIF:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T5_UDTIMX_REG{
 unsigned int reg;
 struct T5_UDTIMX_BITS{
  unsigned int _UDCNT:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T6_UDTIMZ_REG{
 unsigned int reg;
 struct T6_UDTIMZ_BITS{
  unsigned int _UDCNT:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_DF_REG{
 unsigned int reg;
 struct ECCP5_DF_BITS{
  unsigned int _CH1DF:1;
  unsigned int _CH2DF:1;
  unsigned int _CH3DF:1;
  unsigned int _CH4DF:1;
  unsigned int _CLSDF:1;
  unsigned int _TRIGDF:1;
  unsigned int _TZUDF:1;
  unsigned int _TXUDF:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_C1_REG{
 unsigned int reg;
 struct ECCP5_C1_BITS{
  unsigned int _ECCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_C2_REG{
 unsigned int reg;
 struct ECCP5_C2_BITS{
  unsigned int _ECCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_C3_REG{
 unsigned int reg;
 struct ECCP5_C3_BITS{
  unsigned int _ECCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_C4_REG{
 unsigned int reg;
 struct ECCP5_C4_BITS{
  unsigned int _ECCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_DE_REG{
 unsigned int reg;
 struct ECCP5_DE_BITS{
  unsigned int _CH1DE:1;
  unsigned int _CH2DE:1;
  unsigned int _CH3DE:1;
  unsigned int _CH4DE:1;
  unsigned int _CLSDE:1;
  unsigned int _TXTDE:1;
  unsigned int _TZUDE:1;
  unsigned int _TXUDE:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_SRIC_REG{
 unsigned int reg;
 struct ECCP5_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TZIC:1;
  unsigned int _TXIC:1;
  unsigned int _TZUIC:1;
  unsigned int _TXUIC:1;
  unsigned int _CPIC:1;
  unsigned int _PDIC:1;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECCP5_CTL3_REG{
 unsigned int reg;
 struct ECCP5_CTL3_BITS{
  unsigned int _PXSPMST:1;
  unsigned int _TUNITE:1;
  unsigned int _PXRSEN:1;
  unsigned int _COMBEN:1;
  unsigned int _COMINV:2;
  unsigned int _CAPTST:1;
  unsigned int :2;
  unsigned int _CH0HM:1;
  unsigned int _CH1HM:1;
  unsigned int _CH2HM:1;
  unsigned int _CH3HM:1;
  unsigned int _TRGSEL:2;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union QEI0_CTL0_REG{
 unsigned int reg;
 struct QEI0_CTL0_BITS{
  unsigned int _TXDIR:1;
  unsigned int _TXDIROUT:1;
  unsigned int _INDEX:1;
  unsigned int _TXCS:1;
  unsigned int _INDRES:1;
  unsigned int _QEIMOD:3;
  unsigned int _CNTERRIF:1;
  unsigned int _PHEIF:1;
  unsigned int _TXIF:1;
  unsigned int _LPCLK:1;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union QEI0_CTL1_REG{
 unsigned int reg;
 struct QEI0_CTL1_BITS{
  unsigned int _SWPAB:1;
  unsigned int _QEICK:3;
  unsigned int _QEIOUT:1;
  unsigned int _QEICLK:2;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T7_CNT_REG{
 unsigned int reg;
 struct T7_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T7_PPX_REG{
 unsigned int reg;
 struct T7_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T7_PRSC_REG{
 unsigned int reg;
 struct T7_PRSC_BITS{
  unsigned int _TXPRSC:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union QEI0_DIER_REG{
 unsigned int reg;
 struct QEI0_DIER_BITS{
  unsigned int _CNTERRIE:1;
  unsigned int _PHEIE:1;
  unsigned int _TXIE:1;
  unsigned int _CNTERRIC:1;
  unsigned int _PHEIC:1;
  unsigned int _TXIC:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_CTL0_REG{
 unsigned int reg;
 struct ADC0_CTL0_BITS{
  unsigned int _EN:1;
  unsigned int _CLKS:2;
  unsigned int _LR:1;
  unsigned int _TP:3;
  unsigned int _TPOEN:1;
  unsigned int _ADCCLKS:3;
  unsigned int :2;
  unsigned int _NDMAEN:1;
  unsigned int _TRIMIBIAS:1;
  unsigned int _BOSSSEL:1;
  unsigned int _BOSSSELCOMP:1;
  unsigned int _SCANEN:1;
  unsigned int _CONT:1;
  unsigned int _HPAUTO:1;
  unsigned int _DSEN:1;
  unsigned int _HPDSEN:1;
  unsigned int _HP0DMAEN:1;
  unsigned int _HP1DMAEN:1;
  unsigned int _HP2DMAEN:1;
  unsigned int _HP3DMAEN:1;
  unsigned int _DSNUM:3;
  unsigned int _WDEN:1;
  unsigned int _HPWDEN:1;
  unsigned int _WDSCH:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_CTL1_REG{
 unsigned int reg;
 struct ADC0_CTL1_BITS{
  unsigned int :2;
  unsigned int _START:1;
  unsigned int _HPSTART:1;
  unsigned int _NCH:7;
  unsigned int _EXTEN:1;
  unsigned int :5;
  unsigned int _REF0:1;
  unsigned int _REF1:1;
  unsigned int _REF2:1;
  unsigned int _HCH:7;
  unsigned int _HPEXTEN:1;
  unsigned int _DOUMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_SCANSQ0_REG{
 unsigned int reg;
 struct ADC0_SCANSQ0_BITS{
  unsigned int _SSQ0:8;
  unsigned int _SSQ1:8;
  unsigned int _SSQ2:8;
  unsigned int _SSQ3:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_SCANSQ1_REG{
 unsigned int reg;
 struct ADC0_SCANSQ1_BITS{
  unsigned int _SSQ4:8;
  unsigned int _SSQ5:8;
  unsigned int _SSQ6:8;
  unsigned int _SSQ7:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_SCANSQ2_REG{
 unsigned int reg;
 struct ADC0_SCANSQ2_BITS{
  unsigned int _SSQ8:8;
  unsigned int _SSQ9:8;
  unsigned int _SSQ10:8;
  unsigned int _SSQ11:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_SCANSQ3_REG{
 unsigned int reg;
 struct ADC0_SCANSQ3_BITS{
  unsigned int _SSQ12:8;
  unsigned int _SSQ13:8;
  unsigned int _SSQ14:8;
  unsigned int _SSQ15:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HSCANSQ_REG{
 unsigned int reg;
 struct ADC0_HSCANSQ_BITS{
  unsigned int _HSSQ0:8;
  unsigned int _HSSQ1:8;
  unsigned int _HSSQ2:8;
  unsigned int _HSSQ3:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_WDH_REG{
 unsigned int reg;
 struct ADC0_WDH_BITS{
  unsigned int _WDH:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_WDL_REG{
 unsigned int reg;
 struct ADC0_WDL_BITS{
  unsigned int _WDL:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_DATA_REG{
 unsigned int reg;
 struct ADC0_DATA_BITS{
  unsigned int _DATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDATA0_REG{
 unsigned int reg;
 struct ADC0_HPDATA0_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDATA1_REG{
 unsigned int reg;
 struct ADC0_HPDATA1_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDATA2_REG{
 unsigned int reg;
 struct ADC0_HPDATA2_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDATA3_REG{
 unsigned int reg;
 struct ADC0_HPDATA3_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDOFF0_REG{
 unsigned int reg;
 struct ADC0_HPDOFF0_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDOFF1_REG{
 unsigned int reg;
 struct ADC0_HPDOFF1_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDOFF2_REG{
 unsigned int reg;
 struct ADC0_HPDOFF2_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_HPDOFF3_REG{
 unsigned int reg;
 struct ADC0_HPDOFF3_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_STATE_REG{
 unsigned int reg;
 struct ADC0_STATE_BITS{
  unsigned int _STARTIF:1;
  unsigned int _HPSTARTIF:1;
  unsigned int _ENDIF:1;
  unsigned int _HPENDIF:1;
  unsigned int _WDIF:1;
  unsigned int _ENDIC:1;
  unsigned int _HPENDIC:1;
  unsigned int _WDIC:1;
  unsigned int _ENDIE:1;
  unsigned int _HPENDIE:1;
  unsigned int _WDIE:1;
  unsigned int _EOCIF:1;
  unsigned int _EOCIC:1;
  unsigned int _EOCIE:1;
  unsigned int _CCR0N:1;
  unsigned int _CCR0H:1;
  unsigned int _CCR1N:1;
  unsigned int _CCR1H:1;
  unsigned int _CCR2N:1;
  unsigned int _CCR2H:1;
  unsigned int :6;
  unsigned int _TSSELTOADCIS0:1;
  unsigned int _TRIMIBIASOPA:1;
  unsigned int _TSSELTOADCIS1:1;
  unsigned int _TSSELTOADCIS2:1;
  unsigned int _TRIMERROR:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_DELAY_REG{
 unsigned int reg;
 struct ADC0_DELAY_BITS{
  unsigned int _FDELAY:6;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC0_SCANCTL_REG{
 unsigned int reg;
 struct ADC0_SCANCTL_BITS{
  unsigned int _SLEN:4;
  unsigned int _HSLEN:2;
  unsigned int :10;
  unsigned int _WDCH:7;
  unsigned int :1;
  unsigned int _SAMSEL:4;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_CTL0_REG{
 unsigned int reg;
 struct ADC1_CTL0_BITS{
  unsigned int _EN:1;
  unsigned int _CLKS:2;
  unsigned int _LR:1;
  unsigned int _TP:3;
  unsigned int _TPOEN:1;
  unsigned int _ADCCLKS:3;
  unsigned int :2;
  unsigned int _NDMAEN:1;
  unsigned int _TRIMIBIAS:1;
  unsigned int _BOSSSEL:1;
  unsigned int _BOSSSELCOMP:1;
  unsigned int _SCANEN:1;
  unsigned int _CONT:1;
  unsigned int _HPAUTO:1;
  unsigned int _DSEN:1;
  unsigned int _HPDSEN:1;
  unsigned int _HP0DMAEN:1;
  unsigned int _HP1DMAEN:1;
  unsigned int _HP2DMAEN:1;
  unsigned int _HP3DMAEN:1;
  unsigned int _DSNUM:3;
  unsigned int _WDEN:1;
  unsigned int _HPWDEN:1;
  unsigned int _WDSCH:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_CTL1_REG{
 unsigned int reg;
 struct ADC1_CTL1_BITS{
  unsigned int :2;
  unsigned int _START:1;
  unsigned int _HPSTART:1;
  unsigned int _NCH:7;
  unsigned int _EXTEN:1;
  unsigned int :5;
  unsigned int _REF0:1;
  unsigned int _REF1:1;
  unsigned int _REF2:1;
  unsigned int _HCH:7;
  unsigned int _HPEXTEN:1;
  unsigned int _DOUMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_SCANSQ0_REG{
 unsigned int reg;
 struct ADC1_SCANSQ0_BITS{
  unsigned int _SSQ0:8;
  unsigned int _SSQ1:8;
  unsigned int _SSQ2:8;
  unsigned int _SSQ3:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_SCANSQ1_REG{
 unsigned int reg;
 struct ADC1_SCANSQ1_BITS{
  unsigned int _SSQ4:8;
  unsigned int _SSQ5:8;
  unsigned int _SSQ6:8;
  unsigned int _SSQ7:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_SCANSQ2_REG{
 unsigned int reg;
 struct ADC1_SCANSQ2_BITS{
  unsigned int _SSQ8:8;
  unsigned int _SSQ9:8;
  unsigned int _SSQ10:8;
  unsigned int _SSQ11:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_SCANSQ3_REG{
 unsigned int reg;
 struct ADC1_SCANSQ3_BITS{
  unsigned int _SSQ12:8;
  unsigned int _SSQ13:8;
  unsigned int _SSQ14:8;
  unsigned int _SSQ15:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HSCANSQ_REG{
 unsigned int reg;
 struct ADC1_HSCANSQ_BITS{
  unsigned int _HSSQ0:8;
  unsigned int _HSSQ1:8;
  unsigned int _HSSQ2:8;
  unsigned int _HSSQ3:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_WDH_REG{
 unsigned int reg;
 struct ADC1_WDH_BITS{
  unsigned int _WDH:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_WDL_REG{
 unsigned int reg;
 struct ADC1_WDL_BITS{
  unsigned int _WDL:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_DATA_REG{
 unsigned int reg;
 struct ADC1_DATA_BITS{
  unsigned int _DATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDATA0_REG{
 unsigned int reg;
 struct ADC1_HPDATA0_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDATA1_REG{
 unsigned int reg;
 struct ADC1_HPDATA1_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDATA2_REG{
 unsigned int reg;
 struct ADC1_HPDATA2_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDATA3_REG{
 unsigned int reg;
 struct ADC1_HPDATA3_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDOFF0_REG{
 unsigned int reg;
 struct ADC1_HPDOFF0_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDOFF1_REG{
 unsigned int reg;
 struct ADC1_HPDOFF1_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDOFF2_REG{
 unsigned int reg;
 struct ADC1_HPDOFF2_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_HPDOFF3_REG{
 unsigned int reg;
 struct ADC1_HPDOFF3_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_STATE_REG{
 unsigned int reg;
 struct ADC1_STATE_BITS{
  unsigned int _STARTIF:1;
  unsigned int _HPSTARTIF:1;
  unsigned int _ENDIF:1;
  unsigned int _HPENDIF:1;
  unsigned int _WDIF:1;
  unsigned int _ENDIC:1;
  unsigned int _HPENDIC:1;
  unsigned int _WDIC:1;
  unsigned int _ENDIE:1;
  unsigned int _HPENDIE:1;
  unsigned int _WDIE:1;
  unsigned int _EOCIF:1;
  unsigned int _EOCIC:1;
  unsigned int _EOCIE:1;
  unsigned int _CCR0N:1;
  unsigned int _CCR0H:1;
  unsigned int _CCR1N:1;
  unsigned int _CCR1H:1;
  unsigned int _CCR2N:1;
  unsigned int _CCR2H:1;
  unsigned int _CCR3N:1;
  unsigned int _CCR3H:1;
  unsigned int _CCR4N:1;
  unsigned int _CCR4H:1;
  unsigned int _CCR5N:1;
  unsigned int _CCR5H:1;
  unsigned int _TSSELTOADCIS0:1;
  unsigned int _TRIMIBIASOPA:1;
  unsigned int _TSSELTOADCIS1:1;
  unsigned int _TSSELTOADCIS2:1;
  unsigned int _TRIMERROR:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC1_SCANCTL_REG{
 unsigned int reg;
 struct ADC1_SCANCTL_BITS{
  unsigned int _SLEN:4;
  unsigned int _HSLEN:2;
  unsigned int :10;
  unsigned int _WDCH:7;
  unsigned int :1;
  unsigned int _SAMSEL:4;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_CTL0_REG{
 unsigned int reg;
 struct ADC2_CTL0_BITS{
  unsigned int _EN:1;
  unsigned int _CLKS:2;
  unsigned int _LR:1;
  unsigned int _TP:3;
  unsigned int _TPOEN:1;
  unsigned int _ADCCLKS:3;
  unsigned int :2;
  unsigned int _NDMAEN:1;
  unsigned int _TRIMIBIAS:1;
  unsigned int _BOSSSEL:1;
  unsigned int _BOSSSELCOMP:1;
  unsigned int _SCANEN:1;
  unsigned int _CONT:1;
  unsigned int _HPAUTO:1;
  unsigned int _DSEN:1;
  unsigned int _HPDSEN:1;
  unsigned int _HP0DMAEN:1;
  unsigned int _HP1DMAEN:1;
  unsigned int _HP2DMAEN:1;
  unsigned int _HP3DMAEN:1;
  unsigned int _DSNUM:3;
  unsigned int _WDEN:1;
  unsigned int _HPWDEN:1;
  unsigned int _WDSCH:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_CTL1_REG{
 unsigned int reg;
 struct ADC2_CTL1_BITS{
  unsigned int :2;
  unsigned int _START:1;
  unsigned int _HPSTART:1;
  unsigned int _NCH:7;
  unsigned int _EXTEN:1;
  unsigned int :5;
  unsigned int _REF0:1;
  unsigned int _REF1:1;
  unsigned int _REF2:1;
  unsigned int _HCH:7;
  unsigned int _HPEXTEN:1;
  unsigned int _DOUMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_SCANSQ0_REG{
 unsigned int reg;
 struct ADC2_SCANSQ0_BITS{
  unsigned int _SSQ0:8;
  unsigned int _SSQ1:8;
  unsigned int _SSQ2:8;
  unsigned int _SSQ3:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_SCANSQ1_REG{
 unsigned int reg;
 struct ADC2_SCANSQ1_BITS{
  unsigned int _SSQ4:8;
  unsigned int _SSQ5:8;
  unsigned int _SSQ6:8;
  unsigned int _SSQ7:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_SCANSQ2_REG{
 unsigned int reg;
 struct ADC2_SCANSQ2_BITS{
  unsigned int _SSQ8:8;
  unsigned int _SSQ9:8;
  unsigned int _SSQ10:8;
  unsigned int _SSQ11:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_SCANSQ3_REG{
 unsigned int reg;
 struct ADC2_SCANSQ3_BITS{
  unsigned int _SSQ12:8;
  unsigned int _SSQ13:8;
  unsigned int _SSQ14:8;
  unsigned int _SSQ15:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HSCANSQ_REG{
 unsigned int reg;
 struct ADC2_HSCANSQ_BITS{
  unsigned int _HSSQ0:8;
  unsigned int _HSSQ1:8;
  unsigned int _HSSQ2:8;
  unsigned int _HSSQ3:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_WDH_REG{
 unsigned int reg;
 struct ADC2_WDH_BITS{
  unsigned int _WDH:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_WDL_REG{
 unsigned int reg;
 struct ADC2_WDL_BITS{
  unsigned int _WDL:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_DATA_REG{
 unsigned int reg;
 struct ADC2_DATA_BITS{
  unsigned int _DATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDATA0_REG{
 unsigned int reg;
 struct ADC2_HPDATA0_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDATA1_REG{
 unsigned int reg;
 struct ADC2_HPDATA1_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDATA2_REG{
 unsigned int reg;
 struct ADC2_HPDATA2_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDATA3_REG{
 unsigned int reg;
 struct ADC2_HPDATA3_BITS{
  unsigned int _HPDATA:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDOFF0_REG{
 unsigned int reg;
 struct ADC2_HPDOFF0_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDOFF1_REG{
 unsigned int reg;
 struct ADC2_HPDOFF1_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDOFF2_REG{
 unsigned int reg;
 struct ADC2_HPDOFF2_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_HPDOFF3_REG{
 unsigned int reg;
 struct ADC2_HPDOFF3_BITS{
  unsigned int _HPDOFF:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_STATE_REG{
 unsigned int reg;
 struct ADC2_STATE_BITS{
  unsigned int _STARTIF:1;
  unsigned int _HPSTARTIF:1;
  unsigned int _ENDIF:1;
  unsigned int _HPENDIF:1;
  unsigned int _WDIF:1;
  unsigned int _ENDIC:1;
  unsigned int _HPENDIC:1;
  unsigned int _WDIC:1;
  unsigned int _ENDIE:1;
  unsigned int _HPENDIE:1;
  unsigned int _WDIE:1;
  unsigned int _EOCIF:1;
  unsigned int _EOCIC:1;
  unsigned int _EOCIE:1;
  unsigned int _CCR0N:1;
  unsigned int _CCR0H:1;
  unsigned int _CCR1N:1;
  unsigned int _CCR1H:1;
  unsigned int _CCR2N:1;
  unsigned int _CCR2H:1;
  unsigned int _CCR3N:1;
  unsigned int _CCR3H:1;
  unsigned int _CCR4N:1;
  unsigned int _CCR4H:1;
  unsigned int _CCR5N:1;
  unsigned int _CCR5H:1;
  unsigned int _TSSELTOADCIS0:1;
  unsigned int _TRIMIBIASOPA:1;
  unsigned int _TSSELTOADCIS1:1;
  unsigned int _TSSELTOADCIS2:1;
  unsigned int _TRIMERROR:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ADC2_SCANCTL_REG{
 unsigned int reg;
 struct ADC2_SCANCTL_BITS{
  unsigned int _SLEN:4;
  unsigned int _HSLEN:2;
  unsigned int :10;
  unsigned int _WDCH:7;
  unsigned int :1;
  unsigned int _SAMSEL:4;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC0_CTL_REG{
 unsigned int reg;
 struct DAC0_CTL_BITS{
  unsigned int _EN:1;
  unsigned int _DE:1;
  unsigned int :1;
  unsigned int _TRIGEN:1;
  unsigned int _TREVT:4;
  unsigned int _WAVE:2;
  unsigned int _MAS:4;
  unsigned int _SWTRIG:1;
  unsigned int _DF:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC0_DAHD_REG{
 unsigned int reg;
 struct DAC0_DAHD_BITS{
  unsigned int _DAHD:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC0_DATA_REG{
 unsigned int reg;
 struct DAC0_DATA_BITS{
  unsigned int _DATA:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC0_CTL1_REG{
 unsigned int reg;
 struct DAC0_CTL1_BITS{
  unsigned int _SEL:1;
  unsigned int _RFS:2;
  unsigned int :1;
  unsigned int _CLK:2;
  unsigned int _BUFEN:1;
  unsigned int :2;
  unsigned int _CLKDIV:3;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC0_CAL_REG{
 unsigned int reg;
 struct DAC0_CAL_BITS{
  unsigned int _TPEN:1;
  unsigned int _TP:2;
  unsigned int :10;
  unsigned int _TRIMLO:1;
  unsigned int _TRIMHI:1;
  unsigned int _TRIMSTATE:1;
  unsigned int _TRIMN:6;
  unsigned int _TRIMNPOL:1;
  unsigned int :1;
  unsigned int _TRIMP:6;
  unsigned int _TRIMPPOL:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC1_CTL_REG{
 unsigned int reg;
 struct DAC1_CTL_BITS{
  unsigned int _EN:1;
  unsigned int _DE:1;
  unsigned int :1;
  unsigned int _TRIGEN:1;
  unsigned int _TREVT:4;
  unsigned int _WAVE:2;
  unsigned int _MAS:4;
  unsigned int _SWTRIG:1;
  unsigned int _DF:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC1_DAHD_REG{
 unsigned int reg;
 struct DAC1_DAHD_BITS{
  unsigned int _DAHD:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC1_DATA_REG{
 unsigned int reg;
 struct DAC1_DATA_BITS{
  unsigned int _DATA:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC1_CTL1_REG{
 unsigned int reg;
 struct DAC1_CTL1_BITS{
  unsigned int _SEL:1;
  unsigned int _RFS:2;
  unsigned int :1;
  unsigned int _CLK:2;
  unsigned int _BUFEN:1;
  unsigned int :2;
  unsigned int _CLKDIV:3;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC1_CAL_REG{
 unsigned int reg;
 struct DAC1_CAL_BITS{
  unsigned int _TPEN:1;
  unsigned int _TP:2;
  unsigned int :10;
  unsigned int _TRIMLO:1;
  unsigned int _TRIMHI:1;
  unsigned int _TRIMSTATE:1;
  unsigned int _TRIMN:6;
  unsigned int _TRIMNPOL:1;
  unsigned int :1;
  unsigned int _TRIMP:6;
  unsigned int _TRIMPPOL:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC2_CTL_REG{
 unsigned int reg;
 struct DAC2_CTL_BITS{
  unsigned int _EN:1;
  unsigned int _DE:1;
  unsigned int :1;
  unsigned int _TRIGEN:1;
  unsigned int _TREVT:4;
  unsigned int _WAVE:2;
  unsigned int _MAS:4;
  unsigned int _SWTRIG:1;
  unsigned int _DF:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC2_DAHD_REG{
 unsigned int reg;
 struct DAC2_DAHD_BITS{
  unsigned int _DAHD:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC2_DATA_REG{
 unsigned int reg;
 struct DAC2_DATA_BITS{
  unsigned int _DATA:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC2_CTL1_REG{
 unsigned int reg;
 struct DAC2_CTL1_BITS{
  unsigned int _SEL:1;
  unsigned int _RFS:2;
  unsigned int :1;
  unsigned int _CLK:2;
  unsigned int _BUFEN:1;
  unsigned int :2;
  unsigned int _CLKDIV:3;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC2_CAL_REG{
 unsigned int reg;
 struct DAC2_CAL_BITS{
  unsigned int _TPEN:1;
  unsigned int _TP:2;
  unsigned int :10;
  unsigned int _TRIMLO:1;
  unsigned int _TRIMHI:1;
  unsigned int _TRIMSTATE:1;
  unsigned int _TRIMN:6;
  unsigned int _TRIMNPOL:1;
  unsigned int :1;
  unsigned int _TRIMP:6;
  unsigned int _TRIMPPOL:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC3_CTL_REG{
 unsigned int reg;
 struct DAC3_CTL_BITS{
  unsigned int _EN:1;
  unsigned int _DE:1;
  unsigned int :1;
  unsigned int _TRIGEN:1;
  unsigned int _TREVT:4;
  unsigned int _WAVE:2;
  unsigned int _MAS:4;
  unsigned int _SWTRIG:1;
  unsigned int _DF:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC3_DAHD_REG{
 unsigned int reg;
 struct DAC3_DAHD_BITS{
  unsigned int _DAHD:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC3_DATA_REG{
 unsigned int reg;
 struct DAC3_DATA_BITS{
  unsigned int _DATA:12;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC3_CTL1_REG{
 unsigned int reg;
 struct DAC3_CTL1_BITS{
  unsigned int _SEL:1;
  unsigned int _RFS:2;
  unsigned int :1;
  unsigned int _CLK:2;
  unsigned int _BUFEN:1;
  unsigned int :2;
  unsigned int _CLKDIV:3;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DAC3_CAL_REG{
 unsigned int reg;
 struct DAC3_CAL_BITS{
  unsigned int _TPEN:1;
  unsigned int _TP:2;
  unsigned int :10;
  unsigned int _TRIMLO:1;
  unsigned int _TRIMHI:1;
  unsigned int _TRIMSTATE:1;
  unsigned int _TRIMN:6;
  unsigned int _TRIMNPOL:1;
  unsigned int :1;
  unsigned int _TRIMP:6;
  unsigned int _TRIMPPOL:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP_CTL0_REG{
 unsigned int reg;
 struct CMP_CTL0_BITS{
  unsigned int :1;
  unsigned int _POL:1;
  unsigned int _WINEN:1;
  unsigned int _FLTEN:1;
  unsigned int _FLTCNT:3;
  unsigned int _WINCLKSEL:1;
  unsigned int _FLTDIV:8;
  unsigned int _FLTCS:2;
  unsigned int _IFREN:1;
  unsigned int _IFFEN:1;
  unsigned int :4;
  unsigned int _NMOD:4;
  unsigned int _PMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP_CTL1_REG{
 unsigned int reg;
 struct CMP_CTL1_BITS{
  unsigned int :1;
  unsigned int _POL:1;
  unsigned int _WINEN:1;
  unsigned int _FLTEN:1;
  unsigned int _FLTCNT:3;
  unsigned int _WINCLKSEL:1;
  unsigned int _FLTDIV:8;
  unsigned int _FLTCS:2;
  unsigned int _IFREN:1;
  unsigned int _IFFEN:1;
  unsigned int :4;
  unsigned int _NMOD:4;
  unsigned int _PMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP_CTL2_REG{
 unsigned int reg;
 struct CMP_CTL2_BITS{
  unsigned int :1;
  unsigned int _POL:1;
  unsigned int _WINEN:1;
  unsigned int _FLTEN:1;
  unsigned int _FLTCNT:3;
  unsigned int _WINCLKSEL:1;
  unsigned int _FLTDIV:8;
  unsigned int _FLTCS:2;
  unsigned int _IFREN:1;
  unsigned int _IFFEN:1;
  unsigned int :4;
  unsigned int _NMOD:4;
  unsigned int _PMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP_CTL3_REG{
 unsigned int reg;
 struct CMP_CTL3_BITS{
  unsigned int _EN:1;
  unsigned int _POL:1;
  unsigned int _WINEN:1;
  unsigned int _FLTEN:1;
  unsigned int _FLTCNT:3;
  unsigned int _WINCLKSEL:1;
  unsigned int _FLTDIV:8;
  unsigned int _FLTCS:2;
  unsigned int _IFREN:1;
  unsigned int _IFFEN:1;
  unsigned int :3;
  unsigned int _CMP3PSEL:1;
  unsigned int :1;
  unsigned int _NMOD:3;
  unsigned int _PMOD:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP_CTL4_REG{
 unsigned int reg;
 struct CMP_CTL4_BITS{
  unsigned int _C0EN:1;
  unsigned int _C1EN:1;
  unsigned int _C2EN:1;
  unsigned int _FLTINSEL:1;
  unsigned int _BEMFEN:1;
  unsigned int _HALLSEL:1;
  unsigned int _DELAYVOL:2;
  unsigned int _CMPOUTDSEL:2;
  unsigned int _IOEN:1;
  unsigned int :1;
  unsigned int _C0IE:1;
  unsigned int _C1IE:1;
  unsigned int _C2IE:1;
  unsigned int _C3IE:1;
  unsigned int _C0IC:1;
  unsigned int _C1IC:1;
  unsigned int _C2IC:1;
  unsigned int _C3IC:1;
  unsigned int _CMPOUTASEL:2;
  unsigned int _PWMCMP:1;
  unsigned int _CIFMS:1;
  unsigned int _C0IF:1;
  unsigned int _C1IF:1;
  unsigned int _C2IF:1;
  unsigned int _C3IF:1;
  unsigned int _C0OUT:1;
  unsigned int _C1OUT:1;
  unsigned int _C2OUT:1;
  unsigned int _C3OUT:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP_CTL5_REG{
 unsigned int reg;
 struct CMP_CTL5_BITS{
  unsigned int _C0TRGSEL:2;
  unsigned int _C1TRGSEL:2;
  unsigned int _C2TRGSEL:2;
  unsigned int _C3TRGSEL:2;
  unsigned int _CMPLPEN:1;
  unsigned int :19;
  unsigned int _C0PSEL:2;
  unsigned int _MOTORSEL:1;
  unsigned int _INSCM:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP0_TRIM0_REG{
 unsigned int reg;
 struct CMP0_TRIM0_BITS{
  unsigned int _C0TRIMNPOL:1;
  unsigned int _C0TRIMN:6;
  unsigned int _C0TRIMPPOL:1;
  unsigned int _C0TRIMP:6;
  unsigned int :16;
  unsigned int _CMPTRIMHIGHEN:1;
  unsigned int _CMPTRIMLOWEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP0_TRIM1_REG{
 unsigned int reg;
 struct CMP0_TRIM1_BITS{
  unsigned int _C1TRIMNPOL:1;
  unsigned int _C1TRIMN:6;
  unsigned int _C1TRIMPPOL:1;
  unsigned int _C1TRIMP:6;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP0_TRIM2_REG{
 unsigned int reg;
 struct CMP0_TRIM2_BITS{
  unsigned int _C2TRIMNPOL:1;
  unsigned int _C2TRIMN:6;
  unsigned int _C2TRIMPPOL:1;
  unsigned int _C2TRIMP:6;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CMP0_TRIM3_REG{
 unsigned int reg;
 struct CMP0_TRIM3_BITS{
  unsigned int _C3TRIMNPOL:1;
  unsigned int _C3TRIMN:6;
  unsigned int _C3TRIMPPOL:1;
  unsigned int _C3TRIMP:6;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T0_CNT_REG{
 unsigned int reg;
 struct T0_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T0_CTL1_REG{
 unsigned int reg;
 struct T0_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T0_CTL2_REG{
 unsigned int reg;
 struct T0_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS0:1;
  unsigned int _TXMMS1:1;
  unsigned int _TXMMS2:1;
  unsigned int _TXSMS0:1;
  unsigned int _TXSMS1:1;
  unsigned int _TXSMS2:1;
  unsigned int _TXTS0:1;
  unsigned int _TXTS1:1;
  unsigned int _TXTS2:1;
  unsigned int _TXTS3:1;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T0_PRSC_REG{
 unsigned int reg;
 struct T0_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T0_PPX_REG{
 unsigned int reg;
 struct T0_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T0_UDTIMx_REG{
 unsigned int reg;
 struct T0_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_C1_REG{
 unsigned int reg;
 struct CCP0_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_C2_REG{
 unsigned int reg;
 struct CCP0_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_C3_REG{
 unsigned int reg;
 struct CCP0_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_C4_REG{
 unsigned int reg;
 struct CCP0_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_SRIC_REG{
 unsigned int reg;
 struct CCP0_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_DF_REG{
 unsigned int reg;
 struct CCP0_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_CTL1_REG{
 unsigned int reg;
 struct CCP0_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_R1_REG{
 unsigned int reg;
 struct CCP0_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_R2_REG{
 unsigned int reg;
 struct CCP0_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_R3_REG{
 unsigned int reg;
 struct CCP0_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_R4_REG{
 unsigned int reg;
 struct CCP0_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_CTL2_REG{
 unsigned int reg;
 struct CCP0_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_CTL3_REG{
 unsigned int reg;
 struct CCP0_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP0_EGIF_REG{
 unsigned int reg;
 struct CCP0_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_CTLR_REG{
 unsigned int reg;
 struct USART0_CTLR_BITS{
  unsigned int _USARTEN:1;
  unsigned int _BRCKS:2;
  unsigned int _SCKPS:1;
  unsigned int _TCONV:1;
  unsigned int _RCONV:1;
  unsigned int _DINV:1;
  unsigned int _WUEN:1;
  unsigned int _CSRS:1;
  unsigned int _ADREN:1;
  unsigned int :1;
  unsigned int _ABRDEN:1;
  unsigned int _RIDLES:1;
  unsigned int _SENDB:1;
  unsigned int _SYNC:1;
  unsigned int _TXEN:1;
  unsigned int _RXEN:1;
  unsigned int _TIDLEEN:1;
  unsigned int _STPW:1;
  unsigned int _TX9SEL:1;
  unsigned int _PARM:1;
  unsigned int _DT9EN:1;
  unsigned int _TRGSEL:2;
  unsigned int _CTSE:1;
  unsigned int _RTSE:1;
  unsigned int _BKPWS:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _IRDAEN:1;
  unsigned int _RESHD:1;
  unsigned int _SLMEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_BRGR_REG{
 unsigned int reg;
 struct USART0_BRGR_BITS{
  unsigned int _BRGM:16;
  unsigned int _BRGF1:4;
  unsigned int _BRGF2:4;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_STR_REG{
 unsigned int reg;
 struct USART0_STR_BITS{
  unsigned int _OVFEIF:1;
  unsigned int _PAREIF:1;
  unsigned int _FREIF:1;
  unsigned int _BRIF:1;
  unsigned int _ABTOIF:1;
  unsigned int _WUIF:1;
  unsigned int _TEIF:1;
  unsigned int _REIF:1;
  unsigned int _CTSIF:1;
  unsigned int _RCFR:1;
  unsigned int _TXFR:1;
  unsigned int _RDRIF:1;
  unsigned int _TFEIF:1;
  unsigned int _TXEIF:1;
  unsigned int _UADMIF:1;
  unsigned int _IDLFIF:1;
  unsigned int _OVFEIC:1;
  unsigned int _PAREIC:1;
  unsigned int _FREIC:1;
  unsigned int _BRIC:1;
  unsigned int _ABTOIC:1;
  unsigned int _WUIC:1;
  unsigned int _TEIC:1;
  unsigned int _REIC:1;
  unsigned int _CTSIC:1;
  unsigned int _UADMIC:1;
  unsigned int _IDLEIC:1;
  unsigned int :1;
  unsigned int _CTSSEL:1;
  unsigned int _RXDSEL:1;
  unsigned int _TX1SEL:1;
  unsigned int _TX0SEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_TBUFR_REG{
 unsigned int reg;
 struct USART0_TBUFR_BITS{
  unsigned int _TBUF:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_RBUFR_REG{
 unsigned int reg;
 struct USART0_RBUFR_BITS{
  unsigned int _RBUF:9;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_U7816R_REG{
 unsigned int reg;
 struct USART0_U7816R_BITS{
  unsigned int _7816EN:1;
  unsigned int _CLKOUT:1;
  unsigned int _ERSW:2;
  unsigned int _PSEL:1;
  unsigned int _BGTEN:1;
  unsigned int :2;
  unsigned int _TREPEN:1;
  unsigned int _RREPEN:1;
  unsigned int _TXRE:2;
  unsigned int _RXRE:2;
  unsigned int _TREPMS:1;
  unsigned int _CLKDIV:8;
  unsigned int :1;
  unsigned int _EGT:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_IER_REG{
 unsigned int reg;
 struct USART0_IER_BITS{
  unsigned int _OVFEIE:1;
  unsigned int _PAREIE:1;
  unsigned int _FREIE:1;
  unsigned int _BRIE:1;
  unsigned int _ABTOIE:1;
  unsigned int _WUIE:1;
  unsigned int _TEIE:1;
  unsigned int _REIE:1;
  unsigned int _CTSIE:1;
  unsigned int _RDRIE:1;
  unsigned int _TFEIE:1;
  unsigned int _TXEIE:1;
  unsigned int _IDLEIE:1;
  unsigned int :3;
  unsigned int _URCDE:1;
  unsigned int _UTXDE:1;
  unsigned int _UADMIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART0_ADM_REG{
 unsigned int reg;
 struct USART0_ADM_BITS{
  unsigned int _ADM:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_CTLR_REG{
 unsigned int reg;
 struct USART1_CTLR_BITS{
  unsigned int _USARTEN:1;
  unsigned int _BRCKS:2;
  unsigned int _SCKPS:1;
  unsigned int _TCONV:1;
  unsigned int _RCONV:1;
  unsigned int _DINV:1;
  unsigned int _WUEN:1;
  unsigned int _CSRS:1;
  unsigned int _ADREN:1;
  unsigned int :1;
  unsigned int _ABRDEN:1;
  unsigned int _RIDLES:1;
  unsigned int _SENDB:1;
  unsigned int _SYNC:1;
  unsigned int _TXEN:1;
  unsigned int _RXEN:1;
  unsigned int _TIDLEEN:1;
  unsigned int _STPW:1;
  unsigned int _TX9SEL:1;
  unsigned int _PARM:1;
  unsigned int _DT9EN:1;
  unsigned int _TRGSEL:2;
  unsigned int _CTSE:1;
  unsigned int _RTSE:1;
  unsigned int _BKPWS:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _IRDAEN:1;
  unsigned int _RESHD:1;
  unsigned int _SLMEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_BRGR_REG{
 unsigned int reg;
 struct USART1_BRGR_BITS{
  unsigned int _BRGM:16;
  unsigned int _BRGF1:4;
  unsigned int _BRGF2:4;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_STR_REG{
 unsigned int reg;
 struct USART1_STR_BITS{
  unsigned int _OVFEIF:1;
  unsigned int _PAREIF:1;
  unsigned int _FREIF:1;
  unsigned int _BRIF:1;
  unsigned int _ABTOIF:1;
  unsigned int _WUIF:1;
  unsigned int _TEIF:1;
  unsigned int _REIF:1;
  unsigned int _CTSIF:1;
  unsigned int _RCFR:1;
  unsigned int _TXFR:1;
  unsigned int _RDRIF:1;
  unsigned int _TFEIF:1;
  unsigned int _TXEIF:1;
  unsigned int _UADMIF:1;
  unsigned int _IDLFIF:1;
  unsigned int _OVFEIC:1;
  unsigned int _PAREIC:1;
  unsigned int _FREIC:1;
  unsigned int _BRIC:1;
  unsigned int _ABTOIC:1;
  unsigned int _WUIC:1;
  unsigned int _TEIC:1;
  unsigned int _REIC:1;
  unsigned int _CTSIC:1;
  unsigned int _UADMIC:1;
  unsigned int _IDLEIC:1;
  unsigned int :1;
  unsigned int _CTSSEL:1;
  unsigned int _RXDSEL:1;
  unsigned int _TX1SEL:1;
  unsigned int _TX0SEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_TBUFR_REG{
 unsigned int reg;
 struct USART1_TBUFR_BITS{
  unsigned int _TBUF:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_RBUFR_REG{
 unsigned int reg;
 struct USART1_RBUFR_BITS{
  unsigned int _RBUF:9;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_U7816R_REG{
 unsigned int reg;
 struct USART1_U7816R_BITS{
  unsigned int _7816EN:1;
  unsigned int _CLKOUT:1;
  unsigned int _ERSW:2;
  unsigned int _PSEL:1;
  unsigned int _BGTEN:1;
  unsigned int :2;
  unsigned int _TREPEN:1;
  unsigned int _RREPEN:1;
  unsigned int _TXRE:2;
  unsigned int _RXRE:2;
  unsigned int _TREPMS:1;
  unsigned int _CLKDIV:8;
  unsigned int :1;
  unsigned int _EGT:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_IER_REG{
 unsigned int reg;
 struct USART1_IER_BITS{
  unsigned int _OVFEIE:1;
  unsigned int _PAREIE:1;
  unsigned int _FREIE:1;
  unsigned int _BRIE:1;
  unsigned int _ABTOIE:1;
  unsigned int _WUIE:1;
  unsigned int _TEIE:1;
  unsigned int _REIE:1;
  unsigned int _CTSIE:1;
  unsigned int _RDRIE:1;
  unsigned int _TFEIE:1;
  unsigned int _TXEIE:1;
  unsigned int _IDLEIE:1;
  unsigned int :3;
  unsigned int _URCDE:1;
  unsigned int _UTXDE:1;
  unsigned int _UADMIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART1_ADM_REG{
 unsigned int reg;
 struct USART1_ADM_BITS{
  unsigned int _ADM:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_CTLR_REG{
 unsigned int reg;
 struct USART2_CTLR_BITS{
  unsigned int _USARTEN:1;
  unsigned int _BRCKS:2;
  unsigned int _SCKPS:1;
  unsigned int _TCONV:1;
  unsigned int _RCONV:1;
  unsigned int _DINV:1;
  unsigned int _WUEN:1;
  unsigned int _CSRS:1;
  unsigned int _ADREN:1;
  unsigned int :1;
  unsigned int _ABRDEN:1;
  unsigned int _RIDLES:1;
  unsigned int _SENDB:1;
  unsigned int _SYNC:1;
  unsigned int _TXEN:1;
  unsigned int _RXEN:1;
  unsigned int _TIDLEEN:1;
  unsigned int _STPW:1;
  unsigned int _TX9SEL:1;
  unsigned int _PARM:1;
  unsigned int _DT9EN:1;
  unsigned int _TRGSEL:2;
  unsigned int _CTSE:1;
  unsigned int _RTSE:1;
  unsigned int _BKPWS:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _IRDAEN:1;
  unsigned int _RESHD:1;
  unsigned int _SLMEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_BRGR_REG{
 unsigned int reg;
 struct USART2_BRGR_BITS{
  unsigned int _BRGM:16;
  unsigned int _BRGF1:4;
  unsigned int _BRGF2:4;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_STR_REG{
 unsigned int reg;
 struct USART2_STR_BITS{
  unsigned int _OVFEIF:1;
  unsigned int _PAREIF:1;
  unsigned int _FREIF:1;
  unsigned int _BRIF:1;
  unsigned int _ABTOIF:1;
  unsigned int _WUIF:1;
  unsigned int _TEIF:1;
  unsigned int _REIF:1;
  unsigned int _CTSIF:1;
  unsigned int _RCFR:1;
  unsigned int _TXFR:1;
  unsigned int _RDRIF:1;
  unsigned int _TFEIF:1;
  unsigned int _TXEIF:1;
  unsigned int _UADMIF:1;
  unsigned int _IDLFIF:1;
  unsigned int _OVFEIC:1;
  unsigned int _PAREIC:1;
  unsigned int _FREIC:1;
  unsigned int _BRIC:1;
  unsigned int _ABTOIC:1;
  unsigned int _WUIC:1;
  unsigned int _TEIC:1;
  unsigned int _REIC:1;
  unsigned int _CTSIC:1;
  unsigned int _UADMIC:1;
  unsigned int _IDLEIC:1;
  unsigned int :1;
  unsigned int _CTSSEL:1;
  unsigned int _RXDSEL:1;
  unsigned int _TX1SEL:1;
  unsigned int _TX0SEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_TBUFR_REG{
 unsigned int reg;
 struct USART2_TBUFR_BITS{
  unsigned int _TBUF:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_RBUFR_REG{
 unsigned int reg;
 struct USART2_RBUFR_BITS{
  unsigned int _RBUF:9;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_U7816R_REG{
 unsigned int reg;
 struct USART2_U7816R_BITS{
  unsigned int _7816EN:1;
  unsigned int _CLKOUT:1;
  unsigned int _ERSW:2;
  unsigned int _PSEL:1;
  unsigned int _BGTEN:1;
  unsigned int :2;
  unsigned int _TREPEN:1;
  unsigned int _RREPEN:1;
  unsigned int _TXRE:2;
  unsigned int _RXRE:2;
  unsigned int _TREPMS:1;
  unsigned int _CLKDIV:8;
  unsigned int :1;
  unsigned int _EGT:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_IER_REG{
 unsigned int reg;
 struct USART2_IER_BITS{
  unsigned int _OVFEIE:1;
  unsigned int _PAREIE:1;
  unsigned int _FREIE:1;
  unsigned int _BRIE:1;
  unsigned int _ABTOIE:1;
  unsigned int _WUIE:1;
  unsigned int _TEIE:1;
  unsigned int _REIE:1;
  unsigned int _CTSIE:1;
  unsigned int _RDRIE:1;
  unsigned int _TFEIE:1;
  unsigned int _TXEIE:1;
  unsigned int _IDLEIE:1;
  unsigned int :3;
  unsigned int _URCDE:1;
  unsigned int _UTXDE:1;
  unsigned int _UADMIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART2_ADM_REG{
 unsigned int reg;
 struct USART2_ADM_BITS{
  unsigned int _ADM:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_CTLR_REG{
 unsigned int reg;
 struct USART4_CTLR_BITS{
  unsigned int _USARTEN:1;
  unsigned int _BRCKS:2;
  unsigned int _SCKPS:1;
  unsigned int _TCONV:1;
  unsigned int _RCONV:1;
  unsigned int _DINV:1;
  unsigned int _WUEN:1;
  unsigned int _CSRS:1;
  unsigned int _ADREN:1;
  unsigned int :1;
  unsigned int _ABRDEN:1;
  unsigned int _RIDLES:1;
  unsigned int _SENDB:1;
  unsigned int _SYNC:1;
  unsigned int _TXEN:1;
  unsigned int _RXEN:1;
  unsigned int _TIDLEEN:1;
  unsigned int _STPW:1;
  unsigned int _TX9SEL:1;
  unsigned int _PARM:1;
  unsigned int _DT9EN:1;
  unsigned int _TRGSEL:2;
  unsigned int _CTSE:1;
  unsigned int _RTSE:1;
  unsigned int _BKPWS:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _IRDAEN:1;
  unsigned int _RESHD:1;
  unsigned int _SLMEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_BRGR_REG{
 unsigned int reg;
 struct USART4_BRGR_BITS{
  unsigned int _BRGM:16;
  unsigned int _BRGF1:4;
  unsigned int _BRGF2:4;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_STR_REG{
 unsigned int reg;
 struct USART4_STR_BITS{
  unsigned int _OVFEIF:1;
  unsigned int _PAREIF:1;
  unsigned int _FREIF:1;
  unsigned int _BRIF:1;
  unsigned int _ABTOIF:1;
  unsigned int _WUIF:1;
  unsigned int _TEIF:1;
  unsigned int _REIF:1;
  unsigned int _CTSIF:1;
  unsigned int _RCFR:1;
  unsigned int _TXFR:1;
  unsigned int _RDRIF:1;
  unsigned int _TFEIF:1;
  unsigned int _TXEIF:1;
  unsigned int _UADMIF:1;
  unsigned int _IDLFIF:1;
  unsigned int _OVFEIC:1;
  unsigned int _PAREIC:1;
  unsigned int _FREIC:1;
  unsigned int _BRIC:1;
  unsigned int _ABTOIC:1;
  unsigned int _WUIC:1;
  unsigned int _TEIC:1;
  unsigned int _REIC:1;
  unsigned int _CTSIC:1;
  unsigned int _UADMIC:1;
  unsigned int _IDLEIC:1;
  unsigned int :1;
  unsigned int _CTSSEL:1;
  unsigned int _RXDSEL:1;
  unsigned int _TX1SEL:1;
  unsigned int _TX0SEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_TBUFR_REG{
 unsigned int reg;
 struct USART4_TBUFR_BITS{
  unsigned int _TBUF:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_RBUFR_REG{
 unsigned int reg;
 struct USART4_RBUFR_BITS{
  unsigned int _RBUF:9;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_U7816R_REG{
 unsigned int reg;
 struct USART4_U7816R_BITS{
  unsigned int _7816EN:1;
  unsigned int _CLKOUT:1;
  unsigned int _ERSW:2;
  unsigned int _PSEL:1;
  unsigned int _BGTEN:1;
  unsigned int :2;
  unsigned int _TREPEN:1;
  unsigned int _RREPEN:1;
  unsigned int _TXRE:2;
  unsigned int _RXRE:2;
  unsigned int _TREPMS:1;
  unsigned int _CLKDIV:8;
  unsigned int :1;
  unsigned int _EGT:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_IER_REG{
 unsigned int reg;
 struct USART4_IER_BITS{
  unsigned int _OVFEIE:1;
  unsigned int _PAREIE:1;
  unsigned int _FREIE:1;
  unsigned int _BRIE:1;
  unsigned int _ABTOIE:1;
  unsigned int _WUIE:1;
  unsigned int _TEIE:1;
  unsigned int _REIE:1;
  unsigned int _CTSIE:1;
  unsigned int _RDRIE:1;
  unsigned int _TFEIE:1;
  unsigned int _TXEIE:1;
  unsigned int _IDLEIE:1;
  unsigned int :3;
  unsigned int _URCDE:1;
  unsigned int _UTXDE:1;
  unsigned int _UADMIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART4_ADM_REG{
 unsigned int reg;
 struct USART4_ADM_BITS{
  unsigned int _ADM:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI0_BRGR_REG{
 unsigned int reg;
 struct SPI0_BRGR_BITS{
  unsigned int _SPIBRG:16;
  unsigned int _I2SDIV:8;
  unsigned int _MCKEN:1;
  unsigned int _I2SODD:1;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI0_CTLR_REG{
 unsigned int reg;
 struct SPI0_CTLR_BITS{
  unsigned int _SPIEN:1;
  unsigned int _SPIMS:3;
  unsigned int _SPICKS:2;
  unsigned int _SPIDS:1;
  unsigned int _SPIIOS:1;
  unsigned int _SPICKP:1;
  unsigned int _SPICKE:1;
  unsigned int :2;
  unsigned int _SPIBS:2;
  unsigned int _SSEL:2;
  unsigned int _I2SMD:1;
  unsigned int _SMINS:1;
  unsigned int _MCKOS:1;
  unsigned int _SPIPRCS:1;
  unsigned int _I2SMC:2;
  unsigned int _I2SSS:2;
  unsigned int _PCMS:1;
  unsigned int _I2SCKS:2;
  unsigned int _PCMCKP:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI0_BUFR_REG{
 unsigned int reg;
 struct SPI0_BUFR_BITS{
  unsigned int _SPIBUF:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI0_STR_REG{
 unsigned int reg;
 struct SPI0_STR_BITS{
  unsigned int _SPIBUSY:1;
  unsigned int _RNE:1;
  unsigned int _TNE:1;
  unsigned int _CHSIDE:1;
  unsigned int _ROVFIF:1;
  unsigned int _TOVFIF:1;
  unsigned int _UDRIF:1;
  unsigned int :4;
  unsigned int _UDRIE:1;
  unsigned int _ROVFIE:1;
  unsigned int _TOVFIE:1;
  unsigned int _RNEIE:1;
  unsigned int _TNEIE:1;
  unsigned int _ROVFIC:1;
  unsigned int _TOVFIC:1;
  unsigned int _UDRIC:1;
  unsigned int :1;
  unsigned int _SRCDE:1;
  unsigned int _STXDE:1;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI1_BRGR_REG{
 unsigned int reg;
 struct SPI1_BRGR_BITS{
  unsigned int _SPIBRG:16;
  unsigned int _I2SDIV:8;
  unsigned int _MCKEN:1;
  unsigned int _I2SODD:1;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI1_CTLR_REG{
 unsigned int reg;
 struct SPI1_CTLR_BITS{
  unsigned int _SPIEN:1;
  unsigned int _SPIMS:3;
  unsigned int _SPICKS:2;
  unsigned int _SPIDS:1;
  unsigned int _SPIIOS:1;
  unsigned int _SPICKP:1;
  unsigned int _SPICKE:1;
  unsigned int :2;
  unsigned int _SPIBS:2;
  unsigned int _SSEL:2;
  unsigned int _I2SMD:1;
  unsigned int _SMINS:1;
  unsigned int _MCKOS:1;
  unsigned int _SPIPRCS:1;
  unsigned int _I2SMC:2;
  unsigned int _I2SSS:2;
  unsigned int _PCMS:1;
  unsigned int _I2SCKS:2;
  unsigned int _PCMCKP:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI1_BUFR_REG{
 unsigned int reg;
 struct SPI1_BUFR_BITS{
  unsigned int _SPIBUF:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI1_STR_REG{
 unsigned int reg;
 struct SPI1_STR_BITS{
  unsigned int _SPIBUSY:1;
  unsigned int _RNE:1;
  unsigned int _TNE:1;
  unsigned int _CHSIDE:1;
  unsigned int _ROVFIF:1;
  unsigned int _TOVFIF:1;
  unsigned int _UDRIF:1;
  unsigned int :4;
  unsigned int _UDRIE:1;
  unsigned int _ROVFIE:1;
  unsigned int _TOVFIE:1;
  unsigned int _RNEIE:1;
  unsigned int _TNEIE:1;
  unsigned int _ROVFIC:1;
  unsigned int _TOVFIC:1;
  unsigned int _UDRIC:1;
  unsigned int :1;
  unsigned int _SRCDE:1;
  unsigned int _STXDE:1;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_CTLR_REG{
 unsigned int reg;
 struct I2C0_CTLR_BITS{
  unsigned int _I2CEN:1;
  unsigned int _BADR10:1;
  unsigned int :2;
  unsigned int _DHCNT:4;
  unsigned int _SEN:1;
  unsigned int :1;
  unsigned int _PEN:1;
  unsigned int :1;
  unsigned int _ACKEN:1;
  unsigned int _ACKDT:1;
  unsigned int _GCEN:1;
  unsigned int :1;
  unsigned int _I2CCKS:2;
  unsigned int _I2CCKDIV:2;
  unsigned int _MTHALL:1;
  unsigned int _ENASCL:1;
  unsigned int _NMENA:1;
  unsigned int :1;
  unsigned int _SMBUS:1;
  unsigned int _SMBT:1;
  unsigned int _ARPEN:1;
  unsigned int _ALERT:1;
  unsigned int :3;
  unsigned int _ADRL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_SR_REG{
 unsigned int reg;
 struct I2C0_SR_BITS{
  unsigned int _SIF:1;
  unsigned int _PIF:1;
  unsigned int _ADDR:1;
  unsigned int _ADD10:1;
  unsigned int _DATA:1;
  unsigned int _AFIF:1;
  unsigned int _ARBLIF:1;
  unsigned int _RNW:1;
  unsigned int _SMBAIF:1;
  unsigned int _SMBHIF:1;
  unsigned int _SMBDIF:1;
  unsigned int _ISIF:1;
  unsigned int _RCBF:1;
  unsigned int _TXBE:1;
  unsigned int :2;
  unsigned int _IRCDF:1;
  unsigned int _ITXDF:1;
  unsigned int _BERRIF:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_BUFR_REG{
 unsigned int reg;
 struct I2C0_BUFR_BITS{
  unsigned int _I2CBUF:10;
  unsigned int :22;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_ADDR0_REG{
 unsigned int reg;
 struct I2C0_ADDR0_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_BRGR_REG{
 unsigned int reg;
 struct I2C0_BRGR_BITS{
  unsigned int _I2CBRGH:16;
  unsigned int _I2CBRGL:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_ADDR1_REG{
 unsigned int reg;
 struct I2C0_ADDR1_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_ADDR2_REG{
 unsigned int reg;
 struct I2C0_ADDR2_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_ADDR3_REG{
 unsigned int reg;
 struct I2C0_ADDR3_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_IER_REG{
 unsigned int reg;
 struct I2C0_IER_BITS{
  unsigned int _SIE:1;
  unsigned int _PIE:1;
  unsigned int :3;
  unsigned int _AFIE:1;
  unsigned int _ARBLIE:1;
  unsigned int :1;
  unsigned int _SMBAIE:1;
  unsigned int _SMBHIE:1;
  unsigned int _SMBDIE:1;
  unsigned int _ISIE:1;
  unsigned int :4;
  unsigned int _IRCDE:1;
  unsigned int _ITXDE:1;
  unsigned int _BERRIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C0_TPSR_REG{
 unsigned int reg;
 struct I2C0_TPSR_BITS{
  unsigned int _I2CTPS0:1;
  unsigned int _I2CTPS1:1;
  unsigned int _I2CTPS2:1;
  unsigned int _I2CTPS3:1;
  unsigned int _I2CTPS4:1;
  unsigned int _I2CTPS5:1;
  unsigned int _I2CTPS6:1;
  unsigned int _I2CTPS7:1;
  unsigned int _I2CTPS8:1;
  unsigned int _I2CTPS9:1;
  unsigned int _I2CTPS10:1;
  unsigned int _I2CTPS11:1;
  unsigned int _I2CTPOEN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_CTLR_REG{
 unsigned int reg;
 struct I2C1_CTLR_BITS{
  unsigned int _I2CEN:1;
  unsigned int _BADR10:1;
  unsigned int :2;
  unsigned int _DHCNT:4;
  unsigned int _SEN:1;
  unsigned int :1;
  unsigned int _PEN:1;
  unsigned int :1;
  unsigned int _ACKEN:1;
  unsigned int _ACKDT:1;
  unsigned int _GCEN:1;
  unsigned int :1;
  unsigned int _I2CCKS:2;
  unsigned int _I2CCKDIV:2;
  unsigned int _MTHALL:1;
  unsigned int _ENASCL:1;
  unsigned int _NMENA:1;
  unsigned int :1;
  unsigned int _SMBUS:1;
  unsigned int _SMBT:1;
  unsigned int _ARPEN:1;
  unsigned int _ALERT:1;
  unsigned int :3;
  unsigned int _ADRL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_SR_REG{
 unsigned int reg;
 struct I2C1_SR_BITS{
  unsigned int _SIF:1;
  unsigned int _PIF:1;
  unsigned int _ADDR:1;
  unsigned int _ADD10:1;
  unsigned int _DATA:1;
  unsigned int _AFIF:1;
  unsigned int _ARBLIF:1;
  unsigned int _RNW:1;
  unsigned int _SMBAIF:1;
  unsigned int _SMBHIF:1;
  unsigned int _SMBDIF:1;
  unsigned int _ISIF:1;
  unsigned int _RCBF:1;
  unsigned int _TXBE:1;
  unsigned int :2;
  unsigned int _IRCDF:1;
  unsigned int _ITXDF:1;
  unsigned int _BERRIF:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_BUFR_REG{
 unsigned int reg;
 struct I2C1_BUFR_BITS{
  unsigned int _I2CBUF:10;
  unsigned int :22;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_ADDR0_REG{
 unsigned int reg;
 struct I2C1_ADDR0_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_BRGR_REG{
 unsigned int reg;
 struct I2C1_BRGR_BITS{
  unsigned int _I2CBRGH:16;
  unsigned int _I2CBRGL:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_ADDR1_REG{
 unsigned int reg;
 struct I2C1_ADDR1_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_ADDR2_REG{
 unsigned int reg;
 struct I2C1_ADDR2_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_ADDR3_REG{
 unsigned int reg;
 struct I2C1_ADDR3_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_IER_REG{
 unsigned int reg;
 struct I2C1_IER_BITS{
  unsigned int _SIE:1;
  unsigned int _PIE:1;
  unsigned int :3;
  unsigned int _AFIE:1;
  unsigned int _ARBLIE:1;
  unsigned int :1;
  unsigned int _SMBAIE:1;
  unsigned int _SMBHIE:1;
  unsigned int _SMBDIE:1;
  unsigned int _ISIE:1;
  unsigned int :4;
  unsigned int _IRCDE:1;
  unsigned int _ITXDE:1;
  unsigned int _BERRIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C1_TPSR_REG{
 unsigned int reg;
 struct I2C1_TPSR_BITS{
  unsigned int _I2CTPS0:1;
  unsigned int _I2CTPS1:1;
  unsigned int _I2CTPS2:1;
  unsigned int _I2CTPS3:1;
  unsigned int _I2CTPS4:1;
  unsigned int _I2CTPS5:1;
  unsigned int _I2CTPS6:1;
  unsigned int _I2CTPS7:1;
  unsigned int _I2CTPS8:1;
  unsigned int _I2CTPS9:1;
  unsigned int _I2CTPS10:1;
  unsigned int _I2CTPS11:1;
  unsigned int _I2CTPOEN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_CTLR_REG{
 unsigned int reg;
 struct I2C2_CTLR_BITS{
  unsigned int _I2CEN:1;
  unsigned int _BADR10:1;
  unsigned int :2;
  unsigned int _DHCNT:4;
  unsigned int _SEN:1;
  unsigned int :1;
  unsigned int _PEN:1;
  unsigned int :1;
  unsigned int _ACKEN:1;
  unsigned int _ACKDT:1;
  unsigned int _GCEN:1;
  unsigned int :1;
  unsigned int _I2CCKS:2;
  unsigned int _I2CCKDIV:2;
  unsigned int _MTHALL:1;
  unsigned int _ENASCL:1;
  unsigned int _NMENA:1;
  unsigned int :1;
  unsigned int _SMBUS:1;
  unsigned int _SMBT:1;
  unsigned int _ARPEN:1;
  unsigned int _ALERT:1;
  unsigned int :3;
  unsigned int _ADRL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_SR_REG{
 unsigned int reg;
 struct I2C2_SR_BITS{
  unsigned int _SIF:1;
  unsigned int _PIF:1;
  unsigned int _ADDR:1;
  unsigned int _ADD10:1;
  unsigned int _DATA:1;
  unsigned int _AFIF:1;
  unsigned int _ARBLIF:1;
  unsigned int _RNW:1;
  unsigned int _SMBAIF:1;
  unsigned int _SMBHIF:1;
  unsigned int _SMBDIF:1;
  unsigned int _ISIF:1;
  unsigned int _RCBF:1;
  unsigned int _TXBE:1;
  unsigned int :2;
  unsigned int _IRCDF:1;
  unsigned int _ITXDF:1;
  unsigned int _BERRIF:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_BUFR_REG{
 unsigned int reg;
 struct I2C2_BUFR_BITS{
  unsigned int _I2CBUF:10;
  unsigned int :22;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_ADDR0_REG{
 unsigned int reg;
 struct I2C2_ADDR0_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_BRGR_REG{
 unsigned int reg;
 struct I2C2_BRGR_BITS{
  unsigned int _I2CBRGH:16;
  unsigned int _I2CBRGL:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_ADDR1_REG{
 unsigned int reg;
 struct I2C2_ADDR1_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_ADDR2_REG{
 unsigned int reg;
 struct I2C2_ADDR2_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_ADDR3_REG{
 unsigned int reg;
 struct I2C2_ADDR3_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_IER_REG{
 unsigned int reg;
 struct I2C2_IER_BITS{
  unsigned int _SIE:1;
  unsigned int _PIE:1;
  unsigned int :3;
  unsigned int _AFIE:1;
  unsigned int _ARBLIE:1;
  unsigned int :1;
  unsigned int _SMBAIE:1;
  unsigned int _SMBHIE:1;
  unsigned int _SMBDIE:1;
  unsigned int _ISIE:1;
  unsigned int :4;
  unsigned int _IRCDE:1;
  unsigned int _ITXDE:1;
  unsigned int _BERRIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C2_TPSR_REG{
 unsigned int reg;
 struct I2C2_TPSR_BITS{
  unsigned int _I2CTPS0:1;
  unsigned int _I2CTPS1:1;
  unsigned int _I2CTPS2:1;
  unsigned int _I2CTPS3:1;
  unsigned int _I2CTPS4:1;
  unsigned int _I2CTPS5:1;
  unsigned int _I2CTPS6:1;
  unsigned int _I2CTPS7:1;
  unsigned int _I2CTPS8:1;
  unsigned int _I2CTPS9:1;
  unsigned int _I2CTPS10:1;
  unsigned int _I2CTPS11:1;
  unsigned int _I2CTPOEN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_CR_REG{
 unsigned int reg;
 struct RTC_CR_BITS{
  unsigned int _RTCEN:1;
  unsigned int _LD:1;
  unsigned int _RTOFF:1;
  unsigned int _CNF:1;
  unsigned int _HT:1;
  unsigned int _LIF:1;
  unsigned int _RESET:1;
  unsigned int :1;
  unsigned int _RTCTSCH:6;
  unsigned int _RTCCLKS:2;
  unsigned int _RTCTT:3;
  unsigned int _SUB1H:1;
  unsigned int _ADD1H:1;
  unsigned int _TSEN:1;
  unsigned int _TSEDGE:1;
  unsigned int :1;
  unsigned int _RTCCAL:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_ALRA_REG{
 unsigned int reg;
 struct RTC_ALRA_BITS{
  unsigned int _ALRSA:7;
  unsigned int _ASENA:1;
  unsigned int _ALRMA:7;
  unsigned int _AMENA:1;
  unsigned int _ALRHA:6;
  unsigned int _AMPMA:1;
  unsigned int _AHENA:1;
  unsigned int _ALRWA:3;
  unsigned int _AWENA:1;
  unsigned int :3;
  unsigned int _ALRENA:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_TMR_REG{
 unsigned int reg;
 struct RTC_TMR_BITS{
  unsigned int _SEC:7;
  unsigned int :1;
  unsigned int _MIN:7;
  unsigned int :1;
  unsigned int _HOUR:6;
  unsigned int _AMPM:1;
  unsigned int :1;
  unsigned int _WEK:3;
  unsigned int :5;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_DTR_REG{
 unsigned int reg;
 struct RTC_DTR_BITS{
  unsigned int _DAY:6;
  unsigned int :2;
  unsigned int _MTH:5;
  unsigned int :3;
  unsigned int _YEAR:8;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_ALRB_REG{
 unsigned int reg;
 struct RTC_ALRB_BITS{
  unsigned int _ALRSB:7;
  unsigned int _ASENB:1;
  unsigned int _ALRMB:7;
  unsigned int _AMENB:1;
  unsigned int _ALRHB:6;
  unsigned int _AMPMB:1;
  unsigned int _AHENB:1;
  unsigned int _ALRWB:3;
  unsigned int _AWENB:1;
  unsigned int :3;
  unsigned int _ALRENB:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_TMER_REG{
 unsigned int reg;
 struct RTC_TMER_BITS{
  unsigned int _TMR0:16;
  unsigned int _TMR1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_TCR_REG{
 unsigned int reg;
 struct RTC_TCR_BITS{
  unsigned int _TMR0C:4;
  unsigned int _TMR1C:4;
  unsigned int _TMR0EN:1;
  unsigned int _TMR1EN:1;
  unsigned int :22;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_IER_REG{
 unsigned int reg;
 struct RTC_IER_BITS{
  unsigned int _SECIE:1;
  unsigned int _MINIE:1;
  unsigned int _HOURIE:1;
  unsigned int _DAYIE:1;
  unsigned int _ALRAIE:1;
  unsigned int _ALRBIE:1;
  unsigned int _TTIE:1;
  unsigned int :1;
  unsigned int _RTCT0IE:1;
  unsigned int _RTCT1IE:1;
  unsigned int _TSOVFIE:1;
  unsigned int _TSIE:1;
  unsigned int :20;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_IFR_REG{
 unsigned int reg;
 struct RTC_IFR_BITS{
  unsigned int _SECIF:1;
  unsigned int _MINIF:1;
  unsigned int _HOURIF:1;
  unsigned int _DAYIF:1;
  unsigned int _ALRAIF:1;
  unsigned int _ALRBIF:1;
  unsigned int _TTIF:1;
  unsigned int :1;
  unsigned int _RTCT0IF:1;
  unsigned int _RTCT1IF:1;
  unsigned int _TSOVFIF:1;
  unsigned int _TSIF:1;
  unsigned int :4;
  unsigned int _SECIC:1;
  unsigned int _MINIC:1;
  unsigned int _HOURIC:1;
  unsigned int _DAYIC:1;
  unsigned int _ALRAIC:1;
  unsigned int _ALRBIC:1;
  unsigned int _TTIC:1;
  unsigned int :1;
  unsigned int _RTCT0IC:1;
  unsigned int _RTCT1IC:1;
  unsigned int _TSOVFIC:1;
  unsigned int _TSIC:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_TMBR_REG{
 unsigned int reg;
 struct RTC_TMBR_BITS{
  unsigned int _SECB:7;
  unsigned int :1;
  unsigned int _MINB:7;
  unsigned int :1;
  unsigned int _HOURB:6;
  unsigned int _AMPMB:1;
  unsigned int :1;
  unsigned int _WEKB:3;
  unsigned int :5;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RTC_DTBR_REG{
 unsigned int reg;
 struct RTC_DTBR_BITS{
  unsigned int _DAYB:6;
  unsigned int :2;
  unsigned int _MTHB:5;
  unsigned int :3;
  unsigned int _YEARB:8;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_CTLR0_REG{
 unsigned int reg;
 struct CANFD6_CTLR0_BITS{
  unsigned int _RSMOD:1;
  unsigned int _SILENT:1;
  unsigned int _LBACK:1;
  unsigned int _SLEEP:1;
  unsigned int _ISOFDCANEN:1;
  unsigned int _CANCKS:2;
  unsigned int _CANEN:1;
  unsigned int _TXR:1;
  unsigned int _ATX:1;
  unsigned int _RELRX:1;
  unsigned int _RELF:1;
  unsigned int _MBSIZE:2;
  unsigned int _FULLRXEN:1;
  unsigned int _ANSWEREN:1;
  unsigned int _RXBSTA:1;
  unsigned int _DOSTA:1;
  unsigned int _TXBSTA:1;
  unsigned int _TCSTA:1;
  unsigned int _RXSTA:1;
  unsigned int _TXSTA:1;
  unsigned int _CERROR:1;
  unsigned int _BOFF:1;
  unsigned int _CANRMC:7;
  unsigned int _CANFDEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_BRGR_REG{
 unsigned int reg;
 struct CANFD6_BRGR_BITS{
  unsigned int _CANBRP:6;
  unsigned int _SJW:2;
  unsigned int _TSEG1:4;
  unsigned int _TSEG2:3;
  unsigned int _SAM:1;
  unsigned int _BRSBRP:6;
  unsigned int _HTSEG1:4;
  unsigned int _HTSEG2:3;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RCR_REG{
 unsigned int reg;
 struct CANFD6_RCR_BITS{
  unsigned int _CANALC:5;
  unsigned int :3;
  unsigned int _CANSEG:5;
  unsigned int _CANDIR:1;
  unsigned int _CANERRC:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_EROR_REG{
 unsigned int reg;
 struct CANFD6_EROR_BITS{
  unsigned int _CANRXE:8;
  unsigned int _CANTXE:8;
  unsigned int _CANEWL:8;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_CTLR2_REG{
 unsigned int reg;
 struct CANFD6_CTLR2_BITS{
  unsigned int _TDCV:7;
  unsigned int _TDC0EN:1;
  unsigned int _TDCEN:1;
  unsigned int _TDCAUT0:1;
  unsigned int _TDCS:2;
  unsigned int _TDCSR:2;
  unsigned int _TDC0:2;
  unsigned int _TDCVM:7;
  unsigned int _TEST0:1;
  unsigned int _RELRXALL:1;
  unsigned int _AMCKDIV:2;
  unsigned int _TEST1:1;
  unsigned int _TEST2:1;
  unsigned int _TEST3:1;
  unsigned int _TEST4:1;
  unsigned int _TEST5:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_MSKR_REG{
 unsigned int reg;
 struct CANFD6_MSKR_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_IER_REG{
 unsigned int reg;
 struct CANFD6_IER_BITS{
  unsigned int _CANRXIE:1;
  unsigned int _CANTXIE:1;
  unsigned int _EAIE:1;
  unsigned int _DOVFIE:1;
  unsigned int _WUIE:1;
  unsigned int _ENIE:1;
  unsigned int _ALIE:1;
  unsigned int _BEIE:1;
  unsigned int _CTXDE:1;
  unsigned int _CRXDE:1;
  unsigned int _RXBSTAIE:1;
  unsigned int _TRGMBIE:1;
  unsigned int _BOFFIE:1;
  unsigned int _TDCFAILIE:1;
  unsigned int _ARBFAILIE:1;
  unsigned int _MOENDIE:1;
  unsigned int _CANRXIC:1;
  unsigned int _CANTXIC:1;
  unsigned int _EAIC:1;
  unsigned int _DOVFIC:1;
  unsigned int _WUIC:1;
  unsigned int _ENIC:1;
  unsigned int _ALIC:1;
  unsigned int _BEIC:1;
  unsigned int :2;
  unsigned int _MOENDIC:1;
  unsigned int _TRGMBIC:1;
  unsigned int _BOFFIC:1;
  unsigned int _TDCFAILIC:1;
  unsigned int _LPCANGPIOSEL0:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_IFR_REG{
 unsigned int reg;
 struct CANFD6_IFR_BITS{
  unsigned int _CANRXIF:1;
  unsigned int _CANTXIF:1;
  unsigned int _EAIF:1;
  unsigned int _DOVFIF:1;
  unsigned int _WUIF:1;
  unsigned int _ENIF:1;
  unsigned int _ALIF:1;
  unsigned int _BEIF:1;
  unsigned int _CTXDF:1;
  unsigned int _CRXDF:1;
  unsigned int _RXBSTAIF:1;
  unsigned int _TRGMBIF:1;
  unsigned int _BOFFIF:1;
  unsigned int _TDCFAILIF:1;
  unsigned int _MOENDIF:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA0_REG{
 unsigned int reg;
 struct CANFD6_RXDATA0_BITS{
  unsigned int _RXDATA0:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA1_REG{
 unsigned int reg;
 struct CANFD6_RXDATA1_BITS{
  unsigned int _RXDATA1:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA2_REG{
 unsigned int reg;
 struct CANFD6_RXDATA2_BITS{
  unsigned int _RXDATA2:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA3_REG{
 unsigned int reg;
 struct CANFD6_RXDATA3_BITS{
  unsigned int _RXDATA3:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA4_REG{
 unsigned int reg;
 struct CANFD6_RXDATA4_BITS{
  unsigned int _RXDATA4:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA5_REG{
 unsigned int reg;
 struct CANFD6_RXDATA5_BITS{
  unsigned int _RXDATA5:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA6_REG{
 unsigned int reg;
 struct CANFD6_RXDATA6_BITS{
  unsigned int _RXDATA6:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA7_REG{
 unsigned int reg;
 struct CANFD6_RXDATA7_BITS{
  unsigned int _RXDATA7:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA8_REG{
 unsigned int reg;
 struct CANFD6_RXDATA8_BITS{
  unsigned int _RXDATA8:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA9_REG{
 unsigned int reg;
 struct CANFD6_RXDATA9_BITS{
  unsigned int _RXDATA9:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA10_REG{
 unsigned int reg;
 struct CANFD6_RXDATA10_BITS{
  unsigned int _RXDATA10:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA11_REG{
 unsigned int reg;
 struct CANFD6_RXDATA11_BITS{
  unsigned int _RXDATA11:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA12_REG{
 unsigned int reg;
 struct CANFD6_RXDATA12_BITS{
  unsigned int _RXDATA12:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA13_REG{
 unsigned int reg;
 struct CANFD6_RXDATA13_BITS{
  unsigned int _RXDATA13:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA14_REG{
 unsigned int reg;
 struct CANFD6_RXDATA14_BITS{
  unsigned int _RXDATA14:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA15_REG{
 unsigned int reg;
 struct CANFD6_RXDATA15_BITS{
  unsigned int _RXDATA15:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA16_REG{
 unsigned int reg;
 struct CANFD6_RXDATA16_BITS{
  unsigned int _RXDATA16:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_RXDATA17_REG{
 unsigned int reg;
 struct CANFD6_RXDATA17_BITS{
  unsigned int _RXDATA17:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_TIMER_REG{
 unsigned int reg;
 struct CANFD6_TIMER_BITS{
  unsigned int _CANTIMER:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_CRC_REG{
 unsigned int reg;
 struct CANFD6_CRC_BITS{
  unsigned int _CRC:21;
  unsigned int :7;
  unsigned int _STUFFCNT:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_CTLR1_REG{
 unsigned int reg;
 struct CANFD6_CTLR1_BITS{
  unsigned int _AMCKS:2;
  unsigned int _RXMUX:7;
  unsigned int _ST:1;
  unsigned int _FTCLKS:1;
  unsigned int _TSYN:1;
  unsigned int _MBNUM:1;
  unsigned int _MATCHMS:1;
  unsigned int _MBMSKEN:1;
  unsigned int _ARBMS:1;
  unsigned int _ARBSTART:1;
  unsigned int _LBSEL:1;
  unsigned int _BOFFREC:1;
  unsigned int _CKMODE:1;
  unsigned int _TRGNUM:4;
  unsigned int _TRGMBSEL:7;
  unsigned int _TRGMBEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD6_AMSTA_REG{
 unsigned int reg;
 struct CANFD6_AMSTA_BITS{
  unsigned int _MATWINNER:10;
  unsigned int _MATSTA:1;
  unsigned int :5;
  unsigned int _ARBWINNER:10;
  unsigned int _ARBSTA0:1;
  unsigned int _ARBSTA1:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_CTLR0_REG{
 unsigned int reg;
 struct CANFD7_CTLR0_BITS{
  unsigned int _RSMOD:1;
  unsigned int _SILENT:1;
  unsigned int _LBACK:1;
  unsigned int _SLEEP:1;
  unsigned int _ISOFDCANEN:1;
  unsigned int _CANCKS:2;
  unsigned int _CANEN:1;
  unsigned int _TXR:1;
  unsigned int _ATX:1;
  unsigned int _RELRX:1;
  unsigned int _RELF:1;
  unsigned int _MBSIZE:2;
  unsigned int _FULLRXEN:1;
  unsigned int _ANSWEREN:1;
  unsigned int _RXBSTA:1;
  unsigned int _DOSTA:1;
  unsigned int _TXBSTA:1;
  unsigned int _TCSTA:1;
  unsigned int _RXSTA:1;
  unsigned int _TXSTA:1;
  unsigned int _CERROR:1;
  unsigned int _BOFF:1;
  unsigned int _CANRMC:7;
  unsigned int _CANFDEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_BRGR_REG{
 unsigned int reg;
 struct CANFD7_BRGR_BITS{
  unsigned int _CANBRP:6;
  unsigned int _SJW:2;
  unsigned int _TSEG1:4;
  unsigned int _TSEG2:3;
  unsigned int _SAM:1;
  unsigned int _BRSBRP:6;
  unsigned int _HTSEG1:4;
  unsigned int _HTSEG2:3;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RCR_REG{
 unsigned int reg;
 struct CANFD7_RCR_BITS{
  unsigned int _CANALC:5;
  unsigned int :3;
  unsigned int _CANSEG:5;
  unsigned int _CANDIR:1;
  unsigned int _CANERRC:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_EROR_REG{
 unsigned int reg;
 struct CANFD7_EROR_BITS{
  unsigned int _CANRXE:8;
  unsigned int _CANTXE:8;
  unsigned int _CANEWL:8;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_CTLR2_REG{
 unsigned int reg;
 struct CANFD7_CTLR2_BITS{
  unsigned int _TDCV:7;
  unsigned int _TDC0EN:1;
  unsigned int _TDCEN:1;
  unsigned int _TDCAUT0:1;
  unsigned int _TDCS:2;
  unsigned int _TDCSR:2;
  unsigned int _TDC0:2;
  unsigned int _TDCVM:7;
  unsigned int _TEST0:1;
  unsigned int _RELRXALL:1;
  unsigned int _AMCKDIV:2;
  unsigned int _TEST1:1;
  unsigned int _TEST2:1;
  unsigned int _TEST3:1;
  unsigned int _TEST4:1;
  unsigned int _TEST5:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_MSKR_REG{
 unsigned int reg;
 struct CANFD7_MSKR_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_IER_REG{
 unsigned int reg;
 struct CANFD7_IER_BITS{
  unsigned int _CANRXIE:1;
  unsigned int _CANTXIE:1;
  unsigned int _EAIE:1;
  unsigned int _DOVFIE:1;
  unsigned int _WUIE:1;
  unsigned int _ENIE:1;
  unsigned int _ALIE:1;
  unsigned int _BEIE:1;
  unsigned int _CTXDE:1;
  unsigned int _CRXDE:1;
  unsigned int _RXBSTAIE:1;
  unsigned int _TRGMBIE:1;
  unsigned int _BOFFIE:1;
  unsigned int _TDCFAILIE:1;
  unsigned int _ARBFAILIE:1;
  unsigned int _MOENDIE:1;
  unsigned int _CANRXIC:1;
  unsigned int _CANTXIC:1;
  unsigned int _EAIC:1;
  unsigned int _DOVFIC:1;
  unsigned int _WUIC:1;
  unsigned int _ENIC:1;
  unsigned int _ALIC:1;
  unsigned int _BEIC:1;
  unsigned int :2;
  unsigned int _MOENDIC:1;
  unsigned int _TRGMBIC:1;
  unsigned int _BOFFIC:1;
  unsigned int _TDCFAILIC:1;
  unsigned int :2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_IFR_REG{
 unsigned int reg;
 struct CANFD7_IFR_BITS{
  unsigned int _CANRXIF:1;
  unsigned int _CANTXIF:1;
  unsigned int _EAIF:1;
  unsigned int _DOVFIF:1;
  unsigned int _WUIF:1;
  unsigned int _ENIF:1;
  unsigned int _ALIF:1;
  unsigned int _BEIF:1;
  unsigned int _CTXDF:1;
  unsigned int _CRXDF:1;
  unsigned int _RXBSTAIF:1;
  unsigned int _TRGMBIF:1;
  unsigned int _BOFFIF:1;
  unsigned int _TDCFAILIF:1;
  unsigned int _MOENDIF:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA0_REG{
 unsigned int reg;
 struct CANFD7_RXDATA0_BITS{
  unsigned int _RXDATA0:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA1_REG{
 unsigned int reg;
 struct CANFD7_RXDATA1_BITS{
  unsigned int _RXDATA1:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA2_REG{
 unsigned int reg;
 struct CANFD7_RXDATA2_BITS{
  unsigned int _RXDATA2:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA3_REG{
 unsigned int reg;
 struct CANFD7_RXDATA3_BITS{
  unsigned int _RXDATA3:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA4_REG{
 unsigned int reg;
 struct CANFD7_RXDATA4_BITS{
  unsigned int _RXDATA4:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA5_REG{
 unsigned int reg;
 struct CANFD7_RXDATA5_BITS{
  unsigned int _RXDATA5:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA6_REG{
 unsigned int reg;
 struct CANFD7_RXDATA6_BITS{
  unsigned int _RXDATA6:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA7_REG{
 unsigned int reg;
 struct CANFD7_RXDATA7_BITS{
  unsigned int _RXDATA7:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA8_REG{
 unsigned int reg;
 struct CANFD7_RXDATA8_BITS{
  unsigned int _RXDATA8:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA9_REG{
 unsigned int reg;
 struct CANFD7_RXDATA9_BITS{
  unsigned int _RXDATA9:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA10_REG{
 unsigned int reg;
 struct CANFD7_RXDATA10_BITS{
  unsigned int _RXDATA10:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA11_REG{
 unsigned int reg;
 struct CANFD7_RXDATA11_BITS{
  unsigned int _RXDATA11:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA12_REG{
 unsigned int reg;
 struct CANFD7_RXDATA12_BITS{
  unsigned int _RXDATA12:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA13_REG{
 unsigned int reg;
 struct CANFD7_RXDATA13_BITS{
  unsigned int _RXDATA13:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA14_REG{
 unsigned int reg;
 struct CANFD7_RXDATA14_BITS{
  unsigned int _RXDATA14:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA15_REG{
 unsigned int reg;
 struct CANFD7_RXDATA15_BITS{
  unsigned int _RXDATA15:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA16_REG{
 unsigned int reg;
 struct CANFD7_RXDATA16_BITS{
  unsigned int _RXDATA16:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_RXDATA17_REG{
 unsigned int reg;
 struct CANFD7_RXDATA17_BITS{
  unsigned int _RXDATA17:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_TIMER_REG{
 unsigned int reg;
 struct CANFD7_TIMER_BITS{
  unsigned int _CANTIMER:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_CRC_REG{
 unsigned int reg;
 struct CANFD7_CRC_BITS{
  unsigned int _CRC:21;
  unsigned int :7;
  unsigned int _STUFFCNT:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_CTLR1_REG{
 unsigned int reg;
 struct CANFD7_CTLR1_BITS{
  unsigned int _AMCKS:2;
  unsigned int _RXMUX:7;
  unsigned int _ST:1;
  unsigned int _FTCLKS:1;
  unsigned int _TSYN:1;
  unsigned int _MBNUM:1;
  unsigned int _MATCHMS:1;
  unsigned int _MBMSKEN:1;
  unsigned int _ARBMS:1;
  unsigned int _ARBSTART:1;
  unsigned int _LBSEL:1;
  unsigned int _BOFFREC:1;
  unsigned int _CKMODE:1;
  unsigned int _TRGNUM:4;
  unsigned int _TRGMBSEL:7;
  unsigned int _TRGMBEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CANFD7_AMSTA_REG{
 unsigned int reg;
 struct CANFD7_AMSTA_BITS{
  unsigned int _MATWINNER:10;
  unsigned int _MATSTA:1;
  unsigned int :5;
  unsigned int _ARBWINNER:10;
  unsigned int _ARBSTA0:1;
  unsigned int _ARBSTA1:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union IWDT_CTL_REG{
 unsigned int reg;
 struct IWDT_CTL_BITS{
  unsigned int _IWDTPS:4;
  unsigned int _IWDTOVF:12;
  unsigned int :13;
  unsigned int _CLKS:1;
  unsigned int _IWDTTPEN:1;
  unsigned int _IWDTEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union IWDT_FD_REG{
 unsigned int reg;
 struct IWDT_FD_BITS{
  unsigned int _IWDTFD:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union WWDT_CTL_REG{
 unsigned int reg;
 struct WWDT_CTL_BITS{
  unsigned int _WWDTEN:1;
  unsigned int _WWDTIE:1;
  unsigned int _WWDTIF:1;
  unsigned int _WPS:5;
  unsigned int _WW:7;
  unsigned int _WWDTIC:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union WWDT_CNT_REG{
 unsigned int reg;
 struct WWDT_CNT_BITS{
  unsigned int _WT:7;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union WWDT_CTL1_REG{
 unsigned int reg;
 struct WWDT_CTL1_BITS{
  unsigned int _CLKS:2;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_CTL_REG{
 unsigned int reg;
 struct BKP_CTL_BITS{
  unsigned int _EXTLFEN:1;
  unsigned int _EXTHFBYP:1;
  unsigned int _EXTLFBYP:1;
  unsigned int _SAMCLKS:1;
  unsigned int _SYNC:1;
  unsigned int :11;
  unsigned int _TAMP1EN:1;
  unsigned int _TAMP2EN:1;
  unsigned int _TAMP3EN:1;
  unsigned int :1;
  unsigned int _TAMP1LVL:1;
  unsigned int _TAMP2LVL:1;
  unsigned int _TAMP3LVL:1;
  unsigned int :8;
  unsigned int _BKDRST:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_INT_REG{
 unsigned int reg;
 struct BKP_INT_BITS{
  unsigned int _TAMP1IC:1;
  unsigned int _TAMP2IC:1;
  unsigned int _TAMP3IC:1;
  unsigned int :5;
  unsigned int _TAMP1IE:1;
  unsigned int _TAMP2IE:1;
  unsigned int _TAMP3IE:1;
  unsigned int :5;
  unsigned int _TAMP1IF:1;
  unsigned int _TAMP2IF:1;
  unsigned int _TAMP3IF:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA0_REG{
 unsigned int reg;
 struct BKP_DATA0_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA1_REG{
 unsigned int reg;
 struct BKP_DATA1_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA2_REG{
 unsigned int reg;
 struct BKP_DATA2_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA3_REG{
 unsigned int reg;
 struct BKP_DATA3_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA4_REG{
 unsigned int reg;
 struct BKP_DATA4_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA5_REG{
 unsigned int reg;
 struct BKP_DATA5_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA6_REG{
 unsigned int reg;
 struct BKP_DATA6_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union BKP_DATA7_REG{
 unsigned int reg;
 struct BKP_DATA7_BITS{
  unsigned int _BKPDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RST_CTL0_REG{
 unsigned int reg;
 struct RST_CTL0_BITS{
  unsigned int _GPIOARST:1;
  unsigned int _GPIOBRST:1;
  unsigned int _GPIOCRST:1;
  unsigned int _GPIODRST:1;
  unsigned int _GPIOERST:1;
  unsigned int _GPIOFRST:1;
  unsigned int _GPIOGRST:1;
  unsigned int _GPIOHRST:1;
  unsigned int :23;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RST_CTL1_REG{
 unsigned int reg;
 struct RST_CTL1_BITS{
  unsigned int :1;
  unsigned int _QEI1RST:1;
  unsigned int _T1RST:1;
  unsigned int _T2RST:1;
  unsigned int _T3RST:1;
  unsigned int _T4RST:1;
  unsigned int _T5T6RST:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _QEI0RST:1;
  unsigned int _ADC0RST:1;
  unsigned int _ADC1RST:1;
  unsigned int _ADC2RST:1;
  unsigned int _DAC0RST:1;
  unsigned int _DAC1RST:1;
  unsigned int _CMPRST:1;
  unsigned int _T0RST:1;
  unsigned int :1;
  unsigned int _USART0RST:1;
  unsigned int _USART1RST:1;
  unsigned int _USART2RST:1;
  unsigned int :1;
  unsigned int _USART4RST:1;
  unsigned int _SPI0RST:1;
  unsigned int _SPI1RST:1;
  unsigned int _I2C0RST:1;
  unsigned int _I2C1RST:1;
  unsigned int _I2C2RST:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RST_CTL2_REG{
 unsigned int reg;
 struct RST_CTL2_BITS{
  unsigned int :4;
  unsigned int :1;
  unsigned int _WWDTRST:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _EPWM11RST:1;
  unsigned int _EPWM12RST:1;
  unsigned int _EPWM13RST:1;
  unsigned int _EPWM16RST:1;
  unsigned int _DMA0RST:1;
  unsigned int :1;
  unsigned int _DMA1RST:1;
  unsigned int :1;
  unsigned int _T14RST:1;
  unsigned int :3;
  unsigned int :1;
  unsigned int _T18RST:1;
  unsigned int _T19RST:1;
  unsigned int :1;
  unsigned int _T21RST:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _DAC2RST:1;
  unsigned int _DAC3RST:1;
  unsigned int _USART5RST:1;
  unsigned int :1;
  unsigned int _USART7RST:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RST_CTL3_REG{
 unsigned int reg;
 struct RST_CTL3_BITS{
  unsigned int :1;
  unsigned int _SPI2RST:1;
  unsigned int _SPI3RST:1;
  unsigned int :3;
  unsigned int :1;
  unsigned int _I2C3RST:1;
  unsigned int _HRCAP0RST:1;
  unsigned int _HRCAP1RST:1;
  unsigned int _HRCAP2RST:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _CRCRST:1;
  unsigned int _AESRST:1;
  unsigned int :1;
  unsigned int _EXICRST:1;
  unsigned int _CAN4RST:1;
  unsigned int :1;
  unsigned int _CFGLRST:1;
  unsigned int _OPRST:1;
  unsigned int _FLEXMUXRST:1;
  unsigned int _FDC0RST:1;
  unsigned int _FDC1RST:1;
  unsigned int _FDC2RST:1;
  unsigned int _FLEXRMRST:1;
  unsigned int _ECFGLRST:1;
  unsigned int _EWDTRST:1;
  unsigned int _RNGRST:1;
  unsigned int _CANFD6RST:1;
  unsigned int _CANFD7RST:1;
  unsigned int _RTCRST:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_CTL0_REG{
 unsigned int reg;
 struct PM_CTL0_BITS{
  unsigned int _LPMS:3;
  unsigned int _MEMSEL:1;
  unsigned int :1;
  unsigned int _LPREN:1;
  unsigned int _OCALLOCK:1;
  unsigned int _BKPWR:1;
  unsigned int _HSIEN:1;
  unsigned int _PDMDELAY:2;
  unsigned int _PDMSEL:1;
  unsigned int :1;
  unsigned int _PHERIIOSEL:1;
  unsigned int _PORDELAYSEL:1;
  unsigned int _BKPPORDELAYSEL:1;
  unsigned int _IWDTRMSEL:1;
  unsigned int _LSECONF:1;
  unsigned int _LP4MEN:1;
  unsigned int _LPRAMSEL:1;
  unsigned int _DPRAMASEL:1;
  unsigned int _IWDTCLR:1;
  unsigned int _BKPREGCLR:1;
  unsigned int _LPBGON:1;
  unsigned int _LDO18EN:1;
  unsigned int _MRBGEN:1;
  unsigned int :2;
  unsigned int _LSEEN:1;
  unsigned int _LSIEN:1;
  unsigned int _VDDPORON:1;
  unsigned int _IOLATCH:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_CTL1_REG{
 unsigned int reg;
 struct PM_CTL1_BITS{
  unsigned int _PVDEN:1;
  unsigned int _BKPLPRTYPE:1;
  unsigned int _PVDS:3;
  unsigned int _VREFEN:1;
  unsigned int _VREFSEL:2;
  unsigned int _LPDEBUG:1;
  unsigned int _P18LVLSENB:1;
  unsigned int _RAMECCEN:1;
  unsigned int _LPCANCLKS:1;
  unsigned int :4;
  unsigned int _LVL18OEN:1;
  unsigned int :5;
  unsigned int _BUFCLKDIV:3;
  unsigned int _BUFCLKEN:1;
  unsigned int _INTBUFEN:1;
  unsigned int _P18OE:1;
  unsigned int _TSOE:1;
  unsigned int _TSEN:1;
  unsigned int _LPBOREN:1;
  unsigned int _BOREN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_STA0_REG{
 unsigned int reg;
 struct PM_STA0_BITS{
  unsigned int _LPRSTA:1;
  unsigned int _LPRUNF:1;
  unsigned int :23;
  unsigned int _WSRSTF:1;
  unsigned int _BORF:1;
  unsigned int _PORF:1;
  unsigned int _WKPPINF:1;
  unsigned int :1;
  unsigned int _IWDTF:1;
  unsigned int _RSTFC:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_STA1_REG{
 unsigned int reg;
 struct PM_STA1_BITS{
  unsigned int _PVDSTA:1;
  unsigned int :17;
  unsigned int _STOPERROR:1;
  unsigned int _PMCERROR:1;
  unsigned int :2;
  unsigned int _POR18STA:1;
  unsigned int :3;
  unsigned int _PMCIF:1;
  unsigned int _WKP1STA:1;
  unsigned int _WKP2STA:1;
  unsigned int _WKP3STA:1;
  unsigned int _WKP4STA:1;
  unsigned int _WKP5STA:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_STAC_REG{
 unsigned int reg;
 struct PM_STAC_BITS{
  unsigned int :25;
  unsigned int _IWDTDBGEN:1;
  unsigned int _PMCIC:1;
  unsigned int _WKP1SC:1;
  unsigned int _WKP2SC:1;
  unsigned int _WKP3SC:1;
  unsigned int _WKP4SC:1;
  unsigned int _WKP5SC:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_CTL2_REG{
 unsigned int reg;
 struct PM_CTL2_BITS{
  unsigned int _CANFD6LPEN:1;
  unsigned int _CCP0LPEN:1;
  unsigned int _EWDTLPEN:1;
  unsigned int _USART0LPEN:1;
  unsigned int _CANFD6CLKLPEN:1;
  unsigned int _CCP0CLKLPEN:1;
  unsigned int _EWDTCLKLPEN:1;
  unsigned int _USART0CLKLPEN:1;
  unsigned int _POR18SHD:1;
  unsigned int _VF12INF0:1;
  unsigned int _VF12INF1:1;
  unsigned int _VF12EN:1;
  unsigned int :2;
  unsigned int _RTCLPEN:1;
  unsigned int _RTCCLKLPEN:1;
  unsigned int _QEI0CLKLPEN:1;
  unsigned int _GPIOALPEN:1;
  unsigned int _QEI0LPEN:1;
  unsigned int _PMCIE:1;
  unsigned int :2;
  unsigned int _WKP1P:1;
  unsigned int _WKP2P:1;
  unsigned int _WKP3P:1;
  unsigned int _WKP4P:1;
  unsigned int _WKP5P:1;
  unsigned int _WKP1EN:1;
  unsigned int _WKP2EN:1;
  unsigned int _WKP3EN:1;
  unsigned int _WKP4EN:1;
  unsigned int _WKP5EN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_CAL0_REG{
 unsigned int reg;
 struct PM_CAL0_BITS{
  unsigned int _BGTRIMFLLDO:5;
  unsigned int _BGTRIMMRLDO:5;
  unsigned int _NRSTOEN:1;
  unsigned int _NRST1EN:1;
  unsigned int :1;
  unsigned int _MRHVTRIM:2;
  unsigned int _MRHVEN:1;
  unsigned int _MRTRIM:2;
  unsigned int _BORVREFSEL:1;
  unsigned int _PMIWDTEN:1;
  unsigned int _BORSEL:2;
  unsigned int _FLBGEN:1;
  unsigned int _BORHSEN:1;
  unsigned int _ZEROTISTRIM:2;
  unsigned int _FLBG:3;
  unsigned int _LPRSEL:1;
  unsigned int _MRBGSEL:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_CAL1_REG{
 unsigned int reg;
 struct PM_CAL1_BITS{
  unsigned int _LSETRIMNBIAS:2;
  unsigned int _LSETRIMBIAS:4;
  unsigned int _LP4MTRIM:9;
  unsigned int _HSESEL:1;
  unsigned int _LPBGTRIMPUMP:3;
  unsigned int _LSESEL:1;
  unsigned int _LPTRIMBIAS:3;
  unsigned int _SPCPUR:1;
  unsigned int _LSITRIMCAP:5;
  unsigned int _LSITRIMBIAS:3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PM_CAL2_REG{
 unsigned int reg;
 struct PM_CAL2_BITS{
  unsigned int _MRDELAYS:2;
  unsigned int _VCOREDELAYS:2;
  unsigned int _LPRDELAYS:2;
  unsigned int :2;
  unsigned int _STOPTEST:1;
  unsigned int _POR12NODELAY:1;
  unsigned int _DELAYUSEHSI:1;
  unsigned int :1;
  unsigned int _ICSPCAL12EN:1;
  unsigned int _ICSPCAL13EN:1;
  unsigned int _PMCWKPSEL:1;
  unsigned int :1;
  unsigned int _BGTRIMREFBUF:6;
  unsigned int _CAPFREELDOIS:2;
  unsigned int _LPR12CAPLESSI:5;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR1_REG{
 unsigned int reg;
 struct DMA0_CTLR1_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR2_REG{
 unsigned int reg;
 struct DMA0_CTLR2_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR3_REG{
 unsigned int reg;
 struct DMA0_CTLR3_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR4_REG{
 unsigned int reg;
 struct DMA0_CTLR4_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR5_REG{
 unsigned int reg;
 struct DMA0_CTLR5_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR6_REG{
 unsigned int reg;
 struct DMA0_CTLR6_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CTLR7_REG{
 unsigned int reg;
 struct DMA0_CTLR7_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR1_REG{
 unsigned int reg;
 struct DMA0_PADDR1_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR2_REG{
 unsigned int reg;
 struct DMA0_PADDR2_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR3_REG{
 unsigned int reg;
 struct DMA0_PADDR3_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR4_REG{
 unsigned int reg;
 struct DMA0_PADDR4_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR5_REG{
 unsigned int reg;
 struct DMA0_PADDR5_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR6_REG{
 unsigned int reg;
 struct DMA0_PADDR6_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_PADDR7_REG{
 unsigned int reg;
 struct DMA0_PADDR7_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR1_REG{
 unsigned int reg;
 struct DMA0_MADDR1_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR2_REG{
 unsigned int reg;
 struct DMA0_MADDR2_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR3_REG{
 unsigned int reg;
 struct DMA0_MADDR3_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR4_REG{
 unsigned int reg;
 struct DMA0_MADDR4_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR5_REG{
 unsigned int reg;
 struct DMA0_MADDR5_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR6_REG{
 unsigned int reg;
 struct DMA0_MADDR6_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_MADDR7_REG{
 unsigned int reg;
 struct DMA0_MADDR7_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR1_REG{
 unsigned int reg;
 struct DMA0_CPAR1_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR2_REG{
 unsigned int reg;
 struct DMA0_CPAR2_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR3_REG{
 unsigned int reg;
 struct DMA0_CPAR3_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR4_REG{
 unsigned int reg;
 struct DMA0_CPAR4_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR5_REG{
 unsigned int reg;
 struct DMA0_CPAR5_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR6_REG{
 unsigned int reg;
 struct DMA0_CPAR6_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CPAR7_REG{
 unsigned int reg;
 struct DMA0_CPAR7_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR1_REG{
 unsigned int reg;
 struct DMA0_CMAR1_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR2_REG{
 unsigned int reg;
 struct DMA0_CMAR2_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR3_REG{
 unsigned int reg;
 struct DMA0_CMAR3_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR4_REG{
 unsigned int reg;
 struct DMA0_CMAR4_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR5_REG{
 unsigned int reg;
 struct DMA0_CMAR5_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR6_REG{
 unsigned int reg;
 struct DMA0_CMAR6_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_CMAR7_REG{
 unsigned int reg;
 struct DMA0_CMAR7_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT1_REG{
 unsigned int reg;
 struct DMA0_NCT1_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT2_REG{
 unsigned int reg;
 struct DMA0_NCT2_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT3_REG{
 unsigned int reg;
 struct DMA0_NCT3_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT4_REG{
 unsigned int reg;
 struct DMA0_NCT4_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT5_REG{
 unsigned int reg;
 struct DMA0_NCT5_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT6_REG{
 unsigned int reg;
 struct DMA0_NCT6_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_NCT7_REG{
 unsigned int reg;
 struct DMA0_NCT7_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_LIFR_REG{
 unsigned int reg;
 struct DMA0_LIFR_BITS{
  unsigned int _FTIF1:1;
  unsigned int _HTIF1:1;
  unsigned int _ETIF1:1;
  unsigned int _FTIF2:1;
  unsigned int _HTIF2:1;
  unsigned int _ETIF2:1;
  unsigned int _FTIF3:1;
  unsigned int _HTIF3:1;
  unsigned int _ETIF3:1;
  unsigned int _FTIF4:1;
  unsigned int _HTIF4:1;
  unsigned int _ETIF4:1;
  unsigned int _FTIF5:1;
  unsigned int _HTIF5:1;
  unsigned int _ETIF5:1;
  unsigned int _FTIF6:1;
  unsigned int _HTIF6:1;
  unsigned int _ETIF6:1;
  unsigned int _FTIF7:1;
  unsigned int _HTIF7:1;
  unsigned int _ETIF7:1;
  unsigned int :11;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA0_LIER_REG{
 unsigned int reg;
 struct DMA0_LIER_BITS{
  unsigned int _FTIE1:1;
  unsigned int _HTIE1:1;
  unsigned int _ETIE1:1;
  unsigned int _FTIE2:1;
  unsigned int _HTIE2:1;
  unsigned int _ETIE2:1;
  unsigned int _FTIE3:1;
  unsigned int _HTIE3:1;
  unsigned int _ETIE3:1;
  unsigned int _FTIE4:1;
  unsigned int _HTIE4:1;
  unsigned int _ETIE4:1;
  unsigned int _FTIE5:1;
  unsigned int _HTIE5:1;
  unsigned int _ETIE5:1;
  unsigned int _FTIE6:1;
  unsigned int _HTIE6:1;
  unsigned int _ETIE6:1;
  unsigned int _FTIE7:1;
  unsigned int _HTIE7:1;
  unsigned int _ETIE7:1;
  unsigned int :11;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR1_REG{
 unsigned int reg;
 struct DMA1_CTLR1_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR2_REG{
 unsigned int reg;
 struct DMA1_CTLR2_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR3_REG{
 unsigned int reg;
 struct DMA1_CTLR3_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR4_REG{
 unsigned int reg;
 struct DMA1_CTLR4_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR5_REG{
 unsigned int reg;
 struct DMA1_CTLR5_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR6_REG{
 unsigned int reg;
 struct DMA1_CTLR6_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CTLR7_REG{
 unsigned int reg;
 struct DMA1_CTLR7_BITS{
  unsigned int _DMAEN:1;
  unsigned int :2;
  unsigned int _BLKM:1;
  unsigned int _DDIR:1;
  unsigned int _LPM:1;
  unsigned int _MINC:1;
  unsigned int _PINC:1;
  unsigned int _MDS:2;
  unsigned int _PDS:2;
  unsigned int _ONESHOT:1;
  unsigned int _CPL:2;
  unsigned int _M2M:1;
  unsigned int _NUMODT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR1_REG{
 unsigned int reg;
 struct DMA1_PADDR1_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR2_REG{
 unsigned int reg;
 struct DMA1_PADDR2_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR3_REG{
 unsigned int reg;
 struct DMA1_PADDR3_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR4_REG{
 unsigned int reg;
 struct DMA1_PADDR4_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR5_REG{
 unsigned int reg;
 struct DMA1_PADDR5_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR6_REG{
 unsigned int reg;
 struct DMA1_PADDR6_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_PADDR7_REG{
 unsigned int reg;
 struct DMA1_PADDR7_BITS{
  unsigned int _PADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR1_REG{
 unsigned int reg;
 struct DMA1_MADDR1_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR2_REG{
 unsigned int reg;
 struct DMA1_MADDR2_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR3_REG{
 unsigned int reg;
 struct DMA1_MADDR3_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR4_REG{
 unsigned int reg;
 struct DMA1_MADDR4_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR5_REG{
 unsigned int reg;
 struct DMA1_MADDR5_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR6_REG{
 unsigned int reg;
 struct DMA1_MADDR6_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_MADDR7_REG{
 unsigned int reg;
 struct DMA1_MADDR7_BITS{
  unsigned int _MADDR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR1_REG{
 unsigned int reg;
 struct DMA1_CPAR1_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR2_REG{
 unsigned int reg;
 struct DMA1_CPAR2_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR3_REG{
 unsigned int reg;
 struct DMA1_CPAR3_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR4_REG{
 unsigned int reg;
 struct DMA1_CPAR4_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR5_REG{
 unsigned int reg;
 struct DMA1_CPAR5_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR6_REG{
 unsigned int reg;
 struct DMA1_CPAR6_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CPAR7_REG{
 unsigned int reg;
 struct DMA1_CPAR7_BITS{
  unsigned int _CPAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR1_REG{
 unsigned int reg;
 struct DMA1_CMAR1_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR2_REG{
 unsigned int reg;
 struct DMA1_CMAR2_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR3_REG{
 unsigned int reg;
 struct DMA1_CMAR3_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR4_REG{
 unsigned int reg;
 struct DMA1_CMAR4_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR5_REG{
 unsigned int reg;
 struct DMA1_CMAR5_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR6_REG{
 unsigned int reg;
 struct DMA1_CMAR6_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_CMAR7_REG{
 unsigned int reg;
 struct DMA1_CMAR7_BITS{
  unsigned int _CMAR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT1_REG{
 unsigned int reg;
 struct DMA1_NCT1_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT2_REG{
 unsigned int reg;
 struct DMA1_NCT2_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT13_REG{
 unsigned int reg;
 struct DMA1_NCT13_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT4_REG{
 unsigned int reg;
 struct DMA1_NCT4_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT5_REG{
 unsigned int reg;
 struct DMA1_NCT5_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT6_REG{
 unsigned int reg;
 struct DMA1_NCT6_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_NCT7_REG{
 unsigned int reg;
 struct DMA1_NCT7_BITS{
  unsigned int :16;
  unsigned int _NCT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_LIFR_REG{
 unsigned int reg;
 struct DMA1_LIFR_BITS{
  unsigned int _FTIF1:1;
  unsigned int _HTIF1:1;
  unsigned int _ETIF1:1;
  unsigned int _FTIF2:1;
  unsigned int _HTIF2:1;
  unsigned int _ETIF2:1;
  unsigned int _FTIF3:1;
  unsigned int _HTIF3:1;
  unsigned int _ETIF3:1;
  unsigned int _FTIF4:1;
  unsigned int _HTIF4:1;
  unsigned int _ETIF4:1;
  unsigned int _FTIF5:1;
  unsigned int _HTIF5:1;
  unsigned int _ETIF5:1;
  unsigned int _FTIF6:1;
  unsigned int _HTIF6:1;
  unsigned int _ETIF6:1;
  unsigned int _FTIF7:1;
  unsigned int _HTIF7:1;
  unsigned int _ETIF7:1;
  unsigned int :11;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_LIER_REG{
 unsigned int reg;
 struct DMA1_LIER_BITS{
  unsigned int _FTIE1:1;
  unsigned int _HTIE1:1;
  unsigned int _ETIE1:1;
  unsigned int _FTIE2:1;
  unsigned int _HTIE2:1;
  unsigned int _ETIE2:1;
  unsigned int _FTIE3:1;
  unsigned int _HTIE3:1;
  unsigned int _ETIE3:1;
  unsigned int _FTIE4:1;
  unsigned int _HTIE4:1;
  unsigned int _ETIE4:1;
  unsigned int _FTIE5:1;
  unsigned int _HTIE5:1;
  unsigned int _ETIE5:1;
  unsigned int _FTIE6:1;
  unsigned int _HTIE6:1;
  unsigned int _ETIE6:1;
  unsigned int _FTIE7:1;
  unsigned int _HTIF7:1;
  unsigned int _ETIE7:1;
  unsigned int :11;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union DMA1_REMAP_REG{
 unsigned int reg;
 struct DMA1_REMAP_BITS{
  unsigned int _REMAP0:1;
  unsigned int _REMAP1:1;
  unsigned int _REMAP2:1;
  unsigned int _REMAP3:1;
  unsigned int _REMAP4:1;
  unsigned int _REMAP5:1;
  unsigned int _REMAP6:1;
  unsigned int _REMAP7:1;
  unsigned int _REMAP8:1;
  unsigned int _REMAP9:1;
  unsigned int _REMAP10:1;
  unsigned int _REMAP11:1;
  unsigned int _REMAP12:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_CNT_REG{
 unsigned int reg;
 struct T14_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_CTL1_REG{
 unsigned int reg;
 struct T14_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int _TXSY:1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int _TRGSEL:2;
  unsigned int _TCKSEL:2;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_CTL2_REG{
 unsigned int reg;
 struct T14_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS:2;
  unsigned int _TXSMS:3;
  unsigned int _TXTS:4;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _PXSPMST:1;
  unsigned int _PXSPM:1;
  unsigned int _TXTRG:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_PRSC_REG{
 unsigned int reg;
 struct T14_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_PPX_REG{
 unsigned int reg;
 struct T14_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_DIER_REG{
 unsigned int reg;
 struct T14_DIER_BITS{
  unsigned int _TXUIE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXIE:1;
  unsigned int _TXUDE:1;
  unsigned int _TXTDE:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_SR_REG{
 unsigned int reg;
 struct T14_SR_BITS{
  unsigned int _TXUIF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXIF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T14_SRIC_REG{
 unsigned int reg;
 struct T14_SRIC_BITS{
  unsigned int _TXUIC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXIC:1;
  unsigned int :29;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T11_CNT_REG{
 unsigned int reg;
 struct T11_CNT_BITS{
  unsigned int _TXCNT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T11_PHS_REG{
 unsigned int reg;
 struct T11_PHS_BITS{
  unsigned int _TXPHS:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T11_PPX_REG{
 unsigned int reg;
 struct T11_PPX_BITS{
  unsigned int _PPX:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T11_PRSC_REG{
 unsigned int reg;
 struct T11_PRSC_BITS{
  unsigned int _TXPRSC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T11_CTL_REG{
 unsigned int reg;
 struct T11_CTL_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int _TXGATE:1;
  unsigned int _TXSY:1;
  unsigned int _TXCLK0:1;
  unsigned int _TXCLK1:1;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS0:1;
  unsigned int _TXCMS1:1;
  unsigned int _TXCMS2:1;
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXUR:1;
  unsigned int _SYNCI:1;
  unsigned int _PHSEN:1;
  unsigned int _SYNCOSEL0:1;
  unsigned int _SYNCOSEL1:1;
  unsigned int _SWFSYNC:1;
  unsigned int _PHSDIR:1;
  unsigned int _TXMAX:1;
  unsigned int _CAPSEL:2;
  unsigned int _CAPEN:1;
  unsigned int _AQLOCKA:1;
  unsigned int _AQLOCKB:1;
  unsigned int _DBLOCK:1;
  unsigned int _PCLOCK:1;
  unsigned int _ETLOCK:1;
  unsigned int _HRLOCK:1;
  unsigned int _UDSYNEN:1;
  unsigned int _LINKEN:1;
  unsigned int _BLINKEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_RA_REG{
 unsigned int reg;
 struct EPWM11_RA_BITS{
  unsigned int _EPWMRA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_RB_REG{
 unsigned int reg;
 struct EPWM11_RB_BITS{
  unsigned int _EPWMRB:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_CTLA_REG{
 unsigned int reg;
 struct EPWM11_CTLA_BITS{
  unsigned int _AZRO:2;
  unsigned int _APRD:2;
  unsigned int _ACAU:2;
  unsigned int _ACAD:2;
  unsigned int _ACBU:2;
  unsigned int _ACBD:2;
  unsigned int _CSFA:2;
  unsigned int _ACTSFA:2;
  unsigned int _OTSFA:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_CTLB_REG{
 unsigned int reg;
 struct EPWM11_CTLB_BITS{
  unsigned int _BZRO:2;
  unsigned int _BPRD:2;
  unsigned int _BCAU:2;
  unsigned int _BCAD:2;
  unsigned int _BCBU:2;
  unsigned int _BCBD:2;
  unsigned int _CSFB:2;
  unsigned int _ACTSFB:2;
  unsigned int _OTSFB:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_DBCTL_REG{
 unsigned int reg;
 struct EPWM11_DBCTL_BITS{
  unsigned int _OUTMODE:2;
  unsigned int _POLSEL:2;
  unsigned int _INMODE:2;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_DBT_REG{
 unsigned int reg;
 struct EPWM11_DBT_BITS{
  unsigned int _FDBT:16;
  unsigned int _RDBT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_PCCTL_REG{
 unsigned int reg;
 struct EPWM11_PCCTL_BITS{
  unsigned int _CHPEN:1;
  unsigned int _OSHTWTH:4;
  unsigned int _CHPDUTY:3;
  unsigned int _CHPFREQ:3;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_PXASCTL_REG{
 unsigned int reg;
 struct EPWM11_PXASCTL_BITS{
  unsigned int _PXASS:3;
  unsigned int _PXASE:1;
  unsigned int _PXSSB:2;
  unsigned int _PXSSA:2;
  unsigned int _PXRSEN:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_ETCTL_REG{
 unsigned int reg;
 struct EPWM11_ETCTL_BITS{
  unsigned int _TOADENA:1;
  unsigned int _SELA:2;
  unsigned int _FRCA:1;
  unsigned int _APP:2;
  unsigned int _AT:2;
  unsigned int _ATSEL:2;
  unsigned int :6;
  unsigned int _TOADENB:1;
  unsigned int _SELB:2;
  unsigned int _FRCB:1;
  unsigned int _BPP:2;
  unsigned int _BT:2;
  unsigned int _BTSEL:2;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_IE_REG{
 unsigned int reg;
 struct EPWM11_IE_BITS{
  unsigned int _TXTIE0:1;
  unsigned int _TXTIE1:1;
  unsigned int _TXGIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXIE:1;
  unsigned int _TXBIE:1;
  unsigned int _TXAIE:1;
  unsigned int _TXCIE:1;
  unsigned int _TXDIE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_IF_REG{
 unsigned int reg;
 struct EPWM11_IF_BITS{
  unsigned int _TXTIF0:1;
  unsigned int _TXTIF1:1;
  unsigned int _TXGIF:1;
  unsigned int _TXUIF:1;
  unsigned int _TXIF:1;
  unsigned int _TXBIF:1;
  unsigned int _TXAIF:1;
  unsigned int _TXCIF:1;
  unsigned int _TXDIF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_IC_REG{
 unsigned int reg;
 struct EPWM11_IC_BITS{
  unsigned int _TXTIC0:1;
  unsigned int _TXTIC1:1;
  unsigned int _TXGIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int _TXBIC:1;
  unsigned int _TXAIC:1;
  unsigned int _TXCIC:1;
  unsigned int _TXDIC:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_DE_REG{
 unsigned int reg;
 struct EPWM11_DE_BITS{
  unsigned int _TXTDE0:1;
  unsigned int _TXTDE1:1;
  unsigned int _TXGDE:1;
  unsigned int _TXUDE:1;
  unsigned int _TXDE:1;
  unsigned int _TXBDE:1;
  unsigned int _TXADE:1;
  unsigned int _TXCDE:1;
  unsigned int _TXDDE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_DF_REG{
 unsigned int reg;
 struct EPWM11_DF_BITS{
  unsigned int _TXTDF0:1;
  unsigned int _TXTDF1:1;
  unsigned int _TXGDF:1;
  unsigned int _TXUDF:1;
  unsigned int _TXDF:1;
  unsigned int _TXBDF:1;
  unsigned int _TXADF:1;
  unsigned int _TXCDF:1;
  unsigned int _TXDDF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_HRPWMCTL_REG{
 unsigned int reg;
 struct EPWM11_HRPWMCTL_BITS{
  unsigned int _HRPEN:1;
  unsigned int _HRPOUTB:1;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_HRCMP_REG{
 unsigned int reg;
 struct EPWM11_HRCMP_BITS{
  unsigned int _HRCMP:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_CAP_REG{
 unsigned int reg;
 struct EPWM11_CAP_BITS{
  unsigned int _CAP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_RC_REG{
 unsigned int reg;
 struct EPWM11_RC_BITS{
  unsigned int _EPWMRC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_RD_REG{
 unsigned int reg;
 struct EPWM11_RD_BITS{
  unsigned int _EPWMRD:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM11_UDCTL_REG{
 unsigned int reg;
 struct EPWM11_UDCTL_BITS{
  unsigned int _PPUDEN:1;
  unsigned int _PPUDSEL:2;
  unsigned int _PRUDEN:1;
  unsigned int _PRUDSEL:2;
  unsigned int _CMAUDEN:1;
  unsigned int _CMAUDSEL:2;
  unsigned int _CMBUDEN:1;
  unsigned int _CMBUDSEL:2;
  unsigned int _CMCUDEN:1;
  unsigned int _CMCUDSEL:2;
  unsigned int _CMDUDEN:1;
  unsigned int _CMDUDSEL:2;
  unsigned int _EAUDEN:1;
  unsigned int _EAUDSEL:2;
  unsigned int _EBUDEN:1;
  unsigned int _EBUDSEL:2;
  unsigned int _HRPUDEN:1;
  unsigned int _HRPUDSEL:2;
  unsigned int _GBUDEN:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T12_CNT_REG{
 unsigned int reg;
 struct T12_CNT_BITS{
  unsigned int _TXCNT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T12_PHS_REG{
 unsigned int reg;
 struct T12_PHS_BITS{
  unsigned int _TXPHS:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T12_PPX_REG{
 unsigned int reg;
 struct T12_PPX_BITS{
  unsigned int _PPX:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T12_PRSC_REG{
 unsigned int reg;
 struct T12_PRSC_BITS{
  unsigned int _TXPRSC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T12_CTL_REG{
 unsigned int reg;
 struct T12_CTL_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int _TXGATE:1;
  unsigned int _TXSY:1;
  unsigned int _TXCLK0:1;
  unsigned int _TXCLK1:1;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS0:1;
  unsigned int _TXCMS1:1;
  unsigned int _TXCMS2:1;
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXUR:1;
  unsigned int _SYNCI:1;
  unsigned int _PHSEN:1;
  unsigned int _SYNCOSEL0:1;
  unsigned int _SYNCOSEL1:1;
  unsigned int _SWFSYNC:1;
  unsigned int _PHSDIR:1;
  unsigned int _TXMAX:1;
  unsigned int _CAPSEL:2;
  unsigned int _CAPEN:1;
  unsigned int _AQLOCKA:1;
  unsigned int _AQLOCKB:1;
  unsigned int _DBLOCK:1;
  unsigned int _PCLOCK:1;
  unsigned int _ETLOCK:1;
  unsigned int _HRLOCK:1;
  unsigned int _UDSYNEN:1;
  unsigned int _LINKEN:1;
  unsigned int _BLINKEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_RA_REG{
 unsigned int reg;
 struct EPWM12_RA_BITS{
  unsigned int _EPWMRA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_RB_REG{
 unsigned int reg;
 struct EPWM12_RB_BITS{
  unsigned int _EPWMRB:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_CTLA_REG{
 unsigned int reg;
 struct EPWM12_CTLA_BITS{
  unsigned int _AZRO:2;
  unsigned int _APRD:2;
  unsigned int _ACAU:2;
  unsigned int _ACAD:2;
  unsigned int _ACBU:2;
  unsigned int _ACBD:2;
  unsigned int _CSFA:2;
  unsigned int _ACTSFA:2;
  unsigned int _OTSFA:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_CTLB_REG{
 unsigned int reg;
 struct EPWM12_CTLB_BITS{
  unsigned int _BZRO:2;
  unsigned int _BPRD:2;
  unsigned int _BCAU:2;
  unsigned int _BCAD:2;
  unsigned int _BCBU:2;
  unsigned int _BCBD:2;
  unsigned int _CSFB:2;
  unsigned int _ACTSFB:2;
  unsigned int _OTSFB:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_DBCTL_REG{
 unsigned int reg;
 struct EPWM12_DBCTL_BITS{
  unsigned int _OUTMODE:2;
  unsigned int _POLSEL:2;
  unsigned int _INMODE:2;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_DBT_REG{
 unsigned int reg;
 struct EPWM12_DBT_BITS{
  unsigned int _FDBT:16;
  unsigned int _RDBT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_PCCTL_REG{
 unsigned int reg;
 struct EPWM12_PCCTL_BITS{
  unsigned int _CHPEN:1;
  unsigned int _OSHTWTH:4;
  unsigned int _CHPDUTY:3;
  unsigned int _CHPFREQ:3;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_PXASCTL_REG{
 unsigned int reg;
 struct EPWM12_PXASCTL_BITS{
  unsigned int _PXASS:3;
  unsigned int _PXASE:1;
  unsigned int _PXSSB:2;
  unsigned int _PXSSA:2;
  unsigned int _PXRSEN:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_ETCTL_REG{
 unsigned int reg;
 struct EPWM12_ETCTL_BITS{
  unsigned int _TOADENA:1;
  unsigned int _SELA:2;
  unsigned int _FRCA:1;
  unsigned int _APP:2;
  unsigned int _AT:2;
  unsigned int _ATSEL:2;
  unsigned int :6;
  unsigned int _TOADENB:1;
  unsigned int _SELB:2;
  unsigned int _FRCB:1;
  unsigned int _BPP:2;
  unsigned int _BT:2;
  unsigned int _BTSEL:2;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_IE_REG{
 unsigned int reg;
 struct EPWM12_IE_BITS{
  unsigned int _TXTIE0:1;
  unsigned int _TXTIE1:1;
  unsigned int _TXGIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXIE:1;
  unsigned int _TXBIE:1;
  unsigned int _TXAIE:1;
  unsigned int _TXCIE:1;
  unsigned int _TXDIE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_IF_REG{
 unsigned int reg;
 struct EPWM12_IF_BITS{
  unsigned int _TXTIF0:1;
  unsigned int _TXTIF1:1;
  unsigned int _TXGIF:1;
  unsigned int _TXUIF:1;
  unsigned int _TXIF:1;
  unsigned int _TXBIF:1;
  unsigned int _TXAIF:1;
  unsigned int _TXCIF:1;
  unsigned int _TXDIF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_IC_REG{
 unsigned int reg;
 struct EPWM12_IC_BITS{
  unsigned int _TXTIC0:1;
  unsigned int _TXTIC1:1;
  unsigned int _TXGIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int _TXBIC:1;
  unsigned int _TXAIC:1;
  unsigned int _TXCIC:1;
  unsigned int _TXDIC:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_DE_REG{
 unsigned int reg;
 struct EPWM12_DE_BITS{
  unsigned int _TXTDE0:1;
  unsigned int _TXTDE1:1;
  unsigned int _TXGDE:1;
  unsigned int _TXUDE:1;
  unsigned int _TXDE:1;
  unsigned int _TXBDE:1;
  unsigned int _TXADE:1;
  unsigned int _TXCDE:1;
  unsigned int _TXDDE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_DF_REG{
 unsigned int reg;
 struct EPWM12_DF_BITS{
  unsigned int _TXTDF0:1;
  unsigned int _TXTDF1:1;
  unsigned int _TXGDF:1;
  unsigned int _TXUDF:1;
  unsigned int _TXDF:1;
  unsigned int _TXBDF:1;
  unsigned int _TXADF:1;
  unsigned int _TXCDF:1;
  unsigned int _TXDDF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_HRPWMCTL_REG{
 unsigned int reg;
 struct EPWM12_HRPWMCTL_BITS{
  unsigned int _HRPEN:1;
  unsigned int _HRPOUTB:1;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_HRCMP_REG{
 unsigned int reg;
 struct EPWM12_HRCMP_BITS{
  unsigned int _HRCMP:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_CAP_REG{
 unsigned int reg;
 struct EPWM12_CAP_BITS{
  unsigned int _CAP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_RC_REG{
 unsigned int reg;
 struct EPWM12_RC_BITS{
  unsigned int _EPWMRC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_RD_REG{
 unsigned int reg;
 struct EPWM12_RD_BITS{
  unsigned int _EPWMRD:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM12_UDCTL_REG{
 unsigned int reg;
 struct EPWM12_UDCTL_BITS{
  unsigned int _PPUDEN:1;
  unsigned int _PPUDSEL:2;
  unsigned int _PRUDEN:1;
  unsigned int _PRUDSEL:2;
  unsigned int _CMAUDEN:1;
  unsigned int _CMAUDSEL:2;
  unsigned int _CMBUDEN:1;
  unsigned int _CMBUDSEL:2;
  unsigned int _CMCUDEN:1;
  unsigned int _CMCUDSEL:2;
  unsigned int _CMDUDEN:1;
  unsigned int _CMDUDSEL:2;
  unsigned int _EAUDEN:1;
  unsigned int _EAUDSEL:2;
  unsigned int _EBUDEN:1;
  unsigned int _EBUDSEL:2;
  unsigned int _HRPUDEN:1;
  unsigned int _HRPUDSEL:2;
  unsigned int _GBUDEN:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T13_CNT_REG{
 unsigned int reg;
 struct T13_CNT_BITS{
  unsigned int _TXCNT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T13_PHS_REG{
 unsigned int reg;
 struct T13_PHS_BITS{
  unsigned int _TXPHS:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T13_PPX_REG{
 unsigned int reg;
 struct T13_PPX_BITS{
  unsigned int _PPX:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T13_PRSC_REG{
 unsigned int reg;
 struct T13_PRSC_BITS{
  unsigned int _TXPRSC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T13_CTL_REG{
 unsigned int reg;
 struct T13_CTL_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int _TXGATE:1;
  unsigned int _TXSY:1;
  unsigned int _TXCLK0:1;
  unsigned int _TXCLK1:1;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS0:1;
  unsigned int _TXCMS1:1;
  unsigned int _TXCMS2:1;
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXUR:1;
  unsigned int _SYNCI:1;
  unsigned int _PHSEN:1;
  unsigned int _SYNCOSEL0:1;
  unsigned int _SYNCOSEL1:1;
  unsigned int _SWFSYNC:1;
  unsigned int _PHSDIR:1;
  unsigned int _TXMAX:1;
  unsigned int _CAPSEL:2;
  unsigned int _CAPEN:1;
  unsigned int _AQLOCKA:1;
  unsigned int _AQLOCKB:1;
  unsigned int _DBLOCK:1;
  unsigned int _PCLOCK:1;
  unsigned int _ETLOCK:1;
  unsigned int _HRLOCK:1;
  unsigned int _UDSYNEN:1;
  unsigned int _LINKEN:1;
  unsigned int _BLINKEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_RA_REG{
 unsigned int reg;
 struct EPWM13_RA_BITS{
  unsigned int _EPWMRA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_RB_REG{
 unsigned int reg;
 struct EPWM13_RB_BITS{
  unsigned int _EPWMRB:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_CTLA_REG{
 unsigned int reg;
 struct EPWM13_CTLA_BITS{
  unsigned int _AZRO:2;
  unsigned int _APRD:2;
  unsigned int _ACAU:2;
  unsigned int _ACAD:2;
  unsigned int _ACBU:2;
  unsigned int _ACBD:2;
  unsigned int _CSFA:2;
  unsigned int _ACTSFA:2;
  unsigned int _OTSFA:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_CTLB_REG{
 unsigned int reg;
 struct EPWM13_CTLB_BITS{
  unsigned int _BZRO:2;
  unsigned int _BPRD:2;
  unsigned int _BCAU:2;
  unsigned int _BCAD:2;
  unsigned int _BCBU:2;
  unsigned int _BCBD:2;
  unsigned int _CSFB:2;
  unsigned int _ACTSFB:2;
  unsigned int _OTSFB:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_DBCTL_REG{
 unsigned int reg;
 struct EPWM13_DBCTL_BITS{
  unsigned int _OUTMODE:2;
  unsigned int _POLSEL:2;
  unsigned int _INMODE:2;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_DBT_REG{
 unsigned int reg;
 struct EPWM13_DBT_BITS{
  unsigned int _FDBT:16;
  unsigned int _RDBT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_PCCTL_REG{
 unsigned int reg;
 struct EPWM13_PCCTL_BITS{
  unsigned int _CHPEN:1;
  unsigned int _OSHTWTH:4;
  unsigned int _CHPDUTY:3;
  unsigned int _CHPFREQ:3;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_PXASCTL_REG{
 unsigned int reg;
 struct EPWM13_PXASCTL_BITS{
  unsigned int _PXASS:3;
  unsigned int _PXASE:1;
  unsigned int _PXSSB:2;
  unsigned int _PXSSA:2;
  unsigned int _PXRSEN:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_ETCTL_REG{
 unsigned int reg;
 struct EPWM13_ETCTL_BITS{
  unsigned int _TOADENA:1;
  unsigned int _SELA:2;
  unsigned int _FRCA:1;
  unsigned int _APP:2;
  unsigned int _AT:2;
  unsigned int _ATSEL:2;
  unsigned int :6;
  unsigned int _TOADENB:1;
  unsigned int _SELB:2;
  unsigned int _FRCB:1;
  unsigned int _BPP:2;
  unsigned int _BT:2;
  unsigned int _BTSEL:2;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_IE_REG{
 unsigned int reg;
 struct EPWM13_IE_BITS{
  unsigned int _TXTIE0:1;
  unsigned int _TXTIE1:1;
  unsigned int _TXGIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXIE:1;
  unsigned int _TXBIE:1;
  unsigned int _TXAIE:1;
  unsigned int _TXCIE:1;
  unsigned int _TXDIE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_IF_REG{
 unsigned int reg;
 struct EPWM13_IF_BITS{
  unsigned int _TXTIF0:1;
  unsigned int _TXTIF1:1;
  unsigned int _TXGIF:1;
  unsigned int _TXUIF:1;
  unsigned int _TXIF:1;
  unsigned int _TXBIF:1;
  unsigned int _TXAIF:1;
  unsigned int _TXCIF:1;
  unsigned int _TXDIF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_IC_REG{
 unsigned int reg;
 struct EPWM13_IC_BITS{
  unsigned int _TXTIC0:1;
  unsigned int _TXTIC1:1;
  unsigned int _TXGIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int _TXBIC:1;
  unsigned int _TXAIC:1;
  unsigned int _TXCIC:1;
  unsigned int _TXDIC:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_DE_REG{
 unsigned int reg;
 struct EPWM13_DE_BITS{
  unsigned int _TXTDE0:1;
  unsigned int _TXTDE1:1;
  unsigned int _TXGDE:1;
  unsigned int _TXUDE:1;
  unsigned int _TXDE:1;
  unsigned int _TXBDE:1;
  unsigned int _TXADE:1;
  unsigned int _TXCDE:1;
  unsigned int _TXDDE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_DF_REG{
 unsigned int reg;
 struct EPWM13_DF_BITS{
  unsigned int _TXTDF0:1;
  unsigned int _TXTDF1:1;
  unsigned int _TXGDF:1;
  unsigned int _TXUDF:1;
  unsigned int _TXDF:1;
  unsigned int _TXBDF:1;
  unsigned int _TXADF:1;
  unsigned int _TXCDF:1;
  unsigned int _TXDDF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_HRPWMCTL_REG{
 unsigned int reg;
 struct EPWM13_HRPWMCTL_BITS{
  unsigned int _HRPEN:1;
  unsigned int _HRPOUTB:1;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_HRCMP_REG{
 unsigned int reg;
 struct EPWM13_HRCMP_BITS{
  unsigned int _HRCMP:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_CAP_REG{
 unsigned int reg;
 struct EPWM13_CAP_BITS{
  unsigned int _CAP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_RC_REG{
 unsigned int reg;
 struct EPWM13_RC_BITS{
  unsigned int _EPWMRC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_RD_REG{
 unsigned int reg;
 struct EPWM13_RD_BITS{
  unsigned int _EPWMRD:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM13_UDCTL_REG{
 unsigned int reg;
 struct EPWM13_UDCTL_BITS{
  unsigned int _PPUDEN:1;
  unsigned int _PPUDSEL:2;
  unsigned int _PRUDEN:1;
  unsigned int _PRUDSEL:2;
  unsigned int _CMAUDEN:1;
  unsigned int _CMAUDSEL:2;
  unsigned int _CMBUDEN:1;
  unsigned int _CMBUDSEL:2;
  unsigned int _CMCUDEN:1;
  unsigned int _CMCUDSEL:2;
  unsigned int _CMDUDEN:1;
  unsigned int _CMDUDSEL:2;
  unsigned int _EAUDEN:1;
  unsigned int _EAUDSEL:2;
  unsigned int _EBUDEN:1;
  unsigned int _EBUDSEL:2;
  unsigned int _HRPUDEN:1;
  unsigned int _HRPUDSEL:2;
  unsigned int _GBUDEN:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T16_CNT_REG{
 unsigned int reg;
 struct T16_CNT_BITS{
  unsigned int _TXCNT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T16_PHS_REG{
 unsigned int reg;
 struct T16_PHS_BITS{
  unsigned int _TXPHS:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T16_PPX_REG{
 unsigned int reg;
 struct T16_PPX_BITS{
  unsigned int _PPX:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T16_PRSC_REG{
 unsigned int reg;
 struct T16_PRSC_BITS{
  unsigned int _TXPRSC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T16_CTL_REG{
 unsigned int reg;
 struct T16_CTL_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int _TXGATE:1;
  unsigned int _TXSY:1;
  unsigned int _TXCLK0:1;
  unsigned int _TXCLK1:1;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS0:1;
  unsigned int _TXCMS1:1;
  unsigned int _TXCMS2:1;
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXUR:1;
  unsigned int _SYNCI:1;
  unsigned int _PHSEN:1;
  unsigned int _SYNCOSEL0:1;
  unsigned int _SYNCOSEL1:1;
  unsigned int _SWFSYNC:1;
  unsigned int _PHSDIR:1;
  unsigned int _TXMAX:1;
  unsigned int _CAPSEL:2;
  unsigned int _CAPEN:1;
  unsigned int _AQLOCKA:1;
  unsigned int _AQLOCKB:1;
  unsigned int _DBLOCK:1;
  unsigned int _PCLOCK:1;
  unsigned int _ETLOCK:1;
  unsigned int _HRLOCK:1;
  unsigned int _UDSYNEN:1;
  unsigned int _LINKEN:1;
  unsigned int _BLINKEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_RA_REG{
 unsigned int reg;
 struct EPWM16_RA_BITS{
  unsigned int _EPWMRA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_RB_REG{
 unsigned int reg;
 struct EPWM16_RB_BITS{
  unsigned int _EPWMRB:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_CTLA_REG{
 unsigned int reg;
 struct EPWM16_CTLA_BITS{
  unsigned int _AZRO:2;
  unsigned int _APRD:2;
  unsigned int _ACAU:2;
  unsigned int _ACAD:2;
  unsigned int _ACBU:2;
  unsigned int _ACBD:2;
  unsigned int _CSFA:2;
  unsigned int _ACTSFA:2;
  unsigned int _OTSFA:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_CTLB_REG{
 unsigned int reg;
 struct EPWM16_CTLB_BITS{
  unsigned int _BZRO:2;
  unsigned int _BPRD:2;
  unsigned int _BCAU:2;
  unsigned int _BCAD:2;
  unsigned int _BCBU:2;
  unsigned int _BCBD:2;
  unsigned int _CSFB:2;
  unsigned int _ACTSFB:2;
  unsigned int _OTSFB:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_DBCTL_REG{
 unsigned int reg;
 struct EPWM16_DBCTL_BITS{
  unsigned int _OUTMODE:2;
  unsigned int _POLSEL:2;
  unsigned int _INMODE:2;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_DBT_REG{
 unsigned int reg;
 struct EPWM16_DBT_BITS{
  unsigned int _FDBT:16;
  unsigned int _RDBT:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_PCCTL_REG{
 unsigned int reg;
 struct EPWM16_PCCTL_BITS{
  unsigned int _CHPEN:1;
  unsigned int _OSHTWTH:4;
  unsigned int _CHPDUTY:3;
  unsigned int _CHPFREQ:3;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_PXASCTL_REG{
 unsigned int reg;
 struct EPWM16_PXASCTL_BITS{
  unsigned int _PXASS:3;
  unsigned int _PXASE:1;
  unsigned int _PXSSB:2;
  unsigned int _PXSSA:2;
  unsigned int _PXRSEN:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_ETCTL_REG{
 unsigned int reg;
 struct EPWM16_ETCTL_BITS{
  unsigned int _TOADENA:1;
  unsigned int _SELA:2;
  unsigned int _FRCA:1;
  unsigned int _APP:2;
  unsigned int _AT:2;
  unsigned int _ATSEL:2;
  unsigned int :6;
  unsigned int _TOADENB:1;
  unsigned int _SELB:2;
  unsigned int _FRCB:1;
  unsigned int _BPP:2;
  unsigned int _BT:2;
  unsigned int _BTSEL:2;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_IE_REG{
 unsigned int reg;
 struct EPWM16_IE_BITS{
  unsigned int _TXTIE0:1;
  unsigned int _TXTIE1:1;
  unsigned int _TXGIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXIE:1;
  unsigned int _TXBIE:1;
  unsigned int _TXAIE:1;
  unsigned int _TXCIE:1;
  unsigned int _TXDIE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_IF_REG{
 unsigned int reg;
 struct EPWM16_IF_BITS{
  unsigned int _TXTIF0:1;
  unsigned int _TXTIF1:1;
  unsigned int _TXGIF:1;
  unsigned int _TXUIF:1;
  unsigned int _TXIF:1;
  unsigned int _TXBIF:1;
  unsigned int _TXAIF:1;
  unsigned int _TXCIF:1;
  unsigned int _TXDIF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_IC_REG{
 unsigned int reg;
 struct EPWM16_IC_BITS{
  unsigned int _TXTIC0:1;
  unsigned int _TXTIC1:1;
  unsigned int _TXGIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int _TXBIC:1;
  unsigned int _TXAIC:1;
  unsigned int _TXCIC:1;
  unsigned int _TXDIC:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_DE_REG{
 unsigned int reg;
 struct EPWM16_DE_BITS{
  unsigned int _TXTDE0:1;
  unsigned int _TXTDE1:1;
  unsigned int _TXGDE:1;
  unsigned int _TXUDE:1;
  unsigned int _TXDE:1;
  unsigned int _TXBDE:1;
  unsigned int _TXADE:1;
  unsigned int _TXCDE:1;
  unsigned int _TXDDE:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_DF_REG{
 unsigned int reg;
 struct EPWM16_DF_BITS{
  unsigned int _TXTDF0:1;
  unsigned int _TXTDF1:1;
  unsigned int _TXGDF:1;
  unsigned int _TXUDF:1;
  unsigned int _TXDF:1;
  unsigned int _TXBDF:1;
  unsigned int _TXADF:1;
  unsigned int _TXCDF:1;
  unsigned int _TXDDF:1;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_HRPWMCTL_REG{
 unsigned int reg;
 struct EPWM16_HRPWMCTL_BITS{
  unsigned int _HRPEN:1;
  unsigned int _HRPOUTB:1;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_HRCMP_REG{
 unsigned int reg;
 struct EPWM16_HRCMP_BITS{
  unsigned int _HRCMP:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_CAP_REG{
 unsigned int reg;
 struct EPWM16_CAP_BITS{
  unsigned int _CAP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_RC_REG{
 unsigned int reg;
 struct EPWM16_RC_BITS{
  unsigned int _EPWMRC:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_RD_REG{
 unsigned int reg;
 struct EPWM16_RD_BITS{
  unsigned int _EPWMRD:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EPWM16_UDCTL_REG{
 unsigned int reg;
 struct EPWM16_UDCTL_BITS{
  unsigned int _PPUDEN:1;
  unsigned int _PPUDSEL:2;
  unsigned int _PRUDEN:1;
  unsigned int _PRUDSEL:2;
  unsigned int _CMAUDEN:1;
  unsigned int _CMAUDSEL:2;
  unsigned int _CMBUDEN:1;
  unsigned int _CMBUDSEL:2;
  unsigned int _CMCUDEN:1;
  unsigned int _CMCUDSEL:2;
  unsigned int _CMDUDEN:1;
  unsigned int _CMDUDSEL:2;
  unsigned int _EAUDEN:1;
  unsigned int _EAUDSEL:2;
  unsigned int _EBUDEN:1;
  unsigned int _EBUDSEL:2;
  unsigned int _HRPUDEN:1;
  unsigned int _HRPUDSEL:2;
  unsigned int _GBUDEN:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_CTL_REG{
 unsigned int reg;
 struct HC0_CTL_BITS{
  unsigned int _HCINSEL:1;
  unsigned int _RISEINTE:1;
  unsigned int _FALLINTE:1;
  unsigned int _OVERINTE:1;
  unsigned int _SOFTRESET:1;
  unsigned int _CLKSEL:2;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_COUNTER_REG{
 unsigned int reg;
 struct HC0_COUNTER_BITS{
  unsigned int _COUNTER:16;
  unsigned int _COUNTERSR:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_RISE0_REG{
 unsigned int reg;
 struct HC0_RISE0_BITS{
  unsigned int _RISE0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_RISE1_REG{
 unsigned int reg;
 struct HC0_RISE1_BITS{
  unsigned int _RISE1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_FALL0_REG{
 unsigned int reg;
 struct HC0_FALL0_BITS{
  unsigned int _FALL0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_FALL1_REG{
 unsigned int reg;
 struct HC0_FALL1_BITS{
  unsigned int _FALL1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_HRRISE0_REG{
 unsigned int reg;
 struct HC0_HRRISE0_BITS{
  unsigned int _HRRISE0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_HRRISE1_REG{
 unsigned int reg;
 struct HC0_HRRISE1_BITS{
  unsigned int _HRRISE1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_HRFALL0_REG{
 unsigned int reg;
 struct HC0_HRFALL0_BITS{
  unsigned int _HRFALL0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_HRFALL1_REG{
 unsigned int reg;
 struct HC0_HRFALL1_BITS{
  unsigned int _HRFALL1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_SR_REG{
 unsigned int reg;
 struct HC0_SR_BITS{
  unsigned int :1;
  unsigned int _RISEIF:1;
  unsigned int _FALLIF:1;
  unsigned int _COUNTEROVF:1;
  unsigned int _RISEOVF:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_SRIC_REG{
 unsigned int reg;
 struct HC0_SRIC_BITS{
  unsigned int :1;
  unsigned int _RISEIC:1;
  unsigned int _FALLIC:1;
  unsigned int _COUNTEROVC:1;
  unsigned int _RISEOVC:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC0_IFRC_REG{
 unsigned int reg;
 struct HC0_IFRC_BITS{
  unsigned int :1;
  unsigned int _RISEIFRC:1;
  unsigned int _FALLIFRC:1;
  unsigned int _COUNTEROVFRC:1;
  unsigned int :28;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_CTL_REG{
 unsigned int reg;
 struct HC1_CTL_BITS{
  unsigned int _HCINSEL:1;
  unsigned int _RISEINTE:1;
  unsigned int _FALLINTE:1;
  unsigned int _OVERINTE:1;
  unsigned int _SOFTRESET:1;
  unsigned int _CLKSEL:2;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_COUNTER_REG{
 unsigned int reg;
 struct HC1_COUNTER_BITS{
  unsigned int _COUNTER:16;
  unsigned int _COUNTERSR:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_RISE0_REG{
 unsigned int reg;
 struct HC1_RISE0_BITS{
  unsigned int _RISE0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_RISE1_REG{
 unsigned int reg;
 struct HC1_RISE1_BITS{
  unsigned int _RISE1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_FALL0_REG{
 unsigned int reg;
 struct HC1_FALL0_BITS{
  unsigned int _FALL0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_FALL1_REG{
 unsigned int reg;
 struct HC1_FALL1_BITS{
  unsigned int _FALL1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_HRRISE0_REG{
 unsigned int reg;
 struct HC1_HRRISE0_BITS{
  unsigned int _HRRISE0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_HRRISE1_REG{
 unsigned int reg;
 struct HC1_HRRISE1_BITS{
  unsigned int _HRRISE1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_HRFALL0_REG{
 unsigned int reg;
 struct HC1_HRFALL0_BITS{
  unsigned int _HRFALL0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_HRFALL1_REG{
 unsigned int reg;
 struct HC1_HRFALL1_BITS{
  unsigned int _HRFALL1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_SR_REG{
 unsigned int reg;
 struct HC1_SR_BITS{
  unsigned int :1;
  unsigned int _RISEIF:1;
  unsigned int _FALLIF:1;
  unsigned int _COUNTEROVF:1;
  unsigned int _RISEOVF:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_SRIC_REG{
 unsigned int reg;
 struct HC1_SRIC_BITS{
  unsigned int :1;
  unsigned int _RISEIC:1;
  unsigned int _FALLIC:1;
  unsigned int _COUNTEROVC:1;
  unsigned int _RISEOVC:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC1_IFRC_REG{
 unsigned int reg;
 struct HC1_IFRC_BITS{
  unsigned int :1;
  unsigned int _RISEIFRC:1;
  unsigned int _FALLIFRC:1;
  unsigned int _COUNTEROVFRC:1;
  unsigned int :28;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_CTL_REG{
 unsigned int reg;
 struct HC2_CTL_BITS{
  unsigned int _HCINSEL:1;
  unsigned int _RISEINTE:1;
  unsigned int _FALLINTE:1;
  unsigned int _OVERINTE:1;
  unsigned int _SOFTRESET:1;
  unsigned int _CLKSEL:2;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_COUNTER_REG{
 unsigned int reg;
 struct HC2_COUNTER_BITS{
  unsigned int _COUNTER:16;
  unsigned int _COUNTERSR:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_RISE0_REG{
 unsigned int reg;
 struct HC2_RISE0_BITS{
  unsigned int _RISE0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_RISE1_REG{
 unsigned int reg;
 struct HC2_RISE1_BITS{
  unsigned int _RISE1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_FALL0_REG{
 unsigned int reg;
 struct HC2_FALL0_BITS{
  unsigned int _FALL0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_FALL1_REG{
 unsigned int reg;
 struct HC2_FALL1_BITS{
  unsigned int _FALL1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_HRRISE0_REG{
 unsigned int reg;
 struct HC2_HRRISE0_BITS{
  unsigned int _HRRISE0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_HRRISE1_REG{
 unsigned int reg;
 struct HC2_HRRISE1_BITS{
  unsigned int _HRRISE1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_HRFALL0_REG{
 unsigned int reg;
 struct HC2_HRFALL0_BITS{
  unsigned int _HRFALL0:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_HRFALL1_REG{
 unsigned int reg;
 struct HC2_HRFALL1_BITS{
  unsigned int _HRFALL1:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_SR_REG{
 unsigned int reg;
 struct HC2_SR_BITS{
  unsigned int :1;
  unsigned int _RISEIF:1;
  unsigned int _FALLIF:1;
  unsigned int _COUNTEROVF:1;
  unsigned int _RISEOVF:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_SRIC_REG{
 unsigned int reg;
 struct HC2_SRIC_BITS{
  unsigned int :1;
  unsigned int _RISEIC:1;
  unsigned int _FALLIC:1;
  unsigned int _COUNTEROVC:1;
  unsigned int _RISEOVC:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union HC2_IFRC_REG{
 unsigned int reg;
 struct HC2_IFRC_BITS{
  unsigned int :1;
  unsigned int _RISEIFRC:1;
  unsigned int _FALLIFRC:1;
  unsigned int _COUNTEROVFRC:1;
  unsigned int :28;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RNG_CTL_REG{
 unsigned int reg;
 struct RNG_CTL_BITS{
  unsigned int _RNGEN:1;
  unsigned int _RNGSEL:1;
  unsigned int _CLKS:2;
  unsigned int _CLKDIV:4;
  unsigned int _TSEEDEN:1;
  unsigned int _TSEEDGO:1;
  unsigned int _ADD:2;
  unsigned int _HIPOW:1;
  unsigned int _RECEN:1;
  unsigned int _TRNGMS:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RNG_STATE_REG{
 unsigned int reg;
 struct RNG_STATE_BITS{
  unsigned int _DEIF:1;
  unsigned int _DRIF:1;
  unsigned int _TSRIF:1;
  unsigned int :1;
  unsigned int _DEIC:1;
  unsigned int _DRIC:1;
  unsigned int _TSRIC:1;
  unsigned int :1;
  unsigned int _DEIE:1;
  unsigned int _DRIE:1;
  unsigned int _TSRIE:1;
  unsigned int :1;
  unsigned int _HSPD0:1;
  unsigned int _HSPD1:1;
  unsigned int _READSEED:1;
  unsigned int _DEIS:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RNG_SEED_REG{
 unsigned int reg;
 struct RNG_SEED_BITS{
  unsigned int _SEED:32;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union RNG_DR_REG{
 unsigned int reg;
 struct RNG_DR_BITS{
  unsigned int _DR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T18_CNT_REG{
 unsigned int reg;
 struct T18_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T18_CTL1_REG{
 unsigned int reg;
 struct T18_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK0:1;
  unsigned int _TXCLK1:1;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS0:1;
  unsigned int _TXCMS1:1;
  unsigned int _TXCMS2:1;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T18_CTL2_REG{
 unsigned int reg;
 struct T18_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS:3;
  unsigned int _TXSMS:3;
  unsigned int _TXTS:4;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T18_PRSC_REG{
 unsigned int reg;
 struct T18_PRSC_BITS{
  unsigned int _TXCKS:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T18_PPX_REG{
 unsigned int reg;
 struct T18_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T18_UDTIMx_REG{
 unsigned int reg;
 struct T18_UDTIMx_BITS{
  unsigned int _TXUD0:1;
  unsigned int _TXUD1:1;
  unsigned int _TXUD2:1;
  unsigned int _TXUD3:1;
  unsigned int _TXUD4:1;
  unsigned int _TXUD5:1;
  unsigned int _TXUD6:1;
  unsigned int _TXUD7:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_C1_REG{
 unsigned int reg;
 struct CCP18_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_C2_REG{
 unsigned int reg;
 struct CCP18_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_C3_REG{
 unsigned int reg;
 struct CCP18_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_C4_REG{
 unsigned int reg;
 struct CCP18_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_SRIC_REG{
 unsigned int reg;
 struct CCP18_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_DF_REG{
 unsigned int reg;
 struct CCP18_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_CTL1_REG{
 unsigned int reg;
 struct CCP18_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_R1_REG{
 unsigned int reg;
 struct CCP18_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_R2_REG{
 unsigned int reg;
 struct CCP18_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_R3_REG{
 unsigned int reg;
 struct CCP18_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_R4_REG{
 unsigned int reg;
 struct CCP18_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_CTL2_REG{
 unsigned int reg;
 struct CCP18_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_CTL3_REG{
 unsigned int reg;
 struct CCP18_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP18_EGIF_REG{
 unsigned int reg;
 struct CCP18_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T19_CNT_REG{
 unsigned int reg;
 struct T19_CNT_BITS{
  unsigned int _TXCNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T19_CTL1_REG{
 unsigned int reg;
 struct T19_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T19_CTL2_REG{
 unsigned int reg;
 struct T19_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS:3;
  unsigned int _TXSMS:3;
  unsigned int _TXTS:4;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGRSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T19_PRSC_REG{
 unsigned int reg;
 struct T19_PRSC_BITS{
  unsigned int _TXCKS0:1;
  unsigned int _TXCKS1:1;
  unsigned int _TXCKS2:1;
  unsigned int _TXCKS3:1;
  unsigned int _TXCKS4:1;
  unsigned int _TXCKS5:1;
  unsigned int _TXCKS6:1;
  unsigned int _TXCKS7:1;
  unsigned int _TXCKS8:1;
  unsigned int _TXCKS9:1;
  unsigned int _TXCKS10:1;
  unsigned int _TXCKS11:1;
  unsigned int _TXCKS12:1;
  unsigned int _TXCKS13:1;
  unsigned int _TXCKS14:1;
  unsigned int _TXCKS15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T19_PPX_REG{
 unsigned int reg;
 struct T19_PPX_BITS{
  unsigned int _PPX:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T19_UDTIMx_REG{
 unsigned int reg;
 struct T19_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_C1_REG{
 unsigned int reg;
 struct CCP19_C1_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_C2_REG{
 unsigned int reg;
 struct CCP19_C2_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_C3_REG{
 unsigned int reg;
 struct CCP19_C3_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_C4_REG{
 unsigned int reg;
 struct CCP19_C4_BITS{
  unsigned int _CCPXCY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_SRIC_REG{
 unsigned int reg;
 struct CCP19_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_DF_REG{
 unsigned int reg;
 struct CCP19_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_CTL1_REG{
 unsigned int reg;
 struct CCP19_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_R1_REG{
 unsigned int reg;
 struct CCP19_R1_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_R2_REG{
 unsigned int reg;
 struct CCP19_R2_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_R3_REG{
 unsigned int reg;
 struct CCP19_R3_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_R4_REG{
 unsigned int reg;
 struct CCP19_R4_BITS{
  unsigned int _CCPXRY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_CTL2_REG{
 unsigned int reg;
 struct CCP19_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_CTL3_REG{
 unsigned int reg;
 struct CCP19_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP19_EGIF_REG{
 unsigned int reg;
 struct CCP19_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T21_CNT_REG{
 unsigned int reg;
 struct T21_CNT_BITS{
  unsigned int _TXCNT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T21_CTL1_REG{
 unsigned int reg;
 struct T21_CTL1_BITS{
  unsigned int _TXEN:1;
  unsigned int _TXCS:1;
  unsigned int :1;
  unsigned int _TXSY:1;
  unsigned int :1;
  unsigned int _TXCLK:2;
  unsigned int _TXDIR:1;
  unsigned int _TXCMS:3;
  unsigned int :1;
  unsigned int _TXIE:1;
  unsigned int _TXIF:1;
  unsigned int :18;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T21_CTL2_REG{
 unsigned int reg;
 struct T21_CTL2_BITS{
  unsigned int _TXUDEN:1;
  unsigned int _TXUDEVT:1;
  unsigned int _TXMMS:3;
  unsigned int _TXSMS:3;
  unsigned int _TXTS:4;
  unsigned int _TXMSSYNC:1;
  unsigned int _TXUR:1;
  unsigned int _TRGSEL:2;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T21_PRSC_REG{
 unsigned int reg;
 struct T21_PRSC_BITS{
  unsigned int _TXCKS:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T21_PPX_REG{
 unsigned int reg;
 struct T21_PPX_BITS{
  unsigned int _PPX:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union T21_UDTIMx_REG{
 unsigned int reg;
 struct T21_UDTIMx_BITS{
  unsigned int _TXUD:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_C1_REG{
 unsigned int reg;
 struct CCP21_C1_BITS{
  unsigned int _CCPXCY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_C2_REG{
 unsigned int reg;
 struct CCP21_C2_BITS{
  unsigned int _CCPXCY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_C3_REG{
 unsigned int reg;
 struct CCP21_C3_BITS{
  unsigned int _CCPXCY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_C4_REG{
 unsigned int reg;
 struct CCP21_C4_BITS{
  unsigned int _CCPXCY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_SRIC_REG{
 unsigned int reg;
 struct CCP21_SRIC_BITS{
  unsigned int _CC1IC:1;
  unsigned int _CC2IC:1;
  unsigned int _CC3IC:1;
  unsigned int _CC4IC:1;
  unsigned int _TXTIC:1;
  unsigned int _TXUIC:1;
  unsigned int _TXIC:1;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_DF_REG{
 unsigned int reg;
 struct CCP21_DF_BITS{
  unsigned int _CC1DF:1;
  unsigned int _CC2DF:1;
  unsigned int _CC3DF:1;
  unsigned int _CC4DF:1;
  unsigned int _TXTDF:1;
  unsigned int _TXUDF:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_CTL1_REG{
 unsigned int reg;
 struct CCP21_CTL1_BITS{
  unsigned int _CH1M:4;
  unsigned int _CH2M:4;
  unsigned int _CH3M:4;
  unsigned int _CH4M:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_R1_REG{
 unsigned int reg;
 struct CCP21_R1_BITS{
  unsigned int _CCPXRY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_R2_REG{
 unsigned int reg;
 struct CCP21_R2_BITS{
  unsigned int _CCPXRY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_R3_REG{
 unsigned int reg;
 struct CCP21_R3_BITS{
  unsigned int _CCPXRY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_R4_REG{
 unsigned int reg;
 struct CCP21_R4_BITS{
  unsigned int _CCPXRY:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_CTL2_REG{
 unsigned int reg;
 struct CCP21_CTL2_BITS{
  unsigned int _PXOC1:2;
  unsigned int _PXOC2:2;
  unsigned int _PXOC3:2;
  unsigned int _PXOC4:2;
  unsigned int _TCKSEL:2;
  unsigned int _PXASS:2;
  unsigned int _PXOC1CE:1;
  unsigned int _PXOC2CE:1;
  unsigned int _PXOC3CE:1;
  unsigned int _PXOC4CE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_CTL3_REG{
 unsigned int reg;
 struct CCP21_CTL3_BITS{
  unsigned int _CC1IE:1;
  unsigned int _CC2IE:1;
  unsigned int _CC3IE:1;
  unsigned int _CC4IE:1;
  unsigned int _TXTIE:1;
  unsigned int _TXUIE:1;
  unsigned int _TXUDE:1;
  unsigned int _CC1DE:1;
  unsigned int _CC2DE:1;
  unsigned int _CC3DE:1;
  unsigned int _CC4DE:1;
  unsigned int _TXTDE:1;
  unsigned int _PXSPM:1;
  unsigned int _PXXORM:1;
  unsigned int _PXPWMI:1;
  unsigned int _PXSPMST:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CCP21_EGIF_REG{
 unsigned int reg;
 struct CCP21_EGIF_BITS{
  unsigned int _UARTRXEN:1;
  unsigned int _CC1G:1;
  unsigned int _CC2G:1;
  unsigned int _CC3G:1;
  unsigned int _CC4G:1;
  unsigned int _TXTRG:1;
  unsigned int _CC1IF:1;
  unsigned int _CC2IF:1;
  unsigned int _CC3IF:1;
  unsigned int _CC4IF:1;
  unsigned int _TXTIF:1;
  unsigned int _TXUIF:1;
  unsigned int _PXSEL:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_CTLR_REG{
 unsigned int reg;
 struct USART5_CTLR_BITS{
  unsigned int _USARTEN:1;
  unsigned int _BRCKS:2;
  unsigned int _SCKPS:1;
  unsigned int _TCONV:1;
  unsigned int _RCONV:1;
  unsigned int _DINV:1;
  unsigned int _WUEN:1;
  unsigned int _CSRS:1;
  unsigned int _ADREN:1;
  unsigned int :1;
  unsigned int _ABRDEN:1;
  unsigned int _RIDLES:1;
  unsigned int _SENDB:1;
  unsigned int _SYNC:1;
  unsigned int _TXEN:1;
  unsigned int _RXEN:1;
  unsigned int _TIDLEEN:1;
  unsigned int _STPW:1;
  unsigned int _TX9SEL:1;
  unsigned int _PARM:1;
  unsigned int _DT9EN:1;
  unsigned int _TRGSEL:2;
  unsigned int _CTSE:1;
  unsigned int _RTSE:1;
  unsigned int _BKPWS:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _IRDAEN:1;
  unsigned int _RESHD:1;
  unsigned int _SLMEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_BRGR_REG{
 unsigned int reg;
 struct USART5_BRGR_BITS{
  unsigned int _BRGM:16;
  unsigned int _BRGF1:4;
  unsigned int _BRGF2:4;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_STR_REG{
 unsigned int reg;
 struct USART5_STR_BITS{
  unsigned int _OVFEIF:1;
  unsigned int _PAREIF:1;
  unsigned int _FREIF:1;
  unsigned int _BRIF:1;
  unsigned int _ABTOIF:1;
  unsigned int _WUIF:1;
  unsigned int _TEIF:1;
  unsigned int _REIF:1;
  unsigned int _CTSIF:1;
  unsigned int _RCFR:1;
  unsigned int _TXFR:1;
  unsigned int _RDRIF:1;
  unsigned int _TFEIF:1;
  unsigned int _TXEIF:1;
  unsigned int _UADMIF:1;
  unsigned int _IDLFIF:1;
  unsigned int _OVFEIC:1;
  unsigned int _PAREIC:1;
  unsigned int _FREIC:1;
  unsigned int _BRIC:1;
  unsigned int _ABTOIC:1;
  unsigned int _WUIC:1;
  unsigned int _TEIC:1;
  unsigned int _REIC:1;
  unsigned int _CTSIC:1;
  unsigned int _UADMIC:1;
  unsigned int _IDLEIC:1;
  unsigned int :1;
  unsigned int _CTSSEL:1;
  unsigned int _RXDSEL:1;
  unsigned int _TX1SEL:1;
  unsigned int _TX0SEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_TBUFR_REG{
 unsigned int reg;
 struct USART5_TBUFR_BITS{
  unsigned int _TBUF:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_RBUFR_REG{
 unsigned int reg;
 struct USART5_RBUFR_BITS{
  unsigned int _RBUF:9;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_U7816R_REG{
 unsigned int reg;
 struct USART5_U7816R_BITS{
  unsigned int _7816EN:1;
  unsigned int _CLKOUT:1;
  unsigned int _ERSW:2;
  unsigned int _PSEL:1;
  unsigned int _BGTEN:1;
  unsigned int :2;
  unsigned int _TREPEN:1;
  unsigned int _RREPEN:1;
  unsigned int _TXRE:2;
  unsigned int _RXRE:2;
  unsigned int _TREPMS:1;
  unsigned int _CLKDIV:8;
  unsigned int :1;
  unsigned int _EGT:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_IER_REG{
 unsigned int reg;
 struct USART5_IER_BITS{
  unsigned int _OVFEIE:1;
  unsigned int _PAREIE:1;
  unsigned int _FREIE:1;
  unsigned int _BRIE:1;
  unsigned int _ABTOIE:1;
  unsigned int _WUIE:1;
  unsigned int _TEIE:1;
  unsigned int _REIE:1;
  unsigned int _CTSIE:1;
  unsigned int _RDRIE:1;
  unsigned int _TFEIE:1;
  unsigned int _TXEIE:1;
  unsigned int _IDLEIE:1;
  unsigned int :3;
  unsigned int _URCDE:1;
  unsigned int _UTXDE:1;
  unsigned int _UADMIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART5_ADM_REG{
 unsigned int reg;
 struct USART5_ADM_BITS{
  unsigned int _ADM:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_CTLR_REG{
 unsigned int reg;
 struct USART7_CTLR_BITS{
  unsigned int _USARTEN:1;
  unsigned int _BRCKS:2;
  unsigned int _SCKPS:1;
  unsigned int _TCONV:1;
  unsigned int _RCONV:1;
  unsigned int _DINV:1;
  unsigned int _WUEN:1;
  unsigned int _CSRS:1;
  unsigned int _ADREN:1;
  unsigned int :1;
  unsigned int _ABRDEN:1;
  unsigned int _RIDLES:1;
  unsigned int _SENDB:1;
  unsigned int _SYNC:1;
  unsigned int _TXEN:1;
  unsigned int _RXEN:1;
  unsigned int _TIDLEEN:1;
  unsigned int _STPW:1;
  unsigned int _TX9SEL:1;
  unsigned int _PARM:1;
  unsigned int _DT9EN:1;
  unsigned int _TRGSEL:2;
  unsigned int _CTSE:1;
  unsigned int _RTSE:1;
  unsigned int _BKPWS:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _IRDAEN:1;
  unsigned int _RESHD:1;
  unsigned int _SLMEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_BRGR_REG{
 unsigned int reg;
 struct USART7_BRGR_BITS{
  unsigned int _BRGM:16;
  unsigned int _BRGF1:4;
  unsigned int _BRGF2:4;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_STR_REG{
 unsigned int reg;
 struct USART7_STR_BITS{
  unsigned int _OVFEIF:1;
  unsigned int _PAREIF:1;
  unsigned int _FREIF:1;
  unsigned int _BRIF:1;
  unsigned int _ABTOIF:1;
  unsigned int _WUIF:1;
  unsigned int _TEIF:1;
  unsigned int _REIF:1;
  unsigned int _CTSIF:1;
  unsigned int _RCFR:1;
  unsigned int _TXFR:1;
  unsigned int _RDRIF:1;
  unsigned int _TFEIF:1;
  unsigned int _TXEIF:1;
  unsigned int _UADMIF:1;
  unsigned int _IDLFIF:1;
  unsigned int _OVFEIC:1;
  unsigned int _PAREIC:1;
  unsigned int _FREIC:1;
  unsigned int _BRIC:1;
  unsigned int _ABTOIC:1;
  unsigned int _WUIC:1;
  unsigned int _TEIC:1;
  unsigned int _REIC:1;
  unsigned int _CTSIC:1;
  unsigned int _UADMIC:1;
  unsigned int _IDLEIC:1;
  unsigned int :1;
  unsigned int _CTSSEL:1;
  unsigned int _RXDSEL:1;
  unsigned int _TX1SEL:1;
  unsigned int _TX0SEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_TBUFR_REG{
 unsigned int reg;
 struct USART7_TBUFR_BITS{
  unsigned int _TBUF:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_RBUFR_REG{
 unsigned int reg;
 struct USART7_RBUFR_BITS{
  unsigned int _RBUF:9;
  unsigned int :23;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_U7816R_REG{
 unsigned int reg;
 struct USART7_U7816R_BITS{
  unsigned int _7816EN:1;
  unsigned int _CLKOUT:1;
  unsigned int _ERSW:2;
  unsigned int _PSEL:1;
  unsigned int _BGTEN:1;
  unsigned int :2;
  unsigned int _TREPEN:1;
  unsigned int _RREPEN:1;
  unsigned int _TXRE:2;
  unsigned int _RXRE:2;
  unsigned int _TREPMS:1;
  unsigned int _CLKDIV:8;
  unsigned int :1;
  unsigned int _EGT:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_IER_REG{
 unsigned int reg;
 struct USART7_IER_BITS{
  unsigned int _OVFEIE:1;
  unsigned int _PAREIE:1;
  unsigned int _FREIE:1;
  unsigned int _BRIE:1;
  unsigned int _ABTOIE:1;
  unsigned int _WUIE:1;
  unsigned int _TEIE:1;
  unsigned int _REIE:1;
  unsigned int _CTSIE:1;
  unsigned int _RDRIE:1;
  unsigned int _TFEIE:1;
  unsigned int _TXEIE:1;
  unsigned int _IDLEIE:1;
  unsigned int :3;
  unsigned int _URCDE:1;
  unsigned int _UTXDE:1;
  unsigned int _UADMIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union USART7_ADM_REG{
 unsigned int reg;
 struct USART7_ADM_BITS{
  unsigned int _ADM:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI2_BRGR_REG{
 unsigned int reg;
 struct SPI2_BRGR_BITS{
  unsigned int _SPIBRG:16;
  unsigned int _I2SDIV:8;
  unsigned int _MCKEN:1;
  unsigned int _I2SODD:1;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI2_CTLR_REG{
 unsigned int reg;
 struct SPI2_CTLR_BITS{
  unsigned int _SPIEN:1;
  unsigned int _SPIMS:3;
  unsigned int _SPICKS:2;
  unsigned int _SPIDS:1;
  unsigned int _SPIIOS:1;
  unsigned int _SPICKP:1;
  unsigned int _SPICKE:1;
  unsigned int :2;
  unsigned int _SPIBS:2;
  unsigned int _SSEL:2;
  unsigned int _I2SMD:1;
  unsigned int _SMINS:1;
  unsigned int _MCKOS:1;
  unsigned int _SPIPRCS:1;
  unsigned int _I2SMC:2;
  unsigned int _I2SSS:2;
  unsigned int _PCMS:1;
  unsigned int _I2SCKS:2;
  unsigned int _PCMCKP:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI2_BUFR_REG{
 unsigned int reg;
 struct SPI2_BUFR_BITS{
  unsigned int _SPIBUF:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI2_STR_REG{
 unsigned int reg;
 struct SPI2_STR_BITS{
  unsigned int _SPIBUSY:1;
  unsigned int _RNE:1;
  unsigned int _TNE:1;
  unsigned int _CHSIDE:1;
  unsigned int _ROVFIF:1;
  unsigned int _TOVFIF:1;
  unsigned int _UDRIF:1;
  unsigned int :4;
  unsigned int _UDRIE:1;
  unsigned int _ROVFIE:1;
  unsigned int _TOVFIE:1;
  unsigned int _RNEIE:1;
  unsigned int _TNEIE:1;
  unsigned int _ROVFIC:1;
  unsigned int _TOVFIC:1;
  unsigned int _UDRIC:1;
  unsigned int :1;
  unsigned int _SRCDE:1;
  unsigned int _STXDE:1;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI3_BRGR_REG{
 unsigned int reg;
 struct SPI3_BRGR_BITS{
  unsigned int _SPIBRG:16;
  unsigned int _I2SDIV:8;
  unsigned int _MCKEN:1;
  unsigned int _I2SODD:1;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI3_CTLR_REG{
 unsigned int reg;
 struct SPI3_CTLR_BITS{
  unsigned int _SPIEN:1;
  unsigned int _SPIMS:3;
  unsigned int _SPICKS:2;
  unsigned int _SPIDS:1;
  unsigned int _SPIIOS:1;
  unsigned int _SPICKP:1;
  unsigned int _SPICKE:1;
  unsigned int :2;
  unsigned int _SPIBS:2;
  unsigned int _SSEL:2;
  unsigned int _I2SMD:1;
  unsigned int _SMINS:1;
  unsigned int _MCKOS:1;
  unsigned int _SPIPRCS:1;
  unsigned int _I2SMC:2;
  unsigned int _I2SSS:2;
  unsigned int _PCMS:1;
  unsigned int _I2SCKS:2;
  unsigned int _PCMCKP:1;
  unsigned int :4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI3_BUFR_REG{
 unsigned int reg;
 struct SPI3_BUFR_BITS{
  unsigned int _SPIBUF:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SPI3_STR_REG{
 unsigned int reg;
 struct SPI3_STR_BITS{
  unsigned int _SPIBUSY:1;
  unsigned int _RNE:1;
  unsigned int _TNE:1;
  unsigned int _CHSIDE:1;
  unsigned int _ROVFIF:1;
  unsigned int _TOVFIF:1;
  unsigned int _UDRIF:1;
  unsigned int :4;
  unsigned int _UDRIE:1;
  unsigned int _ROVFIE:1;
  unsigned int _TOVFIE:1;
  unsigned int _RNEIE:1;
  unsigned int _TNEIE:1;
  unsigned int _ROVFIC:1;
  unsigned int _TOVFIC:1;
  unsigned int _UDRIC:1;
  unsigned int :1;
  unsigned int _SRCDE:1;
  unsigned int _STXDE:1;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_CTLR_REG{
 unsigned int reg;
 struct I2C3_CTLR_BITS{
  unsigned int _I2CEN:1;
  unsigned int _BADR10:1;
  unsigned int :2;
  unsigned int _DHCNT:4;
  unsigned int _SEN:1;
  unsigned int :1;
  unsigned int _PEN:1;
  unsigned int :1;
  unsigned int _ACKEN:1;
  unsigned int _ACKDT:1;
  unsigned int _GCEN:1;
  unsigned int :1;
  unsigned int _I2CCKS:2;
  unsigned int _I2CCKDIV:2;
  unsigned int _MTHALL:1;
  unsigned int _ENASCL:1;
  unsigned int _NMENA:1;
  unsigned int :1;
  unsigned int _SMBUS:1;
  unsigned int _SMBT:1;
  unsigned int _ARPEN:1;
  unsigned int _ALERT:1;
  unsigned int :3;
  unsigned int _ADRL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_SR_REG{
 unsigned int reg;
 struct I2C3_SR_BITS{
  unsigned int _SIF:1;
  unsigned int _PIF:1;
  unsigned int _ADDR:1;
  unsigned int _ADD10:1;
  unsigned int _DATA:1;
  unsigned int _AFIF:1;
  unsigned int _ARBLIF:1;
  unsigned int _RNW:1;
  unsigned int _SMBAIF:1;
  unsigned int _SMBHIF:1;
  unsigned int _SMBDIF:1;
  unsigned int _ISIF:1;
  unsigned int _RCBF:1;
  unsigned int _TXBE:1;
  unsigned int :2;
  unsigned int _IRCDF:1;
  unsigned int _ITXDF:1;
  unsigned int _BERRIF:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_BUFR_REG{
 unsigned int reg;
 struct I2C3_BUFR_BITS{
  unsigned int _I2CBUF:10;
  unsigned int :22;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_ADDR0_REG{
 unsigned int reg;
 struct I2C3_ADDR0_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_BRGR_REG{
 unsigned int reg;
 struct I2C3_BRGR_BITS{
  unsigned int _I2CBRGH:16;
  unsigned int _I2CBRGL:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_ADDR1_REG{
 unsigned int reg;
 struct I2C3_ADDR1_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_ADDR2_REG{
 unsigned int reg;
 struct I2C3_ADDR2_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_ADDR3_REG{
 unsigned int reg;
 struct I2C3_ADDR3_BITS{
  unsigned int _I2CADD:10;
  unsigned int :6;
  unsigned int _I2CMSK:10;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_IER_REG{
 unsigned int reg;
 struct I2C3_IER_BITS{
  unsigned int _SIE:1;
  unsigned int _PIE:1;
  unsigned int :3;
  unsigned int _AFIE:1;
  unsigned int _ARBLIE:1;
  unsigned int :1;
  unsigned int _SMBAIE:1;
  unsigned int _SMBHIE:1;
  unsigned int _SMBDIE:1;
  unsigned int _ISIE:1;
  unsigned int :4;
  unsigned int _IRCDE:1;
  unsigned int _ITXDE:1;
  unsigned int _BERRIE:1;
  unsigned int :13;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union I2C3_TPSR_REG{
 unsigned int reg;
 struct I2C3_TPSR_BITS{
  unsigned int _I2CTPS0:1;
  unsigned int _I2CTPS1:1;
  unsigned int _I2CTPS2:1;
  unsigned int _I2CTPS3:1;
  unsigned int _I2CTPS4:1;
  unsigned int _I2CTPS5:1;
  unsigned int _I2CTPS6:1;
  unsigned int _I2CTPS7:1;
  unsigned int _I2CTPS8:1;
  unsigned int _I2CTPS9:1;
  unsigned int _I2CTPS10:1;
  unsigned int _I2CTPS11:1;
  unsigned int _I2CTPOEN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PLL_CTL_REG{
 unsigned int reg;
 struct PLL_CTL_BITS{
  unsigned int _PDRST:1;
  unsigned int :1;
  unsigned int _M:14;
  unsigned int _N:4;
  unsigned int _OD:2;
  unsigned int :9;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PCLK_CTL0_REG{
 unsigned int reg;
 struct PCLK_CTL0_BITS{
  unsigned int _GPIOACLKEN:1;
  unsigned int _GPIOBCLKEN:1;
  unsigned int _GPIOCCLKEN:1;
  unsigned int _GPIODCLKEN:1;
  unsigned int _GPIOECLKEN:1;
  unsigned int _GPIOFCLKEN:1;
  unsigned int _GPIOGCLKEN:1;
  unsigned int _GPIOHCLKEN:1;
  unsigned int :23;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PCLK_CTL1_REG{
 unsigned int reg;
 struct PCLK_CTL1_BITS{
  unsigned int :1;
  unsigned int _QEI1CLKEN:1;
  unsigned int _T1CLKEN:1;
  unsigned int _T2CLKEN:1;
  unsigned int _T3CLKEN:1;
  unsigned int _T4CLKEN:1;
  unsigned int _T5T6CLKEN:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _QEI0CLKEN:1;
  unsigned int _ADC0CLKEN:1;
  unsigned int _ADC1CLKEN:1;
  unsigned int _ADC2CLKEN:1;
  unsigned int _DAC0CLKEN:1;
  unsigned int _DAC1CLKEN:1;
  unsigned int _CMPCLKEN:1;
  unsigned int _T0CLKEN:1;
  unsigned int :1;
  unsigned int _USART0CLKEN:1;
  unsigned int _USART1CLKEN:1;
  unsigned int _USART2CLKEN:1;
  unsigned int :1;
  unsigned int _USART4CLKEN:1;
  unsigned int _SPI0CLKEN:1;
  unsigned int _SPI1CLKEN:1;
  unsigned int _I2C0CLKEN:1;
  unsigned int _I2C1CLKEN:1;
  unsigned int _I2C2CLKEN:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PCLK_CTL2_REG{
 unsigned int reg;
 struct PCLK_CTL2_BITS{
  unsigned int :4;
  unsigned int :1;
  unsigned int _WWDTCLKEN:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _EPWM11CLKEN:1;
  unsigned int _EPWM12CLKEN:1;
  unsigned int _EPWM13CLKEN:1;
  unsigned int _EPWM16CLKEN:1;
  unsigned int _DMA0CLKEN:1;
  unsigned int :1;
  unsigned int _DMA1CLKEN:1;
  unsigned int :1;
  unsigned int _T14CLKEN:1;
  unsigned int :3;
  unsigned int :1;
  unsigned int _T18CLKEN:1;
  unsigned int _T19CLKEN:1;
  unsigned int :1;
  unsigned int _T21CLKEN:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _DAC2CLKEN:1;
  unsigned int _DAC3CLKEN:1;
  unsigned int _USART5CLKEN:1;
  unsigned int :1;
  unsigned int _USART7CLKEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union PCLK_CTL3_REG{
 unsigned int reg;
 struct PCLK_CTL3_BITS{
  unsigned int :1;
  unsigned int _SPI2CLKEN:1;
  unsigned int _SPI3CLKEN:1;
  unsigned int :3;
  unsigned int :1;
  unsigned int _I2C3CLKEN:1;
  unsigned int _HRCAP0CLKEN:1;
  unsigned int _HRCAP1CLKEN:1;
  unsigned int _HRCAP2CLKEN:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _CRCCLKEN:1;
  unsigned int _AESCLKEN:1;
  unsigned int :1;
  unsigned int _EXICCLKEN:1;
  unsigned int _CAN4CLKEN:1;
  unsigned int :1;
  unsigned int _CFGLCLKEN:1;
  unsigned int _OPCLKEN:1;
  unsigned int _FLEXMUXCLKEN:1;
  unsigned int _FDC0CLKEN:1;
  unsigned int _FDC1CLKEN:1;
  unsigned int _FDC2CLKEN:1;
  unsigned int _FLEXRMCLKEN:1;
  unsigned int _ECFLGPCLKEN:1;
  unsigned int _EWDTCLKEN:1;
  unsigned int _RNGCLKEN:1;
  unsigned int _CANFD6CLKEN:1;
  unsigned int _CANFD7CLKEN:1;
  unsigned int _RTCCLKEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_CTL_REG{
 unsigned int reg;
 struct CRC_CTL_BITS{
  unsigned int _RSET:1;
  unsigned int :1;
  unsigned int _DATASIZE:2;
  unsigned int :1;
  unsigned int _DATAREV:1;
  unsigned int :1;
  unsigned int _RSLTREV:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_DATA_REG{
 unsigned int reg;
 struct CRC_DATA_BITS{
  unsigned int _CRCDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_RSLT_REG{
 unsigned int reg;
 struct CRC_RSLT_BITS{
  unsigned int _CRCRSLT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_INIT_REG{
 unsigned int reg;
 struct CRC_INIT_BITS{
  unsigned int _CRCINIT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_PLN_REG{
 unsigned int reg;
 struct CRC_PLN_BITS{
  unsigned int _CRCPLN:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_RXOR_REG{
 unsigned int reg;
 struct CRC_RXOR_BITS{
  unsigned int _CRCRXOR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_IDATA_REG{
 unsigned int reg;
 struct CRC_IDATA_BITS{
  unsigned int _CRCIDATA:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CRC_TEMP_REG{
 unsigned int reg;
 struct CRC_TEMP_BITS{
  unsigned int _CRCTEMP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_CTL_REG{
 unsigned int reg;
 struct AES_CTL_BITS{
  unsigned int _AESEN:1;
  unsigned int _AESLIKE:1;
  unsigned int _ENCRYPT:1;
  unsigned int _SB0XINV:1;
  unsigned int _KEYLEN:3;
  unsigned int :1;
  unsigned int _RNDNUM:5;
  unsigned int _DIV:3;
  unsigned int _CKS:2;
  unsigned int :2;
  unsigned int _CBCEN:1;
  unsigned int :9;
  unsigned int _HSMODE:1;
  unsigned int _AESRUN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_INT_REG{
 unsigned int reg;
 struct AES_INT_BITS{
  unsigned int _AESFIE:1;
  unsigned int _AESFIC:1;
  unsigned int _AESFIF:1;
  unsigned int :29;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_INPUT0_REG{
 unsigned int reg;
 struct AES_INPUT0_BITS{
  unsigned int _AESINPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_INPUT1_REG{
 unsigned int reg;
 struct AES_INPUT1_BITS{
  unsigned int _AESINPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_INPUT2_REG{
 unsigned int reg;
 struct AES_INPUT2_BITS{
  unsigned int _AESINPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_INPUT3_REG{
 unsigned int reg;
 struct AES_INPUT3_BITS{
  unsigned int _AESINPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_OUTPUT0_REG{
 unsigned int reg;
 struct AES_OUTPUT0_BITS{
  unsigned int _AESOUTPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_OUTPUT1_REG{
 unsigned int reg;
 struct AES_OUTPUT1_BITS{
  unsigned int _AESOUTPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_OUTPUT2_REG{
 unsigned int reg;
 struct AES_OUTPUT2_BITS{
  unsigned int _AESOUTPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union AES_OUTPUT3_REG{
 unsigned int reg;
 struct AES_OUTPUT3_BITS{
  unsigned int _AESOUTPUT:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EXIC_CTL0_REG{
 unsigned int reg;
 struct EXIC_CTL0_BITS{
  unsigned int _EXICEN:1;
  unsigned int _CSEN:1;
  unsigned int _DCSEL:1;
  unsigned int _WRITEEN:1;
  unsigned int _READEN:1;
  unsigned int :3;
  unsigned int _TDMAEN:1;
  unsigned int _RDMAEN:1;
  unsigned int :6;
  unsigned int _WENDEN:1;
  unsigned int _RENDIE:1;
  unsigned int :10;
  unsigned int _WRITE1EN:1;
  unsigned int _READ1EN:1;
  unsigned int _DATATR:1;
  unsigned int _MODESEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EXIC_CTL1_REG{
 unsigned int reg;
 struct EXIC_CTL1_BITS{
  unsigned int _EXICCS:2;
  unsigned int :2;
  unsigned int _PULSEWIDTH:4;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EXIC_STATE_REG{
 unsigned int reg;
 struct EXIC_STATE_BITS{
  unsigned int _WENDIF:1;
  unsigned int _RENDIF:1;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EXIC_WRITEBUF_REG{
 unsigned int reg;
 struct EXIC_WRITEBUF_BITS{
  unsigned int _WRITEBUF:18;
  unsigned int :14;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EXIC_READBUF_REG{
 unsigned int reg;
 struct EXIC_READBUF_BITS{
  unsigned int _READBUF:18;
  unsigned int :14;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_CTLR_REG{
 unsigned int reg;
 struct CAN4_CTLR_BITS{
  unsigned int _RSMOD:1;
  unsigned int _SILENT:1;
  unsigned int _LBACK:1;
  unsigned int _SLEEP:1;
  unsigned int _FILTEREXT:1;
  unsigned int _CANCKS:2;
  unsigned int _CANEN:1;
  unsigned int _TXR:1;
  unsigned int _ATX:1;
  unsigned int _RELRX:1;
  unsigned int _RELF:1;
  unsigned int _LBSEL:1;
  unsigned int _BOFFREC:1;
  unsigned int _CKMODE:1;
  unsigned int _RELRXALL:1;
  unsigned int _RXBSTA:1;
  unsigned int _DOSTA:1;
  unsigned int _TXBSTA:1;
  unsigned int _TCSTA:1;
  unsigned int _RXSTA:1;
  unsigned int _TXSTA:1;
  unsigned int _CERROR:1;
  unsigned int _BOFF:1;
  unsigned int _CANRMC:7;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_BRGR_REG{
 unsigned int reg;
 struct CAN4_BRGR_BITS{
  unsigned int _CANBRP:6;
  unsigned int _SJW:2;
  unsigned int _TSEG1:4;
  unsigned int _TSEG2:3;
  unsigned int _SAM:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_RCR_REG{
 unsigned int reg;
 struct CAN4_RCR_BITS{
  unsigned int _CANALC:5;
  unsigned int :3;
  unsigned int _CANSEG:5;
  unsigned int _CANDIR:1;
  unsigned int _CANERRC:2;
  unsigned int _RAMMB:6;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_EROR_REG{
 unsigned int reg;
 struct CAN4_EROR_BITS{
  unsigned int _CANRXE:8;
  unsigned int _CANTXE:8;
  unsigned int _CANEWL:8;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACRR_REG{
 unsigned int reg;
 struct CAN4_ACRR_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSKR_REG{
 unsigned int reg;
 struct CAN4_MSKR_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_IER_REG{
 unsigned int reg;
 struct CAN4_IER_BITS{
  unsigned int _CANRXIE:1;
  unsigned int _CANTXIE:1;
  unsigned int _EAIE:1;
  unsigned int _DOVFIE:1;
  unsigned int _WUIE:1;
  unsigned int _ENIE:1;
  unsigned int _ALIE:1;
  unsigned int _BEIE:1;
  unsigned int _CANTXDE:1;
  unsigned int _CANRXDE:1;
  unsigned int _CANRFIE:1;
  unsigned int :1;
  unsigned int _BOFFIE:1;
  unsigned int :3;
  unsigned int _CANRXIC:1;
  unsigned int _CANTXIC:1;
  unsigned int _EAIC:1;
  unsigned int _DOVFIC:1;
  unsigned int _WUIC:1;
  unsigned int _ENIC:1;
  unsigned int _ALIC:1;
  unsigned int _BEIC:1;
  unsigned int :4;
  unsigned int _BOFFIC:1;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_IFR_REG{
 unsigned int reg;
 struct CAN4_IFR_BITS{
  unsigned int _CANRXIF:1;
  unsigned int _CANTXIF:1;
  unsigned int _EAIF:1;
  unsigned int _DOVFIF:1;
  unsigned int _WUIF:1;
  unsigned int _ENIF:1;
  unsigned int _ALIF:1;
  unsigned int _BEIF:1;
  unsigned int _CANTXDF:1;
  unsigned int _CANRXDF:1;
  unsigned int _CANRFIF:1;
  unsigned int :1;
  unsigned int _BOFFIF:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_INFR_REG{
 unsigned int reg;
 struct CAN4_INFR_BITS{
  unsigned int _DLC:4;
  unsigned int :2;
  unsigned int _RTR:1;
  unsigned int _IDE:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_TX0R_REG{
 unsigned int reg;
 struct CAN4_TX0R_BITS{
  unsigned int _CANTX0:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_TX1R_REG{
 unsigned int reg;
 struct CAN4_TX1R_BITS{
  unsigned int _CANTX1:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_TX2R_REG{
 unsigned int reg;
 struct CAN4_TX2R_BITS{
  unsigned int _CANTX2:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_RXDATA0_REG{
 unsigned int reg;
 struct CAN4_RXDATA0_BITS{
  unsigned int _DLC:4;
  unsigned int :2;
  unsigned int _RTR:1;
  unsigned int _IDE:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_RXDATA1_REG{
 unsigned int reg;
 struct CAN4_RXDATA1_BITS{
  unsigned int :2;
  unsigned int _RTR:1;
  unsigned int _ID0:1;
  unsigned int _ID1:1;
  unsigned int _ID2:1;
  unsigned int _ID3:1;
  unsigned int _ID4:1;
  unsigned int _ID5:1;
  unsigned int _ID6:1;
  unsigned int _ID7:1;
  unsigned int _ID8:1;
  unsigned int _ID9:1;
  unsigned int _ID10:1;
  unsigned int _ID11:1;
  unsigned int _ID12:1;
  unsigned int _ID13:1;
  unsigned int _ID14:1;
  unsigned int _ID15:1;
  unsigned int _ID16:1;
  unsigned int _ID17:1;
  unsigned int _ID18:1;
  unsigned int _ID19:1;
  unsigned int _ID20:1;
  unsigned int _ID21:1;
  unsigned int _ID22:1;
  unsigned int _ID23:1;
  unsigned int _ID24:1;
  unsigned int _ID25:1;
  unsigned int _ID26:1;
  unsigned int _ID27:1;
  unsigned int _ID28:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_RXDATA2_REG{
 unsigned int reg;
 struct CAN4_RXDATA2_BITS{
  unsigned int :7;
  unsigned int _CANRXDT3:1;
  unsigned int :7;
  unsigned int _CANRXDT2:1;
  unsigned int :7;
  unsigned int _CANRXDT1:1;
  unsigned int :7;
  unsigned int _CANRXDT0:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_RXDATA3_REG{
 unsigned int reg;
 struct CAN4_RXDATA3_BITS{
  unsigned int :7;
  unsigned int _CANRXDT7:1;
  unsigned int :7;
  unsigned int _CANRXDT6:1;
  unsigned int :7;
  unsigned int _CANRXDT5:1;
  unsigned int :7;
  unsigned int _CANRXDT4:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR1R_REG{
 unsigned int reg;
 struct CAN4_ACR1R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK1R_REG{
 unsigned int reg;
 struct CAN4_MSK1R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR2R_REG{
 unsigned int reg;
 struct CAN4_ACR2R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK2R_REG{
 unsigned int reg;
 struct CAN4_MSK2R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR3R_REG{
 unsigned int reg;
 struct CAN4_ACR3R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK3R_REG{
 unsigned int reg;
 struct CAN4_MSK3R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR4R_REG{
 unsigned int reg;
 struct CAN4_ACR4R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK4R_REG{
 unsigned int reg;
 struct CAN4_MSK4R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR5R_REG{
 unsigned int reg;
 struct CAN4_ACR5R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK5R_REG{
 unsigned int reg;
 struct CAN4_MSK5R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR6R_REG{
 unsigned int reg;
 struct CAN4_ACR6R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK6R_REG{
 unsigned int reg;
 struct CAN4_MSK6R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR7R_REG{
 unsigned int reg;
 struct CAN4_ACR7R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK7R_REG{
 unsigned int reg;
 struct CAN4_MSK7R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_ACR8R_REG{
 unsigned int reg;
 struct CAN4_ACR8R_BITS{
  unsigned int _ACR:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CAN4_MSK8R_REG{
 unsigned int reg;
 struct CAN4_MSK8R_BITS{
  unsigned int _MSK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CFGL1_CTL0_REG{
 unsigned int reg;
 struct CFGL1_CTL0_BITS{
  unsigned int _TPSEL:3;
  unsigned int _REGIN:1;
  unsigned int _D1S:3;
  unsigned int :1;
  unsigned int _D2S:3;
  unsigned int :1;
  unsigned int _D3S:3;
  unsigned int :1;
  unsigned int _D4S:3;
  unsigned int :1;
  unsigned int _G1POL:1;
  unsigned int _G2POL:1;
  unsigned int _G3POL:1;
  unsigned int _G4POL:1;
  unsigned int _POL:1;
  unsigned int _MD:3;
  unsigned int _INTN:1;
  unsigned int _INTP:1;
  unsigned int _OE:1;
  unsigned int _EN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CFGL1_CTL1_REG{
 unsigned int reg;
 struct CFGL1_CTL1_BITS{
  unsigned int _G1D1N:1;
  unsigned int _G1D1T:1;
  unsigned int _G1D2N:1;
  unsigned int _G1D2T:1;
  unsigned int _G1D3N:1;
  unsigned int _G1D3T:1;
  unsigned int _G1D4N:1;
  unsigned int _G1D4T:1;
  unsigned int _G2D1N:1;
  unsigned int _G2D1T:1;
  unsigned int _G2D2N:1;
  unsigned int _G2D2T:1;
  unsigned int _G2D3N:1;
  unsigned int _G2D3T:1;
  unsigned int _G2D4N:1;
  unsigned int _G2D4T:1;
  unsigned int _G3D1N:1;
  unsigned int _G3D1T:1;
  unsigned int _G3D2N:1;
  unsigned int _G3D2T:1;
  unsigned int _G3D3N:1;
  unsigned int _G3D3T:1;
  unsigned int _G3D4N:1;
  unsigned int _G3D4T:1;
  unsigned int _G4D1N:1;
  unsigned int _G4D1T:1;
  unsigned int _G4D2N:1;
  unsigned int _G4D2T:1;
  unsigned int _G4D3N:1;
  unsigned int _G4D3T:1;
  unsigned int _G4D4N:1;
  unsigned int _G4D4T:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CFGL2_CTL0_REG{
 unsigned int reg;
 struct CFGL2_CTL0_BITS{
  unsigned int _TPSEL:3;
  unsigned int _REGIN:1;
  unsigned int _D1S:3;
  unsigned int :1;
  unsigned int _D2S:3;
  unsigned int :1;
  unsigned int _D3S:3;
  unsigned int :1;
  unsigned int _D4S:3;
  unsigned int :1;
  unsigned int _G1POL:1;
  unsigned int _G2POL:1;
  unsigned int _G3POL:1;
  unsigned int _G4POL:1;
  unsigned int _POL:1;
  unsigned int _MD:3;
  unsigned int _INTN:1;
  unsigned int _INTP:1;
  unsigned int _OE:1;
  unsigned int _EN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CFGL2_CTL1_REG{
 unsigned int reg;
 struct CFGL2_CTL1_BITS{
  unsigned int _G1D1N:1;
  unsigned int _G1D1T:1;
  unsigned int _G1D2N:1;
  unsigned int _G1D2T:1;
  unsigned int _G1D3N:1;
  unsigned int _G1D3T:1;
  unsigned int _G1D4N:1;
  unsigned int _G1D4T:1;
  unsigned int _G2D1N:1;
  unsigned int _G2D1T:1;
  unsigned int _G2D2N:1;
  unsigned int _G2D2T:1;
  unsigned int _G2D3N:1;
  unsigned int _G2D3T:1;
  unsigned int _G2D4N:1;
  unsigned int _G2D4T:1;
  unsigned int _G3D1N:1;
  unsigned int _G3D1T:1;
  unsigned int _G3D2N:1;
  unsigned int _G3D2T:1;
  unsigned int _G3D3N:1;
  unsigned int _G3D3T:1;
  unsigned int _G3D4N:1;
  unsigned int _G3D4T:1;
  unsigned int _G4D1N:1;
  unsigned int _G4D1T:1;
  unsigned int _G4D2N:1;
  unsigned int _G4D2T:1;
  unsigned int _G4D3N:1;
  unsigned int _G4D3T:1;
  unsigned int _G4D4N:1;
  unsigned int _G4D4T:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CFGL_IFR_REG{
 unsigned int reg;
 struct CFGL_IFR_BITS{
  unsigned int _CFGL1OUT:1;
  unsigned int _CFGL2OUT:1;
  unsigned int _CFGL1C:1;
  unsigned int :5;
  unsigned int _CFGL1IF:1;
  unsigned int _CFGL2IF:1;
  unsigned int :18;
  unsigned int _CFGL1IE:1;
  unsigned int _CFGL2IE:1;
  unsigned int _CFGL1SYNCEN:1;
  unsigned int _CFGL2SYNCEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OP_CTL0_REG{
 unsigned int reg;
 struct OP_CTL0_BITS{
  unsigned int _OP0EN:1;
  unsigned int _OP1EN:1;
  unsigned int _OP2EN:1;
  unsigned int _OP3EN:1;
  unsigned int _OP0OUTEN:1;
  unsigned int _OP1OUTEN:1;
  unsigned int _OP2OUTEN:1;
  unsigned int _OP3OUTEN:1;
  unsigned int _OP0GAIN2X:1;
  unsigned int _OP0GAIN4X:1;
  unsigned int _OP0GAIN8X:1;
  unsigned int _OP0GAIN16X:1;
  unsigned int _OP0GAIN32X:1;
  unsigned int _OP0GAIN64X:1;
  unsigned int _OP1GAIN2X:1;
  unsigned int _OP1GAIN4X:1;
  unsigned int _OP1GAIN8X:1;
  unsigned int _OP1GAIN16X:1;
  unsigned int _OP1GAIN32X:1;
  unsigned int _OP1GAIN64X:1;
  unsigned int _OP2GAIN2X:1;
  unsigned int _OP2GAIN4X:1;
  unsigned int _OP2GAIN8X:1;
  unsigned int _OP2GAIN16X:1;
  unsigned int _OP2GAIN32X:1;
  unsigned int _OP2GAIN64X:1;
  unsigned int _OP3GAIN2X:1;
  unsigned int _OP3GAIN4X:1;
  unsigned int _OP3GAIN8X:1;
  unsigned int _OP3GAIN16X:1;
  unsigned int _OP3GAIN32X:1;
  unsigned int _OP3GAIN64X:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OP_CTL1_REG{
 unsigned int reg;
 struct OP_CTL1_BITS{
  unsigned int _ENCMP3:1;
  unsigned int _ENOPVCOM:1;
  unsigned int _OPVCOMOUTEN:1;
  unsigned int _VCOMPSEL:2;
  unsigned int _ENOP0INSHORT:1;
  unsigned int _ENOP1INSHORT:1;
  unsigned int _ENOP2INSHORT:1;
  unsigned int _ENOP3INSHORT:1;
  unsigned int :7;
  unsigned int _OP0TOCU:1;
  unsigned int _OP0TOCV:1;
  unsigned int _OP0TOCW:1;
  unsigned int _OP1TOCU:1;
  unsigned int _OP1TOCV:1;
  unsigned int _OP1TOCW:1;
  unsigned int _OP2TOCU:1;
  unsigned int _OP2TOCV:1;
  unsigned int _OP2TOCW:1;
  unsigned int _OP3TOCU:1;
  unsigned int _OP3TOCV:1;
  unsigned int _OP3TOCW:1;
  unsigned int _OP010KSEL:1;
  unsigned int _OP110KSEL:1;
  unsigned int _OP210KSEL:1;
  unsigned int _OP310KSEL:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OP0_TRIM_REG{
 unsigned int reg;
 struct OP0_TRIM_BITS{
  unsigned int _OP0TRIMNPOL:1;
  unsigned int _OP0TRIMN:6;
  unsigned int _OP0TRIMPPOL:1;
  unsigned int _OP0TRIMP:6;
  unsigned int :10;
  unsigned int _OP0TRIMOUT:1;
  unsigned int :5;
  unsigned int _OPTRIMHIEN:1;
  unsigned int _OPTRIMLOWEN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OP1_TRIM_REG{
 unsigned int reg;
 struct OP1_TRIM_BITS{
  unsigned int _OP1TRIMNPOL:1;
  unsigned int _OP1TRIMN:6;
  unsigned int _OP1TRIMPPOL:1;
  unsigned int _OP1TRIMP:6;
  unsigned int :10;
  unsigned int _OP1TRIMOUT:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OP2_TRIM_REG{
 unsigned int reg;
 struct OP2_TRIM_BITS{
  unsigned int _OP2TRIMNPOL:1;
  unsigned int _OP2TRIMN:6;
  unsigned int _OP2TRIMPPOL:1;
  unsigned int _OP2TRIMP:6;
  unsigned int :10;
  unsigned int _OP2TRIMOUT:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union OP3_TRIM_REG{
 unsigned int reg;
 struct OP3_TRIM_BITS{
  unsigned int _OP3TRIMNPOL:1;
  unsigned int _OP3TRIMN:6;
  unsigned int _OP3TRIMPPOL:1;
  unsigned int _OP3TRIMP:6;
  unsigned int :10;
  unsigned int _OP0TRIMOUT:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EWDT_CTL_REG{
 unsigned int reg;
 struct EWDT_CTL_BITS{
  unsigned int _EWDTEN:1;
  unsigned int _WT40IE:1;
  unsigned int _WT40IF:1;
  unsigned int _WPS:5;
  unsigned int _WW:7;
  unsigned int _WT40IC:1;
  unsigned int _EWDTINEN:1;
  unsigned int _EWDTINPOL:1;
  unsigned int _CLKS:2;
  unsigned int _TPEN:1;
  unsigned int _EWDTRSTIE:1;
  unsigned int _EWDTRSTIC:1;
  unsigned int _EWDTRSTIF:1;
  unsigned int _OUTSEL:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union EWDT_CNT_REG{
 unsigned int reg;
 struct EWDT_CNT_BITS{
  unsigned int _WT:7;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CTL_REG{
 unsigned int reg;
 struct FDC0_CTL_BITS{
  unsigned int _FDCEN:1;
  unsigned int _POEN:1;
  unsigned int _LDOK:1;
  unsigned int _CONT:1;
  unsigned int _MDLIF:1;
  unsigned int _MDLIE:1;
  unsigned int _TRGSEL:1;
  unsigned int _MULSEL:6;
  unsigned int _PRESC:3;
  unsigned int _FDCDE:1;
  unsigned int _SWTRIG:1;
  unsigned int _FDCEIE:1;
  unsigned int _LDMOD:2;
  unsigned int _BBMODE:1;
  unsigned int _CMODE:1;
  unsigned int _MDLIC:1;
  unsigned int _CLKSEL:2;
  unsigned int _TCLR:1;
  unsigned int _TP:2;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_MOD_REG{
 unsigned int reg;
 struct FDC0_MOD_BITS{
  unsigned int _MOD:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CNT_REG{
 unsigned int reg;
 struct FDC0_CNT_BITS{
  unsigned int _CNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_IDLY_REG{
 unsigned int reg;
 struct FDC0_IDLY_BITS{
  unsigned int _IDLY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH0CTL_REG{
 unsigned int reg;
 struct FDC0_CH0CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH1CTL_REG{
 unsigned int reg;
 struct FDC0_CH1CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH2CTL_REG{
 unsigned int reg;
 struct FDC0_CH2CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH3CTL_REG{
 unsigned int reg;
 struct FDC0_CH3CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH0DLY0_REG{
 unsigned int reg;
 struct FDC0_CH0DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH0DLY1_REG{
 unsigned int reg;
 struct FDC0_CH0DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH0DLY2_REG{
 unsigned int reg;
 struct FDC0_CH0DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH1DLY0_REG{
 unsigned int reg;
 struct FDC0_CH1DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH1DLY1_REG{
 unsigned int reg;
 struct FDC0_CH1DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH1DLY2_REG{
 unsigned int reg;
 struct FDC0_CH1DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH2DLY0_REG{
 unsigned int reg;
 struct FDC0_CH2DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH2DLY1_REG{
 unsigned int reg;
 struct FDC0_CH2DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH2DLY2_REG{
 unsigned int reg;
 struct FDC0_CH2DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH3DLY0_REG{
 unsigned int reg;
 struct FDC0_CH3DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH3DLY1_REG{
 unsigned int reg;
 struct FDC0_CH3DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_CH3DLY2_REG{
 unsigned int reg;
 struct FDC0_CH3DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_PO0DLY_REG{
 unsigned int reg;
 struct FDC0_PO0DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_PO1DLY_REG{
 unsigned int reg;
 struct FDC0_PO1DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_PO2DLY_REG{
 unsigned int reg;
 struct FDC0_PO2DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC0_PO3DLY_REG{
 unsigned int reg;
 struct FDC0_PO3DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CTL_REG{
 unsigned int reg;
 struct FDC1_CTL_BITS{
  unsigned int _FDCEN:1;
  unsigned int _POEN:1;
  unsigned int _LDOK:1;
  unsigned int _CONT:1;
  unsigned int _MDLIF:1;
  unsigned int _MDLIE:1;
  unsigned int _TRGSEL:1;
  unsigned int _MULSEL:6;
  unsigned int _PRESC:3;
  unsigned int _FDCDE:1;
  unsigned int _SWTRIG:1;
  unsigned int _FDCEIE:1;
  unsigned int _LDMOD:2;
  unsigned int _BBMODE:1;
  unsigned int _CMODE:1;
  unsigned int _MDLIC:1;
  unsigned int _CLKSEL:2;
  unsigned int _TCLR:1;
  unsigned int _TP:2;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_MOD_REG{
 unsigned int reg;
 struct FDC1_MOD_BITS{
  unsigned int _MOD:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CNT_REG{
 unsigned int reg;
 struct FDC1_CNT_BITS{
  unsigned int _CNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_IDLY_REG{
 unsigned int reg;
 struct FDC1_IDLY_BITS{
  unsigned int _IDLY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH0CTL_REG{
 unsigned int reg;
 struct FDC1_CH0CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH1CTL_REG{
 unsigned int reg;
 struct FDC1_CH1CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH2CTL_REG{
 unsigned int reg;
 struct FDC1_CH2CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH3CTL_REG{
 unsigned int reg;
 struct FDC1_CH3CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH0DLY0_REG{
 unsigned int reg;
 struct FDC1_CH0DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH0DLY1_REG{
 unsigned int reg;
 struct FDC1_CH0DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH0DLY2_REG{
 unsigned int reg;
 struct FDC1_CH0DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH1DLY0_REG{
 unsigned int reg;
 struct FDC1_CH1DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH1DLY1_REG{
 unsigned int reg;
 struct FDC1_CH1DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH1DLY2_REG{
 unsigned int reg;
 struct FDC1_CH1DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH2DLY0_REG{
 unsigned int reg;
 struct FDC1_CH2DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH2DLY1_REG{
 unsigned int reg;
 struct FDC1_CH2DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH2DLY2_REG{
 unsigned int reg;
 struct FDC1_CH2DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH3DLY0_REG{
 unsigned int reg;
 struct FDC1_CH3DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH3DLY1_REG{
 unsigned int reg;
 struct FDC1_CH3DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_CH3DLY2_REG{
 unsigned int reg;
 struct FDC1_CH3DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_PO0DLY_REG{
 unsigned int reg;
 struct FDC1_PO0DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_PO1DLY_REG{
 unsigned int reg;
 struct FDC1_PO1DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_PO2DLY_REG{
 unsigned int reg;
 struct FDC1_PO2DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC1_PO3DLY_REG{
 unsigned int reg;
 struct FDC1_PO3DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CTL_REG{
 unsigned int reg;
 struct FDC2_CTL_BITS{
  unsigned int _FDCEN:1;
  unsigned int _POEN:1;
  unsigned int _LDOK:1;
  unsigned int _CONT:1;
  unsigned int _MDLIF:1;
  unsigned int _MDLIE:1;
  unsigned int _TRGSEL:1;
  unsigned int _MULSEL:6;
  unsigned int _PRESC:3;
  unsigned int _FDCDE:1;
  unsigned int _SWTRIG:1;
  unsigned int _FDCEIE:1;
  unsigned int _LDMOD:2;
  unsigned int _BBMODE:1;
  unsigned int _CMODE:1;
  unsigned int _MDLIC:1;
  unsigned int _CLKSEL:2;
  unsigned int _TCLR:1;
  unsigned int _TP:2;
  unsigned int :3;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_MOD_REG{
 unsigned int reg;
 struct FDC2_MOD_BITS{
  unsigned int _MOD:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CNT_REG{
 unsigned int reg;
 struct FDC2_CNT_BITS{
  unsigned int _CNT:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_IDLY_REG{
 unsigned int reg;
 struct FDC2_IDLY_BITS{
  unsigned int _IDLY:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH0CTL_REG{
 unsigned int reg;
 struct FDC2_CH0CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH1CTL_REG{
 unsigned int reg;
 struct FDC2_CH1CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH2CTL_REG{
 unsigned int reg;
 struct FDC2_CH2CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH3CTL_REG{
 unsigned int reg;
 struct FDC2_CH3CTL_BITS{
  unsigned int _PREN0:1;
  unsigned int _PREN1:1;
  unsigned int _PREN2:1;
  unsigned int _PREN3:1;
  unsigned int _PREN4:1;
  unsigned int _TOS0:1;
  unsigned int _TOS1:1;
  unsigned int _TOS2:1;
  unsigned int _TOS3:1;
  unsigned int _TOS4:1;
  unsigned int _CF0:1;
  unsigned int _CF1:1;
  unsigned int _CF2:1;
  unsigned int _CF3:1;
  unsigned int _CF4:1;
  unsigned int _ERR0:1;
  unsigned int _ERR1:1;
  unsigned int _ERR2:1;
  unsigned int _ERR3:1;
  unsigned int _ERR4:1;
  unsigned int _ERRIC0:1;
  unsigned int _ERRIC1:1;
  unsigned int _ERRIC2:1;
  unsigned int _ERRIC3:1;
  unsigned int _ERRIC4:1;
  unsigned int :7;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH0DLY0_REG{
 unsigned int reg;
 struct FDC2_CH0DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH0DLY1_REG{
 unsigned int reg;
 struct FDC2_CH0DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH0DLY2_REG{
 unsigned int reg;
 struct FDC2_CH0DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH1DLY0_REG{
 unsigned int reg;
 struct FDC2_CH1DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH1DLY1_REG{
 unsigned int reg;
 struct FDC2_CH1DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH1DLY2_REG{
 unsigned int reg;
 struct FDC2_CH1DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH2DLY0_REG{
 unsigned int reg;
 struct FDC2_CH2DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH2DLY1_REG{
 unsigned int reg;
 struct FDC2_CH2DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH2DLY2_REG{
 unsigned int reg;
 struct FDC2_CH2DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH3DLY0_REG{
 unsigned int reg;
 struct FDC2_CH3DLY0_BITS{
  unsigned int _DLY0:16;
  unsigned int _DLY1:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH3DLY1_REG{
 unsigned int reg;
 struct FDC2_CH3DLY1_BITS{
  unsigned int _DLY2:16;
  unsigned int _DLY3:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_CH3DLY2_REG{
 unsigned int reg;
 struct FDC2_CH3DLY2_BITS{
  unsigned int _DLY4:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_PO0DLY_REG{
 unsigned int reg;
 struct FDC2_PO0DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_PO1DLY_REG{
 unsigned int reg;
 struct FDC2_PO1DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_PO2DLY_REG{
 unsigned int reg;
 struct FDC2_PO2DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FDC2_PO3DLY_REG{
 unsigned int reg;
 struct FDC2_PO3DLY_BITS{
  unsigned int _DLYL:16;
  unsigned int _DLYH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexMUX_SOU_REG{
 unsigned int reg;
 struct FlexMUX_SOU_BITS{
  unsigned int _SEL1:7;
  unsigned int _CH1EN:1;
  unsigned int _SEL2:7;
  unsigned int _CH2EN:1;
  unsigned int _SEL3:7;
  unsigned int _CH3EN:1;
  unsigned int _SEL4:7;
  unsigned int _CH4EN:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexMUX_TAR_REG{
 unsigned int reg;
 struct FlexMUX_TAR_BITS{
  unsigned int _FMUXEN:1;
  unsigned int _CH1DE:1;
  unsigned int _CH2DE:1;
  unsigned int _CH3DE:1;
  unsigned int _CH4DE:1;
  unsigned int _CH1DIV:2;
  unsigned int _CH2DIV:2;
  unsigned int _CH3DIV:2;
  unsigned int _CH4DIV:2;
  unsigned int _CH1SEL:2;
  unsigned int _CH2SEL:2;
  unsigned int _CH3SEL:2;
  unsigned int _CH4SEL:2;
  unsigned int _TCKS:2;
  unsigned int :9;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexRP_CTL_REG{
 unsigned int reg;
 struct FlexRP_CTL_BITS{
  unsigned int _G0EN:1;
  unsigned int _G1EN:1;
  unsigned int _G2EN:1;
  unsigned int _G3EN:1;
  unsigned int _G4EN:1;
  unsigned int _G5EN:1;
  unsigned int _G6EN:1;
  unsigned int _G7EN:1;
  unsigned int _G8EN:1;
  unsigned int _G9EN:1;
  unsigned int _G10EN:1;
  unsigned int _G11EN:1;
  unsigned int _CH0TRSEL:1;
  unsigned int _CH1TRSEL:1;
  unsigned int _CH2TRSEL:1;
  unsigned int _CH3TRSEL:1;
  unsigned int _CH4TRSEL:1;
  unsigned int _CH5TRSEL:1;
  unsigned int _CH6TRSEL:1;
  unsigned int _CH7TRSEL:1;
  unsigned int _CH8TRSEL:1;
  unsigned int _CH9TRSEL:1;
  unsigned int _CH10TRSEL:1;
  unsigned int _CH11TRSEL:1;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexRP_GPSR0_REG{
 unsigned int reg;
 struct FlexRP_GPSR0_BITS{
  unsigned int _G0PS:4;
  unsigned int _G1PS:4;
  unsigned int _G2PS:4;
  unsigned int _G3PS:4;
  unsigned int _G4PS:4;
  unsigned int _G5PS:4;
  unsigned int _G6PS:4;
  unsigned int _G7PS:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexRP_GPSR1_REG{
 unsigned int reg;
 struct FlexRP_GPSR1_BITS{
  unsigned int _G8PS:4;
  unsigned int _G9PS:4;
  unsigned int _G10PS:4;
  unsigned int _G11PS:4;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexRP_GCSR0_REG{
 unsigned int reg;
 struct FlexRP_GCSR0_BITS{
  unsigned int _CH0OS:4;
  unsigned int _G0CIS:4;
  unsigned int _CH1OS:4;
  unsigned int _G1CIS:4;
  unsigned int _CH2OS:4;
  unsigned int _G2CIS:4;
  unsigned int _CH3OS:4;
  unsigned int _G3CIS:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexRP_GCSR1_REG{
 unsigned int reg;
 struct FlexRP_GCSR1_BITS{
  unsigned int _G4COS:4;
  unsigned int _CH4OS:4;
  unsigned int _G5COS:4;
  unsigned int _CH5OS:4;
  unsigned int _G6COS:4;
  unsigned int _CH6OS:4;
  unsigned int _G7COS:4;
  unsigned int _CH7OS:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FlexRP_GCSR2_REG{
 unsigned int reg;
 struct FlexRP_GCSR2_BITS{
  unsigned int _G8COS:4;
  unsigned int _CH8OS:4;
  unsigned int _G9COS:4;
  unsigned int _CH9OS:4;
  unsigned int _G10COS:4;
  unsigned int _CH10OS:4;
  unsigned int _G11COS:4;
  unsigned int _CH11OS:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL0_CTL_REG{
 unsigned int reg;
 struct ECFGL0_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL1_CTL_REG{
 unsigned int reg;
 struct ECFGL1_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL2_CTL_REG{
 unsigned int reg;
 struct ECFGL2_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL3_CTL_REG{
 unsigned int reg;
 struct ECFGL3_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL4_CTL_REG{
 unsigned int reg;
 struct ECFGL4_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL5_CTL_REG{
 unsigned int reg;
 struct ECFGL5_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL6_CTL_REG{
 unsigned int reg;
 struct ECFGL6_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL7_CTL_REG{
 unsigned int reg;
 struct ECFGL7_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL8_CTL_REG{
 unsigned int reg;
 struct ECFGL8_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL9_CTL_REG{
 unsigned int reg;
 struct ECFGL9_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL10_CTL_REG{
 unsigned int reg;
 struct ECFGL10_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL11_CTL_REG{
 unsigned int reg;
 struct ECFGL11_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL12_CTL_REG{
 unsigned int reg;
 struct ECFGL12_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL13_CTL_REG{
 unsigned int reg;
 struct ECFGL13_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL14_CTL_REG{
 unsigned int reg;
 struct ECFGL14_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL15_CTL_REG{
 unsigned int reg;
 struct ECFGL15_CTL_BITS{
  unsigned int _MUX0SEL:2;
  unsigned int _MUX1SEL:2;
  unsigned int _MUX2SEL:1;
  unsigned int _MUX3SEL:1;
  unsigned int _MUX4SEL:1;
  unsigned int :1;
  unsigned int _FUNSEL:4;
  unsigned int _EN:1;
  unsigned int :19;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_SOFTSEL_REG{
 unsigned int reg;
 struct ECFGL_SOFTSEL_BITS{
  unsigned int _ECFGL0MUX2SOFTSEL:1;
  unsigned int _ECFGL1MUX2SOFTSEL:1;
  unsigned int _ECFGL2MUX2SOFTSEL:1;
  unsigned int _ECFGL3MUX2SOFTSEL:1;
  unsigned int _ECFGL4MUX2SOFTSEL:1;
  unsigned int _ECFGL5MUX2SOFTSEL:1;
  unsigned int _ECFGL6MUX2SOFTSEL:1;
  unsigned int _ECFGL7MUX2SOFTSEL:1;
  unsigned int _ECFGL8MUX2SOFTSEL:1;
  unsigned int _ECFGL9MUX2SOFTSEL:1;
  unsigned int _ECFGL10MUX2SOFTSEL:1;
  unsigned int _ECFGL11MUX2SOFTSEL:1;
  unsigned int _ECFGL12MUX2SOFTSEL:1;
  unsigned int _ECFGL13MUX2SOFTSEL:1;
  unsigned int _ECFGL14MUX2SOFTSEL:1;
  unsigned int _ECFGL15MUX2SOFTSEL:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_FCLK_REG{
 unsigned int reg;
 struct ECFGL_FCLK_BITS{
  unsigned int _FCLKSEL:3;
  unsigned int :1;
  unsigned int _FCLKDIV:3;
  unsigned int :25;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_IC_REG{
 unsigned int reg;
 struct ECFGL_IC_BITS{
  unsigned int _ECFGLIC:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_IF_REG{
 unsigned int reg;
 struct ECFGL_IF_BITS{
  unsigned int _ECFGLIF:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_RFCTL_REG{
 unsigned int reg;
 struct ECFGL_RFCTL_BITS{
  unsigned int _ECFGLR:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_FFCTL_REG{
 unsigned int reg;
 struct ECFGL_FFCTL_BITS{
  unsigned int _ECFGLF:16;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_ADC_REG{
 unsigned int reg;
 struct ECFGL_ADC_BITS{
  unsigned int _ADCTRISEL:4;
  unsigned int _ADCTRIEN:1;
  unsigned int :27;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ECFGL_OUT_REG{
 unsigned int reg;
 struct ECFGL_OUT_BITS{
  unsigned int _ECFGL0OUT:1;
  unsigned int _ECFGL1OUT:1;
  unsigned int _ECFGL2OUT:1;
  unsigned int _ECFGL3OUT:1;
  unsigned int _ECFGL4OUT:1;
  unsigned int _ECFGL5OUT:1;
  unsigned int _ECFGL6OUT:1;
  unsigned int _ECFGL7OUT:1;
  unsigned int _ECFGL8OUT:1;
  unsigned int _ECFGL9OUT:1;
  unsigned int _ECFGL10OUT:1;
  unsigned int _ECFGL11OUT:1;
  unsigned int _ECFGL12OUT:1;
  unsigned int _ECFGL13OUT:1;
  unsigned int _ECFGL14OUT:1;
  unsigned int _ECFGL15OUT:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_CTL0_REG{
 unsigned int reg;
 struct INT_CTL0_BITS{
  unsigned int _AIE:1;
  unsigned int _PRIGROUP:2;
  unsigned int :1;
  unsigned int _INTPENDING:1;
  unsigned int _INTPREEMPT:1;
  unsigned int _FAULTMASK:1;
  unsigned int _DSALIGN:1;
  unsigned int :4;
  unsigned int _PRIBASE:4;
  unsigned int _INTPEND:7;
  unsigned int :1;
  unsigned int _INTACT:7;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EIE0_REG{
 unsigned int reg;
 struct INT_EIE0_BITS{
  unsigned int :3;
  unsigned int _HADRFAULTIE:1;
  unsigned int :1;
  unsigned int _STACKIE:1;
  unsigned int _ARIFAULTIE:1;
  unsigned int :3;
  unsigned int :1;
  unsigned int _SVCIE:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _SOFTSVIE:1;
  unsigned int _SYSTICKIE:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EIE1_REG{
 unsigned int reg;
 struct INT_EIE1_BITS{
  unsigned int _WWDTIE:1;
  unsigned int _EINT16IE:1;
  unsigned int _EINT0IE:1;
  unsigned int _EINT1IE:1;
  unsigned int _EINT2IE:1;
  unsigned int _EINT3IE:1;
  unsigned int _EINT4IE:1;
  unsigned int _EINT9TO5IE:1;
  unsigned int _EINT15TO10IE:1;
  unsigned int _T1IE:1;
  unsigned int _T3IE:1;
  unsigned int _T5IE:1;
  unsigned int _T6IE:1;
  unsigned int _QEI0IE:1;
  unsigned int _QEI1IE:1;
  unsigned int _ECFGLIE:1;
  unsigned int _CAN4IE:1;
  unsigned int _T14IE:1;
  unsigned int _RNGIE:1;
  unsigned int _FDC2IE:1;
  unsigned int _EXICIE:1;
  unsigned int _ADC0IE:1;
  unsigned int _ADC1IE:1;
  unsigned int _CFGLIE:1;
  unsigned int _T11IE:1;
  unsigned int _T0IE:1;
  unsigned int _DMA0IE:1;
  unsigned int _CMPIE:1;
  unsigned int _USART0IE:1;
  unsigned int _USART1IE:1;
  unsigned int _SPI0IE:1;
  unsigned int _SPI1IE:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EIE2_REG{
 unsigned int reg;
 struct INT_EIE2_BITS{
  unsigned int _DMA1IE:1;
  unsigned int _EINT19TO17IE:1;
  unsigned int _CANFD6IE:1;
  unsigned int _CANFD7IE:1;
  unsigned int _FDC0IE:1;
  unsigned int _FDC1IE:1;
  unsigned int _EINT31TO20IE:1;
  unsigned int _ECCIE:1;
  unsigned int _OSCIE:1;
  unsigned int _I2C0IE:1;
  unsigned int _I2C1IE:1;
  unsigned int _I2C2IE:1;
  unsigned int _T12IE:1;
  unsigned int _T2IE:1;
  unsigned int _T4IE:1;
  unsigned int _T13IE:1;
  unsigned int _USART2IE:1;
  unsigned int _T16IE:1;
  unsigned int _USART4IE:1;
  unsigned int _SPI2IE:1;
  unsigned int _SPI3IE:1;
  unsigned int _ADC2IE:1;
  unsigned int _T18IE:1;
  unsigned int _T19IE:1;
  unsigned int _HRCAP0IE:1;
  unsigned int _WKPIE:1;
  unsigned int _HRCAP1IE:1;
  unsigned int _T21IE:1;
  unsigned int _I2C3IE:1;
  unsigned int _USART5IE:1;
  unsigned int _HRCAP2IE:1;
  unsigned int _USART7IE:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EIF0_REG{
 unsigned int reg;
 struct INT_EIF0_BITS{
  unsigned int :2;
  unsigned int _NMIIF:1;
  unsigned int _HARDFAULTIF:1;
  unsigned int :1;
  unsigned int _STACKIF:1;
  unsigned int _ARIFAULTIF:1;
  unsigned int :3;
  unsigned int :1;
  unsigned int _SVCIF:1;
  unsigned int :1;
  unsigned int :1;
  unsigned int _SOFTSVIF:1;
  unsigned int _SYSTICKIF:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EIF1_REG{
 unsigned int reg;
 struct INT_EIF1_BITS{
  unsigned int _WWDTIF:1;
  unsigned int _EINT16IF:1;
  unsigned int _EINT0IF:1;
  unsigned int _EINT1IF:1;
  unsigned int _EINT2IF:1;
  unsigned int _EINT3IF:1;
  unsigned int _EINT4IF:1;
  unsigned int _EINT9TO5IF:1;
  unsigned int _EINT15TO10IF:1;
  unsigned int _T1IF:1;
  unsigned int _T3IF:1;
  unsigned int _T5IF:1;
  unsigned int _T6IF:1;
  unsigned int _QEI0IF:1;
  unsigned int _QEI1IF:1;
  unsigned int _ECFGLIF:1;
  unsigned int _CAN4IF:1;
  unsigned int _T14IF:1;
  unsigned int _RNGIF:1;
  unsigned int _FDC2IF:1;
  unsigned int _EXICIF:1;
  unsigned int _ADC0IF:1;
  unsigned int _ADC1IF:1;
  unsigned int _CFGLIF:1;
  unsigned int _T11IF:1;
  unsigned int _T0IF:1;
  unsigned int _DMA0IF:1;
  unsigned int _CMPIF:1;
  unsigned int _USART0IF:1;
  unsigned int _USART1IF:1;
  unsigned int _SPI0IF:1;
  unsigned int _SPI1IF:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EIF2_REG{
 unsigned int reg;
 struct INT_EIF2_BITS{
  unsigned int _DMA1IF:1;
  unsigned int _EINT19TO17IF:1;
  unsigned int _CANFD6IF:1;
  unsigned int _CANFD7IF:1;
  unsigned int _FDC0IF:1;
  unsigned int _FDC1IF:1;
  unsigned int _EINT31TO20IF:1;
  unsigned int _ECCIF:1;
  unsigned int _OSCIF:1;
  unsigned int _I2C0IF:1;
  unsigned int _I2C1IF:1;
  unsigned int _I2C2IF:1;
  unsigned int _T12IF:1;
  unsigned int _T2IF:1;
  unsigned int _T4IF:1;
  unsigned int _T13IF:1;
  unsigned int _USART2IF:1;
  unsigned int _T16IF:1;
  unsigned int _USART4IF:1;
  unsigned int _SPI2IF:1;
  unsigned int _SPI3IF:1;
  unsigned int _ADC2IF:1;
  unsigned int _T18IF:1;
  unsigned int _T19IF:1;
  unsigned int _HRCAP0IF:1;
  unsigned int _WKPIF:1;
  unsigned int _HRCAP1IF:1;
  unsigned int _T21IF:1;
  unsigned int _I2C3IF:1;
  unsigned int _USART5IF:1;
  unsigned int _HRCAP2IF:1;
  unsigned int _USART7IF:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP0_REG{
 unsigned int reg;
 struct INT_IP0_BITS{
  unsigned int _PRI4:8;
  unsigned int _PRI5:8;
  unsigned int _PRI6:8;
  unsigned int _PRI7:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP1_REG{
 unsigned int reg;
 struct INT_IP1_BITS{
  unsigned int _PRI8:8;
  unsigned int _PRI9:8;
  unsigned int _PRI10:8;
  unsigned int _PRI11:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP2_REG{
 unsigned int reg;
 struct INT_IP2_BITS{
  unsigned int _PRI12:8;
  unsigned int _PRI13:8;
  unsigned int _PRI14:8;
  unsigned int _PRI15:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP3_REG{
 unsigned int reg;
 struct INT_IP3_BITS{
  unsigned int _PR16:8;
  unsigned int _PRI17:8;
  unsigned int _PRI18:8;
  unsigned int _PRI19:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP4_REG{
 unsigned int reg;
 struct INT_IP4_BITS{
  unsigned int _PRI20:8;
  unsigned int _PRI21:8;
  unsigned int _PRI22:8;
  unsigned int _PRI23:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP5_REG{
 unsigned int reg;
 struct INT_IP5_BITS{
  unsigned int _PRI24:8;
  unsigned int _PRI25:8;
  unsigned int _PRI26:8;
  unsigned int _PRI27:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP6_REG{
 unsigned int reg;
 struct INT_IP6_BITS{
  unsigned int _PRI28:8;
  unsigned int _PRI29:8;
  unsigned int _PRI30:8;
  unsigned int _PRI31:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP7_REG{
 unsigned int reg;
 struct INT_IP7_BITS{
  unsigned int _PRI32:8;
  unsigned int _PRI33:8;
  unsigned int _PRI34:8;
  unsigned int _PRI35:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP8_REG{
 unsigned int reg;
 struct INT_IP8_BITS{
  unsigned int _PRI36:8;
  unsigned int _PRI37:8;
  unsigned int _PRI38:8;
  unsigned int _PRI39:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP9_REG{
 unsigned int reg;
 struct INT_IP9_BITS{
  unsigned int _PRI40:8;
  unsigned int _PRI41:8;
  unsigned int _PRI42:8;
  unsigned int _PRI43:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP10_REG{
 unsigned int reg;
 struct INT_IP10_BITS{
  unsigned int _PRI44:8;
  unsigned int _PRI45:8;
  unsigned int _PRI46:8;
  unsigned int _PRI47:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP11_REG{
 unsigned int reg;
 struct INT_IP11_BITS{
  unsigned int _PRI48:8;
  unsigned int _PRI49:8;
  unsigned int _PRI50:8;
  unsigned int _PRI51:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP12_REG{
 unsigned int reg;
 struct INT_IP12_BITS{
  unsigned int _PRI52:8;
  unsigned int _PRI53:8;
  unsigned int _PRI54:8;
  unsigned int _PRI55:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP13_REG{
 unsigned int reg;
 struct INT_IP13_BITS{
  unsigned int _PRI56:8;
  unsigned int _PRI57:8;
  unsigned int _PRI58:8;
  unsigned int _PRI59:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP14_REG{
 unsigned int reg;
 struct INT_IP14_BITS{
  unsigned int _PRI60:8;
  unsigned int _PRI61:8;
  unsigned int _PRI62:8;
  unsigned int _PRI63:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP15_REG{
 unsigned int reg;
 struct INT_IP15_BITS{
  unsigned int _PRI64:8;
  unsigned int _PRI65:8;
  unsigned int _PRI66:8;
  unsigned int _PRI67:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP16_REG{
 unsigned int reg;
 struct INT_IP16_BITS{
  unsigned int _PRI68:8;
  unsigned int _PRI69:8;
  unsigned int _PRI70:8;
  unsigned int _PRI71:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP17_REG{
 unsigned int reg;
 struct INT_IP17_BITS{
  unsigned int _PRI72:8;
  unsigned int _PRI73:8;
  unsigned int _PRI74:8;
  unsigned int _PRI75:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_IP18_REG{
 unsigned int reg;
 struct INT_IP18_BITS{
  unsigned int _PRI76:8;
  unsigned int _PRI77:8;
  unsigned int _PRI78:8;
  unsigned int _PRI79:8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EINTMASK_REG{
 unsigned int reg;
 struct INT_EINTMASK_BITS{
  unsigned int _EINTM:22;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EINTRISE_REG{
 unsigned int reg;
 struct INT_EINTRISE_BITS{
  unsigned int _EINTRI:22;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EINTFALL_REG{
 unsigned int reg;
 struct INT_EINTFALL_BITS{
  unsigned int _EINTFA:22;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EINTF_REG{
 unsigned int reg;
 struct INT_EINTF_BITS{
  unsigned int _EINTIF:22;
  unsigned int :10;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EINTSS0_REG{
 unsigned int reg;
 struct INT_EINTSS0_BITS{
  unsigned int _EINTSOU0:4;
  unsigned int _EINTSOU1:4;
  unsigned int _EINTSOU2:4;
  unsigned int _EINTSOU3:4;
  unsigned int _EINTSOU4:4;
  unsigned int _EINTSOU5:4;
  unsigned int _EINTSOU6:4;
  unsigned int _EINTSOU7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_EINTSS1_REG{
 unsigned int reg;
 struct INT_EINTSS1_BITS{
  unsigned int _EINTSOU8:4;
  unsigned int _EINTSOU9:4;
  unsigned int _EINTSOU10:4;
  unsigned int _EINTSOU11:4;
  unsigned int _EINTSOU12:4;
  unsigned int _EINTSOU13:4;
  unsigned int _EINTSOU14:4;
  unsigned int _EINTSOU15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union INT_CTL1_REG{
 unsigned int reg;
 struct INT_CTL1_BITS{
  unsigned int _INTDELY:8;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ST_CTL_REG{
 unsigned int reg;
 struct ST_CTL_BITS{
  unsigned int _STEN:1;
  unsigned int _TICKINTEN:1;
  unsigned int _STCLKS:1;
  unsigned int :13;
  unsigned int _COUNTZERO:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ST_RELOAD_REG{
 unsigned int reg;
 struct ST_RELOAD_BITS{
  unsigned int _STRELOAD:24;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ST_CV_REG{
 unsigned int reg;
 struct ST_CV_BITS{
  unsigned int _STCV:24;
  unsigned int :8;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union ST_CALI_REG{
 unsigned int reg;
 struct ST_CALI_BITS{
  unsigned int _STCALIB:24;
  unsigned int :6;
  unsigned int _SKEW:1;
  unsigned int _STCLKREF:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_PSW_REG{
 unsigned int reg;
 struct SYS_PSW_BITS{
  unsigned int :28;
  unsigned int _V:1;
  unsigned int _C:1;
  unsigned int _Z:1;
  unsigned int _N:1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_MCTL_REG{
 unsigned int reg;
 struct SYS_MCTL_BITS{
  unsigned int :1;
  unsigned int _SLEEPONEXIT:1;
  unsigned int _SLEEPDEEP:1;
  unsigned int :1;
  unsigned int _SLPONMOD:1;
  unsigned int :4;
  unsigned int _STACKALIGN:1;
  unsigned int :5;
  unsigned int _SUSTA:1;
  unsigned int _SPSEL:1;
  unsigned int :15;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_ARCTL_REG{
 unsigned int reg;
 struct SYS_ARCTL_BITS{
  unsigned int :1;
  unsigned int _VECTRST:1;
  unsigned int _SYSTEMRST:1;
  unsigned int _DWD:1;
  unsigned int _CDMAR:1;
  unsigned int _CDMAAM:1;
  unsigned int _CRWDC:1;
  unsigned int _CDMADC:1;
  unsigned int _CDBUGBS:1;
  unsigned int _CDMALDC:2;
  unsigned int _CPOPINT:1;
  unsigned int _CDIV:1;
  unsigned int _CDMAHEC:1;
  unsigned int :2;
  unsigned int _ARKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_VECTOFF_REG{
 unsigned int reg;
 struct SYS_VECTOFF_BITS{
  unsigned int _TBLOFF:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union CACHE_CTLR_REG{
 unsigned int reg;
 struct CACHE_CTLR_BITS{
  unsigned int _CACHEEN:1;
  unsigned int _CACHERST:1;
  unsigned int _ICWR2LEN:1;
  unsigned int _ICRD2LEN:1;
  unsigned int _CECCEN:1;
  unsigned int _FECCERRIE:1;
  unsigned int _CECCERRIE:1;
  unsigned int _RECCERRIE:1;
  unsigned int _FECCERRFLAG:1;
  unsigned int _CECCERRFLAG:1;
  unsigned int :22;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_RAMSPA_REG{
 unsigned int reg;
 struct SYS_RAMSPA_BITS{
  unsigned int _RAMSPA:26;
  unsigned int :6;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_MEMCTL_REG{
 unsigned int reg;
 struct SYS_MEMCTL_BITS{
  unsigned int _MEMM:2;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_MSPSPA_REG{
 unsigned int reg;
 struct SYS_MSPSPA_BITS{
  unsigned int _MSPSPAL:16;
  unsigned int _MSPSPAH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_PSPSPA_REG{
 unsigned int reg;
 struct SYS_PSPSPA_BITS{
  unsigned int _PSPSPAL:16;
  unsigned int _PSPSPAH:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_ISPCON0_REG{
 unsigned int reg;
 struct FLASH_ISPCON0_BITS{
  unsigned int _NVMLOCK:1;
  unsigned int _FLASHLOCK:1;
  unsigned int _CFGLOCK:1;
  unsigned int _DWEN:1;
  unsigned int _IFEN:1;
  unsigned int _STANDBY1:1;
  unsigned int :26;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_ISPCON1_REG{
 unsigned int reg;
 struct FLASH_ISPCON1_BITS{
  unsigned int _IPSEL:1;
  unsigned int _RECALLEN:1;
  unsigned int _CONFEN:1;
  unsigned int :12;
  unsigned int _CHIPONEM:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_ISPCMD_REG{
 unsigned int reg;
 struct FLASH_ISPCMD_BITS{
  unsigned int _CMD0:1;
  unsigned int _CMD1:1;
  unsigned int _CMD2:1;
  unsigned int _CMD3:1;
  unsigned int _CMD4:1;
  unsigned int _WSIZE0:1;
  unsigned int _WSIZE1:1;
  unsigned int _WSIZE2:1;
  unsigned int _WSIZE3:1;
  unsigned int _WSIZE4:1;
  unsigned int _WSIZE5:1;
  unsigned int :21;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_ISPTRG_REG{
 unsigned int reg;
 struct FLASH_ISPTRG_BITS{
  unsigned int _ISPG0:1;
  unsigned int :31;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CFG_REG{
 unsigned int reg;
 struct FLASH_CFG_BITS{
  unsigned int _TCFG:4;
  unsigned int :2;
  unsigned int _PREFETCHEN:1;
  unsigned int _ECCREADEN:1;
  unsigned int :24;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_ISPADDR_REG{
 unsigned int reg;
 struct FLASH_ISPADDR_BITS{
  unsigned int :2;
  unsigned int _SADDR2:1;
  unsigned int _SADDR3:1;
  unsigned int _SADDR4:1;
  unsigned int _SADDR5:1;
  unsigned int _SADDR6:1;
  unsigned int _SADDR7:1;
  unsigned int _SADDR8:1;
  unsigned int _SADDR9:1;
  unsigned int _SADDR10:1;
  unsigned int _SADDR11:1;
  unsigned int _SADDR12:1;
  unsigned int _SADDR13:1;
  unsigned int _SADDR14:1;
  unsigned int _SADDR15:1;
  unsigned int _SADDR16:1;
  unsigned int _SADDR17:1;
  unsigned int _SADDR18:1;
  unsigned int _SADDR19:1;
  unsigned int :12;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_STATE_REG{
 unsigned int reg;
 struct FLASH_STATE_BITS{
  unsigned int :1;
  unsigned int _SIGDONE:1;
  unsigned int :30;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_NVMUNLOCK_REG{
 unsigned int reg;
 struct FLASH_NVMUNLOCK_BITS{
  unsigned int _NVMUNLOCK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_PROUNLOCK_REG{
 unsigned int reg;
 struct FLASH_PROUNLOCK_BITS{
  unsigned int _PROUNLOCK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CFGUNLOCK_REG{
 unsigned int reg;
 struct FLASH_CFGUNLOCK_BITS{
  unsigned int _CFGUNLOCK:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CSSTART_REG{
 unsigned int reg;
 struct FLASH_CSSTART_BITS{
  unsigned int :4;
  unsigned int _CKSTADDR:16;
  unsigned int :12;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CSSTOP_REG{
 unsigned int reg;
 struct FLASH_CSSTOP_BITS{
  unsigned int :4;
  unsigned int _CKSPADDR:16;
  unsigned int _SIGG0:1;
  unsigned int :11;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CSRES0_REG{
 unsigned int reg;
 struct FLASH_CSRES0_BITS{
  unsigned int _CKSPRES0:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CSRES1_REG{
 unsigned int reg;
 struct FLASH_CSRES1_BITS{
  unsigned int _CKSPRES1:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CSRES2_REG{
 unsigned int reg;
 struct FLASH_CSRES2_BITS{
  unsigned int _CKSPRES2:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union FLASH_CSRES3_REG{
 unsigned int reg;
 struct FLASH_CSRES3_BITS{
  unsigned int _CKSPRES3:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_CORETP0_REG{
 unsigned int reg;
 struct SYS_CORETP0_BITS{
  unsigned int _TP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_CORETP1_REG{
 unsigned int reg;
 struct SYS_CORETP1_BITS{
  unsigned int _TP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_CORETP2_REG{
 unsigned int reg;
 struct SYS_CORETP2_BITS{
  unsigned int _TP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union SYS_CORETP3_REG{
 unsigned int reg;
 struct SYS_CORETP3_BITS{
  unsigned int _TP:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_PIR_REG{
 unsigned int reg;
 struct GPIOA_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_POR_REG{
 unsigned int reg;
 struct GPIOA_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_PUR_REG{
 unsigned int reg;
 struct GPIOA_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_PDR_REG{
 unsigned int reg;
 struct GPIOA_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_PODR_REG{
 unsigned int reg;
 struct GPIOA_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_PMOD_REG{
 unsigned int reg;
 struct GPIOA_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_OMOD_REG{
 unsigned int reg;
 struct GPIOA_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_LOCK_REG{
 unsigned int reg;
 struct GPIOA_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_RMPL_REG{
 unsigned int reg;
 struct GPIOA_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_RMPH_REG{
 unsigned int reg;
 struct GPIOA_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOA_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOA_RMP_MSB_BITS{
  unsigned int _RMP_MSB:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_PIR_REG{
 unsigned int reg;
 struct GPIOB_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_POR_REG{
 unsigned int reg;
 struct GPIOB_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_PUR_REG{
 unsigned int reg;
 struct GPIOB_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_PDR_REG{
 unsigned int reg;
 struct GPIOB_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_PODR_REG{
 unsigned int reg;
 struct GPIOB_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_PMOD_REG{
 unsigned int reg;
 struct GPIOB_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_OMOD_REG{
 unsigned int reg;
 struct GPIOB_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_LOCK_REG{
 unsigned int reg;
 struct GPIOB_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_RMPL_REG{
 unsigned int reg;
 struct GPIOB_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_RMPH_REG{
 unsigned int reg;
 struct GPIOB_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_UHS_REG{
 unsigned int reg;
 struct GPIOB_UHS_BITS{
  unsigned int _UHSEN0:1;
  unsigned int _UHSEN1:1;
  unsigned int _UHSEN2:1;
  unsigned int _UHSEN3:1;
  unsigned int :28;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOB_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOB_RMP_MSB_BITS{
  unsigned int _RMP_MSB:32;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_PIR_REG{
 unsigned int reg;
 struct GPIOC_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_POR_REG{
 unsigned int reg;
 struct GPIOC_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_PUR_REG{
 unsigned int reg;
 struct GPIOC_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_PDR_REG{
 unsigned int reg;
 struct GPIOC_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_PODR_REG{
 unsigned int reg;
 struct GPIOC_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_PMOD_REG{
 unsigned int reg;
 struct GPIOC_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_OMOD_REG{
 unsigned int reg;
 struct GPIOC_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_LOCK_REG{
 unsigned int reg;
 struct GPIOC_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_RMPL_REG{
 unsigned int reg;
 struct GPIOC_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_RMPH_REG{
 unsigned int reg;
 struct GPIOC_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOC_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOC_RMP_MSB_BITS{
  unsigned int _RMP_MSB:16;
  unsigned int _RMP_MSB:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_PIR_REG{
 unsigned int reg;
 struct GPIOD_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_POR_REG{
 unsigned int reg;
 struct GPIOD_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_PUR_REG{
 unsigned int reg;
 struct GPIOD_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_PDR_REG{
 unsigned int reg;
 struct GPIOD_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_PODR_REG{
 unsigned int reg;
 struct GPIOD_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_PMOD_REG{
 unsigned int reg;
 struct GPIOD_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_OMOD_REG{
 unsigned int reg;
 struct GPIOD_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_LOCK_REG{
 unsigned int reg;
 struct GPIOD_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_RMPL_REG{
 unsigned int reg;
 struct GPIOD_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_RMPH_REG{
 unsigned int reg;
 struct GPIOD_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOD_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOD_RMP_MSB_BITS{
  unsigned int _RMP_MSB:16;
  unsigned int _RMP_MSB:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_PIR_REG{
 unsigned int reg;
 struct GPIOE_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_POR_REG{
 unsigned int reg;
 struct GPIOE_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_PUR_REG{
 unsigned int reg;
 struct GPIOE_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_PDR_REG{
 unsigned int reg;
 struct GPIOE_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_PODR_REG{
 unsigned int reg;
 struct GPIOE_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_PMOD_REG{
 unsigned int reg;
 struct GPIOE_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_OMOD_REG{
 unsigned int reg;
 struct GPIOE_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_LOCK_REG{
 unsigned int reg;
 struct GPIOE_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_RMPL_REG{
 unsigned int reg;
 struct GPIOE_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_RMPH_REG{
 unsigned int reg;
 struct GPIOE_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOE_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOE_RMP_MSB_BITS{
  unsigned int _RMP_MSB:16;
  unsigned int _RMP_MSB:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_PIR_REG{
 unsigned int reg;
 struct GPIOF_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_POR_REG{
 unsigned int reg;
 struct GPIOF_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_PUR_REG{
 unsigned int reg;
 struct GPIOF_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_PDR_REG{
 unsigned int reg;
 struct GPIOF_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_PODR_REG{
 unsigned int reg;
 struct GPIOF_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_PMOD_REG{
 unsigned int reg;
 struct GPIOF_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_OMOD_REG{
 unsigned int reg;
 struct GPIOF_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_LOCK_REG{
 unsigned int reg;
 struct GPIOF_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_RMPL_REG{
 unsigned int reg;
 struct GPIOF_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_RMPH_REG{
 unsigned int reg;
 struct GPIOF_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOF_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOF_RMP_MSB_BITS{
  unsigned int _RMP_MSB:16;
  unsigned int _RMP_MSB:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_PIR_REG{
 unsigned int reg;
 struct GPIOG_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_POR_REG{
 unsigned int reg;
 struct GPIOG_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_PUR_REG{
 unsigned int reg;
 struct GPIOG_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_PDR_REG{
 unsigned int reg;
 struct GPIOG_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_PODR_REG{
 unsigned int reg;
 struct GPIOG_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_PMOD_REG{
 unsigned int reg;
 struct GPIOG_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_OMOD_REG{
 unsigned int reg;
 struct GPIOG_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_LOCK_REG{
 unsigned int reg;
 struct GPIOG_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_RMPL_REG{
 unsigned int reg;
 struct GPIOG_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_RMPH_REG{
 unsigned int reg;
 struct GPIOG_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOG_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOG_RMP_MSB_BITS{
  unsigned int _RMP_MSB:16;
  unsigned int _RMP_MSB:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_PIR_REG{
 unsigned int reg;
 struct GPIOH_PIR_BITS{
  unsigned int _PXPIR0:1;
  unsigned int _PXPIR1:1;
  unsigned int _PXPIR2:1;
  unsigned int _PXPIR3:1;
  unsigned int _PXPIR4:1;
  unsigned int _PXPIR5:1;
  unsigned int _PXPIR6:1;
  unsigned int _PXPIR7:1;
  unsigned int _PXPIR8:1;
  unsigned int _PXPIR9:1;
  unsigned int _PXPIR10:1;
  unsigned int _PXPIR11:1;
  unsigned int _PXPIR12:1;
  unsigned int _PXPIR13:1;
  unsigned int _PXPIR14:1;
  unsigned int _PXPIR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_POR_REG{
 unsigned int reg;
 struct GPIOH_POR_BITS{
  unsigned int _PXPOR0:1;
  unsigned int _PXPOR1:1;
  unsigned int _PXPOR2:1;
  unsigned int _PXPOR3:1;
  unsigned int _PXPOR4:1;
  unsigned int _PXPOR5:1;
  unsigned int _PXPOR6:1;
  unsigned int _PXPOR7:1;
  unsigned int _PXPOR8:1;
  unsigned int _PXPOR9:1;
  unsigned int _PXPOR10:1;
  unsigned int _PXPOR11:1;
  unsigned int _PXPOR12:1;
  unsigned int _PXPOR13:1;
  unsigned int _PXPOR14:1;
  unsigned int _PXPOR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_PUR_REG{
 unsigned int reg;
 struct GPIOH_PUR_BITS{
  unsigned int _PXPUR0:1;
  unsigned int _PXPUR1:1;
  unsigned int _PXPUR2:1;
  unsigned int _PXPUR3:1;
  unsigned int _PXPUR4:1;
  unsigned int _PXPUR5:1;
  unsigned int _PXPUR6:1;
  unsigned int _PXPUR7:1;
  unsigned int _PXPUR8:1;
  unsigned int _PXPUR9:1;
  unsigned int _PXPUR10:1;
  unsigned int _PXPUR11:1;
  unsigned int _PXPUR12:1;
  unsigned int _PXPUR13:1;
  unsigned int _PXPUR14:1;
  unsigned int _PXPUR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_PDR_REG{
 unsigned int reg;
 struct GPIOH_PDR_BITS{
  unsigned int _PXPDR0:1;
  unsigned int _PXPDR1:1;
  unsigned int _PXPDR2:1;
  unsigned int _PXPDR3:1;
  unsigned int _PXPDR4:1;
  unsigned int _PXPDR5:1;
  unsigned int _PXPDR6:1;
  unsigned int _PXPDR7:1;
  unsigned int _PXPDR8:1;
  unsigned int _PXPDR9:1;
  unsigned int _PXPDR10:1;
  unsigned int _PXPDR11:1;
  unsigned int _PXPDR12:1;
  unsigned int _PXPDR13:1;
  unsigned int _PXPDR14:1;
  unsigned int _PXPDR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_PODR_REG{
 unsigned int reg;
 struct GPIOH_PODR_BITS{
  unsigned int _PXPODR0:1;
  unsigned int _PXPODR1:1;
  unsigned int _PXPODR2:1;
  unsigned int _PXPODR3:1;
  unsigned int _PXPODR4:1;
  unsigned int _PXPODR5:1;
  unsigned int _PXPODR6:1;
  unsigned int _PXPODR7:1;
  unsigned int _PXPODR8:1;
  unsigned int _PXPODR9:1;
  unsigned int _PXPODR10:1;
  unsigned int _PXPODR11:1;
  unsigned int _PXPODR12:1;
  unsigned int _PXPODR13:1;
  unsigned int _PXPODR14:1;
  unsigned int _PXPODR15:1;
  unsigned int :16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_PMOD_REG{
 unsigned int reg;
 struct GPIOH_PMOD_BITS{
  unsigned int _PXPMD0:2;
  unsigned int _PXPMD1:2;
  unsigned int _PXPMD2:2;
  unsigned int _PXPMD3:2;
  unsigned int _PXPMD4:2;
  unsigned int _PXPMD5:2;
  unsigned int _PXPMD6:2;
  unsigned int _PXPMD7:2;
  unsigned int _PXPMD8:2;
  unsigned int _PXPMD9:2;
  unsigned int _PXPMD10:2;
  unsigned int _PXPMD11:2;
  unsigned int _PXPMD12:2;
  unsigned int _PXPMD13:2;
  unsigned int _PXPMD14:2;
  unsigned int _PXPMD15:2;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_OMOD_REG{
 unsigned int reg;
 struct GPIOH_OMOD_BITS{
  unsigned int _PXOMD0:1;
  unsigned int :1;
  unsigned int _PXOMD1:1;
  unsigned int :1;
  unsigned int _PXOMD2:1;
  unsigned int :1;
  unsigned int _PXOMD3:1;
  unsigned int :1;
  unsigned int _PXOMD4:1;
  unsigned int :1;
  unsigned int _PXOMD5:1;
  unsigned int :1;
  unsigned int _PXOMD6:1;
  unsigned int :1;
  unsigned int _PXOMD7:1;
  unsigned int :1;
  unsigned int _PXOMD8:1;
  unsigned int :1;
  unsigned int _PXOMD9:1;
  unsigned int :1;
  unsigned int _PXOMD10:1;
  unsigned int :1;
  unsigned int _PXOMD11:1;
  unsigned int :1;
  unsigned int _PXOMD12:1;
  unsigned int :1;
  unsigned int _PXOMD13:1;
  unsigned int :1;
  unsigned int _PXOMD14:1;
  unsigned int :1;
  unsigned int _PXOMD15:1;
  unsigned int :1;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_LOCK_REG{
 unsigned int reg;
 struct GPIOH_LOCK_BITS{
  unsigned int _PXLCK0:1;
  unsigned int _PXLCK1:1;
  unsigned int _PXLCK2:1;
  unsigned int _PXLCK3:1;
  unsigned int _PXLCK4:1;
  unsigned int _PXLCK5:1;
  unsigned int _PXLCK6:1;
  unsigned int _PXLCK7:1;
  unsigned int _PXLCK8:1;
  unsigned int _PXLCK9:1;
  unsigned int _PXLCK10:1;
  unsigned int _PXLCK11:1;
  unsigned int _PXLCK12:1;
  unsigned int _PXLCK13:1;
  unsigned int _PXLCK14:1;
  unsigned int _PXLCK15:1;
  unsigned int _PXLCKKEY:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_RMPL_REG{
 unsigned int reg;
 struct GPIOH_RMPL_BITS{
  unsigned int _PXRMP0:4;
  unsigned int _PXRMP1:4;
  unsigned int _PXRMP2:4;
  unsigned int _PXRMP3:4;
  unsigned int _PXRMP4:4;
  unsigned int _PXRMP5:4;
  unsigned int _PXRMP6:4;
  unsigned int _PXRMP7:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_RMPH_REG{
 unsigned int reg;
 struct GPIOH_RMPH_BITS{
  unsigned int _PXRMP8:4;
  unsigned int _PXRMP9:4;
  unsigned int _PXRMP10:4;
  unsigned int _PXRMP11:4;
  unsigned int _PXRMP12:4;
  unsigned int _PXRMP13:4;
  unsigned int _PXRMP14:4;
  unsigned int _PXRMP15:4;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union GPIOH_RMP_MSB_REG{
 unsigned int reg;
 struct GPIOH_RMP_MSB_BITS{
  unsigned int _RMP_MSB:16;
  unsigned int _RMP_MSB:16;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};




union IONMI_CTLR_REG{
 unsigned int reg;
 struct IONMI_CTLR_BITS{
  unsigned int _IONMIEN:1;
  unsigned int _FLTWR:3;
  unsigned int _FCKDIV:3;
  unsigned int :1;
  unsigned int _IRQMS:3;
  unsigned int _FLTEN:1;
  unsigned int _FLTCKS:1;
  unsigned int _IONMIIC:1;
  unsigned int _IONMIIF:1;
  unsigned int :17;
 }__attribute__((packed)) bits;
 struct all_bit bit;
};
# 6 "D:/KungFu32_/ChipONCC32/include/KF32A156MQV.h" 2
# 11 "../main.c" 2


volatile unsigned int aaaa[20]={1,2,3,4,5,};
void FunTest(volatile unsigned int aaaa[20], volatile unsigned int temp3)
{
 aaaa[1] = temp3++;
}

void main()
{
    volatile unsigned int temp3 = 3;
    temp3++;
    temp3++;
 while(1)
 {
     FunTest(aaaa, temp3);

 }
}
