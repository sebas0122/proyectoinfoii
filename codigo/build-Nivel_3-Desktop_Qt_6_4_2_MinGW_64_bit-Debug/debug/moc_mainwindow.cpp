/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Nivel_3/mainwindow.h"
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
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[16];
    char stringdata5[6];
    char stringdata6[7];
    char stringdata7[11];
    char stringdata8[19];
    char stringdata9[19];
    char stringdata10[10];
    char stringdata11[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 20),  // "colisionBotellallena"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 20),  // "colisionBotellavacia"
        QT_MOC_LITERAL(54, 15),  // "colisionEnemigo"
        QT_MOC_LITERAL(70, 5),  // "salto"
        QT_MOC_LITERAL(76, 6),  // "animar"
        QT_MOC_LITERAL(83, 10),  // "Actualizar"
        QT_MOC_LITERAL(94, 18),  // "movimientoBotellas"
        QT_MOC_LITERAL(113, 18),  // "movimientoEnemigos"
        QT_MOC_LITERAL(132, 9),  // "subeSalud"
        QT_MOC_LITERAL(142, 9)   // "bajaSalud"
    },
    "MainWindow",
    "colisionBotellallena",
    "",
    "colisionBotellavacia",
    "colisionEnemigo",
    "salto",
    "animar",
    "Actualizar",
    "movimientoBotellas",
    "movimientoEnemigos",
    "subeSalud",
    "bajaSalud"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,
       4,    0,   76,    2, 0x06,    3 /* Public */,
       5,    0,   77,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   78,    2, 0x0a,    5 /* Public */,
       7,    0,   79,    2, 0x0a,    6 /* Public */,
       8,    0,   80,    2, 0x0a,    7 /* Public */,
       9,    0,   81,    2, 0x0a,    8 /* Public */,
      10,    0,   82,    2, 0x0a,    9 /* Public */,
      11,    0,   83,    2, 0x0a,   10 /* Public */,

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
        // method 'colisionBotellallena'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colisionBotellavacia'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'colisionEnemigo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'salto'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'animar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Actualizar'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimientoBotellas'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'movimientoEnemigos'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'subeSalud'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'bajaSalud'
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
        case 0: _t->colisionBotellallena(); break;
        case 1: _t->colisionBotellavacia(); break;
        case 2: _t->colisionEnemigo(); break;
        case 3: _t->salto(); break;
        case 4: _t->animar(); break;
        case 5: _t->Actualizar(); break;
        case 6: _t->movimientoBotellas(); break;
        case 7: _t->movimientoEnemigos(); break;
        case 8: _t->subeSalud(); break;
        case 9: _t->bajaSalud(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::colisionBotellallena; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::colisionBotellavacia; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::colisionEnemigo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::salto; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
    (void)_a;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::colisionBotellallena()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::colisionBotellavacia()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::colisionEnemigo()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::salto()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
