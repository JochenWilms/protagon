/****************************************************************************
** Meta object code from reading C++ file 'world.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../world source/world.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'world.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PEnemy_t {
    QByteArrayData data[4];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PEnemy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PEnemy_t qt_meta_stringdata_PEnemy = {
    {
QT_MOC_LITERAL(0, 0, 6), // "PEnemy"
QT_MOC_LITERAL(1, 7, 4), // "dead"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 6) // "poison"

    },
    "PEnemy\0dead\0\0poison"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PEnemy[] = {

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
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void PEnemy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PEnemy *_t = static_cast<PEnemy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dead(); break;
        case 1: { bool _r = _t->poison();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PEnemy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PEnemy::dead)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject PEnemy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PEnemy.data,
      qt_meta_data_PEnemy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PEnemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PEnemy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PEnemy.stringdata0))
        return static_cast<void*>(const_cast< PEnemy*>(this));
    if (!strcmp(_clname, "Enemy"))
        return static_cast< Enemy*>(const_cast< PEnemy*>(this));
    return QObject::qt_metacast(_clname);
}

int PEnemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PEnemy::dead()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_Protagonist_t {
    QByteArrayData data[5];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protagonist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protagonist_t qt_meta_stringdata_Protagonist = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Protagonist"
QT_MOC_LITERAL(1, 12, 10), // "posChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 1), // "x"
QT_MOC_LITERAL(4, 26, 1) // "y"

    },
    "Protagonist\0posChanged\0\0x\0y"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protagonist[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

void Protagonist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Protagonist *_t = static_cast<Protagonist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->posChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Protagonist::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Protagonist::posChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Protagonist::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Protagonist.data,
      qt_meta_data_Protagonist,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Protagonist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protagonist::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Protagonist.stringdata0))
        return static_cast<void*>(const_cast< Protagonist*>(this));
    if (!strcmp(_clname, "Tile"))
        return static_cast< Tile*>(const_cast< Protagonist*>(this));
    return QObject::qt_metacast(_clname);
}

int Protagonist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Protagonist::posChanged(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
