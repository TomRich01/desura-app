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

#include "Common.h"
#include "WindowManager.h"
#include <wx/wx.h>

namespace Managers
{

void LoadTheme(wxWindow* win, const char* name)
{
	Color bg = GetThemeManager().getColor(name, "bg");
	Color fg = GetThemeManager().getColor(name, "fg");

	win->SetForegroundColour(wxColor(fg));
	win->SetBackgroundColour(wxColor(bg));
}

}


WindowItem::WindowItem(wxFrame* frame)
	: BaseItem()
{
	m_uiHash = frame->GetId();
	m_pFrame = frame;
}

WindowManager::WindowManager()
	: BaseManager()
{

}

void WindowManager::registerWindow(wxFrame* win)
{
	if (win)
		addItem(gcRefPtr<WindowItem>::create(win));
}

void WindowManager::unRegisterWindow(wxFrame* win)
{
	if (win)
		removeItem(win->GetId());
}

void WindowManager::getWindowList(std::vector<wxFrame*> &vList)
{
	for (uint32 x=0; x<getCount(); x++)
		vList.push_back(getItem(x)->m_pFrame);

	std::sort(vList.begin(), vList.end(), [](wxFrame* lhs, wxFrame* rhs){
		return wcscmp(lhs->GetTitle().c_str(), rhs->GetTitle().c_str())>0;
	});
}

