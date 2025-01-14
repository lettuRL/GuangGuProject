//********************************************************************************** 
//** 文件名称：CT3D_ShadedVertex3f.h
//** CopyRight (c) 2000-2012 武大吉奥信息技术有限公司开发一部
//** 文件描述： 三维顶点类（用于光照计算渲染色彩的顶点）定义，
//** 创 建 人： 杨灵
//** 创建日期： 2012-04-13
//********************************************************************************** 

#if defined (_MSC_VER) && (_MSC_VER >= 1000)
#pragma once
#endif
#ifndef _INC_SHADEDVERTEX3F_49EDC9340121_INCLUDED
#define _INC_SHADEDVERTEX3F_49EDC9340121_INCLUDED

#include "CT3D_Vertex3f.h"


class /*DLL_EXPORT*/ ShadedVertex3f : public Vertex3f
{
    /** @defgroup ShadedVertex3f ShadedVertex3f-用于光照计算渲染色彩的顶点  
    *  @{
    */

public:
    /** @name 属性（成员变量）
    * @{
    */


    /** 法线 */
    float nx; 
    float ny; 
    float nz;

    /** 颜色 */
    float r; 
    float g; 
    float b;

    /** @} */ // 属性结尾

public:

    /** @defgroup ShadedVertex3f 操作（成员函数）
    * @{
    */


    /** @name 构造与析构函数
    *  @{
    */
	//********************************************************************************** 
	//** 函数名称： ShadedVertex3f
	//** 功能描述： 构造函数1
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
    ShadedVertex3f(float fx = 0.0,float fy = 0.0,float fz = 0.0,float fnx = 0.0,float fny = 0.0,float fnz = 0.0,float fr = 0.0,float fg = 0.0, float fb = 0.0);

	//********************************************************************************** 
	//** 函数名称： ShadedVertex3f
	//** 功能描述： 构造函数2
	//** 输    入： 无           
	//** 输    出： 无
	//** 返回值：	无
	//** 作    者： 杨灵
	//** 创建日期： 2012-04-16
	//**********************************************************************************
    ShadedVertex3f(Vertex3f& vPos,Vertex3f& vNor,Vertex3f& vColor);


    //********************************************************************************** 
    //** 函数名称： sizeBuffer
    //** 功能描述：计算三维点结构的大小
    //** 输    入： 无           
    //** 输    出： 无
    //** 返回值：	点结构大小
    //** 作    者： 杨灵
    //** 创建日期： 2012-04-26
    //**********************************************************************************
    static size_t sizeBuffer();

};

#endif /* _INC_SHADEDVERTEX3F_49EDC9340121_INCLUDED */
