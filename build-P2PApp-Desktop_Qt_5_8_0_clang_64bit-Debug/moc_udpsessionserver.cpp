/****************************************************************************
** Meta object code from reading C++ file 'udpsessionserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../udpsessionserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'udpsessionserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UdpSessionServer_t {
    QByteArrayData data[14];
    char stringdata0[157];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UdpSessionServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UdpSessionServer_t qt_meta_stringdata_UdpSessionServer = {
    {
QT_MOC_LITERAL(0, 0, 16), // "UdpSessionServer"
QT_MOC_LITERAL(1, 17, 12), // "receivedData"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "byteArray"
QT_MOC_LITERAL(4, 41, 12), // "sendDatagram"
QT_MOC_LITERAL(5, 54, 4), // "data"
QT_MOC_LITERAL(6, 59, 4), // "port"
QT_MOC_LITERAL(7, 64, 12), // "QHostAddress"
QT_MOC_LITERAL(8, 77, 7), // "address"
QT_MOC_LITERAL(9, 85, 6), // "update"
QT_MOC_LITERAL(10, 92, 19), // "readPendingDatagram"
QT_MOC_LITERAL(11, 112, 18), // "processTheDatagram"
QT_MOC_LITERAL(12, 131, 16), // "QNetworkDatagram"
QT_MOC_LITERAL(13, 148, 8) // "datagram"

    },
    "UdpSessionServer\0receivedData\0\0byteArray\0"
    "sendDatagram\0data\0port\0QHostAddress\0"
    "address\0update\0readPendingDatagram\0"
    "processTheDatagram\0QNetworkDatagram\0"
    "datagram"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UdpSessionServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    3,   42,    2, 0x0a /* Public */,
       9,    0,   49,    2, 0x0a /* Public */,
      10,    0,   50,    2, 0x08 /* Private */,
      11,    1,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Short, 0x80000000 | 7,    5,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

       0        // eod
};

void UdpSessionServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UdpSessionServer *_t = static_cast<UdpSessionServer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receivedData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->sendDatagram((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2])),(*reinterpret_cast< QHostAddress(*)>(_a[3]))); break;
        case 2: _t->update(); break;
        case 3: _t->readPendingDatagram(); break;
        case 4: _t->processTheDatagram((*reinterpret_cast< QNetworkDatagram(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkDatagram >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UdpSessionServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UdpSessionServer::receivedData)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject UdpSessionServer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UdpSessionServer.data,
      qt_meta_data_UdpSessionServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UdpSessionServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UdpSessionServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UdpSessionServer.stringdata0))
        return static_cast<void*>(const_cast< UdpSessionServer*>(this));
    return QObject::qt_metacast(_clname);
}

int UdpSessionServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UdpSessionServer::receivedData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
