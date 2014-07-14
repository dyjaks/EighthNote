#ifndef _SONG_H
#define _SONG_H

#include <QString>
#include <mpd/client.h>

namespace MPD {
  class Song {
  public:
    Song();
    Song(mpd_song * = 0);
   // ~Song();
    
    QString GetArtist(unsigned = 0) const;
    QString GetTitle(unsigned = 0) const;
    QString GetAlbum(unsigned = 0) const;
    
  private:
    std::string ParseFormat(std::string::const_iterator &it, const char *escape_chars) const;
    QString GetTag(mpd_tag_type, unsigned) const;
    QString artist;
    QString title;
    QString album;
    
    mpd_song *mSong;
  };
}


#endif