#ifndef DLLDEMO_H
#define DLLDEMO_H

#include "dlldemo_global.h"

class DLLDEMOSHARED_EXPORT DllDemo
{

public:
    DllDemo();
    QString  strAdd(const  QString  &str1,  const  QString  &str2);
    static  int  numberAdd(const  int  &  number1,  const  int  &
    number2);
};

#endif // DLLDEMO_H
