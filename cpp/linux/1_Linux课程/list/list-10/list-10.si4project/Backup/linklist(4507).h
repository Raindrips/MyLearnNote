/******************************************************************************
*
*  Copyright (C), 2001-2005, Huawei Tech. Co., Ltd.
*
*******************************************************************************
*  File Name     : linklist.h
*  Version       : Initial Draft
*  Author        : chandler
*  Created       : 2020/1/13
*  Last Modified :
*  Description   : linklist.c header file
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
#ifndef __LINKLIST_H__
#define __LINKLIST_H__


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

extern db_list_pt proxy_list_create( void );
extern void proxy_list_cuid( db_list_t  * list_head, void (*do_function)(void *) );
extern int proxy_list_delete(db_list_t **list_head, int num );
extern int proxy_list_insert_after(db_list_t ** list_head, int num, void * new_node_data );
extern int proxy_list_insert_before( db_list_t ** list_head, int num, void * new_node_data );
extern int proxy_list_modify( db_list_t ** list_head, int num, void *new_node_data );
extern int proxy_list_search( db_list_t ** list_head, void * find_data, int(* compare)(void *,void*) );
static inline void * __proxy_list_visit(db_list_t **list_head ,u32 num );

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __LINKLIST_H__ */
