#ifndef UTILITY_H
#define UTILITY_H

#include <QSysInfo>
#include <QDebug>

class Utility
{
public:
    template<typename T> static void dataToBytes(T number, char* bytes, int index=0){
        int byteSize = sizeof(T);
        int bitSize = byteSize * 8;

        //qDebug() << "size, byteSize :" << size << "," << byteSize;

        if(QSysInfo::ByteOrder == QSysInfo::BigEndian){
            for(int i=0; i<byteSize; ++i){
                T mask = 0xff << (bitSize - 8 * (i + 1));
                //qDebug("mask :%x", mask);
                bytes[index + i] = (number & mask) >> (bitSize - 8 * (i + 1));
            }
        }else{
            for(int i=0; i<byteSize; ++i){
                T mask = 0xff << (bitSize -  8 * (i + 1));
                //qDebug("mask :%x", mask);
                bytes[index + byteSize - (i + 1)] = (number & mask) >> (bitSize - 8 * (i + 1));
                //qDebug("bytes[%d] = %x",(index + byteSize - (i + 1)), bytes[index + byteSize - (i + 1)] );
            }
        }

    }


    template<typename T> static T bytesToData(const char* bytes, int index=0){
        T t = 0;
        int byteSize = sizeof(T);
        int bitSize = byteSize * 8;

        if(QSysInfo::ByteOrder == QSysInfo::BigEndian){
            for(int i=0; i<byteSize; ++i){
                t += (uchar)bytes[index + i] << (bitSize - (i+1)*8);
            }
        }else{
            for(int i=0; i<byteSize; ++i){
                t += (uchar)bytes[index + i] << i*8;
            }
        }

        //qDebug() << "bytesToData =" << t;
        return t;

    }

};

#endif // UTILITY_H
