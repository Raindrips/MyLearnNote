```
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
//创建通信节点
int socket(int domain, int type, int protocol);
	domain:协议域/族
				AF_UNIX, AF_LOCAL   本地通信
				AF_INET             IPv4 Internet protocols          
				AF_INET6            IPv6 Internet protocols    
				...      
	type 	类型,即数据传输方式
		SOCK_STREAM      有序的, 可靠的, 双向的, 基于连接的，字节流.  TCP
		SOCK_DGRAM       数据报(包) (无连接, 不可靠 ，最大长度固定).	UDP
		protocol 通信协议
			指实现数据传输方式的协议的编号，从0开始算，
			0表示默认协议
			SOCK_STREAM的默认协议是TCP
			SOCK_DGRAM的默认协议是UDP
	成功返回套接字描述符
	失败返回-1，errno被设置
		
struct sockaddr_in {
	 sa_family_t    sin_family; /* 协议族: AF_INET */
	 in_port_t      sin_port;   /* 网络字节序的端口 */
	 struct in_addr sin_addr;   /* IP地址结构 */
};

/* Internet address. */
struct in_addr {
	 uint32_t       s_addr;     /* 网络字节序的IP地址 */
};

#include <arpa/inet.h>
	//把主机字节序转成网络字节序
	uint32_t htonl(uint32_t hostlong);
	uint16_t htons(uint16_t hostshort);
	uint32_t ntohl(uint32_t netlong);
	uint16_t ntohs(uint16_t netshort);

//点分十进制的IP与整数IP之间的转换
in_addr_t inet_addr(const char *cp);
char *inet_ntoa(struct in_addr in);		

//把通信地址绑定到套接字
int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
	sockfd	套接字描述符 socket()成功的返回值
	addr 	通信地址结构体指针，任何类型的地址结构都必须转换此类型
	addrlen 地址结构的长度，sizeof()计算即可
	成功 0 失败-1
	
//监听指定的套接字 监听完成后，套接字转为被动状态，只能提供服务，不能再发出请求了。称为监听套接字或服务套接字
int listen(int sockfd, int backlog);
	sockfd 	套接字描述符 socket()成功的返回值
	backlog 等待队列 的最大长度
	成功 0 失败-1
	
//接收套接字上的连接
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);	
	sockfd 	套接字描述符 socket()成功的返回值
	addr 	结构体指针,保存连接来的客户端的地址
	addrlen socklen_t类型的指针,保存客户端地址的长度。必须初始化
	成功返回客户端套接字描述符，称为连接套接字，用于服务器与客户端通信.
	失败返回-1
	
//用于客户连接服务器	
int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);	
	sockfd 	套接字描述符 socket()成功的返回值
	addr    服务器的地址
	addrlen 服务器的地址结构的长度
	成功 0 失败-1
	
套接字选项:
//内核提供两个接口，用来读取和设置套接选项
int getsockopt(int sockfd, int level, int optname,void *optval, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen);
sockfd 	套接字描述符
	level  	层次名
					SOL_SOCKET
	optname 选项名
					SO_REUSEADDR
	optval	选项的值
				(默认值为0 表示不允许 1:就表示允许重用)
	optlen 	选项的值的长度
	成功 0 失败-1

IO复用服务器
#include <sys/select.h>

//监控三个描述符集合，在指定的时间内，如果监控的描述符准备就绪，select正常返回，如果在指定时间内没有任何描述符准备就绪，select超时返回
int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
	nfds 		监控的最大描述符+1
	readfds 	对读操作感兴趣的文件描述符集合
	writefds	对写操作感兴趣的文件描述符集合
	exceptfds	对异常操作感兴趣的文件描述符集合
	timeout		超时时间
	struct timeval {
			long    tv_sec;         /* 秒 */
			long    tv_usec;        /* 微秒 */
	};
	返回文件描述符的个数	
	出错返回-1
	超时返回0
	
	void FD_CLR(int fd, fd_set *set);//把指定的描述符从指定的集合中移除
	int  FD_ISSET(int fd, fd_set *set);//判断指定的描述符是否在指定的集合中
	void FD_SET(int fd, fd_set *set);//把指定的描述符加入到指令的集合中
	void FD_ZERO(fd_set *set);//把指定的集合全部置0，即初始化
	
//创建epoll实例(空间)
int epoll_create(int size);	

//控制epoll空间中的描述符
int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);

	epfd 	epoll_create成功的返回值，即epoll描述符
	op		操作方式
			EPOLL_CTL_ADD	添加
			EPOLL_CTL_DEL	删除
			EPOLL_CTL_MOD	修改
	fd  	要操纵的具体的文件描述符
	event   事件
	typedef union epoll_data {
			 void        *ptr;
			 int          fd;
			 uint32_t     u32;
			 uint64_t     u64;
	 }epoll_data_t;
	 struct epoll_event {
			 uint32_t     events;      /* Epoll 事件(EPOLLIN   EPOLLOUT  EPOLLERR ...) */
			 epoll_data_t data;        /* 联合体/共用体  需要监控的描述符 */
	 };
	成功0 失败-1
	
//等待epoll空间中描述符发生IO事件
int epoll_wait(int epfd, struct epoll_event *events,int maxevents, int timeout);
	epfd 	epoll_create成功的返回值，即epoll描述符
	events 结构体指针，缓冲区首地址，用于保存 准备就绪的文件描述符，
	maxevents  缓冲区的大小，一般设置为 与需要监控的描述符的总数 相同
	timeout		超时时间，单位ms
	返回准备就绪的文件描述个数
	出错-1 超时0       

//用来发送数据报(UDP)
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
					const struct sockaddr *dest_addr, socklen_t addrlen);
		sockfd 套接字描述符
		buf    数据缓冲区首地址，表示数据从哪里来
		len 	要发送的数据的长度，不能超过缓冲区的最大值
		flags  发送标志 ，阻塞或不阻塞
				阻塞			0
				不阻塞		MSG_DONTWAIT
		dest_addr 目标地址，指数据发送到哪里去
		addrlen   目标地址结构的长度
		成功返回实际发送的字节数
		失败返回-1

//用来接收数据报(UDP)
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
	sockfd 套接字描述符
	buf    数据缓冲区首地址，表示数据保存到哪里去
	len 	要接收的数据的长度，不能超过缓冲区的最大值
	flags  接收标志,阻塞或不阻塞
		阻塞			0
		不阻塞		MSG_DONTWAIT
	src_addr  源地址，指数据从哪里发送来的
	addrlen   源地址结构的长度
	成功返回实际接受的字节数
	失败返回-1
	
//发送数据(TCP)
/*flag:  发送标志,阻塞或不阻塞
	阻塞			0
	不阻塞		MSG_DONTWAIT
*/
send(int sock,void* buf,size_t size,int flag)

	
//接收数据(TCP)
/*flag:  接收标志,阻塞或不阻塞
	阻塞			0
	不阻塞		MSG_DONTWAIT
*/
recv(int sock,void* buf,size_t size,int flag)
```

```c
//初始化套接字库
WSAStartup(WORD wVersionRequested,LPWSADATA IpWASData);

//创建套接字
SOCKET socket(int af,int type,int protocol);

/*
 *	
 */
bind(SOCKET s,struct sockaddr FAR*name,namelen)


/*
 *
 *
 */
liten(SOCKET s,int backlog);

SOCKET accept(SOCKET s,struct sockaddr FAR* *addr,int FAR *addrlen);

closesocket();

connect();

htons()
```

