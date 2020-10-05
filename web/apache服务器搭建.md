## apache服务器搭建

[下载地址](https://www.apachelounge.com/download/)

下载好之后解压,进入解压后的文件目录,修改配置文件`文件目录\conf\httpd.conf`

```ini
# 项目的目录位置
Define SRVROOT "c:/Apache24"

# 服务器目录
ServerRoot "${SRVROOT}"
```

启动http服务
```sh
http 

# 开机自动运行
httpd.exe -k install

# 卸载开机启动
httpd.exe -k uninstall
```
`Apache24\bin\`