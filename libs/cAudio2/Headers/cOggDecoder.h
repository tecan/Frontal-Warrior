// Copyright (c) 2008-2010 Raynaldo (Wildicv) Rivera, Joshua (Dark_Kilauea) Jones
// This file is part of the "cAudio Engine"
// For conditions of distribution and use, see copyright notice in cAudio.h

#ifndef COGGDECODER_H_INCLUDED
#define COGGDECODER_H_INCLUDED

#include "../include/cAudioDefines.h"

#ifdef CAUDIO_COMPILE_WITH_OGG_DECODER

#include "../include/IAudioDecoder.h"
#include <ogg/ogg.h>
#include <vorbis/codec.h>
#include <vorbis/vorbisenc.h>
#include <vorbis/vorbisfile.h>

namespace cAudio
{

    class cOggDecoder : public IAudioDecoder
    {
        public:

            cOggDecoder(IDataSource* stream);
            ~cOggDecoder();

            virtual AudioFormats getFormat();
            virtual int getFrequency();
            virtual bool isSeekingSupported();
			virtual bool isValid();
            virtual int readAudioData(void* output, int amount);
            virtual bool setPosition(int position, bool relative);
            virtual bool seek(float seconds,bool relative);
			virtual float getTotalTime();
			virtual int getTotalSize();
			virtual int getCompressedSize();
			virtual float getCurrentTime();
			virtual int getCurrentPosition();
			virtual int getCurrentCompressedPosition();

        protected:
       	    //! Callbacks used for read memory
            ov_callbacks vorbisCallbacks;
			//! Format information
            vorbis_info* vorbisInfo;
			//! User Comments
            vorbis_comment* vorbisComment;
			//! Stream handle
            OggVorbis_File oggStream; 
			bool Valid;
    };

}

#endif

#endif //! COGGDECODER_H_INCLUDED
