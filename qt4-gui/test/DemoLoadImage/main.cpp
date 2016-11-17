#include "qt4-gui/LoadImage.h"
#include <QApplication>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );
    LoadImage li;
    li.show();

    return a.exec();
}
