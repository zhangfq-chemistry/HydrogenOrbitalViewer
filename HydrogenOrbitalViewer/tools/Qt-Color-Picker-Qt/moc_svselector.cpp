/****************************************************************************
** Meta object code from reading C++ file 'svselector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Widgets/ColorWidgets/svselector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'svselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SVSelector_t {
    QByteArrayData data[7];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SVSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SVSelector_t qt_meta_stringdata_SVSelector = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SVSelector"
QT_MOC_LITERAL(1, 11, 12), // "colorChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 17), // "saturationChanged"
QT_MOC_LITERAL(4, 43, 12), // "valueChanged"
QT_MOC_LITERAL(5, 56, 9), // "changeHue"
QT_MOC_LITERAL(6, 66, 5) // "color"

    },
    "SVSelector\0colorChanged\0\0saturationChanged\0"
    "valueChanged\0changeHue\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SVSelector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       3,    1,   37,    2, 0x06 /* Public */,
       4,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, QMetaType::QColor,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    6,

       0        // eod
};

void SVSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SVSelector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->colorChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->saturationChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->valueChanged((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->changeHue((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SVSelector::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SVSelector::colorChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SVSelector::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SVSelector::saturationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SVSelector::*)(QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SVSelector::valueChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SVSelector::staticMetaObject = { {
    &ColorWidget::staticMetaObject,
    qt_meta_stringdata_SVSelector.data,
    qt_meta_data_SVSelector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SVSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SVSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SVSelector.stringdata0))
        return static_cast<void*>(this);
    return ColorWidget::qt_metacast(_clname);
}

int SVSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ColorWidget::qt_metacall(_c, _id, _a);
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
void SVSelector::colorChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SVSelector::saturationChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SVSelector::valueChanged(QColor _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
