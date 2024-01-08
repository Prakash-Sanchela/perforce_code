#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>>
#include <sstream>

using namespace std;

/*!*****************************************************************************
* @brief 
*   Time structure holds variables hour and minute
*   basically a structure which is used to hold the time in hour & minute
* 
*******************************************************************************/
struct Time {
    int hour;
    int minute;
};

/*!*****************************************************************************
* @brief 
*   VisitorEntry structure holds instance of Time structure
*   which is used to hold the inTime and outTime of the visitors
* 
*******************************************************************************/
struct VisitorEntry {
    Time inTime;
    Time outTime;
};

