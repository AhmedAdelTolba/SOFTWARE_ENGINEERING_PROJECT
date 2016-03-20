///////////////for bit//////////////////
/* #define getbit (reg,bitno)
#define clrbit (reg,bitno)
#define setbit (reg,bitno)
#define togglebit (reg,bitno) */
/////////////////for registers/////////////
/* #define setreg (reg)
#define clrreg (reg)
#define togglereg (reg)
#define assignreg (reg,value) */
/////////////////for low nib/////////////////////////
/* #define getlownib (reg)
#define clrlownib (reg)
#define setlownib (reg)
#define assignlownib (reg,value) */
///////////////////for high nib///////////////////////
/* #define gethighnib (reg)
#define clrhighnib (reg)
#define sethighnib (reg)
#define assignhighnib (reg,value) */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////for bit////////////////////
#define getbit(reg,bitno) (((reg)&(0x01<<(bitno)))? (1):(0)) // ((reg >> bitno)&(0x01))
#define clrbit(reg,bitno) (reg&((0xfe<<bitno)|(0xfe>>(8-bitno))))
#define setbit(reg,bitno) reg|(0x01<<bitno)
#define togglebit(reg,bitno) reg^(0x01<<bitno)
/////////////////for registers/////////////
#define setreg(reg) reg = 0xff
#define clrreg(reg) reg = 0x00
#define getreg(reg) (reg)
#define togglereg(reg) reg ^=0xff
#define assignreg(reg,value) reg = value
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////for low nib/////////////////////////
#define getlownib(reg) reg&0x0f 
#define clrlownib(reg) reg&0xf0 
#define setlownib(reg) reg|0x0f
#define assignlownib(reg,value) reg = value
///////////////////for high nib///////////////////////
#define gethighnib(reg) reg|0xf0 
#define clrhighnib(reg) reg&0x0f 
#define sethighnib(reg) reg&0xf0
#define assignhighnib(reg,value) reg = value
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
