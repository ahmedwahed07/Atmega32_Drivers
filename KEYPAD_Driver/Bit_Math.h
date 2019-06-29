#define Set_Bit(var,BitNo)      (var|=(1<<BitNo))
#define Clr_Bit(var,BitNo)      (var&=~(1<<BitNo))
#define Toggle_Bit(var,BitNo)   (var^=(1<<BitNo))
#define Get_Bit(var,BitNo)      ((var>>BitNo)&1)


//reg&(1<<pin))>>pin
