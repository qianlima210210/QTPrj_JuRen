/****************************************************************************
** Meta object code from reading C++ file 'grouplistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grouplistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grouplistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GroupListView_t {
    QByteArrayData data[14];
    char stringdata0[170];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupListView_t qt_meta_stringdata_GroupListView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "GroupListView"
QT_MOC_LITERAL(1, 14, 12), // "deletePeople"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 7), // "groupId"
QT_MOC_LITERAL(4, 36, 8), // "peopelId"
QT_MOC_LITERAL(5, 45, 22), // "movePeopleToOtherGroup"
QT_MOC_LITERAL(6, 68, 12), // "fromBaseInfo"
QT_MOC_LITERAL(7, 81, 6), // "People"
QT_MOC_LITERAL(8, 88, 7), // "patient"
QT_MOC_LITERAL(9, 96, 10), // "toBaseInfo"
QT_MOC_LITERAL(10, 107, 15), // "showContentMenu"
QT_MOC_LITERAL(11, 123, 19), // "deleteCurrentPeople"
QT_MOC_LITERAL(12, 143, 10), // "movePeople"
QT_MOC_LITERAL(13, 154, 15) // "updateFixHeight"

    },
    "GroupListView\0deletePeople\0\0groupId\0"
    "peopelId\0movePeopleToOtherGroup\0"
    "fromBaseInfo\0People\0patient\0toBaseInfo\0"
    "showContentMenu\0deleteCurrentPeople\0"
    "movePeople\0updateFixHeight"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    3,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   56,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,
      12,    0,   60,    2, 0x08 /* Private */,
      13,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 7, QMetaType::QString,    6,    8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GroupListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupListView *_t = static_cast<GroupListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deletePeople((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->movePeopleToOtherGroup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const People(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 2: _t->showContentMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->deleteCurrentPeople(); break;
        case 4: _t->movePeople(); break;
        case 5: _t->updateFixHeight(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupListView::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupListView::deletePeople)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GroupListView::*_t)(const QString & , const People & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupListView::movePeopleToOtherGroup)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject GroupListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_GroupListView.data,
      qt_meta_data_GroupListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupListView.stringdata0))
        return static_cast<void*>(const_cast< GroupListView*>(this));
    return QListView::qt_metacast(_clname);
}

int GroupListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GroupListView::deletePeople(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GroupListView::movePeopleToOtherGroup(const QString & _t1, const People & _t2, const QString & _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
