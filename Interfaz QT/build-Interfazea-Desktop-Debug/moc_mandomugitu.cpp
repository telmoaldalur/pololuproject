/****************************************************************************
** Meta object code from reading C++ file 'mandomugitu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interfazea/mandomugitu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mandomugitu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Mandomugitu_t {
    QByteArrayData data[10];
    char stringdata[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Mandomugitu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Mandomugitu_t qt_meta_stringdata_Mandomugitu = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 21),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 22),
QT_MOC_LITERAL(4, 58, 21),
QT_MOC_LITERAL(5, 80, 23),
QT_MOC_LITERAL(6, 104, 26),
QT_MOC_LITERAL(7, 131, 28),
QT_MOC_LITERAL(8, 160, 29),
QT_MOC_LITERAL(9, 190, 11)
    },
    "Mandomugitu\0on_hasiButton_clicked\0\0"
    "on_pausaButton_clicked\0on_stopButton_clicked\0"
    "on_atzeraButton_clicked\0"
    "on_actionManeiua_triggered\0"
    "on_actionKontrolak_triggered\0"
    "on_berrabiaraziButton_clicked\0showNagusia\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mandomugitu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08,
       3,    0,   55,    2, 0x08,
       4,    0,   56,    2, 0x08,
       5,    0,   57,    2, 0x08,
       6,    0,   58,    2, 0x08,
       7,    0,   59,    2, 0x08,
       8,    0,   60,    2, 0x08,
       9,    0,   61,    2, 0x0a,

 // slots: parameters
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

void Mandomugitu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Mandomugitu *_t = static_cast<Mandomugitu *>(_o);
        switch (_id) {
        case 0: _t->on_hasiButton_clicked(); break;
        case 1: _t->on_pausaButton_clicked(); break;
        case 2: _t->on_stopButton_clicked(); break;
        case 3: _t->on_atzeraButton_clicked(); break;
        case 4: _t->on_actionManeiua_triggered(); break;
        case 5: _t->on_actionKontrolak_triggered(); break;
        case 6: _t->on_berrabiaraziButton_clicked(); break;
        case 7: _t->showNagusia(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Mandomugitu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Mandomugitu.data,
      qt_meta_data_Mandomugitu,  qt_static_metacall, 0, 0}
};


const QMetaObject *Mandomugitu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mandomugitu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Mandomugitu.stringdata))
        return static_cast<void*>(const_cast< Mandomugitu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Mandomugitu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
