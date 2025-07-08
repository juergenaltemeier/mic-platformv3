#include "Renamer.h"
#include "../utils/FileUtils.h"
#include <QFileInfo>
#include <QMap>
#include <algorithm>

Renamer::Renamer(const QString& project, const QList<ItemSettings>& items,
                 const RenameConfig& config, const QString& destDir, const QString& mode)
    : m_project(project), m_items(items), m_destDir(destDir), m_config(config), m_mode(mode) {}

QList<QPair<ItemSettings, QString>> Renamer::buildMapping() {
    QList<QPair<ItemSettings, QString>> mapping;

    if (m_mode == "position") {
        for (const auto& item : m_items) {
            QString base = m_project + "_pos";
            if (!item.suffix.isEmpty()) {
                base += "_" + item.suffix;
            }
            QFileInfo fileInfo(item.originalPath);
            QString newBasename = base + "." + fileInfo.suffix();
            QString dirPath = m_destDir.isEmpty() ? fileInfo.path() : m_destDir;
            QString candidate = dirPath + "/" + newBasename;
            QString uniqueName = FileUtils::ensureUniqueName(candidate, item.originalPath);
            mapping.append({item, uniqueName});
        }
        return mapping;
    }

    if (m_mode == "pa_mat") {
        QMap<QString, QList<ItemSettings>> groups;
        for (const auto& item : m_items) {
            groups[item.date].append(item);
        }

        for (auto it = groups.constBegin(); it != groups.constEnd(); ++it) {
            const QList<ItemSettings>& itemsInGroup = it.value();
            bool useIndex = itemsInGroup.size() > 1;
            int counter = m_config.startIndex;
            for (const auto& item : itemsInGroup) {
                QString base = QString("%1_PA_MAT_%2").arg(m_project).arg(item.date);
                if (useIndex) {
                    base += QString("_%1").arg(counter, 2, 10, QChar('0'));
                    counter++;
                }
                if (!item.suffix.isEmpty()) {
                    base += "_" + item.suffix;
                }
                QFileInfo fileInfo(item.originalPath);
                QString newBasename = base + "." + fileInfo.suffix();
                QString dirPath = m_destDir.isEmpty() ? fileInfo.path() : m_destDir;
                QString candidate = dirPath + "/" + newBasename;
                QString uniqueName = FileUtils::ensureUniqueName(candidate, item.originalPath);
                mapping.append({item, uniqueName});
            }
        }
        return mapping;
    }

    // Normal mode
    QMap<QString, QList<QPair<ItemSettings, QList<QString>>>> groups;
    for (const auto& item : m_items) {
        QList<QString> orderedTags = item.tags.values();
        std::sort(orderedTags.begin(), orderedTags.end());
        QString base = item.buildBaseName(m_project, orderedTags, m_config);
        groups[base].append({item, orderedTags});
    }

    for (auto it = groups.constBegin(); it != groups.constEnd(); ++it) {
        const auto& itemsInGroup = it.value();
        bool useIndex = itemsInGroup.size() > 1;
        int counter = m_config.startIndex;
        for (const auto& itemPair : itemsInGroup) {
            const ItemSettings& item = itemPair.first;
            const QList<QString>& orderedTags = itemPair.second;
            QString newBasename = item.buildNewName(m_project, counter, orderedTags, m_config, useIndex);
            if (useIndex) {
                counter++;
            }
            QFileInfo fileInfo(item.originalPath);
            QString dirPath = m_destDir.isEmpty() ? fileInfo.path() : m_destDir;
            QString candidate = dirPath + "/" + newBasename;
            QString uniqueName = FileUtils::ensureUniqueName(candidate, item.originalPath);
            mapping.append({item, uniqueName});
        }
    }

    return mapping;
}
