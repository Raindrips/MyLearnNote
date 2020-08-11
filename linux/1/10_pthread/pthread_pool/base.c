#include "pthread_pool.h"

/*
*child_work:the code exec in child thread
*ptr: the ds of thread_node of current thread.
*return :nothing.void * just avoid warning.
*/ 

void *child_work (void *ptr) 
{
  // ��ԭ����
  THREAD_NODE * self = (THREAD_NODE *) ptr;
  /*modify the tid attribute the first time exec */ 
  pthread_mutex_lock (&self->mutex);
  
  //self->tid = syscall (SYS_gettid);
  self->tid = gettid();
  pthread_mutex_unlock (&self->mutex);
  
  while (1)
  {
    pthread_mutex_lock (&self->mutex);
    /*if no task exec,blocked */ 
    if (NULL == self->work)
    {   
      pthread_cond_wait (&self->cond, &self->mutex);
    }
    pthread_mutex_lock (&self->work->mutex);
    /*execute the real work. */ 
    self->work->fun (self->work->arg);

    /*after finished the work */ 
    self->work->fun = NULL;
    self->work->flag = 0;
    self->work->tid = 0;
    self->work->next = NULL;
    free (self->work->arg);
    self->work->arg=NULL;
    pthread_mutex_unlock (&self->work->mutex);  //unlock the task
    pthread_mutex_destroy (&self->work->mutex);
    /*free the task space */ 
    free (self->work);
      
    self->work = NULL;
    pthread_mutex_lock (&task_queue_head->mutex);
    /*
     *get new task from the task_link if not NULL.
     *there no idle thread if there are task to do.
     *if on task ,make self idle and add to the idle queue.
     */ 
    if(task_queue_head->head != NULL)
    {
      TASK_NODE * temp = task_queue_head->head;
      /*get the first task */ 
      task_queue_head->head = task_queue_head->head->next;          
      /*modify self thread attribute */ 
      self->flag = 1;          
      self->work = temp;       
      temp->tid = self->tid;        

      temp->flag = 1;          
      task_queue_head->number--;     


       continue;        
    }     
    else        
    {          
      /*no task need to exec, add self to idle queue and del from busy queue */ 
      pthread_mutex_unlock (&task_queue_head->mutex); 
      pthread_mutex_lock (&pthread_queue_busy->mutex);          
          /*self is the last execte thread */ 
      if (pthread_queue_busy->head == self
                && pthread_queue_busy->rear == self)
      {              
          
          /*the first one thread in busy queue */ 
      else if (pthread_queue_busy->head == self
                     && pthread_queue_busy->rear != self)
      {              
              
          
            /*the last one thread in busy queue */ 
      else if (pthread_queue_busy->head != self
                     && pthread_queue_busy->rear == self)            
      {              
           
          
      /*middle one */ 
      else            
      {              
        /*add self to the idle queue */ 
      pthread_mutex_lock (&pthread_queue_idle->mutex);          
        /*now the idle queue is empty */ 
      if (pthread_queue_idle->head == NULL
                || pthread_queue_idle->head == NULL)
      {              
          
      else
      {              
           
        /*signal have idle thread */ 
      pthread_cond_signal (&pthread_queue_idle->cond);    
}
/*
*create thread pool when the system on, and thread number is THREAD_DEF_NUM.
*when init, initial all the thread into a double link queue and all wait fo self->cond. 
*/ 
void
create_pthread_pool (void) 
{
  THREAD_NODE * temp =
    (THREAD_NODE *) malloc (sizeof (THREAD_NODE) * THREAD_DEF_NUM);
  
  {
    printf (" malloc failure\n");
    exit (EXIT_FAILURE);
  }

    /*init as a double link queue */ 
  int i;
  for (i = 0; i < THREAD_DEF_NUM; i++)
  {      
  
  
   
   
      
         temp[i].prev = NULL;
      else
  
  
  
  
        /*create this thread */ 
    pthread_create (&temp[i].tid, NULL, child_work, (void *) &temp[i]);  
  } 

      
    /*modify the idle thread queue attribute */ 
  pthread_mutex_lock (&pthread_queue_idle->mutex);  
  pthread_queue_idle->number = THREAD_DEF_NUM;  
  pthread_queue_idle->head = &temp[0];  
  pthread_queue_idle->rear = &temp[THREAD_DEF_NUM - 1]; 
  pthread_mutex_unlock (&pthread_queue_idle->mutex);


/*
*init_system :init the system glob pointor.
*/ 
void
init_system (void) 
{  
    /*init the pthread_queue_idle */ 
     pthread_queue_idle =
    (PTHREAD_QUEUE_T *) malloc (sizeof (PTHREAD_QUEUE_T));
  
  
  
  
     pthread_cond_init (&pthread_queue_idle->cond, NULL);  
    /*init the pthread_queue_busy */ 
    pthread_queue_busy =
    (PTHREAD_QUEUE_T *) malloc (sizeof (PTHREAD_QUEUE_T));
  
  
  
  
    pthread_cond_init (&pthread_queue_busy->cond, NULL);  
    /*init the task_queue_head */ 
    task_queue_head = (TASK_QUEUE_T *) malloc (sizeof (TASK_QUEUE_T));
  
    task_queue_head->number = 0;  
    pthread_cond_init (&task_queue_head->cond, NULL); 
  

  /*create thread poll */ 
  create_pthread_pool ();
}

/*
*thread_manager:code exec in manager thread. 
*               block on task_queue_head->cond when no task come.
*               block on pthread_queue_idle->cond when no idle thread 
*ptr:no used ,in order to avoid warning.
*return :nothing.
*/ 

{  
    while (1)
  {
    THREAD_NODE * temp_thread = NULL;     
    TASK_NODE * temp_task = NULL;      
        /*
         *get a new task, and modify the task_queue.
         *if no task block om task_queue_head->cond.
         */ 
    pthread_mutex_lock (&task_queue_head->mutex);      
    if (task_queue_head->number == 0)        
        pthread_cond_wait (&task_queue_head->cond,&task_queue_head->mutex);   

    
       temp_task = task_queue_head->head;      
       task_queue_head->head = task_queue_head->head->next;    
    
        pthread_mutex_unlock (&task_queue_head->mutex);
      
        /*
         *get a new idle thread, and modify the idle_queue.
         *if no idle thread, block on pthread_queue_idle->cond.
         */ 
        pthread_mutex_lock (&pthread_queue_idle->mutex);      
        if (pthread_queue_idle->number == 0)    
           pthread_cond_wait (&pthread_queue_idle->cond,&pthread_queue_idle->mutex);  
       
      
        /*if this is the last idle thread ,modiry the head and rear pointor */ 
    if (pthread_queue_idle->head == pthread_queue_idle->rear)
    {
      pthread_queue_idle->head = NULL;
      pthread_queue_idle->rear = NULL;
    }      
     /*if idle thread number>2, get the first one,modify the head pointor  */ 
    else
    {
      pthread_queue_idle->head = pthread_queue_idle->head->next;
      pthread_queue_idle->head->prev = NULL;
    }



      
   /*modify the  task attribute. */ 
    pthread_mutex_lock (&temp_task->mutex);
    temp_task->tid = temp_thread->tid;
    temp_task->next = NULL;
    temp_task->flag = 1;
    pthread_mutex_unlock (&temp_task->mutex);   
    
        /*modify the idle thread attribute. */ 
    pthread_mutex_lock (&temp_thread->mutex);
    temp_thread->flag = 1;
    temp_thread->work = temp_task;
    temp_thread->next = NULL;
    temp_thread->prev = NULL;
   pthread_mutex_unlock (&temp_thread->mutex);     

   
        /*add the thread assinged task to the busy queue. */ 
    pthread_mutex_lock (&pthread_queue_busy->mutex);      
        /*if this is the first one in busy queue */ 
    if (pthread_queue_busy->head == NULL)        
    {
       pthread_queue_busy->head = temp_thread;          
       pthread_queue_busy->rear = temp_thread;          
       temp_thread->prev = temp_thread->next = NULL;        
    }
    else        
    {          
            /*insert in thre front of the queue */ 
      pthread_queue_busy->head->prev = temp_thread;          
      temp_thread->prev = NULL;          
      temp_thread->next = pthread_queue_busy->head;      
      pthread_queue_busy->head = temp_thread;  
      pthread_queue_busy->number++;    
    }
    pthread_mutex_unlock (&pthread_queue_busy->mutex); 
    
    
    /*signal the child thread to exec the work */ 
    pthread_cond_signal (&temp_thread->cond);
  }

/*
*code to process the new client in every chilld pthead.
*ptr: the fd come from listen thread that can communicate to the client.
*return:nothing. void * only used to avoid waring.
*/
prcoess_client (void *ptr) 
{  
    int net_fd;  
    net_fd = atoi ((char *) ptr);

  

    /*get the command mesg from client */ 
  if (-1 == recv (net_fd, &client_info, sizeof (client_info), 0))    
  {      
    printf ("recv msg error\n");      
    close (net_fd);
    goto clean;    
  /* if the client requre the attribute of one file. */
  if (client_info.flag == 1)    
  {      
    {          
       goto clean;       
      
      
        /*send info of the file */ 
        if (-1 == send (net_fd, msgbuf, strlen (msgbuf) + 1, 0))
        {
              printf ("send msg error\n");
              close (net_fd);
        	  goto clean;
        }
    	
        close (net_fd);      
        return ;    
    }
  else    
  {
    int local_begin = ntohl (client_info.local_begin);  /* the content begining location. */    
    int length = ntohl (client_info.length);            /* the length of the content. */
    int file_fd; /* open the src file and get the real content. */ 
    if (-1 == (file_fd = open (client_info.buf, O_RDONLY)))        
    {          
        printf ("open file %s error\n", client_info.buf);          
        close (net_fd);
        goto clean;	  
    }   
	/*seek the read local to the real location. */
       lseek (file_fd, local_begin, SEEK_SET);      
    
       int ret;    
    do        
    {          
    char buf[1024];    
      memset (buf, '\0', 1024);          
	  /*read 1024bytes from file everytome, if the last one,read the real length. */
	  if (need_send < 1024)     
     ret = read (file_fd, buf, need_send);   
      else            
        ret = read (file_fd, buf, 1024);      
      if (ret == -1)            
      {              
      printf ("read file %s error\n", client_info.buf);          
      
        close (net_fd);              
      close (file_fd);              
        return ;            
        }
      
      /*send the data to client. */	  
     if (-1 == send (net_fd, buf, ret, 0))
        
      {              
            printf ("send file %s error\n", client_info.buf);              
            close (net_fd);              
            close (file_fd);              
            return;            
            }        
            } 
    while (ret > 0);    
    	  
            close (file_fd);      

        }
  return ;
  
clean:
  sys_clean();

/*
*task_manager: get new task and add to the tail of the task_link.
*ptr: no used. just avoid warning.
*return:nothing.
*/ 

task_manager (void *ptr) 
{
    int listen_fd; 
   if (-1 == (listen_fd = socket (AF_INET, SOCK_STREAM, 0)))    
   {      
            perror ("socket");      
            goto clean;   
   }

    struct ifreq ifr;
  
  
    {     
        perror ("ioctl");      
        goto clean;
    }
  
  
     myaddr.sin_port = htons (PORT);
     myaddr.sin_addr.s_addr =
      ((struct sockaddr_in *) &(ifr.ifr_addr))->sin_addr.s_addr;

  {      
    goto clean;   
  {      
    goto clean;   
 
    /*i is the id of the task */ 
  int i;  
  {      
  int newfd;      
  struct sockaddr_in client;      
  socklen_t len = sizeof (client);
    
if (-1 ==(newfd = accept (listen_fd, (struct sockaddr *) &client, &len)))        
  {  
      perror ("accept");
      goto clean;        
   }    

     TASK_NODE * temp = NULL;      
     //����������
     TASK_NODE * newtask = (TASK_NODE *) malloc (sizeof (TASK_NODE));     
      
    {          
        printf ("malloc error");       
        
     }
        /*
         *initial the attribute of the task.
         *because this task havn't add to system,so,no need lock the mutex.
         */ 
         
        newtask->arg = (void *) malloc (128);
      
        sprintf (newtask->arg, "%d", newfd);   
      
      
        newtask->work_id = i;     
        newtask->next = NULL;  
    pthread_mutex_init (&newtask->mutex, NULL);      

    //�����ú������������������
        /*add new task to task_link */ 
    pthread_mutex_lock (&task_queue_head->mutex);      
        /*find the tail of the task link and add the new one to tail */ 
    temp = task_queue_head->head;
      
    {          
        task_queue_head->head = newtask;        
    }      
    else        
    {          
        while (temp->next != NULL)            
        temp = temp->next;  
        
      }      
      task_queue_head->number++;   
      pthread_mutex_unlock (&task_queue_head->mutex); 

     /*signal the manager thread , no task coming */ 
      pthread_cond_signal (&task_queue_head->cond);    
   }
  
  return ;
  
clean:  
  sys_clean();

/*
*monitor: get the system info 
*ptr: not used ,only to avoid warning for pthread_create
*return: nothing.
*/ 
void * monitor (void *ptr) 
{  
    /*in order to prevent warning. */ 
  ptr = ptr;  
  THREAD_NODE * temp_thread = NULL; 
 
  {      
    pthread_mutex_lock (&pthread_queue_busy->mutex);      
        /*output the busy thread works one by one */ 
    temp_thread = pthread_queue_busy->head;
    printf ("\n*******************************\n");      
    while (temp_thread)        
    {          
        printf ("thread %ld is  execute work_number %d\n",                   \
        temp_thread->tid, temp_thread->work->work_id);        
        temp_thread = temp_thread->next;        
    
    
    
    }  
  
}

/*
*sys_clean: clean the system . 
*this function code need to do to make it more stronger.
*/
sys_clean (void) 
{
  printf("the system exit abnormally\n");  