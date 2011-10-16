#pragma once
#include <wx/string.h>
#include <wx/filename.h>

class LogbookDialog;
class Logbook;

class LogbookHTML
{
public:
	LogbookHTML(Logbook* l, LogbookDialog* d, wxString data, wxString layout);
	~LogbookHTML(void);

	void viewHTML(wxString path,wxString layout, bool mode);
	void viewODT(wxString path, wxString layout, bool mode);
	wxString toHTML(wxString path,wxString layout, bool mode);
	wxString toODT(wxString path,wxString layout, bool mode);
	void toCSV(wxString path);
	void toXML(wxString path);
	void toODS(wxString path);
	void backup(wxString path);
	void setFileName(wxString s, wxString l);

private:
	enum fields{ ROUTE,RDATE,RTIME,SIGN,WAKE,DISTANCE,DTOTAL,POSITION,COG,COW,SOG,SOW,DEPTH,REMARKS,
				 BARO,WIND,WSPD,CURRENT,CSPD,WAVE,SWELL,WEATHER,CLOUDS,VISIBILITY,
				 MOTOR,MOTORT,FUEL,FUELT,SAILS,REEF,WATER,WATERT,MREMARKS};	

	wxString readLayoutFile(wxString layout);
	wxString readLayoutFileODT(wxString layout);
	void setSelection();
	bool checkLayoutError(int result, wxString html, wxString layout);
	wxString replacePlaceholder(wxString html, wxString htmlHeader, wxString line, int nr,bool mode);

	LogbookDialog *parent;
	Logbook		  *logbook;
	wxString data_locn;
	wxString layout_locn;
	wxString fileName;
};