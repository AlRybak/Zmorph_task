#include "GcodeFileController.h"
#include <QtQml>
#include <QtDebug>
#include <QDir>
//#include <QFile

GcodeFileController::GcodeFileController(QObject *parent)
    : QObject(parent)
{
    QDir dir("test_data");
    auto fileList = dir.entryInfoList({"*.png"});
    for(auto& file : fileList){
        auto gcode = new GcodeFile();
        gcode->setThumbnailPath(QString("file:///%1").arg(file.absoluteFilePath()));
        appendGcodeFileToList(gcode);
    }
}

QQmlListProperty<GcodeFile> GcodeFileController::getGcodeFiles()
{
    return QQmlListProperty<GcodeFile>(this, m_gcodeList);
}

void GcodeFileController::appendGcodeFileToList(GcodeFile *file)
{
    m_gcodeList.append(file);
    emit gcodeFilesChanged();
}
