//********************************************************************************** 
//** 文件名称：CT3D_SecondVersatileVertex3fWithoutRGB.h
//** CopyRight (c) 2000-2012 武大吉奥信息技术有限公司开发一部
//** 文件描述： 三维顶点类（全有顶点 ）定义，
//** 创 建 人： 杨灵
//** 创建日期： 2012-04-13
//********************************************************************************** 

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#include "CT3D_VersatileVertex3fWithoutRGB.h"

class /*DLL_EXPORT*/ SecondVersatileVertex3fWithoutRGB : public Vertex3f
{
	/** @defgroup VersatileVertex3f VersatileVertex3f-全有顶点  
    *  @{
    */

public:	
    /** 法线 */
    float nx; 
    float ny; 
    float nz;

    /** 纹理坐标 */
    float tu; 
    float tv;

    /** 纹理坐标 */
	float tu2; 
    float tv2;
	
public:
	/** 构造函数1
	*/
	SecondVersatileVertex3fWithoutRGB(float fx = 0.0,float fy = 0.0,float fz = 0.0,float fnx = 0.0,float fny = 0.0,float fnz = 0.0,float fu = 0.0,float fv = 0.0,float fu2 = 0.0,float fv2 = 0.0);
	  
	  
	  /** 构造函数2
	*/
	SecondVersatileVertex3fWithoutRGB(Vertex3f& vPos,Vertex3f& vNor,float fu,float fv,float fu2,float fv2);
	 
	  /** 构造函数3
	*/
	SecondVersatileVertex3fWithoutRGB(Vertex3f& vPos,Vertex3f& vNor,Vertex2f& vTex,Vertex2f& vTex2); 


	/** 获得顶点纹理坐标	
	* @param 
	* @return 顶点纹理坐标	
	*/
	Vertex2f GetSecondTexCoor() const
	{
		return Vertex2f(tu2,tv2);
	}

	/** 设置顶点纹理坐标	
	* @param [in] vTex 顶点纹理坐标		
	* @return
	*/
	void SetSecondTexCoor(const Vertex2f& vTex) 
	{
		tu2 = vTex.x;
		tv2 = vTex.y;
	}	
	static size_t sizeBuffer();
};

