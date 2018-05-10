/****************************************************************************
** Meta object code from reading C++ file 'network_pannel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../network_pannel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network_pannel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetWork_t {
    QByteArrayData data[15];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetWork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetWork_t qt_meta_stringdata_NetWork = {
    {
QT_MOC_LITERAL(0, 0, 7), // "NetWork"
QT_MOC_LITERAL(1, 8, 16), // "show_result_byid"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "picid"
QT_MOC_LITERAL(4, 32, 5), // "actvi"
QT_MOC_LITERAL(5, 38, 6), // "mytest"
QT_MOC_LITERAL(6, 45, 4), // "text"
QT_MOC_LITERAL(7, 50, 10), // "result_rcv"
QT_MOC_LITERAL(8, 61, 14), // "rcvpic_handler"
QT_MOC_LITERAL(9, 76, 7), // "res_str"
QT_MOC_LITERAL(10, 84, 14), // "rcv_ip_handler"
QT_MOC_LITERAL(11, 99, 5), // "rcvip"
QT_MOC_LITERAL(12, 105, 12), // "SubmitQuerry"
QT_MOC_LITERAL(13, 118, 13), // "QuerryStruct&"
QT_MOC_LITERAL(14, 132, 2) // "QS"

    },
    "NetWork\0show_result_byid\0\0picid\0actvi\0"
    "mytest\0text\0result_rcv\0rcvpic_handler\0"
    "res_str\0rcv_ip_handler\0rcvip\0SubmitQuerry\0"
    "QuerryStruct&\0QS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetWork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   52,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       8,    1,   59,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13,   14,

       0        // eod
};

void NetWork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetWork *_t = static_cast<NetWork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_result_byid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->actvi(); break;
        case 2: _t->mytest((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->result_rcv((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->rcvpic_handler((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->rcv_ip_handler((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->SubmitQuerry((*reinterpret_cast< QuerryStruct(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetWork::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetWork::show_result_byid)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject NetWork::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NetWork.data,
      qt_meta_data_NetWork,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *NetWork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetWork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetWork.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int NetWork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void NetWork::show_result_byid(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_singleclient_t {
    QByteArrayData data[4];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_singleclient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_singleclient_t qt_meta_stringdata_singleclient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "singleclient"
QT_MOC_LITERAL(1, 13, 11), // "resultReady"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20) // "do_StartSingleClient"

    },
    "singleclient\0resultReady\0\0"
    "do_StartSingleClient"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_singleclient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void singleclient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        singleclient *_t = static_cast<singleclient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resultReady((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->do_StartSingleClient(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (singleclient::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&singleclient::resultReady)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject singleclient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_singleclient.data,
      qt_meta_data_singleclient,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *singleclient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *singleclient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_singleclient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int singleclient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void singleclient::resultReady(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_Cthread_controller_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Cthread_controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Cthread_controller_t qt_meta_stringdata_Cthread_controller = {
    {
QT_MOC_LITERAL(0, 0, 18), // "Cthread_controller"
QT_MOC_LITERAL(1, 19, 7), // "operate"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "rcv_ip"
QT_MOC_LITERAL(4, 35, 13) // "handleResults"

    },
    "Cthread_controller\0operate\0\0rcv_ip\0"
    "handleResults"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Cthread_controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void Cthread_controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Cthread_controller *_t = static_cast<Cthread_controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->operate(); break;
        case 1: _t->rcv_ip((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->handleResults((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Cthread_controller::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cthread_controller::operate)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Cthread_controller::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Cthread_controller::rcv_ip)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Cthread_controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Cthread_controller.data,
      qt_meta_data_Cthread_controller,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Cthread_controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Cthread_controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Cthread_controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Cthread_controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Cthread_controller::operate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Cthread_controller::rcv_ip(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
