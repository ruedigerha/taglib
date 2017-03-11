
#include <iostream>
#include <iomanip>
#include <string.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#include <tlist.h>
#include <fileref.h>
#include <tfile.h>
#include <tag.h>
#include <tpropertymap.h>

using namespace std;

bool isFile(const char *s)
{
  struct stat st;
#ifdef _WIN32
  return ::stat(s, &st) == 0 && (st.st_mode & (S_IFREG));
#else
  return ::stat(s, &st) == 0 && (st.st_mode & (S_IFREG | S_IFLNK));
#endif
}

void usage()
{
  cout << endl;
  cout << "Usage: copymqatags <source-file> <dest-file>" << endl;
  cout << endl;
}

char const * const ORIGINALSAMPLERATE = "ORIGINALSAMPLERATE";
char const * const MQAENCODER         = "MQAENCODER";
char const * const ENCODEDBY          = "ENCODEDBY";
char const * const ENCODER            = "ENCODER";

int main(int argc, char *argv[])
{
  if (argc != 3 || !isFile(argv[1]) || !isFile(argv[2]))
  {
    usage();
    exit(1);
  }

  TagLib::FileRef src(argv[1]);

  if(!src.isNull() && src.tag()) {
    TagLib::PropertyMap tags = src.file()->properties();
    if (tags.contains(ORIGINALSAMPLERATE) &&
        tags.contains(MQAENCODER))
    {
      TagLib::FileRef dst(argv[2]);

      if(!dst.isNull() && dst.tag())
      {
        TagLib::PropertyMap map = dst.file()->properties();
        map.replace(ORIGINALSAMPLERATE, tags[ORIGINALSAMPLERATE]);
        map.replace(MQAENCODER, tags[MQAENCODER]);
        map.replace(ENCODEDBY, tags[tags.contains(ENCODER) ? ENCODER : MQAENCODER]);
        dst.file()->setProperties(map);
        dst.file()->save();
      }
    }
  }
  return 0;
}
