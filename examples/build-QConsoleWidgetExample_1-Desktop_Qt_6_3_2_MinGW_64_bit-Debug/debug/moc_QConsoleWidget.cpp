/****************************************************************************
** Meta object code from reading C++ file 'QConsoleWidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QConsoleWidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QConsoleWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget_t {
    uint offsetsAndSizes[22];
    char stringdata0[37];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[15];
    char stringdata5[12];
    char stringdata6[16];
    char stringdata7[10];
    char stringdata8[18];
    char stringdata9[4];
    char stringdata10[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget_t qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget = {
    {
        QT_MOC_LITERAL(0, 36),  // "AntonaQConsoleWidget::QConsol..."
        QT_MOC_LITERAL(37, 17),  // "setUserInputColor"
        QT_MOC_LITERAL(55, 0),  // ""
        QT_MOC_LITERAL(56, 5),  // "color"
        QT_MOC_LITERAL(62, 14),  // "setOutputColor"
        QT_MOC_LITERAL(77, 11),  // "setErrColor"
        QT_MOC_LITERAL(89, 15),  // "slot_outputChar"
        QT_MOC_LITERAL(105, 9),  // "char_code"
        QT_MOC_LITERAL(115, 17),  // "slot_outputString"
        QT_MOC_LITERAL(133, 3),  // "str"
        QT_MOC_LITERAL(137, 18)   // "slot_clearContents"
    },
    "AntonaQConsoleWidget::QConsoleWidget",
    "setUserInputColor",
    "",
    "color",
    "setOutputColor",
    "setErrColor",
    "slot_outputChar",
    "char_code",
    "slot_outputString",
    "str",
    "slot_clearContents"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AntonaQConsoleWidget__QConsoleWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x0a,    1 /* Public */,
       4,    1,   53,    2, 0x0a,    3 /* Public */,
       5,    1,   56,    2, 0x0a,    5 /* Public */,
       6,    2,   59,    2, 0x0a,    7 /* Public */,
       8,    2,   64,    2, 0x0a,   10 /* Public */,
      10,    0,   69,    2, 0x0a,   13 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::QColor,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QColor,    7,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    9,    3,
    QMetaType::Void,

       0        // eod
};

void AntonaQConsoleWidget::QConsoleWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QConsoleWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setUserInputColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 1: _t->setOutputColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 2: _t->setErrColor((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        case 3: _t->slot_outputChar((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 4: _t->slot_outputString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 5: _t->slot_clearContents(); break;
        default: ;
        }
    }
}

const QMetaObject AntonaQConsoleWidget::QConsoleWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QPlainTextEdit::staticMetaObject>(),
    qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget.offsetsAndSizes,
    qt_meta_data_AntonaQConsoleWidget__QConsoleWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget_t
, QtPrivate::TypeAndForceComplete<QConsoleWidget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QColor &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AntonaQConsoleWidget::QConsoleWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AntonaQConsoleWidget::QConsoleWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AntonaQConsoleWidget__QConsoleWidget.stringdata0))
        return static_cast<void*>(this);
    return QPlainTextEdit::qt_metacast(_clname);
}

int AntonaQConsoleWidget::QConsoleWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
