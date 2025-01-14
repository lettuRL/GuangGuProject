//********************************************************************************** 
//** 文件名称：CT3D_C3DPoint.h
//** CopyRight (c) 2000-2012 武大吉奥信息技术有限公司开发一部
//** 文件描述： 三维点类实现
//** 创 建 人： 杨灵
//** 创建日期： 2012-04-14
//********************************************************************************** 

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _CT3D_3DPOINT_H_
#define _CT3D_3DPOINT_H_

#include "ModelDef.h"
#include "CT3D_3DGeometry.h"
#include <vector>
using namespace std;


class /*DLL_EXPORT*/ C3DPoint 
: public C3DGeometry
{
	/** @defgroup C3DPoint C3DPoint-三维点  
    *  @{
    */

public:

	/** @defgroup C3DPoint 操作（成员函数）
	* @{
	*/

	/** @name 构造与析构函数
	*  @{
	*/
	
	//********************************************************************************** 
	//** 函数名称： C3DPoint
	//** 功能描述： 构造函数
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	C3DPoint();

	//********************************************************************************** 
	//** 函数名称： ~C3DPoint
	//** 功能描述： 析构函数
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	virtual ~C3DPoint();

	/** @} */ // 构造与析构函数结尾


	/** @name 计算操作
	*  @{
	*/

	//********************************************************************************** 
	//** 函数名称： CreateObject
	//** 功能描述： 开辟一个当前类对象所需的内存空间
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	开辟的当前类对象内存空间的首地址
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	CGeometry* CreateObject();

	//********************************************************************************** 
	//** 函数名称： readBuffer
	//** 功能描述： 从缓冲区中解析当前对象，并给成员变量赋值
	//** 输    入： buf	缓冲区的引用           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	bool readBuffer( Buffer & buf);

	//********************************************************************************** 
	//** 函数名称： writeBuffer
	//** 功能描述： 把当前对象的成员变量数据，打包成一个缓冲区
	//** 输    入： buf	缓冲区的引用           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void writeBuffer(Buffer& buf);

	virtual size_t sizeBuffer();

	
};

#endif 
