/******************************************************************************
*
*  Copyright (C), 2001-2005, Huawei Tech. Co., Ltd.
*
*******************************************************************************
*  File Name     : http.h
*  Version       : Initial Draft
*  Author        : chandler
*  Created       : 2020/1/13
*  Last Modified :
*  Description   : http.c header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/1/13
*           Author       : chandler
*           Modification : Created file
*
******************************************************************************/
#ifndef __HTTP_H__
#define __HTTP_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/




/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

static int http_proxy_send(db_data_pt pdata,void * sendbuffer);
static int init_http_proxy_node(db_data_pt pdata);
extern void init_proxy_http(db_list_pt ptlist);
static void register_http_proxy_method(db_list_pt ptlist,void *pdata);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __HTTP_H__ */
