#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "PrimeAlgos.h"
#include <assert.h> 

using namespace std;

typedef bool prime_fn(int num);

// method that gets the arrays from a .txt file with
// comma seperated values where a new line starts
// a new list
vector<vector<int> > getArrays(string fileName){
  // create a vector of vectors of ints to store the integers
  vector<vector<int> > data;

  // initialize the input stream and open the file
  ifstream infile;
  infile.open(fileName);

  // while there are lines in the file
  while (infile){
    string s;
    if (!getline(infile, s)) break; // break if there isn't another line

    // create an object to help you read strings from the file called ss
    istringstream ss( s );
    vector <int> record;
    int j = 0;

    // while there are still whitespace seperated strings
    while (ss){
      string f; string s; int i = 0;
      // put the next string from the file commas attached to end 
      ss >> f;
      while (i < f.length()){
	while (f[i] != ',' && i < f.length()){ 
	  s += f[i];
	  i++;
	}
	// stoi is a function to convert a string to an int
	// push the result to the back of the vector
	record.push_back(stoi(s)); 
	s = ""; // clear s
	i++; 
      }
    }

    // push the whole row to the back of the vecotr
    data.push_back(record);
  }
  if (!infile.eof()){ // if the file is empty
    cout<<"EMPTY FILE"<<endl;
  }
  return data;
}

  
//dummy method to measure time for
void code_to_time(){
  int sum = 0;
  for(int i = 0; i < 10000; i++){
    sum *= 1.5;
  }
}


//method to measure time of code_to_time()
double measureTime(prime_fn fn, int num){
  using namespace std::chrono;

  // create a start time
  steady_clock::time_point start = steady_clock::now();

  // call whatever function you are timing
  (*fn)(num);

  // get the end time
  steady_clock::time_point end = steady_clock::now();

  //get the difference
  duration<double> time_span = duration_cast<duration<double> >(end - start);
  return time_span.count();
}


//method to output a vector<double> of data to a csv file
void output(vector<double> data, string filename){
  // take in the vector of doubles to output and desired filename
  // create a file with the given filename
  ofstream outfile;
  outfile.open(filename, std::ios_base::app);
  // iterate over the vector, outputting the data to the file
  for (int i = 0; i < data.size()-1; i++){
    outfile << fixed << setprecision(10) << data[i] << ",";
  }
  outfile << data[data.size()-1] << endl;

  // close the file
  outfile.close();
}

int main(){
  // TESTS
  assert(one(1) == false);
  assert(one(2));
  assert(one(3));
  assert(one(4) == false);
  assert(one(5));
  assert(one(100) == false);
  assert(one(199128) == false);
  assert(one(19128312) == false);
  assert(one(7219));
  assert(one(4973));
  assert(one(23167));

  assert(two(1) == false);
  assert(two(2));
  assert(two(3));
  assert(two(4) == false);
  assert(two(5));
  assert(two(100) == false);
  assert(two(199128) == false);
  assert(two(19128312) == false);
  assert(two(7219));
  assert(two(4973));
  assert(two(23167));

  assert(three(1) == false);
  assert(three(2));
  assert(three(3));
  assert(three(4) == false);
  assert(three(5));
  assert(three(100) == false);
  assert(three(199128) == false);
  assert(three(19128312) == false);
  assert(three(7219));
  assert(three(4973));
  assert(three(23167));

  prime_fn* a = &one;
  prime_fn* b = &two;
  prime_fn* c = &three;

  vector<double> times;
  vector<vector<int> > nums = getArrays("primes.txt");

  for(int i = 0; i < nums.size(); i++){
    for(int j = 0; j < nums[i].size(); j++){
      int num = nums[i][j];
      times.push_back(num);
      times.push_back(measureTime(a, num));
      times.push_back(measureTime(b, num));
      times.push_back(measureTime(c, num));

      output(times, "OUT.csv");
      times.clear();
    }
  }

  return 0;
}