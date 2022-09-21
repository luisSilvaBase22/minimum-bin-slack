# README

Here you will find an implementation of the Minimum Bin Slack algorithm, which is an euristhic proposed by Gupta and Oh. 
The algorithm is implemented using the C++ language.

## How to use
1. Download the files from this repository and save them in the same folder
2. Download the bin1data, hard28, 53NIRUP and waescherH instances, each one in its own folder 
3. The MBSCallFiles.cpp file has a function to read from the folder of the instance you want to examinate, in order to examinate a differente instance, rename the folder name in the line 36 and 38 mathching any of the folders from step 2
4. Using a Unix terminal (or Windows), navigate to the folder where you have the code and execute the following command to compile the main file:
    ```
    g++ MBSCallFiles.cpp
    ```
3. The program out put the following information:
- Time used to run the program
- Number of bins to group the items
- A list of containers displaying the content of each item
 
 ### References
 <https://www.researchgate.net/publication/339207296_Implementacion_del_algoritmo_MBS_para_resolver_instancias_de_bin_packing>
 <https://rcs.cic.ipn.mx/2017_134/Implementacion%20del%20algoritmo%20MBS%20para%20resolver%20instancias%20de%20bin%20packing.pdf>