/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Nivel_2/mainwindow.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[8];
    char stringdata5[6];
    char stringdata6[7];
    char stringdata7[20];
    char stringdata8[19];
    char stringdata9[13];
    char stringdata10[13];
    char stringdata11[2];
    char stringdata12[14];
    char stringdata13[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "colisionGasolina"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 17),  // "colisionObstaculo"
        QT_MOC_LITERAL(47, 7),  // "acelera"
        QT_MOC_LITERAL(55, 5),  // "freno"
        QT_MOC_LITERAL(61, 6),  // "animar"
        QT_MOC_LITERAL(68, 19),  // "movimientoVehiculos"
        QT_MOC_LITERAL(88, 18),  // "movimientoGasolina"
        QT_MOC_LITERAL(107, 12),  // "subeGasolina"
        QT_MOC_LITERAL(120, 12),  // "bajaGasolina"
        QT_MOC_LITERAL(133, 1),  // "x"
        QT_MOC_LITERAL(135, 13),  // "aumentarItems"
        QT_MOC_LITERAL(149, 10)   // "Actualizar"
    },
    "MainWindow",
    "colisionGasolina",
    "",
    "colisionObstaculo",
    "acelera",
    "freno",
    "animar",
    "movimientoVehiculos",
    "movimientoGasolina",
    "subeGasolina",
    "bajaGasolina",
    "x",
    "aumentarItems",
    "Actualizar"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,
       4,    0,   82,    2, 0x06,    3 /* Public */,
       5,    0,   83,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x0a,    6 /* Public */,
       8,    0,   86,    2, 0x0a,    7 /* Public */,
       9,    0,   87,    2, 0x0a,    8 /* Public */,
      10,    1,   88,    2, 0x0a,    9 /* Public */,
      12,    0,   91,    2, 0x0a,   11 /* Public */,
      13,    0,   92,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'colisionGasolina'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colisionObstaculo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'acelera'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'freno'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimientoVehiculos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimientoGasolina'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'subeGasolina'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bajaGasolina'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'aumentarItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Actualizar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->colisionGasolina(); break;
        case 1: _t->colisionObstaculo(); break;
        case 2: _t->acelera(); break;
        case 3: _t->freno(); break;
        case 4: _t->animar(); break;
        case 5: _t->movimientoVehiculos(); break;
        case 6: _t->movimientoGasolina(); break;
        case 7: _t->subeGasolina(); break;
        case 8: _t->bajaGasolina((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->aumentarItems(); break;
        case 10: _t->Actualizar(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::colisionGasolina; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::colisionObstaculo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::acelera; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::freno; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::colisionGasolina()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::colisionObstaculo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::acelera()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::freno()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
