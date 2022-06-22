#pragma once

#include <QObject>
#include <QFile>

class GcodeFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString thumbnailPath READ getThumbnailPath NOTIFY thumbnailPathChanged)
    Q_PROPERTY(int size READ getSize NOTIFY sizeChanged)

public:
    GcodeFile(QObject* parent = nullptr);

    void setThumbnailPath(const QString& thumbnailPath);
    QString getThumbnailPath();

    void setSize(const int & size);
    int getSize();

signals:
    void thumbnailPathChanged(QString);
    void sizeChanged(int);

private:
    QString m_thumbnailPath;
    int m_size;
};
