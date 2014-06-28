#ifndef _SONG_H
#define _SONG_H

#include <map>
#include <string>

#include <mpd/client.h>

namespace MPD {
  class Song {
    typedef std::map<std::pair<mpd_tag_type, unsigned>, std::string> TagMap;
    
  public:
    typedef void (Song::*SetFunction)(const std::string &, unsigned);
    typedef std::string (Song::*GetFunction)(unsigned) const;
    
    Song(mpd_song * = 0, bool = 0);
    Song(const Song &);
    ~Song();
    
    std::string GetName(unsigned = 0) const;
    std::string GetArtist(unsigned = 0) const;
    std::string GetTitle(unsigned = 0) const;
    std::string GetAlbum(unsigned = 0) const;
    std::string GetAlbumArtist(unsigned = 0) const; 
    std::string GetTrack(unsigned = 0) const;
    std::string GetTrackNumber(unsigned = 0) const;
    std::string GetLength(unsigned = 0) const;
    
    std::string GetTags(GetFunction) const;
    
    //unsigned GetHash() const { return itsHash; }
    unsigned GetTotalLength() const { return mpd_song_get_duration(itsSong); }
    unsigned GetPosition() const { return mpd_song_get_pos(itsSong); }
    unsigned GetID() const { return mpd_song_get_id(itsSong); }
    
    static std::string ShowTime(int);
    
  private:
    std::string GetTag(mpd_tag_type, unsigned) const;
    const char *MyFileName() const;
    
    mpd_song *itsSong;
    TagMap *itsTags;
    
  };
}

#endif