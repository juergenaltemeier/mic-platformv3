#pragma once

#include <QString>
#include <QSet>
#include <QDateTime>
#include <QFileInfo>
#include <QDate>

// Corresponds to the RenameConfig class in Python
struct RenameConfig {
    QString dateFormat = "%y%m%d";
    int indexPadding = 3;
    QString separator = "_";
    int startIndex = 1;
};

// Corresponds to the ItemSettings class in Python
struct ItemSettings {
    QString originalPath;
    QSet<QString> tags;
    QString suffix;
    QString date;
    QString position;
    QString pa_mat; // for PA_MAT mode
    qint64 sizeBytes = 0;
    qint64 compressedBytes = 0;

    // Helper to get a date string, falling back to now() if empty
    QString getDateString(const RenameConfig& config) const {
        if (!date.isEmpty() && QDate::fromString(date, "yyMMdd").isValid()) {
            return date;
        }
        return QDateTime::currentDateTime().toString(config.dateFormat);
    }

    // Builds the base part of the filename before index/suffix
    QString buildBaseName(const QString& project, const QList<QString>& orderedTags, const RenameConfig& config) const {
        QStringList parts;
        parts << project;
        parts.append(orderedTags);
        parts << getDateString(config);
        return parts.join(config.separator);
    }

    // Builds the final new filename
    QString buildNewName(const QString& project, int index, const QList<QString>& orderedTags, const RenameConfig& config, bool includeIndex = true) const {
        QString base = buildBaseName(project, orderedTags, config);
        QString name = base;
        if (includeIndex) {
            name += QString("%1%2").arg(config.separator).arg(index, config.indexPadding, 10, QChar('0'));
        }
        if (!suffix.isEmpty()) {
            name += config.separator + suffix;
        }
        QFileInfo fileInfo(originalPath);
        name += "." + fileInfo.suffix();
        return name;
    }
};
