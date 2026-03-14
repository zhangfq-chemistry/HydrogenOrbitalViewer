/****************************************************************************
** Meta object code from reading C++ file 'ColorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ColorDialog/ColorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ColorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ColorDialog_t {
    QByteArrayData data[15];
    char stringdata0[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ColorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ColorDialog_t qt_meta_stringdata_ColorDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ColorDialog"
QT_MOC_LITERAL(1, 12, 17), // "colorItemSelcSlot"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 18), // "addCustomColorSlot"
QT_MOC_LITERAL(4, 50, 16), // "okBtnClickedSlot"
QT_MOC_LITERAL(5, 67, 20), // "cancelBtnClickedSlot"
QT_MOC_LITERAL(6, 88, 15), // "editChangedSlot"
QT_MOC_LITERAL(7, 104, 16), // "editFinishedSlot"
QT_MOC_LITERAL(8, 121, 17), // "hValueChangedSlot"
QT_MOC_LITERAL(9, 139, 17), // "sValueChangedSlot"
QT_MOC_LITERAL(10, 157, 17), // "vValueChangedSlot"
QT_MOC_LITERAL(11, 175, 17), // "rValueChangedSlot"
QT_MOC_LITERAL(12, 193, 17), // "gValueChangedSlot"
QT_MOC_LITERAL(13, 211, 17), // "bValueChangedSlot"
QT_MOC_LITERAL(14, 229, 14) // "updateEditData"

    },
    "ColorDialog\0colorItemSelcSlot\0\0"
    "addCustomColorSlot\0okBtnClickedSlot\0"
    "cancelBtnClickedSlot\0editChangedSlot\0"
    "editFinishedSlot\0hValueChangedSlot\0"
    "sValueChangedSlot\0vValueChangedSlot\0"
    "rValueChangedSlot\0gValueChangedSlot\0"
    "bValueChangedSlot\0updateEditData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ColorDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       3,    0,   82,    2, 0x08 /* Private */,
       4,    0,   83,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    1,   85,    2, 0x08 /* Private */,
       7,    0,   88,    2, 0x08 /* Private */,
       8,    1,   89,    2, 0x08 /* Private */,
       9,    1,   92,    2, 0x08 /* Private */,
      10,    1,   95,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      12,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      14,    3,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,

       0        // eod
};

void ColorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ColorDialog *_t = static_cast<ColorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->colorItemSelcSlot((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 1: _t->addCustomColorSlot(); break;
        case 2: _t->okBtnClickedSlot(); break;
        case 3: _t->cancelBtnClickedSlot(); break;
        case 4: _t->editChangedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->editFinishedSlot(); break;
        case 6: _t->hValueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sValueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->vValueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->rValueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->gValueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->bValueChangedSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->updateEditData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject ColorDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ColorDialog.data,
      qt_meta_data_ColorDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ColorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ColorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ColorDialog.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ColorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
