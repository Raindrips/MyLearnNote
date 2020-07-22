## ICMP Tunnel 

* ICMP Tunnel Des

  ```JS
  1.将所有的流量包装在icmp协议中，实现所有流量的隐蔽传输，绕过计费和防火墙系统
  2.使用原始套接字，编写基于ICMP ECHO协议的封装流量
  ```

* Usage

  ```sh
  Server:
      echo 1 > /proc/sys/net/ipv4/icmp_echo_ignore_all 
      ./icmptunnel -s &
      ifconfig tun0 10.0.0.1 netmask 255.255.255.0
   Client:
   	echo 1 > /proc/sys/net/ipv4/icmp_echo_ignore_all 
   	./icmptunnel 192.168.199.183 &
   	ifconfig tun0 10.0.0.2 netmask 255.255.255.0
   	tcpdump -w /tmp/test.pcap
  ```

* Code

  ```JS
  1. 创建虚拟tun网卡，利用linux内核taP/tun 虚拟网卡机制，创建虚拟旁路网卡
  2. 创建与真实网卡的原始套接字 sockfd1
  3. 创建与虚拟网卡的原始套接字 sockfd2
  4. 实现sockfd1 sockfd2 的流量收发  ---select
  5. 将从sockfd2读出的数据，封装icmp协议，并且写入sockfd1
  6. 将从sockfd1读出的数据，解除icmp协议，并且写入sockfd2 
  7. 创建tunnel协议
  ```

  







[sudo] ./icmptunnel -s 10.0.1.1

[sudo] ./icmptunnel -c <server>