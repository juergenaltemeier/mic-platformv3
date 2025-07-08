// RenamerModule.cpp
#include "RenamerModule.h"

RenamerModule::RenamerModule(QObject *parent)
    : IModule(parent)
{
    emit initialized();
}

QString RenamerModule::id() const
{
    return QStringLiteral("renamer");
}

QString RenamerModule::name() const
{
    return QObject::tr("Image Renamer");
}

QString RenamerModule::qmlSource() const
{
    // Return the path to the QML file for this module
    return "qrc:/qml/RenamerPage.qml";
}
