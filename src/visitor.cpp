#include "visitor.h"

/*!****************************************************************************
 * @brief 
 *  accepts Time structure object and returns in minutes form
 *  This function accepts one Time structure object, calculates the
 *  minutes from hour and add minutes from time.minute. 
 * @param time object of Time structure which hold the timing of either in time
 * or out time
 * @return returns the converted minutes from hh:mm
 * @note time.hour * 60 + time.minute
 * 
 *******************************************************************************/
int convertToMinutes(const Time& time) {
    return time.hour * 60 + time.minute;
}

int main(int argc, char* argv[]) {

    if (argc != 2)
    {
        cout << "Please provide the input file path : " << endl;
        return 0;
    }
    ifstream inputFile(argv[1]); 
    cout << "file : " << argv[1] << endl;

    if (!inputFile.is_open()) {
        cout << "Error opening the file." <<endl;
        return 1;
    }

    string line;                   //!< string line : string of singel line which stores the line by line in time and out time
    vector<VisitorEntry> entries;  //!< vector<VisitorEntry> entries : vector of VisitorEntry, which holds the in time and out time entry of each line

    // Read input file and parse entries
    while (std::getline(inputFile, line)) {
        istringstream iss(line);
        VisitorEntry entry;
        char separator;
        iss >> entry.inTime.hour >> separator >> entry.inTime.minute;
        iss >> separator; // Discard comma
        iss >> entry.outTime.hour >> separator >> entry.outTime.minute;
        entries.push_back(entry);
    }

    unordered_map<int, int> visitorsCount; /*!< unordered_map<int, int> visitorsCount : map to track the number of visitors for each minute,
                                                minute as key and number of visitors as value*/

    // Update visitors count for each minute
    for (const auto& entry : entries) {
        int inTimeMinutes = convertToMinutes(entry.inTime);
        int outTimeMinutes = convertToMinutes(entry.outTime);
        
        for (int i = inTimeMinutes; i < outTimeMinutes; ++i) {
            visitorsCount[i]++;
        }
    }
    // Find the minute with the maximum number of visitors
    int maxMinute = 0;
    int maxVisitors = 0;

    for (const auto& entry : visitorsCount) {
        if (entry.second > maxVisitors) {
            maxVisitors = entry.second;
            maxMinute = entry.first;
        }
    }
    cout << "Maximum visitors at: " << maxMinute / 60 << ":" << maxMinute % 60 << endl;
    cout << "Number of visitors: " << maxVisitors << endl;

    return 0;
}
