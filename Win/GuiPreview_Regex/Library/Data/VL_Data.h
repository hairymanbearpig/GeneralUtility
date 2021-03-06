/*******************************************************************************
Vczh Library++ 2.0
数据结构::基本数据结构
开发者：陈梓瀚

接口：
  IVL_Interface									：接口
  IVL_Iterator			<_Type>					：单向迭代器
  IVL_ModifiableIterator<_Type>					：可修改单向迭代器
  IVL_BiIterator		<_Type>					：双向迭代器
内部类：
  VL_Base										：根类
  VL_Markable<_Mark>							：可标记类
  VL_MarkManagerNode							：可标记类管理器内部节点
  VL_MarkManager								：可标记类管理器
  VObjectString<...>							：串
元素类：
  VMbcsString									：Mbcs字符串
  VUnicodeString								：Unicode字符串
  VL_AutoPtr			<_Type>					：非全局引用计数指针管理器，一般用于跟容器组合
  VL_Compair			<_Key,_Value>			：二元组，Key需要可比较大小
  VL_Fullpair			<_Key,_Value>			：二元组，Key和Value都需要可比较大小
  VL_Comvec				<_Type,_Count>			：元素类型相同的向量，元素必须可比较
  VL_Array				<_Type,_Dims>			：多维数组
  VL_Tuple				<_Type0,...,_Type9>		：多元组
  VL_Iterator			<_Type>					：单向迭代器接口实例管理器
  VL_ModifiableIterator	<_Type>					：可修改单向迭代器接口实例管理器
  VL_BiIterator			<_Type>					：双向迭代器接口实例管理器
容器：
  VL_List				<_Type,_SolidType>		：线性表
  VL_OrderedList		<_Type,_SolidType>		：有序线性表
  VL_Chain				<_Type>					：链表
  VL_Bintree			<_Type>					：二叉树
  VL_SearchTree			<_Type>					：搜索树
  VL_BalTree			<_Type>					：平衡搜索树
  VL_ListedMap			_Container,_Key,_Type>	：字典
  VL_MultiMap			<_Key,_Type>			：一对多字典
  VL_FixedPool			<_Object>				：固定对象池
  VL_Pool				<_Object>				：对象池
函数：
  TestMemoryLeaks								：检查内存泄漏状况
  ToMbcs										：Unicode字符串转Mbcs字符串
  ToUnicode										：Mbcs字符串转Unicode字符串

对于Data文件夹中包含的所有容器的共同约定：
  当_SolidType为true的时候，移动对象的时候使用2进制数据复制，否则则调用operator=函数进行复制
  当_Type为VL_AutoPtr的时候，_ExtType必须是VL_AutoPtr所控制的指针的类型
*******************************************************************************/
#ifndef VL_DATA
#define VL_DATA

#define __VL_USE_MEMORY_TEST__

#ifdef __VL_USE_MEMORY_TEST__
	#define CRTDBG_MAP_ALLOC 
	#include <stdlib.h>
	#include <crtdbg.h>
	#define VL_TestMemoryLeaks _CrtDumpMemoryLeaks()
#else
	#define VL_TestMemoryLeaks
#endif

namespace vl
{
	extern void TestMemoryLeaks();
}

#include "Data\VL_Data_Basic.h"

/*********************************************************************************************************
String
*********************************************************************************************************/

#include "Data\VL_Data_String.h"

/*********************************************************************************************************
Iterator
*********************************************************************************************************/

#include "Data\VL_Data_Iterator.h"

/*********************************************************************************************************
Container
*********************************************************************************************************/

#include "Data\VL_Data_List.h"
#include "Data\VL_Data_Chain.h"
#include "Data\VL_Data_CustomBintree.h"
#include "Data\VL_Data_Bintree.h"
#include "Data\VL_Data_SearchTree.h"
#include "Data\VL_Data_BalanceTree.h"
#include "Data\VL_Data_Map.h"
#include "Data\VL_Data_Pool.h"

#endif