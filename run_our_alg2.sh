#!/bin/bash
g++ -fopenmp -O3 -march=native -std=c++17 -o main_results2_24_12_15 *.cpp

PARAM1_VALUES=(walmart trivago-clicks dblp coauth-MAG-Geology-full coauth-MAG-History-full threads-stack)  
PARAM2_VALUES=(10 11 12 13 14 15 16 17 18)  

# 循环遍历两个参数
for param2 in "${PARAM2_VALUES[@]}"; do
  for param1 in "${PARAM1_VALUES[@]}"; do
    echo "Running ././main_results2_24_12_15 with parameters: $param1 $param2"
    echo ".............................................................................$param1 $param2"
    ././main_results2_24_12_15 "$param1" "$param2"
  done
done

for param2 in "${PARAM2_VALUES[@]}"; do
  
  echo "Running ././main_results2_24_12_15 with parameters: NDC $param2"
  echo ".............................................................................DNC $param2"
  ././main_results2_24_12_15 NDC "$param2"
  
done

for param2 in "${PARAM2_VALUES[@]}"; do
  
  echo "Running ././main_results2_24_12_15 with parameters: DAWN $param2"
  echo ".............................................................................DAWN $param2"
  ././main_results2_24_12_15 DAWN "$param2"
  
done

for param2 in "${PARAM2_VALUES[@]}"; do
  
  echo "Running ././main_results2_24_12_15 with parameters: tags-stack $param2"
  echo ".............................................................................tags-stack $param2"
  ././main_results2_24_12_15 tags-stack "$param2"
  
done

