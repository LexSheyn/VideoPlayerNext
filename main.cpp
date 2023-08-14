#include "WPlayerWidget.h"

#include <QApplication>

qint32 main(qint32 argc, char *argv[])
{
    QApplication application(argc, argv);

    QCoreApplication::setApplicationName("Video Player Next");
    QCoreApplication::setOrganizationName("Next");
    QCoreApplication::setApplicationVersion("0.0.0.1");

    WPlayerWidget* playerWidget = new WPlayerWidget();

    playerWidget->show();

    return application.exec();
}
