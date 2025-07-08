#include "FileUtils.h"
#include <QFileInfo>

namespace FileUtils {

QString ensureUniqueName(const QString& candidate, const QString& originalPath) {
    QFileInfo candidateInfo(candidate);
    QString baseName = candidateInfo.path() + "/" + candidateInfo.completeBaseName();
    QString suffix = "." + candidateInfo.suffix();

    QString newPath = candidate;
    int counter = 1;

    while (QFileInfo(newPath).exists() && QFileInfo(newPath).absoluteFilePath() != QFileInfo(originalPath).absoluteFilePath()) {
        newPath = QString("%1_%2%3").arg(baseName).arg(counter, 3, 10, QChar('0')).arg(suffix);
        counter++;
    }

    return newPath;
}

} // namespace FileUtils
