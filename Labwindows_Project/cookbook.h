/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  MAIN                             1       /* callback function: MainPanelCallback */
#define  MAIN_TEST                        2       /* control type: command, callback function: TestTheFilterCallback */
#define  MAIN_RUN                         3       /* control type: command, callback function: MakeFilterCookbookCallback */
#define  MAIN_QUIT                        4       /* control type: command, callback function: QuitCookbookCallback */
#define  MAIN_SAMPLE_RATE                 5       /* control type: numeric, callback function: (none) */
#define  MAIN_FREQUENCY                   6       /* control type: numeric, callback function: (none) */
#define  MAIN_BANDWIDTH                   7       /* control type: numeric, callback function: (none) */
#define  MAIN_A4                          8       /* control type: numeric, callback function: (none) */
#define  MAIN_A3                          9       /* control type: numeric, callback function: (none) */
#define  MAIN_A2                          10      /* control type: numeric, callback function: (none) */
#define  MAIN_A1                          11      /* control type: numeric, callback function: (none) */
#define  MAIN_A0                          12      /* control type: numeric, callback function: (none) */
#define  MAIN_GAIN                        13      /* control type: numeric, callback function: (none) */
#define  MAIN_TYPE                        14      /* control type: ring, callback function: (none) */
#define  MAIN_GRAPH                       15      /* control type: graph, callback function: (none) */
#define  MAIN_TEST_FREQ                   16      /* control type: numeric, callback function: TestTheFilterCallback */
#define  MAIN_TITLE                       17      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK MainPanelCallback(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MakeFilterCookbookCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCookbookCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestTheFilterCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
