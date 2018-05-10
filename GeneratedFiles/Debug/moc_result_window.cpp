/****************************************************************************
** Meta object code from reading C++ file 'result_window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../result_window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'result_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_result_window_t {
    QByteArrayData data[9];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_result_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_result_window_t qt_meta_stringdata_result_window = {
    {
QT_MOC_LITERAL(0, 0, 13), // "result_window"
QT_MOC_LITERAL(1, 14, 16), // "show_result_byid"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "picid"
QT_MOC_LITERAL(4, 38, 14), // "button_clicked"
QT_MOC_LITERAL(5, 53, 1), // "i"
QT_MOC_LITERAL(6, 55, 13), // "ClickedButton"
QT_MOC_LITERAL(7, 69, 4), // "text"
QT_MOC_LITERAL(8, 74, 17) // "fresh_btn_clicked"

    },
    "result_window\0show_result_byid\0\0picid\0"
    "button_clicked\0i\0ClickedButton\0text\0"
    "fresh_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_result_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x08 /* Private */,
       6,    1,   40,    2, 0x08 /* Private */,
       8,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void result_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        result_window *_t = static_cast<result_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_result_byid((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->button_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ClickedButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->fresh_btn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (result_window::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&result_window::show_result_byid)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject result_window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_result_window.data,
      qt_meta_data_result_window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *result_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *result_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_result_window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int result_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void result_window::show_result_byid(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
