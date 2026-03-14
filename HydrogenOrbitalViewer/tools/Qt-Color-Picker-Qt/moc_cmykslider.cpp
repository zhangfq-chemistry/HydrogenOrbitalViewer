/****************************************************************************
** Meta object code from reading C++ file 'cmykslider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widgets/Sliders/CMYK/cmykslider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cmykslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMYKSlider_t {
    QByteArrayData data[6];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMYKSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMYKSlider_t qt_meta_stringdata_CMYKSlider = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CMYKSlider"
QT_MOC_LITERAL(1, 11, 11), // "cyanChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "magentaChanged"
QT_MOC_LITERAL(4, 39, 13), // "yellowChanged"
QT_MOC_LITERAL(5, 53, 12) // "blackChanged"

    },
    "CMYKSlider\0cyanChanged\0\0magentaChanged\0"
    "yellowChanged\0blackChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMYKSlider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,
       4,    1,   40,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

       0        // eod
};

void CMYKSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CMYKSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cyanChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->magentaChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->yellowChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->blackChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CMYKSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMYKSlider::cyanChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CMYKSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMYKSlider::magentaChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CMYKSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMYKSlider::yellowChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CMYKSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CMYKSlider::blackChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CMYKSlider::staticMetaObject = { {
    &ColorSlider::staticMetaObject,
    qt_meta_stringdata_CMYKSlider.data,
    qt_meta_data_CMYKSlider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CMYKSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMYKSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMYKSlider.stringdata0))
        return static_cast<void*>(this);
    return ColorSlider::qt_metacast(_clname);
}

int CMYKSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ColorSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CMYKSlider::cyanChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CMYKSlider::magentaChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CMYKSlider::yellowChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CMYKSlider::blackChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
