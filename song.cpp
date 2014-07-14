#include "song.h"

MPD::Song::Song(mpd_song *s) : mSong(s) { }

QString MPD::Song::GetArtist(unsigned pos) const {
  return GetTag(MPD_TAG_ARTIST, pos);
}

QString MPD::Song::GetTitle(unsigned pos) const {
  return GetTag(MPD_TAG_TITLE, pos);
}

QString MPD::Song::GetAlbum(unsigned pos) const {
  return GetTag(MPD_TAG_ALBUM, pos);
}

QString MPD::Song::GetTag(mpd_tag_type type, unsigned pos) const
{
/*	if (itsTags)
	{
		TagMap::const_iterator it = itsTags->find(std::make_pair(type, pos));
		if (it != itsTags->end())
			return it->second;
	}*/
	const char *tag = mpd_song_get_tag(mSong, type, pos);
	return tag ? tag : "";
}
