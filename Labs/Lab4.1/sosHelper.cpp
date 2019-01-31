#include "sosHelper.h"

using namespace std;

//method that gets the arrays from a .txt file with
//comma seperated values where a new line starts
//a new list
vector<vector<int> > getArrays(string fileName){
  vector<vector<int> > data;
  ifstream infile;
  infile.open(fileName);
    
  while (infile){
    string s;
    if (!getline(infile, s)) break;

    istringstream ss( s );
    vector <int> record;

    while (ss){
      string f; string s; int i = 0;
      ss >> f;
      while (i < f.length()){
	while (f[i] != ',' && i < f.length()){
	  s += f[i]; i++;}
	record.push_back(stoi(s));
	s = ""; i++;
	}
    }
    data.push_back(record);
  }
  if (!infile.eof()){
    cout<<"EMPTY FILE"<<endl;
    }
  return data;
}

  
//dummy method to measure time for
void code_to_time(){
  for(int i = 0; i < 10000; i++){
    cout<<endl;
  }
}


//method to measure time of code_to_time()
double measureTime(sorting_algo algorithm, std::vector<int> &nums){
  using namespace std::chrono;
  steady_clock::time_point start = steady_clock::now();
  (*algorithm)(nums);
  steady_clock::time_point end = steady_clock::now();
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