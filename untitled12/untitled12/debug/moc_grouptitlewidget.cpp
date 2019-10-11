/****************************************************************************
** Meta object code from reading C++ file 'grouptitlewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../grouptitlewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'grouptitlewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GroupTitleWidget_t {
    QByteArrayData data[14];
    char stringdata0[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupTitleWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupTitleWidget_t qt_meta_stringdata_GroupTitleWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GroupTitleWidget"
QT_MOC_LITERAL(1, 17, 9), // "showGroup"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 4), // "flag"
QT_MOC_LITERAL(4, 33, 9), // "GroupBase"
QT_MOC_LITERAL(5, 43, 2), // "id"
QT_MOC_LITERAL(6, 46, 11), // "addNewGroup"
QT_MOC_LITERAL(7, 58, 11), // "deleteGroup"
QT_MOC_LITERAL(8, 70, 11), // "reNameGroup"
QT_MOC_LITERAL(9, 82, 18), // "startToReNameGroup"
QT_MOC_LITERAL(10, 101, 10), // "changeFlag"
QT_MOC_LITERAL(11, 112, 15), // "showContextMenu"
QT_MOC_LITERAL(12, 128, 14), // "deleteCurGroup"
QT_MOC_LITERAL(13, 143, 12) // "endNameGroup"

    },
    "GroupTitleWidget\0showGroup\0\0flag\0"
    "GroupBase\0id\0addNewGroup\0deleteGroup\0"
    "reNameGroup\0startToReNameGroup\0"
    "changeFlag\0showContextMenu\0deleteCurGroup\0"
    "endNameGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupTitleWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   71,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    1,   73,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 4,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GroupTitleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupTitleWidget *_t = static_cast<GroupTitleWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showGroup((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const GroupBase(*)>(_a[2]))); break;
        case 1: _t->addNewGroup(); break;
        case 2: _t->deleteGroup((*reinterpret_cast< const GroupBase(*)>(_a[1]))); break;
        case 3: _t->reNameGroup((*reinterpret_cast< const GroupBase(*)>(_a[1]))); break;
        case 4: _t->startToReNameGroup(); break;
        case 5: _t->changeFlag(); break;
        case 6: _t->showContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 7: _t->deleteCurGroup(); break;
        case 8: _t->endNameGroup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GroupTitleWidget::*_t)(bool , const GroupBase & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupTitleWidget::showGroup)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (GroupTitleWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupTitleWidget::addNewGroup)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (GroupTitleWidget::*_t)(const GroupBase & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupTitleWidget::deleteGroup)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (GroupTitleWidget::*_t)(const GroupBase & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GroupTitleWidget::reNameGroup)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject GroupTitleWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupTitleWidget.data,
      qt_meta_data_GroupTitleWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GroupTitleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupTitleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GroupTitleWidget.stringdata0))
        return static_cast<void*>(const_cast< GroupTitleWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupTitleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GroupTitleWidget::showGroup(bool _t1, const GroupBase & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GroupTitleWidget::addNewGroup()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void GroupTitleWidget::deleteGroup(const GroupBase & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GroupTitleWidget::reNameGroup(const GroupBase & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
