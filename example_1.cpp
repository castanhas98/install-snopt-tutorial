/*
*   Example 1 - Population-Based Evolution using pagmo and SNOPT
*
*   Inspired by https://esa.github.io/pagmo_plugins_nonfree/quickstart.html
*/

#include <pagmo/algorithm.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/problems/rosenbrock.hpp>
#include <pagmo_plugins_nonfree/pagmo_plugins_nonfree.hpp>

using namespace pagmo;


int main( )
{
    // 1 - Instantiate a pagmo problem constructing it from the Rosenbrock UDP.
    problem prob{rosenbrock(30)};
    
    // 2 - Instantiate a pagmo_plugins_nonfree algorithm, in this case SNOPT. This assumes a library libsnopt7_c.so is
    // found in the path "/usr/local/lib/". Otherwise you will get a runtime error.
    // Default values -> ppnf::snopt7(bool screen_output = false, std::string snopt7_c_library = "/usr/local/lib/libsnopt7_c.so", unsigned minor_version = 6u);
    algorithm algo(ppnf::snopt7(true, "./snopt-interface/lib/libsnopt7_c.so", 6u));

    // 3 - Instantiate a population with a single individual and random_seed = 0.
    population pop( prob, 1, 0 );

    // 4 - Print the initial population.
    std::cout << "Initial Population:" << std::endl;
    std::cout << pop << std::endl;

    // 5 - Perform one generation of evolution with snopt7.
    pop = algo.evolve( pop );

    // 6 - Print the population after the evolution.
    std::cout << "Final Population:" << std::endl;
    std::cout << pop << std::endl;

    return 0;
}
