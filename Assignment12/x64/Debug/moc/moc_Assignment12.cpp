/****************************************************************************
** Meta object code from reading C++ file 'Assignment12.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Assignment12.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Assignment12.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Assignment12_t {
    QByteArrayData data[13];
    char stringdata0[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Assignment12_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Assignment12_t qt_meta_stringdata_Assignment12 = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Assignment12"
QT_MOC_LITERAL(1, 13, 6), // "addDog"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "updateDog"
QT_MOC_LITERAL(4, 31, 7), // "saveDog"
QT_MOC_LITERAL(5, 39, 9), // "runMyList"
QT_MOC_LITERAL(6, 49, 4), // "next"
QT_MOC_LITERAL(7, 54, 6), // "filter"
QT_MOC_LITERAL(8, 61, 4), // "undo"
QT_MOC_LITERAL(9, 66, 10), // "undo_modeB"
QT_MOC_LITERAL(10, 77, 4), // "redo"
QT_MOC_LITERAL(11, 82, 10), // "redo_modeB"
QT_MOC_LITERAL(12, 93, 13) // "showNewWindow"

    },
    "Assignment12\0addDog\0\0updateDog\0saveDog\0"
    "runMyList\0next\0filter\0undo\0undo_modeB\0"
    "redo\0redo_modeB\0showNewWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Assignment12[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x0a /* Public */,
       4,    0,   71,    2, 0x0a /* Public */,
       5,    0,   72,    2, 0x0a /* Public */,
       6,    0,   73,    2, 0x0a /* Public */,
       7,    0,   74,    2, 0x0a /* Public */,
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Assignment12::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Assignment12 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addDog(); break;
        case 1: _t->updateDog(); break;
        case 2: _t->saveDog(); break;
        case 3: _t->runMyList(); break;
        case 4: _t->next(); break;
        case 5: _t->filter(); break;
        case 6: _t->undo(); break;
        case 7: _t->undo_modeB(); break;
        case 8: _t->redo(); break;
        case 9: _t->redo_modeB(); break;
        case 10: _t->showNewWindow(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Assignment12::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Assignment12.data,
    qt_meta_data_Assignment12,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Assignment12::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Assignment12::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Assignment12.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Assignment12::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
