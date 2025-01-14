//********************************************************************************** 
//** 文件名称：CT3D_3DLinearRing.h
//** CopyRight (c) 2000-2012 武大吉奥信息技术有限公司开发一部
//** 文件描述： 三维三角形网格类定义
//** 创 建 人： 杨灵
//** 创建日期： 2012-04-11
//********************************************************************************** 


#ifndef _INC_C3DTRIANGLEMESH_49E347280178_INCLUDED
#define _INC_C3DTRIANGLEMESH_49E347280178_INCLUDED

#include "ModelDef.h"
#include "CT3D_3DSurface.h"
#include "ModelDef.h"
//#include "MemManager.h"
#include <vector>
#include <osg/Geode>

using namespace std;


class  C3DTriangleMesh : public C3DSurface
{

public:
    /** 顶点类型编码 */
    byte m_byVertexType;
   
    /** 顶点列表长度，亦即顶点数目 */
    long m_lVertNum;

	/** 顶点列表 */
	void* m_vVertexList;	

    /** 三角形索引表长度，索引指向顶点列表，长度为三角形个数的3倍 */
    long m_lTriListSize;

	/** 三角形索引表 */
	long* m_lTriangleList;

    /** 三角形条带索引表长度，索引指向顶点列表，长度与为三角形个数加上2 */
    long m_lStripListSize;
	
    /** 三角形条带索引表 */
	long* m_lStripIndices;

protected:
	int GetVertexStrideFromType(int nType);
	void FreeVertexBuffer();
public:
	/*osg::Geode m_osgGeode;*/

	//********************************************************************************** 
	//** 函数名称： C3DTriangleMesh
	//** 功能描述： 构造函数
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	C3DTriangleMesh();

	//********************************************************************************** 
	//** 函数名称： ~C3DTriangleMesh
	//** 功能描述： 析构函数
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	virtual ~C3DTriangleMesh();
	
	//********************************************************************************** 
	//** 函数名称： GetVertexType
	//** 功能描述： 获得顶点类型编码
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	顶点类型编码
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	byte GetVertexType() const;

	
	
	//********************************************************************************** 
	//** 函数名称： GetVertices
	//** 功能描述： 获得顶点列表
	//** 输    入： vVertexList的地址           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	void GetVertices(void*& vVertexList) const;
;
	
//********************************************************************************** 
//** 函数名称： GetVertices
//** 功能描述： 获得顶点列表和顶点列表长度
//** 输    入： vVertexList	顶点列表的地址 ；lVertNum	顶点列表长度的地址         
//** 输    出： 无
//** 返回值：	无
//** 作    者： 杨灵
//** 创建日期： 2012-04-11
//**********************************************************************************
	void GetVertices(void*& vVertexList,long& lVertNum) const;

	
	//********************************************************************************** 
	//** 函数名称： GetVerticesNum
	//** 功能描述： 获得顶点列表长度
	//** 输    入： 无         
	//** 输    出： 无
	//** 返回值：	顶点列表长度
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	long GetVerticesNum() const;

	
	
	//********************************************************************************** 
	//** 函数名称： GetTriangles
	//** 功能描述： 获得三角形索引
	//** 输    入： 三角形索引序列：tr3d         
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	void GetTriangles(vector<long>& tr3d);
	
	
	//********************************************************************************** 
	//** 函数名称： GetStrips
	//** 功能描述： 获得三角形条带索引
	//** 输    入： 三角形条带索引序列：st3d        
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	void GetStrips(vector<long>& st3d);
	
	
	//********************************************************************************** 
	//** 函数名称： GetTriangles
	//** 功能描述： 获得三角形索引及索引长度
	//** 输    入： 三角形索引序列lTriangleList的地址；三角形索引长度lTriListSize的地址
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	void GetTriangles(long*& lTriangleList, long& lTriListSize) const;
	
	
	//********************************************************************************** 
	//** 函数名称： GetStrips
	//** 功能描述： 获得三角形条带索引及索引长度
	//** 输    入： 三角形条带索引序列lStripIndices的地址；三角形条带索引长度lStripListSize的地址       
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	void GetStrips(long*& lStripIndices, long& lStripListSize) const;
	
public:

	//********************************************************************************** 
	//** 函数名称： readBuffer
	//** 功能描述： 将数据读入buf
	//** 输    入： Buffer对象buf的引用           
	//** 输    出： 无
	//** 返回值：	成功为true，失败为false
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	bool readBuffer( Buffer & buf);

	//********************************************************************************** 
	//** 函数名称： writeBuffer
	//** 功能描述： 将数据写入buf
	//** 输    入： Buffer对象buf的引用           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-11
	//**********************************************************************************
	void writeBuffer(Buffer& buf);

	virtual size_t sizeBuffer();

public:

//********************************************************************************** 
//** 函数名称： SetVertices
//** 功能描述： 设置顶点列表和顶点列表长度，顶点类型
//** 输    入： vVertexList	顶点列表的地址 ；lVertNum	顶点列表长度的地址  
//**			byVerType 顶点类型
//**			lBufSize  顶点Buffer长度
//** 输    出： 无
//** 返回值：	无
//** 作    者： 周星
//** 创建日期： 2012-06-9
//**********************************************************************************
	void SetVertices(void* vVertexList,long lVertNum, long lBufSize, byte byVerType);
	bool DoubleVertex2FloatVertex(bool bInverseTexCood);

	void SetTriangles(long* const lTriangleList, long lTriListSize);
	void FreeIndexBuffer();
};

#endif 
