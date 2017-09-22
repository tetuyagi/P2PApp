/****************************************************************************
** Meta object code from reading C++ file 'audio.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../audio.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audio.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Audio_t {
    QByteArrayData data[17];
    char stringdata0[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Audio_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Audio_t qt_meta_stringdata_Audio = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Audio"
QT_MOC_LITERAL(1, 6, 4), // "play"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 4), // "save"
QT_MOC_LITERAL(4, 17, 8), // "stopPlay"
QT_MOC_LITERAL(5, 26, 8), // "stopSave"
QT_MOC_LITERAL(6, 35, 6), // "update"
QT_MOC_LITERAL(7, 42, 12), // "getInputData"
QT_MOC_LITERAL(8, 55, 13), // "setOutputData"
QT_MOC_LITERAL(9, 69, 9), // "byteArray"
QT_MOC_LITERAL(10, 79, 16), // "resetInputBuffer"
QT_MOC_LITERAL(11, 96, 17), // "resetOutputBuffer"
QT_MOC_LITERAL(12, 114, 24), // "inputStateChangedHandler"
QT_MOC_LITERAL(13, 139, 13), // "QAudio::State"
QT_MOC_LITERAL(14, 153, 5), // "state"
QT_MOC_LITERAL(15, 159, 25), // "outputStateChangedHandler"
QT_MOC_LITERAL(16, 185, 9) // "onDecoded"

    },
    "Audio\0play\0\0save\0stopPlay\0stopSave\0"
    "update\0getInputData\0setOutputData\0"
    "byteArray\0resetInputBuffer\0resetOutputBuffer\0"
    "inputStateChangedHandler\0QAudio::State\0"
    "state\0outputStateChangedHandler\0"
    "onDecoded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Audio[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    1,   80,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      11,    1,   84,    2, 0x0a /* Public */,
      12,    1,   87,    2, 0x08 /* Private */,
      15,    1,   90,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QByteArray,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::QByteArray,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,

       0        // eod
};

void Audio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Audio *_t = static_cast<Audio *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->save(); break;
        case 2: _t->stopPlay(); break;
        case 3: _t->stopSave(); break;
        case 4: _t->update(); break;
        case 5: { QByteArray _r = _t->getInputData();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 6: _t->setOutputData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: { QByteArray _r = _t->resetInputBuffer();
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = _r; }  break;
        case 8: _t->resetOutputBuffer((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 9: _t->inputStateChangedHandler((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        case 10: _t->outputStateChangedHandler((*reinterpret_cast< QAudio::State(*)>(_a[1]))); break;
        case 11: _t->onDecoded(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudio::State >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudio::State >(); break;
            }
            break;
        }
    }
}

const QMetaObject Audio::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Audio.data,
      qt_meta_data_Audio,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Audio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Audio::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Audio.stringdata0))
        return static_cast<void*>(const_cast< Audio*>(this));
    return QObject::qt_metacast(_clname);
}

int Audio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
