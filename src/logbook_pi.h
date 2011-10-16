/******************************************************************************
 * $Id: logbookkonni_pi.h,v 1.8 2010/06/21 01:54:37 bdbcat Exp $
 *
 * Project:  OpenCPN
 * Purpose:  DEMO Plugin
 * Author:   David Register
 *
 ***************************************************************************
 *   Copyright (C) 2010 by David S. Register   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */

#ifndef _LOGBOOKPIKONNI_H_
#define _LOGBOOKPIKONNI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    908

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    5



#include "../../../include/ocpn_plugin.h"
#include "nmea0183/nmea0183.h"

#include <wx/aui/aui.h>
#include <wx/string.h>
#include <wx/settings.h>
#include <wx/statline.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include <wx/splitter.h>
#include <wx/fileconf.h>

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define LOGBOOK_TOOL_POSITION -1

class Logbook;
class LogbookDialog;
class LogbookTimer;
class LogbookOptions;
class Options;

class logbookkonni_pi : public opencpn_plugin
{
public:
	//logbook_pi(void *ppimgr):opencpn_plugin(ppimgr){} 
	logbookkonni_pi(void *ppimgr);
	~logbookkonni_pi();

	  LogbookTimer		*timer;
      wxWindow          *m_parent_window;
      LogbookDialog     *m_plogbook_window;
	  wxFileConfig		*m_pconfig;
	  Options			*opt;
      wxTimer 		    *m_timer;
//    The required PlugIn Methods
      int Init(void);
      bool DeInit(void);

      int GetAPIVersionMajor();
      int GetAPIVersionMinor();
      int GetPlugInVersionMajor();
      int GetPlugInVersionMinor();
      wxBitmap *GetPlugInBitmap();
      wxString GetCommonName();
      wxString GetShortDescription();
      wxString GetLongDescription();
	  void UpdateAuiStatus(void);
      void SetColorScheme(PI_ColorScheme cs);

//    The optional method overrides

      void SetNMEASentence(wxString &sentence);
	  void SetPositionFix(PlugIn_Position_Fix &pfix);
      void OnContextMenuItemCallback(int id);

//    The required override PlugIn Methods
 //     bool RenderOverlay(wxMemoryDC *pmdc, PlugIn_ViewPort *vp);
//      void SetCursorLatLon(double lat, double lon);


      void SetDefaults(void);
      int GetToolbarToolCount(void);
      void ShowPreferencesDialog( wxWindow* parent );
      void OnToolbarToolCallback(int id);

	  void loadLanguages(wxWindow * parent);
	  void loadLayouts(wxWindow * parent);

private:
	  void OnTimer(wxTimerEvent& ev);
	  void SaveConfig();
	  void LoadConfig();
	  void dialogDimmer(wxWindow* ctrl,wxColour col,wxColour back_color,wxColour text_color);

	  LogbookOptions    *optionsDialog;
      wxAuiManager     *m_pauimgr;

      int               m_show_id;
      int               m_hide_id;
	  bool				show;
	  int				m_leftclick_tool_id;

      bool              m_bLOGShowIcon;
};


class LogbookTimer : public wxWindow
{
 
public:
	LogbookTimer(logbookkonni_pi* l) : wxWindow() { plogbook_pi = l; }

	void OnTimer(wxTimerEvent& ev);

public:
	logbookkonni_pi* plogbook_pi;
};

#endif


