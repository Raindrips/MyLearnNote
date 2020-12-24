# 输入输出流

## 标准IO

标准IO:
stdin 标准输入流 一般是键盘 在开发板中 是串口
stdout 标准输出流 一般指的是屏幕或者终端 在开发板中还是串口
stderr 标准出错流 大多数和输出流是同一个文件

```c++
#include <stdio.h>
```

错误存放在errno中
	

注意：追加时 本质上有两个光标 一个是读光标 一个是写光标 ,读光标定位在文件开头 写光标定位在文件末尾

```c++
//	path 路径
// 	mode 模式权限		r 以只读的方式打开 
//						w 以只写的方式打开 如果文件不存在则创建 如果文件存在则清空并打开
//						r+ 表示可读可写 文件不存在则报错
//						w+ 表示可读可写 文件不存在则创建 存在则清空 
//						a 追加方式打开 只写 在文件末尾添加数据,文件不存在则创建
//						a+追加方式打开 可读可写
//	return 成功返回一个文件指针File 失败返回NULL
FILE *fopen(const char *path, const char *mode);
```

```c++
//	fp 文件指针
//	return 成功返回0 失败返回-1	
//fgetc 是一个函数 getc是一个宏定义
int fclose(FILE *fp);	


//从文件读取一个指针
int fgetc(FILE *stream);
int getc(FILE *stream);
//stream： 文件指针
//return 成功返回读取到字符的ASCII
	
int fputc(int c, FILE *stream);
int putc(int c, FILE *stream);
//c 表示要写入字符的ASCII
//	stream: 文件指针
//	return 成功返回写入的值 失败返回-1

//从文件写入字符串
int fputs(const char *s, FILE *stream); //不会自动换行
//	s 要写入的字符串
//	stream: 文件指针
	
//获取一个字符串
char *fgets(char *s, int size, FILE *stream);
//	s 要存储的数据的数组
//	size 数组长度
//	stream 文件指针
//	return 返回读取到字符串存储的首地址 
		
//功能： 从指定的流中读取 单位为size 的 nmemb个数据存储到ptr指向的区域		
size_t fread(void *ptr, size_t size, size_t nmemb,
			FILE *stream);
//功能：将ptr指向区域的 单位为size 的nmemb个数据写入到指定的流中		
size_t fwrite(const void *ptr, size_t size, size_t nmemb,
			FILE *stream);
//	ptr 存储区域的地址		
//	size: 读写的大小
//	nmemb: 读写的个数 
//	stream 流 
//	return 成功返回 写入的字符个数或者读取到的字符个数 失败返回-1 
```


```c++
int fseek(FILE *stream, long offset, int whence);
stream: 文件指针 
  偏移量
whence 从哪里开始偏移
	SEEK_SET 从头开始偏移  此时offset只能为正数 
	SEEK_END 从尾巴开始偏移 此时offset只能为正数
	SEKK_CUR 从当前位置开始偏移 此时可正可负  向后是正 向前是负 

//用来获取当前光标位置与文件头的距离
long ftell(FILE *stream);
	
//将光标偏移到文件的起始位置
void rewind(FILE *stream);

//从文件中格式输入	
int fscanf(FILE *stream, const char *format, ...);

//格式化输出文件流内容
int fprintf(FILE *stream, const char *format, ...)
		
//格式输出比sprintf多了长度参数 
int snprintf(char *str, size_t size, const char *format, ...);
	

```

## LinuxIO库

```cpp
//文件IO(unix)		
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

//打开文件
int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```



```c++
pathname: 表示带路径的文件名
flags: 打开标志
	O_RDONLY //只读  
	O_WRONLY //只写
	O_RDWR	// 可读可
	//以上为必填,以下为可选
	O_APPEND //追加方式 打开时有两个光标 读在文件头 写在文件尾 
	O_CREAT	 //创建方式 如果文件存在则打开 如果文件不存在则创建 
	O_EXCL   //该标志一般与O_CREAT搭配使用 如果存在就会报错 如果不存在则创建 
	O_NONBLOCK:以非阻塞的方式打开 
	O_TRUNC: 截断标志 如果文件存在并且是一个普通文件 且打开的方式是O_RDWR 
mode:权限(参加Linux)
return 成功返回0 失败返回-1 
```



```c++
//关闭该文件
int close(int fd);		
//从文件描述符所表示的文件中 读取 count 个字节的数据到 buf指向的区域
size_t read(int fd, void *buf, size_t count);
	fd: 文件描述符
	buf: 存储区域的首地址
	count：读取的字节数
  return 成功读取到的字节长度
				 失败返回-1 

//写入文件				 
ssize_t write(int fd, const void *buf, size_t count);	
	fd: 需要写入的文件描述符 
	buf: 写入数据的首地址 
	count: 写入数据的字节数 
	return 成功返回成功写入的字节数 失败返回 -1 	

//删除一个普通文件或者空目录	
int remove(const char *pathname);
	return 成功返回0 失败返回-1 
	
//通过路径获取文件属性到结构体中 lstat可以获取到软连接.fstat从描述符里获取
int stat(const char *path, struct stat *buf);
int lstat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);

struct stat {
		dev_t     st_dev;     /* ID of device containing file  文件的设备编号 如果这是一个设备文件就对应一个编号*/
		ino_t     st_ino;     /* inode number i节点号 */
		mode_t    st_mode;    /* protection  文件的类型以及可以操作的权限 权限指的是创建时的权限
				文件有那几个类型： 普通文件 目录文件 连接文件 字符设备文件 套接字文件 管道文件 块设备文件	*/
		nlink_t   st_nlink;   /* number of hard links 硬链接的数目 在文件创建时数目为1	 */
		uid_t     st_uid;     /* user ID of owner  文件所有者用后标识码 */
		gid_t     st_gid;     /* group ID of owner 文件所有者所在组的标识码 */
		dev_t     st_rdev;    /* device ID (if special file) 若是一个装置设备文件 设备编号  */
		off_t     st_size;    /* total size, in bytes 文件大小 字节表示 */ 
		blksize_t st_blksize; /* blocksize for filesystem I/O 文件系统IO缓冲区的大小 */ 
		blkcnt_t  st_blocks;  /* number of 512B blocks allocated 占用文件区块的个数 以512字节计 */ 
		time_t    st_atime;   /* time of last access  最后一次被存取或者指向的时间 */
		time_t    st_mtime;   /* time of last modification 最后一次修改的时间  */
		time_t    st_ctime;   /* time of last status change 最后一次状态改变的时间 // 一般只有修改用户 类型才会被修改 */
	 };
	 
文件的判断:使用宏定义解析 
	S_ISREG(m)  is it a regular file? 普通文件判断
	S_ISDIR(m)  directory? 目录文件判断
	S_ISCHR(m)  character device? 字符设备文件判断
	S_ISBLK(m)  block device? 块设备文件判断
	S_ISFIFO(m) FIFO (named pipe)? 管道文件判断
	S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.) 连接文件判断
	S_ISSOCK(m) socket?  (Not in POSIX.1-1996.) 套接字文件判断 

//创建一个目录
int mkdir(const char *pathname, mode_t mode);

//删除一个目录
int rmdir(const char *pathname);

//打开一个目录
DIR *opendir(const char *name);

//关闭目录
int closedir(DIR *dirp);

//读取一个目录
struct dirent *readdir(DIR *dirp);

struct dirent {
	ino_t          d_ino;   /* inode number */ i结点号
	off_t          d_off;   /* not an offset; see NOTES */ 在目录文件中的偏移
	unsigned short d_reclen;/* length of this record */文件名的长度
	unsigned char  d_type;  /* type of file; not supported by all filesystem types */文件类型										   
	char           d_name[256]; /* filename */ 文件名
};

#include <sys/mman.h>
//创建映射
void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
	addr:分配空间NULL则自动分配
	length 映射的起始地址,按字节计
	prot 映射内存区域的权限
		PROT_READ 可读
		PROT_WRITE 可写
		PROT_EXEL 可执行 
		PROT_NONE 无权限 
	flags: 映射的标志 有两个取值
		MAP_SHARED： 共享的 映射区域对于其他进程可见 内存操作可以直接影响到文件 
		MAP_PRIVATE：私有的 对与其他进程不可见 内存操作无法直接影响到文件
	fd: 文件描述符 表示要映射的文件
	offset:偏移量 
//释放映射		  
int munmap(void *addr, size_t length);
```

