#include "wrapper.h"

#include <assert.h>
#include <stdio.h>
#include <QString>

MPD::Connection Mpd;

MPD::Connection::Connection() :
   itsConnection(0)
  ,itsHost("localhost")
  ,itsPort(6600)
  ,itsCurrentStatus(0)
  ,isIdle(0) { }
  
MPD::Connection::~Connection() {
  if (itsConnection)
    mpd_connection_free(itsConnection);
  if (itsCurrentStatus)
    mpd_status_free(itsCurrentStatus);
}

bool MPD::Connection::Connect() {
  if (itsConnection)
    return true;
  
  itsConnection = mpd_connection_new(itsHost.c_str(), itsPort, 30000);
  
  return true;
}

bool MPD::Connection::Connected() const {
  return itsConnection;
}

void MPD::Connection::Disconnect() {
  if (itsConnection)
    mpd_connection_free(itsConnection);
  if (itsCurrentStatus)
    mpd_status_free(itsCurrentStatus);
  
  itsConnection = 0;
  itsCurrentStatus = 0;
  isIdle = 0;
}

void MPD::Connection::Play() {
  if (itsConnection) {
      mpd_send_play(itsConnection);
      mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::Play(int pos) {
  if (itsConnection) {
      mpd_send_play_pos(itsConnection, pos);
      mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::PlayById(int id) {
  if (itsConnection) {
      mpd_send_play_pos(itsConnection, id);
      mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::Pause(bool state) {
  if (itsConnection) {
      mpd_send_pause(itsConnection, state);
      mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::Toggle() {
  if (itsConnection) {
    if (isPlaying()) {
      mpd_run_toggle_pause(itsConnection);
      mpd_recv_idle(itsConnection, 15000);
    } else {
      mpd_send_play(itsConnection);
      mpd_recv_idle(itsConnection, 15000);
    }
  }
}

void MPD::Connection::Stop() {
  if (itsConnection) {
    mpd_send_stop(itsConnection);
    mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::Prev() {
  if (itsConnection) {
    mpd_send_previous(itsConnection);
    mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::Next() {
  if (itsConnection) {
    mpd_send_next(itsConnection);
    mpd_recv_idle(itsConnection, 15000);
  }
}

void MPD::Connection::GetDirectoryRecursive(const std::string &path, mpdSongList &v) {
  if (!itsConnection)
    return;

  //mpd_send_list_all_meta(itsConnection, path.c_str());
  mpd_send_list_queue_meta(itsConnection);

  while (mpd_song *s = mpd_recv_song(itsConnection)) {
    v.push_back(new Song(s));
  }
  mpd_response_finish(itsConnection);
}

void MPD::Connection::Delete(int pos) {
    mpd_run_delete(itsConnection, pos);
}
