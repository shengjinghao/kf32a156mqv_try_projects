//*********************************************************************************************************
//
//
//
//*********************************************************************************************************
#ifndef _ChipMessageAPI_H
#define _ChipMessageAPI_H

#ifdef __cplusplus
extern "C" {
#endif
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// selecte flash or ram function,can define by extern
#ifndef __Use_Flash_Driver_RAM__
	#define  __Use_Flash_Driver_RAM__	0
#endif

// erase write function need key, no support modify
#define Function_Parameter_Validate   0x5A5A6688
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if __Use_Flash_Driver_RAM__
	#define __getChipMessage			__getChipMessage__RAM__
	#define __getChipUniqueSerialNumber	__getChipUniqueSerialNumber__RAM__
	#define __getChipMessages			__getChipMessages__RAM__

	#define __FLASH_Erase__				__FLASH_Erase__RAM__
	#define __FLASH_Program__			__FLASH_Program__RAM__
	#define __FLASH_Read_One__			__FLASH_Read_One__RAM__
	#define __FLASH_Read__				__FLASH_Read__RAM__
	#define __FLASH_Check__				__FLASH_Check__RAM__

	#define __FLASHCFG_Program__		__FLASHCFG_Program__RAM__
	#define __FLASHCFG_Read__			__FLASHCFG_Read__RAM__
#endif

#define __FLASH_Program_NBytes__	__FLASH_Program_NBytes__RAM__
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define CMD_SUCCESS 									0x00
#define INVALID_COMMAND									0x01
#define SRC_ADDR_ERROR									0x02
#define DST_ADDR_ERROR									0x03
#define SRC_ADDR_NOT_MAPPED 							0x04
#define DST_ADDR_NOT_MAPPED 							0x05
#define COUNT_ERROR										0x06
#define INVALID_SECTOR 									0x07
#define SECTOR_NOT_BLANK								0x08
#define SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION 		0x09
#define COMPARE_ERROR									0x0A
#define BUSY 											0x0B
#define PARAM_ERROR										0x0C
#define ADDR_ERROR										0x0D
#define ADDR_NOT_MAPPED									0x0E
#define CMD_LOCKED										0x0F
#define INVALID_CODE									0x10
#define INVALID_BAUD_RATE								0x11
#define INVALID_STOP_BIT								0x12
#define CODE_READ_PROTECTION_ENABLED					0x13

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//// for chip message or flash data driver
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Return:CMD_SUCCESS 									0x00
//Return:COUNT_ERROR									0x06
//Return:ADDR_ERROR 									0x0D
//Return:ADDR_NOT_MAPPED 								0x0E

//Parameter: address can  be 0x1C00~0x1FFC or 0x900~0xFFC
//Parameter: length  must align by 2,like  4 8 12 16 ....
//Parameter: buffers must big than the length,like  sizeof(buffers)==length+1, stores begin buffers[1] of readout

/*
 *Get Chip Message or Data
 *range:(   ( addr>=0x900 && addr <0x1000 )   || (addr>=0x1C00 && addr<0x2000)  ) ,align 4.
 *return 0 with fail,or return data with succeed  
 */
unsigned int __getChipMessage(unsigned int address);

 /*
 *Get Chip Message of ID
 *return -1 with fail,or return 0 with succeed , buffers must align by 4 byte 
 */
unsigned int __getChipUniqueSerialNumber(unsigned int buffers[]);
/*
 *Get Chip Message or Data
 *range:(   ( addr>=0x900 && addr <0x1000 )   || (addr>=0x1C00 && addr<0x2000)  ) ,align 4.
 *len  size of byte  
 *buffers align by 32bit,value rerurn with size offset one word,That means first word record the result flag by function,value 0 is succeed.data is saved from buffers[1]
 *return -1 with fail,or return 0 with succeed
 */
unsigned int __getChipMessages(unsigned int address,unsigned int len,unsigned int buffers[]);

/*
 * driver  server op flash function
 *
 *
 */
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//// flash   erase first and write then
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Return:CMD_SUCCESS 									0x00
//Return:BUSY 											0x0B
//Return:SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION 		0x09
//Return:INVALID_SECTOR 								0x07
//Parameter: address aligned by 1K and length like 1024 2048 3072 4096
//Parameter: key must be Function_Parameter_Validate by check 
unsigned int  __FLASH_Erase__(unsigned int key,unsigned int address,unsigned int length);


//Return:CMD_SUCCESS 									0x00
//Return:SRC_ADDR_ERROR								0x02
//Return:DST_ADDR_ERROR								0x03
//Return:SRC_ADDR_NOT_MAPPED 							0x04
//Return:DST_ADDR_NOT_MAPPED 							0x05
//Return:COUNT_ERROR(not bytes 1K 2K 3K 4K)			0x06
//Return:SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION 		0x09
//Return:BUSY 											0x0B
//Parameter: address aligned by 1K ,and length can be 1K 2K 3K 4K
//Parameter: key must be Function_Parameter_Validate by check 
unsigned int  __FLASH_Program__(unsigned int key,unsigned int address,unsigned int length,unsigned int buffers[]);

//Return:CMD_SUCCESS 									0x00
//Return:PARAM_ERROR									0x0C
//Parameter: address aligned by 8Bytes and length like 8 16 24 32 ... 8*N
//Parameter: buffers must have enough size to save the result
//Parameter: key must be Function_Parameter_Validate by check 
__attribute__((section(".indata")))
unsigned int  __FLASH_Program_NBytes__(unsigned int key,unsigned int address,unsigned int length,unsigned int buffers[]);

//Return:one byte 									0x00
unsigned char  __FLASH_Read_One__(unsigned int address);
//Return:CMD_SUCCESS 									0x00
//Parameter: buffers must have enough size to save the result
unsigned int  __FLASH_Read__(unsigned int address,unsigned int length,unsigned char buffers[]);

//Return:CMD_SUCCESS 									0x00
//Return:COMPARE_ ERROR								0x0A
//Return:COUNT_ERROR									0x06
//Return:ADDR_ERROR									0x0D
//Return:ADDR_NOT_MAPPED								0x0E

//Parameter:address aligned by 2 ,like 0 4 8 12 16....
//Parameter: length  must align by 2,like  4 8 12 16 ....
unsigned int  __FLASH_Check__(unsigned int address,unsigned int length,unsigned char buffers[]);


//Return:CMD_SUCCESS 									0x00
//Return:PARAM_ERROR									0x0C
//Parameter:startaddress aligned by 16bytes like 0 16 32 48 64
//Parameter:length  aligned by 16bytes like 16 32 48 64
//Parameter:CheckSum Resultin.size of result must mort than 4*4 bytes and address aligned by 4bytes. like 0x1XXX XXX0 or 0x1XXX XXX4 0x1XXX XXX8 0x1XXX XXXC by defined with type of int
__attribute__((section(".indata")))
unsigned int  __FLASH_CheckSum_With_128bits__(unsigned int startaddress,unsigned int length,unsigned int result[]);

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//flash cfg  wirte with auto erase first
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//Return:CMD_SUCCESS 									0x00
//Return:SRC_ADDR_ERROR								0x02
//Return:DST_ADDR_ERROR								0x03
//Return:SRC_ADDR_NOT_MAPPED 							0x04
//Return:DST_ADDR_NOT_MAPPED 							0x05
//Return:COUNT_ERROR(not bytes 1K 2K 3K 4K)			0x06
//Return:SECTOR_NOT_PREPARED_FOR_WRITE_OPERATION 		0x09
//Return:BUSY 											0x0B

//Parameter:address must is 0x1C00
//Parameter:length must be 1024,
//Parameter:buffers[256] with 1024 bytes at least
//Parameter: key must be Function_Parameter_Validate by check 
unsigned int  __FLASHCFGUSER_Program__(unsigned int key,unsigned int address,unsigned int length,unsigned int buffers[]);
//Return:CMD_SUCCESS 								0x00
//Return:COUNT_ERROR								0x06
//Return:ADDR_ERROR									0x0D
//Return:ADDR_NOT_MAPPED							0x0E

//Parameter: address must between 0x1C00-0x1FFF ,with length ,all data must be between 0x1C00-0x1FFF
//Parameter: length  must align by 2,like  4 8 12 16 ....
//Parameter:result, buffers must big then length,like  sizeof(buffers)==length+1, stores begin buffers[1] of readout
unsigned int  __FLASHCFGUSER_Read__(unsigned int address,unsigned int length,unsigned int buffers[]);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#ifdef __cplusplus
}
#endif
#endif