/****************************************************************************
** Meta object code from reading C++ file 'ShowMOForm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ShowMOForm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShowMOForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ShowMOForm_t {
    QByteArrayData data[11];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowMOForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowMOForm_t qt_meta_stringdata_ShowMOForm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ShowMOForm"
QT_MOC_LITERAL(1, 11, 12), // "onCentralize"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "onClear"
QT_MOC_LITERAL(4, 33, 9), // "onAddAtom"
QT_MOC_LITERAL(5, 43, 8), // "onRotate"
QT_MOC_LITERAL(6, 52, 11), // "onTranslate"
QT_MOC_LITERAL(7, 64, 13), // "onAddMolecule"
QT_MOC_LITERAL(8, 78, 7), // "onReset"
QT_MOC_LITERAL(9, 86, 7), // "onClose"
QT_MOC_LITERAL(10, 94, 28) // "on_pushButton_import_clicked"

    },
    "ShowMOForm\0onCentralize\0\0onClear\0"
    "onAddAtom\0onRotate\0onTranslate\0"
    "onAddMolecule\0onReset\0onClose\0"
    "on_pushButton_import_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowMOForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
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

void ShowMOForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShowMOForm *_t = static_cast<ShowMOForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCentralize(); break;
        case 1: _t->onClear(); break;
        case 2: _t->onAddAtom(); break;
        case 3: _t->onRotate(); break;
        case 4: _t->onTranslate(); break;
        case 5: _t->onAddMolecule(); break;
        case 6: _t->onReset(); break;
        case 7: _t->onClose(); break;
        case 8: _t->on_pushButton_import_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ShowMOForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ShowMOForm.data,
      qt_meta_data_ShowMOForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ShowMOForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowMOForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ShowMOForm.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ShowMOForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
