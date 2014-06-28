#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "song.h"

std::string MPD::Song::GetLength(unsigned pos) const
{
  if (pos > 0) {
    return "";
  }
  unsigned len = mpd_song_get_duration(itsSong);
  return !len ? "--:--" : ShowTime(len);
}

std::string MPD::Song::GetName(unsigned pos) const
{
  if (pos > 0) {
    return "";
  }
  
  std::string name = GetTag(MPD_TAG_NAME, 0);
  if (!name.empty()) {
    return name;
  } else {
    return "";
  }
}

std::string MPD::Song::GetArtist(unsigned pos) const
{
  return GetTag(MPD_TAG_ARTIST, pos);
}

std::string MPD::Song::GetTitle(unsigned pos) const
{
  return GetTag(MPD_TAG_TITLE, pos);
}

std::string MPD::Song::GetAlbum(unsigned pos) const
{
  return GetTag(MPD_TAG_ALBUM, pos);
}

std::string MPD::Song::GetTrack(unsigned pos) const
{
  std::string track = GetTag(MPD_TAG_TRACK, pos);
  return (track.length() == 1 && track[0] != '0') || 
	 (track.length() > 3 && track[1] == '/') ? "0" + track : track;
}


std::string MPD::Song::GetTrackNumber(unsigned pos) const
{
  std::string track = GetTag(MPD_TAG_TRACK, pos);
  size_t slash = track.find('/');
  if (slash != std::string::npos) {
    track.resize(slash);
  }
  return track.length() == 1 && track[0] != '0' ? "0"+track : track;
}

std::string MPD::Song::ShowTime(int length)
{
  std::ostringstream ss;

  int hours = length/3600;
  length -= hours*3600;
  int minutes = length/60;
  length -= minutes*60;
  int seconds = length;

  if (hours > 0) {
    ss << hours << ":"
    << std::setw(2) << std::setfill('0') << minutes << ":"
    << std::setw(2) << std::setfill('0') << seconds;
  } else {
    ss << minutes << ":"
    << std::setw(2) << std::setfill('0') << seconds;
  }
  return ss.str();
}

std::string MPD::Song::GetTag(mpd_tag_type type, unsigned pos) const
{
  if (itsTags) {
    TagMap::const_iterator it = itsTags->find(std::make_pair(type, pos));
    if (it != itsTags->end()) {
      return it->second;   
    }
  }
  
  const char *tag = mpd_song_get_tag(itsSong, type, pos);
  return tag ? tag : "";
}