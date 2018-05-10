/****************************************************************************
** Meta object code from reading C++ file 'search_w.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../search_w.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search_w.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_search_w_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_search_w_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_search_w_t qt_meta_stringdata_search_w = {
    {
QT_MOC_LITERAL(0, 0, 8), // "search_w"
QT_MOC_LITERAL(1, 9, 12), // "SubmitQuerry"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 13), // "QuerryStruct&"
QT_MOC_LITERAL(4, 37, 2), // "QS"
QT_MOC_LITERAL(5, 40, 18), // "cancel_btn_clicked"
QT_MOC_LITERAL(6, 59, 19), // "confirm_btn_clicked"
QT_MOC_LITERAL(7, 79, 15), // "sel_pic_clicked"
QT_MOC_LITERAL(8, 95, 12), // "b_date_check"
QT_MOC_LITERAL(9, 108, 4) // "date"

    },
    "search_w\0SubmitQuerry\0\0QuerryStruct&\0"
    "QS\0cancel_btn_clicked\0confirm_btn_clicked\0"
    "sel_pic_clicked\0b_date_check\0date"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_search_w[] = {

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
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,
       7,    0,   44,    2, 0x08 /* Private */,
       8,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    9,

       0        // eod
};

void search_w::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        search_w *_t = static_cast<search_w *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SubmitQuerry((*reinterpret_cast< QuerryStruct(*)>(_a[1]))); break;
        case 1: _t->cancel_btn_clicked(); break;
        case 2: _t->confirm_btn_clicked(); break;
        case 3: _t->sel_pic_clicked(); break;
        case 4: _t->b_date_check((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (search_w::*_t)(QuerryStruct & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&search_w::SubmitQuerry)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject search_w::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_search_w.data,
      qt_meta_data_search_w,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *search_w::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *search_w::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_search_w.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int search_w::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void search_w::SubmitQuerry(QuerryStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
