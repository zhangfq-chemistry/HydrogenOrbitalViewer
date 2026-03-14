/****************************************************************************
** Meta object code from reading C++ file 'RadialFunViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RadialFunViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RadialFunViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RadialFunViewer_t {
    QByteArrayData data[18];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RadialFunViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RadialFunViewer_t qt_meta_stringdata_RadialFunViewer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "RadialFunViewer"
QT_MOC_LITERAL(1, 16, 9), // "renderMol"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "HMol*"
QT_MOC_LITERAL(4, 33, 10), // "addSeriesR"
QT_MOC_LITERAL(5, 44, 4), // "HMO*"
QT_MOC_LITERAL(6, 49, 2), // "mo"
QT_MOC_LITERAL(7, 52, 11), // "addSeriesR2"
QT_MOC_LITERAL(8, 64, 12), // "addSeriesRDF"
QT_MOC_LITERAL(9, 77, 12), // "removeSeries"
QT_MOC_LITERAL(10, 90, 14), // "connectMarkers"
QT_MOC_LITERAL(11, 105, 17), // "disconnectMarkers"
QT_MOC_LITERAL(12, 123, 19), // "handleMarkerClicked"
QT_MOC_LITERAL(13, 143, 12), // "setR2visible"
QT_MOC_LITERAL(14, 156, 1), // "v"
QT_MOC_LITERAL(15, 158, 13), // "setRDFvisible"
QT_MOC_LITERAL(16, 172, 11), // "setRvisible"
QT_MOC_LITERAL(17, 184, 11) // "refreshAxis"

    },
    "RadialFunViewer\0renderMol\0\0HMol*\0"
    "addSeriesR\0HMO*\0mo\0addSeriesR2\0"
    "addSeriesRDF\0removeSeries\0connectMarkers\0"
    "disconnectMarkers\0handleMarkerClicked\0"
    "setR2visible\0v\0setRDFvisible\0setRvisible\0"
    "refreshAxis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RadialFunViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       7,    1,   80,    2, 0x0a /* Public */,
       8,    1,   83,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x0a /* Public */,
      10,    0,   87,    2, 0x0a /* Public */,
      11,    0,   88,    2, 0x0a /* Public */,
      12,    0,   89,    2, 0x0a /* Public */,
      13,    1,   90,    2, 0x0a /* Public */,
      15,    1,   93,    2, 0x0a /* Public */,
      16,    1,   96,    2, 0x0a /* Public */,
      17,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void RadialFunViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RadialFunViewer *_t = static_cast<RadialFunViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->renderMol((*reinterpret_cast< HMol*(*)>(_a[1]))); break;
        case 1: _t->addSeriesR((*reinterpret_cast< HMO*(*)>(_a[1]))); break;
        case 2: _t->addSeriesR2((*reinterpret_cast< HMO*(*)>(_a[1]))); break;
        case 3: _t->addSeriesRDF((*reinterpret_cast< HMO*(*)>(_a[1]))); break;
        case 4: _t->removeSeries(); break;
        case 5: _t->connectMarkers(); break;
        case 6: _t->disconnectMarkers(); break;
        case 7: _t->handleMarkerClicked(); break;
        case 8: _t->setR2visible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setRDFvisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->setRvisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->refreshAxis(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RadialFunViewer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RadialFunViewer.data,
      qt_meta_data_RadialFunViewer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RadialFunViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RadialFunViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RadialFunViewer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RadialFunViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
