/*
Copyright (C) 2011 Mark Chandler (Desura Net Pty Ltd)
Copyright (C) 2014 Bad Juju Games, Inc.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.

Contact us at legal@badjuju.com.
*/


#ifndef DESURA_NEWSITEM_H
#define DESURA_NEWSITEM_H
#ifdef _WIN32
#pragma once
#endif

namespace UserCore
{
	namespace Misc
	{

		//! Container class that stores information for one news item
		class NewsItem : public gcRefBase
		{
		public:
			//! Constructor
			//!
			//! @param i News item id
			//! @param c News item category
			//! @param t Title
			//! @param u Url
			//!
			NewsItem(uint32 i, uint8 c, const char* t, const char* u)
			: id(i)
			, cat(c)
			, szTitle(t)
			, szUrl(u)
			, hasBeenShown(false)
			{
			}

			//! Copy Constructor
			//!
			//! @param item In NewsItem
			NewsItem(NewsItem* item)
			: id(0)
			, cat(0)
			, szTitle("")
			, szUrl("")
			, hasBeenShown(false)
			{
				if (item)
				{
					id = item->id;
					cat = item->cat;
					szTitle = item->szTitle;
					szUrl = item->szUrl;

					hasBeenShown = item->hasBeenShown;
				}
			}

			uint32 id;
			uint8 cat;
			gcString szTitle;
			gcString szUrl;

			bool hasBeenShown;

			gc_IMPLEMENT_REFCOUNTING(NewsItem)
		};

	}
}

#endif //DESURA_NEWSITEM_H
