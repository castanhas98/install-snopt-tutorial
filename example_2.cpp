/*
*   Example 2 - Archipelago-Based Evolution using pagmo and SNOPT
*
*   Inspired by https://esa.github.io/pagmo_plugins_nonfree/quickstart.html
*/

#include <pagmo/algorithm.hpp>
#include <pagmo/archipelago.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/problems/rosenbrock.hpp>
#include <pagmo_plugins_nonfree/pagmo_plugins_nonfree.hpp>

using namespace pagmo;


int main()
{
    // 1 - Instantiate a pagmo problem constructing it from the Rosenbrock
    // UDP (user defined problem).
    problem prob{rosenbrock(30)};

    // 2 - Instantiate a pagmo_plugins_nonfree algorithm, in this case SNOPT. This assumes a library libsnopt7_c.so is
    // found in the path "/usr/local/lib/". Otherwise you will get a runtime error.
    // Can be a relative path.
    algorithm algo(ppnf::snopt7(false, "./snopt-interface/lib/libsnopt7_c.so", 6u));

    // 3 - Instantiate an archipelago with 16 islands having each 1 individual (the initial guess)
    archipelago archi{16, algo, prob, 1};
    
    // 4 - Instantiating a copy of the first archipelago for printing purposes
    // as it makes it easier to see the results when the screen_output is set to true
    archipelago archi1 = archi;

    // 4 - Run the snopt7 calls in parallel on the 16 separate islands.
    archi.evolve(10);

    // 5 - Wait for the snopt7 calls to be finished
    archi.wait();

    // 6 - Print the original fitness of the best solution in each island
    std::cout << "Fitness function values of the original archipelago:" << std::endl;
    for (const auto &isl : archi1) {
        print(isl.get_population().champion_f(), "\n");
    }

    // 7 - Print the fitness of the best solution in each island
    std::cout << "\nFitness function values after the optimization:" << std::endl;
    for (const auto &isl : archi) {
        print(isl.get_population().champion_f(), "\n");
    }
    
    

    return 0;
}
