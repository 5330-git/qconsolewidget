/****************************************************************************
** Meta object code from reading C++ file 'QConsoleWidgetBuffer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../QConsoleWidgetBuffer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QConsoleWidgetBuffer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer_t {
    uint offsetsAndSizes[16];
    char stringdata0[39];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[2];
    char stringdata5[6];
    char stringdata6[15];
    char stringdata7[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer_t qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer = {
    {
        QT_MOC_LITERAL(0, 38),  // "AntonaQConsoleWidget::Console..."
        QT_MOC_LITERAL(39, 12),  // "sig_output_c"
        QT_MOC_LITERAL(52, 0),  // ""
        QT_MOC_LITERAL(53, 24),  // "std::streambuf::int_type"
        QT_MOC_LITERAL(78, 1),  // "c"
        QT_MOC_LITERAL(80, 5),  // "color"
        QT_MOC_LITERAL(86, 14),  // "sig_output_str"
        QT_MOC_LITERAL(101, 3)   // "str"
    },
    "AntonaQConsoleWidget::ConsoleOutBuffer",
    "sig_output_c",
    "",
    "std::streambuf::int_type",
    "c",
    "color",
    "sig_output_str",
    "str"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AntonaQConsoleWidget__ConsoleOutBuffer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,
       6,    2,   31,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QColor,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QColor,    7,    5,

       0        // eod
};

void AntonaQConsoleWidget::ConsoleOutBuffer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConsoleOutBuffer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_output_c((*reinterpret_cast< std::add_pointer_t<std::streambuf::int_type>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        case 1: _t->sig_output_str((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QColor>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConsoleOutBuffer::*)(std::streambuf::int_type , QColor );
            if (_t _q_method = &ConsoleOutBuffer::sig_output_c; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ConsoleOutBuffer::*)(QString , QColor );
            if (_t _q_method = &ConsoleOutBuffer::sig_output_str; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AntonaQConsoleWidget::ConsoleOutBuffer::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer.offsetsAndSizes,
    qt_meta_data_AntonaQConsoleWidget__ConsoleOutBuffer,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer_t
, QtPrivate::TypeAndForceComplete<ConsoleOutBuffer, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::streambuf::int_type, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QColor, std::false_type>



>,
    nullptr
} };


const QMetaObject *AntonaQConsoleWidget::ConsoleOutBuffer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AntonaQConsoleWidget::ConsoleOutBuffer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AntonaQConsoleWidget__ConsoleOutBuffer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "std::streambuf"))
        return static_cast< std::streambuf*>(this);
    return QObject::qt_metacast(_clname);
}

int AntonaQConsoleWidget::ConsoleOutBuffer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AntonaQConsoleWidget::ConsoleOutBuffer::sig_output_c(std::streambuf::int_type _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AntonaQConsoleWidget::ConsoleOutBuffer::sig_output_str(QString _t1, QColor _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
