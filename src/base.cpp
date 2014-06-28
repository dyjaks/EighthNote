#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>

#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.addPlaylistItem("");
    w.show();

    return a.exec();
}