#ifndef _WRAPPER_H
#define _WRAPPER_H

#include <vector>
#include <cassert>
#include <exception>
#include <mpd/client.h>
#include "song.h"
#include "songQueue.h"

namespace MPD {
  enum PlayerState {unknown, stopped, playing, paused};
  
  struct StatusChanges {
    StatusChanges() : Playlist(0)
		      ,SongID(0)
		      ,Database(0)
		      ,DBUpdating(0)
		      ,Volume(0)
		      ,ElapsedTime(0)
		      ,Crossfade(0)
		      ,Random(0)
		      ,Repeat(0)
		      ,Single(0)
		      ,Consume(0)
		      ,PlayerState(0)
		      ,StatusFlags(0)
		      ,Outputs(0) { }
    bool Playlist:1;
    bool SongID:1;
    bool Database:1;
    bool DBUpdating:1;
    bool Volume:1;
    bool ElapsedTime:1;
    bool Crossfade:1;
    bool Random:1;
    bool Repeat:1;
    bool Single:1;
    bool Consume:1;
    bool PlayerState:1;
    bool StatusFlags:1;
    bool Outputs:1; 
  };
  
  class Connection {
    typedef void (*StatusUpdater) (Connection *, StatusChanges, void *);
    typedef void (*ErrorHandler) (Connection *, int, const char *, void *);
    
  public:
    Connection();
    ~Connection();
    
    bool Connect();
    bool Connected() const;
    void Disconnect();
    
    const std::string & GetHostName() {return itsHost;}
    int GetPort() {return itsPort;}
    
    void UpdateStatus();
    
    void Play();
    void Play(int);
    void PlayById(int);
    void Pause(bool);
    void Toggle();
    void Stop();
    void Prev();
    void Next();
    void Seek(unsigned);

    //temp
    void Delete(int);
    
    PlayerState GetState() const {return itsCurrentStatus ? PlayerState(mpd_status_get_state(itsCurrentStatus)) : unknown;}
    bool isPlaying() const {return GetState() > stopped;}
    
    Song GetCurrentlyPlayingSong();
    int GetCurrentlyPlayingSongPos() const;
    int GetCurrentSongPos() const;
    
    void GetDirectoryRecursive(const std::string &, mpdSongList &);

  private:
    mpd_connection *itsConnection;
    songQueue mQueue;
    std::string itsHost;
    int itsPort;
    int isIdle;
    
    mpd_status *itsCurrentStatus;
    
  };
}

extern MPD::Connection Mpd;

#endif
