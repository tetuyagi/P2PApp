/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[220];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "sendRequest"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "data"
QT_MOC_LITERAL(4, 29, 4), // "port"
QT_MOC_LITERAL(5, 34, 12), // "QHostAddress"
QT_MOC_LITERAL(6, 47, 7), // "address"
QT_MOC_LITERAL(7, 55, 17), // "sendSignalEmitter"
QT_MOC_LITERAL(8, 73, 15), // "onImageCaptured"
QT_MOC_LITERAL(9, 89, 2), // "id"
QT_MOC_LITERAL(10, 92, 5), // "image"
QT_MOC_LITERAL(11, 98, 9), // "showImage"
QT_MOC_LITERAL(12, 108, 9), // "playSound"
QT_MOC_LITERAL(13, 118, 19), // "processReceivedData"
QT_MOC_LITERAL(14, 138, 9), // "byteArray"
QT_MOC_LITERAL(15, 148, 11), // "encodeImage"
QT_MOC_LITERAL(16, 160, 11), // "const char*"
QT_MOC_LITERAL(17, 172, 6), // "format"
QT_MOC_LITERAL(18, 179, 11), // "decodeImage"
QT_MOC_LITERAL(19, 191, 6), // "update"
QT_MOC_LITERAL(20, 198, 6), // "onPlay"
QT_MOC_LITERAL(21, 205, 7), // "checked"
QT_MOC_LITERAL(22, 213, 6) // "onSave"

    },
    "MainWindow\0sendRequest\0\0data\0port\0"
    "QHostAddress\0address\0sendSignalEmitter\0"
    "onImageCaptured\0id\0image\0showImage\0"
    "playSound\0processReceivedData\0byteArray\0"
    "encodeImage\0const char*\0format\0"
    "decodeImage\0update\0onPlay\0checked\0"
    "onSave"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   76,    2, 0x08 /* Private */,
       8,    2,   77,    2, 0x08 /* Private */,
      11,    1,   82,    2, 0x08 /* Private */,
      12,    1,   85,    2, 0x08 /* Private */,
      13,    1,   88,    2, 0x08 /* Private */,
      15,    2,   91,    2, 0x08 /* Private */,
      18,    2,   96,    2, 0x08 /* Private */,
      19,    0,  101,    2, 0x08 /* Private */,
      20,    1,  102,    2, 0x08 /* Private */,
      22,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray, QMetaType::Short, 0x80000000 | 5,    3,    4,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QImage,    9,   10,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::QByteArray,   14,
    QMetaType::QByteArray, QMetaType::QImage, 0x80000000 | 16,   10,   17,
    QMetaType::QImage, QMetaType::QByteArray, 0x80000000 | 16,   14,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::Bool,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendRequest((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< qint16(*)>(_a[2])),(*reinterpret_cast< QHostAddress(*)>(_a[3]))); break;
        case 1: _t->sendSignalEmitter(); break;
        case 2: _t->onImageCaptured((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 3: _t->showImage((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 4: _t->playSound((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 5: _t->processReceivedData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: { QByteArray _r = _t->encodeImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 7: { QImage _r = _t->decodeImage((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = _r; }  break;
        case 8: _t->update(); break;
        case 9: _t->onPlay((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onSave((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QByteArray , qint16 , QHostAddress );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendRequest)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendRequest(QByteArray _t1, qint16 _t2, QHostAddress _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
