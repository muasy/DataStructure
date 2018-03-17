/*
*********************************************************************************************************
* @file    	LinkStack.h
* @author  	SY
* @version 	V1.0.0
* @date    	2016-9-2 10:16:49
* @IDE	 	V4.70.0.0
* @Chip    	STM32F407VE
* @brief   	��ʽ��ջͷ�ļ�
*********************************************************************************************************
* @attention
*
* 
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Define to prevent recursive inclusion
*********************************************************************************************************
*/
#ifndef __LINKSTACK_H
#define __LINKSTACK_H

/*
*********************************************************************************************************
*                              				Exported Includes
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                              				Exported define
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported types
*********************************************************************************************************
*/
typedef struct tagLINK_STACK_TypeDef
{
	void *data;
	struct tagLINK_STACK_TypeDef *next;
}LINK_STACK_TypeDef;


/*
*********************************************************************************************************
*                              				Exported constants
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported macro
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported variables
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                              				Exported functions
*********************************************************************************************************
*/
LINK_STACK_TypeDef *CreateLinkStack( void );
DATA_STRUCT_STATUS_ENUM LinkStackIsEmpty( LINK_STACK_TypeDef *top );
void ClearLinkStack( LINK_STACK_TypeDef *top );
void DestoryLinkStack( LINK_STACK_TypeDef **top );
DATA_STRUCT_STATUS_ENUM PushLinkStack( LINK_STACK_TypeDef *top, void *dataIn, uint32_t dataSize );
DATA_STRUCT_STATUS_ENUM PopLinkStack( LINK_STACK_TypeDef *top, void *dataOut, uint32_t dataSize );
DATA_STRUCT_STATUS_ENUM GetLinkStackElement( LINK_STACK_TypeDef *top, void *dataOut, uint32_t dataSize );
void TraverseLinkStack( LINK_STACK_TypeDef *top, void *dataOut, uint32_t dataSize,\
		void (*show_CallBack)( void *dataOut, uint32_t dataSize) );

#endif
/************************ (C) COPYRIGHT STMicroelectronics **********END OF FILE*************************/
