g++ Lab.cpp sosHelper.cpp Sorting.cpp
echo "compiled"
echo "Running 10"
./a.out Inputs/arrays10.txt Outputs/out10.csv
echo "Running 50"
./a.out Inputs/arrays50.txt Outputs/out50.csv
echo "Running 100"
./a.out Inputs/arrays100.txt Outputs/out100.csv
echo "Running 500"
./a.out Inputs/arrays500.txt Outputs/out500.csv
echo "Running 1000"
./a.out Inputs/arrays1000.txt Outputs/out1000.csv
echo "Running 5000"
./a.out Inputs/arrays5000.txt Outputs/out5000.csv
echo "Running 10000"
./a.out Inputs/arrays10000.txt Outputs/out10000.csv
echo "finished"