/****************************************************************************
** Meta object code from reading C++ file 'groupwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../groupwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GroupWidget_t {
    QByteArrayData data[20];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupWidget_t qt_meta_stringdata_GroupWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GroupWidget"
QT_MOC_LITERAL(1, 12, 14), // "deleteCurGroup"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "GroupBase"
QT_MOC_LITERAL(4, 38, 17), // "showGroupListView"
QT_MOC_LITERAL(5, 56, 4), // "flag"
QT_MOC_LITERAL(6, 61, 8), // "baseInfo"
QT_MOC_LITERAL(7, 70, 11), // "deleteGroup"
QT_MOC_LITERAL(8, 82, 8), // "addGroup"
QT_MOC_LITERAL(9, 91, 11), // "reNameGroup"
QT_MOC_LITERAL(10, 103, 12), // "deletePeople"
QT_MOC_LITERAL(11, 116, 7), // "groupId"
QT_MOC_LITERAL(12, 124, 8), // "peopleId"
QT_MOC_LITERAL(13, 133, 12), // "moveNewGroup"
QT_MOC_LITERAL(14, 146, 12), // "fromBaseInfo"
QT_MOC_LITERAL(15, 159, 6), // "People"
QT_MOC_LITERAL(16, 166, 7), // "patient"
QT_MOC_LITERAL(17, 174, 10), // "toBaseInfo"
QT_MOC_LITERAL(18, 185, 17), // "deleteGroupPeople"
QT_MOC_LITERAL(19, 203, 9) // "patientId"

    },
    "GroupWidget\0deleteCurGroup\0\0GroupBase\0"
    "showGroupListView\0flag\0baseInfo\0"
    "deleteGroup\0addGroup\0reNameGroup\0"
    "deletePeople\0groupId\0peopleId\0"
    "moveNewGroup\0fromBaseInfo\0People\0"
    "patient\0toBaseInfo\0deleteGroupPeople\0"
    "patientId"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   57,    2, 0x08 /* Private */,
       7,    1,   62,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    1,   66,    2, 0x08 /* Private */,
      10,    2,   69,    2, 0x08 /* Private */,
      13,    3,   74,    2, 0x08 /* Private */,
      18,    2,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 3,    5,    6,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 15, QMetaType::QString,   14,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   11,

       0        // eod
};

void GroupWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupWidget *_t = static_cast<GroupWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteCurGroup((*reinterpret_cast< const GroupBase(*)>(_a[1]))); break;
        case 1: _t->showGroupListView((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const GroupBase(*)>(_a[2]))); break;
        case 2: _t->deleteGroup((*reinterpret_cast< const GroupBase(*)>(_a[1]))); break;
        case 3: _t->addGroup(); break;
        case 4: _t->reNameGroup((*reinterpret_cast< const GroupBase(*)>(_a[1]))); break;
        case 5: _t->deletePeople((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 6: _t->moveNewGroup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const People(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 7: _t->deleteGroupPeople((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupWidget::*_t)(const GroupBase & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupWidget::deleteCurGroup)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject GroupWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupWidget.data,
      qt_meta_data_GroupWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupWidget.stringdata0))
        return static_cast<void*>(const_cast< GroupWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void GroupWidget::deleteCurGroup(const GroupBase & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
