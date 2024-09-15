/****************************************************************************
** Meta object code from reading C++ file 'QDataViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QDataViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QDataViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QDataViewer_t {
    QByteArrayData data[7];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QDataViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QDataViewer_t qt_meta_stringdata_QDataViewer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QDataViewer"
QT_MOC_LITERAL(1, 12, 30), // "on_actionsaveProject_triggered"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 30), // "on_actionloadProject_triggered"
QT_MOC_LITERAL(4, 75, 33), // "on_actionaddVectorLayer_trigg..."
QT_MOC_LITERAL(5, 109, 33), // "on_actionaddRasterLayer_trigg..."
QT_MOC_LITERAL(6, 143, 30) // "on_actionremoveLayer_triggered"

    },
    "QDataViewer\0on_actionsaveProject_triggered\0"
    "\0on_actionloadProject_triggered\0"
    "on_actionaddVectorLayer_triggered\0"
    "on_actionaddRasterLayer_triggered\0"
    "on_actionremoveLayer_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QDataViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QDataViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QDataViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionsaveProject_triggered(); break;
        case 1: _t->on_actionloadProject_triggered(); break;
        case 2: _t->on_actionaddVectorLayer_triggered(); break;
        case 3: _t->on_actionaddRasterLayer_triggered(); break;
        case 4: _t->on_actionremoveLayer_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject QDataViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QDataViewer.data,
    qt_meta_data_QDataViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QDataViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QDataViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QDataViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QDataViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
