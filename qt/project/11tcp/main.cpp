#include <QCoreApplication>
#include <QSemaphore>
#include <QThread>
#include <QtDebug>

//生产者   信号量
static const int Max_SIZE=10;
int buf[Max_SIZE];
QSemaphore wk(10);  //信号量 仓库的容量
//9   1    8  2
//消费者   信号量
QSemaphore us(0);

class worker:public QThread
{
public:
    worker(){}
    void run(){
        for(int i=0;i<Max_SIZE;i++){
            //生产者获取1个信号量，调用一次，信号量数少1
            wk.acquire();
            buf[i]=i;   //
            //消费者释放1个信号量，调用一次，信号量数加1
            us.release();

        }
        //        qDebug()<<"wk0"<<wk.available();
        //        qDebug()<<"us0"<<us.available();
    }
};

class user:public QThread{
public:

    user(){}
    void run(){
        for(int i=0;i<Max_SIZE;i++){
            //消费者获取1个信号量，调用一次，信号量数少1
            us.acquire();
            qDebug()<<buf[i];
            //生产者释放1个信号量，调用一次，信号量数加1
            wk.release();
            qDebug()<<"wk1"<<wk.available();
            qDebug()<<"us1"<<us.available();

        }
        //        qDebug()<<"wk1"<<wk.available();
        //        qDebug()<<"us1"<<us.available();
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    worker wk;
    user us;

    //启动生产者和消费者
    wk.start();
    us.start();

    //等待生产者和消费者各自执行完毕后自动退出
    wk.wait();
    us.wait();
    return a.exec();
}
