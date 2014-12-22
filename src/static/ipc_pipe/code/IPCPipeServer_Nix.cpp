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
#include "IPCPipeServer.h"
#include "IPCManager.h"

namespace IPC
{

PipeServer::PipeServer(const char* name, uint8 numPipes, bool changeAccess)
	: PipeBase(name, gcString("{0}- IPC Server", name).c_str())
	, m_pPipe(new PipeInst())
	, onConnectEvent()
	, onDisconnectEvent()
	, onNeedAuthEvent()
{
	m_pPipe->pIPC = new IPCManager(this, 0, name, true);
	m_pPipe->pIPC->onNeedAuthEvent += delegate(&onNeedAuthEvent);
	m_pPipe->pIPC->setSendEvent(&m_WaitCond);

}

PipeServer::~PipeServer()
{
	stop();
	safe_delete(m_pPipe);
}

void PipeServer::setUpPipes()
{

}

IPCManager* PipeServer::getManager(uint32 i)
{
	return m_pPipe->pIPC;
}

}
