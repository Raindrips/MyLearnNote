
#define HTTP   1
#define TCP    2
#define UDP    3
#define UART   4

#define INUSE   1
#define UNUSE   0

typedef unsigned int   u32;
typedef unsigned char  u8;
typedef unsigned short u16;


typedef struct db_data
{
    u8   id;
    u8   flag;
    int  sock_fd;
    u8    * send_buffer;
    u32  (* Init)(struct db_data *pdata);
    int  (* SendFunction)(struct db_data *pdata,void *sendbuffer);
}db_data_t;
typedef db_data_t * db_data_pt;

typedef struct db_node
{
    void *           data;
    struct db_node * prev;
    struct db_node * next;
}db_node_t;
typedef db_node_t * db_node_pt; 


typedef struct db_list
{
    u32  limit_size;
    db_node_pt head;
    db_node_pt tail;
}db_list_t;
typedef db_list_t * db_list_pt ;

extern int errno;

/*****************************************************************************
*   Prototype    : proxy_list_create
*   Description  : proxy list creat function
*   Input        : void
*   Output       : None
*   Return Value : db_list_pt
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/9
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
db_list_pt proxy_list_create( void )
{
    db_list_pt list_head=NULL; 
    list_head = (db_list_pt)malloc(sizeof(db_list_t));
    if(list_head==NULL)
    {
        errno = ENOMEM;
        return NULL;
    }
    list_head->limit_size = 0;
    list_head->head = (db_node_pt)malloc(sizeof(db_node_t));
    if(list_head->head==NULL)
    {
        errno = ENOMEM;
        return NULL;
    }
    list_head->head->next =list_head->head->prev=NULL;
    list_head->head->data =NULL;
    list_head->tail = list_head->head;
    return list_head;
}

/*****************************************************************************
*   Prototype    : proxy_list_insert_before
*   Description  : insert node from head
*   Input        : db_list_t ** list_head
*                  int num
*                  void * new_node_data
*   Output       : None
*   Return Value : int
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/9
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
int proxy_list_insert_before( db_list_t ** list_head, int num, void * new_node_data )
{
    u32 counter = 1;
    db_node_pt current=NULL;
    db_node_pt new_node=NULL;

    if(list_head==NULL||*list_head==NULL)
    {
        errno = EINVAL;
        return -1;
    }
    if((*list_head)->limit_size!=0)
    {
        new_node = (db_node_pt)malloc(sizeof(db_node_t));
        if(new_node==NULL)
        {
            errno = ENOMEM;
            return -1;
        }
        new_node->data = new_node_data;
        new_node->prev = new_node->next=NULL;
        if(num>0 && num<= (*list_head)->limit_size)
        {
            current = (*list_head)->head;
            while(counter < num)
            {
                counter++;
                current = current->next;
            }
            if(counter==1)
            {
                (*list_head)->head->prev = new_node;
                new_node->next = (*list_head)->head;
                (*list_head)->head = new_node;
                (*list_head)->limit_size++;
                return 0 ;
            }
           // current->prev->next = new_node;
            current->next->prev = new_node;
            new_node->prev = current->prev;
            current->prev = new_node;
            new_node->next =current;
            (*list_head)->limit_size++;
            return 0;
        }
    }
    else
    {         
        if (num!=0)
        {
            errno=EINVAL;
            return -1;
        }
        (*list_head)->head->data=new_node_data;
        (*list_head)->limit_size++;
        return 0;
    }
}


/*****************************************************************************
*   Prototype    : core_list_insert_after
*   Description  : db_list_t **list_head
*   Input        : db_list_t ** list_head
*                  int num
*                  void * new_node_data
*   Output       : None
*   Return Value : int
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/10
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
int proxy_list_insert_after(db_list_t ** list_head, int num, void * new_node_data )
{
    u32 counter = 1;
    db_node_pt current=NULL;
    db_node_pt new_node=NULL;

    if(list_head==NULL||*list_head==NULL)
    {
        errno = EINVAL;
        return -1;
    }
    if((*list_head)->limit_size!=0)
    {
        new_node = (db_node_pt)malloc(sizeof(db_node_t));
        if(new_node==NULL)
        {
            errno = ENOMEM;
            return -1;
        }
        new_node->data = new_node_data;
        new_node->prev = new_node->next=NULL;
        if(num>0 && num<= (*list_head)->limit_size)
        {
            current = (*list_head)->head;
            while(counter < num)
            {
                counter++;
                current = current->next;
            }
            if(current->next==NULL)
            {
                (*list_head)->tail = new_node;
                current->next = new_node;
                new_node->prev = current;
                (*list_head)->limit_size++;
                return 0;
            }
            new_node->prev = current;
            new_node->next = current->next;
            current->next = new_node;
            current->next->prev = new_node;
            (*list_head)->limit_size++;
            return 0;
        }
        else
        {
            errno = EINVAL;
            free(new_node);
            new_node=NULL;
            return -1;
        }
    }
    else
    {
        if (num!=0)
        {
            errno=EINVAL;
            return -1;
        }
        (*list_head)->head->data=new_node_data;
        (*list_head)->limit_size++;
        return 0;
    }
}

/*****************************************************************************
*   Prototype    : core_list_delete
*   Description  : list delete
*   Input        : db_list_t **list_head
*                  int num
*   Output       : None
*   Return Value : int
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/10
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
int proxy_list_delete(db_list_t **list_head, int num )
{
    int counter =1;
    db_node_pt current=NULL;
    db_node_pt tmp=NULL;
    if(list_head==NULL||*list_head==NULL)
    {
        errno = EINVAL;
        return -1;
    }
    current = (*list_head)->head;
    while ( counter < num )
    {
        counter++;
        current=current->next;
    }
    if(counter==1)
    {
        tmp= (*list_head)->head;
        (*list_head)->head=(*list_head)->head->next;
        free(tmp);
        tmp=NULL;
        (*list_head)->head->prev = NULL;
        (*list_head)->limit_size--;
        return 0;
    }
    if((*list_head)->limit_size==counter)
    {
         tmp= (*list_head)->tail;
         (*list_head)->tail=(*list_head)->tail->prev;
         free(tmp);
         tmp =NULL;
         (*list_head)->tail->next =NULL;
         (*list_head)->limit_size--;
         return 0;
    }
    tmp =current;
    current->prev->next=current->next;
    current->next->prev=current->prev;
    free(tmp);
    tmp=NULL;
    (*list_head)->limit_size--;
    return 0;
}

/*****************************************************************************
*   Prototype    : core_list_modify
*   Description  : modify node data
*   Input        : db_list_t ** list_head
*                  int num
*                  void *new_node_data
*   Output       : None
*   Return Value : int
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/10
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
int proxy_list_modify( db_list_t ** list_head, int num, void *new_node_data )
{
    int counter =0;
    db_node_pt current=NULL;    
    if(list_head==NULL||*list_head==NULL||num <0 || num >(*list_head)->limit_size)
    {
        errno = EINVAL;
        return -1;
    }
    current= (*list_head)->head;
    while ( counter!=num-1 )
    {
        counter++;
        current=current->next;    
    }
    current->data = new_node_data;
    return 0;
}


/*****************************************************************************
*   Prototype    : core_list_visit
*   Description  : show num node data
*   Input        : u32 num
*   Output       : None
*   Return Value : db_list_t ** list_head
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/10
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
static inline void * __proxy_list_visit(db_list_t **list_head ,u32 num )
{
    int counter=0;
    db_node_pt current=(*list_head)->head;
    if(list_head==NULL||*list_head==NULL||num <0 || num >(*list_head)->limit_size)
    {
        errno = EINVAL;
        return -1;
    }
    for(counter=0;counter<num;counter++)
    {
        current=current->next;
    }
    return (void *)current->data;
}


/*****************************************************************************
*   Prototype    : core_list_cuid
*   Description  : travel this list
*   Input        : db_list_t  * list_head
*                  void *(do_function)(void *)
*   Output       : None
*   Return Value : void
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/10
*           Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
void proxy_list_cuid( db_list_t  * list_head, void (*do_function)(void *) )
{
    u32 i =0;
    if(list_head==NULL || list_head->limit_size<0)
    {
        errno = EINVAL;
        return -1;
    }
    for ( i=0;i<list_head->limit_size ; i++ )
    {
        (* do_function)(__proxy_list_visit(&list_head,i));
    }
}

/*****************************************************************************
*   Prototype    : core_list_search
*   Description  : search list 
*   Input        : db_list_t ** list_head
*                  void * find_data
*                  int(*compare)(void *,void*)
*   Output       : None
*   Return Value : int
*   Calls        : 
*   Called By    : 
*
*   History:
* 
*       1.  Date         : 2020/1/10
*
Author       : chandler
*           Modification : Created function
*
*****************************************************************************/
int proxy_list_search( db_list_t ** list_head, void * find_data, int(* compare)(void *,void*) )
{
    int counter =1;
    db_node_pt current=(*list_head)->head;
    if(list_head==NULL|| *list_head==NULL)
    {
        errno = EINVAL;
        return -1;
    }
    current=(*list_head)->head;
    while (compare(current->data,find_data)!=0 && current->next!=NULL )
    {
        current=current->next;
        counter++;
    }
    if(current->next==NULL && compare(current->data,find_data)!=0)
        return 0;
    return counter;
}

