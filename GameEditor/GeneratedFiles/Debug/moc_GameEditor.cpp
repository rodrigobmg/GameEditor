/****************************************************************************
** Meta object code from reading C++ file 'GameEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../GameEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameEditor_t {
    QByteArrayData data[15];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameEditor_t qt_meta_stringdata_GameEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "GameEditor"
QT_MOC_LITERAL(1, 11, 31), // "on_actionObjConverter_triggered"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 11), // "AddSGOToMap"
QT_MOC_LITERAL(4, 56, 23), // "StaticGameObjectDbInfo&"
QT_MOC_LITERAL(5, 80, 10), // "gameObject"
QT_MOC_LITERAL(6, 91, 18), // "AddPointLightToMap"
QT_MOC_LITERAL(7, 110, 17), // "PointLightDbInfo&"
QT_MOC_LITERAL(8, 128, 10), // "pointLight"
QT_MOC_LITERAL(9, 139, 34), // "on_editPreferencesAction_trig..."
QT_MOC_LITERAL(10, 174, 30), // "on_actionSnap_to_angle_toggled"
QT_MOC_LITERAL(11, 205, 7), // "checked"
QT_MOC_LITERAL(12, 213, 29), // "on_actionSnap_to_grid_toggled"
QT_MOC_LITERAL(13, 243, 34), // "on_actionUseTestLightining_to..."
QT_MOC_LITERAL(14, 278, 28) // "on_actionShowShadows_toggled"

    },
    "GameEditor\0on_actionObjConverter_triggered\0"
    "\0AddSGOToMap\0StaticGameObjectDbInfo&\0"
    "gameObject\0AddPointLightToMap\0"
    "PointLightDbInfo&\0pointLight\0"
    "on_editPreferencesAction_triggered\0"
    "on_actionSnap_to_angle_toggled\0checked\0"
    "on_actionSnap_to_grid_toggled\0"
    "on_actionUseTestLightining_toggled\0"
    "on_actionShowShadows_toggled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    1,   55,    2, 0x08 /* Private */,
       6,    1,   58,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,
      10,    1,   62,    2, 0x08 /* Private */,
      12,    1,   65,    2, 0x08 /* Private */,
      13,    1,   68,    2, 0x08 /* Private */,
      14,    1,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void GameEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameEditor *_t = static_cast<GameEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionObjConverter_triggered(); break;
        case 1: _t->AddSGOToMap((*reinterpret_cast< StaticGameObjectDbInfo(*)>(_a[1]))); break;
        case 2: _t->AddPointLightToMap((*reinterpret_cast< PointLightDbInfo(*)>(_a[1]))); break;
        case 3: _t->on_editPreferencesAction_triggered(); break;
        case 4: _t->on_actionSnap_to_angle_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_actionSnap_to_grid_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_actionUseTestLightining_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_actionShowShadows_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject GameEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GameEditor.data,
      qt_meta_data_GameEditor,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GameEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameEditor.stringdata0))
        return static_cast<void*>(const_cast< GameEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GameEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
