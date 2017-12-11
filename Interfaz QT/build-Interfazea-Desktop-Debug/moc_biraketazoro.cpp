/****************************************************************************
** Meta object code from reading C++ file 'biraketazoro.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Interfazea/biraketazoro.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'biraketazoro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Biraketazoro_t {
    QByteArrayData data[14];
    char stringdata[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Biraketazoro_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Biraketazoro_t qt_meta_stringdata_Biraketazoro = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 21),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 35),
QT_MOC_LITERAL(4, 72, 4),
QT_MOC_LITERAL(5, 77, 21),
QT_MOC_LITERAL(6, 99, 22),
QT_MOC_LITERAL(7, 122, 21),
QT_MOC_LITERAL(8, 144, 23),
QT_MOC_LITERAL(9, 168, 29),
QT_MOC_LITERAL(10, 198, 26),
QT_MOC_LITERAL(11, 225, 28),
QT_MOC_LITERAL(12, 254, 38),
QT_MOC_LITERAL(13, 293, 11)
    },
    "Biraketazoro\0on_adosButton_clicked\0\0"
    "on_abiaduraAldatzailea_valueChanged\0"
    "arg1\0on_hasiButton_clicked\0"
    "on_pausaButton_clicked\0on_stopButton_clicked\0"
    "on_atzeraButton_clicked\0"
    "on_berrabiaraziButton_clicked\0"
    "on_actionManeiua_triggered\0"
    "on_actionKontrolak_triggered\0"
    "on_actionAbiadura_aukeraketa_triggered\0"
    "showNagusia\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Biraketazoro[] = {

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

void Biraketazoro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Biraketazoro *_t = static_cast<Biraketazoro *>(_o);
        switch (_id) {
        case 0: _t->on_adosButton_clicked(); break;
        case 1: _t->on_abiaduraAldatzailea_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_hasiButton_clicked(); break;
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

const QMetaObject Biraketazoro::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Biraketazoro.data,
      qt_meta_data_Biraketazoro,  qt_static_metacall, 0, 0}
};


const QMetaObject *Biraketazoro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Biraketazoro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Biraketazoro.stringdata))
        return static_cast<void*>(const_cast< Biraketazoro*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Biraketazoro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
