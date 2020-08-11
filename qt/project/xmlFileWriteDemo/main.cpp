#include <QCoreApplication>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QTextCodec>
#include <QFile>
#include <QFileInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //文件操作
    QFile file("./writeFile.xml");
    //打开文件
    file.open(QFile::WriteOnly | QFile::Truncate);

    //xmlStreamWrite类
    QXmlStreamWriter stream(&file);

    stream.setCodec(QTextCodec::codecForName("utf-8"));
    stream.setAutoFormatting(true);           //排版格式
    stream.writeStartDocument();
    stream.writeStartElement("teachers");

    /*老王*/
    stream.writeStartElement("teacher");
    stream.writeAttribute("id", "01");
    stream.writeAttribute("time", "23:30");  //子时 练习
    stream.writeTextElement("name", "老王");
    stream.writeTextElement("book", "葵花宝典");
    stream.writeEndElement();

    /* robort */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id", "02");
    stream.writeAttribute("time", "04:00");
    stream.writeTextElement("name", "robort");
    stream.writeTextElement("book", "金瓶梅");
    stream.writeEndElement();

    /* 夏七 */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id", "03");
    stream.writeAttribute("time", "19:00");
    stream.writeTextElement("name", "夏七");
    stream.writeTextElement("book", "红楼梦");
    stream.writeEndElement();


    stream.writeEndElement();
    stream.writeEndDocument();
    file.close();
    return a.exec();
}
