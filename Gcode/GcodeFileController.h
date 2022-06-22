#pragma once

#include <QObject>
#include <QQmlListProperty>
#include "GcodeFile.h"

class GcodeFileController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<GcodeFile> gcodeFiles READ getGcodeFiles NOTIFY gcodeFilesChanged)
public:
    GcodeFileController(QObject* parent = nullptr);
    QQmlListProperty<GcodeFile> getGcodeFiles();
    void appendGcodeFileToList(GcodeFile* file);

signals:
    void gcodeFilesChanged();

private:
    QList<GcodeFile*> m_gcodeList;
};

