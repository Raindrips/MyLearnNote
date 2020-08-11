#  Linux 原始套接字
## 问题
 实现路由器，都需要什么网络协议
### 
* rip 
* ARP
* DHCP
* PPPOE
* EIGRP 
* VPN

## 原始套接字目标
* 直接操作各层数据
* IP/ICMP/IGMP.....协议的实现
* 网络诊断，测试程序(Poc 漏洞利用工具)

## 原始套接字流程
* 创建 
```
socket(AF_INET, SOCK_RAW, IPPROTO_XXXX)
```
> IPPROTO_XXXX 是需要创建的协议类型
![IPPROTO_XXXX](https://i.imgur.com/vOVopsI.jpg)

* 开启修改选项 
> 开启可修改头选项 选择是否要设置IP_HDRINCL
* 实现协议

## 套接字选项

* setsockopt 设置选项值
```
int setsockopt ( SOCKET s, int level, int optname, const char FAR *optval, int  optlen } ; 
```
* getsockopt 获取选项值
* 
```
int getsockopt (SOCKET s, int level , int optname , char FAR * optval , int FAR * optlen ）
```


#### 作业
收集所有socket level optname

+ SOL_SOCKET 
  SO_BROADCAST:布尔型（BOOL)->用于允许／禁止发送广播报文。
  SO_RCVTIMEO:struct timeval 结构型，用于设置数据接收超时值。
  SO_ SNDTIMEO:struct timeval 结构型,用于设置数据发送超时值。
+ IPPROTO_IP
  IP_HDRINCL:布尔型，仅适用于原始套接口,如果应用程序希望能接收IP 层及IP 层以上的所有数据或者自行组装包含IP 层在内的报文，那么可以设置该选项为TRUE 。

+ IPPROTO_IPV6
+ IPPROTO_RM
+ IPPROTO_TCP
+ IPPROTO_UDP
+ NSPROTO_lPX
+ SOL_APPLETALK
+ SOL_IRLMP 

### SYN FLOOD DOS 
* 协议字段
* 协议流程
![TCP协议](https://i.imgur.com/XUfnlux.jpg)
![](https://i.imgur.com/rTn4x1b.jpg)