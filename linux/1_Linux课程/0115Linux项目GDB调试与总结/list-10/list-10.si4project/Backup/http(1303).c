

static int init_tcp_proxy_node(db_data_pt pdata)
{

}

static int tcp_proxy_send(db_data_pt pdata,void * sendbuffer)
{

}


static db_data_t tcp_proxy_node ={
    .id = TCP ,
    .flag = INUSE,
    .Init = init_tcp_proxy_node,
    .SendFunction = tcp_proxy_send,
};

static void register_tcp_proxy_method(db_list_pt ptlist,void *pdata)
{
    if(ptlist==NULL || pdata==NULL)
    {
       errno =EINVAL;
       return ;
    }
    proxy_list_insert_before(&ptlist,1, pdata);
}

void init_proxy_tcp(db_list_pt ptlist)
{
    register_tcp_proxy_method(ptlist,(void *)&tcp_proxy_node);
}
