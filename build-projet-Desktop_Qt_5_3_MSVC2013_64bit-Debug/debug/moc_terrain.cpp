/****************************************************************************
** Meta object code from reading C++ file 'terrain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../projet/terrain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'terrain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Terrain_t {
    QByteArrayData data[10];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Terrain_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Terrain_t qt_meta_stringdata_Terrain = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 17),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 6),
QT_MOC_LITERAL(4, 34, 15),
QT_MOC_LITERAL(5, 50, 13),
QT_MOC_LITERAL(6, 64, 28),
QT_MOC_LITERAL(7, 93, 18),
QT_MOC_LITERAL(8, 112, 23),
QT_MOC_LITERAL(9, 136, 11)
    },
    "Terrain\0comportementDecor\0\0Decor*\0"
    "toucheParEnnemi\0testColission\0"
    "changeSensDeplacementEnnemis\0"
    "deplacementEnnemis\0comportementDecorAction\0"
    "resetNiveau"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Terrain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    0,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
       9,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,

       0        // eod
};

void Terrain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Terrain *_t = static_cast<Terrain *>(_o);
        switch (_id) {
        case 0: _t->comportementDecor((*reinterpret_cast< Decor*(*)>(_a[1]))); break;
        case 1: _t->toucheParEnnemi(); break;
        case 2: _t->testColission(); break;
        case 3: _t->changeSensDeplacementEnnemis(); break;
        case 4: _t->deplacementEnnemis(); break;
        case 5: _t->comportementDecorAction((*reinterpret_cast< Decor*(*)>(_a[1]))); break;
        case 6: _t->resetNiveau(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Terrain::*_t)(Decor * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Terrain::comportementDecor)) {
                *result = 0;
            }
        }
        {
            typedef void (Terrain::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Terrain::toucheParEnnemi)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Terrain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Terrain.data,
      qt_meta_data_Terrain,  qt_static_metacall, 0, 0}
};


const QMetaObject *Terrain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Terrain::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Terrain.stringdata))
        return static_cast<void*>(const_cast< Terrain*>(this));
    return QWidget::qt_metacast(_clname);
}

int Terrain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Terrain::comportementDecor(Decor * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Terrain::toucheParEnnemi()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
