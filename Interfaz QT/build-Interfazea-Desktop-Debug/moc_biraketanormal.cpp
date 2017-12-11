/****************************************************************************
** Meta object code from reading C++ file 'biraketanormal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interfazea/biraketanormal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'biraketanormal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Biraketanormal_t {
    QByteArrayData data[14];
    char stringdata[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Biraketanormal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Biraketanormal_t qt_meta_stringdata_Biraketanormal = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 21),
QT_MOC_LITERAL(2, 37, 0),
QT_MOC_LITERAL(3, 38, 35),
QT_MOC_LITERAL(4, 74, 4),
QT_MOC_LITERAL(5, 79, 21),
QT_MOC_LITERAL(6, 101, 22),
QT_MOC_LITERAL(7, 124, 21),
QT_MOC_LITERAL(8, 146, 23),
QT_MOC_LITERAL(9, 170, 29),
QT_MOC_LITERAL(10, 200, 26),
QT_MOC_LITERAL(11, 227, 28),
QT_MOC_LITERAL(12, 256, 38),
QT_MOC_LITERAL(13, 295, 11)
    },
    "Biraketanormal\0on_hasiButton_clicked\0"
    "\0on_abiaduraAldatzailea_valueChanged\0"
    "arg1\0on_adosButton_clicked\0"
    "on_pausaButton_clicked\0on_stopButton_clicked\0"
    "on_atzeraButton_clicked\0"
    "on_berrabiaraziButton_clicked\0"
    "on_actionManeiua_triggered\0"
    "on_actionKontrolak_triggered\0"
    "on_actionAbiadura_aukeraketa_triggered\0"
    "showNagusia\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Biraketanormal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08,
       3,    1,   70,    2, 0x08,
       5,    0,   73,    2, 0x08,
       6,    0,   74,    2, 0x08,
       7,    0,   75,    2, 0x08,
       8,    0,   76,    2, 0x08,
       9,    0,   77,    2, 0x08,
      10,    0,   78,    2, 0x08,
      11,    0,   79,    2, 0x08,
      12,    0,   80,    2, 0x08,
      13,    0,   81,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
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

void Biraketanormal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Biraketanormal *_t = static_cast<Biraketanormal *>(_o);
        switch (_id) {
        case 0: _t->on_hasiButton_clicked(); break;
        case 1: _t->on_abiaduraAldatzailea_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_adosButton_clicked(); break;
        case 3: _t->on_pausaButton_clicked(); break;
        case 4: _t->on_stopButton_clicked(); break;
        case 5: _t->on_atzeraButton_clicked(); break;
        case 6: _t->on_berrabiaraziButton_clicked(); break;
        case 7: _t->on_actionManeiua_triggered(); break;
        case 8: _t->on_actionKontrolak_triggered(); break;
        case 9: _t->on_actionAbiadura_aukeraketa_triggered(); break;
        case 10: _t->showNagusia(); break;
        default: ;
        }
    }
}

const QMetaObject Biraketanormal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Biraketanormal.data,
      qt_meta_data_Biraketanormal,  qt_static_metacall, 0, 0}
};


const QMetaObject *Biraketanormal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Biraketanormal::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Biraketanormal.stringdata))
        return static_cast<void*>(const_cast< Biraketanormal*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Biraketanormal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
