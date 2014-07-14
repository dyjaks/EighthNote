#ifndef SONGQUEUE_H
#define SONGQUEUE_H

#include "song.h"
#include <vector>

namespace MPD {

    typedef std::vector<Song *> mpdSongList;

    class songQueue {
    public:
        songQueue();
        ~songQueue();

        mpdSongList getCurrentQueue() { return currentPlaylist; }
        bool addToQueue(mpdSongList v);
        bool removeFromQueue(mpdSongList v);
        bool removeFromQueue(int i);

    private:
        mpdSongList currentPlaylist;
        int selected;

    };
}

#endif
