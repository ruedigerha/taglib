# TagLib (MQA Edition)

This fork of taglib is only of interest to you if you - like me - want to
transcode your MQA music to ALAC so that you can drop the files into
iTunes and sync them to your iPhone.

MQA files use some particular tags (`ENCODER`, `MQAENCODER` and
`ORIGNALSAMPLERATE`), the latter two are currently not supported by most
metadata tools. These tags are usually lost when transcoding.

In this fork I've simply added recognition of these tags in MP4 files, and
a small tool `copymqatags` (built by default) that will copy them (if they
exist) from the original MQA file (usually FLAC) to the transcoded ALAC
file.

Note that the `ENCODER` value is placed into `ENCODEDBY`. This seems to be
the equivalent MP4 tag for this value. The software I use can deal with
that, others may have problems. Let me know if any program absolutely
requires `ENCODER` here.

### TagLib Audio Meta-Data Library

http://taglib.org/

TagLib is a library for reading and editing the meta-data of several
popular audio formats. Currently it supports both ID3v1 and [ID3v2][]
for MP3 files, [Ogg Vorbis][] comments and ID3 tags and Vorbis comments
in [FLAC][], MPC, Speex, WavPack, TrueAudio, WAV, AIFF, MP4 and ASF
files.

TagLib is distributed under the [GNU Lesser General Public License][]
(LGPL) and [Mozilla Public License][] (MPL). Essentially that means that
it may be used in proprietary applications, but if changes are made to
TagLib they must be contributed back to the project. Please review the
licenses if you are considering using TagLib in your project.

  [ID3v2]: http://www.id3.org 
  [Ogg Vorbis]: http://vorbis.com/
  [FLAC]: https://xiph.org/flac/
  [GNU Lesser General Public License]: http://www.gnu.org/licenses/lgpl.html
  [Mozilla Public License]: http://www.mozilla.org/MPL/MPL-1.1.html

