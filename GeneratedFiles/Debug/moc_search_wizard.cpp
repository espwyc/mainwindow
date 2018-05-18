/****************************************************************************
** Meta object code from reading C++ file 'search_wizard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../search_wizard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'search_wizard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_page_1_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_page_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_page_1_t qt_meta_stringdata_page_1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "page_1"
QT_MOC_LITERAL(1, 7, 17), // "tree_item_changed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 43, 4), // "item"
QT_MOC_LITERAL(5, 48, 6), // "column"
QT_MOC_LITERAL(6, 55, 18), // "TreeUpdateFinished"
QT_MOC_LITERAL(7, 74, 15) // "treeItemChanged"

    },
    "page_1\0tree_item_changed\0\0QTreeWidgetItem*\0"
    "item\0column\0TreeUpdateFinished\0"
    "treeItemChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_page_1[] = {

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
       1,    2,   29,    2, 0x06 /* Public */,
       6,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   35,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,

       0        // eod
};

void page_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        page_1 *_t = static_cast<page_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tree_item_changed((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->TreeUpdateFinished(); break;
        case 2: _t->treeItemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (page_1::*_t)(QTreeWidgetItem * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&page_1::tree_item_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (page_1::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&page_1::TreeUpdateFinished)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject page_1::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_page_1.data,
      qt_meta_data_page_1,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *page_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *page_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_page_1.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int page_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
void page_1::tree_item_changed(QTreeWidgetItem * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void page_1::TreeUpdateFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_page_2_t {
    QByteArrayData data[15];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_page_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_page_2_t qt_meta_stringdata_page_2 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "page_2"
QT_MOC_LITERAL(1, 7, 12), // "SubmitQuerry"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "QuerryStruct&"
QT_MOC_LITERAL(4, 35, 2), // "QS"
QT_MOC_LITERAL(5, 38, 11), // "PicSelected"
QT_MOC_LITERAL(6, 50, 13), // "PicUnSelected"
QT_MOC_LITERAL(7, 64, 18), // "cancel_btn_clicked"
QT_MOC_LITERAL(8, 83, 19), // "confirm_btn_clicked"
QT_MOC_LITERAL(9, 103, 15), // "sel_pic_clicked"
QT_MOC_LITERAL(10, 119, 12), // "b_date_check"
QT_MOC_LITERAL(11, 132, 4), // "date"
QT_MOC_LITERAL(12, 137, 13), // "update_status"
QT_MOC_LITERAL(13, 151, 22), // "SBQTWiardButtonClicked"
QT_MOC_LITERAL(14, 174, 15) // "treeItemChanged"

    },
    "page_2\0SubmitQuerry\0\0QuerryStruct&\0"
    "QS\0PicSelected\0PicUnSelected\0"
    "cancel_btn_clicked\0confirm_btn_clicked\0"
    "sel_pic_clicked\0b_date_check\0date\0"
    "update_status\0SBQTWiardButtonClicked\0"
    "treeItemChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_page_2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void page_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        page_2 *_t = static_cast<page_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SubmitQuerry((*reinterpret_cast< QuerryStruct(*)>(_a[1]))); break;
        case 1: _t->PicSelected(); break;
        case 2: _t->PicUnSelected(); break;
        case 3: _t->cancel_btn_clicked(); break;
        case 4: _t->confirm_btn_clicked(); break;
        case 5: _t->sel_pic_clicked(); break;
        case 6: _t->b_date_check((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 7: _t->update_status(); break;
        case 8: _t->SBQTWiardButtonClicked(); break;
        case 9: _t->treeItemChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (page_2::*_t)(QuerryStruct & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&page_2::SubmitQuerry)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (page_2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&page_2::PicSelected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (page_2::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&page_2::PicUnSelected)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject page_2::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_page_2.data,
      qt_meta_data_page_2,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *page_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *page_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_page_2.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int page_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void page_2::SubmitQuerry(QuerryStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void page_2::PicSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void page_2::PicUnSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_page_3_t {
    QByteArrayData data[7];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_page_3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_page_3_t qt_meta_stringdata_page_3 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "page_3"
QT_MOC_LITERAL(1, 7, 12), // "SubmitQuerry"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "QuerryStruct&"
QT_MOC_LITERAL(4, 35, 2), // "QS"
QT_MOC_LITERAL(5, 38, 22), // "confirm_button_clicked"
QT_MOC_LITERAL(6, 61, 9) // "RcvQuerry"

    },
    "page_3\0SubmitQuerry\0\0QuerryStruct&\0"
    "QS\0confirm_button_clicked\0RcvQuerry"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_page_3[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void page_3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        page_3 *_t = static_cast<page_3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SubmitQuerry((*reinterpret_cast< QuerryStruct(*)>(_a[1]))); break;
        case 1: _t->confirm_button_clicked(); break;
        case 2: _t->RcvQuerry((*reinterpret_cast< QuerryStruct(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (page_3::*_t)(QuerryStruct & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&page_3::SubmitQuerry)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject page_3::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_page_3.data,
      qt_meta_data_page_3,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *page_3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *page_3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_page_3.stringdata0))
        return static_cast<void*>(this);
    return QWizardPage::qt_metacast(_clname);
}

int page_3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
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
void page_3::SubmitQuerry(QuerryStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_search_wizard_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_search_wizard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_search_wizard_t qt_meta_stringdata_search_wizard = {
    {
QT_MOC_LITERAL(0, 0, 13), // "search_wizard"
QT_MOC_LITERAL(1, 14, 12), // "SubmitQuerry"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "QuerryStruct&"
QT_MOC_LITERAL(4, 42, 2), // "QS"
QT_MOC_LITERAL(5, 45, 4), // "SBQT"
QT_MOC_LITERAL(6, 50, 5), // "SBQTS"
QT_MOC_LITERAL(7, 56, 15), // "SBQTpicselected"
QT_MOC_LITERAL(8, 72, 17) // "SBQTpicunselected"

    },
    "search_wizard\0SubmitQuerry\0\0QuerryStruct&\0"
    "QS\0SBQT\0SBQTS\0SBQTpicselected\0"
    "SBQTpicunselected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_search_wizard[] = {

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
       8,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void search_wizard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        search_wizard *_t = static_cast<search_wizard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SubmitQuerry((*reinterpret_cast< QuerryStruct(*)>(_a[1]))); break;
        case 1: _t->SBQT(); break;
        case 2: _t->SBQTS(); break;
        case 3: _t->SBQTpicselected(); break;
        case 4: _t->SBQTpicunselected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (search_wizard::*_t)(QuerryStruct & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&search_wizard::SubmitQuerry)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject search_wizard::staticMetaObject = {
    { &QWizard::staticMetaObject, qt_meta_stringdata_search_wizard.data,
      qt_meta_data_search_wizard,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *search_wizard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *search_wizard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_search_wizard.stringdata0))
        return static_cast<void*>(this);
    return QWizard::qt_metacast(_clname);
}

int search_wizard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizard::qt_metacall(_c, _id, _a);
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
void search_wizard::SubmitQuerry(QuerryStruct & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
