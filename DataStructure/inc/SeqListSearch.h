/*
*********************************************************************************************************
* @file    	SeqListSearch.h
* @author  	SY
* @version 	V1.0.0
* @date    	2016-9-12 15:58:15
* @IDE	 	V4.70.0.0
* @Chip    	STM32F407VE
* @brief   	˳�����Ա��㷨ͷ�ļ�
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
#ifndef __SEQ_LIST_SEARCH_H
#define __SEQ_LIST_SEARCH_H

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
typedef struct
{
	void *key;	
	void *value;	
}SEQ_LIST_SEARCH_NODE_TypeDef;

typedef struct
{
	void *basePtr;
	uint32_t maxLenth;
}SEQ_LIST_SEARCH_TypeDef;

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
* Function Name : SeqListSearchSetNodeU32_CallBack
* Description	: ˳�����Ա�����32λ�ڵ����ݻص�����
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
__STATIC_INLINE void SeqListSearchSetNodeU32_CallBack( void *base, uint32_t nodeIndex,\
		void *key, void *value )
{
	SEQ_LIST_SEARCH_NODE_TypeDef *nodePtr = ((SEQ_LIST_SEARCH_NODE_TypeDef *)base + nodeIndex);
	
	nodePtr->key = key;
	nodePtr->value = value;
}

/*
*********************************************************************************************************
* Function Name : SeqListMatchKeyU32_CallBack
* Description	: ���Ա��ֵƥ��
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
__STATIC_INLINE void *SeqListMatchKeyU32_CallBack( void *base, uint32_t nodeIndex, void *findKey )
{
	SEQ_LIST_SEARCH_NODE_TypeDef *nodePtr = ((SEQ_LIST_SEARCH_NODE_TypeDef *)base + nodeIndex);
	uint32_t *nodeKeyPtr = nodePtr->key;
	uint32_t *findKeyPtr = findKey;
	
	if (*findKeyPtr == *nodeKeyPtr)
	{
		return nodePtr->value;
	}
	else
	{
		return NULL;
	}
}

/*
*********************************************************************************************************
* Function Name : SeqListIsEqualKeyU32_CallBack
* Description	: ���Ա��ֵ�Ƿ����
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
__STATIC_INLINE int8_t SeqListIsEqualKeyU32_CallBack( void *base, uint32_t nodeIndex,\
		void *findKey )
{
	SEQ_LIST_SEARCH_NODE_TypeDef *nodePtr = ((SEQ_LIST_SEARCH_NODE_TypeDef *)base + nodeIndex);
	uint32_t *nodeKeyPtr = nodePtr->key;
	uint32_t *findKeyPtr = findKey;
	
	if (*findKeyPtr > *nodeKeyPtr)
	{
		return 1;
	}
	else if (*findKeyPtr < *nodeKeyPtr)
	{
		return -1;
	}
	else
	{	
		return 0;
	}
}

/*
*********************************************************************************************************
* Function Name : SeqListReverseIsEqualKeyU32_CallBack
* Description	: ���Ա��ֵ�Ƿ����(֧�ּ�ֵ�Ӵ�С)
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
__STATIC_INLINE int8_t SeqListReverseIsEqualKeyU32_CallBack( void *base, uint32_t nodeIndex,\
		void *findKey )
{
	SEQ_LIST_SEARCH_NODE_TypeDef *nodePtr = ((SEQ_LIST_SEARCH_NODE_TypeDef *)base + nodeIndex);
	uint32_t *nodeKeyPtr = nodePtr->key;
	uint32_t *findKeyPtr = findKey;
	
	if (*findKeyPtr > *nodeKeyPtr)
	{
		return -1;
	}
	else if (*findKeyPtr < *nodeKeyPtr)
	{
		return 1;
	}
	else
	{	
		return 0;
	}
}

/*
*********************************************************************************************************
* Function Name : SeqListGetValue
* Description	: ˳�����Ա��ȡֵ
* Input			: None
* Output		: None
* Return		: None
*********************************************************************************************************
*/
__STATIC_INLINE void *SeqListGetValue( SEQ_LIST_SEARCH_TypeDef *listPtr, uint32_t keyIndex )
{
	SEQ_LIST_SEARCH_NODE_TypeDef *nodePtr = ((SEQ_LIST_SEARCH_NODE_TypeDef *)(listPtr->basePtr) + keyIndex);
	
	if (keyIndex >= listPtr->maxLenth)
	{
		return NULL;
	}
	
	return nodePtr->value;
}

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
void InitSeqListSearching( SEQ_LIST_SEARCH_TypeDef *listPtr, void *pBase, uint32_t lenth );
bool InsertSeqListSearchingNode( SEQ_LIST_SEARCH_TypeDef *listPtr,\
		uint32_t nodeIndex, void *key, void *value,\
		void (*setNode_CallBack)( void *base, uint32_t nodeIndex, void *key, void *value ) );
void *SeqListSequenceSearching( SEQ_LIST_SEARCH_TypeDef *listPtr, void *findKey,\
		void *(*matchKey_CallBack)( void *base, uint32_t nodeIndex, void *findKey ) );
bool SeqListBinSearching( SEQ_LIST_SEARCH_TypeDef *listPtr, void *findKey, uint32_t *keyIndex,\
		int8_t (*equalKey_CallBack)( void *base, uint32_t nodeIndex, void *findKey ) );


#endif
/************************ (C) COPYRIGHT STMicroelectronics **********END OF FILE*************************/
