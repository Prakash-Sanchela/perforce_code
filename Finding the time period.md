
This program reads the input file, parses the in-time and out-time entries, and maintains a count of visitors for each minute. 
Finally, it identifies the minute with the maximum number of visitors and outputs the result. 

Basically this program reads the "visitors.txt" file, it has in time and out time as hh:mm,hh:mm format.
program parse this entry one by one and hold each entry into vector. 
one by one for each entries we will be updating the number of visitors for particular minute. 
At the end finding the max visitors at any particular minute. 

Algoritham : 

Structure used : 
	Time         :  two int variables which holds time in hour and minute
	VisitorEntry :  two Time variables which holds the inTime and outTime
	
Method used :
	convertToMinutes : convert the hh:mm format to minute. 

	1. number of argument check 
	   if not, return back.
	2. open the file from first argument.
	3. Read the input file line by line till EOF and extract the below information on each iteration. 
			- In Time 
			- discard the comma separator
			- out Time
			- store it in VisitorEntry object entry. 
			- store the entry object into entries vector. 
	4. at the end of this loop, vector entries holds the in-time and out-time for each vistitor
    5. declare a map in which it is used to hold the particular minute and number of visitor visited the museum at that minute. 
	6. iterate the loop on vector entries. 
			- at each iteration, fetch the in-time and out-time convert it to minute. 
			- for the duraction in which visitor stayed in museum, rotate the loop starting from in time till out time. 
			- add each visitor by 1 for those period of time.
	7. Now we have a map which has minute as key and value as number of visitor for that particular minute. 
			- unordered_map<int, int> visitorsCount
			- 980 4
			- 780 12
			- 651 6
			- 654 8
			- 665 16
    8. From the map we can calculate the time period when there were the most number of visitors in the museum and how many visitors were there. 
