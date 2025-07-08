// RenamerModule.h
#pragma once

#include "IModule.h"
#include <QObject>
#include <QUrl>
#include <QString>

class RenamerModule : public IModule
{
    Q_OBJECT

public:
    explicit RenamerModule(QObject *parent = nullptr);

    QString id() const override;
    QString name() const override;
    QString qmlSource() const override;

signals:
    void initialized();
};
