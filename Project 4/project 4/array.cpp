#include <iostream>
#include <string>
#include <cassert>
using namespace std;


int appendToAll(string a[], int n, string value)  //append value to the end of each of the n elements of the array and return n
{
	if (n < 0)
	{
		return -1;
	}

	for (int s = 0; s < n; s++)
			a[s] += value;        //appends whatever character(s) the user wants to the end of elements of the array

	return n;
}



int lookup(const string a[], int n, string target) //return the position of a string in the array that is equal to target
{
	for (int s = 0; s < n; s++)
		if (target == a[s])
			return s;      //returns the position of the string that is equivalent to the target
	
	return -1;
}



int positionOfMax(const string a[], int n) //return the position of a string in the array such that that string is >= every string in the array
{
	if (n <= 0)
	{
		return -1;
	}
	string maximum = "";
	int maximumIndex = 0;      // indicates which # string it is in the array (ex. maximumIndex = 4, it's the 4th element of the array)

	for (int s = 0; s < n; s++)   //iterates through the array
		if (a[s] > maximum)
		{
			maximumIndex = s;
			maximum = a[s];       //if a value greater than maximum is found, it is put into the maximumIndex
		}
	return maximumIndex;
}



int rotateLeft(string a[], int n, int pos) //eliminate the item at position pos by copying all elements after it one place to the left
{
	if (pos < 0 || pos >= n || n < 0)
	{
		return -1;
	}

	string t = a[pos];

	for (int s = pos; s < n - 1; s++)
	{
		a[s] = a[s + 1];         //moves each element over one space to the left

		a[n - 1] = t;            //moves the temporary string that the user selected to the last element of the array
	}
		
		return pos;
}



int countRuns(const string a[], int n)    //return the number of sequences of one or more consecutive identical items in a
{
	if (n == 0)
	{
		return 0;
	}
		
	else if (n < 0)
	{
		return -1;
	}
		
	int totalRuns = 1;             //variable to count the amount of different sequences   

	for (int k = 1; k < n; k++)    //iterates through the array
		if (a[k] != a[k - 1])      //if current element is different from the previous, add 1 to totalRuns
			totalRuns++;
	
	return totalRuns;
}



int flip(string a[], int n)   //reverse the order of the elements of the array and return n
{
	if (n < 0)
	{
		return -1;
	}

	string t;

	for (int s = 0; s < n / 2; s++)   //iterate through half the values, going through all of them would result in no changes occuring
	{
		t = a[s];
		a[s] = a[n - 1 - s];
		a[n - 1 - s] = t;     //switches the current element with the flipped element (ex. second element switches with second-to-last element)
	}
	return n;	
}



int differ(const string a1[], int n1, const string a2[], int n2)  //return the position of the first corresponding elements of a1 and a2 that are not equal
{
	if (n2 < 0 || n1 < 0)
	{
		return -1;
	}
	
	int repetitions;

	if (n1 <= n2)                           //stores integer input that is less to or equal to the other into "repetitions"
		repetitions = n1;
	else
		repetitions = n2;

	for (int s = 0; s < repetitions; s++)   
		if (a1[s] != a2[s])                 //compares the elements of the two arrays
			return s;                       //returns index of the elements if they are not equivalent
		
	return repetitions;                     //returns whichever is less: n1 or n2 
}



int subsequence(const string a1[], int n1, const string a2[], int n2) //if all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins
{
	if (n1 < n2 || n1 < 0 || n2 < 0)
		return -1;
	
	else if ((n2 == 0) && (n1 == 0) || n2 == 0)
		return 0;

	int same = 0;                          //keeps track of the number of matched elements in a row

	for (int x = 0; x < n1; x++)
		for (int y = 0; y < n2; y++)
		{
			if (a1[x] == a2[y])            //if both elements are the same
			{
				same++;
				if (n2 == same)            //if number of matched elements in a row = size of a2
					return x - same + 1;   //return the position in a1 where the subsequence begins
				x++;                       //keeps iterating through x for a1 to compare the following elements with y for a2
			}
			else
				same = 0;                  //resets the amount of matched in a row
		}
	return -1;                             //returns this message if the loop passes with no matches
}



int lookupAny(const string a1[], int n1, const string a2[], int n2)  //return the smallest position in a1 of an element that is equal to any of the n2 elements in a2
{
	if (n1 < 0 || n2 < 0)
	{
		return -1;
	}

	for (int s = 0; s < n1; s++)
		for (int s = 0; s < n1; s++)            //iterate through the first array to the n1th element
			if (lookup(a2, n2, a1[s]) != -1)    //if the element in the a1 is found in a2
				return s;

	return -1;	
}



int separate(string a[], int n, string separator)  //rearrange the elements of the array so that all the elements whose value is < separator come before all
{                                                  //the other elements, and all the elements whose value is > separator come after all the other elements
	if (n < 0)
		return -1;

	int same = 0;                     //used to track where separator is if it is contained in the array

	for (int s = n - 1; s >= 0; s--)
		if (a[s] >= separator)
			rotateLeft(a, n, s);      //if element is >= separator, used rotateLeft to push current element to the end of the array; shifts the rest of them left as well
		else
			same++;                   //if less than separator, add 1 to same to track location of separator

	for (int s = 0; s < n; s++)       
		if (a[s] == separator)        //if current element is the separator string
		{
			string t = a[s];          //moves separator from position s to position same
			a[same] = a[s];
			t = a[same];
			same++;
		}
	for (int s = 0; s < n; s++)
		if (a[s] >= separator)
			return s;                 //returns the position of the first element that is not < separator after the rearrangement of the array


	return n;
}


int main()
{
	string h[7] = { "mick", "marie", "fiona", "rudy", "", "gordon", "lindsey" };
	assert(lookup(h, 7, "gordon") == 5);
	assert(lookup(h, 7, "fiona") == 2);
	assert(lookup(h, 2, "fiona") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "mick", "marie", "lindsey", "nancy" };
	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "mick?" && g[3] == "nancy?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "lindsey?" && g[3] == "marie?");

	string e[4] = { "fiona", "rudy", "", "gordon" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "marie", "marie", "marie", "rudy", "rudy" };
	assert(countRuns(d, 5) == 2);

	string f[3] = { "lindsey", "fiona", "mike" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "mike" && f[2] == "lindsey");

	assert(separate(h, 7, "lindsey") == 3);

	cout << "All tests succeeded" << endl;
}


