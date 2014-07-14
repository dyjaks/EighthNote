#include "mainwindow.h"
#include <QApplication>
 #include <QTextCodec>
#include <vector>

#include <mpd/client.h>
#include <mpd/status.h>
#include <mpd/entity.h>
#include <mpd/search.h>
#include <mpd/tag.h>
#include "wrapper.h"
#include "song.h"
#include "songQueue.h"

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));
    QApplication a(argc, argv);
    MainWindow w;

    //MPD::Connection mpd;
    MPD::mpdSongList v;
    Mpd.Connect();

    Mpd.GetDirectoryRecursive("", v);


    for (MPD::mpdSongList::const_iterator it = v.begin(); it != v.end(); ++it) {
      w.addPlaylistItem((*it)->GetArtist(), (*it)->GetTitle());
    }

    w.show();

    return a.exec();
}
