#pragma once

#include <QString>

namespace FileUtils {

/**
 * @brief Ensures the candidate path is unique, appending a counter if necessary.
 *
 * If a file at `candidate` path already exists, this function appends a
 * counter (e.g., "_001", "_002") to the base name until a unique path is found.
 * It checks against the original path to allow overwriting the source file.
 *
 * @param candidate The desired new file path.
 * @param originalPath The original file path, which is allowed to be overwritten.
 * @return A unique file path.
 */
QString ensureUniqueName(const QString& candidate, const QString& originalPath);

} // namespace FileUtils
