//
//  main.cpp
//  NearestNeighbours
//
//  Created by Petr Vaněk on 06/06/2019.
//  Copyright © 2019 Macbook. All rights reserved.
//


#include "armadillo.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace arma;


int main(int argc, char* argv[])
{
    int param_k = 5;
    ///////////////////////////
    ////// READING DATA ///////
    ///////////////////////////
    
    //Read dataX from dist
    double x[200][34];
    std::ifstream read_file("dataX.dat");
    assert(read_file.is_open());
    for (int i = 0; i<200; i++)
    {
        for (int j = 0; j<34; j++)
        {
            read_file >> x[i][j];
        }
    }
    read_file.close();
    
    //Read dataXtest from disk
    double x_test[151][34];
    std::ifstream read_file_test("dataXtest.dat");
    assert(read_file_test.is_open());
    for (int i = 0; i<151; i++)
    {
        for (int j = 0; j<34; j++)
        {
            read_file_test >> x_test[i][j];
        }
    }
    read_file_test.close();
    
    //Read dataY from disk
    double y[200];
    std::ifstream read_file_y("dataY.dat");
    assert(read_file_y.is_open());
    for (int i = 0; i<200; i++)
    {
            read_file_y >> y[i];
    }
    read_file_y.close();
    
    
    ////////////////////////////////////////
    /// Nearest Neighbour Classification ///
    ////////////////////////////////////////
    

    double res;
    double result[151];
    uvec ind;
    vec diffe(34);
    vec distances(200);
    
    //loop for all x_test
    for(int i=0; i<151; i++)
    {
        //compute differences
        for(int k=0; k<200; k++)
        {
            for(int j=0; j<34; j++)
            {
                diffe[j] = x[k][j] - x_test[i][j];
            }
            
            //compute norm for each x
            distances[k] = norm(diffe, 2);
        }
        
        //sort norm distances
        ind = sort_index(distances);
        std::vector<int> index = conv_to<std::vector<int>>::from(ind);
        //null vector
        res = 0;
    
        //For condition
        for(int l=0; l<param_k; l++)
        {
            res = res + y[index[l]];
        }
        
    
        //Save result
        if(res>0)
        {
            result[i] = 1;
        }
        else
        {
            result[i] = -1;
        }
        
        
    }
    
    
    /////////////////////////////
    //////// WRITING DATA ///////
    /////////////////////////////
    
    std::ofstream write_output("NN.dat");
    assert(write_output.is_open());
    for (int i=0; i<151; i++)
    {
        write_output << result[i] << "\n";
    }
    write_output.close();
    
    
    
    

   
    
    
    
    return 0;
}
