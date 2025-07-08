#pragma once

#include "Settings.h"
#include <QString>
#include <QList>
#include <QPair>

class Renamer {
public:
    Renamer(const QString& project, const QList<ItemSettings>& items,
            const RenameConfig& config = RenameConfig(),
            const QString& destDir = QString(),
            const QString& mode = "normal");

    // Returns a list of tuples: (original_settings, original_path, new_path)
    QList<QPair<ItemSettings, QString>> buildMapping();

private:
    QString m_project;
    QList<ItemSettings> m_items;
    QString m_destDir;
    RenameConfig m_config;
    QString m_mode;
};
