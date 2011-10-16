#pragma once
#ifndef _OVERVIEW_H_
#define _OVERVIEW_H_

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "wx/generic/gridctrl.h"
#include <wx/textfile.h>
#include <wx/tokenzr.h>
#include <wx/wfstream.h> 
#include <wx/txtstrm.h> 

class LogbookDialog;
class Options;

class OverView
{
public:
	OverView(LogbookDialog* d, wxString data, wxString lay, wxString layoutODT);
	~OverView(void);

private:
	enum logfields{ROUTE,DATE, TIME, SIGN,WATCH, DISTANCE, DISTANCETOTAL, POSITION, COG, HEADING, SOG, STW, DEPTH,
					REMARKS, BAROMETER, WIND, WINDFORCE, CURRENT, CURRENTFORCE, WAVE, SWELL, WEATHER,
					CLOUDS, VISIBILITY, ENGINE, ENGINETOTAL, FUEL, FUELTOTAL, SAILS, REEF,WATER, WATERTOTAL, MREMARKS};
	enum gridfields{FROUTE, FSTART, FEND, FDISTANCE, FETMAL, FBESTETMAL, FENGINE, FFUEL, FWATER, FWINDDIR, FWIND, FWINDPEAK, 
					FCURRENTDIR, FCURRENT, FCURRENTPEAK, FWAVE, FWAVEPEAK, FSWELL, FSWELLPEAK, FSAILS };

	void setLayoutLocation();
	void loadLogbookData(wxString filename);
	void loadAllLogbooks();
	void writeSumColumn(int row);
	void resetValues();


	LogbookDialog*		parent;
	wxGrid*				grid;
	Options*			opt;

	wxString			ODTLayout_locn;
	wxString			HTMLLayout_locn;
	wxString			layout_locn;
	wxString			data_locn;
	wxArrayString		logbooks;

	wxString			startdate;
	wxString			enddate;
	wxString			date;
	wxString			etmaldate;
	double				distance;
	double				etmal;
	double				bestetmal;
	double				bestetmaltemp;
	int					enginehours;
	int					enginemin;
	double				fuel;
	double				water;
	double				winddir;
	double				wind;
	double				wave;
	double				swell;
	double				current;
	double				currentdir;
	double				windpeak;
	double				wavepeak;
	double				swellpeak;
	double				currentpeak;

	int					windcount;
	int					currentcount;
	int					wavecount;
	int					swellcount;
	int					etmalcount;
};
#endif