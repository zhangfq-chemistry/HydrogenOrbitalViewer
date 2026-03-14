/****************************************************************************
** Meta object code from reading C++ file 'hsvslider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widgets/Sliders/HSV/hsvslider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hsvslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HSVSlider_t {
    QByteArrayData data[5];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HSVSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HSVSlider_t qt_meta_stringdata_HSVSlider = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HSVSlider"
QT_MOC_LITERAL(1, 10, 10), // "hueChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "saturationChanged"
QT_MOC_LITERAL(4, 40, 12) // "valueChanged"

    },
    "HSVSlider\0hueChanged\0\0saturationChanged\0"
    "valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HSVSlider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,
       4,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

       0        // eod
};

void HSVSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HSVSlider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hueChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->saturationChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->valueChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HSVSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HSVSlider::hueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HSVSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HSVSlider::saturationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HSVSlider::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HSVSlider::valueChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HSVSlider::staticMetaObject = { {
    &ColorSlider::staticMetaObject,
    qt_meta_stringdata_HSVSlider.data,
    qt_meta_data_HSVSlider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HSVSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HSVSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HSVSlider.stringdata0))
        return static_cast<void*>(this);
    return ColorSlider::qt_metacast(_clname);
}

int HSVSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ColorSlider::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HSVSlider::hueChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HSVSlider::saturationChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HSVSlider::valueChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
