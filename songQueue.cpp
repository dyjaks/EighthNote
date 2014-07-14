#include "songQueue.h"


MPD::songQueue::songQueue() : currentPlaylist() { }

MPD::songQueue::~songQueue() {
        currentPlaylist.clear();
}

bool MPD::songQueue::addToQueue(mpdSongList v) {
    for (MPD::mpdSongList::const_iterator it = v.begin(); it != v.end(); ++it) {
        currentPlaylist.push_back((*it));
    }

    return true;
}

//bool removeFromQueue(mpdSongList v);
//bool removeFromQueue(int i);
