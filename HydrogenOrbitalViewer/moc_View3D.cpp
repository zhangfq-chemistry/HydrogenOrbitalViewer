/****************************************************************************
** Meta object code from reading C++ file 'View3D.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View3D.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'View3D.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_View3D_t {
    QByteArrayData data[14];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_View3D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_View3D_t qt_meta_stringdata_View3D = {
    {
QT_MOC_LITERAL(0, 0, 6), // "View3D"
QT_MOC_LITERAL(1, 7, 12), // "zoomToExtent"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 8), // "onViewXY"
QT_MOC_LITERAL(4, 30, 8), // "onViewXZ"
QT_MOC_LITERAL(5, 39, 8), // "onViewYZ"
QT_MOC_LITERAL(6, 48, 11), // "onViewReset"
QT_MOC_LITERAL(7, 60, 22), // "onView_rotateClockwise"
QT_MOC_LITERAL(8, 83, 6), // "degree"
QT_MOC_LITERAL(9, 90, 29), // "onView_rotateCounterClockwise"
QT_MOC_LITERAL(10, 120, 15), // "onView_rotateUp"
QT_MOC_LITERAL(11, 136, 17), // "onView_rotateDown"
QT_MOC_LITERAL(12, 154, 18), // "onView_rotateRight"
QT_MOC_LITERAL(13, 173, 17) // "onView_rotateLeft"

    },
    "View3D\0zoomToExtent\0\0onViewXY\0onViewXZ\0"
    "onViewYZ\0onViewReset\0onView_rotateClockwise\0"
    "degree\0onView_rotateCounterClockwise\0"
    "onView_rotateUp\0onView_rotateDown\0"
    "onView_rotateRight\0onView_rotateLeft"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_View3D[] = {

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
       7,    1,   74,    2, 0x0a /* Public */,
       9,    1,   77,    2, 0x0a /* Public */,
      10,    1,   80,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,
      12,    1,   86,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void View3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View3D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->zoomToExtent(); break;
        case 1: _t->onViewXY(); break;
        case 2: _t->onViewXZ(); break;
        case 3: _t->onViewYZ(); break;
        case 4: _t->onViewReset(); break;
        case 5: _t->onView_rotateClockwise((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->onView_rotateCounterClockwise((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->onView_rotateUp((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->onView_rotateDown((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->onView_rotateRight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->onView_rotateLeft((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject View3D::staticMetaObject = { {
    &QVTKOpenGLNativeWidget::staticMetaObject,
    qt_meta_stringdata_View3D.data,
    qt_meta_data_View3D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *View3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View3D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_View3D.stringdata0))
        return static_cast<void*>(this);
    return QVTKOpenGLNativeWidget::qt_metacast(_clname);
}

int View3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVTKOpenGLNativeWidget::qt_metacall(_c, _id, _a);
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
