# Mth9815 Final Project

- Project structure
    - /BondService: the bond implementation header files on different services
    - /Data: data generator files and all the generated files and .txt output files
    - All the modified sample codes and main.cpp
    - CMakeLists.txt
    - README.md

- Deployment
    - In the root directory of the project
    ```
    cmake .
    make
    ./tradingsystem
    ```
    - The size of generated dataset can be modified in 4 "DataGenerator.hpp" files in "Data" folder
    - The CUSIP, coupon, maturity and PV01 data of 7 securities are presented in "main.cpp"
    - The results can be viewed in "Data" folder after running the program
