// main.c 
// Biquad design tool
// 8/25/15  D. Gleichman 		Some Clean up

// Include files

#include <ansi_c.h>
#include <cvirte.h>     
#include <userint.h>
#include "toolbox.h"

#include "biquad.h"
#include "cookbook.h"

int mainHandle;


/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
    int error = 0;
    
    /* initialize and load resources */
    mainHandle = LoadPanel (0, "cookbook.uir", MAIN);
    
    /* display the panel and run the user interface */
    DisplayPanel(mainHandle);
    RunUserInterface();

    /* clean up */
    DiscardPanel (mainHandle);
    return 0;
}

//==============================================================================

biquad bi1, bi2;
smp_type sampleRate = 1000;
smp_type gain = 0;
smp_type freq = 200;
smp_type bandwidth = 100;

int type = LPF;


void PrintBiquad(biquad * b)
{
	printf("a0 = %15.6e\n", b->a0);
	printf("a1 = %15.6e\n", b->a1);
	printf("a2 = %15.6e\n", b->a2);
	printf("a3 = %15.6e\n", b->a3);
	printf("a4 = %15.6e\n", b->a4);
}
	
	
void RunTester(void)
{
	
	GetCtrlVal(mainHandle, MAIN_TYPE, &type);
	GetCtrlVal(mainHandle, MAIN_GAIN, &gain);
	GetCtrlVal(mainHandle, MAIN_FREQUENCY, &freq);
	GetCtrlVal(mainHandle, MAIN_SAMPLE_RATE, &sampleRate);
	GetCtrlVal(mainHandle, MAIN_BANDWIDTH, &bandwidth);
	
	bi1 = *BiQuad_new(type, gain, freq, sampleRate, bandwidth);

	SetCtrlVal(mainHandle, MAIN_A0, bi1.a0);
	SetCtrlVal(mainHandle, MAIN_A1, bi1.a1);
	SetCtrlVal(mainHandle, MAIN_A2, bi1.a2);
	SetCtrlVal(mainHandle, MAIN_A3, bi1.a3);
	SetCtrlVal(mainHandle, MAIN_A4, bi1.a4);
	
}

//-----------------------------------------------------------------------------
//		Testing the filter
//-----------------------------------------------------------------------------


#define TEST_SIZE 1000

double inputData[TEST_SIZE];
double outputData[TEST_SIZE];

double testAmp = 1.0;
double testFreq;

void CreateSineWave(double amp, double freq, double srate)
{
	int i;
	
	for (i=0;i<TEST_SIZE;i++)
	{
		inputData[i] = amp * sin(2*PI*i*freq/srate);
	}
}

void MakeInput(void)
{
	GetCtrlVal(mainHandle, MAIN_TEST_FREQ, &testFreq);
	CreateSineWave(testAmp, testFreq, sampleRate);

    DeleteGraphPlot (mainHandle, MAIN_GRAPH, -1, VAL_DELAYED_DRAW);
	PlotY(mainHandle, MAIN_GRAPH, inputData, TEST_SIZE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_BLUE);
}

void RunDataThroughFilter(void)
{
	int i;
	
	ZeroBiQuad(&bi1);
	
	for (i=0;i<TEST_SIZE;i++)
	{
		outputData[i] = BiQuad(inputData[i], &bi1);
	}
}

void ShowOutput(void)
{
	PlotY(mainHandle, MAIN_GRAPH, outputData, TEST_SIZE, VAL_DOUBLE, VAL_THIN_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
}	

 
void TestFilter(void)
{
	MakeInput();
	RunDataThroughFilter();
	ShowOutput();
}

//-----------------------------------------------------------------------------


int CVICALLBACK QuitCookbookCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface(0); 
			break;
	}
	return 0;
}

int CVICALLBACK MakeFilterCookbookCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			RunTester();
			break;
	}
	return 0;
}

int CVICALLBACK MainPanelCallback (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface(0);  
			break;
	}
	return 0;
}

int CVICALLBACK TestTheFilterCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			TestFilter();
			break;
	}
	return 0;
}
