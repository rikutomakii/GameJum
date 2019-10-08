/* Exit Games Photon - C++ Client Lib
 * Copyright (C) 2004-2018 by Exit Games GmbH. All rights reserved.
 * http://www.photonengine.com
 * mailto:developer@photonengine.com
 */

#pragma once

#include "Common-cpp/inc/Common.h"

#if defined _EG_WINDOWSSTORE_PLATFORM || defined _EG_XB1_PLATFORM
#	define _EG_WEBSOCKET_AVAILABLE
#endif

namespace ExitGames
{
	namespace Photon
	{
		/** These are the options that can be used as underlying transport protocol.*/
		namespace ConnectionProtocol
		{
#ifndef _EG_EMSCRIPTEN_PLATFORM
			static const nByte UDP = 0; ///<Use UDP to connect to Photon, which allows you to send operations reliable or unreliable on demand.
#endif
#if !defined _EG_EMSCRIPTEN_PLATFORM && !defined _EG_XB1_PLATFORM
			static const nByte TCP     = 1; ///<Use TCP to connect to Photon.
#endif
#if defined _EG_EMSCRIPTEN_PLATFORM || defined _EG_WEBSOCKET_AVAILABLE || defined EG_DOC
#	if !defined _EG_XB1_PLATFORM
			static const nByte WS      = 4; ///<Use websockets to connect to Photon.
#	endif
			static const nByte WSS     = 5; ///<Use secure websockets to connect to Photon.
#endif
#ifdef _EG_EMSCRIPTEN_PLATFORM
			static const nByte DEFAULT = WS;
#elif defined _EG_XB1_PLATFORM
			static const nByte DEFAULT = WSS;
#else
			static const nByte DEFAULT = UDP;
#endif

			bool getIsUDP(nByte connectionProtocol);
			bool getIsTCP(nByte connectionProtocol);
			bool getIsWebSocket(nByte connectionProtocol);
			bool getIsSecure(nByte connectionProtocol);
		}
	}
}