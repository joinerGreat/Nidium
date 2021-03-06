/*
   Copyright 2016 Nidium Inc. All rights reserved.
   Use of this source code is governed by a MIT license
   that can be found in the LICENSE file.
*/
#ifndef io_embedstream_h__
#define io_embedstream_h__

#include <string>

#include "IO/FileStream.h"
#include "IO/NFSStream.h"

#include "Interface/SystemInterface.h"

namespace Nidium {
namespace IO {

#ifndef NIDIUM_PACKAGE_EMBED

class EmbedStream : public IO::FileStream
{
public:
    explicit EmbedStream(const char *location) : IO::FileStream(location)
    {
    }

    static IO::Stream *CreateStream(const char *location)
    {
        return new EmbedStream(location);
    }

    static bool AllowLocalFileStream()
    {
        return true;
    }

    static bool AllowSyncStream()
    {
        return true;
    }

    static const char *GetBaseDir()
    {
        return Interface::SystemInterface::GetInstance()->getEmbedDirectory();
    }
};

#else

class EmbedStream : public IO::NFSStream
{
public:
    explicit EmbedStream(const char *location) : NFSStream(location)
    {
    }

    static IO::Stream *CreateStream(const char *location)
    {
        return new EmbedStream(location);
    }

    static bool AllowLocalFileStream()
    {
        return true;
    }

    static bool AllowSyncStream()
    {
        return true;
    }

    static const char *GetBaseDir()
    {
        return "/";
    }
};

#endif

} // namespace IO
} // namespace Nidium

#endif
