#include "handler.h"

handler::handler(QObject *parent) : QObject(parent)
{

}

handler::~handler()
{

}
handler *handler::hand=new handler;

handler *handler::getInstance(){
    return hand;
}
void handler::addSoure(){
    emit beatMouse();

}
