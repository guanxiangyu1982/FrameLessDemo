#include "FrameLessDemo.h"
#include <QtWidgets/QApplication>
#include "DarkStyle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new DarkStyle);
    FrameLessDemo w;
    w.setWindowIcon(a.style()->standardIcon(QStyle::SP_DesktopIcon));
    w.show();
    return a.exec();
}
