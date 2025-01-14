//********************************************************************************** 
//** 文件名称：CT3D_3DReference.h
//** CopyRight (c) 2000-2012 武大吉奥信息技术有限公司开发一部
//** 文件描述： 三维参照图元类定义
//** 创 建 人： 杨灵
//** 创建日期： 2012-04-11
//********************************************************************************** 

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _CT3D_3DREFERENCE_H_
#define _CT3D_3DREFERENCE_H_

#include "ModelDef.h"
#include "CT3D_3DPoint.h"
#include "CT3D_Quaternion.h"


typedef struct tagScale
{
	double x;
	double y;
	double z;
}Scale;//缩放
class /*DLL_EXPORT*/ C3DReference :
	public C3DPoint
{
	/** @defgroup C3DReference C3DReference-三维参照图元
	*  @{
	*/
protected:
	/** @name 属性（成员变量）
	* @{
	*/

	/** 平移分量 */
	Vertex3d m_vPosition;

	/** 旋转分量 */
	Quaternion m_qOrientation;

	/** 缩放分量 */
	Scale m_Scale;

	/** 关联文件类型 */
	int m_nLinkType;	

	/** 关联对象ID */
	UID64 m_nLinkID;

	/** 关联对象名称 */
	string m_strLinkName;


	/** 附属数据(占用内存)大小 */
	int m_nExtParaSize;

	/** 附属数据 */
	void* m_pExtParaData;

	/** @} */ // 属性结尾

public:

	/** @defgroup C3DReference 操作（成员函数）
	* @{
	*/

	/** @name 构造与析构函数
	*  @{
	*/

	//********************************************************************************** 
	//** 函数名称： C3DReference
	//** 功能描述： 构造函数
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	C3DReference();

	//********************************************************************************** 
	//** 函数名称： ~C3DReference
	//** 功能描述： 析构函数
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	virtual ~C3DReference();

	/** @} */ // 构造与析构函数结尾



	/** @name 数据操作
	*  @{
	*/
	//********************************************************************************** 
	//** 函数名称： GetPosition
	//** 功能描述： 获得插入点位置(平移分量)
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	插入点位置
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	Vertex3d GetPosition() const 
	{ 
		return m_vPosition; 
	}

	//********************************************************************************** 
	//** 函数名称： SetPosition
	//** 功能描述： 设置插入点位置(平移分量)
	//** 输    入： 已知Vertex3d点           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetPosition(Vertex3d pos) 
	{ 
		m_vPosition = pos; 
	}

	//********************************************************************************** 
	//** 函数名称： GetOrientation
	//** 功能描述： 获得四元数(旋转分量)
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	四元数
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	Quaternion GetOrientation() const 
	{ 
		return m_qOrientation; 
	}

	//********************************************************************************** 
	//** 函数名称： SetOrientation
	//** 功能描述： 设置四元数(旋转分量)
	//** 输    入： orientation 已知四元数           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetOrientation(Quaternion orientation) 
	{ 
		m_qOrientation = orientation; 
	}

	//********************************************************************************** 
	//** 函数名称： GetLinkType
	//** 功能描述： 获得关联文件类型
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	关联文件类型
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	int GetLinkType() const 
	{ 
		return m_nLinkType; 
	}

	//********************************************************************************** 
	//** 函数名称： SetLinkType
	//** 功能描述： 设置关联文件类型
	//** 输    入： nLinkType 已知关联文件类型           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetLinkType(int nLinkType) 
	{ 
		m_nLinkType = nLinkType; 
	}
	
	//********************************************************************************** 
	//** 函数名称： GetScale
	//** 功能描述： 获得缩放比例
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	缩放比例
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	Scale GetScale() const 
	{ 
		return m_Scale; 
	}

	//********************************************************************************** 
	//** 函数名称： SetScale
	//** 功能描述： 设置缩放比例
	//** 输    入： _scale 缩放比例           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetScale(Scale _scale) 
	{ 
		m_Scale = _scale; 
	}

	//********************************************************************************** 
	//** 函数名称： GetLinkID
	//** 功能描述： 获得关联对象类型
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	关联对象类型
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	UID64 GetLinkID() const
	{ 
		return m_nLinkID; 
	}
	
	//********************************************************************************** 
	//** 函数名称： SetLinkID
	//** 功能描述： 设置关联对象类型
	//** 输    入： nLinkID 关联对象类型           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetLinkID(UID64 nLinkID)
	{ 
		m_nLinkID = nLinkID; 
	}

	//********************************************************************************** 
	//** 函数名称： GetLinkName
	//** 功能描述： 获得关联对象名称
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	关联对象名称
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	std::string GetLinkName() const 
	{ 
		return m_strLinkName; 
	}

	//********************************************************************************** 
	//** 函数名称： SetLinkName
	//** 功能描述： 设置关联对象名称
	//** 输    入： strLinkName 关联对象名称           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetLinkName(std::string strLinkName) 
	{ 
		m_strLinkName = strLinkName; 
	}

	//********************************************************************************** 
	//** 函数名称： GetExtParaData
	//** 功能描述： 获得连接数据大小及数据首地址
	//** 输    入： nExtParaSize  连接数据大小；pExeParaData  连接数据收地址           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void GetExtParaData(int& nExtParaSize, void*& pExeParaData) const; 	
	
	//********************************************************************************** 
	//** 函数名称： SetExtParaData
	//** 功能描述： 设置连接数据大小及数据首地址
	//** 输    入： nExtParaSize  连接数据大小；pExeParaData  连接数据收地址           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	void SetExtParaData(int nExtParaSize, void* pExeParaData);

	//********************************************************************************** 
	//** 函数名称： DPointToGeometryEx
	//** 功能描述： 计算外部指定的三维点对象到当前几何对象距离的平方
	//** 输    入： vPt	Vertex3d类型三维点对象的引用           
	//** 输    出： 无
	//** 返回值：	点到当前几何对象距离的平方
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
	double DPointToGeometryEx(Vertex3d& vPt) const;

	/** @} */ // 数据操作组结尾



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
	//** 返回值：	成功为true，失败为false
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


#endif /* _INC_C3DREFERENCE_49E347230290_INCLUDED */