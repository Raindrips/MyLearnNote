#include <QCoreApplication>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFile file("./testWrite.xml");
    if (!file.open(QFile::WriteOnly | QFile::Text))  //创建方式写
    {
        qDebug() << "Error: cannot open file";
    }

    QXmlStreamWriter stream(&file);  //主播好流

    stream.setCodec(QTextCodec::codecForName("utf-8")); //设置为utf-8编码
    stream.setAutoFormatting(true);
    stream.writeStartDocument(); //文档开始
    stream.writeStartElement("teachers"); //teachers

    /* 老王 */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id", "01");             //工号
    stream.writeAttribute("time", "12:00");
    stream.writeTextElement("name", QString::fromLocal8Bit("老王"));
    stream.writeTextElement("book", QString::fromLocal8Bit("金瓶梅"));
    stream.writeEndElement();

    /* robort */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id", "02");
    stream.writeAttribute("time", "04:00");
    stream.writeTextElement("name", "robort");
    stream.writeTextElement("book", QString::fromLocal8Bit("葵花宝典"));
    stream.writeEndElement();

    /* 夏七 */
    stream.writeStartElement("teacher");
    stream.writeAttribute("id", "03");
    stream.writeAttribute("time", "19:00");
    stream.writeTextElement("name", QString::fromLocal8Bit("夏七"));
    stream.writeTextElement("book", QString::fromLocal8Bit("红楼梦"));
    stream.writeEndElement();

    stream.writeEndElement();
    stream.writeEndDocument();
    file.close();

    return a.exec();
}
