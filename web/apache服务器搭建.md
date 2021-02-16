## apache服务器搭建

windows环境[下载地址](https://www.apachehaus.com/cgi-bin/download.plx)

下载好之后解压,进入解压后的文件目录,修改配置文件`文件目录\conf\httpd.conf`

```ini
# 项目的目录位置
Define SRVROOT "c:/Apache24"

# 服务器目录
ServerRoot "${SRVROOT}"
```

启动http服务,将`index.html`文件放入`文件目录\hdocs`下
```sh
# 启动命令
httpd.exe

# 开机自动运行
httpd.exe -k install

# 卸载开机启动
httpd.exe -k uninstall
```
`Apache24\bin\`

