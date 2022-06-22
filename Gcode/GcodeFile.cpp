#include <QtQml>
#include "GcodeFile.h"

GcodeFile::GcodeFile(QObject *parent)
    : QObject(parent)
{

}

void GcodeFile::setThumbnailPath(const QString &thumbnailPath)
{
    if(m_thumbnailPath != thumbnailPath){
        m_thumbnailPath = thumbnailPath;
        emit thumbnailPathChanged(m_thumbnailPath);
    }
}

QString GcodeFile::getThumbnailPath()
{
    return m_thumbnailPath;
}

void GcodeFile::setSize(const int &size)
{
    if(m_size != size){
        m_size = size;
        emit sizeChanged(m_size);
    }
}

int GcodeFile::getSize()
{
    return m_size;
}

namespace{
void registerTypes(){
    qmlRegisterType<GcodeFile>("Zmorph.Interview", 1, 0, "GcodeFile");
}
}
Q_COREAPP_STARTUP_FUNCTION(registerTypes)
