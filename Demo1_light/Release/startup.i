# 1 "../_config/startup.c"
# 1 "D:\\KungFu32\\workspace32\\Demo1_light\\Release//"
# 1 "<command-line>"
# 1 "../_config/startup.c"





extern unsigned int __text_end__;
extern unsigned int __bss_start__;
extern unsigned int __bss_end__;
extern unsigned int __data_start__;
extern unsigned int __data_end__;







int main(void);
int startup(void);

int startup(void)
{
 unsigned int *s;
 unsigned int *begin;
 unsigned int *end;





 (*((volatile unsigned int *)(0x40000000)))=0;

 s = (unsigned int*)&__text_end__;
 begin = (unsigned int*)&__data_start__;
 end = (unsigned int*)&__data_end__;
 while( begin < end) {
  *begin = *s;
  begin++;s++;
 }
# 52 "../_config/startup.c"
 begin = (unsigned int*)&__bss_start__;
 end = (unsigned int*)&__bss_end__;
 while( begin < end ){
  *begin = 0;begin++;
 }


 return main();
}
