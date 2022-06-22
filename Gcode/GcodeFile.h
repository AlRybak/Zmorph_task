#pragma once

#include <QObject>
#include <QFile>

class GcodeFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString thumbnailPath READ getThumbnailPath NOTIFY thumbnailPathChanged)

public:
    GcodeFile(QObject* parent = nullptr);
    void setThumbnailPath(const QString& thumbnailPath);

    QString getThumbnailPath();

signals:
    void thumbnailPathChanged(QString);

private:
    QString m_thumbnailPath;
};
