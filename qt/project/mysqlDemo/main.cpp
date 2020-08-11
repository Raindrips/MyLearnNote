#include <QCoreApplication>
#include <QDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //指定使用什么数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    //连接数据库   跟自己的机器有关系
    {
        db.setHostName("localhost");    //本地数据库 如果是远程的db 这里ipaddress
        db.setPort(3306);               //设置端口
        db.setDatabaseName("db_book");  //使用db_book这个库  sql = USE `db_book`;
        db.setUserName("root");
        db.setPassword("123456");
        if(db.open())
        {
            qDebug()<<"sql open sucess";
        }
        else
        {
            qDebug()<<"open sql failed";
        }
    }

    //执行sql语句
    QSqlQuery query("SELECT * FROM t_book");

    //接住sql返回结构
    while (query.next()) {
        QString str0 = query.value(0).toString();
        QString str1 = query.value(1).toString();
        QString str2 = query.value(2).toString();
        QString str3 = query.value(3).toString();

        qDebug()<<str0 << str1 << str2 << str3;
    }
    return a.exec();
}
