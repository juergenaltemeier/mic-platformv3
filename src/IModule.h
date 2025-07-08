#pragma once

#include <QObject>
#include <QString>

class IModule : public QObject {
    Q_OBJECT
public:
    using QObject::QObject;
    virtual ~IModule() = default;

    virtual QString id() const = 0;
    virtual QString name() const = 0;
    virtual QString qmlSource() const = 0;
};
